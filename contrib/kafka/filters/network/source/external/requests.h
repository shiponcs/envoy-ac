
#pragma once
#include "contrib/kafka/filters/network/source/kafka_request.h"
#include "contrib/kafka/filters/network/source/kafka_request_parser.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace Kafka {


struct PartitionProduceData {

  
  
  const int32_t index_;
  const absl::optional<Bytes> records_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7, 8]
  PartitionProduceData(int32_t index, absl::optional<Bytes> records): index_{index}, records_{records}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  PartitionProduceData(int32_t index, absl::optional<Bytes> records, TaggedFields tagged_fields): index_{index}, records_{records}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(index_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(records_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(records_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(index_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(records_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(records_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const PartitionProduceData& rhs) const {
  
    return true
    && index_ == rhs.index_
    && records_ == rhs.records_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class PartitionProduceDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class PartitionProduceDataV9Deserializer:
  public CompositeDeserializerWith3Delegates<
    PartitionProduceData
    ,
      Int32Deserializer
    ,
      NullableCompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct TopicProduceData {

  
  
  const std::string name_;
  const std::vector<PartitionProduceData> partition_data_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7, 8]
  TopicProduceData(std::string name, std::vector<PartitionProduceData> partition_data): name_{name}, partition_data_{partition_data}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  TopicProduceData(std::string name, std::vector<PartitionProduceData> partition_data, TaggedFields tagged_fields): name_{name}, partition_data_{partition_data}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(partition_data_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(partition_data_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(partition_data_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(partition_data_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TopicProduceData& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_data_ == rhs.partition_data_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TopicProduceDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV0Deserializer>
    >{};

class TopicProduceDataV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV1Deserializer>
    >{};

class TopicProduceDataV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV2Deserializer>
    >{};

class TopicProduceDataV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV3Deserializer>
    >{};

class TopicProduceDataV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV4Deserializer>
    >{};

class TopicProduceDataV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV5Deserializer>
    >{};

class TopicProduceDataV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV6Deserializer>
    >{};

class TopicProduceDataV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV7Deserializer>
    >{};

class TopicProduceDataV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceDataV8Deserializer>
    >{};

class TopicProduceDataV9Deserializer:
  public CompositeDeserializerWith3Delegates<
    TopicProduceData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<PartitionProduceDataV9Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ProduceRequest {

  
  
  const absl::optional<std::string> transactional_id_;
  const int16_t acks_;
  const int32_t timeout_ms_;
  const std::vector<TopicProduceData> topic_data_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  ProduceRequest(int16_t acks, int32_t timeout_ms, std::vector<TopicProduceData> topic_data): transactional_id_{absl::nullopt}, acks_{acks}, timeout_ms_{timeout_ms}, topic_data_{topic_data}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4, 5, 6, 7, 8]
  ProduceRequest(absl::optional<std::string> transactional_id, int16_t acks, int32_t timeout_ms, std::vector<TopicProduceData> topic_data): transactional_id_{transactional_id}, acks_{acks}, timeout_ms_{timeout_ms}, topic_data_{topic_data}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  ProduceRequest(absl::optional<std::string> transactional_id, int16_t acks, int32_t timeout_ms, std::vector<TopicProduceData> topic_data, TaggedFields tagged_fields): transactional_id_{transactional_id}, acks_{acks}, timeout_ms_{timeout_ms}, topic_data_{topic_data}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 9) {
      written += encoder.computeSize(transactional_id_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(acks_);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(topic_data_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(topic_data_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 9) {
      written += encoder.encode(transactional_id_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(acks_, dst);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(topic_data_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(topic_data_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ProduceRequest& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && acks_ == rhs.acks_
    && timeout_ms_ == rhs.timeout_ms_
    && topic_data_ == rhs.topic_data_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ProduceRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ProduceRequest
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV0Deserializer>
    >{};

class ProduceRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ProduceRequest
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV1Deserializer>
    >{};

class ProduceRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ProduceRequest
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV2Deserializer>
    >{};

class ProduceRequestV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    ProduceRequest
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV3Deserializer>
    >{};

class ProduceRequestV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    ProduceRequest
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV4Deserializer>
    >{};

class ProduceRequestV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    ProduceRequest
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV5Deserializer>
    >{};

class ProduceRequestV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    ProduceRequest
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV6Deserializer>
    >{};

class ProduceRequestV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    ProduceRequest
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV7Deserializer>
    >{};

class ProduceRequestV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    ProduceRequest
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TopicProduceDataV8Deserializer>
    >{};

class ProduceRequestV9Deserializer:
  public CompositeDeserializerWith5Delegates<
    ProduceRequest
    ,
      NullableCompactStringDeserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<TopicProduceDataV9Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t PRODUCE_REQUEST_API_KEY =
  0;

constexpr int16_t PRODUCE_REQUEST_MAX_VERSION =
  9;

class ProduceRequestV0Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV0Deserializer>
{
public:
  ProduceRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV1Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV1Deserializer>
{
public:
  ProduceRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV2Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV2Deserializer>
{
public:
  ProduceRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV3Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV3Deserializer>
{
public:
  ProduceRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV4Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV4Deserializer>
{
public:
  ProduceRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV5Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV5Deserializer>
{
public:
  ProduceRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV6Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV6Deserializer>
{
public:
  ProduceRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV7Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV7Deserializer>
{
public:
  ProduceRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV8Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV8Deserializer>
{
public:
  ProduceRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ProduceRequestV9Parser:
  public RequestDataParser<
    ProduceRequest, ProduceRequestV9Deserializer>
{
public:
  ProduceRequestV9Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct FetchPartition {

  
  
  const int32_t partition_;
  const int32_t current_leader_epoch_;
  const int64_t fetch_offset_;
  const int32_t last_fetched_epoch_;
  const int64_t log_start_offset_;
  const int32_t partition_max_bytes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  FetchPartition(int32_t partition, int64_t fetch_offset, int32_t partition_max_bytes): partition_{partition}, current_leader_epoch_{-1}, fetch_offset_{fetch_offset}, last_fetched_epoch_{-1}, log_start_offset_{-1}, partition_max_bytes_{partition_max_bytes}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7, 8]
  FetchPartition(int32_t partition, int64_t fetch_offset, int64_t log_start_offset, int32_t partition_max_bytes): partition_{partition}, current_leader_epoch_{-1}, fetch_offset_{fetch_offset}, last_fetched_epoch_{-1}, log_start_offset_{log_start_offset}, partition_max_bytes_{partition_max_bytes}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9, 10, 11]
  FetchPartition(int32_t partition, int32_t current_leader_epoch, int64_t fetch_offset, int64_t log_start_offset, int32_t partition_max_bytes): partition_{partition}, current_leader_epoch_{current_leader_epoch}, fetch_offset_{fetch_offset}, last_fetched_epoch_{-1}, log_start_offset_{log_start_offset}, partition_max_bytes_{partition_max_bytes}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12, 13, 14, 15]
  FetchPartition(int32_t partition, int32_t current_leader_epoch, int64_t fetch_offset, int32_t last_fetched_epoch, int64_t log_start_offset, int32_t partition_max_bytes, TaggedFields tagged_fields): partition_{partition}, current_leader_epoch_{current_leader_epoch}, fetch_offset_{fetch_offset}, last_fetched_epoch_{last_fetched_epoch}, log_start_offset_{log_start_offset}, partition_max_bytes_{partition_max_bytes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(partition_);
    }
    
    if (api_version >= 9 && api_version < 16) {
      written += encoder.computeSize(current_leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(fetch_offset_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeSize(last_fetched_epoch_);
    }
    
    if (api_version >= 5 && api_version < 16) {
      written += encoder.computeSize(log_start_offset_);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(partition_max_bytes_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.encode(partition_, dst);
    }
    
    if (api_version >= 9 && api_version < 16) {
      written += encoder.encode(current_leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.encode(fetch_offset_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encode(last_fetched_epoch_, dst);
    }
    
    if (api_version >= 5 && api_version < 16) {
      written += encoder.encode(log_start_offset_, dst);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.encode(partition_max_bytes_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FetchPartition& rhs) const {
  
    return true
    && partition_ == rhs.partition_
    && current_leader_epoch_ == rhs.current_leader_epoch_
    && fetch_offset_ == rhs.fetch_offset_
    && last_fetched_epoch_ == rhs.last_fetched_epoch_
    && log_start_offset_ == rhs.log_start_offset_
    && partition_max_bytes_ == rhs.partition_max_bytes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchPartitionV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV9Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV10Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV11Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class FetchPartitionV12Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchPartitionV13Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchPartitionV14Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchPartitionV15Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct FetchTopic {

  
  
  const std::string topic_;
  const Uuid topic_id_;
  const std::vector<FetchPartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
  FetchTopic(std::string topic, std::vector<FetchPartition> partitions): topic_{topic}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12]
  FetchTopic(std::string topic, std::vector<FetchPartition> partitions, TaggedFields tagged_fields): topic_{topic}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [13, 14, 15]
  FetchTopic(Uuid topic_id, std::vector<FetchPartition> partitions, TaggedFields tagged_fields): topic_{""}, topic_id_{topic_id}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.computeSize(topic_);
    }
    
    if (api_version >= 12 && api_version < 13) {
      written += encoder.computeCompactSize(topic_);
    }
    
    if (api_version >= 13 && api_version < 16) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.encode(topic_, dst);
    }
    
    if (api_version >= 12 && api_version < 13) {
      written += encoder.encodeCompact(topic_, dst);
    }
    
    if (api_version >= 13 && api_version < 16) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FetchTopic& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && topic_id_ == rhs.topic_id_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV0Deserializer>
    >{};

class FetchTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV1Deserializer>
    >{};

class FetchTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV2Deserializer>
    >{};

class FetchTopicV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV3Deserializer>
    >{};

class FetchTopicV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV4Deserializer>
    >{};

class FetchTopicV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV5Deserializer>
    >{};

class FetchTopicV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV6Deserializer>
    >{};

class FetchTopicV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV7Deserializer>
    >{};

class FetchTopicV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV8Deserializer>
    >{};

class FetchTopicV9Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV9Deserializer>
    >{};

class FetchTopicV10Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV10Deserializer>
    >{};

class FetchTopicV11Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchPartitionV11Deserializer>
    >{};

class FetchTopicV12Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<FetchPartitionV12Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchTopicV13Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchTopic
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<FetchPartitionV13Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchTopicV14Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchTopic
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<FetchPartitionV14Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchTopicV15Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchTopic
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<FetchPartitionV15Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ForgottenTopic {

  
  
  const std::string topic_;
  const Uuid topic_id_;
  const std::vector<int32_t> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [7, 8, 9, 10, 11]
  ForgottenTopic(std::string topic, std::vector<int32_t> partitions): topic_{topic}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12]
  ForgottenTopic(std::string topic, std::vector<int32_t> partitions, TaggedFields tagged_fields): topic_{topic}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [13, 14, 15]
  ForgottenTopic(Uuid topic_id, std::vector<int32_t> partitions, TaggedFields tagged_fields): topic_{""}, topic_id_{topic_id}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 7 && api_version < 12) {
      written += encoder.computeSize(topic_);
    }
    
    if (api_version >= 12 && api_version < 13) {
      written += encoder.computeCompactSize(topic_);
    }
    
    if (api_version >= 13 && api_version < 16) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 7 && api_version < 12) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 7 && api_version < 12) {
      written += encoder.encode(topic_, dst);
    }
    
    if (api_version >= 12 && api_version < 13) {
      written += encoder.encodeCompact(topic_, dst);
    }
    
    if (api_version >= 13 && api_version < 16) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 7 && api_version < 12) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ForgottenTopic& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && topic_id_ == rhs.topic_id_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ForgottenTopicV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    ForgottenTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class ForgottenTopicV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    ForgottenTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class ForgottenTopicV9Deserializer:
  public CompositeDeserializerWith2Delegates<
    ForgottenTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class ForgottenTopicV10Deserializer:
  public CompositeDeserializerWith2Delegates<
    ForgottenTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class ForgottenTopicV11Deserializer:
  public CompositeDeserializerWith2Delegates<
    ForgottenTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class ForgottenTopicV12Deserializer:
  public CompositeDeserializerWith3Delegates<
    ForgottenTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ForgottenTopicV13Deserializer:
  public CompositeDeserializerWith3Delegates<
    ForgottenTopic
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ForgottenTopicV14Deserializer:
  public CompositeDeserializerWith3Delegates<
    ForgottenTopic
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ForgottenTopicV15Deserializer:
  public CompositeDeserializerWith3Delegates<
    ForgottenTopic
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct FetchRequest {

  
  
  const int32_t replica_id_;
  const int32_t max_wait_ms_;
  const int32_t min_bytes_;
  const int32_t max_bytes_;
  const int8_t isolation_level_;
  const int32_t session_id_;
  const int32_t session_epoch_;
  const std::vector<FetchTopic> topics_;
  const std::vector<ForgottenTopic> forgotten_topics_data_;
  const std::string rack_id_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  FetchRequest(int32_t replica_id, int32_t max_wait_ms, int32_t min_bytes, std::vector<FetchTopic> topics): replica_id_{replica_id}, max_wait_ms_{max_wait_ms}, min_bytes_{min_bytes}, max_bytes_{0x7fffffff}, isolation_level_{0}, session_id_{0}, session_epoch_{-1}, topics_{topics}, forgotten_topics_data_{std::vector<ForgottenTopic>{}}, rack_id_{}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  FetchRequest(int32_t replica_id, int32_t max_wait_ms, int32_t min_bytes, int32_t max_bytes, std::vector<FetchTopic> topics): replica_id_{replica_id}, max_wait_ms_{max_wait_ms}, min_bytes_{min_bytes}, max_bytes_{max_bytes}, isolation_level_{0}, session_id_{0}, session_epoch_{-1}, topics_{topics}, forgotten_topics_data_{std::vector<ForgottenTopic>{}}, rack_id_{}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5, 6]
  FetchRequest(int32_t replica_id, int32_t max_wait_ms, int32_t min_bytes, int32_t max_bytes, int8_t isolation_level, std::vector<FetchTopic> topics): replica_id_{replica_id}, max_wait_ms_{max_wait_ms}, min_bytes_{min_bytes}, max_bytes_{max_bytes}, isolation_level_{isolation_level}, session_id_{0}, session_epoch_{-1}, topics_{topics}, forgotten_topics_data_{std::vector<ForgottenTopic>{}}, rack_id_{}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [7, 8, 9, 10]
  FetchRequest(int32_t replica_id, int32_t max_wait_ms, int32_t min_bytes, int32_t max_bytes, int8_t isolation_level, int32_t session_id, int32_t session_epoch, std::vector<FetchTopic> topics, std::vector<ForgottenTopic> forgotten_topics_data): replica_id_{replica_id}, max_wait_ms_{max_wait_ms}, min_bytes_{min_bytes}, max_bytes_{max_bytes}, isolation_level_{isolation_level}, session_id_{session_id}, session_epoch_{session_epoch}, topics_{topics}, forgotten_topics_data_{forgotten_topics_data}, rack_id_{}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [11]
  FetchRequest(int32_t replica_id, int32_t max_wait_ms, int32_t min_bytes, int32_t max_bytes, int8_t isolation_level, int32_t session_id, int32_t session_epoch, std::vector<FetchTopic> topics, std::vector<ForgottenTopic> forgotten_topics_data, std::string rack_id): replica_id_{replica_id}, max_wait_ms_{max_wait_ms}, min_bytes_{min_bytes}, max_bytes_{max_bytes}, isolation_level_{isolation_level}, session_id_{session_id}, session_epoch_{session_epoch}, topics_{topics}, forgotten_topics_data_{forgotten_topics_data}, rack_id_{rack_id}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12, 13, 14]
  FetchRequest(int32_t replica_id, int32_t max_wait_ms, int32_t min_bytes, int32_t max_bytes, int8_t isolation_level, int32_t session_id, int32_t session_epoch, std::vector<FetchTopic> topics, std::vector<ForgottenTopic> forgotten_topics_data, std::string rack_id, TaggedFields tagged_fields): replica_id_{replica_id}, max_wait_ms_{max_wait_ms}, min_bytes_{min_bytes}, max_bytes_{max_bytes}, isolation_level_{isolation_level}, session_id_{session_id}, session_epoch_{session_epoch}, topics_{topics}, forgotten_topics_data_{forgotten_topics_data}, rack_id_{rack_id}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [15]
  FetchRequest(int32_t max_wait_ms, int32_t min_bytes, int32_t max_bytes, int8_t isolation_level, int32_t session_id, int32_t session_epoch, std::vector<FetchTopic> topics, std::vector<ForgottenTopic> forgotten_topics_data, std::string rack_id, TaggedFields tagged_fields): replica_id_{-1}, max_wait_ms_{max_wait_ms}, min_bytes_{min_bytes}, max_bytes_{max_bytes}, isolation_level_{isolation_level}, session_id_{session_id}, session_epoch_{session_epoch}, topics_{topics}, forgotten_topics_data_{forgotten_topics_data}, rack_id_{rack_id}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 15) {
      written += encoder.computeSize(replica_id_);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(max_wait_ms_);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(min_bytes_);
    }
    
    if (api_version >= 3 && api_version < 16) {
      written += encoder.computeSize(max_bytes_);
    }
    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.computeSize(isolation_level_);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.computeSize(session_id_);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.computeSize(session_epoch_);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 7 && api_version < 12) {
      written += encoder.computeSize(forgotten_topics_data_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(forgotten_topics_data_);
    }
    
    if (api_version >= 11 && api_version < 12) {
      written += encoder.computeSize(rack_id_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(rack_id_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 15) {
      written += encoder.encode(replica_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.encode(max_wait_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.encode(min_bytes_, dst);
    }
    
    if (api_version >= 3 && api_version < 16) {
      written += encoder.encode(max_bytes_, dst);
    }
    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.encode(isolation_level_, dst);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.encode(session_id_, dst);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.encode(session_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 7 && api_version < 12) {
      written += encoder.encode(forgotten_topics_data_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(forgotten_topics_data_, dst);
    }
    
    if (api_version >= 11 && api_version < 12) {
      written += encoder.encode(rack_id_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(rack_id_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FetchRequest& rhs) const {
  
    return true
    && replica_id_ == rhs.replica_id_
    && max_wait_ms_ == rhs.max_wait_ms_
    && min_bytes_ == rhs.min_bytes_
    && max_bytes_ == rhs.max_bytes_
    && isolation_level_ == rhs.isolation_level_
    && session_id_ == rhs.session_id_
    && session_epoch_ == rhs.session_epoch_
    && topics_ == rhs.topics_
    && forgotten_topics_data_ == rhs.forgotten_topics_data_
    && rack_id_ == rhs.rack_id_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV0Deserializer>
    >{};

class FetchRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV1Deserializer>
    >{};

class FetchRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV2Deserializer>
    >{};

class FetchRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV3Deserializer>
    >{};

class FetchRequestV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<FetchTopicV4Deserializer>
    >{};

class FetchRequestV5Deserializer:
  public CompositeDeserializerWith6Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<FetchTopicV5Deserializer>
    >{};

class FetchRequestV6Deserializer:
  public CompositeDeserializerWith6Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<FetchTopicV6Deserializer>
    >{};

class FetchRequestV7Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV7Deserializer>
    ,
      ArrayDeserializer<ForgottenTopicV7Deserializer>
    >{};

class FetchRequestV8Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV8Deserializer>
    ,
      ArrayDeserializer<ForgottenTopicV8Deserializer>
    >{};

class FetchRequestV9Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV9Deserializer>
    ,
      ArrayDeserializer<ForgottenTopicV9Deserializer>
    >{};

class FetchRequestV10Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV10Deserializer>
    ,
      ArrayDeserializer<ForgottenTopicV10Deserializer>
    >{};

class FetchRequestV11Deserializer:
  public CompositeDeserializerWith10Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchTopicV11Deserializer>
    ,
      ArrayDeserializer<ForgottenTopicV11Deserializer>
    ,
      StringDeserializer
    >{};

class FetchRequestV12Deserializer:
  public CompositeDeserializerWith11Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchTopicV12Deserializer>
    ,
      CompactArrayDeserializer<ForgottenTopicV12Deserializer>
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchRequestV13Deserializer:
  public CompositeDeserializerWith11Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchTopicV13Deserializer>
    ,
      CompactArrayDeserializer<ForgottenTopicV13Deserializer>
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchRequestV14Deserializer:
  public CompositeDeserializerWith11Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchTopicV14Deserializer>
    ,
      CompactArrayDeserializer<ForgottenTopicV14Deserializer>
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchRequestV15Deserializer:
  public CompositeDeserializerWith10Delegates<
    FetchRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchTopicV15Deserializer>
    ,
      CompactArrayDeserializer<ForgottenTopicV15Deserializer>
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t FETCH_REQUEST_API_KEY =
  1;

constexpr int16_t FETCH_REQUEST_MAX_VERSION =
  15;

class FetchRequestV0Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV0Deserializer>
{
public:
  FetchRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV1Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV1Deserializer>
{
public:
  FetchRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV2Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV2Deserializer>
{
public:
  FetchRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV3Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV3Deserializer>
{
public:
  FetchRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV4Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV4Deserializer>
{
public:
  FetchRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV5Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV5Deserializer>
{
public:
  FetchRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV6Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV6Deserializer>
{
public:
  FetchRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV7Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV7Deserializer>
{
public:
  FetchRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV8Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV8Deserializer>
{
public:
  FetchRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV9Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV9Deserializer>
{
public:
  FetchRequestV9Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV10Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV10Deserializer>
{
public:
  FetchRequestV10Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV11Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV11Deserializer>
{
public:
  FetchRequestV11Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV12Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV12Deserializer>
{
public:
  FetchRequestV12Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV13Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV13Deserializer>
{
public:
  FetchRequestV13Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV14Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV14Deserializer>
{
public:
  FetchRequestV14Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FetchRequestV15Parser:
  public RequestDataParser<
    FetchRequest, FetchRequestV15Deserializer>
{
public:
  FetchRequestV15Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ListOffsetsPartition {

  
  
  const int32_t partition_index_;
  const int32_t current_leader_epoch_;
  const int64_t timestamp_;
  const int32_t max_num_offsets_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListOffsetsPartition(int32_t partition_index, int64_t timestamp, int32_t max_num_offsets): partition_index_{partition_index}, current_leader_epoch_{-1}, timestamp_{timestamp}, max_num_offsets_{max_num_offsets}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3]
  ListOffsetsPartition(int32_t partition_index, int64_t timestamp): partition_index_{partition_index}, current_leader_epoch_{-1}, timestamp_{timestamp}, max_num_offsets_{1}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  ListOffsetsPartition(int32_t partition_index, int32_t current_leader_epoch, int64_t timestamp): partition_index_{partition_index}, current_leader_epoch_{current_leader_epoch}, timestamp_{timestamp}, max_num_offsets_{1}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  ListOffsetsPartition(int32_t partition_index, int32_t current_leader_epoch, int64_t timestamp, TaggedFields tagged_fields): partition_index_{partition_index}, current_leader_epoch_{current_leader_epoch}, timestamp_{timestamp}, max_num_offsets_{1}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 4 && api_version < 9) {
      written += encoder.computeSize(current_leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(timestamp_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(max_num_offsets_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 4 && api_version < 9) {
      written += encoder.encode(current_leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(timestamp_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(max_num_offsets_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListOffsetsPartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && current_leader_epoch_ == rhs.current_leader_epoch_
    && timestamp_ == rhs.timestamp_
    && max_num_offsets_ == rhs.max_num_offsets_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListOffsetsPartitionV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class ListOffsetsPartitionV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsPartitionV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsPartitionV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ListOffsetsTopic {

  
  
  const std::string name_;
  const std::vector<ListOffsetsPartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5]
  ListOffsetsTopic(std::string name, std::vector<ListOffsetsPartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  ListOffsetsTopic(std::string name, std::vector<ListOffsetsPartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListOffsetsTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListOffsetsTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionV0Deserializer>
    >{};

class ListOffsetsTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionV1Deserializer>
    >{};

class ListOffsetsTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionV2Deserializer>
    >{};

class ListOffsetsTopicV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionV3Deserializer>
    >{};

class ListOffsetsTopicV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionV4Deserializer>
    >{};

class ListOffsetsTopicV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionV5Deserializer>
    >{};

class ListOffsetsTopicV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ListOffsetsPartitionV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsTopicV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ListOffsetsPartitionV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsTopicV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ListOffsetsPartitionV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ListOffsetsRequest {

  
  
  const int32_t replica_id_;
  const int8_t isolation_level_;
  const std::vector<ListOffsetsTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  ListOffsetsRequest(int32_t replica_id, std::vector<ListOffsetsTopic> topics): replica_id_{replica_id}, isolation_level_{0}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4, 5]
  ListOffsetsRequest(int32_t replica_id, int8_t isolation_level, std::vector<ListOffsetsTopic> topics): replica_id_{replica_id}, isolation_level_{isolation_level}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  ListOffsetsRequest(int32_t replica_id, int8_t isolation_level, std::vector<ListOffsetsTopic> topics, TaggedFields tagged_fields): replica_id_{replica_id}, isolation_level_{isolation_level}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(replica_id_);
    }
    
    if (api_version >= 2 && api_version < 9) {
      written += encoder.computeSize(isolation_level_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(replica_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 9) {
      written += encoder.encode(isolation_level_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListOffsetsRequest& rhs) const {
  
    return true
    && replica_id_ == rhs.replica_id_
    && isolation_level_ == rhs.isolation_level_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListOffsetsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicV0Deserializer>
    >{};

class ListOffsetsRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicV1Deserializer>
    >{};

class ListOffsetsRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicV2Deserializer>
    >{};

class ListOffsetsRequestV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicV3Deserializer>
    >{};

class ListOffsetsRequestV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicV4Deserializer>
    >{};

class ListOffsetsRequestV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicV5Deserializer>
    >{};

class ListOffsetsRequestV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<ListOffsetsTopicV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsRequestV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<ListOffsetsTopicV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsRequestV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsRequest
    ,
      Int32Deserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<ListOffsetsTopicV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t LIST_OFFSETS_REQUEST_API_KEY =
  2;

constexpr int16_t LIST_OFFSETS_REQUEST_MAX_VERSION =
  8;

class ListOffsetsRequestV0Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV0Deserializer>
{
public:
  ListOffsetsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV1Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV1Deserializer>
{
public:
  ListOffsetsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV2Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV2Deserializer>
{
public:
  ListOffsetsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV3Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV3Deserializer>
{
public:
  ListOffsetsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV4Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV4Deserializer>
{
public:
  ListOffsetsRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV5Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV5Deserializer>
{
public:
  ListOffsetsRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV6Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV6Deserializer>
{
public:
  ListOffsetsRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV7Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV7Deserializer>
{
public:
  ListOffsetsRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListOffsetsRequestV8Parser:
  public RequestDataParser<
    ListOffsetsRequest, ListOffsetsRequestV8Deserializer>
{
public:
  ListOffsetsRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct MetadataRequestTopic {

  
  
  const Uuid topic_id_;
  const absl::optional<std::string> name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7, 8]
  MetadataRequestTopic(std::string name): topic_id_{Uuid{0, 0}}, name_{absl::make_optional(name)}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  MetadataRequestTopic(std::string name, TaggedFields tagged_fields): topic_id_{Uuid{0, 0}}, name_{absl::make_optional(name)}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [10, 11, 12]
  MetadataRequestTopic(Uuid topic_id, absl::optional<std::string> name, TaggedFields tagged_fields): topic_id_{topic_id}, name_{name}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 10 && api_version < 13) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 10 && api_version < 13) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MetadataRequestTopic& rhs) const {
  
    return true
    && topic_id_ == rhs.topic_id_
    && name_ == rhs.name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MetadataRequestTopicV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV2Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV3Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV4Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV5Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV6Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV7Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV8Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequestTopic
    ,
      StringDeserializer
    >{};

class MetadataRequestTopicV9Deserializer:
  public CompositeDeserializerWith2Delegates<
    MetadataRequestTopic
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataRequestTopicV10Deserializer:
  public CompositeDeserializerWith3Delegates<
    MetadataRequestTopic
    ,
      UuidDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataRequestTopicV11Deserializer:
  public CompositeDeserializerWith3Delegates<
    MetadataRequestTopic
    ,
      UuidDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataRequestTopicV12Deserializer:
  public CompositeDeserializerWith3Delegates<
    MetadataRequestTopic
    ,
      UuidDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct MetadataRequest {

  
  
  const absl::optional<std::vector<MetadataRequestTopic>> topics_;
  const bool allow_auto_topic_creation_;
  const bool include_cluster_authorized_operations_;
  const bool include_topic_authorized_operations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  MetadataRequest(std::vector<MetadataRequestTopic> topics): topics_{absl::make_optional(topics)}, allow_auto_topic_creation_{true}, include_cluster_authorized_operations_{false}, include_topic_authorized_operations_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3]
  MetadataRequest(absl::optional<std::vector<MetadataRequestTopic>> topics): topics_{topics}, allow_auto_topic_creation_{true}, include_cluster_authorized_operations_{false}, include_topic_authorized_operations_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5, 6, 7]
  MetadataRequest(absl::optional<std::vector<MetadataRequestTopic>> topics, bool allow_auto_topic_creation): topics_{topics}, allow_auto_topic_creation_{allow_auto_topic_creation}, include_cluster_authorized_operations_{false}, include_topic_authorized_operations_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  MetadataRequest(absl::optional<std::vector<MetadataRequestTopic>> topics, bool allow_auto_topic_creation, bool include_cluster_authorized_operations, bool include_topic_authorized_operations): topics_{topics}, allow_auto_topic_creation_{allow_auto_topic_creation}, include_cluster_authorized_operations_{include_cluster_authorized_operations}, include_topic_authorized_operations_{include_topic_authorized_operations}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9, 10]
  MetadataRequest(absl::optional<std::vector<MetadataRequestTopic>> topics, bool allow_auto_topic_creation, bool include_cluster_authorized_operations, bool include_topic_authorized_operations, TaggedFields tagged_fields): topics_{topics}, allow_auto_topic_creation_{allow_auto_topic_creation}, include_cluster_authorized_operations_{include_cluster_authorized_operations}, include_topic_authorized_operations_{include_topic_authorized_operations}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [11, 12]
  MetadataRequest(absl::optional<std::vector<MetadataRequestTopic>> topics, bool allow_auto_topic_creation, bool include_topic_authorized_operations, TaggedFields tagged_fields): topics_{topics}, allow_auto_topic_creation_{allow_auto_topic_creation}, include_cluster_authorized_operations_{false}, include_topic_authorized_operations_{include_topic_authorized_operations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 4 && api_version < 13) {
      written += encoder.computeSize(allow_auto_topic_creation_);
    }
    
    if (api_version >= 8 && api_version < 11) {
      written += encoder.computeSize(include_cluster_authorized_operations_);
    }
    
    if (api_version >= 8 && api_version < 13) {
      written += encoder.computeSize(include_topic_authorized_operations_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 4 && api_version < 13) {
      written += encoder.encode(allow_auto_topic_creation_, dst);
    }
    
    if (api_version >= 8 && api_version < 11) {
      written += encoder.encode(include_cluster_authorized_operations_, dst);
    }
    
    if (api_version >= 8 && api_version < 13) {
      written += encoder.encode(include_topic_authorized_operations_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MetadataRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && allow_auto_topic_creation_ == rhs.allow_auto_topic_creation_
    && include_cluster_authorized_operations_ == rhs.include_cluster_authorized_operations_
    && include_topic_authorized_operations_ == rhs.include_topic_authorized_operations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MetadataRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequest
    ,
      ArrayDeserializer<MetadataRequestTopicV0Deserializer>
    >{};

class MetadataRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV1Deserializer>
    >{};

class MetadataRequestV2Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV2Deserializer>
    >{};

class MetadataRequestV3Deserializer:
  public CompositeDeserializerWith1Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV3Deserializer>
    >{};

class MetadataRequestV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV4Deserializer>
    ,
      BooleanDeserializer
    >{};

class MetadataRequestV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV5Deserializer>
    ,
      BooleanDeserializer
    >{};

class MetadataRequestV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV6Deserializer>
    ,
      BooleanDeserializer
    >{};

class MetadataRequestV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV7Deserializer>
    ,
      BooleanDeserializer
    >{};

class MetadataRequestV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataRequest
    ,
      NullableArrayDeserializer<MetadataRequestTopicV8Deserializer>
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    >{};

class MetadataRequestV9Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataRequest
    ,
      NullableCompactArrayDeserializer<MetadataRequestTopicV9Deserializer>
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataRequestV10Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataRequest
    ,
      NullableCompactArrayDeserializer<MetadataRequestTopicV10Deserializer>
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataRequestV11Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataRequest
    ,
      NullableCompactArrayDeserializer<MetadataRequestTopicV11Deserializer>
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataRequestV12Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataRequest
    ,
      NullableCompactArrayDeserializer<MetadataRequestTopicV12Deserializer>
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t METADATA_REQUEST_API_KEY =
  3;

constexpr int16_t METADATA_REQUEST_MAX_VERSION =
  12;

class MetadataRequestV0Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV0Deserializer>
{
public:
  MetadataRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV1Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV1Deserializer>
{
public:
  MetadataRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV2Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV2Deserializer>
{
public:
  MetadataRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV3Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV3Deserializer>
{
public:
  MetadataRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV4Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV4Deserializer>
{
public:
  MetadataRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV5Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV5Deserializer>
{
public:
  MetadataRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV6Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV6Deserializer>
{
public:
  MetadataRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV7Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV7Deserializer>
{
public:
  MetadataRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV8Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV8Deserializer>
{
public:
  MetadataRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV9Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV9Deserializer>
{
public:
  MetadataRequestV9Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV10Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV10Deserializer>
{
public:
  MetadataRequestV10Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV11Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV11Deserializer>
{
public:
  MetadataRequestV11Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class MetadataRequestV12Parser:
  public RequestDataParser<
    MetadataRequest, MetadataRequestV12Deserializer>
{
public:
  MetadataRequestV12Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct LeaderAndIsrPartitionState {

  
  
  const std::string topic_name_;
  const int32_t partition_index_;
  const int32_t controller_epoch_;
  const int32_t leader_;
  const int32_t leader_epoch_;
  const std::vector<int32_t> isr_;
  const int32_t partition_epoch_;
  const std::vector<int32_t> replicas_;
  const std::vector<int32_t> adding_replicas_;
  const std::vector<int32_t> removing_replicas_;
  const bool is_new_;
  const int8_t leader_recovery_state_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  LeaderAndIsrPartitionState(std::string topic_name, int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t partition_epoch, std::vector<int32_t> replicas): topic_name_{topic_name}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, partition_epoch_{partition_epoch}, replicas_{replicas}, adding_replicas_{std::vector<int32_t>{}}, removing_replicas_{std::vector<int32_t>{}}, is_new_{false}, leader_recovery_state_{0}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  LeaderAndIsrPartitionState(std::string topic_name, int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t partition_epoch, std::vector<int32_t> replicas, bool is_new): topic_name_{topic_name}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, partition_epoch_{partition_epoch}, replicas_{replicas}, adding_replicas_{std::vector<int32_t>{}}, removing_replicas_{std::vector<int32_t>{}}, is_new_{is_new}, leader_recovery_state_{0}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  LeaderAndIsrPartitionState(int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t partition_epoch, std::vector<int32_t> replicas, bool is_new): topic_name_{""}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, partition_epoch_{partition_epoch}, replicas_{replicas}, adding_replicas_{std::vector<int32_t>{}}, removing_replicas_{std::vector<int32_t>{}}, is_new_{is_new}, leader_recovery_state_{0}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  LeaderAndIsrPartitionState(int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t partition_epoch, std::vector<int32_t> replicas, std::vector<int32_t> adding_replicas, std::vector<int32_t> removing_replicas, bool is_new): topic_name_{""}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, partition_epoch_{partition_epoch}, replicas_{replicas}, adding_replicas_{adding_replicas}, removing_replicas_{removing_replicas}, is_new_{is_new}, leader_recovery_state_{0}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  LeaderAndIsrPartitionState(int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t partition_epoch, std::vector<int32_t> replicas, std::vector<int32_t> adding_replicas, std::vector<int32_t> removing_replicas, bool is_new, TaggedFields tagged_fields): topic_name_{""}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, partition_epoch_{partition_epoch}, replicas_{replicas}, adding_replicas_{adding_replicas}, removing_replicas_{removing_replicas}, is_new_{is_new}, leader_recovery_state_{0}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [6, 7]
  LeaderAndIsrPartitionState(int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t partition_epoch, std::vector<int32_t> replicas, std::vector<int32_t> adding_replicas, std::vector<int32_t> removing_replicas, bool is_new, int8_t leader_recovery_state, TaggedFields tagged_fields): topic_name_{""}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, partition_epoch_{partition_epoch}, replicas_{replicas}, adding_replicas_{adding_replicas}, removing_replicas_{removing_replicas}, is_new_{is_new}, leader_recovery_state_{leader_recovery_state}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(controller_epoch_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(leader_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(isr_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(isr_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(partition_epoch_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(replicas_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(replicas_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(adding_replicas_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(adding_replicas_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(removing_replicas_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(removing_replicas_);
    }
    
    if (api_version >= 1 && api_version < 8) {
      written += encoder.computeSize(is_new_);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.computeSize(leader_recovery_state_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(controller_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(leader_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(isr_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(isr_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(partition_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(replicas_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(replicas_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(adding_replicas_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(adding_replicas_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(removing_replicas_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(removing_replicas_, dst);
    }
    
    if (api_version >= 1 && api_version < 8) {
      written += encoder.encode(is_new_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encode(leader_recovery_state_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaderAndIsrPartitionState& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partition_index_ == rhs.partition_index_
    && controller_epoch_ == rhs.controller_epoch_
    && leader_ == rhs.leader_
    && leader_epoch_ == rhs.leader_epoch_
    && isr_ == rhs.isr_
    && partition_epoch_ == rhs.partition_epoch_
    && replicas_ == rhs.replicas_
    && adding_replicas_ == rhs.adding_replicas_
    && removing_replicas_ == rhs.removing_replicas_
    && is_new_ == rhs.is_new_
    && leader_recovery_state_ == rhs.leader_recovery_state_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaderAndIsrPartitionStateV0Deserializer:
  public CompositeDeserializerWith8Delegates<
    LeaderAndIsrPartitionState
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class LeaderAndIsrPartitionStateV1Deserializer:
  public CompositeDeserializerWith9Delegates<
    LeaderAndIsrPartitionState
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      BooleanDeserializer
    >{};

class LeaderAndIsrPartitionStateV2Deserializer:
  public CompositeDeserializerWith8Delegates<
    LeaderAndIsrPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      BooleanDeserializer
    >{};

class LeaderAndIsrPartitionStateV3Deserializer:
  public CompositeDeserializerWith10Delegates<
    LeaderAndIsrPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      BooleanDeserializer
    >{};

class LeaderAndIsrPartitionStateV4Deserializer:
  public CompositeDeserializerWith11Delegates<
    LeaderAndIsrPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrPartitionStateV5Deserializer:
  public CompositeDeserializerWith11Delegates<
    LeaderAndIsrPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrPartitionStateV6Deserializer:
  public CompositeDeserializerWith12Delegates<
    LeaderAndIsrPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrPartitionStateV7Deserializer:
  public CompositeDeserializerWith12Delegates<
    LeaderAndIsrPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct LeaderAndIsrTopicState {

  
  
  const std::string topic_name_;
  const Uuid topic_id_;
  const std::vector<LeaderAndIsrPartitionState> partition_states_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [2, 3]
  LeaderAndIsrTopicState(std::string topic_name, std::vector<LeaderAndIsrPartitionState> partition_states): topic_name_{topic_name}, topic_id_{Uuid{0, 0}}, partition_states_{partition_states}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  LeaderAndIsrTopicState(std::string topic_name, std::vector<LeaderAndIsrPartitionState> partition_states, TaggedFields tagged_fields): topic_name_{topic_name}, topic_id_{Uuid{0, 0}}, partition_states_{partition_states}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5, 6, 7]
  LeaderAndIsrTopicState(std::string topic_name, Uuid topic_id, std::vector<LeaderAndIsrPartitionState> partition_states, TaggedFields tagged_fields): topic_name_{topic_name}, topic_id_{topic_id}, partition_states_{partition_states}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeSize(partition_states_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(partition_states_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encode(partition_states_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(partition_states_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaderAndIsrTopicState& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && topic_id_ == rhs.topic_id_
    && partition_states_ == rhs.partition_states_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaderAndIsrTopicStateV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaderAndIsrTopicState
    ,
      StringDeserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionStateV2Deserializer>
    >{};

class LeaderAndIsrTopicStateV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaderAndIsrTopicState
    ,
      StringDeserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionStateV3Deserializer>
    >{};

class LeaderAndIsrTopicStateV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrTopicState
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionStateV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrTopicStateV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrTopicState
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionStateV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrTopicStateV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrTopicState
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionStateV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrTopicStateV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrTopicState
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionStateV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct LeaderAndIsrLiveLeader {

  
  
  const int32_t broker_id_;
  const std::string host_name_;
  const int32_t port_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  LeaderAndIsrLiveLeader(int32_t broker_id, std::string host_name, int32_t port): broker_id_{broker_id}, host_name_{host_name}, port_{port}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5, 6, 7]
  LeaderAndIsrLiveLeader(int32_t broker_id, std::string host_name, int32_t port, TaggedFields tagged_fields): broker_id_{broker_id}, host_name_{host_name}, port_{port}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(host_name_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(host_name_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(port_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(host_name_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(host_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(port_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaderAndIsrLiveLeader& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && host_name_ == rhs.host_name_
    && port_ == rhs.port_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaderAndIsrLiveLeaderV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class LeaderAndIsrLiveLeaderV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class LeaderAndIsrLiveLeaderV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class LeaderAndIsrLiveLeaderV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class LeaderAndIsrLiveLeaderV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrLiveLeaderV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrLiveLeaderV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrLiveLeaderV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrLiveLeader
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct LeaderAndIsrRequest {

  
  
  const int32_t controller_id_;
  const bool is_k_raft_controller_;
  const int32_t controller_epoch_;
  const int64_t broker_epoch_;
  const int8_t type_;
  const std::vector<LeaderAndIsrPartitionState> ungrouped_partition_states_;
  const std::vector<LeaderAndIsrTopicState> topic_states_;
  const std::vector<LeaderAndIsrLiveLeader> live_leaders_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  LeaderAndIsrRequest(int32_t controller_id, int32_t controller_epoch, std::vector<LeaderAndIsrPartitionState> ungrouped_partition_states, std::vector<LeaderAndIsrLiveLeader> live_leaders): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{-1}, type_{0}, ungrouped_partition_states_{ungrouped_partition_states}, topic_states_{std::vector<LeaderAndIsrTopicState>{}}, live_leaders_{live_leaders}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  LeaderAndIsrRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, std::vector<LeaderAndIsrTopicState> topic_states, std::vector<LeaderAndIsrLiveLeader> live_leaders): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, type_{0}, ungrouped_partition_states_{std::vector<LeaderAndIsrPartitionState>{}}, topic_states_{topic_states}, live_leaders_{live_leaders}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  LeaderAndIsrRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, std::vector<LeaderAndIsrTopicState> topic_states, std::vector<LeaderAndIsrLiveLeader> live_leaders, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, type_{0}, ungrouped_partition_states_{std::vector<LeaderAndIsrPartitionState>{}}, topic_states_{topic_states}, live_leaders_{live_leaders}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5, 6]
  LeaderAndIsrRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, int8_t type, std::vector<LeaderAndIsrTopicState> topic_states, std::vector<LeaderAndIsrLiveLeader> live_leaders, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, type_{type}, ungrouped_partition_states_{std::vector<LeaderAndIsrPartitionState>{}}, topic_states_{topic_states}, live_leaders_{live_leaders}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [7]
  LeaderAndIsrRequest(int32_t controller_id, bool is_k_raft_controller, int32_t controller_epoch, int64_t broker_epoch, int8_t type, std::vector<LeaderAndIsrTopicState> topic_states, std::vector<LeaderAndIsrLiveLeader> live_leaders, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{is_k_raft_controller}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, type_{type}, ungrouped_partition_states_{std::vector<LeaderAndIsrPartitionState>{}}, topic_states_{topic_states}, live_leaders_{live_leaders}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(controller_id_);
    }
    
    if (api_version >= 7 && api_version < 8) {
      written += encoder.computeSize(is_k_raft_controller_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(controller_epoch_);
    }
    
    if (api_version >= 2 && api_version < 8) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(ungrouped_partition_states_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeSize(topic_states_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(topic_states_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(live_leaders_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(live_leaders_);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(controller_id_, dst);
    }
    
    if (api_version >= 7 && api_version < 8) {
      written += encoder.encode(is_k_raft_controller_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(controller_epoch_, dst);
    }
    
    if (api_version >= 2 && api_version < 8) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(ungrouped_partition_states_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encode(topic_states_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(topic_states_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(live_leaders_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(live_leaders_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaderAndIsrRequest& rhs) const {
  
    return true
    && controller_id_ == rhs.controller_id_
    && is_k_raft_controller_ == rhs.is_k_raft_controller_
    && controller_epoch_ == rhs.controller_epoch_
    && broker_epoch_ == rhs.broker_epoch_
    && type_ == rhs.type_
    && ungrouped_partition_states_ == rhs.ungrouped_partition_states_
    && topic_states_ == rhs.topic_states_
    && live_leaders_ == rhs.live_leaders_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaderAndIsrRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionStateV0Deserializer>
    ,
      ArrayDeserializer<LeaderAndIsrLiveLeaderV0Deserializer>
    >{};

class LeaderAndIsrRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionStateV1Deserializer>
    ,
      ArrayDeserializer<LeaderAndIsrLiveLeaderV1Deserializer>
    >{};

class LeaderAndIsrRequestV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrTopicStateV2Deserializer>
    ,
      ArrayDeserializer<LeaderAndIsrLiveLeaderV2Deserializer>
    >{};

class LeaderAndIsrRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrTopicStateV3Deserializer>
    ,
      ArrayDeserializer<LeaderAndIsrLiveLeaderV3Deserializer>
    >{};

class LeaderAndIsrRequestV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrTopicStateV4Deserializer>
    ,
      CompactArrayDeserializer<LeaderAndIsrLiveLeaderV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrRequestV5Deserializer:
  public CompositeDeserializerWith7Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrTopicStateV5Deserializer>
    ,
      CompactArrayDeserializer<LeaderAndIsrLiveLeaderV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrRequestV6Deserializer:
  public CompositeDeserializerWith7Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrTopicStateV6Deserializer>
    ,
      CompactArrayDeserializer<LeaderAndIsrLiveLeaderV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrRequestV7Deserializer:
  public CompositeDeserializerWith8Delegates<
    LeaderAndIsrRequest
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrTopicStateV7Deserializer>
    ,
      CompactArrayDeserializer<LeaderAndIsrLiveLeaderV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t LEADER_AND_ISR_REQUEST_API_KEY =
  4;

constexpr int16_t LEADER_AND_ISR_REQUEST_MAX_VERSION =
  7;

class LeaderAndIsrRequestV0Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV0Deserializer>
{
public:
  LeaderAndIsrRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaderAndIsrRequestV1Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV1Deserializer>
{
public:
  LeaderAndIsrRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaderAndIsrRequestV2Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV2Deserializer>
{
public:
  LeaderAndIsrRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaderAndIsrRequestV3Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV3Deserializer>
{
public:
  LeaderAndIsrRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaderAndIsrRequestV4Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV4Deserializer>
{
public:
  LeaderAndIsrRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaderAndIsrRequestV5Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV5Deserializer>
{
public:
  LeaderAndIsrRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaderAndIsrRequestV6Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV6Deserializer>
{
public:
  LeaderAndIsrRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaderAndIsrRequestV7Parser:
  public RequestDataParser<
    LeaderAndIsrRequest, LeaderAndIsrRequestV7Deserializer>
{
public:
  LeaderAndIsrRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct StopReplicaPartitionV0 {

  
  
  const std::string topic_name_;
  const int32_t partition_index_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  StopReplicaPartitionV0(std::string topic_name, int32_t partition_index): topic_name_{topic_name}, partition_index_{partition_index}, tagged_fields_{TaggedFields({})} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const StopReplicaPartitionV0& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partition_index_ == rhs.partition_index_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class StopReplicaPartitionV0V0Deserializer:
  public CompositeDeserializerWith2Delegates<
    StopReplicaPartitionV0
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};


struct StopReplicaTopicV1 {

  
  
  const std::string name_;
  const std::vector<int32_t> partition_indexes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [1]
  StopReplicaTopicV1(std::string name, std::vector<int32_t> partition_indexes): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  StopReplicaTopicV1(std::string name, std::vector<int32_t> partition_indexes, TaggedFields tagged_fields): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(partition_indexes_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(partition_indexes_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(partition_indexes_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(partition_indexes_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const StopReplicaTopicV1& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_indexes_ == rhs.partition_indexes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class StopReplicaTopicV1V1Deserializer:
  public CompositeDeserializerWith2Delegates<
    StopReplicaTopicV1
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class StopReplicaTopicV1V2Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaTopicV1
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct StopReplicaPartitionState {

  
  
  const int32_t partition_index_;
  const int32_t leader_epoch_;
  const bool delete_partition_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [3, 4]
  StopReplicaPartitionState(int32_t partition_index, int32_t leader_epoch, bool delete_partition, TaggedFields tagged_fields): partition_index_{partition_index}, leader_epoch_{leader_epoch}, delete_partition_{delete_partition}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(delete_partition_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(delete_partition_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const StopReplicaPartitionState& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && leader_epoch_ == rhs.leader_epoch_
    && delete_partition_ == rhs.delete_partition_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class StopReplicaPartitionStateV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    StopReplicaPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaPartitionStateV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    StopReplicaPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct StopReplicaTopicState {

  
  
  const std::string topic_name_;
  const std::vector<StopReplicaPartitionState> partition_states_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [3, 4]
  StopReplicaTopicState(std::string topic_name, std::vector<StopReplicaPartitionState> partition_states, TaggedFields tagged_fields): topic_name_{topic_name}, partition_states_{partition_states}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(partition_states_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(partition_states_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const StopReplicaTopicState& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partition_states_ == rhs.partition_states_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class StopReplicaTopicStateV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaTopicState
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<StopReplicaPartitionStateV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaTopicStateV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaTopicState
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<StopReplicaPartitionStateV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct StopReplicaRequest {

  
  
  const int32_t controller_id_;
  const bool is_k_raft_controller_;
  const int32_t controller_epoch_;
  const int64_t broker_epoch_;
  const bool delete_partitions_;
  const std::vector<StopReplicaPartitionV0> ungrouped_partitions_;
  const std::vector<StopReplicaTopicV1> topics_;
  const std::vector<StopReplicaTopicState> topic_states_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  StopReplicaRequest(int32_t controller_id, int32_t controller_epoch, bool delete_partitions, std::vector<StopReplicaPartitionV0> ungrouped_partitions): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{-1}, delete_partitions_{delete_partitions}, ungrouped_partitions_{ungrouped_partitions}, topics_{std::vector<StopReplicaTopicV1>{}}, topic_states_{std::vector<StopReplicaTopicState>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  StopReplicaRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, bool delete_partitions, std::vector<StopReplicaTopicV1> topics): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, delete_partitions_{delete_partitions}, ungrouped_partitions_{std::vector<StopReplicaPartitionV0>{}}, topics_{topics}, topic_states_{std::vector<StopReplicaTopicState>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  StopReplicaRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, bool delete_partitions, std::vector<StopReplicaTopicV1> topics, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, delete_partitions_{delete_partitions}, ungrouped_partitions_{std::vector<StopReplicaPartitionV0>{}}, topics_{topics}, topic_states_{std::vector<StopReplicaTopicState>{}}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [3]
  StopReplicaRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, std::vector<StopReplicaTopicState> topic_states, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, delete_partitions_{false}, ungrouped_partitions_{std::vector<StopReplicaPartitionV0>{}}, topics_{std::vector<StopReplicaTopicV1>{}}, topic_states_{topic_states}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  StopReplicaRequest(int32_t controller_id, bool is_k_raft_controller, int32_t controller_epoch, int64_t broker_epoch, std::vector<StopReplicaTopicState> topic_states, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{is_k_raft_controller}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, delete_partitions_{false}, ungrouped_partitions_{std::vector<StopReplicaPartitionV0>{}}, topics_{std::vector<StopReplicaTopicV1>{}}, topic_states_{topic_states}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(controller_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(is_k_raft_controller_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(controller_epoch_);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(delete_partitions_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(ungrouped_partitions_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(topic_states_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(controller_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(is_k_raft_controller_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(controller_epoch_, dst);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(delete_partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(ungrouped_partitions_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(topic_states_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const StopReplicaRequest& rhs) const {
  
    return true
    && controller_id_ == rhs.controller_id_
    && is_k_raft_controller_ == rhs.is_k_raft_controller_
    && controller_epoch_ == rhs.controller_epoch_
    && broker_epoch_ == rhs.broker_epoch_
    && delete_partitions_ == rhs.delete_partitions_
    && ungrouped_partitions_ == rhs.ungrouped_partitions_
    && topics_ == rhs.topics_
    && topic_states_ == rhs.topic_states_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class StopReplicaRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    StopReplicaRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<StopReplicaPartitionV0V0Deserializer>
    >{};

class StopReplicaRequestV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    StopReplicaRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<StopReplicaTopicV1V1Deserializer>
    >{};

class StopReplicaRequestV2Deserializer:
  public CompositeDeserializerWith6Delegates<
    StopReplicaRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<StopReplicaTopicV1V2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    StopReplicaRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<StopReplicaTopicStateV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaRequestV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    StopReplicaRequest
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<StopReplicaTopicStateV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t STOP_REPLICA_REQUEST_API_KEY =
  5;

constexpr int16_t STOP_REPLICA_REQUEST_MAX_VERSION =
  4;

class StopReplicaRequestV0Parser:
  public RequestDataParser<
    StopReplicaRequest, StopReplicaRequestV0Deserializer>
{
public:
  StopReplicaRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class StopReplicaRequestV1Parser:
  public RequestDataParser<
    StopReplicaRequest, StopReplicaRequestV1Deserializer>
{
public:
  StopReplicaRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class StopReplicaRequestV2Parser:
  public RequestDataParser<
    StopReplicaRequest, StopReplicaRequestV2Deserializer>
{
public:
  StopReplicaRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class StopReplicaRequestV3Parser:
  public RequestDataParser<
    StopReplicaRequest, StopReplicaRequestV3Deserializer>
{
public:
  StopReplicaRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class StopReplicaRequestV4Parser:
  public RequestDataParser<
    StopReplicaRequest, StopReplicaRequestV4Deserializer>
{
public:
  StopReplicaRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct UpdateMetadataPartitionState {

  
  
  const std::string topic_name_;
  const int32_t partition_index_;
  const int32_t controller_epoch_;
  const int32_t leader_;
  const int32_t leader_epoch_;
  const std::vector<int32_t> isr_;
  const int32_t zk_version_;
  const std::vector<int32_t> replicas_;
  const std::vector<int32_t> offline_replicas_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  UpdateMetadataPartitionState(std::string topic_name, int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t zk_version, std::vector<int32_t> replicas): topic_name_{topic_name}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, zk_version_{zk_version}, replicas_{replicas}, offline_replicas_{std::vector<int32_t>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  UpdateMetadataPartitionState(std::string topic_name, int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t zk_version, std::vector<int32_t> replicas, std::vector<int32_t> offline_replicas): topic_name_{topic_name}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, zk_version_{zk_version}, replicas_{replicas}, offline_replicas_{offline_replicas}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  UpdateMetadataPartitionState(int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t zk_version, std::vector<int32_t> replicas, std::vector<int32_t> offline_replicas): topic_name_{""}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, zk_version_{zk_version}, replicas_{replicas}, offline_replicas_{offline_replicas}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  UpdateMetadataPartitionState(int32_t partition_index, int32_t controller_epoch, int32_t leader, int32_t leader_epoch, std::vector<int32_t> isr, int32_t zk_version, std::vector<int32_t> replicas, std::vector<int32_t> offline_replicas, TaggedFields tagged_fields): topic_name_{""}, partition_index_{partition_index}, controller_epoch_{controller_epoch}, leader_{leader}, leader_epoch_{leader_epoch}, isr_{isr}, zk_version_{zk_version}, replicas_{replicas}, offline_replicas_{offline_replicas}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(controller_epoch_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(leader_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(isr_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(isr_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(zk_version_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(replicas_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(replicas_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeSize(offline_replicas_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(offline_replicas_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(controller_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(leader_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(isr_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(isr_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(zk_version_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(replicas_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(replicas_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encode(offline_replicas_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(offline_replicas_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateMetadataPartitionState& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partition_index_ == rhs.partition_index_
    && controller_epoch_ == rhs.controller_epoch_
    && leader_ == rhs.leader_
    && leader_epoch_ == rhs.leader_epoch_
    && isr_ == rhs.isr_
    && zk_version_ == rhs.zk_version_
    && replicas_ == rhs.replicas_
    && offline_replicas_ == rhs.offline_replicas_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateMetadataPartitionStateV0Deserializer:
  public CompositeDeserializerWith8Delegates<
    UpdateMetadataPartitionState
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class UpdateMetadataPartitionStateV1Deserializer:
  public CompositeDeserializerWith8Delegates<
    UpdateMetadataPartitionState
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class UpdateMetadataPartitionStateV2Deserializer:
  public CompositeDeserializerWith8Delegates<
    UpdateMetadataPartitionState
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class UpdateMetadataPartitionStateV3Deserializer:
  public CompositeDeserializerWith8Delegates<
    UpdateMetadataPartitionState
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class UpdateMetadataPartitionStateV4Deserializer:
  public CompositeDeserializerWith9Delegates<
    UpdateMetadataPartitionState
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class UpdateMetadataPartitionStateV5Deserializer:
  public CompositeDeserializerWith8Delegates<
    UpdateMetadataPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class UpdateMetadataPartitionStateV6Deserializer:
  public CompositeDeserializerWith9Delegates<
    UpdateMetadataPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataPartitionStateV7Deserializer:
  public CompositeDeserializerWith9Delegates<
    UpdateMetadataPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataPartitionStateV8Deserializer:
  public CompositeDeserializerWith9Delegates<
    UpdateMetadataPartitionState
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct UpdateMetadataTopicState {

  
  
  const std::string topic_name_;
  const Uuid topic_id_;
  const std::vector<UpdateMetadataPartitionState> partition_states_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [5]
  UpdateMetadataTopicState(std::string topic_name, std::vector<UpdateMetadataPartitionState> partition_states): topic_name_{topic_name}, topic_id_{Uuid{0, 0}}, partition_states_{partition_states}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6]
  UpdateMetadataTopicState(std::string topic_name, std::vector<UpdateMetadataPartitionState> partition_states, TaggedFields tagged_fields): topic_name_{topic_name}, topic_id_{Uuid{0, 0}}, partition_states_{partition_states}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [7, 8]
  UpdateMetadataTopicState(std::string topic_name, Uuid topic_id, std::vector<UpdateMetadataPartitionState> partition_states, TaggedFields tagged_fields): topic_name_{topic_name}, topic_id_{topic_id}, partition_states_{partition_states}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 7 && api_version < 9) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeSize(partition_states_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(partition_states_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 7 && api_version < 9) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encode(partition_states_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(partition_states_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateMetadataTopicState& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && topic_id_ == rhs.topic_id_
    && partition_states_ == rhs.partition_states_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateMetadataTopicStateV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    UpdateMetadataTopicState
    ,
      StringDeserializer
    ,
      ArrayDeserializer<UpdateMetadataPartitionStateV5Deserializer>
    >{};

class UpdateMetadataTopicStateV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataTopicState
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<UpdateMetadataPartitionStateV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataTopicStateV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataTopicState
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<UpdateMetadataPartitionStateV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataTopicStateV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataTopicState
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<UpdateMetadataPartitionStateV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct UpdateMetadataEndpoint {

  
  
  const int32_t port_;
  const std::string host_;
  const std::string listener_;
  const int16_t security_protocol_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [1, 2]
  UpdateMetadataEndpoint(int32_t port, std::string host, int16_t security_protocol): port_{port}, host_{host}, listener_{""}, security_protocol_{security_protocol}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4, 5]
  UpdateMetadataEndpoint(int32_t port, std::string host, std::string listener, int16_t security_protocol): port_{port}, host_{host}, listener_{listener}, security_protocol_{security_protocol}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  UpdateMetadataEndpoint(int32_t port, std::string host, std::string listener, int16_t security_protocol, TaggedFields tagged_fields): port_{port}, host_{host}, listener_{listener}, security_protocol_{security_protocol}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.computeSize(port_);
    }
    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.computeSize(host_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(host_);
    }
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.computeSize(listener_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(listener_);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.computeSize(security_protocol_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.encode(port_, dst);
    }
    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.encode(host_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(host_, dst);
    }
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.encode(listener_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(listener_, dst);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.encode(security_protocol_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateMetadataEndpoint& rhs) const {
  
    return true
    && port_ == rhs.port_
    && host_ == rhs.host_
    && listener_ == rhs.listener_
    && security_protocol_ == rhs.security_protocol_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateMetadataEndpointV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class UpdateMetadataEndpointV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class UpdateMetadataEndpointV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class UpdateMetadataEndpointV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class UpdateMetadataEndpointV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class UpdateMetadataEndpointV6Deserializer:
  public CompositeDeserializerWith5Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataEndpointV7Deserializer:
  public CompositeDeserializerWith5Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataEndpointV8Deserializer:
  public CompositeDeserializerWith5Delegates<
    UpdateMetadataEndpoint
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct UpdateMetadataBroker {

  
  
  const int32_t id_;
  const std::string v0_host_;
  const int32_t v0_port_;
  const std::vector<UpdateMetadataEndpoint> endpoints_;
  const absl::optional<std::string> rack_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  UpdateMetadataBroker(int32_t id, std::string v0_host, int32_t v0_port): id_{id}, v0_host_{v0_host}, v0_port_{v0_port}, endpoints_{std::vector<UpdateMetadataEndpoint>{}}, rack_{{""}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  UpdateMetadataBroker(int32_t id, std::vector<UpdateMetadataEndpoint> endpoints): id_{id}, v0_host_{""}, v0_port_{0}, endpoints_{endpoints}, rack_{{""}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4, 5]
  UpdateMetadataBroker(int32_t id, std::vector<UpdateMetadataEndpoint> endpoints, absl::optional<std::string> rack): id_{id}, v0_host_{""}, v0_port_{0}, endpoints_{endpoints}, rack_{rack}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  UpdateMetadataBroker(int32_t id, std::vector<UpdateMetadataEndpoint> endpoints, absl::optional<std::string> rack, TaggedFields tagged_fields): id_{id}, v0_host_{""}, v0_port_{0}, endpoints_{endpoints}, rack_{rack}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(v0_host_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(v0_port_);
    }
    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.computeSize(endpoints_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(endpoints_);
    }
    
    if (api_version >= 2 && api_version < 6) {
      written += encoder.computeSize(rack_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(rack_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(v0_host_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(v0_port_, dst);
    }
    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.encode(endpoints_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(endpoints_, dst);
    }
    
    if (api_version >= 2 && api_version < 6) {
      written += encoder.encode(rack_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(rack_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateMetadataBroker& rhs) const {
  
    return true
    && id_ == rhs.id_
    && v0_host_ == rhs.v0_host_
    && v0_port_ == rhs.v0_port_
    && endpoints_ == rhs.endpoints_
    && rack_ == rhs.rack_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateMetadataBrokerV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class UpdateMetadataBrokerV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataEndpointV1Deserializer>
    >{};

class UpdateMetadataBrokerV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataEndpointV2Deserializer>
    ,
      NullableStringDeserializer
    >{};

class UpdateMetadataBrokerV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataEndpointV3Deserializer>
    ,
      NullableStringDeserializer
    >{};

class UpdateMetadataBrokerV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataEndpointV4Deserializer>
    ,
      NullableStringDeserializer
    >{};

class UpdateMetadataBrokerV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataEndpointV5Deserializer>
    ,
      NullableStringDeserializer
    >{};

class UpdateMetadataBrokerV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<UpdateMetadataEndpointV6Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataBrokerV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<UpdateMetadataEndpointV7Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataBrokerV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataBroker
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<UpdateMetadataEndpointV8Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct UpdateMetadataRequest {

  
  
  const int32_t controller_id_;
  const bool is_k_raft_controller_;
  const int32_t controller_epoch_;
  const int64_t broker_epoch_;
  const std::vector<UpdateMetadataPartitionState> ungrouped_partition_states_;
  const std::vector<UpdateMetadataTopicState> topic_states_;
  const std::vector<UpdateMetadataBroker> live_brokers_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  UpdateMetadataRequest(int32_t controller_id, int32_t controller_epoch, std::vector<UpdateMetadataPartitionState> ungrouped_partition_states, std::vector<UpdateMetadataBroker> live_brokers): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{-1}, ungrouped_partition_states_{ungrouped_partition_states}, topic_states_{std::vector<UpdateMetadataTopicState>{}}, live_brokers_{live_brokers}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  UpdateMetadataRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, std::vector<UpdateMetadataTopicState> topic_states, std::vector<UpdateMetadataBroker> live_brokers): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, ungrouped_partition_states_{std::vector<UpdateMetadataPartitionState>{}}, topic_states_{topic_states}, live_brokers_{live_brokers}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7]
  UpdateMetadataRequest(int32_t controller_id, int32_t controller_epoch, int64_t broker_epoch, std::vector<UpdateMetadataTopicState> topic_states, std::vector<UpdateMetadataBroker> live_brokers, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{false}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, ungrouped_partition_states_{std::vector<UpdateMetadataPartitionState>{}}, topic_states_{topic_states}, live_brokers_{live_brokers}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [8]
  UpdateMetadataRequest(int32_t controller_id, bool is_k_raft_controller, int32_t controller_epoch, int64_t broker_epoch, std::vector<UpdateMetadataTopicState> topic_states, std::vector<UpdateMetadataBroker> live_brokers, TaggedFields tagged_fields): controller_id_{controller_id}, is_k_raft_controller_{is_k_raft_controller}, controller_epoch_{controller_epoch}, broker_epoch_{broker_epoch}, ungrouped_partition_states_{std::vector<UpdateMetadataPartitionState>{}}, topic_states_{topic_states}, live_brokers_{live_brokers}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(controller_id_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(is_k_raft_controller_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(controller_epoch_);
    }
    
    if (api_version >= 5 && api_version < 9) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(ungrouped_partition_states_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeSize(topic_states_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(topic_states_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(live_brokers_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(live_brokers_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(controller_id_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(is_k_raft_controller_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(controller_epoch_, dst);
    }
    
    if (api_version >= 5 && api_version < 9) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(ungrouped_partition_states_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encode(topic_states_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(topic_states_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(live_brokers_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(live_brokers_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateMetadataRequest& rhs) const {
  
    return true
    && controller_id_ == rhs.controller_id_
    && is_k_raft_controller_ == rhs.is_k_raft_controller_
    && controller_epoch_ == rhs.controller_epoch_
    && broker_epoch_ == rhs.broker_epoch_
    && ungrouped_partition_states_ == rhs.ungrouped_partition_states_
    && topic_states_ == rhs.topic_states_
    && live_brokers_ == rhs.live_brokers_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateMetadataRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataPartitionStateV0Deserializer>
    ,
      ArrayDeserializer<UpdateMetadataBrokerV0Deserializer>
    >{};

class UpdateMetadataRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataPartitionStateV1Deserializer>
    ,
      ArrayDeserializer<UpdateMetadataBrokerV1Deserializer>
    >{};

class UpdateMetadataRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataPartitionStateV2Deserializer>
    ,
      ArrayDeserializer<UpdateMetadataBrokerV2Deserializer>
    >{};

class UpdateMetadataRequestV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataPartitionStateV3Deserializer>
    ,
      ArrayDeserializer<UpdateMetadataBrokerV3Deserializer>
    >{};

class UpdateMetadataRequestV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<UpdateMetadataPartitionStateV4Deserializer>
    ,
      ArrayDeserializer<UpdateMetadataBrokerV4Deserializer>
    >{};

class UpdateMetadataRequestV5Deserializer:
  public CompositeDeserializerWith5Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<UpdateMetadataTopicStateV5Deserializer>
    ,
      ArrayDeserializer<UpdateMetadataBrokerV5Deserializer>
    >{};

class UpdateMetadataRequestV6Deserializer:
  public CompositeDeserializerWith6Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<UpdateMetadataTopicStateV6Deserializer>
    ,
      CompactArrayDeserializer<UpdateMetadataBrokerV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataRequestV7Deserializer:
  public CompositeDeserializerWith6Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<UpdateMetadataTopicStateV7Deserializer>
    ,
      CompactArrayDeserializer<UpdateMetadataBrokerV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataRequestV8Deserializer:
  public CompositeDeserializerWith7Delegates<
    UpdateMetadataRequest
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<UpdateMetadataTopicStateV8Deserializer>
    ,
      CompactArrayDeserializer<UpdateMetadataBrokerV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t UPDATE_METADATA_REQUEST_API_KEY =
  6;

constexpr int16_t UPDATE_METADATA_REQUEST_MAX_VERSION =
  8;

class UpdateMetadataRequestV0Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV0Deserializer>
{
public:
  UpdateMetadataRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV1Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV1Deserializer>
{
public:
  UpdateMetadataRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV2Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV2Deserializer>
{
public:
  UpdateMetadataRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV3Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV3Deserializer>
{
public:
  UpdateMetadataRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV4Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV4Deserializer>
{
public:
  UpdateMetadataRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV5Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV5Deserializer>
{
public:
  UpdateMetadataRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV6Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV6Deserializer>
{
public:
  UpdateMetadataRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV7Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV7Deserializer>
{
public:
  UpdateMetadataRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateMetadataRequestV8Parser:
  public RequestDataParser<
    UpdateMetadataRequest, UpdateMetadataRequestV8Deserializer>
{
public:
  UpdateMetadataRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ControlledShutdownRequest {

  
  
  const int32_t broker_id_;
  const int64_t broker_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  ControlledShutdownRequest(int32_t broker_id): broker_id_{broker_id}, broker_epoch_{-1}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  ControlledShutdownRequest(int32_t broker_id, int64_t broker_epoch): broker_id_{broker_id}, broker_epoch_{broker_epoch}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  ControlledShutdownRequest(int32_t broker_id, int64_t broker_epoch, TaggedFields tagged_fields): broker_id_{broker_id}, broker_epoch_{broker_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ControlledShutdownRequest& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && broker_epoch_ == rhs.broker_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ControlledShutdownRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    ControlledShutdownRequest
    ,
      Int32Deserializer
    >{};

class ControlledShutdownRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    ControlledShutdownRequest
    ,
      Int32Deserializer
    >{};

class ControlledShutdownRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ControlledShutdownRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class ControlledShutdownRequestV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    ControlledShutdownRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t CONTROLLED_SHUTDOWN_REQUEST_API_KEY =
  7;

constexpr int16_t CONTROLLED_SHUTDOWN_REQUEST_MAX_VERSION =
  3;

class ControlledShutdownRequestV0Parser:
  public RequestDataParser<
    ControlledShutdownRequest, ControlledShutdownRequestV0Deserializer>
{
public:
  ControlledShutdownRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ControlledShutdownRequestV1Parser:
  public RequestDataParser<
    ControlledShutdownRequest, ControlledShutdownRequestV1Deserializer>
{
public:
  ControlledShutdownRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ControlledShutdownRequestV2Parser:
  public RequestDataParser<
    ControlledShutdownRequest, ControlledShutdownRequestV2Deserializer>
{
public:
  ControlledShutdownRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ControlledShutdownRequestV3Parser:
  public RequestDataParser<
    ControlledShutdownRequest, ControlledShutdownRequestV3Deserializer>
{
public:
  ControlledShutdownRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct OffsetCommitRequestPartition {

  
  
  const int32_t partition_index_;
  const int64_t committed_offset_;
  const int32_t committed_leader_epoch_;
  const int64_t commit_timestamp_;
  const absl::optional<std::string> committed_metadata_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 2, 3, 4, 5]
  OffsetCommitRequestPartition(int32_t partition_index, int64_t committed_offset, absl::optional<std::string> committed_metadata): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{-1}, commit_timestamp_{-1}, committed_metadata_{committed_metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  OffsetCommitRequestPartition(int32_t partition_index, int64_t committed_offset, int64_t commit_timestamp, absl::optional<std::string> committed_metadata): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{-1}, commit_timestamp_{commit_timestamp}, committed_metadata_{committed_metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7]
  OffsetCommitRequestPartition(int32_t partition_index, int64_t committed_offset, int32_t committed_leader_epoch, absl::optional<std::string> committed_metadata): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{committed_leader_epoch}, commit_timestamp_{-1}, committed_metadata_{committed_metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  OffsetCommitRequestPartition(int32_t partition_index, int64_t committed_offset, int32_t committed_leader_epoch, absl::optional<std::string> committed_metadata, TaggedFields tagged_fields): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{committed_leader_epoch}, commit_timestamp_{-1}, committed_metadata_{committed_metadata}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(committed_offset_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeSize(committed_leader_epoch_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(commit_timestamp_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(committed_metadata_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(committed_metadata_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(committed_offset_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encode(committed_leader_epoch_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(commit_timestamp_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(committed_metadata_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(committed_metadata_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetCommitRequestPartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && committed_offset_ == rhs.committed_offset_
    && committed_leader_epoch_ == rhs.committed_leader_epoch_
    && commit_timestamp_ == rhs.commit_timestamp_
    && committed_metadata_ == rhs.committed_metadata_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetCommitRequestPartitionV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class OffsetCommitRequestPartitionV8Deserializer:
  public CompositeDeserializerWith5Delegates<
    OffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetCommitRequestTopic {

  
  
  const std::string name_;
  const std::vector<OffsetCommitRequestPartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7]
  OffsetCommitRequestTopic(std::string name, std::vector<OffsetCommitRequestPartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  OffsetCommitRequestTopic(std::string name, std::vector<OffsetCommitRequestPartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetCommitRequestTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetCommitRequestTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV0Deserializer>
    >{};

class OffsetCommitRequestTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV1Deserializer>
    >{};

class OffsetCommitRequestTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV2Deserializer>
    >{};

class OffsetCommitRequestTopicV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV3Deserializer>
    >{};

class OffsetCommitRequestTopicV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV4Deserializer>
    >{};

class OffsetCommitRequestTopicV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV5Deserializer>
    >{};

class OffsetCommitRequestTopicV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV6Deserializer>
    >{};

class OffsetCommitRequestTopicV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestPartitionV7Deserializer>
    >{};

class OffsetCommitRequestTopicV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitRequestTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetCommitRequestPartitionV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetCommitRequest {

  
  
  const std::string group_id_;
  const int32_t generation_id_;
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const int64_t retention_time_ms_;
  const std::vector<OffsetCommitRequestTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  OffsetCommitRequest(std::string group_id, std::vector<OffsetCommitRequestTopic> topics): group_id_{group_id}, generation_id_{-1}, member_id_{""}, group_instance_id_{absl::nullopt}, retention_time_ms_{-1}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 5, 6]
  OffsetCommitRequest(std::string group_id, int32_t generation_id, std::string member_id, std::vector<OffsetCommitRequestTopic> topics): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{absl::nullopt}, retention_time_ms_{-1}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  OffsetCommitRequest(std::string group_id, int32_t generation_id, std::string member_id, int64_t retention_time_ms, std::vector<OffsetCommitRequestTopic> topics): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{absl::nullopt}, retention_time_ms_{retention_time_ms}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [7]
  OffsetCommitRequest(std::string group_id, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id, std::vector<OffsetCommitRequestTopic> topics): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, retention_time_ms_{-1}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  OffsetCommitRequest(std::string group_id, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id, std::vector<OffsetCommitRequestTopic> topics, TaggedFields tagged_fields): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, retention_time_ms_{-1}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.computeSize(generation_id_);
    }
    
    if (api_version >= 1 && api_version < 8) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 7 && api_version < 8) {
      written += encoder.computeSize(group_instance_id_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(group_instance_id_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeSize(retention_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.encode(generation_id_, dst);
    }
    
    if (api_version >= 1 && api_version < 8) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 7 && api_version < 8) {
      written += encoder.encode(group_instance_id_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(group_instance_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encode(retention_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetCommitRequest& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && generation_id_ == rhs.generation_id_
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && retention_time_ms_ == rhs.retention_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetCommitRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV0Deserializer>
    >{};

class OffsetCommitRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV1Deserializer>
    >{};

class OffsetCommitRequestV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV2Deserializer>
    >{};

class OffsetCommitRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV3Deserializer>
    >{};

class OffsetCommitRequestV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV4Deserializer>
    >{};

class OffsetCommitRequestV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV5Deserializer>
    >{};

class OffsetCommitRequestV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV6Deserializer>
    >{};

class OffsetCommitRequestV7Deserializer:
  public CompositeDeserializerWith5Delegates<
    OffsetCommitRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<OffsetCommitRequestTopicV7Deserializer>
    >{};

class OffsetCommitRequestV8Deserializer:
  public CompositeDeserializerWith6Delegates<
    OffsetCommitRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetCommitRequestTopicV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t OFFSET_COMMIT_REQUEST_API_KEY =
  8;

constexpr int16_t OFFSET_COMMIT_REQUEST_MAX_VERSION =
  8;

class OffsetCommitRequestV0Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV0Deserializer>
{
public:
  OffsetCommitRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV1Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV1Deserializer>
{
public:
  OffsetCommitRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV2Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV2Deserializer>
{
public:
  OffsetCommitRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV3Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV3Deserializer>
{
public:
  OffsetCommitRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV4Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV4Deserializer>
{
public:
  OffsetCommitRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV5Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV5Deserializer>
{
public:
  OffsetCommitRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV6Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV6Deserializer>
{
public:
  OffsetCommitRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV7Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV7Deserializer>
{
public:
  OffsetCommitRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetCommitRequestV8Parser:
  public RequestDataParser<
    OffsetCommitRequest, OffsetCommitRequestV8Deserializer>
{
public:
  OffsetCommitRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct OffsetFetchRequestTopic {

  
  
  const std::string name_;
  const std::vector<int32_t> partition_indexes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5]
  OffsetFetchRequestTopic(std::string name, std::vector<int32_t> partition_indexes): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7]
  OffsetFetchRequestTopic(std::string name, std::vector<int32_t> partition_indexes, TaggedFields tagged_fields): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(partition_indexes_);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.computeCompactSize(partition_indexes_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(partition_indexes_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encodeCompact(partition_indexes_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchRequestTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_indexes_ == rhs.partition_indexes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchRequestTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class OffsetFetchRequestTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class OffsetFetchRequestTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class OffsetFetchRequestTopicV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class OffsetFetchRequestTopicV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class OffsetFetchRequestTopicV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class OffsetFetchRequestTopicV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchRequestTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class OffsetFetchRequestTopicV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchRequestTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchRequestTopics {

  
  
  const std::string name_;
  const std::vector<int32_t> partition_indexes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [8]
  OffsetFetchRequestTopics(std::string name, std::vector<int32_t> partition_indexes, TaggedFields tagged_fields): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(partition_indexes_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(partition_indexes_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchRequestTopics& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_indexes_ == rhs.partition_indexes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchRequestTopicsV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchRequestTopics
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchRequestGroup {

  
  
  const std::string group_id_;
  const absl::optional<std::vector<OffsetFetchRequestTopics>> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [8]
  OffsetFetchRequestGroup(std::string group_id, absl::optional<std::vector<OffsetFetchRequestTopics>> topics, TaggedFields tagged_fields): group_id_{group_id}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchRequestGroup& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchRequestGroupV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchRequestGroup
    ,
      CompactStringDeserializer
    ,
      NullableCompactArrayDeserializer<OffsetFetchRequestTopicsV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchRequest {

  
  
  const std::string group_id_;
  const absl::optional<std::vector<OffsetFetchRequestTopic>> topics_;
  const std::vector<OffsetFetchRequestGroup> groups_;
  const bool require_stable_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  OffsetFetchRequest(std::string group_id, std::vector<OffsetFetchRequestTopic> topics): group_id_{group_id}, topics_{absl::make_optional(topics)}, groups_{std::vector<OffsetFetchRequestGroup>{}}, require_stable_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4, 5]
  OffsetFetchRequest(std::string group_id, absl::optional<std::vector<OffsetFetchRequestTopic>> topics): group_id_{group_id}, topics_{topics}, groups_{std::vector<OffsetFetchRequestGroup>{}}, require_stable_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6]
  OffsetFetchRequest(std::string group_id, absl::optional<std::vector<OffsetFetchRequestTopic>> topics, TaggedFields tagged_fields): group_id_{group_id}, topics_{topics}, groups_{std::vector<OffsetFetchRequestGroup>{}}, require_stable_{false}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [7]
  OffsetFetchRequest(std::string group_id, absl::optional<std::vector<OffsetFetchRequestTopic>> topics, bool require_stable, TaggedFields tagged_fields): group_id_{group_id}, topics_{topics}, groups_{std::vector<OffsetFetchRequestGroup>{}}, require_stable_{require_stable}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [8]
  OffsetFetchRequest(std::vector<OffsetFetchRequestGroup> groups, bool require_stable, TaggedFields tagged_fields): group_id_{""}, topics_{{std::vector<OffsetFetchRequestTopic>{}}}, groups_{groups}, require_stable_{require_stable}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(groups_);
    }
    
    if (api_version >= 7 && api_version < 9) {
      written += encoder.computeSize(require_stable_);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(groups_, dst);
    }
    
    if (api_version >= 7 && api_version < 9) {
      written += encoder.encode(require_stable_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchRequest& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && topics_ == rhs.topics_
    && groups_ == rhs.groups_
    && require_stable_ == rhs.require_stable_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequest
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchRequestTopicV0Deserializer>
    >{};

class OffsetFetchRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequest
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchRequestTopicV1Deserializer>
    >{};

class OffsetFetchRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequest
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<OffsetFetchRequestTopicV2Deserializer>
    >{};

class OffsetFetchRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequest
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<OffsetFetchRequestTopicV3Deserializer>
    >{};

class OffsetFetchRequestV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequest
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<OffsetFetchRequestTopicV4Deserializer>
    >{};

class OffsetFetchRequestV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchRequest
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<OffsetFetchRequestTopicV5Deserializer>
    >{};

class OffsetFetchRequestV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchRequest
    ,
      CompactStringDeserializer
    ,
      NullableCompactArrayDeserializer<OffsetFetchRequestTopicV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class OffsetFetchRequestV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchRequest
    ,
      CompactStringDeserializer
    ,
      NullableCompactArrayDeserializer<OffsetFetchRequestTopicV7Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class OffsetFetchRequestV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchRequest
    ,
      CompactArrayDeserializer<OffsetFetchRequestGroupV8Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t OFFSET_FETCH_REQUEST_API_KEY =
  9;

constexpr int16_t OFFSET_FETCH_REQUEST_MAX_VERSION =
  8;

class OffsetFetchRequestV0Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV0Deserializer>
{
public:
  OffsetFetchRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV1Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV1Deserializer>
{
public:
  OffsetFetchRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV2Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV2Deserializer>
{
public:
  OffsetFetchRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV3Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV3Deserializer>
{
public:
  OffsetFetchRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV4Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV4Deserializer>
{
public:
  OffsetFetchRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV5Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV5Deserializer>
{
public:
  OffsetFetchRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV6Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV6Deserializer>
{
public:
  OffsetFetchRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV7Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV7Deserializer>
{
public:
  OffsetFetchRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetFetchRequestV8Parser:
  public RequestDataParser<
    OffsetFetchRequest, OffsetFetchRequestV8Deserializer>
{
public:
  OffsetFetchRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct FindCoordinatorRequest {

  
  
  const std::string key_;
  const int8_t key_type_;
  const std::vector<std::string> coordinator_keys_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  FindCoordinatorRequest(std::string key): key_{key}, key_type_{0}, coordinator_keys_{std::vector<std::string>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2]
  FindCoordinatorRequest(std::string key, int8_t key_type): key_{key}, key_type_{key_type}, coordinator_keys_{std::vector<std::string>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  FindCoordinatorRequest(std::string key, int8_t key_type, TaggedFields tagged_fields): key_{key}, key_type_{key_type}, coordinator_keys_{std::vector<std::string>{}}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  FindCoordinatorRequest(int8_t key_type, std::vector<std::string> coordinator_keys, TaggedFields tagged_fields): key_{""}, key_type_{key_type}, coordinator_keys_{coordinator_keys}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(key_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(key_);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(key_type_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(coordinator_keys_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(key_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(key_, dst);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(key_type_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(coordinator_keys_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FindCoordinatorRequest& rhs) const {
  
    return true
    && key_ == rhs.key_
    && key_type_ == rhs.key_type_
    && coordinator_keys_ == rhs.coordinator_keys_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FindCoordinatorRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    FindCoordinatorRequest
    ,
      StringDeserializer
    >{};

class FindCoordinatorRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    FindCoordinatorRequest
    ,
      StringDeserializer
    ,
      Int8Deserializer
    >{};

class FindCoordinatorRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    FindCoordinatorRequest
    ,
      StringDeserializer
    ,
      Int8Deserializer
    >{};

class FindCoordinatorRequestV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    FindCoordinatorRequest
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FindCoordinatorRequestV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    FindCoordinatorRequest
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t FIND_COORDINATOR_REQUEST_API_KEY =
  10;

constexpr int16_t FIND_COORDINATOR_REQUEST_MAX_VERSION =
  4;

class FindCoordinatorRequestV0Parser:
  public RequestDataParser<
    FindCoordinatorRequest, FindCoordinatorRequestV0Deserializer>
{
public:
  FindCoordinatorRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FindCoordinatorRequestV1Parser:
  public RequestDataParser<
    FindCoordinatorRequest, FindCoordinatorRequestV1Deserializer>
{
public:
  FindCoordinatorRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FindCoordinatorRequestV2Parser:
  public RequestDataParser<
    FindCoordinatorRequest, FindCoordinatorRequestV2Deserializer>
{
public:
  FindCoordinatorRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FindCoordinatorRequestV3Parser:
  public RequestDataParser<
    FindCoordinatorRequest, FindCoordinatorRequestV3Deserializer>
{
public:
  FindCoordinatorRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class FindCoordinatorRequestV4Parser:
  public RequestDataParser<
    FindCoordinatorRequest, FindCoordinatorRequestV4Deserializer>
{
public:
  FindCoordinatorRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct JoinGroupRequestProtocol {

  
  
  const std::string name_;
  const Bytes metadata_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5]
  JoinGroupRequestProtocol(std::string name, Bytes metadata): name_{name}, metadata_{metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8, 9]
  JoinGroupRequestProtocol(std::string name, Bytes metadata, TaggedFields tagged_fields): name_{name}, metadata_{metadata}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(metadata_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(metadata_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(metadata_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(metadata_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const JoinGroupRequestProtocol& rhs) const {
  
    return true
    && name_ == rhs.name_
    && metadata_ == rhs.metadata_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class JoinGroupRequestProtocolV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupRequestProtocol
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupRequestProtocolV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupRequestProtocol
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupRequestProtocolV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupRequestProtocol
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupRequestProtocolV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupRequestProtocol
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupRequestProtocolV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupRequestProtocol
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupRequestProtocolV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupRequestProtocol
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupRequestProtocolV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    JoinGroupRequestProtocol
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupRequestProtocolV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    JoinGroupRequestProtocol
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupRequestProtocolV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    JoinGroupRequestProtocol
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupRequestProtocolV9Deserializer:
  public CompositeDeserializerWith3Delegates<
    JoinGroupRequestProtocol
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct JoinGroupRequest {

  
  
  const std::string group_id_;
  const int32_t session_timeout_ms_;
  const int32_t rebalance_timeout_ms_;
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const std::string protocol_type_;
  const std::vector<JoinGroupRequestProtocol> protocols_;
  const absl::optional<std::string> reason_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  JoinGroupRequest(std::string group_id, int32_t session_timeout_ms, std::string member_id, std::string protocol_type, std::vector<JoinGroupRequestProtocol> protocols): group_id_{group_id}, session_timeout_ms_{session_timeout_ms}, rebalance_timeout_ms_{-1}, member_id_{member_id}, group_instance_id_{absl::nullopt}, protocol_type_{protocol_type}, protocols_{protocols}, reason_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4]
  JoinGroupRequest(std::string group_id, int32_t session_timeout_ms, int32_t rebalance_timeout_ms, std::string member_id, std::string protocol_type, std::vector<JoinGroupRequestProtocol> protocols): group_id_{group_id}, session_timeout_ms_{session_timeout_ms}, rebalance_timeout_ms_{rebalance_timeout_ms}, member_id_{member_id}, group_instance_id_{absl::nullopt}, protocol_type_{protocol_type}, protocols_{protocols}, reason_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  JoinGroupRequest(std::string group_id, int32_t session_timeout_ms, int32_t rebalance_timeout_ms, std::string member_id, absl::optional<std::string> group_instance_id, std::string protocol_type, std::vector<JoinGroupRequestProtocol> protocols): group_id_{group_id}, session_timeout_ms_{session_timeout_ms}, rebalance_timeout_ms_{rebalance_timeout_ms}, member_id_{member_id}, group_instance_id_{group_instance_id}, protocol_type_{protocol_type}, protocols_{protocols}, reason_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7]
  JoinGroupRequest(std::string group_id, int32_t session_timeout_ms, int32_t rebalance_timeout_ms, std::string member_id, absl::optional<std::string> group_instance_id, std::string protocol_type, std::vector<JoinGroupRequestProtocol> protocols, TaggedFields tagged_fields): group_id_{group_id}, session_timeout_ms_{session_timeout_ms}, rebalance_timeout_ms_{rebalance_timeout_ms}, member_id_{member_id}, group_instance_id_{group_instance_id}, protocol_type_{protocol_type}, protocols_{protocols}, reason_{absl::nullopt}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [8, 9]
  JoinGroupRequest(std::string group_id, int32_t session_timeout_ms, int32_t rebalance_timeout_ms, std::string member_id, absl::optional<std::string> group_instance_id, std::string protocol_type, std::vector<JoinGroupRequestProtocol> protocols, absl::optional<std::string> reason, TaggedFields tagged_fields): group_id_{group_id}, session_timeout_ms_{session_timeout_ms}, rebalance_timeout_ms_{rebalance_timeout_ms}, member_id_{member_id}, group_instance_id_{group_instance_id}, protocol_type_{protocol_type}, protocols_{protocols}, reason_{reason}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(session_timeout_ms_);
    }
    
    if (api_version >= 1 && api_version < 10) {
      written += encoder.computeSize(rebalance_timeout_ms_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeSize(group_instance_id_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(group_instance_id_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(protocol_type_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(protocol_type_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(protocols_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(protocols_);
    }
    
    if (api_version >= 8 && api_version < 10) {
      written += encoder.computeCompactSize(reason_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(session_timeout_ms_, dst);
    }
    
    if (api_version >= 1 && api_version < 10) {
      written += encoder.encode(rebalance_timeout_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encode(group_instance_id_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(group_instance_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(protocol_type_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(protocol_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(protocols_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(protocols_, dst);
    }
    
    if (api_version >= 8 && api_version < 10) {
      written += encoder.encodeCompact(reason_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const JoinGroupRequest& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && session_timeout_ms_ == rhs.session_timeout_ms_
    && rebalance_timeout_ms_ == rhs.rebalance_timeout_ms_
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && protocol_type_ == rhs.protocol_type_
    && protocols_ == rhs.protocols_
    && reason_ == rhs.reason_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class JoinGroupRequestV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    JoinGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupRequestProtocolV0Deserializer>
    >{};

class JoinGroupRequestV1Deserializer:
  public CompositeDeserializerWith6Delegates<
    JoinGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupRequestProtocolV1Deserializer>
    >{};

class JoinGroupRequestV2Deserializer:
  public CompositeDeserializerWith6Delegates<
    JoinGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupRequestProtocolV2Deserializer>
    >{};

class JoinGroupRequestV3Deserializer:
  public CompositeDeserializerWith6Delegates<
    JoinGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupRequestProtocolV3Deserializer>
    >{};

class JoinGroupRequestV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    JoinGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupRequestProtocolV4Deserializer>
    >{};

class JoinGroupRequestV5Deserializer:
  public CompositeDeserializerWith7Delegates<
    JoinGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupRequestProtocolV5Deserializer>
    >{};

class JoinGroupRequestV6Deserializer:
  public CompositeDeserializerWith8Delegates<
    JoinGroupRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupRequestProtocolV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupRequestV7Deserializer:
  public CompositeDeserializerWith8Delegates<
    JoinGroupRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupRequestProtocolV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupRequestV8Deserializer:
  public CompositeDeserializerWith9Delegates<
    JoinGroupRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupRequestProtocolV8Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupRequestV9Deserializer:
  public CompositeDeserializerWith9Delegates<
    JoinGroupRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupRequestProtocolV9Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t JOIN_GROUP_REQUEST_API_KEY =
  11;

constexpr int16_t JOIN_GROUP_REQUEST_MAX_VERSION =
  9;

class JoinGroupRequestV0Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV0Deserializer>
{
public:
  JoinGroupRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV1Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV1Deserializer>
{
public:
  JoinGroupRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV2Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV2Deserializer>
{
public:
  JoinGroupRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV3Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV3Deserializer>
{
public:
  JoinGroupRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV4Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV4Deserializer>
{
public:
  JoinGroupRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV5Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV5Deserializer>
{
public:
  JoinGroupRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV6Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV6Deserializer>
{
public:
  JoinGroupRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV7Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV7Deserializer>
{
public:
  JoinGroupRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV8Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV8Deserializer>
{
public:
  JoinGroupRequestV8Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class JoinGroupRequestV9Parser:
  public RequestDataParser<
    JoinGroupRequest, JoinGroupRequestV9Deserializer>
{
public:
  JoinGroupRequestV9Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct HeartbeatRequest {

  
  
  const std::string group_id_;
  const int32_t generation_id_;
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  HeartbeatRequest(std::string group_id, int32_t generation_id, std::string member_id): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  HeartbeatRequest(std::string group_id, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  HeartbeatRequest(std::string group_id, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id, TaggedFields tagged_fields): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(generation_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(group_instance_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(group_instance_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(generation_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(group_instance_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(group_instance_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const HeartbeatRequest& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && generation_id_ == rhs.generation_id_
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class HeartbeatRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    HeartbeatRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    >{};

class HeartbeatRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    HeartbeatRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    >{};

class HeartbeatRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    HeartbeatRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    >{};

class HeartbeatRequestV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    HeartbeatRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class HeartbeatRequestV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    HeartbeatRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t HEARTBEAT_REQUEST_API_KEY =
  12;

constexpr int16_t HEARTBEAT_REQUEST_MAX_VERSION =
  4;

class HeartbeatRequestV0Parser:
  public RequestDataParser<
    HeartbeatRequest, HeartbeatRequestV0Deserializer>
{
public:
  HeartbeatRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class HeartbeatRequestV1Parser:
  public RequestDataParser<
    HeartbeatRequest, HeartbeatRequestV1Deserializer>
{
public:
  HeartbeatRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class HeartbeatRequestV2Parser:
  public RequestDataParser<
    HeartbeatRequest, HeartbeatRequestV2Deserializer>
{
public:
  HeartbeatRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class HeartbeatRequestV3Parser:
  public RequestDataParser<
    HeartbeatRequest, HeartbeatRequestV3Deserializer>
{
public:
  HeartbeatRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class HeartbeatRequestV4Parser:
  public RequestDataParser<
    HeartbeatRequest, HeartbeatRequestV4Deserializer>
{
public:
  HeartbeatRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct MemberIdentity {

  
  
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const absl::optional<std::string> reason_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [3]
  MemberIdentity(std::string member_id, absl::optional<std::string> group_instance_id): member_id_{member_id}, group_instance_id_{group_instance_id}, reason_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  MemberIdentity(std::string member_id, absl::optional<std::string> group_instance_id, TaggedFields tagged_fields): member_id_{member_id}, group_instance_id_{group_instance_id}, reason_{absl::nullopt}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5]
  MemberIdentity(std::string member_id, absl::optional<std::string> group_instance_id, absl::optional<std::string> reason, TaggedFields tagged_fields): member_id_{member_id}, group_instance_id_{group_instance_id}, reason_{reason}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(group_instance_id_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(group_instance_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(reason_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(group_instance_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(group_instance_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(reason_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MemberIdentity& rhs) const {
  
    return true
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && reason_ == rhs.reason_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MemberIdentityV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    MemberIdentity
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class MemberIdentityV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    MemberIdentity
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MemberIdentityV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    MemberIdentity
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct LeaveGroupRequest {

  
  
  const std::string group_id_;
  const std::string member_id_;
  const std::vector<MemberIdentity> members_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  LeaveGroupRequest(std::string group_id, std::string member_id): group_id_{group_id}, member_id_{member_id}, members_{std::vector<MemberIdentity>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  LeaveGroupRequest(std::string group_id, std::vector<MemberIdentity> members): group_id_{group_id}, member_id_{""}, members_{members}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  LeaveGroupRequest(std::string group_id, std::vector<MemberIdentity> members, TaggedFields tagged_fields): group_id_{group_id}, member_id_{""}, members_{members}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(members_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(members_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(members_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(members_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaveGroupRequest& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && member_id_ == rhs.member_id_
    && members_ == rhs.members_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaveGroupRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaveGroupRequest
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class LeaveGroupRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaveGroupRequest
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class LeaveGroupRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaveGroupRequest
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class LeaveGroupRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaveGroupRequest
    ,
      StringDeserializer
    ,
      ArrayDeserializer<MemberIdentityV3Deserializer>
    >{};

class LeaveGroupRequestV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaveGroupRequest
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<MemberIdentityV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaveGroupRequestV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaveGroupRequest
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<MemberIdentityV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t LEAVE_GROUP_REQUEST_API_KEY =
  13;

constexpr int16_t LEAVE_GROUP_REQUEST_MAX_VERSION =
  5;

class LeaveGroupRequestV0Parser:
  public RequestDataParser<
    LeaveGroupRequest, LeaveGroupRequestV0Deserializer>
{
public:
  LeaveGroupRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaveGroupRequestV1Parser:
  public RequestDataParser<
    LeaveGroupRequest, LeaveGroupRequestV1Deserializer>
{
public:
  LeaveGroupRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaveGroupRequestV2Parser:
  public RequestDataParser<
    LeaveGroupRequest, LeaveGroupRequestV2Deserializer>
{
public:
  LeaveGroupRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaveGroupRequestV3Parser:
  public RequestDataParser<
    LeaveGroupRequest, LeaveGroupRequestV3Deserializer>
{
public:
  LeaveGroupRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaveGroupRequestV4Parser:
  public RequestDataParser<
    LeaveGroupRequest, LeaveGroupRequestV4Deserializer>
{
public:
  LeaveGroupRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class LeaveGroupRequestV5Parser:
  public RequestDataParser<
    LeaveGroupRequest, LeaveGroupRequestV5Deserializer>
{
public:
  LeaveGroupRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct SyncGroupRequestAssignment {

  
  
  const std::string member_id_;
  const Bytes assignment_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  SyncGroupRequestAssignment(std::string member_id, Bytes assignment): member_id_{member_id}, assignment_{assignment}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  SyncGroupRequestAssignment(std::string member_id, Bytes assignment, TaggedFields tagged_fields): member_id_{member_id}, assignment_{assignment}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(assignment_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(assignment_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(assignment_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(assignment_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const SyncGroupRequestAssignment& rhs) const {
  
    return true
    && member_id_ == rhs.member_id_
    && assignment_ == rhs.assignment_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class SyncGroupRequestAssignmentV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    SyncGroupRequestAssignment
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupRequestAssignmentV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    SyncGroupRequestAssignment
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupRequestAssignmentV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    SyncGroupRequestAssignment
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupRequestAssignmentV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    SyncGroupRequestAssignment
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupRequestAssignmentV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    SyncGroupRequestAssignment
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class SyncGroupRequestAssignmentV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    SyncGroupRequestAssignment
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct SyncGroupRequest {

  
  
  const std::string group_id_;
  const int32_t generation_id_;
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const absl::optional<std::string> protocol_type_;
  const absl::optional<std::string> protocol_name_;
  const std::vector<SyncGroupRequestAssignment> assignments_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  SyncGroupRequest(std::string group_id, int32_t generation_id, std::string member_id, std::vector<SyncGroupRequestAssignment> assignments): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{absl::nullopt}, protocol_type_{absl::nullopt}, protocol_name_{absl::nullopt}, assignments_{assignments}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  SyncGroupRequest(std::string group_id, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id, std::vector<SyncGroupRequestAssignment> assignments): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, protocol_type_{absl::nullopt}, protocol_name_{absl::nullopt}, assignments_{assignments}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  SyncGroupRequest(std::string group_id, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id, std::vector<SyncGroupRequestAssignment> assignments, TaggedFields tagged_fields): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, protocol_type_{absl::nullopt}, protocol_name_{absl::nullopt}, assignments_{assignments}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5]
  SyncGroupRequest(std::string group_id, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id, absl::optional<std::string> protocol_type, absl::optional<std::string> protocol_name, std::vector<SyncGroupRequestAssignment> assignments, TaggedFields tagged_fields): group_id_{group_id}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, protocol_type_{protocol_type}, protocol_name_{protocol_name}, assignments_{assignments}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(generation_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(group_instance_id_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(group_instance_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(protocol_type_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(protocol_name_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(assignments_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(assignments_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(generation_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(group_instance_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(group_instance_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(protocol_type_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(protocol_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(assignments_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(assignments_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const SyncGroupRequest& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && generation_id_ == rhs.generation_id_
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && protocol_type_ == rhs.protocol_type_
    && protocol_name_ == rhs.protocol_name_
    && assignments_ == rhs.assignments_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class SyncGroupRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    SyncGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<SyncGroupRequestAssignmentV0Deserializer>
    >{};

class SyncGroupRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    SyncGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<SyncGroupRequestAssignmentV1Deserializer>
    >{};

class SyncGroupRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    SyncGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<SyncGroupRequestAssignmentV2Deserializer>
    >{};

class SyncGroupRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    SyncGroupRequest
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<SyncGroupRequestAssignmentV3Deserializer>
    >{};

class SyncGroupRequestV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    SyncGroupRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<SyncGroupRequestAssignmentV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class SyncGroupRequestV5Deserializer:
  public CompositeDeserializerWith8Delegates<
    SyncGroupRequest
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<SyncGroupRequestAssignmentV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t SYNC_GROUP_REQUEST_API_KEY =
  14;

constexpr int16_t SYNC_GROUP_REQUEST_MAX_VERSION =
  5;

class SyncGroupRequestV0Parser:
  public RequestDataParser<
    SyncGroupRequest, SyncGroupRequestV0Deserializer>
{
public:
  SyncGroupRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SyncGroupRequestV1Parser:
  public RequestDataParser<
    SyncGroupRequest, SyncGroupRequestV1Deserializer>
{
public:
  SyncGroupRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SyncGroupRequestV2Parser:
  public RequestDataParser<
    SyncGroupRequest, SyncGroupRequestV2Deserializer>
{
public:
  SyncGroupRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SyncGroupRequestV3Parser:
  public RequestDataParser<
    SyncGroupRequest, SyncGroupRequestV3Deserializer>
{
public:
  SyncGroupRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SyncGroupRequestV4Parser:
  public RequestDataParser<
    SyncGroupRequest, SyncGroupRequestV4Deserializer>
{
public:
  SyncGroupRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SyncGroupRequestV5Parser:
  public RequestDataParser<
    SyncGroupRequest, SyncGroupRequestV5Deserializer>
{
public:
  SyncGroupRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribeGroupsRequest {

  
  
  const std::vector<std::string> groups_;
  const bool include_authorized_operations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  DescribeGroupsRequest(std::vector<std::string> groups): groups_{groups}, include_authorized_operations_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4]
  DescribeGroupsRequest(std::vector<std::string> groups, bool include_authorized_operations): groups_{groups}, include_authorized_operations_{include_authorized_operations}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  DescribeGroupsRequest(std::vector<std::string> groups, bool include_authorized_operations, TaggedFields tagged_fields): groups_{groups}, include_authorized_operations_{include_authorized_operations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(groups_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(groups_);
    }
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.computeSize(include_authorized_operations_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(groups_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(groups_, dst);
    }
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.encode(include_authorized_operations_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeGroupsRequest& rhs) const {
  
    return true
    && groups_ == rhs.groups_
    && include_authorized_operations_ == rhs.include_authorized_operations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeGroupsRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeGroupsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    >{};

class DescribeGroupsRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeGroupsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    >{};

class DescribeGroupsRequestV2Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeGroupsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    >{};

class DescribeGroupsRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeGroupsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    ,
      BooleanDeserializer
    >{};

class DescribeGroupsRequestV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeGroupsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    ,
      BooleanDeserializer
    >{};

class DescribeGroupsRequestV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeGroupsRequest
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_GROUPS_REQUEST_API_KEY =
  15;

constexpr int16_t DESCRIBE_GROUPS_REQUEST_MAX_VERSION =
  5;

class DescribeGroupsRequestV0Parser:
  public RequestDataParser<
    DescribeGroupsRequest, DescribeGroupsRequestV0Deserializer>
{
public:
  DescribeGroupsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeGroupsRequestV1Parser:
  public RequestDataParser<
    DescribeGroupsRequest, DescribeGroupsRequestV1Deserializer>
{
public:
  DescribeGroupsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeGroupsRequestV2Parser:
  public RequestDataParser<
    DescribeGroupsRequest, DescribeGroupsRequestV2Deserializer>
{
public:
  DescribeGroupsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeGroupsRequestV3Parser:
  public RequestDataParser<
    DescribeGroupsRequest, DescribeGroupsRequestV3Deserializer>
{
public:
  DescribeGroupsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeGroupsRequestV4Parser:
  public RequestDataParser<
    DescribeGroupsRequest, DescribeGroupsRequestV4Deserializer>
{
public:
  DescribeGroupsRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeGroupsRequestV5Parser:
  public RequestDataParser<
    DescribeGroupsRequest, DescribeGroupsRequestV5Deserializer>
{
public:
  DescribeGroupsRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ListGroupsRequest {

  
  
  const std::vector<std::string> states_filter_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  ListGroupsRequest() {};
  // constructor used in versions: [3]
  ListGroupsRequest(TaggedFields tagged_fields): states_filter_{std::vector<std::string>{}}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  ListGroupsRequest(std::vector<std::string> states_filter, TaggedFields tagged_fields): states_filter_{states_filter}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(states_filter_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(states_filter_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListGroupsRequest& rhs) const {
  
    return true
    && states_filter_ == rhs.states_filter_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListGroupsRequestV0Deserializer:
  public CompositeDeserializerWith0Delegates<
    ListGroupsRequest
    >{};

class ListGroupsRequestV1Deserializer:
  public CompositeDeserializerWith0Delegates<
    ListGroupsRequest
    >{};

class ListGroupsRequestV2Deserializer:
  public CompositeDeserializerWith0Delegates<
    ListGroupsRequest
    >{};

class ListGroupsRequestV3Deserializer:
  public CompositeDeserializerWith1Delegates<
    ListGroupsRequest
    ,
      TaggedFieldsDeserializer
    >{};

class ListGroupsRequestV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListGroupsRequest
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t LIST_GROUPS_REQUEST_API_KEY =
  16;

constexpr int16_t LIST_GROUPS_REQUEST_MAX_VERSION =
  4;

class ListGroupsRequestV0Parser:
  public RequestDataParser<
    ListGroupsRequest, ListGroupsRequestV0Deserializer>
{
public:
  ListGroupsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListGroupsRequestV1Parser:
  public RequestDataParser<
    ListGroupsRequest, ListGroupsRequestV1Deserializer>
{
public:
  ListGroupsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListGroupsRequestV2Parser:
  public RequestDataParser<
    ListGroupsRequest, ListGroupsRequestV2Deserializer>
{
public:
  ListGroupsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListGroupsRequestV3Parser:
  public RequestDataParser<
    ListGroupsRequest, ListGroupsRequestV3Deserializer>
{
public:
  ListGroupsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ListGroupsRequestV4Parser:
  public RequestDataParser<
    ListGroupsRequest, ListGroupsRequestV4Deserializer>
{
public:
  ListGroupsRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct SaslHandshakeRequest {

  
  
  const std::string mechanism_;
  
  // constructor used in versions: [0, 1]
  SaslHandshakeRequest(std::string mechanism): mechanism_{mechanism} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(mechanism_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(mechanism_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const SaslHandshakeRequest& rhs) const {
  
    return true
    && mechanism_ == rhs.mechanism_;
  };

};



class SaslHandshakeRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    SaslHandshakeRequest
    ,
      StringDeserializer
    >{};

class SaslHandshakeRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    SaslHandshakeRequest
    ,
      StringDeserializer
    >{};



constexpr int16_t SASL_HANDSHAKE_REQUEST_API_KEY =
  17;

constexpr int16_t SASL_HANDSHAKE_REQUEST_MAX_VERSION =
  1;

class SaslHandshakeRequestV0Parser:
  public RequestDataParser<
    SaslHandshakeRequest, SaslHandshakeRequestV0Deserializer>
{
public:
  SaslHandshakeRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SaslHandshakeRequestV1Parser:
  public RequestDataParser<
    SaslHandshakeRequest, SaslHandshakeRequestV1Deserializer>
{
public:
  SaslHandshakeRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ApiVersionsRequest {

  
  
  const std::string client_software_name_;
  const std::string client_software_version_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  ApiVersionsRequest() {};
  // constructor used in versions: [3]
  ApiVersionsRequest(std::string client_software_name, std::string client_software_version, TaggedFields tagged_fields): client_software_name_{client_software_name}, client_software_version_{client_software_version}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(client_software_name_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(client_software_version_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(client_software_name_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(client_software_version_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ApiVersionsRequest& rhs) const {
  
    return true
    && client_software_name_ == rhs.client_software_name_
    && client_software_version_ == rhs.client_software_version_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ApiVersionsRequestV0Deserializer:
  public CompositeDeserializerWith0Delegates<
    ApiVersionsRequest
    >{};

class ApiVersionsRequestV1Deserializer:
  public CompositeDeserializerWith0Delegates<
    ApiVersionsRequest
    >{};

class ApiVersionsRequestV2Deserializer:
  public CompositeDeserializerWith0Delegates<
    ApiVersionsRequest
    >{};

class ApiVersionsRequestV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    ApiVersionsRequest
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t API_VERSIONS_REQUEST_API_KEY =
  18;

constexpr int16_t API_VERSIONS_REQUEST_MAX_VERSION =
  3;

class ApiVersionsRequestV0Parser:
  public RequestDataParser<
    ApiVersionsRequest, ApiVersionsRequestV0Deserializer>
{
public:
  ApiVersionsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ApiVersionsRequestV1Parser:
  public RequestDataParser<
    ApiVersionsRequest, ApiVersionsRequestV1Deserializer>
{
public:
  ApiVersionsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ApiVersionsRequestV2Parser:
  public RequestDataParser<
    ApiVersionsRequest, ApiVersionsRequestV2Deserializer>
{
public:
  ApiVersionsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ApiVersionsRequestV3Parser:
  public RequestDataParser<
    ApiVersionsRequest, ApiVersionsRequestV3Deserializer>
{
public:
  ApiVersionsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct CreatableReplicaAssignment {

  
  
  const int32_t partition_index_;
  const std::vector<int32_t> broker_ids_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  CreatableReplicaAssignment(int32_t partition_index, std::vector<int32_t> broker_ids): partition_index_{partition_index}, broker_ids_{broker_ids}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7]
  CreatableReplicaAssignment(int32_t partition_index, std::vector<int32_t> broker_ids, TaggedFields tagged_fields): partition_index_{partition_index}, broker_ids_{broker_ids}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(broker_ids_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(broker_ids_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(broker_ids_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(broker_ids_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatableReplicaAssignment& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && broker_ids_ == rhs.broker_ids_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatableReplicaAssignmentV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class CreatableReplicaAssignmentV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class CreatableReplicaAssignmentV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class CreatableReplicaAssignmentV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class CreatableReplicaAssignmentV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class CreatableReplicaAssignmentV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableReplicaAssignmentV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableReplicaAssignmentV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableReplicaAssignment
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct CreateableTopicConfig {

  
  
  const std::string name_;
  const absl::optional<std::string> value_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  CreateableTopicConfig(std::string name, absl::optional<std::string> value): name_{name}, value_{value}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7]
  CreateableTopicConfig(std::string name, absl::optional<std::string> value, TaggedFields tagged_fields): name_{name}, value_{value}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(value_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(value_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(value_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(value_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreateableTopicConfig& rhs) const {
  
    return true
    && name_ == rhs.name_
    && value_ == rhs.value_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreateableTopicConfigV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateableTopicConfig
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class CreateableTopicConfigV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateableTopicConfig
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class CreateableTopicConfigV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateableTopicConfig
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class CreateableTopicConfigV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateableTopicConfig
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class CreateableTopicConfigV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateableTopicConfig
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class CreateableTopicConfigV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateableTopicConfig
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreateableTopicConfigV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateableTopicConfig
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreateableTopicConfigV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateableTopicConfig
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct CreatableTopic {

  
  
  const std::string name_;
  const int32_t num_partitions_;
  const int16_t replication_factor_;
  const std::vector<CreatableReplicaAssignment> assignments_;
  const std::vector<CreateableTopicConfig> configs_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  CreatableTopic(std::string name, int32_t num_partitions, int16_t replication_factor, std::vector<CreatableReplicaAssignment> assignments, std::vector<CreateableTopicConfig> configs): name_{name}, num_partitions_{num_partitions}, replication_factor_{replication_factor}, assignments_{assignments}, configs_{configs}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7]
  CreatableTopic(std::string name, int32_t num_partitions, int16_t replication_factor, std::vector<CreatableReplicaAssignment> assignments, std::vector<CreateableTopicConfig> configs, TaggedFields tagged_fields): name_{name}, num_partitions_{num_partitions}, replication_factor_{replication_factor}, assignments_{assignments}, configs_{configs}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(num_partitions_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(replication_factor_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(assignments_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(assignments_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(configs_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(configs_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(num_partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(replication_factor_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(assignments_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(assignments_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(configs_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(configs_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatableTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && num_partitions_ == rhs.num_partitions_
    && replication_factor_ == rhs.replication_factor_
    && assignments_ == rhs.assignments_
    && configs_ == rhs.configs_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatableTopicV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    CreatableTopic
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<CreatableReplicaAssignmentV0Deserializer>
    ,
      ArrayDeserializer<CreateableTopicConfigV0Deserializer>
    >{};

class CreatableTopicV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    CreatableTopic
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<CreatableReplicaAssignmentV1Deserializer>
    ,
      ArrayDeserializer<CreateableTopicConfigV1Deserializer>
    >{};

class CreatableTopicV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    CreatableTopic
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<CreatableReplicaAssignmentV2Deserializer>
    ,
      ArrayDeserializer<CreateableTopicConfigV2Deserializer>
    >{};

class CreatableTopicV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    CreatableTopic
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<CreatableReplicaAssignmentV3Deserializer>
    ,
      ArrayDeserializer<CreateableTopicConfigV3Deserializer>
    >{};

class CreatableTopicV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    CreatableTopic
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<CreatableReplicaAssignmentV4Deserializer>
    ,
      ArrayDeserializer<CreateableTopicConfigV4Deserializer>
    >{};

class CreatableTopicV5Deserializer:
  public CompositeDeserializerWith6Delegates<
    CreatableTopic
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<CreatableReplicaAssignmentV5Deserializer>
    ,
      CompactArrayDeserializer<CreateableTopicConfigV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableTopicV6Deserializer:
  public CompositeDeserializerWith6Delegates<
    CreatableTopic
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<CreatableReplicaAssignmentV6Deserializer>
    ,
      CompactArrayDeserializer<CreateableTopicConfigV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableTopicV7Deserializer:
  public CompositeDeserializerWith6Delegates<
    CreatableTopic
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<CreatableReplicaAssignmentV7Deserializer>
    ,
      CompactArrayDeserializer<CreateableTopicConfigV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct CreateTopicsRequest {

  
  
  const std::vector<CreatableTopic> topics_;
  const int32_t timeout_ms_;
  const bool validate_only_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  CreateTopicsRequest(std::vector<CreatableTopic> topics, int32_t timeout_ms): topics_{topics}, timeout_ms_{timeout_ms}, validate_only_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4]
  CreateTopicsRequest(std::vector<CreatableTopic> topics, int32_t timeout_ms, bool validate_only): topics_{topics}, timeout_ms_{timeout_ms}, validate_only_{validate_only}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7]
  CreateTopicsRequest(std::vector<CreatableTopic> topics, int32_t timeout_ms, bool validate_only, TaggedFields tagged_fields): topics_{topics}, timeout_ms_{timeout_ms}, validate_only_{validate_only}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 1 && api_version < 8) {
      written += encoder.computeSize(validate_only_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 1 && api_version < 8) {
      written += encoder.encode(validate_only_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreateTopicsRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && timeout_ms_ == rhs.timeout_ms_
    && validate_only_ == rhs.validate_only_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreateTopicsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateTopicsRequest
    ,
      ArrayDeserializer<CreatableTopicV0Deserializer>
    ,
      Int32Deserializer
    >{};

class CreateTopicsRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateTopicsRequest
    ,
      ArrayDeserializer<CreatableTopicV1Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    >{};

class CreateTopicsRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateTopicsRequest
    ,
      ArrayDeserializer<CreatableTopicV2Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    >{};

class CreateTopicsRequestV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateTopicsRequest
    ,
      ArrayDeserializer<CreatableTopicV3Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    >{};

class CreateTopicsRequestV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateTopicsRequest
    ,
      ArrayDeserializer<CreatableTopicV4Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    >{};

class CreateTopicsRequestV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreateTopicsRequest
    ,
      CompactArrayDeserializer<CreatableTopicV5Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreateTopicsRequestV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreateTopicsRequest
    ,
      CompactArrayDeserializer<CreatableTopicV6Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreateTopicsRequestV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreateTopicsRequest
    ,
      CompactArrayDeserializer<CreatableTopicV7Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t CREATE_TOPICS_REQUEST_API_KEY =
  19;

constexpr int16_t CREATE_TOPICS_REQUEST_MAX_VERSION =
  7;

class CreateTopicsRequestV0Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV0Deserializer>
{
public:
  CreateTopicsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateTopicsRequestV1Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV1Deserializer>
{
public:
  CreateTopicsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateTopicsRequestV2Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV2Deserializer>
{
public:
  CreateTopicsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateTopicsRequestV3Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV3Deserializer>
{
public:
  CreateTopicsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateTopicsRequestV4Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV4Deserializer>
{
public:
  CreateTopicsRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateTopicsRequestV5Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV5Deserializer>
{
public:
  CreateTopicsRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateTopicsRequestV6Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV6Deserializer>
{
public:
  CreateTopicsRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateTopicsRequestV7Parser:
  public RequestDataParser<
    CreateTopicsRequest, CreateTopicsRequestV7Deserializer>
{
public:
  CreateTopicsRequestV7Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DeleteTopicState {

  
  
  const absl::optional<std::string> name_;
  const Uuid topic_id_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [6]
  DeleteTopicState(absl::optional<std::string> name, Uuid topic_id, TaggedFields tagged_fields): name_{name}, topic_id_{topic_id}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteTopicState& rhs) const {
  
    return true
    && name_ == rhs.name_
    && topic_id_ == rhs.topic_id_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteTopicStateV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteTopicState
    ,
      NullableCompactStringDeserializer
    ,
      UuidDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteTopicsRequest {

  
  
  const std::vector<DeleteTopicState> topics_;
  const std::vector<std::string> topic_names_;
  const int32_t timeout_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  DeleteTopicsRequest(std::vector<std::string> topic_names, int32_t timeout_ms): topics_{std::vector<DeleteTopicState>{}}, topic_names_{topic_names}, timeout_ms_{timeout_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  DeleteTopicsRequest(std::vector<std::string> topic_names, int32_t timeout_ms, TaggedFields tagged_fields): topics_{std::vector<DeleteTopicState>{}}, topic_names_{topic_names}, timeout_ms_{timeout_ms}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [6]
  DeleteTopicsRequest(std::vector<DeleteTopicState> topics, int32_t timeout_ms, TaggedFields tagged_fields): topics_{topics}, topic_names_{std::vector<std::string>{}}, timeout_ms_{timeout_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(topic_names_);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.computeCompactSize(topic_names_);
    }
    
    if (api_version >= 0 && api_version < 7) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(topic_names_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(topic_names_, dst);
    }
    
    if (api_version >= 0 && api_version < 7) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteTopicsRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && topic_names_ == rhs.topic_names_
    && timeout_ms_ == rhs.timeout_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteTopicsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteTopicsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    ,
      Int32Deserializer
    >{};

class DeleteTopicsRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteTopicsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    ,
      Int32Deserializer
    >{};

class DeleteTopicsRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteTopicsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    ,
      Int32Deserializer
    >{};

class DeleteTopicsRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteTopicsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    ,
      Int32Deserializer
    >{};

class DeleteTopicsRequestV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteTopicsRequest
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteTopicsRequestV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteTopicsRequest
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteTopicsRequestV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteTopicsRequest
    ,
      CompactArrayDeserializer<DeleteTopicStateV6Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DELETE_TOPICS_REQUEST_API_KEY =
  20;

constexpr int16_t DELETE_TOPICS_REQUEST_MAX_VERSION =
  6;

class DeleteTopicsRequestV0Parser:
  public RequestDataParser<
    DeleteTopicsRequest, DeleteTopicsRequestV0Deserializer>
{
public:
  DeleteTopicsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteTopicsRequestV1Parser:
  public RequestDataParser<
    DeleteTopicsRequest, DeleteTopicsRequestV1Deserializer>
{
public:
  DeleteTopicsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteTopicsRequestV2Parser:
  public RequestDataParser<
    DeleteTopicsRequest, DeleteTopicsRequestV2Deserializer>
{
public:
  DeleteTopicsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteTopicsRequestV3Parser:
  public RequestDataParser<
    DeleteTopicsRequest, DeleteTopicsRequestV3Deserializer>
{
public:
  DeleteTopicsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteTopicsRequestV4Parser:
  public RequestDataParser<
    DeleteTopicsRequest, DeleteTopicsRequestV4Deserializer>
{
public:
  DeleteTopicsRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteTopicsRequestV5Parser:
  public RequestDataParser<
    DeleteTopicsRequest, DeleteTopicsRequestV5Deserializer>
{
public:
  DeleteTopicsRequestV5Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteTopicsRequestV6Parser:
  public RequestDataParser<
    DeleteTopicsRequest, DeleteTopicsRequestV6Deserializer>
{
public:
  DeleteTopicsRequestV6Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DeleteRecordsPartition {

  
  
  const int32_t partition_index_;
  const int64_t offset_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteRecordsPartition(int32_t partition_index, int64_t offset): partition_index_{partition_index}, offset_{offset}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteRecordsPartition(int32_t partition_index, int64_t offset, TaggedFields tagged_fields): partition_index_{partition_index}, offset_{offset}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(offset_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(offset_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteRecordsPartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && offset_ == rhs.offset_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteRecordsPartitionV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class DeleteRecordsPartitionV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class DeleteRecordsPartitionV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteRecordsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteRecordsTopic {

  
  
  const std::string name_;
  const std::vector<DeleteRecordsPartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteRecordsTopic(std::string name, std::vector<DeleteRecordsPartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteRecordsTopic(std::string name, std::vector<DeleteRecordsPartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteRecordsTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteRecordsTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DeleteRecordsPartitionV0Deserializer>
    >{};

class DeleteRecordsTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DeleteRecordsPartitionV1Deserializer>
    >{};

class DeleteRecordsTopicV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteRecordsTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DeleteRecordsPartitionV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteRecordsRequest {

  
  
  const std::vector<DeleteRecordsTopic> topics_;
  const int32_t timeout_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteRecordsRequest(std::vector<DeleteRecordsTopic> topics, int32_t timeout_ms): topics_{topics}, timeout_ms_{timeout_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteRecordsRequest(std::vector<DeleteRecordsTopic> topics, int32_t timeout_ms, TaggedFields tagged_fields): topics_{topics}, timeout_ms_{timeout_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteRecordsRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && timeout_ms_ == rhs.timeout_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteRecordsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsRequest
    ,
      ArrayDeserializer<DeleteRecordsTopicV0Deserializer>
    ,
      Int32Deserializer
    >{};

class DeleteRecordsRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsRequest
    ,
      ArrayDeserializer<DeleteRecordsTopicV1Deserializer>
    ,
      Int32Deserializer
    >{};

class DeleteRecordsRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteRecordsRequest
    ,
      CompactArrayDeserializer<DeleteRecordsTopicV2Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DELETE_RECORDS_REQUEST_API_KEY =
  21;

constexpr int16_t DELETE_RECORDS_REQUEST_MAX_VERSION =
  2;

class DeleteRecordsRequestV0Parser:
  public RequestDataParser<
    DeleteRecordsRequest, DeleteRecordsRequestV0Deserializer>
{
public:
  DeleteRecordsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteRecordsRequestV1Parser:
  public RequestDataParser<
    DeleteRecordsRequest, DeleteRecordsRequestV1Deserializer>
{
public:
  DeleteRecordsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteRecordsRequestV2Parser:
  public RequestDataParser<
    DeleteRecordsRequest, DeleteRecordsRequestV2Deserializer>
{
public:
  DeleteRecordsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct InitProducerIdRequest {

  
  
  const absl::optional<std::string> transactional_id_;
  const int32_t transaction_timeout_ms_;
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  InitProducerIdRequest(absl::optional<std::string> transactional_id, int32_t transaction_timeout_ms): transactional_id_{transactional_id}, transaction_timeout_ms_{transaction_timeout_ms}, producer_id_{-1}, producer_epoch_{-1}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  InitProducerIdRequest(absl::optional<std::string> transactional_id, int32_t transaction_timeout_ms, TaggedFields tagged_fields): transactional_id_{transactional_id}, transaction_timeout_ms_{transaction_timeout_ms}, producer_id_{-1}, producer_epoch_{-1}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [3, 4]
  InitProducerIdRequest(absl::optional<std::string> transactional_id, int32_t transaction_timeout_ms, int64_t producer_id, int16_t producer_epoch, TaggedFields tagged_fields): transactional_id_{transactional_id}, transaction_timeout_ms_{transaction_timeout_ms}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(transactional_id_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(transaction_timeout_ms_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(producer_epoch_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(transactional_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(transaction_timeout_ms_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(producer_epoch_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const InitProducerIdRequest& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && transaction_timeout_ms_ == rhs.transaction_timeout_ms_
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class InitProducerIdRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    InitProducerIdRequest
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    >{};

class InitProducerIdRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    InitProducerIdRequest
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    >{};

class InitProducerIdRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    InitProducerIdRequest
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class InitProducerIdRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    InitProducerIdRequest
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class InitProducerIdRequestV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    InitProducerIdRequest
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t INIT_PRODUCER_ID_REQUEST_API_KEY =
  22;

constexpr int16_t INIT_PRODUCER_ID_REQUEST_MAX_VERSION =
  4;

class InitProducerIdRequestV0Parser:
  public RequestDataParser<
    InitProducerIdRequest, InitProducerIdRequestV0Deserializer>
{
public:
  InitProducerIdRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class InitProducerIdRequestV1Parser:
  public RequestDataParser<
    InitProducerIdRequest, InitProducerIdRequestV1Deserializer>
{
public:
  InitProducerIdRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class InitProducerIdRequestV2Parser:
  public RequestDataParser<
    InitProducerIdRequest, InitProducerIdRequestV2Deserializer>
{
public:
  InitProducerIdRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class InitProducerIdRequestV3Parser:
  public RequestDataParser<
    InitProducerIdRequest, InitProducerIdRequestV3Deserializer>
{
public:
  InitProducerIdRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class InitProducerIdRequestV4Parser:
  public RequestDataParser<
    InitProducerIdRequest, InitProducerIdRequestV4Deserializer>
{
public:
  InitProducerIdRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct OffsetForLeaderPartition {

  
  
  const int32_t partition_;
  const int32_t current_leader_epoch_;
  const int32_t leader_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  OffsetForLeaderPartition(int32_t partition, int32_t leader_epoch): partition_{partition}, current_leader_epoch_{-1}, leader_epoch_{leader_epoch}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  OffsetForLeaderPartition(int32_t partition, int32_t current_leader_epoch, int32_t leader_epoch): partition_{partition}, current_leader_epoch_{current_leader_epoch}, leader_epoch_{leader_epoch}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  OffsetForLeaderPartition(int32_t partition, int32_t current_leader_epoch, int32_t leader_epoch, TaggedFields tagged_fields): partition_{partition}, current_leader_epoch_{current_leader_epoch}, leader_epoch_{leader_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(partition_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeSize(current_leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(partition_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encode(current_leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetForLeaderPartition& rhs) const {
  
    return true
    && partition_ == rhs.partition_
    && current_leader_epoch_ == rhs.current_leader_epoch_
    && leader_epoch_ == rhs.leader_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetForLeaderPartitionV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    >{};

class OffsetForLeaderPartitionV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    >{};

class OffsetForLeaderPartitionV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetForLeaderPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    >{};

class OffsetForLeaderPartitionV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetForLeaderPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    >{};

class OffsetForLeaderPartitionV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetForLeaderPartition
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetForLeaderTopic {

  
  
  const std::string topic_;
  const std::vector<OffsetForLeaderPartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  OffsetForLeaderTopic(std::string topic, std::vector<OffsetForLeaderPartition> partitions): topic_{topic}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  OffsetForLeaderTopic(std::string topic, std::vector<OffsetForLeaderPartition> partitions, TaggedFields tagged_fields): topic_{topic}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(topic_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(topic_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(topic_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(topic_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetForLeaderTopic& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetForLeaderTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetForLeaderPartitionV0Deserializer>
    >{};

class OffsetForLeaderTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetForLeaderPartitionV1Deserializer>
    >{};

class OffsetForLeaderTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetForLeaderPartitionV2Deserializer>
    >{};

class OffsetForLeaderTopicV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetForLeaderPartitionV3Deserializer>
    >{};

class OffsetForLeaderTopicV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetForLeaderTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetForLeaderPartitionV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetForLeaderEpochRequest {

  
  
  const int32_t replica_id_;
  const std::vector<OffsetForLeaderTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  OffsetForLeaderEpochRequest(std::vector<OffsetForLeaderTopic> topics): replica_id_{-2}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  OffsetForLeaderEpochRequest(int32_t replica_id, std::vector<OffsetForLeaderTopic> topics): replica_id_{replica_id}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  OffsetForLeaderEpochRequest(int32_t replica_id, std::vector<OffsetForLeaderTopic> topics, TaggedFields tagged_fields): replica_id_{replica_id}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(replica_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(replica_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetForLeaderEpochRequest& rhs) const {
  
    return true
    && replica_id_ == rhs.replica_id_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetForLeaderEpochRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetForLeaderEpochRequest
    ,
      ArrayDeserializer<OffsetForLeaderTopicV0Deserializer>
    >{};

class OffsetForLeaderEpochRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetForLeaderEpochRequest
    ,
      ArrayDeserializer<OffsetForLeaderTopicV1Deserializer>
    >{};

class OffsetForLeaderEpochRequestV2Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetForLeaderEpochRequest
    ,
      ArrayDeserializer<OffsetForLeaderTopicV2Deserializer>
    >{};

class OffsetForLeaderEpochRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderEpochRequest
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetForLeaderTopicV3Deserializer>
    >{};

class OffsetForLeaderEpochRequestV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetForLeaderEpochRequest
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<OffsetForLeaderTopicV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t OFFSET_FOR_LEADER_EPOCH_REQUEST_API_KEY =
  23;

constexpr int16_t OFFSET_FOR_LEADER_EPOCH_REQUEST_MAX_VERSION =
  4;

class OffsetForLeaderEpochRequestV0Parser:
  public RequestDataParser<
    OffsetForLeaderEpochRequest, OffsetForLeaderEpochRequestV0Deserializer>
{
public:
  OffsetForLeaderEpochRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetForLeaderEpochRequestV1Parser:
  public RequestDataParser<
    OffsetForLeaderEpochRequest, OffsetForLeaderEpochRequestV1Deserializer>
{
public:
  OffsetForLeaderEpochRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetForLeaderEpochRequestV2Parser:
  public RequestDataParser<
    OffsetForLeaderEpochRequest, OffsetForLeaderEpochRequestV2Deserializer>
{
public:
  OffsetForLeaderEpochRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetForLeaderEpochRequestV3Parser:
  public RequestDataParser<
    OffsetForLeaderEpochRequest, OffsetForLeaderEpochRequestV3Deserializer>
{
public:
  OffsetForLeaderEpochRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class OffsetForLeaderEpochRequestV4Parser:
  public RequestDataParser<
    OffsetForLeaderEpochRequest, OffsetForLeaderEpochRequestV4Deserializer>
{
public:
  OffsetForLeaderEpochRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct AddPartitionsToTxnTopic {

  
  
  const std::string name_;
  const std::vector<int32_t> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  AddPartitionsToTxnTopic(std::string name, std::vector<int32_t> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4]
  AddPartitionsToTxnTopic(std::string name, std::vector<int32_t> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddPartitionsToTxnTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddPartitionsToTxnTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class AddPartitionsToTxnTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class AddPartitionsToTxnTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class AddPartitionsToTxnTopicV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AddPartitionsToTxnTopicV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AddPartitionsToTxnTransaction {

  
  
  const std::string transactional_id_;
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const bool verify_only_;
  const std::vector<AddPartitionsToTxnTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [4]
  AddPartitionsToTxnTransaction(std::string transactional_id, int64_t producer_id, int16_t producer_epoch, bool verify_only, std::vector<AddPartitionsToTxnTopic> topics, TaggedFields tagged_fields): transactional_id_{transactional_id}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, verify_only_{verify_only}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(producer_epoch_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(verify_only_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(producer_epoch_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(verify_only_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddPartitionsToTxnTransaction& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && verify_only_ == rhs.verify_only_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddPartitionsToTxnTransactionV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    AddPartitionsToTxnTransaction
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<AddPartitionsToTxnTopicV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AddPartitionsToTxnRequest {

  
  
  const std::vector<AddPartitionsToTxnTransaction> transactions_;
  const std::string v3_and_below_transactional_id_;
  const int64_t v3_and_below_producer_id_;
  const int16_t v3_and_below_producer_epoch_;
  const std::vector<AddPartitionsToTxnTopic> v3_and_below_topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  AddPartitionsToTxnRequest(std::string v3_and_below_transactional_id, int64_t v3_and_below_producer_id, int16_t v3_and_below_producer_epoch, std::vector<AddPartitionsToTxnTopic> v3_and_below_topics): transactions_{std::vector<AddPartitionsToTxnTransaction>{}}, v3_and_below_transactional_id_{v3_and_below_transactional_id}, v3_and_below_producer_id_{v3_and_below_producer_id}, v3_and_below_producer_epoch_{v3_and_below_producer_epoch}, v3_and_below_topics_{v3_and_below_topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  AddPartitionsToTxnRequest(std::string v3_and_below_transactional_id, int64_t v3_and_below_producer_id, int16_t v3_and_below_producer_epoch, std::vector<AddPartitionsToTxnTopic> v3_and_below_topics, TaggedFields tagged_fields): transactions_{std::vector<AddPartitionsToTxnTransaction>{}}, v3_and_below_transactional_id_{v3_and_below_transactional_id}, v3_and_below_producer_id_{v3_and_below_producer_id}, v3_and_below_producer_epoch_{v3_and_below_producer_epoch}, v3_and_below_topics_{v3_and_below_topics}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  AddPartitionsToTxnRequest(std::vector<AddPartitionsToTxnTransaction> transactions, TaggedFields tagged_fields): transactions_{transactions}, v3_and_below_transactional_id_{""}, v3_and_below_producer_id_{0}, v3_and_below_producer_epoch_{0}, v3_and_below_topics_{std::vector<AddPartitionsToTxnTopic>{}}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(transactions_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(v3_and_below_transactional_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(v3_and_below_transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(v3_and_below_producer_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(v3_and_below_producer_epoch_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(v3_and_below_topics_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(v3_and_below_topics_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(transactions_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(v3_and_below_transactional_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(v3_and_below_transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(v3_and_below_producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(v3_and_below_producer_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(v3_and_below_topics_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(v3_and_below_topics_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddPartitionsToTxnRequest& rhs) const {
  
    return true
    && transactions_ == rhs.transactions_
    && v3_and_below_transactional_id_ == rhs.v3_and_below_transactional_id_
    && v3_and_below_producer_id_ == rhs.v3_and_below_producer_id_
    && v3_and_below_producer_epoch_ == rhs.v3_and_below_producer_epoch_
    && v3_and_below_topics_ == rhs.v3_and_below_topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddPartitionsToTxnRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    AddPartitionsToTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnTopicV0Deserializer>
    >{};

class AddPartitionsToTxnRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    AddPartitionsToTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnTopicV1Deserializer>
    >{};

class AddPartitionsToTxnRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    AddPartitionsToTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnTopicV2Deserializer>
    >{};

class AddPartitionsToTxnRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    AddPartitionsToTxnRequest
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<AddPartitionsToTxnTopicV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AddPartitionsToTxnRequestV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnRequest
    ,
      CompactArrayDeserializer<AddPartitionsToTxnTransactionV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ADD_PARTITIONS_TO_TXN_REQUEST_API_KEY =
  24;

constexpr int16_t ADD_PARTITIONS_TO_TXN_REQUEST_MAX_VERSION =
  4;

class AddPartitionsToTxnRequestV0Parser:
  public RequestDataParser<
    AddPartitionsToTxnRequest, AddPartitionsToTxnRequestV0Deserializer>
{
public:
  AddPartitionsToTxnRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AddPartitionsToTxnRequestV1Parser:
  public RequestDataParser<
    AddPartitionsToTxnRequest, AddPartitionsToTxnRequestV1Deserializer>
{
public:
  AddPartitionsToTxnRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AddPartitionsToTxnRequestV2Parser:
  public RequestDataParser<
    AddPartitionsToTxnRequest, AddPartitionsToTxnRequestV2Deserializer>
{
public:
  AddPartitionsToTxnRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AddPartitionsToTxnRequestV3Parser:
  public RequestDataParser<
    AddPartitionsToTxnRequest, AddPartitionsToTxnRequestV3Deserializer>
{
public:
  AddPartitionsToTxnRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AddPartitionsToTxnRequestV4Parser:
  public RequestDataParser<
    AddPartitionsToTxnRequest, AddPartitionsToTxnRequestV4Deserializer>
{
public:
  AddPartitionsToTxnRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct AddOffsetsToTxnRequest {

  
  
  const std::string transactional_id_;
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const std::string group_id_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  AddOffsetsToTxnRequest(std::string transactional_id, int64_t producer_id, int16_t producer_epoch, std::string group_id): transactional_id_{transactional_id}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, group_id_{group_id}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  AddOffsetsToTxnRequest(std::string transactional_id, int64_t producer_id, int16_t producer_epoch, std::string group_id, TaggedFields tagged_fields): transactional_id_{transactional_id}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, group_id_{group_id}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(transactional_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(producer_epoch_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(transactional_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(producer_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddOffsetsToTxnRequest& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && group_id_ == rhs.group_id_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddOffsetsToTxnRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    AddOffsetsToTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      StringDeserializer
    >{};

class AddOffsetsToTxnRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    AddOffsetsToTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      StringDeserializer
    >{};

class AddOffsetsToTxnRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    AddOffsetsToTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      StringDeserializer
    >{};

class AddOffsetsToTxnRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    AddOffsetsToTxnRequest
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ADD_OFFSETS_TO_TXN_REQUEST_API_KEY =
  25;

constexpr int16_t ADD_OFFSETS_TO_TXN_REQUEST_MAX_VERSION =
  3;

class AddOffsetsToTxnRequestV0Parser:
  public RequestDataParser<
    AddOffsetsToTxnRequest, AddOffsetsToTxnRequestV0Deserializer>
{
public:
  AddOffsetsToTxnRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AddOffsetsToTxnRequestV1Parser:
  public RequestDataParser<
    AddOffsetsToTxnRequest, AddOffsetsToTxnRequestV1Deserializer>
{
public:
  AddOffsetsToTxnRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AddOffsetsToTxnRequestV2Parser:
  public RequestDataParser<
    AddOffsetsToTxnRequest, AddOffsetsToTxnRequestV2Deserializer>
{
public:
  AddOffsetsToTxnRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AddOffsetsToTxnRequestV3Parser:
  public RequestDataParser<
    AddOffsetsToTxnRequest, AddOffsetsToTxnRequestV3Deserializer>
{
public:
  AddOffsetsToTxnRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct EndTxnRequest {

  
  
  const std::string transactional_id_;
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const bool committed_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  EndTxnRequest(std::string transactional_id, int64_t producer_id, int16_t producer_epoch, bool committed): transactional_id_{transactional_id}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, committed_{committed}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  EndTxnRequest(std::string transactional_id, int64_t producer_id, int16_t producer_epoch, bool committed, TaggedFields tagged_fields): transactional_id_{transactional_id}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, committed_{committed}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(transactional_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(producer_epoch_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(committed_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(transactional_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(producer_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(committed_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EndTxnRequest& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && committed_ == rhs.committed_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class EndTxnRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    EndTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    >{};

class EndTxnRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    EndTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    >{};

class EndTxnRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    EndTxnRequest
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    >{};

class EndTxnRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    EndTxnRequest
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t END_TXN_REQUEST_API_KEY =
  26;

constexpr int16_t END_TXN_REQUEST_MAX_VERSION =
  3;

class EndTxnRequestV0Parser:
  public RequestDataParser<
    EndTxnRequest, EndTxnRequestV0Deserializer>
{
public:
  EndTxnRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class EndTxnRequestV1Parser:
  public RequestDataParser<
    EndTxnRequest, EndTxnRequestV1Deserializer>
{
public:
  EndTxnRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class EndTxnRequestV2Parser:
  public RequestDataParser<
    EndTxnRequest, EndTxnRequestV2Deserializer>
{
public:
  EndTxnRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class EndTxnRequestV3Parser:
  public RequestDataParser<
    EndTxnRequest, EndTxnRequestV3Deserializer>
{
public:
  EndTxnRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct WritableTxnMarkerTopic {

  
  
  const std::string name_;
  const std::vector<int32_t> partition_indexes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  WritableTxnMarkerTopic(std::string name, std::vector<int32_t> partition_indexes): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  WritableTxnMarkerTopic(std::string name, std::vector<int32_t> partition_indexes, TaggedFields tagged_fields): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_indexes_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(partition_indexes_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_indexes_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(partition_indexes_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const WritableTxnMarkerTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_indexes_ == rhs.partition_indexes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class WritableTxnMarkerTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    WritableTxnMarkerTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class WritableTxnMarkerTopicV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    WritableTxnMarkerTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct WritableTxnMarker {

  
  
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const bool transaction_result_;
  const std::vector<WritableTxnMarkerTopic> topics_;
  const int32_t coordinator_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  WritableTxnMarker(int64_t producer_id, int16_t producer_epoch, bool transaction_result, std::vector<WritableTxnMarkerTopic> topics, int32_t coordinator_epoch): producer_id_{producer_id}, producer_epoch_{producer_epoch}, transaction_result_{transaction_result}, topics_{topics}, coordinator_epoch_{coordinator_epoch}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  WritableTxnMarker(int64_t producer_id, int16_t producer_epoch, bool transaction_result, std::vector<WritableTxnMarkerTopic> topics, int32_t coordinator_epoch, TaggedFields tagged_fields): producer_id_{producer_id}, producer_epoch_{producer_epoch}, transaction_result_{transaction_result}, topics_{topics}, coordinator_epoch_{coordinator_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(producer_epoch_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(transaction_result_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(coordinator_epoch_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(producer_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(transaction_result_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(coordinator_epoch_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const WritableTxnMarker& rhs) const {
  
    return true
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && transaction_result_ == rhs.transaction_result_
    && topics_ == rhs.topics_
    && coordinator_epoch_ == rhs.coordinator_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class WritableTxnMarkerV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    WritableTxnMarker
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<WritableTxnMarkerTopicV0Deserializer>
    ,
      Int32Deserializer
    >{};

class WritableTxnMarkerV1Deserializer:
  public CompositeDeserializerWith6Delegates<
    WritableTxnMarker
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<WritableTxnMarkerTopicV1Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct WriteTxnMarkersRequest {

  
  
  const std::vector<WritableTxnMarker> markers_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  WriteTxnMarkersRequest(std::vector<WritableTxnMarker> markers): markers_{markers}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  WriteTxnMarkersRequest(std::vector<WritableTxnMarker> markers, TaggedFields tagged_fields): markers_{markers}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(markers_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(markers_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(markers_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(markers_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const WriteTxnMarkersRequest& rhs) const {
  
    return true
    && markers_ == rhs.markers_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class WriteTxnMarkersRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    WriteTxnMarkersRequest
    ,
      ArrayDeserializer<WritableTxnMarkerV0Deserializer>
    >{};

class WriteTxnMarkersRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    WriteTxnMarkersRequest
    ,
      CompactArrayDeserializer<WritableTxnMarkerV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t WRITE_TXN_MARKERS_REQUEST_API_KEY =
  27;

constexpr int16_t WRITE_TXN_MARKERS_REQUEST_MAX_VERSION =
  1;

class WriteTxnMarkersRequestV0Parser:
  public RequestDataParser<
    WriteTxnMarkersRequest, WriteTxnMarkersRequestV0Deserializer>
{
public:
  WriteTxnMarkersRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class WriteTxnMarkersRequestV1Parser:
  public RequestDataParser<
    WriteTxnMarkersRequest, WriteTxnMarkersRequestV1Deserializer>
{
public:
  WriteTxnMarkersRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct TxnOffsetCommitRequestPartition {

  
  
  const int32_t partition_index_;
  const int64_t committed_offset_;
  const int32_t committed_leader_epoch_;
  const absl::optional<std::string> committed_metadata_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  TxnOffsetCommitRequestPartition(int32_t partition_index, int64_t committed_offset, absl::optional<std::string> committed_metadata): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{-1}, committed_metadata_{committed_metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  TxnOffsetCommitRequestPartition(int32_t partition_index, int64_t committed_offset, int32_t committed_leader_epoch, absl::optional<std::string> committed_metadata): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{committed_leader_epoch}, committed_metadata_{committed_metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  TxnOffsetCommitRequestPartition(int32_t partition_index, int64_t committed_offset, int32_t committed_leader_epoch, absl::optional<std::string> committed_metadata, TaggedFields tagged_fields): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{committed_leader_epoch}, committed_metadata_{committed_metadata}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(committed_offset_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeSize(committed_leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(committed_metadata_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(committed_metadata_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(committed_offset_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encode(committed_leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(committed_metadata_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(committed_metadata_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TxnOffsetCommitRequestPartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && committed_offset_ == rhs.committed_offset_
    && committed_leader_epoch_ == rhs.committed_leader_epoch_
    && committed_metadata_ == rhs.committed_metadata_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TxnOffsetCommitRequestPartitionV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    TxnOffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class TxnOffsetCommitRequestPartitionV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    TxnOffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    >{};

class TxnOffsetCommitRequestPartitionV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    TxnOffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class TxnOffsetCommitRequestPartitionV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    TxnOffsetCommitRequestPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct TxnOffsetCommitRequestTopic {

  
  
  const std::string name_;
  const std::vector<TxnOffsetCommitRequestPartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  TxnOffsetCommitRequestTopic(std::string name, std::vector<TxnOffsetCommitRequestPartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  TxnOffsetCommitRequestTopic(std::string name, std::vector<TxnOffsetCommitRequestPartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TxnOffsetCommitRequestTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TxnOffsetCommitRequestTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<TxnOffsetCommitRequestPartitionV0Deserializer>
    >{};

class TxnOffsetCommitRequestTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<TxnOffsetCommitRequestPartitionV1Deserializer>
    >{};

class TxnOffsetCommitRequestTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<TxnOffsetCommitRequestPartitionV2Deserializer>
    >{};

class TxnOffsetCommitRequestTopicV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    TxnOffsetCommitRequestTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<TxnOffsetCommitRequestPartitionV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct TxnOffsetCommitRequest {

  
  
  const std::string transactional_id_;
  const std::string group_id_;
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const int32_t generation_id_;
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const std::vector<TxnOffsetCommitRequestTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  TxnOffsetCommitRequest(std::string transactional_id, std::string group_id, int64_t producer_id, int16_t producer_epoch, std::vector<TxnOffsetCommitRequestTopic> topics): transactional_id_{transactional_id}, group_id_{group_id}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, generation_id_{-1}, member_id_{}, group_instance_id_{absl::nullopt}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  TxnOffsetCommitRequest(std::string transactional_id, std::string group_id, int64_t producer_id, int16_t producer_epoch, int32_t generation_id, std::string member_id, absl::optional<std::string> group_instance_id, std::vector<TxnOffsetCommitRequestTopic> topics, TaggedFields tagged_fields): transactional_id_{transactional_id}, group_id_{group_id}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, generation_id_{generation_id}, member_id_{member_id}, group_instance_id_{group_instance_id}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(transactional_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(producer_epoch_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(generation_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(group_instance_id_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(transactional_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(producer_epoch_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(generation_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(group_instance_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TxnOffsetCommitRequest& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && group_id_ == rhs.group_id_
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && generation_id_ == rhs.generation_id_
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TxnOffsetCommitRequestV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    TxnOffsetCommitRequest
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<TxnOffsetCommitRequestTopicV0Deserializer>
    >{};

class TxnOffsetCommitRequestV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    TxnOffsetCommitRequest
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<TxnOffsetCommitRequestTopicV1Deserializer>
    >{};

class TxnOffsetCommitRequestV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    TxnOffsetCommitRequest
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<TxnOffsetCommitRequestTopicV2Deserializer>
    >{};

class TxnOffsetCommitRequestV3Deserializer:
  public CompositeDeserializerWith9Delegates<
    TxnOffsetCommitRequest
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<TxnOffsetCommitRequestTopicV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t TXN_OFFSET_COMMIT_REQUEST_API_KEY =
  28;

constexpr int16_t TXN_OFFSET_COMMIT_REQUEST_MAX_VERSION =
  3;

class TxnOffsetCommitRequestV0Parser:
  public RequestDataParser<
    TxnOffsetCommitRequest, TxnOffsetCommitRequestV0Deserializer>
{
public:
  TxnOffsetCommitRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class TxnOffsetCommitRequestV1Parser:
  public RequestDataParser<
    TxnOffsetCommitRequest, TxnOffsetCommitRequestV1Deserializer>
{
public:
  TxnOffsetCommitRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class TxnOffsetCommitRequestV2Parser:
  public RequestDataParser<
    TxnOffsetCommitRequest, TxnOffsetCommitRequestV2Deserializer>
{
public:
  TxnOffsetCommitRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class TxnOffsetCommitRequestV3Parser:
  public RequestDataParser<
    TxnOffsetCommitRequest, TxnOffsetCommitRequestV3Deserializer>
{
public:
  TxnOffsetCommitRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribeAclsRequest {

  
  
  const int8_t resource_type_filter_;
  const absl::optional<std::string> resource_name_filter_;
  const int8_t pattern_type_filter_;
  const absl::optional<std::string> principal_filter_;
  const absl::optional<std::string> host_filter_;
  const int8_t operation_;
  const int8_t permission_type_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeAclsRequest(int8_t resource_type_filter, absl::optional<std::string> resource_name_filter, absl::optional<std::string> principal_filter, absl::optional<std::string> host_filter, int8_t operation, int8_t permission_type): resource_type_filter_{resource_type_filter}, resource_name_filter_{resource_name_filter}, pattern_type_filter_{3}, principal_filter_{principal_filter}, host_filter_{host_filter}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DescribeAclsRequest(int8_t resource_type_filter, absl::optional<std::string> resource_name_filter, int8_t pattern_type_filter, absl::optional<std::string> principal_filter, absl::optional<std::string> host_filter, int8_t operation, int8_t permission_type): resource_type_filter_{resource_type_filter}, resource_name_filter_{resource_name_filter}, pattern_type_filter_{pattern_type_filter}, principal_filter_{principal_filter}, host_filter_{host_filter}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribeAclsRequest(int8_t resource_type_filter, absl::optional<std::string> resource_name_filter, int8_t pattern_type_filter, absl::optional<std::string> principal_filter, absl::optional<std::string> host_filter, int8_t operation, int8_t permission_type, TaggedFields tagged_fields): resource_type_filter_{resource_type_filter}, resource_name_filter_{resource_name_filter}, pattern_type_filter_{pattern_type_filter}, principal_filter_{principal_filter}, host_filter_{host_filter}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(resource_type_filter_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resource_name_filter_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(resource_name_filter_);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(pattern_type_filter_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(principal_filter_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(principal_filter_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(host_filter_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(host_filter_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(operation_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(permission_type_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(resource_type_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resource_name_filter_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(resource_name_filter_, dst);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(pattern_type_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(principal_filter_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(principal_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(host_filter_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(host_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(operation_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(permission_type_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeAclsRequest& rhs) const {
  
    return true
    && resource_type_filter_ == rhs.resource_type_filter_
    && resource_name_filter_ == rhs.resource_name_filter_
    && pattern_type_filter_ == rhs.pattern_type_filter_
    && principal_filter_ == rhs.principal_filter_
    && host_filter_ == rhs.host_filter_
    && operation_ == rhs.operation_
    && permission_type_ == rhs.permission_type_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeAclsRequestV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribeAclsRequest
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    ,
      NullableStringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class DescribeAclsRequestV1Deserializer:
  public CompositeDeserializerWith7Delegates<
    DescribeAclsRequest
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class DescribeAclsRequestV2Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribeAclsRequest
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeAclsRequestV3Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribeAclsRequest
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_ACLS_REQUEST_API_KEY =
  29;

constexpr int16_t DESCRIBE_ACLS_REQUEST_MAX_VERSION =
  3;

class DescribeAclsRequestV0Parser:
  public RequestDataParser<
    DescribeAclsRequest, DescribeAclsRequestV0Deserializer>
{
public:
  DescribeAclsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeAclsRequestV1Parser:
  public RequestDataParser<
    DescribeAclsRequest, DescribeAclsRequestV1Deserializer>
{
public:
  DescribeAclsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeAclsRequestV2Parser:
  public RequestDataParser<
    DescribeAclsRequest, DescribeAclsRequestV2Deserializer>
{
public:
  DescribeAclsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeAclsRequestV3Parser:
  public RequestDataParser<
    DescribeAclsRequest, DescribeAclsRequestV3Deserializer>
{
public:
  DescribeAclsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct AclCreation {

  
  
  const int8_t resource_type_;
  const std::string resource_name_;
  const int8_t resource_pattern_type_;
  const std::string principal_;
  const std::string host_;
  const int8_t operation_;
  const int8_t permission_type_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AclCreation(int8_t resource_type, std::string resource_name, std::string principal, std::string host, int8_t operation, int8_t permission_type): resource_type_{resource_type}, resource_name_{resource_name}, resource_pattern_type_{3}, principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  AclCreation(int8_t resource_type, std::string resource_name, int8_t resource_pattern_type, std::string principal, std::string host, int8_t operation, int8_t permission_type): resource_type_{resource_type}, resource_name_{resource_name}, resource_pattern_type_{resource_pattern_type}, principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  AclCreation(int8_t resource_type, std::string resource_name, int8_t resource_pattern_type, std::string principal, std::string host, int8_t operation, int8_t permission_type, TaggedFields tagged_fields): resource_type_{resource_type}, resource_name_{resource_name}, resource_pattern_type_{resource_pattern_type}, principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(resource_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resource_name_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(resource_name_);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(resource_pattern_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(principal_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(principal_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(host_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(host_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(operation_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(permission_type_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(resource_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resource_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(resource_name_, dst);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(resource_pattern_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(principal_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(principal_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(host_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(host_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(operation_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(permission_type_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AclCreation& rhs) const {
  
    return true
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && resource_pattern_type_ == rhs.resource_pattern_type_
    && principal_ == rhs.principal_
    && host_ == rhs.host_
    && operation_ == rhs.operation_
    && permission_type_ == rhs.permission_type_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AclCreationV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    AclCreation
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class AclCreationV1Deserializer:
  public CompositeDeserializerWith7Delegates<
    AclCreation
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class AclCreationV2Deserializer:
  public CompositeDeserializerWith8Delegates<
    AclCreation
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class AclCreationV3Deserializer:
  public CompositeDeserializerWith8Delegates<
    AclCreation
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct CreateAclsRequest {

  
  
  const std::vector<AclCreation> creations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreateAclsRequest(std::vector<AclCreation> creations): creations_{creations}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreateAclsRequest(std::vector<AclCreation> creations, TaggedFields tagged_fields): creations_{creations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(creations_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(creations_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(creations_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(creations_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreateAclsRequest& rhs) const {
  
    return true
    && creations_ == rhs.creations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreateAclsRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    CreateAclsRequest
    ,
      ArrayDeserializer<AclCreationV0Deserializer>
    >{};

class CreateAclsRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    CreateAclsRequest
    ,
      ArrayDeserializer<AclCreationV1Deserializer>
    >{};

class CreateAclsRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateAclsRequest
    ,
      CompactArrayDeserializer<AclCreationV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreateAclsRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateAclsRequest
    ,
      CompactArrayDeserializer<AclCreationV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t CREATE_ACLS_REQUEST_API_KEY =
  30;

constexpr int16_t CREATE_ACLS_REQUEST_MAX_VERSION =
  3;

class CreateAclsRequestV0Parser:
  public RequestDataParser<
    CreateAclsRequest, CreateAclsRequestV0Deserializer>
{
public:
  CreateAclsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateAclsRequestV1Parser:
  public RequestDataParser<
    CreateAclsRequest, CreateAclsRequestV1Deserializer>
{
public:
  CreateAclsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateAclsRequestV2Parser:
  public RequestDataParser<
    CreateAclsRequest, CreateAclsRequestV2Deserializer>
{
public:
  CreateAclsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateAclsRequestV3Parser:
  public RequestDataParser<
    CreateAclsRequest, CreateAclsRequestV3Deserializer>
{
public:
  CreateAclsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DeleteAclsFilter {

  
  
  const int8_t resource_type_filter_;
  const absl::optional<std::string> resource_name_filter_;
  const int8_t pattern_type_filter_;
  const absl::optional<std::string> principal_filter_;
  const absl::optional<std::string> host_filter_;
  const int8_t operation_;
  const int8_t permission_type_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DeleteAclsFilter(int8_t resource_type_filter, absl::optional<std::string> resource_name_filter, absl::optional<std::string> principal_filter, absl::optional<std::string> host_filter, int8_t operation, int8_t permission_type): resource_type_filter_{resource_type_filter}, resource_name_filter_{resource_name_filter}, pattern_type_filter_{3}, principal_filter_{principal_filter}, host_filter_{host_filter}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DeleteAclsFilter(int8_t resource_type_filter, absl::optional<std::string> resource_name_filter, int8_t pattern_type_filter, absl::optional<std::string> principal_filter, absl::optional<std::string> host_filter, int8_t operation, int8_t permission_type): resource_type_filter_{resource_type_filter}, resource_name_filter_{resource_name_filter}, pattern_type_filter_{pattern_type_filter}, principal_filter_{principal_filter}, host_filter_{host_filter}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DeleteAclsFilter(int8_t resource_type_filter, absl::optional<std::string> resource_name_filter, int8_t pattern_type_filter, absl::optional<std::string> principal_filter, absl::optional<std::string> host_filter, int8_t operation, int8_t permission_type, TaggedFields tagged_fields): resource_type_filter_{resource_type_filter}, resource_name_filter_{resource_name_filter}, pattern_type_filter_{pattern_type_filter}, principal_filter_{principal_filter}, host_filter_{host_filter}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(resource_type_filter_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resource_name_filter_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(resource_name_filter_);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(pattern_type_filter_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(principal_filter_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(principal_filter_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(host_filter_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(host_filter_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(operation_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(permission_type_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(resource_type_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resource_name_filter_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(resource_name_filter_, dst);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(pattern_type_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(principal_filter_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(principal_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(host_filter_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(host_filter_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(operation_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(permission_type_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteAclsFilter& rhs) const {
  
    return true
    && resource_type_filter_ == rhs.resource_type_filter_
    && resource_name_filter_ == rhs.resource_name_filter_
    && pattern_type_filter_ == rhs.pattern_type_filter_
    && principal_filter_ == rhs.principal_filter_
    && host_filter_ == rhs.host_filter_
    && operation_ == rhs.operation_
    && permission_type_ == rhs.permission_type_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteAclsFilterV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    DeleteAclsFilter
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    ,
      NullableStringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class DeleteAclsFilterV1Deserializer:
  public CompositeDeserializerWith7Delegates<
    DeleteAclsFilter
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class DeleteAclsFilterV2Deserializer:
  public CompositeDeserializerWith8Delegates<
    DeleteAclsFilter
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteAclsFilterV3Deserializer:
  public CompositeDeserializerWith8Delegates<
    DeleteAclsFilter
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteAclsRequest {

  
  
  const std::vector<DeleteAclsFilter> filters_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteAclsRequest(std::vector<DeleteAclsFilter> filters): filters_{filters}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DeleteAclsRequest(std::vector<DeleteAclsFilter> filters, TaggedFields tagged_fields): filters_{filters}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(filters_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(filters_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(filters_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(filters_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteAclsRequest& rhs) const {
  
    return true
    && filters_ == rhs.filters_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteAclsRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DeleteAclsRequest
    ,
      ArrayDeserializer<DeleteAclsFilterV0Deserializer>
    >{};

class DeleteAclsRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    DeleteAclsRequest
    ,
      ArrayDeserializer<DeleteAclsFilterV1Deserializer>
    >{};

class DeleteAclsRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteAclsRequest
    ,
      CompactArrayDeserializer<DeleteAclsFilterV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteAclsRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteAclsRequest
    ,
      CompactArrayDeserializer<DeleteAclsFilterV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DELETE_ACLS_REQUEST_API_KEY =
  31;

constexpr int16_t DELETE_ACLS_REQUEST_MAX_VERSION =
  3;

class DeleteAclsRequestV0Parser:
  public RequestDataParser<
    DeleteAclsRequest, DeleteAclsRequestV0Deserializer>
{
public:
  DeleteAclsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteAclsRequestV1Parser:
  public RequestDataParser<
    DeleteAclsRequest, DeleteAclsRequestV1Deserializer>
{
public:
  DeleteAclsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteAclsRequestV2Parser:
  public RequestDataParser<
    DeleteAclsRequest, DeleteAclsRequestV2Deserializer>
{
public:
  DeleteAclsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteAclsRequestV3Parser:
  public RequestDataParser<
    DeleteAclsRequest, DeleteAclsRequestV3Deserializer>
{
public:
  DeleteAclsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribeConfigsResource {

  
  
  const int8_t resource_type_;
  const std::string resource_name_;
  const absl::optional<std::vector<std::string>> configuration_keys_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  DescribeConfigsResource(int8_t resource_type, std::string resource_name, absl::optional<std::vector<std::string>> configuration_keys): resource_type_{resource_type}, resource_name_{resource_name}, configuration_keys_{configuration_keys}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DescribeConfigsResource(int8_t resource_type, std::string resource_name, absl::optional<std::vector<std::string>> configuration_keys, TaggedFields tagged_fields): resource_type_{resource_type}, resource_name_{resource_name}, configuration_keys_{configuration_keys}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(resource_type_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(resource_name_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(resource_name_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(configuration_keys_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(configuration_keys_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(resource_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(resource_name_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(resource_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(configuration_keys_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(configuration_keys_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeConfigsResource& rhs) const {
  
    return true
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && configuration_keys_ == rhs.configuration_keys_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeConfigsResourceV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<StringDeserializer>
    >{};

class DescribeConfigsResourceV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<StringDeserializer>
    >{};

class DescribeConfigsResourceV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<StringDeserializer>
    >{};

class DescribeConfigsResourceV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      NullableArrayDeserializer<StringDeserializer>
    >{};

class DescribeConfigsResourceV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeConfigsResource
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      NullableCompactArrayDeserializer<CompactStringDeserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeConfigsRequest {

  
  
  const std::vector<DescribeConfigsResource> resources_;
  const bool include_synonyms_;
  const bool include_documentation_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeConfigsRequest(std::vector<DescribeConfigsResource> resources): resources_{resources}, include_synonyms_{false}, include_documentation_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2]
  DescribeConfigsRequest(std::vector<DescribeConfigsResource> resources, bool include_synonyms): resources_{resources}, include_synonyms_{include_synonyms}, include_documentation_{false}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  DescribeConfigsRequest(std::vector<DescribeConfigsResource> resources, bool include_synonyms, bool include_documentation): resources_{resources}, include_synonyms_{include_synonyms}, include_documentation_{include_documentation}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DescribeConfigsRequest(std::vector<DescribeConfigsResource> resources, bool include_synonyms, bool include_documentation, TaggedFields tagged_fields): resources_{resources}, include_synonyms_{include_synonyms}, include_documentation_{include_documentation}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(resources_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(resources_);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(include_synonyms_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(include_documentation_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(resources_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(resources_, dst);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(include_synonyms_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(include_documentation_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeConfigsRequest& rhs) const {
  
    return true
    && resources_ == rhs.resources_
    && include_synonyms_ == rhs.include_synonyms_
    && include_documentation_ == rhs.include_documentation_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeConfigsRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeConfigsRequest
    ,
      ArrayDeserializer<DescribeConfigsResourceV0Deserializer>
    >{};

class DescribeConfigsRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeConfigsRequest
    ,
      ArrayDeserializer<DescribeConfigsResourceV1Deserializer>
    ,
      BooleanDeserializer
    >{};

class DescribeConfigsRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeConfigsRequest
    ,
      ArrayDeserializer<DescribeConfigsResourceV2Deserializer>
    ,
      BooleanDeserializer
    >{};

class DescribeConfigsRequestV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsRequest
    ,
      ArrayDeserializer<DescribeConfigsResourceV3Deserializer>
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    >{};

class DescribeConfigsRequestV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeConfigsRequest
    ,
      CompactArrayDeserializer<DescribeConfigsResourceV4Deserializer>
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_CONFIGS_REQUEST_API_KEY =
  32;

constexpr int16_t DESCRIBE_CONFIGS_REQUEST_MAX_VERSION =
  4;

class DescribeConfigsRequestV0Parser:
  public RequestDataParser<
    DescribeConfigsRequest, DescribeConfigsRequestV0Deserializer>
{
public:
  DescribeConfigsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeConfigsRequestV1Parser:
  public RequestDataParser<
    DescribeConfigsRequest, DescribeConfigsRequestV1Deserializer>
{
public:
  DescribeConfigsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeConfigsRequestV2Parser:
  public RequestDataParser<
    DescribeConfigsRequest, DescribeConfigsRequestV2Deserializer>
{
public:
  DescribeConfigsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeConfigsRequestV3Parser:
  public RequestDataParser<
    DescribeConfigsRequest, DescribeConfigsRequestV3Deserializer>
{
public:
  DescribeConfigsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeConfigsRequestV4Parser:
  public RequestDataParser<
    DescribeConfigsRequest, DescribeConfigsRequestV4Deserializer>
{
public:
  DescribeConfigsRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct AlterableConfig {

  
  
  const std::string name_;
  const absl::optional<std::string> value_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterableConfig(std::string name, absl::optional<std::string> value): name_{name}, value_{value}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterableConfig(std::string name, absl::optional<std::string> value, TaggedFields tagged_fields): name_{name}, value_{value}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(value_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(value_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(value_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(value_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterableConfig& rhs) const {
  
    return true
    && name_ == rhs.name_
    && value_ == rhs.value_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterableConfigV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterableConfig
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class AlterableConfigV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterableConfig
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class AlterableConfigV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterableConfig
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterConfigsResource {

  
  
  const int8_t resource_type_;
  const std::string resource_name_;
  const std::vector<AlterableConfig> configs_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterConfigsResource(int8_t resource_type, std::string resource_name, std::vector<AlterableConfig> configs): resource_type_{resource_type}, resource_name_{resource_name}, configs_{configs}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterConfigsResource(int8_t resource_type, std::string resource_name, std::vector<AlterableConfig> configs, TaggedFields tagged_fields): resource_type_{resource_type}, resource_name_{resource_name}, configs_{configs}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(resource_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resource_name_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(resource_name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(configs_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(configs_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(resource_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resource_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(resource_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(configs_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(configs_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterConfigsResource& rhs) const {
  
    return true
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && configs_ == rhs.configs_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterConfigsResourceV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterConfigsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AlterableConfigV0Deserializer>
    >{};

class AlterConfigsResourceV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterConfigsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AlterableConfigV1Deserializer>
    >{};

class AlterConfigsResourceV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterConfigsResource
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<AlterableConfigV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterConfigsRequest {

  
  
  const std::vector<AlterConfigsResource> resources_;
  const bool validate_only_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterConfigsRequest(std::vector<AlterConfigsResource> resources, bool validate_only): resources_{resources}, validate_only_{validate_only}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterConfigsRequest(std::vector<AlterConfigsResource> resources, bool validate_only, TaggedFields tagged_fields): resources_{resources}, validate_only_{validate_only}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resources_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(resources_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(validate_only_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resources_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(resources_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(validate_only_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterConfigsRequest& rhs) const {
  
    return true
    && resources_ == rhs.resources_
    && validate_only_ == rhs.validate_only_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterConfigsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterConfigsRequest
    ,
      ArrayDeserializer<AlterConfigsResourceV0Deserializer>
    ,
      BooleanDeserializer
    >{};

class AlterConfigsRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterConfigsRequest
    ,
      ArrayDeserializer<AlterConfigsResourceV1Deserializer>
    ,
      BooleanDeserializer
    >{};

class AlterConfigsRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterConfigsRequest
    ,
      CompactArrayDeserializer<AlterConfigsResourceV2Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ALTER_CONFIGS_REQUEST_API_KEY =
  33;

constexpr int16_t ALTER_CONFIGS_REQUEST_MAX_VERSION =
  2;

class AlterConfigsRequestV0Parser:
  public RequestDataParser<
    AlterConfigsRequest, AlterConfigsRequestV0Deserializer>
{
public:
  AlterConfigsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterConfigsRequestV1Parser:
  public RequestDataParser<
    AlterConfigsRequest, AlterConfigsRequestV1Deserializer>
{
public:
  AlterConfigsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterConfigsRequestV2Parser:
  public RequestDataParser<
    AlterConfigsRequest, AlterConfigsRequestV2Deserializer>
{
public:
  AlterConfigsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct AlterReplicaLogDirTopic {

  
  
  const std::string name_;
  const std::vector<int32_t> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterReplicaLogDirTopic(std::string name, std::vector<int32_t> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterReplicaLogDirTopic(std::string name, std::vector<int32_t> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterReplicaLogDirTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterReplicaLogDirTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class AlterReplicaLogDirTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class AlterReplicaLogDirTopicV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterReplicaLogDirTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterReplicaLogDir {

  
  
  const std::string path_;
  const std::vector<AlterReplicaLogDirTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterReplicaLogDir(std::string path, std::vector<AlterReplicaLogDirTopic> topics): path_{path}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterReplicaLogDir(std::string path, std::vector<AlterReplicaLogDirTopic> topics, TaggedFields tagged_fields): path_{path}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(path_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(path_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(path_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(path_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterReplicaLogDir& rhs) const {
  
    return true
    && path_ == rhs.path_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterReplicaLogDirV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDir
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AlterReplicaLogDirTopicV0Deserializer>
    >{};

class AlterReplicaLogDirV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDir
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AlterReplicaLogDirTopicV1Deserializer>
    >{};

class AlterReplicaLogDirV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterReplicaLogDir
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<AlterReplicaLogDirTopicV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterReplicaLogDirsRequest {

  
  
  const std::vector<AlterReplicaLogDir> dirs_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterReplicaLogDirsRequest(std::vector<AlterReplicaLogDir> dirs): dirs_{dirs}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterReplicaLogDirsRequest(std::vector<AlterReplicaLogDir> dirs, TaggedFields tagged_fields): dirs_{dirs}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(dirs_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(dirs_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(dirs_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(dirs_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterReplicaLogDirsRequest& rhs) const {
  
    return true
    && dirs_ == rhs.dirs_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterReplicaLogDirsRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    AlterReplicaLogDirsRequest
    ,
      ArrayDeserializer<AlterReplicaLogDirV0Deserializer>
    >{};

class AlterReplicaLogDirsRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    AlterReplicaLogDirsRequest
    ,
      ArrayDeserializer<AlterReplicaLogDirV1Deserializer>
    >{};

class AlterReplicaLogDirsRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirsRequest
    ,
      CompactArrayDeserializer<AlterReplicaLogDirV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ALTER_REPLICA_LOG_DIRS_REQUEST_API_KEY =
  34;

constexpr int16_t ALTER_REPLICA_LOG_DIRS_REQUEST_MAX_VERSION =
  2;

class AlterReplicaLogDirsRequestV0Parser:
  public RequestDataParser<
    AlterReplicaLogDirsRequest, AlterReplicaLogDirsRequestV0Deserializer>
{
public:
  AlterReplicaLogDirsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterReplicaLogDirsRequestV1Parser:
  public RequestDataParser<
    AlterReplicaLogDirsRequest, AlterReplicaLogDirsRequestV1Deserializer>
{
public:
  AlterReplicaLogDirsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterReplicaLogDirsRequestV2Parser:
  public RequestDataParser<
    AlterReplicaLogDirsRequest, AlterReplicaLogDirsRequestV2Deserializer>
{
public:
  AlterReplicaLogDirsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribableLogDirTopic {

  
  
  const std::string topic_;
  const std::vector<int32_t> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribableLogDirTopic(std::string topic, std::vector<int32_t> partitions): topic_{topic}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  DescribableLogDirTopic(std::string topic, std::vector<int32_t> partitions, TaggedFields tagged_fields): topic_{topic}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topic_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(topic_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topic_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(topic_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribableLogDirTopic& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribableLogDirTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribableLogDirTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class DescribableLogDirTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribableLogDirTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class DescribableLogDirTopicV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribableLogDirTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribableLogDirTopicV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribableLogDirTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribableLogDirTopicV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribableLogDirTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeLogDirsRequest {

  
  
  const absl::optional<std::vector<DescribableLogDirTopic>> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeLogDirsRequest(absl::optional<std::vector<DescribableLogDirTopic>> topics): topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  DescribeLogDirsRequest(absl::optional<std::vector<DescribableLogDirTopic>> topics, TaggedFields tagged_fields): topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeLogDirsRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeLogDirsRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeLogDirsRequest
    ,
      NullableArrayDeserializer<DescribableLogDirTopicV0Deserializer>
    >{};

class DescribeLogDirsRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeLogDirsRequest
    ,
      NullableArrayDeserializer<DescribableLogDirTopicV1Deserializer>
    >{};

class DescribeLogDirsRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeLogDirsRequest
    ,
      NullableCompactArrayDeserializer<DescribableLogDirTopicV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeLogDirsRequest
    ,
      NullableCompactArrayDeserializer<DescribableLogDirTopicV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsRequestV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeLogDirsRequest
    ,
      NullableCompactArrayDeserializer<DescribableLogDirTopicV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_LOG_DIRS_REQUEST_API_KEY =
  35;

constexpr int16_t DESCRIBE_LOG_DIRS_REQUEST_MAX_VERSION =
  4;

class DescribeLogDirsRequestV0Parser:
  public RequestDataParser<
    DescribeLogDirsRequest, DescribeLogDirsRequestV0Deserializer>
{
public:
  DescribeLogDirsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeLogDirsRequestV1Parser:
  public RequestDataParser<
    DescribeLogDirsRequest, DescribeLogDirsRequestV1Deserializer>
{
public:
  DescribeLogDirsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeLogDirsRequestV2Parser:
  public RequestDataParser<
    DescribeLogDirsRequest, DescribeLogDirsRequestV2Deserializer>
{
public:
  DescribeLogDirsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeLogDirsRequestV3Parser:
  public RequestDataParser<
    DescribeLogDirsRequest, DescribeLogDirsRequestV3Deserializer>
{
public:
  DescribeLogDirsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeLogDirsRequestV4Parser:
  public RequestDataParser<
    DescribeLogDirsRequest, DescribeLogDirsRequestV4Deserializer>
{
public:
  DescribeLogDirsRequestV4Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct SaslAuthenticateRequest {

  
  
  const Bytes auth_bytes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  SaslAuthenticateRequest(Bytes auth_bytes): auth_bytes_{auth_bytes}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  SaslAuthenticateRequest(Bytes auth_bytes, TaggedFields tagged_fields): auth_bytes_{auth_bytes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(auth_bytes_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(auth_bytes_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(auth_bytes_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(auth_bytes_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const SaslAuthenticateRequest& rhs) const {
  
    return true
    && auth_bytes_ == rhs.auth_bytes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class SaslAuthenticateRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    SaslAuthenticateRequest
    ,
      BytesDeserializer
    >{};

class SaslAuthenticateRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    SaslAuthenticateRequest
    ,
      BytesDeserializer
    >{};

class SaslAuthenticateRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    SaslAuthenticateRequest
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t SASL_AUTHENTICATE_REQUEST_API_KEY =
  36;

constexpr int16_t SASL_AUTHENTICATE_REQUEST_MAX_VERSION =
  2;

class SaslAuthenticateRequestV0Parser:
  public RequestDataParser<
    SaslAuthenticateRequest, SaslAuthenticateRequestV0Deserializer>
{
public:
  SaslAuthenticateRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SaslAuthenticateRequestV1Parser:
  public RequestDataParser<
    SaslAuthenticateRequest, SaslAuthenticateRequestV1Deserializer>
{
public:
  SaslAuthenticateRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class SaslAuthenticateRequestV2Parser:
  public RequestDataParser<
    SaslAuthenticateRequest, SaslAuthenticateRequestV2Deserializer>
{
public:
  SaslAuthenticateRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct CreatePartitionsAssignment {

  
  
  const std::vector<int32_t> broker_ids_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreatePartitionsAssignment(std::vector<int32_t> broker_ids): broker_ids_{broker_ids}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreatePartitionsAssignment(std::vector<int32_t> broker_ids, TaggedFields tagged_fields): broker_ids_{broker_ids}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(broker_ids_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(broker_ids_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(broker_ids_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(broker_ids_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatePartitionsAssignment& rhs) const {
  
    return true
    && broker_ids_ == rhs.broker_ids_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatePartitionsAssignmentV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    CreatePartitionsAssignment
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class CreatePartitionsAssignmentV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    CreatePartitionsAssignment
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class CreatePartitionsAssignmentV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatePartitionsAssignment
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatePartitionsAssignmentV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatePartitionsAssignment
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct CreatePartitionsTopic {

  
  
  const std::string name_;
  const int32_t count_;
  const absl::optional<std::vector<CreatePartitionsAssignment>> assignments_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreatePartitionsTopic(std::string name, int32_t count, absl::optional<std::vector<CreatePartitionsAssignment>> assignments): name_{name}, count_{count}, assignments_{assignments}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreatePartitionsTopic(std::string name, int32_t count, absl::optional<std::vector<CreatePartitionsAssignment>> assignments, TaggedFields tagged_fields): name_{name}, count_{count}, assignments_{assignments}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(count_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(assignments_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(assignments_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(count_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(assignments_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(assignments_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatePartitionsTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && count_ == rhs.count_
    && assignments_ == rhs.assignments_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatePartitionsTopicV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsTopic
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableArrayDeserializer<CreatePartitionsAssignmentV0Deserializer>
    >{};

class CreatePartitionsTopicV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsTopic
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableArrayDeserializer<CreatePartitionsAssignmentV1Deserializer>
    >{};

class CreatePartitionsTopicV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreatePartitionsTopic
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      NullableCompactArrayDeserializer<CreatePartitionsAssignmentV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatePartitionsTopicV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreatePartitionsTopic
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      NullableCompactArrayDeserializer<CreatePartitionsAssignmentV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct CreatePartitionsRequest {

  
  
  const std::vector<CreatePartitionsTopic> topics_;
  const int32_t timeout_ms_;
  const bool validate_only_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreatePartitionsRequest(std::vector<CreatePartitionsTopic> topics, int32_t timeout_ms, bool validate_only): topics_{topics}, timeout_ms_{timeout_ms}, validate_only_{validate_only}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreatePartitionsRequest(std::vector<CreatePartitionsTopic> topics, int32_t timeout_ms, bool validate_only, TaggedFields tagged_fields): topics_{topics}, timeout_ms_{timeout_ms}, validate_only_{validate_only}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(validate_only_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(validate_only_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatePartitionsRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && timeout_ms_ == rhs.timeout_ms_
    && validate_only_ == rhs.validate_only_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatePartitionsRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsRequest
    ,
      ArrayDeserializer<CreatePartitionsTopicV0Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    >{};

class CreatePartitionsRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsRequest
    ,
      ArrayDeserializer<CreatePartitionsTopicV1Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    >{};

class CreatePartitionsRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreatePartitionsRequest
    ,
      CompactArrayDeserializer<CreatePartitionsTopicV2Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreatePartitionsRequestV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreatePartitionsRequest
    ,
      CompactArrayDeserializer<CreatePartitionsTopicV3Deserializer>
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t CREATE_PARTITIONS_REQUEST_API_KEY =
  37;

constexpr int16_t CREATE_PARTITIONS_REQUEST_MAX_VERSION =
  3;

class CreatePartitionsRequestV0Parser:
  public RequestDataParser<
    CreatePartitionsRequest, CreatePartitionsRequestV0Deserializer>
{
public:
  CreatePartitionsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreatePartitionsRequestV1Parser:
  public RequestDataParser<
    CreatePartitionsRequest, CreatePartitionsRequestV1Deserializer>
{
public:
  CreatePartitionsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreatePartitionsRequestV2Parser:
  public RequestDataParser<
    CreatePartitionsRequest, CreatePartitionsRequestV2Deserializer>
{
public:
  CreatePartitionsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreatePartitionsRequestV3Parser:
  public RequestDataParser<
    CreatePartitionsRequest, CreatePartitionsRequestV3Deserializer>
{
public:
  CreatePartitionsRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct CreatableRenewers {

  
  
  const std::string principal_type_;
  const std::string principal_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreatableRenewers(std::string principal_type, std::string principal_name): principal_type_{principal_type}, principal_name_{principal_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreatableRenewers(std::string principal_type, std::string principal_name, TaggedFields tagged_fields): principal_type_{principal_type}, principal_name_{principal_name}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(principal_type_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(principal_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(principal_name_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(principal_name_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(principal_type_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(principal_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(principal_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(principal_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatableRenewers& rhs) const {
  
    return true
    && principal_type_ == rhs.principal_type_
    && principal_name_ == rhs.principal_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatableRenewersV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableRenewers
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class CreatableRenewersV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableRenewers
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class CreatableRenewersV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableRenewers
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableRenewersV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableRenewers
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct CreateDelegationTokenRequest {

  
  
  const absl::optional<std::string> owner_principal_type_;
  const absl::optional<std::string> owner_principal_name_;
  const std::vector<CreatableRenewers> renewers_;
  const int64_t max_lifetime_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreateDelegationTokenRequest(std::vector<CreatableRenewers> renewers, int64_t max_lifetime_ms): owner_principal_type_{{""}}, owner_principal_name_{{""}}, renewers_{renewers}, max_lifetime_ms_{max_lifetime_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  CreateDelegationTokenRequest(std::vector<CreatableRenewers> renewers, int64_t max_lifetime_ms, TaggedFields tagged_fields): owner_principal_type_{{""}}, owner_principal_name_{{""}}, renewers_{renewers}, max_lifetime_ms_{max_lifetime_ms}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [3]
  CreateDelegationTokenRequest(absl::optional<std::string> owner_principal_type, absl::optional<std::string> owner_principal_name, std::vector<CreatableRenewers> renewers, int64_t max_lifetime_ms, TaggedFields tagged_fields): owner_principal_type_{owner_principal_type}, owner_principal_name_{owner_principal_name}, renewers_{renewers}, max_lifetime_ms_{max_lifetime_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(owner_principal_type_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(owner_principal_name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(renewers_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(renewers_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(max_lifetime_ms_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(owner_principal_type_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(owner_principal_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(renewers_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(renewers_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(max_lifetime_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreateDelegationTokenRequest& rhs) const {
  
    return true
    && owner_principal_type_ == rhs.owner_principal_type_
    && owner_principal_name_ == rhs.owner_principal_name_
    && renewers_ == rhs.renewers_
    && max_lifetime_ms_ == rhs.max_lifetime_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreateDelegationTokenRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateDelegationTokenRequest
    ,
      ArrayDeserializer<CreatableRenewersV0Deserializer>
    ,
      Int64Deserializer
    >{};

class CreateDelegationTokenRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateDelegationTokenRequest
    ,
      ArrayDeserializer<CreatableRenewersV1Deserializer>
    ,
      Int64Deserializer
    >{};

class CreateDelegationTokenRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateDelegationTokenRequest
    ,
      CompactArrayDeserializer<CreatableRenewersV2Deserializer>
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreateDelegationTokenRequestV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    CreateDelegationTokenRequest
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<CreatableRenewersV3Deserializer>
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t CREATE_DELEGATION_TOKEN_REQUEST_API_KEY =
  38;

constexpr int16_t CREATE_DELEGATION_TOKEN_REQUEST_MAX_VERSION =
  3;

class CreateDelegationTokenRequestV0Parser:
  public RequestDataParser<
    CreateDelegationTokenRequest, CreateDelegationTokenRequestV0Deserializer>
{
public:
  CreateDelegationTokenRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateDelegationTokenRequestV1Parser:
  public RequestDataParser<
    CreateDelegationTokenRequest, CreateDelegationTokenRequestV1Deserializer>
{
public:
  CreateDelegationTokenRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateDelegationTokenRequestV2Parser:
  public RequestDataParser<
    CreateDelegationTokenRequest, CreateDelegationTokenRequestV2Deserializer>
{
public:
  CreateDelegationTokenRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class CreateDelegationTokenRequestV3Parser:
  public RequestDataParser<
    CreateDelegationTokenRequest, CreateDelegationTokenRequestV3Deserializer>
{
public:
  CreateDelegationTokenRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct RenewDelegationTokenRequest {

  
  
  const Bytes hmac_;
  const int64_t renew_period_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  RenewDelegationTokenRequest(Bytes hmac, int64_t renew_period_ms): hmac_{hmac}, renew_period_ms_{renew_period_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  RenewDelegationTokenRequest(Bytes hmac, int64_t renew_period_ms, TaggedFields tagged_fields): hmac_{hmac}, renew_period_ms_{renew_period_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(hmac_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(hmac_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(renew_period_ms_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(hmac_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(hmac_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(renew_period_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RenewDelegationTokenRequest& rhs) const {
  
    return true
    && hmac_ == rhs.hmac_
    && renew_period_ms_ == rhs.renew_period_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RenewDelegationTokenRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    RenewDelegationTokenRequest
    ,
      BytesDeserializer
    ,
      Int64Deserializer
    >{};

class RenewDelegationTokenRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    RenewDelegationTokenRequest
    ,
      BytesDeserializer
    ,
      Int64Deserializer
    >{};

class RenewDelegationTokenRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    RenewDelegationTokenRequest
    ,
      CompactBytesDeserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t RENEW_DELEGATION_TOKEN_REQUEST_API_KEY =
  39;

constexpr int16_t RENEW_DELEGATION_TOKEN_REQUEST_MAX_VERSION =
  2;

class RenewDelegationTokenRequestV0Parser:
  public RequestDataParser<
    RenewDelegationTokenRequest, RenewDelegationTokenRequestV0Deserializer>
{
public:
  RenewDelegationTokenRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class RenewDelegationTokenRequestV1Parser:
  public RequestDataParser<
    RenewDelegationTokenRequest, RenewDelegationTokenRequestV1Deserializer>
{
public:
  RenewDelegationTokenRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class RenewDelegationTokenRequestV2Parser:
  public RequestDataParser<
    RenewDelegationTokenRequest, RenewDelegationTokenRequestV2Deserializer>
{
public:
  RenewDelegationTokenRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ExpireDelegationTokenRequest {

  
  
  const Bytes hmac_;
  const int64_t expiry_time_period_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  ExpireDelegationTokenRequest(Bytes hmac, int64_t expiry_time_period_ms): hmac_{hmac}, expiry_time_period_ms_{expiry_time_period_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  ExpireDelegationTokenRequest(Bytes hmac, int64_t expiry_time_period_ms, TaggedFields tagged_fields): hmac_{hmac}, expiry_time_period_ms_{expiry_time_period_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(hmac_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(hmac_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(expiry_time_period_ms_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(hmac_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(hmac_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(expiry_time_period_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ExpireDelegationTokenRequest& rhs) const {
  
    return true
    && hmac_ == rhs.hmac_
    && expiry_time_period_ms_ == rhs.expiry_time_period_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ExpireDelegationTokenRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ExpireDelegationTokenRequest
    ,
      BytesDeserializer
    ,
      Int64Deserializer
    >{};

class ExpireDelegationTokenRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ExpireDelegationTokenRequest
    ,
      BytesDeserializer
    ,
      Int64Deserializer
    >{};

class ExpireDelegationTokenRequestV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ExpireDelegationTokenRequest
    ,
      CompactBytesDeserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t EXPIRE_DELEGATION_TOKEN_REQUEST_API_KEY =
  40;

constexpr int16_t EXPIRE_DELEGATION_TOKEN_REQUEST_MAX_VERSION =
  2;

class ExpireDelegationTokenRequestV0Parser:
  public RequestDataParser<
    ExpireDelegationTokenRequest, ExpireDelegationTokenRequestV0Deserializer>
{
public:
  ExpireDelegationTokenRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ExpireDelegationTokenRequestV1Parser:
  public RequestDataParser<
    ExpireDelegationTokenRequest, ExpireDelegationTokenRequestV1Deserializer>
{
public:
  ExpireDelegationTokenRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ExpireDelegationTokenRequestV2Parser:
  public RequestDataParser<
    ExpireDelegationTokenRequest, ExpireDelegationTokenRequestV2Deserializer>
{
public:
  ExpireDelegationTokenRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribeDelegationTokenOwner {

  
  
  const std::string principal_type_;
  const std::string principal_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeDelegationTokenOwner(std::string principal_type, std::string principal_name): principal_type_{principal_type}, principal_name_{principal_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribeDelegationTokenOwner(std::string principal_type, std::string principal_name, TaggedFields tagged_fields): principal_type_{principal_type}, principal_name_{principal_name}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(principal_type_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(principal_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(principal_name_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(principal_name_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(principal_type_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(principal_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(principal_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(principal_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeDelegationTokenOwner& rhs) const {
  
    return true
    && principal_type_ == rhs.principal_type_
    && principal_name_ == rhs.principal_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeDelegationTokenOwnerV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeDelegationTokenOwner
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class DescribeDelegationTokenOwnerV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeDelegationTokenOwner
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class DescribeDelegationTokenOwnerV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeDelegationTokenOwner
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeDelegationTokenOwnerV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeDelegationTokenOwner
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeDelegationTokenRequest {

  
  
  const absl::optional<std::vector<DescribeDelegationTokenOwner>> owners_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeDelegationTokenRequest(absl::optional<std::vector<DescribeDelegationTokenOwner>> owners): owners_{owners}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribeDelegationTokenRequest(absl::optional<std::vector<DescribeDelegationTokenOwner>> owners, TaggedFields tagged_fields): owners_{owners}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(owners_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(owners_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(owners_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(owners_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeDelegationTokenRequest& rhs) const {
  
    return true
    && owners_ == rhs.owners_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeDelegationTokenRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeDelegationTokenRequest
    ,
      NullableArrayDeserializer<DescribeDelegationTokenOwnerV0Deserializer>
    >{};

class DescribeDelegationTokenRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeDelegationTokenRequest
    ,
      NullableArrayDeserializer<DescribeDelegationTokenOwnerV1Deserializer>
    >{};

class DescribeDelegationTokenRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeDelegationTokenRequest
    ,
      NullableCompactArrayDeserializer<DescribeDelegationTokenOwnerV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeDelegationTokenRequestV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeDelegationTokenRequest
    ,
      NullableCompactArrayDeserializer<DescribeDelegationTokenOwnerV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_DELEGATION_TOKEN_REQUEST_API_KEY =
  41;

constexpr int16_t DESCRIBE_DELEGATION_TOKEN_REQUEST_MAX_VERSION =
  3;

class DescribeDelegationTokenRequestV0Parser:
  public RequestDataParser<
    DescribeDelegationTokenRequest, DescribeDelegationTokenRequestV0Deserializer>
{
public:
  DescribeDelegationTokenRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeDelegationTokenRequestV1Parser:
  public RequestDataParser<
    DescribeDelegationTokenRequest, DescribeDelegationTokenRequestV1Deserializer>
{
public:
  DescribeDelegationTokenRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeDelegationTokenRequestV2Parser:
  public RequestDataParser<
    DescribeDelegationTokenRequest, DescribeDelegationTokenRequestV2Deserializer>
{
public:
  DescribeDelegationTokenRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeDelegationTokenRequestV3Parser:
  public RequestDataParser<
    DescribeDelegationTokenRequest, DescribeDelegationTokenRequestV3Deserializer>
{
public:
  DescribeDelegationTokenRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DeleteGroupsRequest {

  
  
  const std::vector<std::string> groups_names_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteGroupsRequest(std::vector<std::string> groups_names): groups_names_{groups_names}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteGroupsRequest(std::vector<std::string> groups_names, TaggedFields tagged_fields): groups_names_{groups_names}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(groups_names_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(groups_names_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(groups_names_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(groups_names_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteGroupsRequest& rhs) const {
  
    return true
    && groups_names_ == rhs.groups_names_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteGroupsRequestV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DeleteGroupsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    >{};

class DeleteGroupsRequestV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    DeleteGroupsRequest
    ,
      ArrayDeserializer<StringDeserializer>
    >{};

class DeleteGroupsRequestV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteGroupsRequest
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DELETE_GROUPS_REQUEST_API_KEY =
  42;

constexpr int16_t DELETE_GROUPS_REQUEST_MAX_VERSION =
  2;

class DeleteGroupsRequestV0Parser:
  public RequestDataParser<
    DeleteGroupsRequest, DeleteGroupsRequestV0Deserializer>
{
public:
  DeleteGroupsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteGroupsRequestV1Parser:
  public RequestDataParser<
    DeleteGroupsRequest, DeleteGroupsRequestV1Deserializer>
{
public:
  DeleteGroupsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DeleteGroupsRequestV2Parser:
  public RequestDataParser<
    DeleteGroupsRequest, DeleteGroupsRequestV2Deserializer>
{
public:
  DeleteGroupsRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct TopicPartitions {

  
  
  const std::string topic_;
  const std::vector<int32_t> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  TopicPartitions(std::string topic, std::vector<int32_t> partitions): topic_{topic}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  TopicPartitions(std::string topic, std::vector<int32_t> partitions, TaggedFields tagged_fields): topic_{topic}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topic_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(topic_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topic_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(topic_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TopicPartitions& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TopicPartitionsV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicPartitions
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class TopicPartitionsV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicPartitions
    ,
      StringDeserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class TopicPartitionsV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    TopicPartitions
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ElectLeadersRequest {

  
  
  const int8_t election_type_;
  const absl::optional<std::vector<TopicPartitions>> topic_partitions_;
  const int32_t timeout_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ElectLeadersRequest(absl::optional<std::vector<TopicPartitions>> topic_partitions, int32_t timeout_ms): election_type_{0}, topic_partitions_{topic_partitions}, timeout_ms_{timeout_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  ElectLeadersRequest(int8_t election_type, absl::optional<std::vector<TopicPartitions>> topic_partitions, int32_t timeout_ms): election_type_{election_type}, topic_partitions_{topic_partitions}, timeout_ms_{timeout_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  ElectLeadersRequest(int8_t election_type, absl::optional<std::vector<TopicPartitions>> topic_partitions, int32_t timeout_ms, TaggedFields tagged_fields): election_type_{election_type}, topic_partitions_{topic_partitions}, timeout_ms_{timeout_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.computeSize(election_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topic_partitions_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(topic_partitions_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.encode(election_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topic_partitions_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(topic_partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ElectLeadersRequest& rhs) const {
  
    return true
    && election_type_ == rhs.election_type_
    && topic_partitions_ == rhs.topic_partitions_
    && timeout_ms_ == rhs.timeout_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ElectLeadersRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ElectLeadersRequest
    ,
      NullableArrayDeserializer<TopicPartitionsV0Deserializer>
    ,
      Int32Deserializer
    >{};

class ElectLeadersRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ElectLeadersRequest
    ,
      Int8Deserializer
    ,
      NullableArrayDeserializer<TopicPartitionsV1Deserializer>
    ,
      Int32Deserializer
    >{};

class ElectLeadersRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    ElectLeadersRequest
    ,
      Int8Deserializer
    ,
      NullableCompactArrayDeserializer<TopicPartitionsV2Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ELECT_LEADERS_REQUEST_API_KEY =
  43;

constexpr int16_t ELECT_LEADERS_REQUEST_MAX_VERSION =
  2;

class ElectLeadersRequestV0Parser:
  public RequestDataParser<
    ElectLeadersRequest, ElectLeadersRequestV0Deserializer>
{
public:
  ElectLeadersRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ElectLeadersRequestV1Parser:
  public RequestDataParser<
    ElectLeadersRequest, ElectLeadersRequestV1Deserializer>
{
public:
  ElectLeadersRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class ElectLeadersRequestV2Parser:
  public RequestDataParser<
    ElectLeadersRequest, ElectLeadersRequestV2Deserializer>
{
public:
  ElectLeadersRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct IncrementalAlterConfigsRequestAlterableConfig {

  
  
  const std::string name_;
  const int8_t config_operation_;
  const absl::optional<std::string> value_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  IncrementalAlterConfigsRequestAlterableConfig(std::string name, int8_t config_operation, absl::optional<std::string> value): name_{name}, config_operation_{config_operation}, value_{value}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  IncrementalAlterConfigsRequestAlterableConfig(std::string name, int8_t config_operation, absl::optional<std::string> value, TaggedFields tagged_fields): name_{name}, config_operation_{config_operation}, value_{value}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(config_operation_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(value_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(value_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(config_operation_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(value_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(value_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const IncrementalAlterConfigsRequestAlterableConfig& rhs) const {
  
    return true
    && name_ == rhs.name_
    && config_operation_ == rhs.config_operation_
    && value_ == rhs.value_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class IncrementalAlterConfigsRequestAlterableConfigV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    IncrementalAlterConfigsRequestAlterableConfig
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    >{};

class IncrementalAlterConfigsRequestAlterableConfigV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    IncrementalAlterConfigsRequestAlterableConfig
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct IncrementalAlterConfigsRequestAlterConfigsResource {

  
  
  const int8_t resource_type_;
  const std::string resource_name_;
  const std::vector<IncrementalAlterConfigsRequestAlterableConfig> configs_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  IncrementalAlterConfigsRequestAlterConfigsResource(int8_t resource_type, std::string resource_name, std::vector<IncrementalAlterConfigsRequestAlterableConfig> configs): resource_type_{resource_type}, resource_name_{resource_name}, configs_{configs}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  IncrementalAlterConfigsRequestAlterConfigsResource(int8_t resource_type, std::string resource_name, std::vector<IncrementalAlterConfigsRequestAlterableConfig> configs, TaggedFields tagged_fields): resource_type_{resource_type}, resource_name_{resource_name}, configs_{configs}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resource_type_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(resource_name_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(resource_name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(configs_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(configs_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resource_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(resource_name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(resource_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(configs_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(configs_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const IncrementalAlterConfigsRequestAlterConfigsResource& rhs) const {
  
    return true
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && configs_ == rhs.configs_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class IncrementalAlterConfigsRequestAlterConfigsResourceV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    IncrementalAlterConfigsRequestAlterConfigsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<IncrementalAlterConfigsRequestAlterableConfigV0Deserializer>
    >{};

class IncrementalAlterConfigsRequestAlterConfigsResourceV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    IncrementalAlterConfigsRequestAlterConfigsResource
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<IncrementalAlterConfigsRequestAlterableConfigV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct IncrementalAlterConfigsRequest {

  
  
  const std::vector<IncrementalAlterConfigsRequestAlterConfigsResource> resources_;
  const bool validate_only_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  IncrementalAlterConfigsRequest(std::vector<IncrementalAlterConfigsRequestAlterConfigsResource> resources, bool validate_only): resources_{resources}, validate_only_{validate_only}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  IncrementalAlterConfigsRequest(std::vector<IncrementalAlterConfigsRequestAlterConfigsResource> resources, bool validate_only, TaggedFields tagged_fields): resources_{resources}, validate_only_{validate_only}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(resources_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(resources_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(validate_only_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(resources_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(resources_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(validate_only_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const IncrementalAlterConfigsRequest& rhs) const {
  
    return true
    && resources_ == rhs.resources_
    && validate_only_ == rhs.validate_only_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class IncrementalAlterConfigsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    IncrementalAlterConfigsRequest
    ,
      ArrayDeserializer<IncrementalAlterConfigsRequestAlterConfigsResourceV0Deserializer>
    ,
      BooleanDeserializer
    >{};

class IncrementalAlterConfigsRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    IncrementalAlterConfigsRequest
    ,
      CompactArrayDeserializer<IncrementalAlterConfigsRequestAlterConfigsResourceV1Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t INCREMENTAL_ALTER_CONFIGS_REQUEST_API_KEY =
  44;

constexpr int16_t INCREMENTAL_ALTER_CONFIGS_REQUEST_MAX_VERSION =
  1;

class IncrementalAlterConfigsRequestV0Parser:
  public RequestDataParser<
    IncrementalAlterConfigsRequest, IncrementalAlterConfigsRequestV0Deserializer>
{
public:
  IncrementalAlterConfigsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class IncrementalAlterConfigsRequestV1Parser:
  public RequestDataParser<
    IncrementalAlterConfigsRequest, IncrementalAlterConfigsRequestV1Deserializer>
{
public:
  IncrementalAlterConfigsRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ReassignablePartition {

  
  
  const int32_t partition_index_;
  const absl::optional<std::vector<int32_t>> replicas_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ReassignablePartition(int32_t partition_index, absl::optional<std::vector<int32_t>> replicas, TaggedFields tagged_fields): partition_index_{partition_index}, replicas_{replicas}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(replicas_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(replicas_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ReassignablePartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && replicas_ == rhs.replicas_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ReassignablePartitionV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ReassignablePartition
    ,
      Int32Deserializer
    ,
      NullableCompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ReassignableTopic {

  
  
  const std::string name_;
  const std::vector<ReassignablePartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ReassignableTopic(std::string name, std::vector<ReassignablePartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ReassignableTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ReassignableTopicV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ReassignableTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ReassignablePartitionV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterPartitionReassignmentsRequest {

  
  
  const int32_t timeout_ms_;
  const std::vector<ReassignableTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AlterPartitionReassignmentsRequest(int32_t timeout_ms, std::vector<ReassignableTopic> topics, TaggedFields tagged_fields): timeout_ms_{timeout_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterPartitionReassignmentsRequest& rhs) const {
  
    return true
    && timeout_ms_ == rhs.timeout_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterPartitionReassignmentsRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterPartitionReassignmentsRequest
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<ReassignableTopicV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ALTER_PARTITION_REASSIGNMENTS_REQUEST_API_KEY =
  45;

constexpr int16_t ALTER_PARTITION_REASSIGNMENTS_REQUEST_MAX_VERSION =
  0;

class AlterPartitionReassignmentsRequestV0Parser:
  public RequestDataParser<
    AlterPartitionReassignmentsRequest, AlterPartitionReassignmentsRequestV0Deserializer>
{
public:
  AlterPartitionReassignmentsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ListPartitionReassignmentsTopics {

  
  
  const std::string name_;
  const std::vector<int32_t> partition_indexes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListPartitionReassignmentsTopics(std::string name, std::vector<int32_t> partition_indexes, TaggedFields tagged_fields): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(partition_indexes_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(partition_indexes_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListPartitionReassignmentsTopics& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_indexes_ == rhs.partition_indexes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListPartitionReassignmentsTopicsV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListPartitionReassignmentsTopics
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ListPartitionReassignmentsRequest {

  
  
  const int32_t timeout_ms_;
  const absl::optional<std::vector<ListPartitionReassignmentsTopics>> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListPartitionReassignmentsRequest(int32_t timeout_ms, absl::optional<std::vector<ListPartitionReassignmentsTopics>> topics, TaggedFields tagged_fields): timeout_ms_{timeout_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListPartitionReassignmentsRequest& rhs) const {
  
    return true
    && timeout_ms_ == rhs.timeout_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListPartitionReassignmentsRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListPartitionReassignmentsRequest
    ,
      Int32Deserializer
    ,
      NullableCompactArrayDeserializer<ListPartitionReassignmentsTopicsV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t LIST_PARTITION_REASSIGNMENTS_REQUEST_API_KEY =
  46;

constexpr int16_t LIST_PARTITION_REASSIGNMENTS_REQUEST_MAX_VERSION =
  0;

class ListPartitionReassignmentsRequestV0Parser:
  public RequestDataParser<
    ListPartitionReassignmentsRequest, ListPartitionReassignmentsRequestV0Deserializer>
{
public:
  ListPartitionReassignmentsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct OffsetDeleteRequestPartition {

  
  
  const int32_t partition_index_;
  
  // constructor used in versions: [0]
  OffsetDeleteRequestPartition(int32_t partition_index): partition_index_{partition_index} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_index_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetDeleteRequestPartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_;
  };

};



class OffsetDeleteRequestPartitionV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetDeleteRequestPartition
    ,
      Int32Deserializer
    >{};


struct OffsetDeleteRequestTopic {

  
  
  const std::string name_;
  const std::vector<OffsetDeleteRequestPartition> partitions_;
  
  // constructor used in versions: [0]
  OffsetDeleteRequestTopic(std::string name, std::vector<OffsetDeleteRequestPartition> partitions): name_{name}, partitions_{partitions} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partitions_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partitions_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetDeleteRequestTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_;
  };

};



class OffsetDeleteRequestTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetDeleteRequestTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetDeleteRequestPartitionV0Deserializer>
    >{};


struct OffsetDeleteRequest {

  
  
  const std::string group_id_;
  const std::vector<OffsetDeleteRequestTopic> topics_;
  
  // constructor used in versions: [0]
  OffsetDeleteRequest(std::string group_id, std::vector<OffsetDeleteRequestTopic> topics): group_id_{group_id}, topics_{topics} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topics_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetDeleteRequest& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && topics_ == rhs.topics_;
  };

};



class OffsetDeleteRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetDeleteRequest
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetDeleteRequestTopicV0Deserializer>
    >{};



constexpr int16_t OFFSET_DELETE_REQUEST_API_KEY =
  47;

constexpr int16_t OFFSET_DELETE_REQUEST_MAX_VERSION =
  0;

class OffsetDeleteRequestV0Parser:
  public RequestDataParser<
    OffsetDeleteRequest, OffsetDeleteRequestV0Deserializer>
{
public:
  OffsetDeleteRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ComponentData {

  
  
  const std::string entity_type_;
  const int8_t match_type_;
  const absl::optional<std::string> match_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ComponentData(std::string entity_type, int8_t match_type, absl::optional<std::string> match): entity_type_{entity_type}, match_type_{match_type}, match_{match}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  ComponentData(std::string entity_type, int8_t match_type, absl::optional<std::string> match, TaggedFields tagged_fields): entity_type_{entity_type}, match_type_{match_type}, match_{match}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entity_type_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entity_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(match_type_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(match_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(match_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entity_type_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entity_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(match_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(match_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(match_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ComponentData& rhs) const {
  
    return true
    && entity_type_ == rhs.entity_type_
    && match_type_ == rhs.match_type_
    && match_ == rhs.match_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ComponentDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ComponentData
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    >{};

class ComponentDataV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    ComponentData
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeClientQuotasRequest {

  
  
  const std::vector<ComponentData> components_;
  const bool strict_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeClientQuotasRequest(std::vector<ComponentData> components, bool strict): components_{components}, strict_{strict}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DescribeClientQuotasRequest(std::vector<ComponentData> components, bool strict, TaggedFields tagged_fields): components_{components}, strict_{strict}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(components_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(components_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(strict_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(components_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(components_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(strict_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeClientQuotasRequest& rhs) const {
  
    return true
    && components_ == rhs.components_
    && strict_ == rhs.strict_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeClientQuotasRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeClientQuotasRequest
    ,
      ArrayDeserializer<ComponentDataV0Deserializer>
    ,
      BooleanDeserializer
    >{};

class DescribeClientQuotasRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeClientQuotasRequest
    ,
      CompactArrayDeserializer<ComponentDataV1Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_CLIENT_QUOTAS_REQUEST_API_KEY =
  48;

constexpr int16_t DESCRIBE_CLIENT_QUOTAS_REQUEST_MAX_VERSION =
  1;

class DescribeClientQuotasRequestV0Parser:
  public RequestDataParser<
    DescribeClientQuotasRequest, DescribeClientQuotasRequestV0Deserializer>
{
public:
  DescribeClientQuotasRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeClientQuotasRequestV1Parser:
  public RequestDataParser<
    DescribeClientQuotasRequest, DescribeClientQuotasRequestV1Deserializer>
{
public:
  DescribeClientQuotasRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct RequestEntityData {

  
  
  const std::string entity_type_;
  const absl::optional<std::string> entity_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  RequestEntityData(std::string entity_type, absl::optional<std::string> entity_name): entity_type_{entity_type}, entity_name_{entity_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  RequestEntityData(std::string entity_type, absl::optional<std::string> entity_name, TaggedFields tagged_fields): entity_type_{entity_type}, entity_name_{entity_name}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entity_type_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entity_type_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entity_name_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entity_name_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entity_type_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entity_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entity_name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entity_name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RequestEntityData& rhs) const {
  
    return true
    && entity_type_ == rhs.entity_type_
    && entity_name_ == rhs.entity_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RequestEntityDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    RequestEntityData
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class RequestEntityDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestEntityData
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OpData {

  
  
  const std::string key_;
  const double value_;
  const bool remove_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  OpData(std::string key, double value, bool remove): key_{key}, value_{value}, remove_{remove}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  OpData(std::string key, double value, bool remove, TaggedFields tagged_fields): key_{key}, value_{value}, remove_{remove}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(key_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(key_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(value_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(remove_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(key_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(key_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(value_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(remove_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OpData& rhs) const {
  
    return true
    && key_ == rhs.key_
    && value_ == rhs.value_
    && remove_ == rhs.remove_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OpDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    OpData
    ,
      StringDeserializer
    ,
      Float64Deserializer
    ,
      BooleanDeserializer
    >{};

class OpDataV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    OpData
    ,
      CompactStringDeserializer
    ,
      Float64Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct RequestEntryData {

  
  
  const std::vector<RequestEntityData> entity_;
  const std::vector<OpData> ops_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  RequestEntryData(std::vector<RequestEntityData> entity, std::vector<OpData> ops): entity_{entity}, ops_{ops}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  RequestEntryData(std::vector<RequestEntityData> entity, std::vector<OpData> ops, TaggedFields tagged_fields): entity_{entity}, ops_{ops}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entity_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entity_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(ops_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(ops_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entity_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entity_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(ops_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(ops_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RequestEntryData& rhs) const {
  
    return true
    && entity_ == rhs.entity_
    && ops_ == rhs.ops_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RequestEntryDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    RequestEntryData
    ,
      ArrayDeserializer<RequestEntityDataV0Deserializer>
    ,
      ArrayDeserializer<OpDataV0Deserializer>
    >{};

class RequestEntryDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestEntryData
    ,
      CompactArrayDeserializer<RequestEntityDataV1Deserializer>
    ,
      CompactArrayDeserializer<OpDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterClientQuotasRequest {

  
  
  const std::vector<RequestEntryData> entries_;
  const bool validate_only_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AlterClientQuotasRequest(std::vector<RequestEntryData> entries, bool validate_only): entries_{entries}, validate_only_{validate_only}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  AlterClientQuotasRequest(std::vector<RequestEntryData> entries, bool validate_only, TaggedFields tagged_fields): entries_{entries}, validate_only_{validate_only}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entries_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entries_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(validate_only_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entries_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entries_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(validate_only_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterClientQuotasRequest& rhs) const {
  
    return true
    && entries_ == rhs.entries_
    && validate_only_ == rhs.validate_only_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterClientQuotasRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterClientQuotasRequest
    ,
      ArrayDeserializer<RequestEntryDataV0Deserializer>
    ,
      BooleanDeserializer
    >{};

class AlterClientQuotasRequestV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterClientQuotasRequest
    ,
      CompactArrayDeserializer<RequestEntryDataV1Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ALTER_CLIENT_QUOTAS_REQUEST_API_KEY =
  49;

constexpr int16_t ALTER_CLIENT_QUOTAS_REQUEST_MAX_VERSION =
  1;

class AlterClientQuotasRequestV0Parser:
  public RequestDataParser<
    AlterClientQuotasRequest, AlterClientQuotasRequestV0Deserializer>
{
public:
  AlterClientQuotasRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterClientQuotasRequestV1Parser:
  public RequestDataParser<
    AlterClientQuotasRequest, AlterClientQuotasRequestV1Deserializer>
{
public:
  AlterClientQuotasRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct UserName {

  
  
  const std::string name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  UserName(std::string name, TaggedFields tagged_fields): name_{name}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UserName& rhs) const {
  
    return true
    && name_ == rhs.name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UserNameV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    UserName
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeUserScramCredentialsRequest {

  
  
  const absl::optional<std::vector<UserName>> users_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeUserScramCredentialsRequest(absl::optional<std::vector<UserName>> users, TaggedFields tagged_fields): users_{users}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(users_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(users_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeUserScramCredentialsRequest& rhs) const {
  
    return true
    && users_ == rhs.users_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeUserScramCredentialsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeUserScramCredentialsRequest
    ,
      NullableCompactArrayDeserializer<UserNameV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_USER_SCRAM_CREDENTIALS_REQUEST_API_KEY =
  50;

constexpr int16_t DESCRIBE_USER_SCRAM_CREDENTIALS_REQUEST_MAX_VERSION =
  0;

class DescribeUserScramCredentialsRequestV0Parser:
  public RequestDataParser<
    DescribeUserScramCredentialsRequest, DescribeUserScramCredentialsRequestV0Deserializer>
{
public:
  DescribeUserScramCredentialsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ScramCredentialDeletion {

  
  
  const std::string name_;
  const int8_t mechanism_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ScramCredentialDeletion(std::string name, int8_t mechanism, TaggedFields tagged_fields): name_{name}, mechanism_{mechanism}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(mechanism_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(mechanism_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ScramCredentialDeletion& rhs) const {
  
    return true
    && name_ == rhs.name_
    && mechanism_ == rhs.mechanism_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ScramCredentialDeletionV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ScramCredentialDeletion
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ScramCredentialUpsertion {

  
  
  const std::string name_;
  const int8_t mechanism_;
  const int32_t iterations_;
  const Bytes salt_;
  const Bytes salted_password_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ScramCredentialUpsertion(std::string name, int8_t mechanism, int32_t iterations, Bytes salt, Bytes salted_password, TaggedFields tagged_fields): name_{name}, mechanism_{mechanism}, iterations_{iterations}, salt_{salt}, salted_password_{salted_password}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(mechanism_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(iterations_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(salt_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(salted_password_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(mechanism_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(iterations_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(salt_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(salted_password_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ScramCredentialUpsertion& rhs) const {
  
    return true
    && name_ == rhs.name_
    && mechanism_ == rhs.mechanism_
    && iterations_ == rhs.iterations_
    && salt_ == rhs.salt_
    && salted_password_ == rhs.salted_password_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ScramCredentialUpsertionV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    ScramCredentialUpsertion
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      CompactBytesDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterUserScramCredentialsRequest {

  
  
  const std::vector<ScramCredentialDeletion> deletions_;
  const std::vector<ScramCredentialUpsertion> upsertions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AlterUserScramCredentialsRequest(std::vector<ScramCredentialDeletion> deletions, std::vector<ScramCredentialUpsertion> upsertions, TaggedFields tagged_fields): deletions_{deletions}, upsertions_{upsertions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(deletions_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(upsertions_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(deletions_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(upsertions_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterUserScramCredentialsRequest& rhs) const {
  
    return true
    && deletions_ == rhs.deletions_
    && upsertions_ == rhs.upsertions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterUserScramCredentialsRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterUserScramCredentialsRequest
    ,
      CompactArrayDeserializer<ScramCredentialDeletionV0Deserializer>
    ,
      CompactArrayDeserializer<ScramCredentialUpsertionV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ALTER_USER_SCRAM_CREDENTIALS_REQUEST_API_KEY =
  51;

constexpr int16_t ALTER_USER_SCRAM_CREDENTIALS_REQUEST_MAX_VERSION =
  0;

class AlterUserScramCredentialsRequestV0Parser:
  public RequestDataParser<
    AlterUserScramCredentialsRequest, AlterUserScramCredentialsRequestV0Deserializer>
{
public:
  AlterUserScramCredentialsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct VoteRequestRequestPartitionData {

  
  
  const int32_t partition_index_;
  const int32_t candidate_epoch_;
  const int32_t candidate_id_;
  const int32_t last_offset_epoch_;
  const int64_t last_offset_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  VoteRequestRequestPartitionData(int32_t partition_index, int32_t candidate_epoch, int32_t candidate_id, int32_t last_offset_epoch, int64_t last_offset, TaggedFields tagged_fields): partition_index_{partition_index}, candidate_epoch_{candidate_epoch}, candidate_id_{candidate_id}, last_offset_epoch_{last_offset_epoch}, last_offset_{last_offset}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(candidate_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(candidate_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(last_offset_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(last_offset_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(candidate_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(candidate_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(last_offset_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(last_offset_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const VoteRequestRequestPartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && candidate_epoch_ == rhs.candidate_epoch_
    && candidate_id_ == rhs.candidate_id_
    && last_offset_epoch_ == rhs.last_offset_epoch_
    && last_offset_ == rhs.last_offset_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class VoteRequestRequestPartitionDataV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    VoteRequestRequestPartitionData
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct VoteRequestRequestTopicData {

  
  
  const std::string topic_name_;
  const std::vector<VoteRequestRequestPartitionData> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  VoteRequestRequestTopicData(std::string topic_name, std::vector<VoteRequestRequestPartitionData> partitions, TaggedFields tagged_fields): topic_name_{topic_name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const VoteRequestRequestTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class VoteRequestRequestTopicDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    VoteRequestRequestTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<VoteRequestRequestPartitionDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct VoteRequest {

  
  
  const absl::optional<std::string> cluster_id_;
  const std::vector<VoteRequestRequestTopicData> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  VoteRequest(absl::optional<std::string> cluster_id, std::vector<VoteRequestRequestTopicData> topics, TaggedFields tagged_fields): cluster_id_{cluster_id}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(cluster_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(cluster_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const VoteRequest& rhs) const {
  
    return true
    && cluster_id_ == rhs.cluster_id_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class VoteRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    VoteRequest
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<VoteRequestRequestTopicDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t VOTE_REQUEST_API_KEY =
  52;

constexpr int16_t VOTE_REQUEST_MAX_VERSION =
  0;

class VoteRequestV0Parser:
  public RequestDataParser<
    VoteRequest, VoteRequestV0Deserializer>
{
public:
  VoteRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct BeginQuorumEpochRequestRequestPartitionData {

  
  
  const int32_t partition_index_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  
  // constructor used in versions: [0]
  BeginQuorumEpochRequestRequestPartitionData(int32_t partition_index, int32_t leader_id, int32_t leader_epoch): partition_index_{partition_index}, leader_id_{leader_id}, leader_epoch_{leader_epoch} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(leader_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(leader_epoch_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(leader_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(leader_epoch_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BeginQuorumEpochRequestRequestPartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_;
  };

};



class BeginQuorumEpochRequestRequestPartitionDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    BeginQuorumEpochRequestRequestPartitionData
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    >{};


struct BeginQuorumEpochRequestRequestTopicData {

  
  
  const std::string topic_name_;
  const std::vector<BeginQuorumEpochRequestRequestPartitionData> partitions_;
  
  // constructor used in versions: [0]
  BeginQuorumEpochRequestRequestTopicData(std::string topic_name, std::vector<BeginQuorumEpochRequestRequestPartitionData> partitions): topic_name_{topic_name}, partitions_{partitions} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partitions_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partitions_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BeginQuorumEpochRequestRequestTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_;
  };

};



class BeginQuorumEpochRequestRequestTopicDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    BeginQuorumEpochRequestRequestTopicData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<BeginQuorumEpochRequestRequestPartitionDataV0Deserializer>
    >{};


struct BeginQuorumEpochRequest {

  
  
  const absl::optional<std::string> cluster_id_;
  const std::vector<BeginQuorumEpochRequestRequestTopicData> topics_;
  
  // constructor used in versions: [0]
  BeginQuorumEpochRequest(absl::optional<std::string> cluster_id, std::vector<BeginQuorumEpochRequestRequestTopicData> topics): cluster_id_{cluster_id}, topics_{topics} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(cluster_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topics_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(cluster_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BeginQuorumEpochRequest& rhs) const {
  
    return true
    && cluster_id_ == rhs.cluster_id_
    && topics_ == rhs.topics_;
  };

};



class BeginQuorumEpochRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    BeginQuorumEpochRequest
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<BeginQuorumEpochRequestRequestTopicDataV0Deserializer>
    >{};



constexpr int16_t BEGIN_QUORUM_EPOCH_REQUEST_API_KEY =
  53;

constexpr int16_t BEGIN_QUORUM_EPOCH_REQUEST_MAX_VERSION =
  0;

class BeginQuorumEpochRequestV0Parser:
  public RequestDataParser<
    BeginQuorumEpochRequest, BeginQuorumEpochRequestV0Deserializer>
{
public:
  BeginQuorumEpochRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct EndQuorumEpochRequestRequestPartitionData {

  
  
  const int32_t partition_index_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  const std::vector<int32_t> preferred_successors_;
  
  // constructor used in versions: [0]
  EndQuorumEpochRequestRequestPartitionData(int32_t partition_index, int32_t leader_id, int32_t leader_epoch, std::vector<int32_t> preferred_successors): partition_index_{partition_index}, leader_id_{leader_id}, leader_epoch_{leader_epoch}, preferred_successors_{preferred_successors} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(leader_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(preferred_successors_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(leader_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(preferred_successors_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EndQuorumEpochRequestRequestPartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_
    && preferred_successors_ == rhs.preferred_successors_;
  };

};



class EndQuorumEpochRequestRequestPartitionDataV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    EndQuorumEpochRequestRequestPartitionData
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};


struct EndQuorumEpochRequestRequestTopicData {

  
  
  const std::string topic_name_;
  const std::vector<EndQuorumEpochRequestRequestPartitionData> partitions_;
  
  // constructor used in versions: [0]
  EndQuorumEpochRequestRequestTopicData(std::string topic_name, std::vector<EndQuorumEpochRequestRequestPartitionData> partitions): topic_name_{topic_name}, partitions_{partitions} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partitions_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partitions_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EndQuorumEpochRequestRequestTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_;
  };

};



class EndQuorumEpochRequestRequestTopicDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    EndQuorumEpochRequestRequestTopicData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<EndQuorumEpochRequestRequestPartitionDataV0Deserializer>
    >{};


struct EndQuorumEpochRequest {

  
  
  const absl::optional<std::string> cluster_id_;
  const std::vector<EndQuorumEpochRequestRequestTopicData> topics_;
  
  // constructor used in versions: [0]
  EndQuorumEpochRequest(absl::optional<std::string> cluster_id, std::vector<EndQuorumEpochRequestRequestTopicData> topics): cluster_id_{cluster_id}, topics_{topics} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(cluster_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topics_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(cluster_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EndQuorumEpochRequest& rhs) const {
  
    return true
    && cluster_id_ == rhs.cluster_id_
    && topics_ == rhs.topics_;
  };

};



class EndQuorumEpochRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    EndQuorumEpochRequest
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<EndQuorumEpochRequestRequestTopicDataV0Deserializer>
    >{};



constexpr int16_t END_QUORUM_EPOCH_REQUEST_API_KEY =
  54;

constexpr int16_t END_QUORUM_EPOCH_REQUEST_MAX_VERSION =
  0;

class EndQuorumEpochRequestV0Parser:
  public RequestDataParser<
    EndQuorumEpochRequest, EndQuorumEpochRequestV0Deserializer>
{
public:
  EndQuorumEpochRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribeQuorumRequestRequestPartitionData {

  
  
  const int32_t partition_index_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeQuorumRequestRequestPartitionData(int32_t partition_index, TaggedFields tagged_fields): partition_index_{partition_index}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeQuorumRequestRequestPartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeQuorumRequestRequestPartitionDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeQuorumRequestRequestPartitionData
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeQuorumRequestRequestPartitionDataV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeQuorumRequestRequestPartitionData
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeQuorumRequestRequestTopicData {

  
  
  const std::string topic_name_;
  const std::vector<DescribeQuorumRequestRequestPartitionData> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeQuorumRequestRequestTopicData(std::string topic_name, std::vector<DescribeQuorumRequestRequestPartitionData> partitions, TaggedFields tagged_fields): topic_name_{topic_name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeQuorumRequestRequestTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeQuorumRequestRequestTopicDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeQuorumRequestRequestTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeQuorumRequestRequestPartitionDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeQuorumRequestRequestTopicDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeQuorumRequestRequestTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeQuorumRequestRequestPartitionDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeQuorumRequest {

  
  
  const std::vector<DescribeQuorumRequestRequestTopicData> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeQuorumRequest(std::vector<DescribeQuorumRequestRequestTopicData> topics, TaggedFields tagged_fields): topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeQuorumRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeQuorumRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeQuorumRequest
    ,
      CompactArrayDeserializer<DescribeQuorumRequestRequestTopicDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeQuorumRequestV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeQuorumRequest
    ,
      CompactArrayDeserializer<DescribeQuorumRequestRequestTopicDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_QUORUM_REQUEST_API_KEY =
  55;

constexpr int16_t DESCRIBE_QUORUM_REQUEST_MAX_VERSION =
  1;

class DescribeQuorumRequestV0Parser:
  public RequestDataParser<
    DescribeQuorumRequest, DescribeQuorumRequestV0Deserializer>
{
public:
  DescribeQuorumRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class DescribeQuorumRequestV1Parser:
  public RequestDataParser<
    DescribeQuorumRequest, DescribeQuorumRequestV1Deserializer>
{
public:
  DescribeQuorumRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct BrokerState {

  
  
  const int32_t broker_id_;
  const int64_t broker_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [3]
  BrokerState(int32_t broker_id, int64_t broker_epoch, TaggedFields tagged_fields): broker_id_{broker_id}, broker_epoch_{broker_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BrokerState& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && broker_epoch_ == rhs.broker_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class BrokerStateV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    BrokerState
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct RequestPartitionData {

  
  
  const int32_t partition_index_;
  const int32_t leader_epoch_;
  const std::vector<int32_t> new_isr_;
  const std::vector<BrokerState> new_isr_with_epochs_;
  const int8_t leader_recovery_state_;
  const int32_t partition_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  RequestPartitionData(int32_t partition_index, int32_t leader_epoch, std::vector<int32_t> new_isr, int32_t partition_epoch, TaggedFields tagged_fields): partition_index_{partition_index}, leader_epoch_{leader_epoch}, new_isr_{new_isr}, new_isr_with_epochs_{std::vector<BrokerState>{}}, leader_recovery_state_{0}, partition_epoch_{partition_epoch}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [1, 2]
  RequestPartitionData(int32_t partition_index, int32_t leader_epoch, std::vector<int32_t> new_isr, int8_t leader_recovery_state, int32_t partition_epoch, TaggedFields tagged_fields): partition_index_{partition_index}, leader_epoch_{leader_epoch}, new_isr_{new_isr}, new_isr_with_epochs_{std::vector<BrokerState>{}}, leader_recovery_state_{leader_recovery_state}, partition_epoch_{partition_epoch}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [3]
  RequestPartitionData(int32_t partition_index, int32_t leader_epoch, std::vector<BrokerState> new_isr_with_epochs, int8_t leader_recovery_state, int32_t partition_epoch, TaggedFields tagged_fields): partition_index_{partition_index}, leader_epoch_{leader_epoch}, new_isr_{std::vector<int32_t>{}}, new_isr_with_epochs_{new_isr_with_epochs}, leader_recovery_state_{leader_recovery_state}, partition_epoch_{partition_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeCompactSize(new_isr_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(new_isr_with_epochs_);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(leader_recovery_state_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partition_epoch_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encodeCompact(new_isr_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(new_isr_with_epochs_, dst);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(leader_recovery_state_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(partition_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RequestPartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && leader_epoch_ == rhs.leader_epoch_
    && new_isr_ == rhs.new_isr_
    && new_isr_with_epochs_ == rhs.new_isr_with_epochs_
    && leader_recovery_state_ == rhs.leader_recovery_state_
    && partition_epoch_ == rhs.partition_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RequestPartitionDataV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    RequestPartitionData
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class RequestPartitionDataV1Deserializer:
  public CompositeDeserializerWith6Delegates<
    RequestPartitionData
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class RequestPartitionDataV2Deserializer:
  public CompositeDeserializerWith6Delegates<
    RequestPartitionData
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class RequestPartitionDataV3Deserializer:
  public CompositeDeserializerWith6Delegates<
    RequestPartitionData
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<BrokerStateV3Deserializer>
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct RequestTopicData {

  
  
  const std::string topic_name_;
  const Uuid topic_id_;
  const std::vector<RequestPartitionData> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  RequestTopicData(std::string topic_name, std::vector<RequestPartitionData> partitions, TaggedFields tagged_fields): topic_name_{topic_name}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [2, 3]
  RequestTopicData(Uuid topic_id, std::vector<RequestPartitionData> partitions, TaggedFields tagged_fields): topic_name_{""}, topic_id_{topic_id}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RequestTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && topic_id_ == rhs.topic_id_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RequestTopicDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<RequestPartitionDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class RequestTopicDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<RequestPartitionDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class RequestTopicDataV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestTopicData
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<RequestPartitionDataV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class RequestTopicDataV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestTopicData
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<RequestPartitionDataV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterPartitionRequest {

  
  
  const int32_t broker_id_;
  const int64_t broker_epoch_;
  const std::vector<RequestTopicData> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  AlterPartitionRequest(int32_t broker_id, int64_t broker_epoch, std::vector<RequestTopicData> topics, TaggedFields tagged_fields): broker_id_{broker_id}, broker_epoch_{broker_epoch}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterPartitionRequest& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && broker_epoch_ == rhs.broker_epoch_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterPartitionRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<RequestTopicDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AlterPartitionRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<RequestTopicDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AlterPartitionRequestV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<RequestTopicDataV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AlterPartitionRequestV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<RequestTopicDataV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ALTER_PARTITION_REQUEST_API_KEY =
  56;

constexpr int16_t ALTER_PARTITION_REQUEST_MAX_VERSION =
  3;

class AlterPartitionRequestV0Parser:
  public RequestDataParser<
    AlterPartitionRequest, AlterPartitionRequestV0Deserializer>
{
public:
  AlterPartitionRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterPartitionRequestV1Parser:
  public RequestDataParser<
    AlterPartitionRequest, AlterPartitionRequestV1Deserializer>
{
public:
  AlterPartitionRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterPartitionRequestV2Parser:
  public RequestDataParser<
    AlterPartitionRequest, AlterPartitionRequestV2Deserializer>
{
public:
  AlterPartitionRequestV2Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class AlterPartitionRequestV3Parser:
  public RequestDataParser<
    AlterPartitionRequest, AlterPartitionRequestV3Deserializer>
{
public:
  AlterPartitionRequestV3Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct FeatureUpdateKey {

  
  
  const std::string feature_;
  const int16_t max_version_level_;
  const bool allow_downgrade_;
  const int8_t upgrade_type_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  FeatureUpdateKey(std::string feature, int16_t max_version_level, bool allow_downgrade, TaggedFields tagged_fields): feature_{feature}, max_version_level_{max_version_level}, allow_downgrade_{allow_downgrade}, upgrade_type_{1}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [1]
  FeatureUpdateKey(std::string feature, int16_t max_version_level, int8_t upgrade_type, TaggedFields tagged_fields): feature_{feature}, max_version_level_{max_version_level}, allow_downgrade_{false}, upgrade_type_{upgrade_type}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(feature_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(max_version_level_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(allow_downgrade_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(upgrade_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(feature_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(max_version_level_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(allow_downgrade_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(upgrade_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FeatureUpdateKey& rhs) const {
  
    return true
    && feature_ == rhs.feature_
    && max_version_level_ == rhs.max_version_level_
    && allow_downgrade_ == rhs.allow_downgrade_
    && upgrade_type_ == rhs.upgrade_type_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FeatureUpdateKeyV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    FeatureUpdateKey
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FeatureUpdateKeyV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    FeatureUpdateKey
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct UpdateFeaturesRequest {

  
  
  const int32_t timeout_ms_;
  const std::vector<FeatureUpdateKey> feature_updates_;
  const bool validate_only_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  UpdateFeaturesRequest(int32_t timeout_ms, std::vector<FeatureUpdateKey> feature_updates, TaggedFields tagged_fields): timeout_ms_{timeout_ms}, feature_updates_{feature_updates}, validate_only_{false}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [1]
  UpdateFeaturesRequest(int32_t timeout_ms, std::vector<FeatureUpdateKey> feature_updates, bool validate_only, TaggedFields tagged_fields): timeout_ms_{timeout_ms}, feature_updates_{feature_updates}, validate_only_{validate_only}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(timeout_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(feature_updates_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(validate_only_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(timeout_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(feature_updates_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(validate_only_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateFeaturesRequest& rhs) const {
  
    return true
    && timeout_ms_ == rhs.timeout_ms_
    && feature_updates_ == rhs.feature_updates_
    && validate_only_ == rhs.validate_only_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateFeaturesRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    UpdateFeaturesRequest
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FeatureUpdateKeyV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateFeaturesRequestV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdateFeaturesRequest
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FeatureUpdateKeyV1Deserializer>
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t UPDATE_FEATURES_REQUEST_API_KEY =
  57;

constexpr int16_t UPDATE_FEATURES_REQUEST_MAX_VERSION =
  1;

class UpdateFeaturesRequestV0Parser:
  public RequestDataParser<
    UpdateFeaturesRequest, UpdateFeaturesRequestV0Deserializer>
{
public:
  UpdateFeaturesRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class UpdateFeaturesRequestV1Parser:
  public RequestDataParser<
    UpdateFeaturesRequest, UpdateFeaturesRequestV1Deserializer>
{
public:
  UpdateFeaturesRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct EnvelopeRequest {

  
  
  const Bytes request_data_;
  const absl::optional<Bytes> request_principal_;
  const Bytes client_host_address_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  EnvelopeRequest(Bytes request_data, absl::optional<Bytes> request_principal, Bytes client_host_address, TaggedFields tagged_fields): request_data_{request_data}, request_principal_{request_principal}, client_host_address_{client_host_address}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(request_data_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(request_principal_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(client_host_address_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(request_data_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(request_principal_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(client_host_address_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EnvelopeRequest& rhs) const {
  
    return true
    && request_data_ == rhs.request_data_
    && request_principal_ == rhs.request_principal_
    && client_host_address_ == rhs.client_host_address_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class EnvelopeRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    EnvelopeRequest
    ,
      CompactBytesDeserializer
    ,
      NullableCompactBytesDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ENVELOPE_REQUEST_API_KEY =
  58;

constexpr int16_t ENVELOPE_REQUEST_MAX_VERSION =
  0;

class EnvelopeRequestV0Parser:
  public RequestDataParser<
    EnvelopeRequest, EnvelopeRequestV0Deserializer>
{
public:
  EnvelopeRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct RequestSnapshotId {

  
  
  const int64_t end_offset_;
  const int32_t epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  RequestSnapshotId(int64_t end_offset, int32_t epoch, TaggedFields tagged_fields): end_offset_{end_offset}, epoch_{epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(end_offset_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(end_offset_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RequestSnapshotId& rhs) const {
  
    return true
    && end_offset_ == rhs.end_offset_
    && epoch_ == rhs.epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RequestSnapshotIdV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestSnapshotId
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct RequestPartitionSnapshot {

  
  
  const int32_t partition_;
  const int32_t current_leader_epoch_;
  const RequestSnapshotId snapshot_id_;
  const int64_t position_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  RequestPartitionSnapshot(int32_t partition, int32_t current_leader_epoch, RequestSnapshotId snapshot_id, int64_t position, TaggedFields tagged_fields): partition_{partition}, current_leader_epoch_{current_leader_epoch}, snapshot_id_{snapshot_id}, position_{position}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(current_leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(snapshot_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(position_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(partition_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(current_leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(snapshot_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(position_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RequestPartitionSnapshot& rhs) const {
  
    return true
    && partition_ == rhs.partition_
    && current_leader_epoch_ == rhs.current_leader_epoch_
    && snapshot_id_ == rhs.snapshot_id_
    && position_ == rhs.position_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RequestPartitionSnapshotV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    RequestPartitionSnapshot
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      RequestSnapshotIdV0Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct RequestTopicSnapshot {

  
  
  const std::string name_;
  const std::vector<RequestPartitionSnapshot> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  RequestTopicSnapshot(std::string name, std::vector<RequestPartitionSnapshot> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RequestTopicSnapshot& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RequestTopicSnapshotV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    RequestTopicSnapshot
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<RequestPartitionSnapshotV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct FetchSnapshotRequest {

  
  
  const int32_t replica_id_;
  const int32_t max_bytes_;
  const std::vector<RequestTopicSnapshot> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  FetchSnapshotRequest(int32_t replica_id, int32_t max_bytes, std::vector<RequestTopicSnapshot> topics, TaggedFields tagged_fields): replica_id_{replica_id}, max_bytes_{max_bytes}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(replica_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(max_bytes_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(replica_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(max_bytes_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FetchSnapshotRequest& rhs) const {
  
    return true
    && replica_id_ == rhs.replica_id_
    && max_bytes_ == rhs.max_bytes_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchSnapshotRequestV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchSnapshotRequest
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<RequestTopicSnapshotV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t FETCH_SNAPSHOT_REQUEST_API_KEY =
  59;

constexpr int16_t FETCH_SNAPSHOT_REQUEST_MAX_VERSION =
  0;

class FetchSnapshotRequestV0Parser:
  public RequestDataParser<
    FetchSnapshotRequest, FetchSnapshotRequestV0Deserializer>
{
public:
  FetchSnapshotRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribeClusterRequest {

  
  
  const bool include_cluster_authorized_operations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeClusterRequest(bool include_cluster_authorized_operations, TaggedFields tagged_fields): include_cluster_authorized_operations_{include_cluster_authorized_operations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(include_cluster_authorized_operations_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(include_cluster_authorized_operations_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeClusterRequest& rhs) const {
  
    return true
    && include_cluster_authorized_operations_ == rhs.include_cluster_authorized_operations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeClusterRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeClusterRequest
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_CLUSTER_REQUEST_API_KEY =
  60;

constexpr int16_t DESCRIBE_CLUSTER_REQUEST_MAX_VERSION =
  0;

class DescribeClusterRequestV0Parser:
  public RequestDataParser<
    DescribeClusterRequest, DescribeClusterRequestV0Deserializer>
{
public:
  DescribeClusterRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct TopicRequest {

  
  
  const std::string name_;
  const std::vector<int32_t> partition_indexes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  TopicRequest(std::string name, std::vector<int32_t> partition_indexes, TaggedFields tagged_fields): name_{name}, partition_indexes_{partition_indexes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(partition_indexes_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(partition_indexes_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TopicRequest& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_indexes_ == rhs.partition_indexes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TopicRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    TopicRequest
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeProducersRequest {

  
  
  const std::vector<TopicRequest> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeProducersRequest(std::vector<TopicRequest> topics, TaggedFields tagged_fields): topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeProducersRequest& rhs) const {
  
    return true
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeProducersRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeProducersRequest
    ,
      CompactArrayDeserializer<TopicRequestV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_PRODUCERS_REQUEST_API_KEY =
  61;

constexpr int16_t DESCRIBE_PRODUCERS_REQUEST_MAX_VERSION =
  0;

class DescribeProducersRequestV0Parser:
  public RequestDataParser<
    DescribeProducersRequest, DescribeProducersRequestV0Deserializer>
{
public:
  DescribeProducersRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct Listener {

  
  
  const std::string name_;
  const std::string host_;
  const uint16_t port_;
  const int16_t security_protocol_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  Listener(std::string name, std::string host, uint16_t port, int16_t security_protocol, TaggedFields tagged_fields): name_{name}, host_{host}, port_{port}, security_protocol_{security_protocol}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(host_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(port_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(security_protocol_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(host_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(port_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(security_protocol_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const Listener& rhs) const {
  
    return true
    && name_ == rhs.name_
    && host_ == rhs.host_
    && port_ == rhs.port_
    && security_protocol_ == rhs.security_protocol_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListenerV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    Listener
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      UInt16Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class ListenerV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    Listener
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      UInt16Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct Feature {

  
  
  const std::string name_;
  const int16_t min_supported_version_;
  const int16_t max_supported_version_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  Feature(std::string name, int16_t min_supported_version, int16_t max_supported_version, TaggedFields tagged_fields): name_{name}, min_supported_version_{min_supported_version}, max_supported_version_{max_supported_version}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(min_supported_version_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(max_supported_version_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(min_supported_version_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(max_supported_version_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const Feature& rhs) const {
  
    return true
    && name_ == rhs.name_
    && min_supported_version_ == rhs.min_supported_version_
    && max_supported_version_ == rhs.max_supported_version_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FeatureV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    Feature
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FeatureV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    Feature
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct BrokerRegistrationRequest {

  
  
  const int32_t broker_id_;
  const std::string cluster_id_;
  const Uuid incarnation_id_;
  const std::vector<Listener> listeners_;
  const std::vector<Feature> features_;
  const absl::optional<std::string> rack_;
  const bool is_migrating_zk_broker_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  BrokerRegistrationRequest(int32_t broker_id, std::string cluster_id, Uuid incarnation_id, std::vector<Listener> listeners, std::vector<Feature> features, absl::optional<std::string> rack, TaggedFields tagged_fields): broker_id_{broker_id}, cluster_id_{cluster_id}, incarnation_id_{incarnation_id}, listeners_{listeners}, features_{features}, rack_{rack}, is_migrating_zk_broker_{false}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [1]
  BrokerRegistrationRequest(int32_t broker_id, std::string cluster_id, Uuid incarnation_id, std::vector<Listener> listeners, std::vector<Feature> features, absl::optional<std::string> rack, bool is_migrating_zk_broker, TaggedFields tagged_fields): broker_id_{broker_id}, cluster_id_{cluster_id}, incarnation_id_{incarnation_id}, listeners_{listeners}, features_{features}, rack_{rack}, is_migrating_zk_broker_{is_migrating_zk_broker}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(cluster_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(incarnation_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(listeners_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(features_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(rack_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(is_migrating_zk_broker_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(cluster_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(incarnation_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(listeners_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(features_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(rack_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(is_migrating_zk_broker_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BrokerRegistrationRequest& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && cluster_id_ == rhs.cluster_id_
    && incarnation_id_ == rhs.incarnation_id_
    && listeners_ == rhs.listeners_
    && features_ == rhs.features_
    && rack_ == rhs.rack_
    && is_migrating_zk_broker_ == rhs.is_migrating_zk_broker_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class BrokerRegistrationRequestV0Deserializer:
  public CompositeDeserializerWith7Delegates<
    BrokerRegistrationRequest
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<ListenerV0Deserializer>
    ,
      CompactArrayDeserializer<FeatureV0Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class BrokerRegistrationRequestV1Deserializer:
  public CompositeDeserializerWith8Delegates<
    BrokerRegistrationRequest
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<ListenerV1Deserializer>
    ,
      CompactArrayDeserializer<FeatureV1Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t BROKER_REGISTRATION_REQUEST_API_KEY =
  62;

constexpr int16_t BROKER_REGISTRATION_REQUEST_MAX_VERSION =
  1;

class BrokerRegistrationRequestV0Parser:
  public RequestDataParser<
    BrokerRegistrationRequest, BrokerRegistrationRequestV0Deserializer>
{
public:
  BrokerRegistrationRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};

class BrokerRegistrationRequestV1Parser:
  public RequestDataParser<
    BrokerRegistrationRequest, BrokerRegistrationRequestV1Deserializer>
{
public:
  BrokerRegistrationRequestV1Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct BrokerHeartbeatRequest {

  
  
  const int32_t broker_id_;
  const int64_t broker_epoch_;
  const int64_t current_metadata_offset_;
  const bool want_fence_;
  const bool want_shut_down_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  BrokerHeartbeatRequest(int32_t broker_id, int64_t broker_epoch, int64_t current_metadata_offset, bool want_fence, bool want_shut_down, TaggedFields tagged_fields): broker_id_{broker_id}, broker_epoch_{broker_epoch}, current_metadata_offset_{current_metadata_offset}, want_fence_{want_fence}, want_shut_down_{want_shut_down}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(current_metadata_offset_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(want_fence_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(want_shut_down_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(current_metadata_offset_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(want_fence_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(want_shut_down_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BrokerHeartbeatRequest& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && broker_epoch_ == rhs.broker_epoch_
    && current_metadata_offset_ == rhs.current_metadata_offset_
    && want_fence_ == rhs.want_fence_
    && want_shut_down_ == rhs.want_shut_down_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class BrokerHeartbeatRequestV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    BrokerHeartbeatRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t BROKER_HEARTBEAT_REQUEST_API_KEY =
  63;

constexpr int16_t BROKER_HEARTBEAT_REQUEST_MAX_VERSION =
  0;

class BrokerHeartbeatRequestV0Parser:
  public RequestDataParser<
    BrokerHeartbeatRequest, BrokerHeartbeatRequestV0Deserializer>
{
public:
  BrokerHeartbeatRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct UnregisterBrokerRequest {

  
  
  const int32_t broker_id_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  UnregisterBrokerRequest(int32_t broker_id, TaggedFields tagged_fields): broker_id_{broker_id}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UnregisterBrokerRequest& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UnregisterBrokerRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    UnregisterBrokerRequest
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t UNREGISTER_BROKER_REQUEST_API_KEY =
  64;

constexpr int16_t UNREGISTER_BROKER_REQUEST_MAX_VERSION =
  0;

class UnregisterBrokerRequestV0Parser:
  public RequestDataParser<
    UnregisterBrokerRequest, UnregisterBrokerRequestV0Deserializer>
{
public:
  UnregisterBrokerRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct DescribeTransactionsRequest {

  
  
  const std::vector<std::string> transactional_ids_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeTransactionsRequest(std::vector<std::string> transactional_ids, TaggedFields tagged_fields): transactional_ids_{transactional_ids}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(transactional_ids_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(transactional_ids_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeTransactionsRequest& rhs) const {
  
    return true
    && transactional_ids_ == rhs.transactional_ids_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeTransactionsRequestV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeTransactionsRequest
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t DESCRIBE_TRANSACTIONS_REQUEST_API_KEY =
  65;

constexpr int16_t DESCRIBE_TRANSACTIONS_REQUEST_MAX_VERSION =
  0;

class DescribeTransactionsRequestV0Parser:
  public RequestDataParser<
    DescribeTransactionsRequest, DescribeTransactionsRequestV0Deserializer>
{
public:
  DescribeTransactionsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct ListTransactionsRequest {

  
  
  const std::vector<std::string> state_filters_;
  const std::vector<int64_t> producer_id_filters_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListTransactionsRequest(std::vector<std::string> state_filters, std::vector<int64_t> producer_id_filters, TaggedFields tagged_fields): state_filters_{state_filters}, producer_id_filters_{producer_id_filters}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(state_filters_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(producer_id_filters_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(state_filters_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(producer_id_filters_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListTransactionsRequest& rhs) const {
  
    return true
    && state_filters_ == rhs.state_filters_
    && producer_id_filters_ == rhs.producer_id_filters_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListTransactionsRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListTransactionsRequest
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      CompactArrayDeserializer<Int64Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t LIST_TRANSACTIONS_REQUEST_API_KEY =
  66;

constexpr int16_t LIST_TRANSACTIONS_REQUEST_MAX_VERSION =
  0;

class ListTransactionsRequestV0Parser:
  public RequestDataParser<
    ListTransactionsRequest, ListTransactionsRequestV0Deserializer>
{
public:
  ListTransactionsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};


struct AllocateProducerIdsRequest {

  
  
  const int32_t broker_id_;
  const int64_t broker_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AllocateProducerIdsRequest(int32_t broker_id, int64_t broker_epoch, TaggedFields tagged_fields): broker_id_{broker_id}, broker_epoch_{broker_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(broker_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(tagged_fields_);
    }
    

    return written;
  }

  uint32_t computeCompactSize(const EncodingContext& encoder) const {
    return computeSize(encoder);
  }

  
  uint32_t encode(Buffer::Instance& dst, EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(broker_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AllocateProducerIdsRequest& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && broker_epoch_ == rhs.broker_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AllocateProducerIdsRequestV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    AllocateProducerIdsRequest
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



constexpr int16_t ALLOCATE_PRODUCER_IDS_REQUEST_API_KEY =
  67;

constexpr int16_t ALLOCATE_PRODUCER_IDS_REQUEST_MAX_VERSION =
  0;

class AllocateProducerIdsRequestV0Parser:
  public RequestDataParser<
    AllocateProducerIdsRequest, AllocateProducerIdsRequestV0Deserializer>
{
public:
  AllocateProducerIdsRequestV0Parser(RequestContextSharedPtr ctx) :
    RequestDataParser{ctx} {};
};



}}}}