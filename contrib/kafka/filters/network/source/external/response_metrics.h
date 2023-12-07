

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
 * Generated metrics, we have a counter and a histogram for each request type.
 */
#define KAFKA_RESPONSE_METRICS(COUNTER, HISTOGRAM)                                                 \
                                                            \
  COUNTER(produce_response)                                                     \
  HISTOGRAM(produce_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(fetch_response)                                                     \
  HISTOGRAM(fetch_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(list_offsets_response)                                                     \
  HISTOGRAM(list_offsets_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(metadata_response)                                                     \
  HISTOGRAM(metadata_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(leader_and_isr_response)                                                     \
  HISTOGRAM(leader_and_isr_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(stop_replica_response)                                                     \
  HISTOGRAM(stop_replica_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(update_metadata_response)                                                     \
  HISTOGRAM(update_metadata_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(controlled_shutdown_response)                                                     \
  HISTOGRAM(controlled_shutdown_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(offset_commit_response)                                                     \
  HISTOGRAM(offset_commit_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(offset_fetch_response)                                                     \
  HISTOGRAM(offset_fetch_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(find_coordinator_response)                                                     \
  HISTOGRAM(find_coordinator_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(join_group_response)                                                     \
  HISTOGRAM(join_group_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(heartbeat_response)                                                     \
  HISTOGRAM(heartbeat_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(leave_group_response)                                                     \
  HISTOGRAM(leave_group_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(sync_group_response)                                                     \
  HISTOGRAM(sync_group_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_groups_response)                                                     \
  HISTOGRAM(describe_groups_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(list_groups_response)                                                     \
  HISTOGRAM(list_groups_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(sasl_handshake_response)                                                     \
  HISTOGRAM(sasl_handshake_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(api_versions_response)                                                     \
  HISTOGRAM(api_versions_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(create_topics_response)                                                     \
  HISTOGRAM(create_topics_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(delete_topics_response)                                                     \
  HISTOGRAM(delete_topics_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(delete_records_response)                                                     \
  HISTOGRAM(delete_records_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(init_producer_id_response)                                                     \
  HISTOGRAM(init_producer_id_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(offset_for_leader_epoch_response)                                                     \
  HISTOGRAM(offset_for_leader_epoch_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(add_partitions_to_txn_response)                                                     \
  HISTOGRAM(add_partitions_to_txn_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(add_offsets_to_txn_response)                                                     \
  HISTOGRAM(add_offsets_to_txn_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(end_txn_response)                                                     \
  HISTOGRAM(end_txn_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(write_txn_markers_response)                                                     \
  HISTOGRAM(write_txn_markers_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(txn_offset_commit_response)                                                     \
  HISTOGRAM(txn_offset_commit_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_acls_response)                                                     \
  HISTOGRAM(describe_acls_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(create_acls_response)                                                     \
  HISTOGRAM(create_acls_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(delete_acls_response)                                                     \
  HISTOGRAM(delete_acls_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_configs_response)                                                     \
  HISTOGRAM(describe_configs_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(alter_configs_response)                                                     \
  HISTOGRAM(alter_configs_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(alter_replica_log_dirs_response)                                                     \
  HISTOGRAM(alter_replica_log_dirs_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_log_dirs_response)                                                     \
  HISTOGRAM(describe_log_dirs_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(sasl_authenticate_response)                                                     \
  HISTOGRAM(sasl_authenticate_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(create_partitions_response)                                                     \
  HISTOGRAM(create_partitions_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(create_delegation_token_response)                                                     \
  HISTOGRAM(create_delegation_token_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(renew_delegation_token_response)                                                     \
  HISTOGRAM(renew_delegation_token_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(expire_delegation_token_response)                                                     \
  HISTOGRAM(expire_delegation_token_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_delegation_token_response)                                                     \
  HISTOGRAM(describe_delegation_token_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(delete_groups_response)                                                     \
  HISTOGRAM(delete_groups_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(elect_leaders_response)                                                     \
  HISTOGRAM(elect_leaders_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(incremental_alter_configs_response)                                                     \
  HISTOGRAM(incremental_alter_configs_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(alter_partition_reassignments_response)                                                     \
  HISTOGRAM(alter_partition_reassignments_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(list_partition_reassignments_response)                                                     \
  HISTOGRAM(list_partition_reassignments_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(offset_delete_response)                                                     \
  HISTOGRAM(offset_delete_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_client_quotas_response)                                                     \
  HISTOGRAM(describe_client_quotas_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(alter_client_quotas_response)                                                     \
  HISTOGRAM(alter_client_quotas_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_user_scram_credentials_response)                                                     \
  HISTOGRAM(describe_user_scram_credentials_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(alter_user_scram_credentials_response)                                                     \
  HISTOGRAM(alter_user_scram_credentials_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(vote_response)                                                     \
  HISTOGRAM(vote_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(begin_quorum_epoch_response)                                                     \
  HISTOGRAM(begin_quorum_epoch_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(end_quorum_epoch_response)                                                     \
  HISTOGRAM(end_quorum_epoch_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_quorum_response)                                                     \
  HISTOGRAM(describe_quorum_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(alter_partition_response)                                                     \
  HISTOGRAM(alter_partition_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(update_features_response)                                                     \
  HISTOGRAM(update_features_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(envelope_response)                                                     \
  HISTOGRAM(envelope_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(fetch_snapshot_response)                                                     \
  HISTOGRAM(fetch_snapshot_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_cluster_response)                                                     \
  HISTOGRAM(describe_cluster_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_producers_response)                                                     \
  HISTOGRAM(describe_producers_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(broker_registration_response)                                                     \
  HISTOGRAM(broker_registration_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(broker_heartbeat_response)                                                     \
  HISTOGRAM(broker_heartbeat_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(unregister_broker_response)                                                     \
  HISTOGRAM(unregister_broker_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(describe_transactions_response)                                                     \
  HISTOGRAM(describe_transactions_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(list_transactions_response)                                                     \
  HISTOGRAM(list_transactions_response_duration, Milliseconds)                            \
                                                            \
  COUNTER(allocate_producer_ids_response)                                                     \
  HISTOGRAM(allocate_producer_ids_response_duration, Milliseconds)                            \
                                                                                       \
  COUNTER(unknown)                                                                                 \
  COUNTER(failure)

struct KafkaResponseMetrics {
  KAFKA_RESPONSE_METRICS(GENERATE_COUNTER_STRUCT, GENERATE_HISTOGRAM_STRUCT)
};

/**
 * Abstraction layer over response-related metrics.
 * Pure interface so that it can be mocked easily.
 */
class RichResponseMetrics {
public:
  virtual ~RichResponseMetrics() = default;

  /**
   * Invoked when properly-parsed message is received.
   */
  virtual void onResponse(const int16_t api_key, const long long duration) PURE;

  /**
   * Invoked when an unknown message is received.
   */
  virtual void onUnknownResponse() PURE;

  /**
   * Invoked when a deserialization error occurs.
   */
  virtual void onBrokenResponse() PURE;
};

using RichResponseMetricsSharedPtr = std::shared_ptr<RichResponseMetrics>;

/**
 * Metrics implementation that uses Envoy Scope to store metrics.
 */
class RichResponseMetricsImpl: public RichResponseMetrics {
public:
  RichResponseMetricsImpl(Stats::Scope& scope, std::string stat_prefix): metrics_({
    KAFKA_RESPONSE_METRICS(POOL_COUNTER_PREFIX(scope, fmt::format("kafka.{}.response.",
      stat_prefix)), POOL_HISTOGRAM_PREFIX(scope, fmt::format("kafka.{}.response.", stat_prefix)))})
  {};

  void onResponse(const int16_t api_key, const long long duration) override {
    // Both successful message parsing & metrics list depend on protocol-generated code, what means
    // both do support the same api keys.
    switch (api_key) {
    
    case 0 :
      // Increase received message counter and update histogram with duration.
      metrics_.produce_response_.inc();
      metrics_.produce_response_duration_.recordValue(duration);
      return;
    
    case 1 :
      // Increase received message counter and update histogram with duration.
      metrics_.fetch_response_.inc();
      metrics_.fetch_response_duration_.recordValue(duration);
      return;
    
    case 2 :
      // Increase received message counter and update histogram with duration.
      metrics_.list_offsets_response_.inc();
      metrics_.list_offsets_response_duration_.recordValue(duration);
      return;
    
    case 3 :
      // Increase received message counter and update histogram with duration.
      metrics_.metadata_response_.inc();
      metrics_.metadata_response_duration_.recordValue(duration);
      return;
    
    case 4 :
      // Increase received message counter and update histogram with duration.
      metrics_.leader_and_isr_response_.inc();
      metrics_.leader_and_isr_response_duration_.recordValue(duration);
      return;
    
    case 5 :
      // Increase received message counter and update histogram with duration.
      metrics_.stop_replica_response_.inc();
      metrics_.stop_replica_response_duration_.recordValue(duration);
      return;
    
    case 6 :
      // Increase received message counter and update histogram with duration.
      metrics_.update_metadata_response_.inc();
      metrics_.update_metadata_response_duration_.recordValue(duration);
      return;
    
    case 7 :
      // Increase received message counter and update histogram with duration.
      metrics_.controlled_shutdown_response_.inc();
      metrics_.controlled_shutdown_response_duration_.recordValue(duration);
      return;
    
    case 8 :
      // Increase received message counter and update histogram with duration.
      metrics_.offset_commit_response_.inc();
      metrics_.offset_commit_response_duration_.recordValue(duration);
      return;
    
    case 9 :
      // Increase received message counter and update histogram with duration.
      metrics_.offset_fetch_response_.inc();
      metrics_.offset_fetch_response_duration_.recordValue(duration);
      return;
    
    case 10 :
      // Increase received message counter and update histogram with duration.
      metrics_.find_coordinator_response_.inc();
      metrics_.find_coordinator_response_duration_.recordValue(duration);
      return;
    
    case 11 :
      // Increase received message counter and update histogram with duration.
      metrics_.join_group_response_.inc();
      metrics_.join_group_response_duration_.recordValue(duration);
      return;
    
    case 12 :
      // Increase received message counter and update histogram with duration.
      metrics_.heartbeat_response_.inc();
      metrics_.heartbeat_response_duration_.recordValue(duration);
      return;
    
    case 13 :
      // Increase received message counter and update histogram with duration.
      metrics_.leave_group_response_.inc();
      metrics_.leave_group_response_duration_.recordValue(duration);
      return;
    
    case 14 :
      // Increase received message counter and update histogram with duration.
      metrics_.sync_group_response_.inc();
      metrics_.sync_group_response_duration_.recordValue(duration);
      return;
    
    case 15 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_groups_response_.inc();
      metrics_.describe_groups_response_duration_.recordValue(duration);
      return;
    
    case 16 :
      // Increase received message counter and update histogram with duration.
      metrics_.list_groups_response_.inc();
      metrics_.list_groups_response_duration_.recordValue(duration);
      return;
    
    case 17 :
      // Increase received message counter and update histogram with duration.
      metrics_.sasl_handshake_response_.inc();
      metrics_.sasl_handshake_response_duration_.recordValue(duration);
      return;
    
    case 18 :
      // Increase received message counter and update histogram with duration.
      metrics_.api_versions_response_.inc();
      metrics_.api_versions_response_duration_.recordValue(duration);
      return;
    
    case 19 :
      // Increase received message counter and update histogram with duration.
      metrics_.create_topics_response_.inc();
      metrics_.create_topics_response_duration_.recordValue(duration);
      return;
    
    case 20 :
      // Increase received message counter and update histogram with duration.
      metrics_.delete_topics_response_.inc();
      metrics_.delete_topics_response_duration_.recordValue(duration);
      return;
    
    case 21 :
      // Increase received message counter and update histogram with duration.
      metrics_.delete_records_response_.inc();
      metrics_.delete_records_response_duration_.recordValue(duration);
      return;
    
    case 22 :
      // Increase received message counter and update histogram with duration.
      metrics_.init_producer_id_response_.inc();
      metrics_.init_producer_id_response_duration_.recordValue(duration);
      return;
    
    case 23 :
      // Increase received message counter and update histogram with duration.
      metrics_.offset_for_leader_epoch_response_.inc();
      metrics_.offset_for_leader_epoch_response_duration_.recordValue(duration);
      return;
    
    case 24 :
      // Increase received message counter and update histogram with duration.
      metrics_.add_partitions_to_txn_response_.inc();
      metrics_.add_partitions_to_txn_response_duration_.recordValue(duration);
      return;
    
    case 25 :
      // Increase received message counter and update histogram with duration.
      metrics_.add_offsets_to_txn_response_.inc();
      metrics_.add_offsets_to_txn_response_duration_.recordValue(duration);
      return;
    
    case 26 :
      // Increase received message counter and update histogram with duration.
      metrics_.end_txn_response_.inc();
      metrics_.end_txn_response_duration_.recordValue(duration);
      return;
    
    case 27 :
      // Increase received message counter and update histogram with duration.
      metrics_.write_txn_markers_response_.inc();
      metrics_.write_txn_markers_response_duration_.recordValue(duration);
      return;
    
    case 28 :
      // Increase received message counter and update histogram with duration.
      metrics_.txn_offset_commit_response_.inc();
      metrics_.txn_offset_commit_response_duration_.recordValue(duration);
      return;
    
    case 29 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_acls_response_.inc();
      metrics_.describe_acls_response_duration_.recordValue(duration);
      return;
    
    case 30 :
      // Increase received message counter and update histogram with duration.
      metrics_.create_acls_response_.inc();
      metrics_.create_acls_response_duration_.recordValue(duration);
      return;
    
    case 31 :
      // Increase received message counter and update histogram with duration.
      metrics_.delete_acls_response_.inc();
      metrics_.delete_acls_response_duration_.recordValue(duration);
      return;
    
    case 32 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_configs_response_.inc();
      metrics_.describe_configs_response_duration_.recordValue(duration);
      return;
    
    case 33 :
      // Increase received message counter and update histogram with duration.
      metrics_.alter_configs_response_.inc();
      metrics_.alter_configs_response_duration_.recordValue(duration);
      return;
    
    case 34 :
      // Increase received message counter and update histogram with duration.
      metrics_.alter_replica_log_dirs_response_.inc();
      metrics_.alter_replica_log_dirs_response_duration_.recordValue(duration);
      return;
    
    case 35 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_log_dirs_response_.inc();
      metrics_.describe_log_dirs_response_duration_.recordValue(duration);
      return;
    
    case 36 :
      // Increase received message counter and update histogram with duration.
      metrics_.sasl_authenticate_response_.inc();
      metrics_.sasl_authenticate_response_duration_.recordValue(duration);
      return;
    
    case 37 :
      // Increase received message counter and update histogram with duration.
      metrics_.create_partitions_response_.inc();
      metrics_.create_partitions_response_duration_.recordValue(duration);
      return;
    
    case 38 :
      // Increase received message counter and update histogram with duration.
      metrics_.create_delegation_token_response_.inc();
      metrics_.create_delegation_token_response_duration_.recordValue(duration);
      return;
    
    case 39 :
      // Increase received message counter and update histogram with duration.
      metrics_.renew_delegation_token_response_.inc();
      metrics_.renew_delegation_token_response_duration_.recordValue(duration);
      return;
    
    case 40 :
      // Increase received message counter and update histogram with duration.
      metrics_.expire_delegation_token_response_.inc();
      metrics_.expire_delegation_token_response_duration_.recordValue(duration);
      return;
    
    case 41 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_delegation_token_response_.inc();
      metrics_.describe_delegation_token_response_duration_.recordValue(duration);
      return;
    
    case 42 :
      // Increase received message counter and update histogram with duration.
      metrics_.delete_groups_response_.inc();
      metrics_.delete_groups_response_duration_.recordValue(duration);
      return;
    
    case 43 :
      // Increase received message counter and update histogram with duration.
      metrics_.elect_leaders_response_.inc();
      metrics_.elect_leaders_response_duration_.recordValue(duration);
      return;
    
    case 44 :
      // Increase received message counter and update histogram with duration.
      metrics_.incremental_alter_configs_response_.inc();
      metrics_.incremental_alter_configs_response_duration_.recordValue(duration);
      return;
    
    case 45 :
      // Increase received message counter and update histogram with duration.
      metrics_.alter_partition_reassignments_response_.inc();
      metrics_.alter_partition_reassignments_response_duration_.recordValue(duration);
      return;
    
    case 46 :
      // Increase received message counter and update histogram with duration.
      metrics_.list_partition_reassignments_response_.inc();
      metrics_.list_partition_reassignments_response_duration_.recordValue(duration);
      return;
    
    case 47 :
      // Increase received message counter and update histogram with duration.
      metrics_.offset_delete_response_.inc();
      metrics_.offset_delete_response_duration_.recordValue(duration);
      return;
    
    case 48 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_client_quotas_response_.inc();
      metrics_.describe_client_quotas_response_duration_.recordValue(duration);
      return;
    
    case 49 :
      // Increase received message counter and update histogram with duration.
      metrics_.alter_client_quotas_response_.inc();
      metrics_.alter_client_quotas_response_duration_.recordValue(duration);
      return;
    
    case 50 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_user_scram_credentials_response_.inc();
      metrics_.describe_user_scram_credentials_response_duration_.recordValue(duration);
      return;
    
    case 51 :
      // Increase received message counter and update histogram with duration.
      metrics_.alter_user_scram_credentials_response_.inc();
      metrics_.alter_user_scram_credentials_response_duration_.recordValue(duration);
      return;
    
    case 52 :
      // Increase received message counter and update histogram with duration.
      metrics_.vote_response_.inc();
      metrics_.vote_response_duration_.recordValue(duration);
      return;
    
    case 53 :
      // Increase received message counter and update histogram with duration.
      metrics_.begin_quorum_epoch_response_.inc();
      metrics_.begin_quorum_epoch_response_duration_.recordValue(duration);
      return;
    
    case 54 :
      // Increase received message counter and update histogram with duration.
      metrics_.end_quorum_epoch_response_.inc();
      metrics_.end_quorum_epoch_response_duration_.recordValue(duration);
      return;
    
    case 55 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_quorum_response_.inc();
      metrics_.describe_quorum_response_duration_.recordValue(duration);
      return;
    
    case 56 :
      // Increase received message counter and update histogram with duration.
      metrics_.alter_partition_response_.inc();
      metrics_.alter_partition_response_duration_.recordValue(duration);
      return;
    
    case 57 :
      // Increase received message counter and update histogram with duration.
      metrics_.update_features_response_.inc();
      metrics_.update_features_response_duration_.recordValue(duration);
      return;
    
    case 58 :
      // Increase received message counter and update histogram with duration.
      metrics_.envelope_response_.inc();
      metrics_.envelope_response_duration_.recordValue(duration);
      return;
    
    case 59 :
      // Increase received message counter and update histogram with duration.
      metrics_.fetch_snapshot_response_.inc();
      metrics_.fetch_snapshot_response_duration_.recordValue(duration);
      return;
    
    case 60 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_cluster_response_.inc();
      metrics_.describe_cluster_response_duration_.recordValue(duration);
      return;
    
    case 61 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_producers_response_.inc();
      metrics_.describe_producers_response_duration_.recordValue(duration);
      return;
    
    case 62 :
      // Increase received message counter and update histogram with duration.
      metrics_.broker_registration_response_.inc();
      metrics_.broker_registration_response_duration_.recordValue(duration);
      return;
    
    case 63 :
      // Increase received message counter and update histogram with duration.
      metrics_.broker_heartbeat_response_.inc();
      metrics_.broker_heartbeat_response_duration_.recordValue(duration);
      return;
    
    case 64 :
      // Increase received message counter and update histogram with duration.
      metrics_.unregister_broker_response_.inc();
      metrics_.unregister_broker_response_duration_.recordValue(duration);
      return;
    
    case 65 :
      // Increase received message counter and update histogram with duration.
      metrics_.describe_transactions_response_.inc();
      metrics_.describe_transactions_response_duration_.recordValue(duration);
      return;
    
    case 66 :
      // Increase received message counter and update histogram with duration.
      metrics_.list_transactions_response_.inc();
      metrics_.list_transactions_response_duration_.recordValue(duration);
      return;
    
    case 67 :
      // Increase received message counter and update histogram with duration.
      metrics_.allocate_producer_ids_response_.inc();
      metrics_.allocate_producer_ids_response_duration_.recordValue(duration);
      return;
    
    }
  }

  void onUnknownResponse() override { metrics_.unknown_.inc(); }

  void onBrokenResponse() override { metrics_.failure_.inc(); }

private:
  KafkaResponseMetrics metrics_;
};

} // namespace Kafka
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy