#include "contrib/mysql_proxy/filters/network/source/mysql_filter.h"

#include "envoy/config/core/v3/base.pb.h"

#include "source/common/buffer/buffer_impl.h"
#include "source/common/common/assert.h"
#include "source/common/common/logger.h"
#include "source/extensions/filters/network/well_known_names.h"

#include "contrib/mysql_proxy/filters/network/source/mysql_codec.h"
#include "contrib/mysql_proxy/filters/network/source/mysql_codec_clogin_resp.h"
#include "contrib/mysql_proxy/filters/network/source/mysql_decoder_impl.h"
#include "contrib/mysql_proxy/filters/network/source/mysql_utils.h"
#include <iomanip>
#include <openssl/sha.h>

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace MySQLProxy {


// Function to perform XOR operation on two byte sequences
std::vector<uint8_t> xorBytes(const std::vector<uint8_t>& a, const std::vector<uint8_t>& b) {
  std::vector<uint8_t> result;
  for (size_t i = 0; i < a.size() && i < b.size(); ++i) {
    result.push_back(a[i] ^ b[i]);
  }
  return result;
}

// Function to perform SHA1 hash on a byte sequence using OpenSSL
std::vector<uint8_t> sha1(const void* data, size_t size) {
  SHA_CTX shaContext;
  SHA1_Init(&shaContext);
  SHA1_Update(&shaContext, data, size);

  std::vector<uint8_t> shaResult(SHA_DIGEST_LENGTH, 0);
  SHA1_Final(shaResult.data(), &shaContext);

  return shaResult;
}

// Function to perform MySQL scrambling
std::vector<uint8_t> mysqlScramble(const std::string& password, const std::vector<uint8_t>& serverSalt) {
  // Calculate SHA1 hash of the password
  std::vector<uint8_t> sha1Password = sha1(password.c_str(), password.size());
  // Print the result in hexadecimal format
  std::cout << "sha1Password: ";
  std::cout << std::hex << std::setfill('0');
  for (const auto& byte : sha1Password) {
    std::cout << std::setw(2) << static_cast<int>(byte);
  }
  std::cout << std::endl;

  // Calculate double SHA1 hash of the password
  std::vector<uint8_t> sha1DoublePassword = sha1(sha1Password.data(), sha1Password.size());

  std::cout << "sha1DoublePassword: ";
  std::cout << std::hex << std::setfill('0');
  for (const auto& byte : sha1DoublePassword) {
    std::cout << std::setw(2) << static_cast<int>(byte);
  }
  std::cout << std::endl;

  // Concatenate server salt and double SHA1 password
  std::vector<uint8_t> sha1Combined;
  sha1Combined.insert(sha1Combined.end(), serverSalt.begin(), serverSalt.end());
  sha1Combined.insert(sha1Combined.end(), sha1DoublePassword.begin(), sha1DoublePassword.end());

  std::cout << "sha1Combined not sha1: ";
  std::cout << std::hex << std::setfill('0');
  for (const auto& byte : sha1Combined) {
    std::cout << std::setw(2) << static_cast<int>(byte);
  }
  std::cout << std::endl;
  // Calculate SHA1 hash of the combined value
  std::vector<uint8_t> sha1CombinedHash = sha1(sha1Combined.data(), sha1Combined.size());

  std::cout << "sha1CombinedHash: ";
  std::cout << std::hex << std::setfill('0');
  for (const auto& byte : sha1CombinedHash) {
    std::cout << std::setw(2) << static_cast<int>(byte);
  }
  std::cout << std::endl;

  // Calculate XOR of SHA1 password and combined value
  std::vector<uint8_t> result = xorBytes(sha1Password, sha1CombinedHash);

  return result;
}


MySQLFilterConfig::MySQLFilterConfig(const std::string& stat_prefix, Stats::Scope& scope)
    : scope_(scope), stats_(generateStats(stat_prefix, scope)) {}

MySQLFilter::MySQLFilter(MySQLFilterConfigSharedPtr config) : config_(std::move(config)) {
  using namespace std;
  if(!mySqlAttribute) {
    mySqlAttribute = new MySQLAttribute();
  }
  ENVOY_LOG(debug, "MySQLFilter::MySQLFilter(...)");
}

void MySQLFilter::initializeReadFilterCallbacks(Network::ReadFilterCallbacks& callbacks) {
  read_callbacks_ = &callbacks;
}

Network::FilterStatus MySQLFilter::onData(Buffer::Instance& data, bool) {
  if(!loggedIn) {

    // Example usage with the provided password and salt
    std::string password = "YoZSCEYwKSi5s!re";
//    std::vector<uint8_t> serverSalt = {0x55, 0x16, 0x75, 0x10, 0x15, 0x45, 0x4C, 0x04, 0x1C, 0x0F, 0x08, 0x5A, 0x71, 0x1B, 0x4C, 0x63, 0x35, 0x0F, 0x3C, 0x34};

    // Calculate MySQL scramble
    std::vector<uint8_t> result = mysqlScramble(password, mySqlAttribute->serverSalt);

    // Print the result in hexadecimal format
    std::cout << std::hex << std::setfill('0');
    for (const auto& byte : result) {
      std::cout << std::setw(2) << static_cast<int>(byte);
    }
    std::cout << std::endl;

    uint originalLength = data.length();
    uint visitedLenght = 0;
    Buffer::OwnedImpl data_copy;
    for(uint64_t i = 0; i < 36; i++) {
      data_copy.writeByte(data.peekLEInt<uint8_t>(i));
    }

    visitedLenght += 36;
    BufferHelper::skipBytes(data, 36);

    BufferHelper::addString(data_copy, "root");
    data_copy.writeByte(0);

    std::string username;
    BufferHelper::readString(data, username); // careful: readString drains space besides reading the string
    visitedLenght += username.length() + 1;

    std::cout << "the username: " << username << std::endl;

    data_copy.writeByte(20); //auth_len is 20 bytes
    for (const auto& byte : result) { // result is 20 bytes
      data_copy.writeByte(byte);
    }
    data.drain(21);
    visitedLenght += 21;
    for(uint i = 0; i < originalLength - visitedLenght; i++) {
      data_copy.writeByte(data.peekLEInt<uint8_t>(i));
    }
    data.drain(originalLength);
    data.add(data_copy);

    // modify the mysql packet header, packet length field
    data_copy.drain(data_copy.length());
    uint packet_length = data.length() - 4;
    data_copy.writeByte((packet_length) & 0xff);
    data_copy.writeByte((packet_length >> 8) & 0xff);
    data_copy.writeByte((packet_length >> 16) & 0xff);
    data.drain(3);
    for(uint64_t i = 0; i < data.length(); i++) {
      data_copy.writeByte(data.peekLEInt<uint8_t>(i));
    }
    data.drain(data.length());
    data.add(data_copy);
    loggedIn = true;
    mySqlAttribute->serverSalt.clear();
  }

  // Safety measure just to make sure that if we have a decoding error we keep going and lose stats.
  // This can be removed once we are more confident of this code.

  if (sniffing_) {
    read_buffer_.add(data);
    doDecode(read_buffer_);
  }
  return Network::FilterStatus::Continue;
}

Network::FilterStatus MySQLFilter::onWrite(Buffer::Instance& data, bool) {
  // Safety measure just to make sure that if we have a decoding error we keep going and lose stats.
  // This can be removed once we are more confident of this code.
  if (sniffing_) {
    write_buffer_.add(data);
    doDecode(write_buffer_);
  }
  return Network::FilterStatus::Continue;
}

void MySQLFilter::doDecode(Buffer::Instance& buffer) {
  // Clear dynamic metadata.
  envoy::config::core::v3::Metadata& dynamic_metadata =
      read_callbacks_->connection().streamInfo().dynamicMetadata();
  auto& metadata =
      (*dynamic_metadata.mutable_filter_metadata())[NetworkFilterNames::get().MySQLProxy];
  metadata.mutable_fields()->clear();

  if (!decoder_) {
    decoder_ = createDecoder(*this);
  }

  try {
    decoder_->onData(buffer);
  } catch (EnvoyException& e) {
    ENVOY_LOG(info, "mysql_proxy: decoding error: {}", e.what());
    config_->stats_.decoder_errors_.inc();
    sniffing_ = false;
    read_buffer_.drain(read_buffer_.length());
    write_buffer_.drain(write_buffer_.length());
  }
}

DecoderPtr MySQLFilter::createDecoder(DecoderCallbacks& callbacks) {
  return std::make_unique<DecoderImpl>(callbacks, mySqlAttribute);
}

void MySQLFilter::onProtocolError() { config_->stats_.protocol_errors_.inc(); }

void MySQLFilter::onNewMessage(MySQLSession::State state) {
  if (state == MySQLSession::State::ChallengeReq) {
    config_->stats_.login_attempts_.inc();
  }
}

void MySQLFilter::onClientLogin(ClientLogin& client_login) {
  if (client_login.isSSLRequest()) {
    config_->stats_.upgraded_to_ssl_.inc();
  }
}

void MySQLFilter::onClientLoginResponse(ClientLoginResponse& client_login_resp) {
  if (client_login_resp.getRespCode() == MYSQL_RESP_AUTH_SWITCH) {
    config_->stats_.auth_switch_request_.inc();
  } else if (client_login_resp.getRespCode() == MYSQL_RESP_ERR) {
    config_->stats_.login_failures_.inc();
  }
}

void MySQLFilter::onMoreClientLoginResponse(ClientLoginResponse& client_login_resp) {
  if (client_login_resp.getRespCode() == MYSQL_RESP_ERR) {
    config_->stats_.login_failures_.inc();
  }
}

void MySQLFilter::onCommand(Command& command) {
  if (!command.isQuery()) {
    return;
  }

  // Parse a given query
  envoy::config::core::v3::Metadata& dynamic_metadata =
      read_callbacks_->connection().streamInfo().dynamicMetadata();
  ProtobufWkt::Struct metadata(
      (*dynamic_metadata.mutable_filter_metadata())[NetworkFilterNames::get().MySQLProxy]);

  auto result = Common::SQLUtils::SQLUtils::setMetadata(command.getData(),
                                                        decoder_->getAttributes(), metadata);

  ENVOY_CONN_LOG(trace, "mysql_proxy: query processed {}, result {}, cmd type {}",
                 read_callbacks_->connection(), command.getData(), result,
                 static_cast<int>(command.getCmd()));

  if (!result) {
    config_->stats_.queries_parse_error_.inc();
    return;
  }
  config_->stats_.queries_parsed_.inc();

  read_callbacks_->connection().streamInfo().setDynamicMetadata(
      NetworkFilterNames::get().MySQLProxy, metadata);
}

Network::FilterStatus MySQLFilter::onNewConnection() {
  config_->stats_.sessions_.inc();
  return Network::FilterStatus::Continue;
}

} // namespace MySQLProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
