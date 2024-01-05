#pragma once

#include "source/extensions/filters/network/common/factory_base.h"
#include "source/extensions/filters/network/well_known_names.h"
#include "source/common/common/logger.h"
#include "contrib/envoy/extensions/filters/network/mysql_proxy/v3/mysql_proxy.pb.h"
#include "contrib/envoy/extensions/filters/network/mysql_proxy/v3/mysql_proxy.pb.validate.h"
#include "contrib/mysql_proxy/filters/network/source/mysql_filter.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace MySQLProxy {

class ProtocolOptionsConfigImpl : public Upstream::ProtocolOptionsConfig {
public:
    ProtocolOptionsConfigImpl(
            const envoy::extensions::filters::network::mysql_proxy::v3::MySQLProtocolOptions &
            proto_config): auth_password_(proto_config.auth_password()) {
//      for(auto x: proto_config.user_maps())
//      std::cout << x.ldap_username() << " " << x.mysql_username() << std::endl;
        auto _ = proto_config;
        std::cout <<  "*******************" << std::endl;
    }

    std::string auth_password_;

};

/**
 * Config registration for the MySQL proxy filter.
 */
class MySQLConfigFactory
    : public Common::FactoryBase<envoy::extensions::filters::network::mysql_proxy::v3::MySQLProxy,
            envoy::extensions::filters::network::mysql_proxy::v3::MySQLProtocolOptions> {
public:
  MySQLConfigFactory() : FactoryBase(NetworkFilterNames::get().MySQLProxy) {}

private:
  Network::FilterFactoryCb createFilterFactoryFromProtoTyped(
      const envoy::extensions::filters::network::mysql_proxy::v3::MySQLProxy& proto_config,
      Server::Configuration::FactoryContext& context) override;

    Upstream::ProtocolOptionsConfigConstSharedPtr createProtocolOptionsTyped(
            const envoy::extensions::filters::network::mysql_proxy::v3::MySQLProtocolOptions&
            proto_config,
            Server::Configuration::ProtocolOptionsFactoryContext&) override {
      std::cout << "\ncreateProtocolOptionsTyped " << proto_config.auth_password() << "\n\n";
      return std::make_shared<ProtocolOptionsConfigImpl>(proto_config);
    }
};

} // namespace MySQLProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
