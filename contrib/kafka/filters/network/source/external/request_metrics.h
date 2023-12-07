

#pragma once

#include <array>
#include <functional>

#include "envoy/stats/scope.h"
#include "envoy/stats/stats_macros.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace Kafka {

/**
 * Generated metrics, we have a counter for each request type.
 */
#define KAFKA_REQUEST_METRICS(COUNTER)                                                             \
                                                            \
  COUNTER(produce_request)                                                     \
                                                            \
  COUNTER(fetch_request)                                                     \
                                                            \
  COUNTER(list_offsets_request)                                                     \
                                                            \
  COUNTER(metadata_request)                                                     \
                                                            \
  COUNTER(leader_and_isr_request)                                                     \
                                                            \
  COUNTER(stop_replica_request)                                                     \
                                                            \
  COUNTER(update_metadata_request)                                                     \
                                                            \
  COUNTER(controlled_shutdown_request)                                                     \
                                                            \
  COUNTER(offset_commit_request)                                                     \
                                                            \
  COUNTER(offset_fetch_request)                                                     \
                                                            \
  COUNTER(find_coordinator_request)                                                     \
                                                            \
  COUNTER(join_group_request)                                                     \
                                                            \
  COUNTER(heartbeat_request)                                                     \
                                                            \
  COUNTER(leave_group_request)                                                     \
                                                            \
  COUNTER(sync_group_request)                                                     \
                                                            \
  COUNTER(describe_groups_request)                                                     \
                                                            \
  COUNTER(list_groups_request)                                                     \
                                                            \
  COUNTER(sasl_handshake_request)                                                     \
                                                            \
  COUNTER(api_versions_request)                                                     \
                                                            \
  COUNTER(create_topics_request)                                                     \
                                                            \
  COUNTER(delete_topics_request)                                                     \
                                                            \
  COUNTER(delete_records_request)                                                     \
                                                            \
  COUNTER(init_producer_id_request)                                                     \
                                                            \
  COUNTER(offset_for_leader_epoch_request)                                                     \
                                                            \
  COUNTER(add_partitions_to_txn_request)                                                     \
                                                            \
  COUNTER(add_offsets_to_txn_request)                                                     \
                                                            \
  COUNTER(end_txn_request)                                                     \
                                                            \
  COUNTER(write_txn_markers_request)                                                     \
                                                            \
  COUNTER(txn_offset_commit_request)                                                     \
                                                            \
  COUNTER(describe_acls_request)                                                     \
                                                            \
  COUNTER(create_acls_request)                                                     \
                                                            \
  COUNTER(delete_acls_request)                                                     \
                                                            \
  COUNTER(describe_configs_request)                                                     \
                                                            \
  COUNTER(alter_configs_request)                                                     \
                                                            \
  COUNTER(alter_replica_log_dirs_request)                                                     \
                                                            \
  COUNTER(describe_log_dirs_request)                                                     \
                                                            \
  COUNTER(sasl_authenticate_request)                                                     \
                                                            \
  COUNTER(create_partitions_request)                                                     \
                                                            \
  COUNTER(create_delegation_token_request)                                                     \
                                                            \
  COUNTER(renew_delegation_token_request)                                                     \
                                                            \
  COUNTER(expire_delegation_token_request)                                                     \
                                                            \
  COUNTER(describe_delegation_token_request)                                                     \
                                                            \
  COUNTER(delete_groups_request)                                                     \
                                                            \
  COUNTER(elect_leaders_request)                                                     \
                                                            \
  COUNTER(incremental_alter_configs_request)                                                     \
                                                            \
  COUNTER(alter_partition_reassignments_request)                                                     \
                                                            \
  COUNTER(list_partition_reassignments_request)                                                     \
                                                            \
  COUNTER(offset_delete_request)                                                     \
                                                            \
  COUNTER(describe_client_quotas_request)                                                     \
                                                            \
  COUNTER(alter_client_quotas_request)                                                     \
                                                            \
  COUNTER(describe_user_scram_credentials_request)                                                     \
                                                            \
  COUNTER(alter_user_scram_credentials_request)                                                     \
                                                            \
  COUNTER(vote_request)                                                     \
                                                            \
  COUNTER(begin_quorum_epoch_request)                                                     \
                                                            \
  COUNTER(end_quorum_epoch_request)                                                     \
                                                            \
  COUNTER(describe_quorum_request)                                                     \
                                                            \
  COUNTER(alter_partition_request)                                                     \
                                                            \
  COUNTER(update_features_request)                                                     \
                                                            \
  COUNTER(envelope_request)                                                     \
                                                            \
  COUNTER(fetch_snapshot_request)                                                     \
                                                            \
  COUNTER(describe_cluster_request)                                                     \
                                                            \
  COUNTER(describe_producers_request)                                                     \
                                                            \
  COUNTER(broker_registration_request)                                                     \
                                                            \
  COUNTER(broker_heartbeat_request)                                                     \
                                                            \
  COUNTER(unregister_broker_request)                                                     \
                                                            \
  COUNTER(describe_transactions_request)                                                     \
                                                            \
  COUNTER(list_transactions_request)                                                     \
                                                            \
  COUNTER(allocate_producer_ids_request)                                                     \
                                                                                       \
  COUNTER(unknown)                                                                                 \
  COUNTER(failure)

struct KafkaRequestMetrics {
  KAFKA_REQUEST_METRICS(GENERATE_COUNTER_STRUCT)
};

/**
 * Abstraction layer over request-related metrics.
 * Pure interface so that it can be mocked easily.
 */
class RichRequestMetrics {
public:
  virtual ~RichRequestMetrics() = default;

  /**
   * Invoked when properly-parsed message is received.
   */
  virtual void onRequest(const int16_t api_key) PURE;

  /**
   * Invoked when an unknown message is received.
   */
  virtual void onUnknownRequest() PURE;

  /**
   * Invoked when a deserialization error occurs.
   */
  virtual void onBrokenRequest() PURE;
};

using RichRequestMetricsSharedPtr = std::shared_ptr<RichRequestMetrics>;

/**
 * Metrics implementation that uses Envoy Scope to store metrics.
 */
class RichRequestMetricsImpl: public RichRequestMetrics {
public:
  RichRequestMetricsImpl(Stats::Scope& scope, std::string stat_prefix): metrics_({
    KAFKA_REQUEST_METRICS(POOL_COUNTER_PREFIX(scope, fmt::format("kafka.{}.request.",
      stat_prefix)))}) {};

  void onRequest(const int16_t api_key) override {
    // Both successful message parsing & metrics list depend on protocol-generated code, what means
    // both do support the same api keys.
    switch (api_key) {
    
    case 0 :
      metrics_.produce_request_.inc();
      return;
    
    case 1 :
      metrics_.fetch_request_.inc();
      return;
    
    case 2 :
      metrics_.list_offsets_request_.inc();
      return;
    
    case 3 :
      metrics_.metadata_request_.inc();
      return;
    
    case 4 :
      metrics_.leader_and_isr_request_.inc();
      return;
    
    case 5 :
      metrics_.stop_replica_request_.inc();
      return;
    
    case 6 :
      metrics_.update_metadata_request_.inc();
      return;
    
    case 7 :
      metrics_.controlled_shutdown_request_.inc();
      return;
    
    case 8 :
      metrics_.offset_commit_request_.inc();
      return;
    
    case 9 :
      metrics_.offset_fetch_request_.inc();
      return;
    
    case 10 :
      metrics_.find_coordinator_request_.inc();
      return;
    
    case 11 :
      metrics_.join_group_request_.inc();
      return;
    
    case 12 :
      metrics_.heartbeat_request_.inc();
      return;
    
    case 13 :
      metrics_.leave_group_request_.inc();
      return;
    
    case 14 :
      metrics_.sync_group_request_.inc();
      return;
    
    case 15 :
      metrics_.describe_groups_request_.inc();
      return;
    
    case 16 :
      metrics_.list_groups_request_.inc();
      return;
    
    case 17 :
      metrics_.sasl_handshake_request_.inc();
      return;
    
    case 18 :
      metrics_.api_versions_request_.inc();
      return;
    
    case 19 :
      metrics_.create_topics_request_.inc();
      return;
    
    case 20 :
      metrics_.delete_topics_request_.inc();
      return;
    
    case 21 :
      metrics_.delete_records_request_.inc();
      return;
    
    case 22 :
      metrics_.init_producer_id_request_.inc();
      return;
    
    case 23 :
      metrics_.offset_for_leader_epoch_request_.inc();
      return;
    
    case 24 :
      metrics_.add_partitions_to_txn_request_.inc();
      return;
    
    case 25 :
      metrics_.add_offsets_to_txn_request_.inc();
      return;
    
    case 26 :
      metrics_.end_txn_request_.inc();
      return;
    
    case 27 :
      metrics_.write_txn_markers_request_.inc();
      return;
    
    case 28 :
      metrics_.txn_offset_commit_request_.inc();
      return;
    
    case 29 :
      metrics_.describe_acls_request_.inc();
      return;
    
    case 30 :
      metrics_.create_acls_request_.inc();
      return;
    
    case 31 :
      metrics_.delete_acls_request_.inc();
      return;
    
    case 32 :
      metrics_.describe_configs_request_.inc();
      return;
    
    case 33 :
      metrics_.alter_configs_request_.inc();
      return;
    
    case 34 :
      metrics_.alter_replica_log_dirs_request_.inc();
      return;
    
    case 35 :
      metrics_.describe_log_dirs_request_.inc();
      return;
    
    case 36 :
      metrics_.sasl_authenticate_request_.inc();
      return;
    
    case 37 :
      metrics_.create_partitions_request_.inc();
      return;
    
    case 38 :
      metrics_.create_delegation_token_request_.inc();
      return;
    
    case 39 :
      metrics_.renew_delegation_token_request_.inc();
      return;
    
    case 40 :
      metrics_.expire_delegation_token_request_.inc();
      return;
    
    case 41 :
      metrics_.describe_delegation_token_request_.inc();
      return;
    
    case 42 :
      metrics_.delete_groups_request_.inc();
      return;
    
    case 43 :
      metrics_.elect_leaders_request_.inc();
      return;
    
    case 44 :
      metrics_.incremental_alter_configs_request_.inc();
      return;
    
    case 45 :
      metrics_.alter_partition_reassignments_request_.inc();
      return;
    
    case 46 :
      metrics_.list_partition_reassignments_request_.inc();
      return;
    
    case 47 :
      metrics_.offset_delete_request_.inc();
      return;
    
    case 48 :
      metrics_.describe_client_quotas_request_.inc();
      return;
    
    case 49 :
      metrics_.alter_client_quotas_request_.inc();
      return;
    
    case 50 :
      metrics_.describe_user_scram_credentials_request_.inc();
      return;
    
    case 51 :
      metrics_.alter_user_scram_credentials_request_.inc();
      return;
    
    case 52 :
      metrics_.vote_request_.inc();
      return;
    
    case 53 :
      metrics_.begin_quorum_epoch_request_.inc();
      return;
    
    case 54 :
      metrics_.end_quorum_epoch_request_.inc();
      return;
    
    case 55 :
      metrics_.describe_quorum_request_.inc();
      return;
    
    case 56 :
      metrics_.alter_partition_request_.inc();
      return;
    
    case 57 :
      metrics_.update_features_request_.inc();
      return;
    
    case 58 :
      metrics_.envelope_request_.inc();
      return;
    
    case 59 :
      metrics_.fetch_snapshot_request_.inc();
      return;
    
    case 60 :
      metrics_.describe_cluster_request_.inc();
      return;
    
    case 61 :
      metrics_.describe_producers_request_.inc();
      return;
    
    case 62 :
      metrics_.broker_registration_request_.inc();
      return;
    
    case 63 :
      metrics_.broker_heartbeat_request_.inc();
      return;
    
    case 64 :
      metrics_.unregister_broker_request_.inc();
      return;
    
    case 65 :
      metrics_.describe_transactions_request_.inc();
      return;
    
    case 66 :
      metrics_.list_transactions_request_.inc();
      return;
    
    case 67 :
      metrics_.allocate_producer_ids_request_.inc();
      return;
    
    }
  }

  void onUnknownRequest() override { metrics_.unknown_.inc(); }

  void onBrokenRequest() override { metrics_.failure_.inc(); }

private:
  KafkaRequestMetrics metrics_;
};

} // namespace Kafka
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy