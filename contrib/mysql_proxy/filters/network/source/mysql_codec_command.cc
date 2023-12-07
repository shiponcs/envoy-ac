#include "contrib/mysql_proxy/filters/network/source/mysql_codec_command.h"

#include "envoy/buffer/buffer.h"

#include "source/common/common/logger.h"
#include "source/common/common/macros.h"

#include "contrib/mysql_proxy/filters/network/source/mysql_codec.h"
#include "contrib/mysql_proxy/filters/network/source/mysql_utils.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace MySQLProxy {

// it will be updated by different methods and
// will be printed by CommandResponse.parseMessage
std::string auditLog{""};

Command::Cmd Command::parseCmd(Buffer::Instance& data) {
  uint8_t cmd;
  if (BufferHelper::readUint8(data, cmd) != DecodeStatus::Success) {
    return Command::Cmd::Null;
  }
  return static_cast<Command::Cmd>(cmd);
}

void Command::setCmd(Command::Cmd cmd) { cmd_ = cmd; }

void Command::setDb(const std::string& db) { db_ = db; }

DecodeStatus Command::parseMessage(Buffer::Instance& buffer, uint32_t len) {
  Command::Cmd cmd = parseCmd(buffer);
  setCmd(cmd);
  if (cmd == Command::Cmd::Null) {
    return DecodeStatus::Failure;
  }
  Buffer::OwnedImpl buffer_cpy;
  buffer_cpy.add(buffer);
  switch (cmd) {
    case Command::Cmd::InitDb:{
      std::basic_string<char>  message;
      BufferHelper::readStringBySize(buffer_cpy, len - 1, message);
//      std::cout << "use database | schema: " << message << std::endl;
      auditLog.assign("use database | schema: " + message);

      if(!mySqlAttribute) {
        std::cout << "mySqlAttribute is NULL ************ message\n";
      }else {
        mySqlAttribute->attributes["database"] = message;
      }


      break;
    }
    case Command::Cmd::Query:{
      std::basic_string<char> data_string;
      BufferHelper::readStringBySize(buffer_cpy, len - 1, data_string);
      auditLog.assign(data_string);
      break;
    }
    default:
      std::cout << "Unhandled request\n";
  }

  switch (cmd) {
  case Command::Cmd::InitDb:
  case Command::Cmd::CreateDb:
  case Command::Cmd::DropDb: {
    std::string db;
    BufferHelper::readStringBySize(buffer, len - 1, db);
    setDb(db);
    break;
  }
  case Command::Cmd::Query:
    is_query_ = true;
    FALLTHRU;
  default:
    BufferHelper::readStringBySize(buffer, len - 1, data_);
    break;
  }
  return DecodeStatus::Success;
}

void Command::setData(const std::string& data) { data_.assign(data); }

void Command::encode(Buffer::Instance& out) const {
  BufferHelper::addUint8(out, static_cast<int>(cmd_));
  switch (cmd_) {
  case Command::Cmd::InitDb:
  case Command::Cmd::CreateDb:
  case Command::Cmd::DropDb: {
    BufferHelper::addString(out, db_);
    break;
  }
  default:
    BufferHelper::addString(out, data_);
    break;
  }
}

DecodeStatus CommandResponse::parseMessage(Buffer::Instance& buffer, uint32_t len) {
  if(auditLog.length() != 0) {
//    int len_c = len;
    Buffer::OwnedImpl temp;
    temp.add(buffer);
//    std::cout << "printing starts here\n";
//    for(uint32_t i = 0; i < len - 10; i++) {
//      uint t = temp.peekLEInt<uint8_t>(i);
//      std::cout << t << ' ';
//    }
//    std::cout<< "|\n";
//    for(uint32_t i = 0; i < len - 10; i++) {
//      uint t = temp.peekBEInt<uint8_t>(i);
//      std::cout << t << ' ';
//    }
//    std::cout<< "|\n";
//    std::cout << "printing ends here\n";


    if(auditLog.length() > 0) {
      uint resp_code = temp.peekLEInt<uint8_t>(0);
      if(!mySqlAttribute) {
        std::cout << "It is empty\n";
        goto HEY;
      }
      switch (resp_code) {
        case MYSQL_RESP_OK:
        case EOF_MARKER:
          std::cout << auditLog << "Database: " << mySqlAttribute->attributes["database"] << " " << "Username: " << mySqlAttribute->attributes["username"] << " [Success]\n";
          auditLog.clear();
          break;
        case MYSQL_RESP_ERR:
          std::cout << auditLog << "Database: " << mySqlAttribute->attributes["database"] << " " << "Username: " << mySqlAttribute->attributes["username"] << " [Failure]\n";
          auditLog.clear();
          break;
      }
    }
  }
  HEY:
  if (BufferHelper::readStringBySize(buffer, len, data_) != DecodeStatus::Success) {
    ENVOY_LOG(debug, "error when parsing command response");
    return DecodeStatus::Failure;
  }
  return DecodeStatus::Success;
}

void CommandResponse::encode(Buffer::Instance& out) const { BufferHelper::addString(out, data_); }

} // namespace MySQLProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
