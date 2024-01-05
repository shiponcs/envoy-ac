#include "contrib/mysql_proxy/filters/network/source/mysql_config.h"

#include <string>

#include "envoy/registry/registry.h"
#include "envoy/server/filter_config.h"

#include "absl/container/flat_hash_map.h"

#include "contrib/envoy/extensions/filters/network/mysql_proxy/v3/mysql_proxy.pb.h"
#include "contrib/envoy/extensions/filters/network/mysql_proxy/v3/mysql_proxy.pb.validate.h"
#include "contrib/mysql_proxy/filters/network/source/mysql_filter.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace MySQLProxy {

/**
 * Config registration for the MySQL proxy filter. @see NamedNetworkFilterConfigFactory.
 */
Network::FilterFactoryCb
NetworkFilters::MySQLProxy::MySQLConfigFactory::createFilterFactoryFromProtoTyped(
    const envoy::extensions::filters::network::mysql_proxy::v3::MySQLProxy& proto_config,
    Server::Configuration::FactoryContext& context) {

  ASSERT(!proto_config.stat_prefix().empty());

  const std::string stat_prefix = fmt::format("mysql.{}", proto_config.stat_prefix());

  auto credentials = proto_config.credentials();
  absl::flat_hash_map<std::string, std::string> credential_map;
  for(auto credential: credentials) {
    credential_map[credential.username()] = credential.password();
  }

  Upstream::ClusterManager& cluster_manager = context.clusterManager();
  std::string_view cluster_name = "mysql_cluster";
  Upstream::ThreadLocalCluster* cluster = cluster_manager.getThreadLocalCluster(cluster_name);
  if (!cluster) {
    /* TODO(shiponcs): generate exception and debug log if cluster is not found. */
//    ENVOY_LOG(debug, "unknown cluster '{}'", cluster_name);
//        return {AppException(AppExceptionType::InternalError,
//                             fmt::format("unknown cluster '{}'", cluster_name)),
//                absl::nullopt};
  }
  auto clusterInfo = cluster->info();
  const std::shared_ptr<const ProtocolOptionsConfigImpl> options = clusterInfo->extensionProtocolOptionsTyped<ProtocolOptionsConfigImpl>(NetworkFilterNames::get().MySQLProxy);

  std::cout << "\n\n" << options->auth_password_ << std::endl;

  MySQLFilterConfigSharedPtr filter_config(
      std::make_shared<MySQLFilterConfig>(stat_prefix, credential_map, context.scope()));
  return [filter_config](Network::FilterManager& filter_manager) -> void {
    filter_manager.addFilter(std::make_shared<MySQLFilter>(filter_config));
  };
}

/**
 * Static registration for the MySQL proxy filter. @see RegisterFactory.
 */
REGISTER_FACTORY(MySQLConfigFactory, Server::Configuration::NamedNetworkFilterConfigFactory);

} // namespace MySQLProxy
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy
