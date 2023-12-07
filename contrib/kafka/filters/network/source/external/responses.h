
#pragma once
#include "contrib/kafka/filters/network/source/kafka_response.h"
#include "contrib/kafka/filters/network/source/kafka_response_parser.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace Kafka {


struct BatchIndexAndErrorMessage {

  
  
  const int32_t batch_index_;
  const absl::optional<std::string> batch_index_error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [8]
  BatchIndexAndErrorMessage(int32_t batch_index, absl::optional<std::string> batch_index_error_message): batch_index_{batch_index}, batch_index_error_message_{batch_index_error_message}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  BatchIndexAndErrorMessage(int32_t batch_index, absl::optional<std::string> batch_index_error_message, TaggedFields tagged_fields): batch_index_{batch_index}, batch_index_error_message_{batch_index_error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 10) {
      written += encoder.computeSize(batch_index_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(batch_index_error_message_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(batch_index_error_message_);
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

    
    if (api_version >= 8 && api_version < 10) {
      written += encoder.encode(batch_index_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(batch_index_error_message_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(batch_index_error_message_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BatchIndexAndErrorMessage& rhs) const {
  
    return true
    && batch_index_ == rhs.batch_index_
    && batch_index_error_message_ == rhs.batch_index_error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class BatchIndexAndErrorMessageV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    BatchIndexAndErrorMessage
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class BatchIndexAndErrorMessageV9Deserializer:
  public CompositeDeserializerWith3Delegates<
    BatchIndexAndErrorMessage
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct PartitionProduceResponse {

  
  
  const int32_t index_;
  const int16_t error_code_;
  const int64_t base_offset_;
  const int64_t log_append_time_ms_;
  const int64_t log_start_offset_;
  const std::vector<BatchIndexAndErrorMessage> record_errors_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  PartitionProduceResponse(int32_t index, int16_t error_code, int64_t base_offset): index_{index}, error_code_{error_code}, base_offset_{base_offset}, log_append_time_ms_{-1}, log_start_offset_{-1}, record_errors_{std::vector<BatchIndexAndErrorMessage>{}}, error_message_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  PartitionProduceResponse(int32_t index, int16_t error_code, int64_t base_offset, int64_t log_append_time_ms): index_{index}, error_code_{error_code}, base_offset_{base_offset}, log_append_time_ms_{log_append_time_ms}, log_start_offset_{-1}, record_errors_{std::vector<BatchIndexAndErrorMessage>{}}, error_message_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7]
  PartitionProduceResponse(int32_t index, int16_t error_code, int64_t base_offset, int64_t log_append_time_ms, int64_t log_start_offset): index_{index}, error_code_{error_code}, base_offset_{base_offset}, log_append_time_ms_{log_append_time_ms}, log_start_offset_{log_start_offset}, record_errors_{std::vector<BatchIndexAndErrorMessage>{}}, error_message_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  PartitionProduceResponse(int32_t index, int16_t error_code, int64_t base_offset, int64_t log_append_time_ms, int64_t log_start_offset, std::vector<BatchIndexAndErrorMessage> record_errors, absl::optional<std::string> error_message): index_{index}, error_code_{error_code}, base_offset_{base_offset}, log_append_time_ms_{log_append_time_ms}, log_start_offset_{log_start_offset}, record_errors_{record_errors}, error_message_{error_message}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  PartitionProduceResponse(int32_t index, int16_t error_code, int64_t base_offset, int64_t log_append_time_ms, int64_t log_start_offset, std::vector<BatchIndexAndErrorMessage> record_errors, absl::optional<std::string> error_message, TaggedFields tagged_fields): index_{index}, error_code_{error_code}, base_offset_{base_offset}, log_append_time_ms_{log_append_time_ms}, log_start_offset_{log_start_offset}, record_errors_{record_errors}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(index_);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(base_offset_);
    }
    
    if (api_version >= 2 && api_version < 10) {
      written += encoder.computeSize(log_append_time_ms_);
    }
    
    if (api_version >= 5 && api_version < 10) {
      written += encoder.computeSize(log_start_offset_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(record_errors_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(record_errors_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(error_message_);
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
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(base_offset_, dst);
    }
    
    if (api_version >= 2 && api_version < 10) {
      written += encoder.encode(log_append_time_ms_, dst);
    }
    
    if (api_version >= 5 && api_version < 10) {
      written += encoder.encode(log_start_offset_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(record_errors_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(record_errors_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const PartitionProduceResponse& rhs) const {
  
    return true
    && index_ == rhs.index_
    && error_code_ == rhs.error_code_
    && base_offset_ == rhs.base_offset_
    && log_append_time_ms_ == rhs.log_append_time_ms_
    && log_start_offset_ == rhs.log_start_offset_
    && record_errors_ == rhs.record_errors_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class PartitionProduceResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV5Deserializer:
  public CompositeDeserializerWith5Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV6Deserializer:
  public CompositeDeserializerWith5Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV7Deserializer:
  public CompositeDeserializerWith5Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class PartitionProduceResponseV8Deserializer:
  public CompositeDeserializerWith7Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<BatchIndexAndErrorMessageV8Deserializer>
    ,
      NullableStringDeserializer
    >{};

class PartitionProduceResponseV9Deserializer:
  public CompositeDeserializerWith8Delegates<
    PartitionProduceResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<BatchIndexAndErrorMessageV9Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct TopicProduceResponse {

  
  
  const std::string name_;
  const std::vector<PartitionProduceResponse> partition_responses_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7, 8]
  TopicProduceResponse(std::string name, std::vector<PartitionProduceResponse> partition_responses): name_{name}, partition_responses_{partition_responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  TopicProduceResponse(std::string name, std::vector<PartitionProduceResponse> partition_responses, TaggedFields tagged_fields): name_{name}, partition_responses_{partition_responses}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(partition_responses_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(partition_responses_);
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
      written += encoder.encode(partition_responses_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(partition_responses_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TopicProduceResponse& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partition_responses_ == rhs.partition_responses_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TopicProduceResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV0Deserializer>
    >{};

class TopicProduceResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV1Deserializer>
    >{};

class TopicProduceResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV2Deserializer>
    >{};

class TopicProduceResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV3Deserializer>
    >{};

class TopicProduceResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV4Deserializer>
    >{};

class TopicProduceResponseV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV5Deserializer>
    >{};

class TopicProduceResponseV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV6Deserializer>
    >{};

class TopicProduceResponseV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV7Deserializer>
    >{};

class TopicProduceResponseV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    TopicProduceResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionProduceResponseV8Deserializer>
    >{};

class TopicProduceResponseV9Deserializer:
  public CompositeDeserializerWith3Delegates<
    TopicProduceResponse
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<PartitionProduceResponseV9Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ProduceResponse {

  
  
  const std::vector<TopicProduceResponse> responses_;
  const int32_t throttle_time_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ProduceResponse(std::vector<TopicProduceResponse> responses): responses_{responses}, throttle_time_ms_{0}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4, 5, 6, 7, 8]
  ProduceResponse(std::vector<TopicProduceResponse> responses, int32_t throttle_time_ms): responses_{responses}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  ProduceResponse(std::vector<TopicProduceResponse> responses, int32_t throttle_time_ms, TaggedFields tagged_fields): responses_{responses}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(responses_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeCompactSize(responses_);
    }
    
    if (api_version >= 1 && api_version < 10) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(responses_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(responses_, dst);
    }
    
    if (api_version >= 1 && api_version < 10) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ProduceResponse& rhs) const {
  
    return true
    && responses_ == rhs.responses_
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ProduceResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV0Deserializer>
    >{};

class ProduceResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV1Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV2Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV3Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV4Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV5Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV6Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV7Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    ProduceResponse
    ,
      ArrayDeserializer<TopicProduceResponseV8Deserializer>
    ,
      Int32Deserializer
    >{};

class ProduceResponseV9Deserializer:
  public CompositeDeserializerWith3Delegates<
    ProduceResponse
    ,
      CompactArrayDeserializer<TopicProduceResponseV9Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class ProduceResponseV0Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV0Deserializer>{
public:
  ProduceResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV1Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV1Deserializer>{
public:
  ProduceResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV2Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV2Deserializer>{
public:
  ProduceResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV3Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV3Deserializer>{
public:
  ProduceResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV4Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV4Deserializer>{
public:
  ProduceResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV5Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV5Deserializer>{
public:
  ProduceResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV6Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV6Deserializer>{
public:
  ProduceResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV7Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV7Deserializer>{
public:
  ProduceResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV8Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV8Deserializer>{
public:
  ProduceResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ProduceResponseV9Parser:
  public ResponseDataParser<
    ProduceResponse, ProduceResponseV9Deserializer>{
public:
  ProduceResponseV9Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AbortedTransaction {

  
  
  const int64_t producer_id_;
  const int64_t first_offset_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [4, 5, 6, 7, 8, 9, 10, 11]
  AbortedTransaction(int64_t producer_id, int64_t first_offset): producer_id_{producer_id}, first_offset_{first_offset}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12, 13, 14, 15]
  AbortedTransaction(int64_t producer_id, int64_t first_offset, TaggedFields tagged_fields): producer_id_{producer_id}, first_offset_{first_offset}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.computeSize(first_offset_);
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

    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.encode(first_offset_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AbortedTransaction& rhs) const {
  
    return true
    && producer_id_ == rhs.producer_id_
    && first_offset_ == rhs.first_offset_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AbortedTransactionV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV9Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV10Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV11Deserializer:
  public CompositeDeserializerWith2Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class AbortedTransactionV12Deserializer:
  public CompositeDeserializerWith3Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class AbortedTransactionV13Deserializer:
  public CompositeDeserializerWith3Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class AbortedTransactionV14Deserializer:
  public CompositeDeserializerWith3Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class AbortedTransactionV15Deserializer:
  public CompositeDeserializerWith3Delegates<
    AbortedTransaction
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct FetchResponseResponsePartitionData {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const int64_t high_watermark_;
  const int64_t last_stable_offset_;
  const int64_t log_start_offset_;
  const absl::optional<std::vector<AbortedTransaction>> aborted_transactions_;
  const int32_t preferred_read_replica_;
  const absl::optional<Bytes> records_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  FetchResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int64_t high_watermark, absl::optional<Bytes> records): partition_index_{partition_index}, error_code_{error_code}, high_watermark_{high_watermark}, last_stable_offset_{-1}, log_start_offset_{-1}, aborted_transactions_{{std::vector<AbortedTransaction>{}}}, preferred_read_replica_{-1}, records_{records}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  FetchResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int64_t high_watermark, int64_t last_stable_offset, absl::optional<std::vector<AbortedTransaction>> aborted_transactions, absl::optional<Bytes> records): partition_index_{partition_index}, error_code_{error_code}, high_watermark_{high_watermark}, last_stable_offset_{last_stable_offset}, log_start_offset_{-1}, aborted_transactions_{aborted_transactions}, preferred_read_replica_{-1}, records_{records}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7, 8, 9, 10]
  FetchResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int64_t high_watermark, int64_t last_stable_offset, int64_t log_start_offset, absl::optional<std::vector<AbortedTransaction>> aborted_transactions, absl::optional<Bytes> records): partition_index_{partition_index}, error_code_{error_code}, high_watermark_{high_watermark}, last_stable_offset_{last_stable_offset}, log_start_offset_{log_start_offset}, aborted_transactions_{aborted_transactions}, preferred_read_replica_{-1}, records_{records}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [11]
  FetchResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int64_t high_watermark, int64_t last_stable_offset, int64_t log_start_offset, absl::optional<std::vector<AbortedTransaction>> aborted_transactions, int32_t preferred_read_replica, absl::optional<Bytes> records): partition_index_{partition_index}, error_code_{error_code}, high_watermark_{high_watermark}, last_stable_offset_{last_stable_offset}, log_start_offset_{log_start_offset}, aborted_transactions_{aborted_transactions}, preferred_read_replica_{preferred_read_replica}, records_{records}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12, 13, 14, 15]
  FetchResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int64_t high_watermark, int64_t last_stable_offset, int64_t log_start_offset, absl::optional<std::vector<AbortedTransaction>> aborted_transactions, int32_t preferred_read_replica, absl::optional<Bytes> records, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, high_watermark_{high_watermark}, last_stable_offset_{last_stable_offset}, log_start_offset_{log_start_offset}, aborted_transactions_{aborted_transactions}, preferred_read_replica_{preferred_read_replica}, records_{records}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.computeSize(high_watermark_);
    }
    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.computeSize(last_stable_offset_);
    }
    
    if (api_version >= 5 && api_version < 16) {
      written += encoder.computeSize(log_start_offset_);
    }
    
    if (api_version >= 4 && api_version < 12) {
      written += encoder.computeSize(aborted_transactions_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(aborted_transactions_);
    }
    
    if (api_version >= 11 && api_version < 16) {
      written += encoder.computeSize(preferred_read_replica_);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.computeSize(records_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(records_);
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
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 16) {
      written += encoder.encode(high_watermark_, dst);
    }
    
    if (api_version >= 4 && api_version < 16) {
      written += encoder.encode(last_stable_offset_, dst);
    }
    
    if (api_version >= 5 && api_version < 16) {
      written += encoder.encode(log_start_offset_, dst);
    }
    
    if (api_version >= 4 && api_version < 12) {
      written += encoder.encode(aborted_transactions_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(aborted_transactions_, dst);
    }
    
    if (api_version >= 11 && api_version < 16) {
      written += encoder.encode(preferred_read_replica_, dst);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.encode(records_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(records_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FetchResponseResponsePartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && high_watermark_ == rhs.high_watermark_
    && last_stable_offset_ == rhs.last_stable_offset_
    && log_start_offset_ == rhs.log_start_offset_
    && aborted_transactions_ == rhs.aborted_transactions_
    && preferred_read_replica_ == rhs.preferred_read_replica_
    && records_ == rhs.records_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchResponseResponsePartitionDataV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV4Deserializer>
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV5Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV5Deserializer>
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV6Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV6Deserializer>
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV7Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV7Deserializer>
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV8Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV8Deserializer>
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV9Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV9Deserializer>
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV10Deserializer:
  public CompositeDeserializerWith7Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV10Deserializer>
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV11Deserializer:
  public CompositeDeserializerWith8Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableArrayDeserializer<AbortedTransactionV11Deserializer>
    ,
      Int32Deserializer
    ,
      NullableBytesDeserializer
    >{};

class FetchResponseResponsePartitionDataV12Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableCompactArrayDeserializer<AbortedTransactionV12Deserializer>
    ,
      Int32Deserializer
    ,
      NullableCompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchResponseResponsePartitionDataV13Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableCompactArrayDeserializer<AbortedTransactionV13Deserializer>
    ,
      Int32Deserializer
    ,
      NullableCompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchResponseResponsePartitionDataV14Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableCompactArrayDeserializer<AbortedTransactionV14Deserializer>
    ,
      Int32Deserializer
    ,
      NullableCompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FetchResponseResponsePartitionDataV15Deserializer:
  public CompositeDeserializerWith9Delegates<
    FetchResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      NullableCompactArrayDeserializer<AbortedTransactionV15Deserializer>
    ,
      Int32Deserializer
    ,
      NullableCompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct FetchableTopicResponse {

  
  
  const std::string topic_;
  const Uuid topic_id_;
  const std::vector<FetchResponseResponsePartitionData> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
  FetchableTopicResponse(std::string topic, std::vector<FetchResponseResponsePartitionData> partitions): topic_{topic}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12]
  FetchableTopicResponse(std::string topic, std::vector<FetchResponseResponsePartitionData> partitions, TaggedFields tagged_fields): topic_{topic}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [13, 14, 15]
  FetchableTopicResponse(Uuid topic_id, std::vector<FetchResponseResponsePartitionData> partitions, TaggedFields tagged_fields): topic_{""}, topic_id_{topic_id}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const FetchableTopicResponse& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && topic_id_ == rhs.topic_id_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchableTopicResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV0Deserializer>
    >{};

class FetchableTopicResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV1Deserializer>
    >{};

class FetchableTopicResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV2Deserializer>
    >{};

class FetchableTopicResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV3Deserializer>
    >{};

class FetchableTopicResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV4Deserializer>
    >{};

class FetchableTopicResponseV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV5Deserializer>
    >{};

class FetchableTopicResponseV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV6Deserializer>
    >{};

class FetchableTopicResponseV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV7Deserializer>
    >{};

class FetchableTopicResponseV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV8Deserializer>
    >{};

class FetchableTopicResponseV9Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV9Deserializer>
    >{};

class FetchableTopicResponseV10Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV10Deserializer>
    >{};

class FetchableTopicResponseV11Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchableTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<FetchResponseResponsePartitionDataV11Deserializer>
    >{};

class FetchableTopicResponseV12Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchableTopicResponse
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<FetchResponseResponsePartitionDataV12Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchableTopicResponseV13Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchableTopicResponse
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<FetchResponseResponsePartitionDataV13Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchableTopicResponseV14Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchableTopicResponse
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<FetchResponseResponsePartitionDataV14Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchableTopicResponseV15Deserializer:
  public CompositeDeserializerWith3Delegates<
    FetchableTopicResponse
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<FetchResponseResponsePartitionDataV15Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct FetchResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const int32_t session_id_;
  const std::vector<FetchableTopicResponse> responses_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  FetchResponse(std::vector<FetchableTopicResponse> responses): throttle_time_ms_{0}, error_code_{0}, session_id_{0}, responses_{responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4, 5, 6]
  FetchResponse(int32_t throttle_time_ms, std::vector<FetchableTopicResponse> responses): throttle_time_ms_{throttle_time_ms}, error_code_{0}, session_id_{0}, responses_{responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [7, 8, 9, 10, 11]
  FetchResponse(int32_t throttle_time_ms, int16_t error_code, int32_t session_id, std::vector<FetchableTopicResponse> responses): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, session_id_{session_id}, responses_{responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [12, 13, 14, 15]
  FetchResponse(int32_t throttle_time_ms, int16_t error_code, int32_t session_id, std::vector<FetchableTopicResponse> responses, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, session_id_{session_id}, responses_{responses}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 16) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.computeSize(session_id_);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.computeSize(responses_);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.computeCompactSize(responses_);
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

    
    if (api_version >= 1 && api_version < 16) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 7 && api_version < 16) {
      written += encoder.encode(session_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 12) {
      written += encoder.encode(responses_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(responses_, dst);
    }
    
    if (api_version >= 12 && api_version < 16) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FetchResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && session_id_ == rhs.session_id_
    && responses_ == rhs.responses_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    FetchResponse
    ,
      ArrayDeserializer<FetchableTopicResponseV0Deserializer>
    >{};

class FetchResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV1Deserializer>
    >{};

class FetchResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV2Deserializer>
    >{};

class FetchResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV3Deserializer>
    >{};

class FetchResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV4Deserializer>
    >{};

class FetchResponseV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV5Deserializer>
    >{};

class FetchResponseV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV6Deserializer>
    >{};

class FetchResponseV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV7Deserializer>
    >{};

class FetchResponseV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV8Deserializer>
    >{};

class FetchResponseV9Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV9Deserializer>
    >{};

class FetchResponseV10Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV10Deserializer>
    >{};

class FetchResponseV11Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<FetchableTopicResponseV11Deserializer>
    >{};

class FetchResponseV12Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchableTopicResponseV12Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchResponseV13Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchableTopicResponseV13Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchResponseV14Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchableTopicResponseV14Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class FetchResponseV15Deserializer:
  public CompositeDeserializerWith5Delegates<
    FetchResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<FetchableTopicResponseV15Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class FetchResponseV0Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV0Deserializer>{
public:
  FetchResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV1Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV1Deserializer>{
public:
  FetchResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV2Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV2Deserializer>{
public:
  FetchResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV3Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV3Deserializer>{
public:
  FetchResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV4Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV4Deserializer>{
public:
  FetchResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV5Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV5Deserializer>{
public:
  FetchResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV6Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV6Deserializer>{
public:
  FetchResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV7Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV7Deserializer>{
public:
  FetchResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV8Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV8Deserializer>{
public:
  FetchResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV9Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV9Deserializer>{
public:
  FetchResponseV9Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV10Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV10Deserializer>{
public:
  FetchResponseV10Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV11Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV11Deserializer>{
public:
  FetchResponseV11Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV12Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV12Deserializer>{
public:
  FetchResponseV12Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV13Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV13Deserializer>{
public:
  FetchResponseV13Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV14Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV14Deserializer>{
public:
  FetchResponseV14Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FetchResponseV15Parser:
  public ResponseDataParser<
    FetchResponse, FetchResponseV15Deserializer>{
public:
  FetchResponseV15Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ListOffsetsPartitionResponse {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const std::vector<int64_t> old_style_offsets_;
  const int64_t timestamp_;
  const int64_t offset_;
  const int32_t leader_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListOffsetsPartitionResponse(int32_t partition_index, int16_t error_code, std::vector<int64_t> old_style_offsets): partition_index_{partition_index}, error_code_{error_code}, old_style_offsets_{old_style_offsets}, timestamp_{-1}, offset_{-1}, leader_epoch_{-1}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3]
  ListOffsetsPartitionResponse(int32_t partition_index, int16_t error_code, int64_t timestamp, int64_t offset): partition_index_{partition_index}, error_code_{error_code}, old_style_offsets_{std::vector<int64_t>{}}, timestamp_{timestamp}, offset_{offset}, leader_epoch_{-1}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  ListOffsetsPartitionResponse(int32_t partition_index, int16_t error_code, int64_t timestamp, int64_t offset, int32_t leader_epoch): partition_index_{partition_index}, error_code_{error_code}, old_style_offsets_{std::vector<int64_t>{}}, timestamp_{timestamp}, offset_{offset}, leader_epoch_{leader_epoch}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  ListOffsetsPartitionResponse(int32_t partition_index, int16_t error_code, int64_t timestamp, int64_t offset, int32_t leader_epoch, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, old_style_offsets_{std::vector<int64_t>{}}, timestamp_{timestamp}, offset_{offset}, leader_epoch_{leader_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(old_style_offsets_);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.computeSize(timestamp_);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.computeSize(offset_);
    }
    
    if (api_version >= 4 && api_version < 9) {
      written += encoder.computeSize(leader_epoch_);
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
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(old_style_offsets_, dst);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.encode(timestamp_, dst);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.encode(offset_, dst);
    }
    
    if (api_version >= 4 && api_version < 9) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListOffsetsPartitionResponse& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && old_style_offsets_ == rhs.old_style_offsets_
    && timestamp_ == rhs.timestamp_
    && offset_ == rhs.offset_
    && leader_epoch_ == rhs.leader_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListOffsetsPartitionResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<Int64Deserializer>
    >{};

class ListOffsetsPartitionResponseV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionResponseV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    >{};

class ListOffsetsPartitionResponseV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class ListOffsetsPartitionResponseV5Deserializer:
  public CompositeDeserializerWith5Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class ListOffsetsPartitionResponseV6Deserializer:
  public CompositeDeserializerWith6Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsPartitionResponseV7Deserializer:
  public CompositeDeserializerWith6Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsPartitionResponseV8Deserializer:
  public CompositeDeserializerWith6Delegates<
    ListOffsetsPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ListOffsetsTopicResponse {

  
  
  const std::string name_;
  const std::vector<ListOffsetsPartitionResponse> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5]
  ListOffsetsTopicResponse(std::string name, std::vector<ListOffsetsPartitionResponse> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  ListOffsetsTopicResponse(std::string name, std::vector<ListOffsetsPartitionResponse> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const ListOffsetsTopicResponse& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListOffsetsTopicResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionResponseV0Deserializer>
    >{};

class ListOffsetsTopicResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionResponseV1Deserializer>
    >{};

class ListOffsetsTopicResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionResponseV2Deserializer>
    >{};

class ListOffsetsTopicResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionResponseV3Deserializer>
    >{};

class ListOffsetsTopicResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionResponseV4Deserializer>
    >{};

class ListOffsetsTopicResponseV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsTopicResponse
    ,
      StringDeserializer
    ,
      ArrayDeserializer<ListOffsetsPartitionResponseV5Deserializer>
    >{};

class ListOffsetsTopicResponseV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsTopicResponse
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ListOffsetsPartitionResponseV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsTopicResponseV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsTopicResponse
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ListOffsetsPartitionResponseV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsTopicResponseV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsTopicResponse
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ListOffsetsPartitionResponseV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ListOffsetsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<ListOffsetsTopicResponse> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  ListOffsetsResponse(std::vector<ListOffsetsTopicResponse> topics): throttle_time_ms_{0}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4, 5]
  ListOffsetsResponse(int32_t throttle_time_ms, std::vector<ListOffsetsTopicResponse> topics): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  ListOffsetsResponse(int32_t throttle_time_ms, std::vector<ListOffsetsTopicResponse> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 2 && api_version < 9) {
      written += encoder.computeSize(throttle_time_ms_);
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

    
    if (api_version >= 2 && api_version < 9) {
      written += encoder.encode(throttle_time_ms_, dst);
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

  
  bool operator==(const ListOffsetsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListOffsetsResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    ListOffsetsResponse
    ,
      ArrayDeserializer<ListOffsetsTopicResponseV0Deserializer>
    >{};

class ListOffsetsResponseV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    ListOffsetsResponse
    ,
      ArrayDeserializer<ListOffsetsTopicResponseV1Deserializer>
    >{};

class ListOffsetsResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicResponseV2Deserializer>
    >{};

class ListOffsetsResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicResponseV3Deserializer>
    >{};

class ListOffsetsResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicResponseV4Deserializer>
    >{};

class ListOffsetsResponseV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListOffsetsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ListOffsetsTopicResponseV5Deserializer>
    >{};

class ListOffsetsResponseV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<ListOffsetsTopicResponseV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsResponseV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<ListOffsetsTopicResponseV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListOffsetsResponseV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListOffsetsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<ListOffsetsTopicResponseV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class ListOffsetsResponseV0Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV0Deserializer>{
public:
  ListOffsetsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV1Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV1Deserializer>{
public:
  ListOffsetsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV2Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV2Deserializer>{
public:
  ListOffsetsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV3Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV3Deserializer>{
public:
  ListOffsetsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV4Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV4Deserializer>{
public:
  ListOffsetsResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV5Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV5Deserializer>{
public:
  ListOffsetsResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV6Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV6Deserializer>{
public:
  ListOffsetsResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV7Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV7Deserializer>{
public:
  ListOffsetsResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListOffsetsResponseV8Parser:
  public ResponseDataParser<
    ListOffsetsResponse, ListOffsetsResponseV8Deserializer>{
public:
  ListOffsetsResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct MetadataResponseBroker {

  
  
  const int32_t node_id_;
  const std::string host_;
  const int32_t port_;
  const absl::optional<std::string> rack_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  MetadataResponseBroker(int32_t node_id, std::string host, int32_t port): node_id_{node_id}, host_{host}, port_{port}, rack_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4, 5, 6, 7, 8]
  MetadataResponseBroker(int32_t node_id, std::string host, int32_t port, absl::optional<std::string> rack): node_id_{node_id}, host_{host}, port_{port}, rack_{rack}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9, 10, 11, 12]
  MetadataResponseBroker(int32_t node_id, std::string host, int32_t port, absl::optional<std::string> rack, TaggedFields tagged_fields): node_id_{node_id}, host_{host}, port_{port}, rack_{rack}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.computeSize(node_id_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(host_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(host_);
    }
    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.computeSize(port_);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.computeSize(rack_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(rack_);
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

    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.encode(node_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(host_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(host_, dst);
    }
    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.encode(port_, dst);
    }
    
    if (api_version >= 1 && api_version < 9) {
      written += encoder.encode(rack_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(rack_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MetadataResponseBroker& rhs) const {
  
    return true
    && node_id_ == rhs.node_id_
    && host_ == rhs.host_
    && port_ == rhs.port_
    && rack_ == rhs.rack_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MetadataResponseBrokerV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class MetadataResponseBrokerV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    >{};

class MetadataResponseBrokerV9Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseBrokerV10Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseBrokerV11Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseBrokerV12Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponseBroker
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct MetadataResponsePartition {

  
  
  const int16_t error_code_;
  const int32_t partition_index_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  const std::vector<int32_t> replica_nodes_;
  const std::vector<int32_t> isr_nodes_;
  const std::vector<int32_t> offline_replicas_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  MetadataResponsePartition(int16_t error_code, int32_t partition_index, int32_t leader_id, std::vector<int32_t> replica_nodes, std::vector<int32_t> isr_nodes): error_code_{error_code}, partition_index_{partition_index}, leader_id_{leader_id}, leader_epoch_{-1}, replica_nodes_{replica_nodes}, isr_nodes_{isr_nodes}, offline_replicas_{std::vector<int32_t>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6]
  MetadataResponsePartition(int16_t error_code, int32_t partition_index, int32_t leader_id, std::vector<int32_t> replica_nodes, std::vector<int32_t> isr_nodes, std::vector<int32_t> offline_replicas): error_code_{error_code}, partition_index_{partition_index}, leader_id_{leader_id}, leader_epoch_{-1}, replica_nodes_{replica_nodes}, isr_nodes_{isr_nodes}, offline_replicas_{offline_replicas}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [7, 8]
  MetadataResponsePartition(int16_t error_code, int32_t partition_index, int32_t leader_id, int32_t leader_epoch, std::vector<int32_t> replica_nodes, std::vector<int32_t> isr_nodes, std::vector<int32_t> offline_replicas): error_code_{error_code}, partition_index_{partition_index}, leader_id_{leader_id}, leader_epoch_{leader_epoch}, replica_nodes_{replica_nodes}, isr_nodes_{isr_nodes}, offline_replicas_{offline_replicas}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9, 10, 11, 12]
  MetadataResponsePartition(int16_t error_code, int32_t partition_index, int32_t leader_id, int32_t leader_epoch, std::vector<int32_t> replica_nodes, std::vector<int32_t> isr_nodes, std::vector<int32_t> offline_replicas, TaggedFields tagged_fields): error_code_{error_code}, partition_index_{partition_index}, leader_id_{leader_id}, leader_epoch_{leader_epoch}, replica_nodes_{replica_nodes}, isr_nodes_{isr_nodes}, offline_replicas_{offline_replicas}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.computeSize(leader_id_);
    }
    
    if (api_version >= 7 && api_version < 13) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(replica_nodes_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(replica_nodes_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(isr_nodes_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(isr_nodes_);
    }
    
    if (api_version >= 5 && api_version < 9) {
      written += encoder.computeSize(offline_replicas_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(offline_replicas_);
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

    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.encode(leader_id_, dst);
    }
    
    if (api_version >= 7 && api_version < 13) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(replica_nodes_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(replica_nodes_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(isr_nodes_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(isr_nodes_, dst);
    }
    
    if (api_version >= 5 && api_version < 9) {
      written += encoder.encode(offline_replicas_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(offline_replicas_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MetadataResponsePartition& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && partition_index_ == rhs.partition_index_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_
    && replica_nodes_ == rhs.replica_nodes_
    && isr_nodes_ == rhs.isr_nodes_
    && offline_replicas_ == rhs.offline_replicas_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MetadataResponsePartitionV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV5Deserializer:
  public CompositeDeserializerWith6Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV6Deserializer:
  public CompositeDeserializerWith6Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV7Deserializer:
  public CompositeDeserializerWith7Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV8Deserializer:
  public CompositeDeserializerWith7Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    ,
      ArrayDeserializer<Int32Deserializer>
    >{};

class MetadataResponsePartitionV9Deserializer:
  public CompositeDeserializerWith8Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponsePartitionV10Deserializer:
  public CompositeDeserializerWith8Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponsePartitionV11Deserializer:
  public CompositeDeserializerWith8Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponsePartitionV12Deserializer:
  public CompositeDeserializerWith8Delegates<
    MetadataResponsePartition
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct MetadataResponseTopic {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> name_;
  const Uuid topic_id_;
  const bool is_internal_;
  const std::vector<MetadataResponsePartition> partitions_;
  const int32_t topic_authorized_operations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  MetadataResponseTopic(int16_t error_code, std::string name, std::vector<MetadataResponsePartition> partitions): error_code_{error_code}, name_{absl::make_optional(name)}, topic_id_{Uuid{0, 0}}, is_internal_{false}, partitions_{partitions}, topic_authorized_operations_{INT32_MIN}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4, 5, 6, 7]
  MetadataResponseTopic(int16_t error_code, std::string name, bool is_internal, std::vector<MetadataResponsePartition> partitions): error_code_{error_code}, name_{absl::make_optional(name)}, topic_id_{Uuid{0, 0}}, is_internal_{is_internal}, partitions_{partitions}, topic_authorized_operations_{INT32_MIN}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  MetadataResponseTopic(int16_t error_code, std::string name, bool is_internal, std::vector<MetadataResponsePartition> partitions, int32_t topic_authorized_operations): error_code_{error_code}, name_{absl::make_optional(name)}, topic_id_{Uuid{0, 0}}, is_internal_{is_internal}, partitions_{partitions}, topic_authorized_operations_{topic_authorized_operations}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9]
  MetadataResponseTopic(int16_t error_code, std::string name, bool is_internal, std::vector<MetadataResponsePartition> partitions, int32_t topic_authorized_operations, TaggedFields tagged_fields): error_code_{error_code}, name_{absl::make_optional(name)}, topic_id_{Uuid{0, 0}}, is_internal_{is_internal}, partitions_{partitions}, topic_authorized_operations_{topic_authorized_operations}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [10, 11]
  MetadataResponseTopic(int16_t error_code, std::string name, Uuid topic_id, bool is_internal, std::vector<MetadataResponsePartition> partitions, int32_t topic_authorized_operations, TaggedFields tagged_fields): error_code_{error_code}, name_{absl::make_optional(name)}, topic_id_{topic_id}, is_internal_{is_internal}, partitions_{partitions}, topic_authorized_operations_{topic_authorized_operations}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [12]
  MetadataResponseTopic(int16_t error_code, absl::optional<std::string> name, Uuid topic_id, bool is_internal, std::vector<MetadataResponsePartition> partitions, int32_t topic_authorized_operations, TaggedFields tagged_fields): error_code_{error_code}, name_{name}, topic_id_{topic_id}, is_internal_{is_internal}, partitions_{partitions}, topic_authorized_operations_{topic_authorized_operations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 10 && api_version < 13) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 1 && api_version < 13) {
      written += encoder.computeSize(is_internal_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(partitions_);
    }
    
    if (api_version >= 8 && api_version < 13) {
      written += encoder.computeSize(topic_authorized_operations_);
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

    
    if (api_version >= 0 && api_version < 13) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 10 && api_version < 13) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 1 && api_version < 13) {
      written += encoder.encode(is_internal_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 8 && api_version < 13) {
      written += encoder.encode(topic_authorized_operations_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MetadataResponseTopic& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && name_ == rhs.name_
    && topic_id_ == rhs.topic_id_
    && is_internal_ == rhs.is_internal_
    && partitions_ == rhs.partitions_
    && topic_authorized_operations_ == rhs.topic_authorized_operations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MetadataResponseTopicV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV0Deserializer>
    >{};

class MetadataResponseTopicV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV1Deserializer>
    >{};

class MetadataResponseTopicV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV2Deserializer>
    >{};

class MetadataResponseTopicV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV3Deserializer>
    >{};

class MetadataResponseTopicV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV4Deserializer>
    >{};

class MetadataResponseTopicV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV5Deserializer>
    >{};

class MetadataResponseTopicV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV6Deserializer>
    >{};

class MetadataResponseTopicV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV7Deserializer>
    >{};

class MetadataResponseTopicV8Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<MetadataResponsePartitionV8Deserializer>
    ,
      Int32Deserializer
    >{};

class MetadataResponseTopicV9Deserializer:
  public CompositeDeserializerWith6Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<MetadataResponsePartitionV9Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseTopicV10Deserializer:
  public CompositeDeserializerWith7Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<MetadataResponsePartitionV10Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseTopicV11Deserializer:
  public CompositeDeserializerWith7Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<MetadataResponsePartitionV11Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseTopicV12Deserializer:
  public CompositeDeserializerWith7Delegates<
    MetadataResponseTopic
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      UuidDeserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<MetadataResponsePartitionV12Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct MetadataResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<MetadataResponseBroker> brokers_;
  const absl::optional<std::string> cluster_id_;
  const int32_t controller_id_;
  const std::vector<MetadataResponseTopic> topics_;
  const int32_t cluster_authorized_operations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  MetadataResponse(std::vector<MetadataResponseBroker> brokers, std::vector<MetadataResponseTopic> topics): throttle_time_ms_{0}, brokers_{brokers}, cluster_id_{absl::nullopt}, controller_id_{-1}, topics_{topics}, cluster_authorized_operations_{INT32_MIN}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  MetadataResponse(std::vector<MetadataResponseBroker> brokers, int32_t controller_id, std::vector<MetadataResponseTopic> topics): throttle_time_ms_{0}, brokers_{brokers}, cluster_id_{absl::nullopt}, controller_id_{controller_id}, topics_{topics}, cluster_authorized_operations_{INT32_MIN}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  MetadataResponse(std::vector<MetadataResponseBroker> brokers, absl::optional<std::string> cluster_id, int32_t controller_id, std::vector<MetadataResponseTopic> topics): throttle_time_ms_{0}, brokers_{brokers}, cluster_id_{cluster_id}, controller_id_{controller_id}, topics_{topics}, cluster_authorized_operations_{INT32_MIN}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4, 5, 6, 7]
  MetadataResponse(int32_t throttle_time_ms, std::vector<MetadataResponseBroker> brokers, absl::optional<std::string> cluster_id, int32_t controller_id, std::vector<MetadataResponseTopic> topics): throttle_time_ms_{throttle_time_ms}, brokers_{brokers}, cluster_id_{cluster_id}, controller_id_{controller_id}, topics_{topics}, cluster_authorized_operations_{INT32_MIN}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  MetadataResponse(int32_t throttle_time_ms, std::vector<MetadataResponseBroker> brokers, absl::optional<std::string> cluster_id, int32_t controller_id, std::vector<MetadataResponseTopic> topics, int32_t cluster_authorized_operations): throttle_time_ms_{throttle_time_ms}, brokers_{brokers}, cluster_id_{cluster_id}, controller_id_{controller_id}, topics_{topics}, cluster_authorized_operations_{cluster_authorized_operations}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [9, 10]
  MetadataResponse(int32_t throttle_time_ms, std::vector<MetadataResponseBroker> brokers, absl::optional<std::string> cluster_id, int32_t controller_id, std::vector<MetadataResponseTopic> topics, int32_t cluster_authorized_operations, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, brokers_{brokers}, cluster_id_{cluster_id}, controller_id_{controller_id}, topics_{topics}, cluster_authorized_operations_{cluster_authorized_operations}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [11, 12]
  MetadataResponse(int32_t throttle_time_ms, std::vector<MetadataResponseBroker> brokers, absl::optional<std::string> cluster_id, int32_t controller_id, std::vector<MetadataResponseTopic> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, brokers_{brokers}, cluster_id_{cluster_id}, controller_id_{controller_id}, topics_{topics}, cluster_authorized_operations_{INT32_MIN}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 13) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(brokers_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(brokers_);
    }
    
    if (api_version >= 2 && api_version < 9) {
      written += encoder.computeSize(cluster_id_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(cluster_id_);
    }
    
    if (api_version >= 1 && api_version < 13) {
      written += encoder.computeSize(controller_id_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 8 && api_version < 11) {
      written += encoder.computeSize(cluster_authorized_operations_);
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

    
    if (api_version >= 3 && api_version < 13) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(brokers_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(brokers_, dst);
    }
    
    if (api_version >= 2 && api_version < 9) {
      written += encoder.encode(cluster_id_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(cluster_id_, dst);
    }
    
    if (api_version >= 1 && api_version < 13) {
      written += encoder.encode(controller_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 8 && api_version < 11) {
      written += encoder.encode(cluster_authorized_operations_, dst);
    }
    
    if (api_version >= 9 && api_version < 13) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MetadataResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && brokers_ == rhs.brokers_
    && cluster_id_ == rhs.cluster_id_
    && controller_id_ == rhs.controller_id_
    && topics_ == rhs.topics_
    && cluster_authorized_operations_ == rhs.cluster_authorized_operations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MetadataResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    MetadataResponse
    ,
      ArrayDeserializer<MetadataResponseBrokerV0Deserializer>
    ,
      ArrayDeserializer<MetadataResponseTopicV0Deserializer>
    >{};

class MetadataResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    MetadataResponse
    ,
      ArrayDeserializer<MetadataResponseBrokerV1Deserializer>
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV1Deserializer>
    >{};

class MetadataResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    MetadataResponse
    ,
      ArrayDeserializer<MetadataResponseBrokerV2Deserializer>
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV2Deserializer>
    >{};

class MetadataResponseV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseBrokerV3Deserializer>
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV3Deserializer>
    >{};

class MetadataResponseV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseBrokerV4Deserializer>
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV4Deserializer>
    >{};

class MetadataResponseV5Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseBrokerV5Deserializer>
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV5Deserializer>
    >{};

class MetadataResponseV6Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseBrokerV6Deserializer>
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV6Deserializer>
    >{};

class MetadataResponseV7Deserializer:
  public CompositeDeserializerWith5Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseBrokerV7Deserializer>
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV7Deserializer>
    >{};

class MetadataResponseV8Deserializer:
  public CompositeDeserializerWith6Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseBrokerV8Deserializer>
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<MetadataResponseTopicV8Deserializer>
    ,
      Int32Deserializer
    >{};

class MetadataResponseV9Deserializer:
  public CompositeDeserializerWith7Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseBrokerV9Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseTopicV9Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseV10Deserializer:
  public CompositeDeserializerWith7Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseBrokerV10Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseTopicV10Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseV11Deserializer:
  public CompositeDeserializerWith6Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseBrokerV11Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseTopicV11Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class MetadataResponseV12Deserializer:
  public CompositeDeserializerWith6Delegates<
    MetadataResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseBrokerV12Deserializer>
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<MetadataResponseTopicV12Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class MetadataResponseV0Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV0Deserializer>{
public:
  MetadataResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV1Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV1Deserializer>{
public:
  MetadataResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV2Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV2Deserializer>{
public:
  MetadataResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV3Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV3Deserializer>{
public:
  MetadataResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV4Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV4Deserializer>{
public:
  MetadataResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV5Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV5Deserializer>{
public:
  MetadataResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV6Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV6Deserializer>{
public:
  MetadataResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV7Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV7Deserializer>{
public:
  MetadataResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV8Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV8Deserializer>{
public:
  MetadataResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV9Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV9Deserializer>{
public:
  MetadataResponseV9Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV10Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV10Deserializer>{
public:
  MetadataResponseV10Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV11Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV11Deserializer>{
public:
  MetadataResponseV11Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class MetadataResponseV12Parser:
  public ResponseDataParser<
    MetadataResponse, MetadataResponseV12Deserializer>{
public:
  MetadataResponseV12Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct LeaderAndIsrPartitionError {

  
  
  const std::string topic_name_;
  const int32_t partition_index_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  LeaderAndIsrPartitionError(std::string topic_name, int32_t partition_index, int16_t error_code): topic_name_{topic_name}, partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  LeaderAndIsrPartitionError(std::string topic_name, int32_t partition_index, int16_t error_code, TaggedFields tagged_fields): topic_name_{topic_name}, partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5, 6, 7]
  LeaderAndIsrPartitionError(int32_t partition_index, int16_t error_code, TaggedFields tagged_fields): topic_name_{""}, partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(error_code_);
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

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaderAndIsrPartitionError& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaderAndIsrPartitionErrorV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrPartitionError
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class LeaderAndIsrPartitionErrorV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrPartitionError
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class LeaderAndIsrPartitionErrorV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrPartitionError
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class LeaderAndIsrPartitionErrorV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrPartitionError
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class LeaderAndIsrPartitionErrorV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaderAndIsrPartitionError
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrPartitionErrorV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrPartitionError
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrPartitionErrorV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrPartitionError
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrPartitionErrorV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrPartitionError
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct LeaderAndIsrTopicError {

  
  
  const Uuid topic_id_;
  const std::vector<LeaderAndIsrPartitionError> partition_errors_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [5, 6, 7]
  LeaderAndIsrTopicError(Uuid topic_id, std::vector<LeaderAndIsrPartitionError> partition_errors, TaggedFields tagged_fields): topic_id_{topic_id}, partition_errors_{partition_errors}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(partition_errors_);
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

    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(partition_errors_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaderAndIsrTopicError& rhs) const {
  
    return true
    && topic_id_ == rhs.topic_id_
    && partition_errors_ == rhs.partition_errors_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaderAndIsrTopicErrorV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrTopicError
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionErrorV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrTopicErrorV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrTopicError
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionErrorV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrTopicErrorV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrTopicError
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionErrorV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct LeaderAndIsrResponse {

  
  
  const int16_t error_code_;
  const std::vector<LeaderAndIsrPartitionError> partition_errors_;
  const std::vector<LeaderAndIsrTopicError> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  LeaderAndIsrResponse(int16_t error_code, std::vector<LeaderAndIsrPartitionError> partition_errors): error_code_{error_code}, partition_errors_{partition_errors}, topics_{std::vector<LeaderAndIsrTopicError>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  LeaderAndIsrResponse(int16_t error_code, std::vector<LeaderAndIsrPartitionError> partition_errors, TaggedFields tagged_fields): error_code_{error_code}, partition_errors_{partition_errors}, topics_{std::vector<LeaderAndIsrTopicError>{}}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5, 6, 7]
  LeaderAndIsrResponse(int16_t error_code, std::vector<LeaderAndIsrTopicError> topics, TaggedFields tagged_fields): error_code_{error_code}, partition_errors_{std::vector<LeaderAndIsrPartitionError>{}}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partition_errors_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(partition_errors_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(topics_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(partition_errors_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(partition_errors_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 4 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const LeaderAndIsrResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && partition_errors_ == rhs.partition_errors_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaderAndIsrResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionErrorV0Deserializer>
    >{};

class LeaderAndIsrResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionErrorV1Deserializer>
    >{};

class LeaderAndIsrResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionErrorV2Deserializer>
    >{};

class LeaderAndIsrResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<LeaderAndIsrPartitionErrorV3Deserializer>
    >{};

class LeaderAndIsrResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrPartitionErrorV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrResponseV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrTopicErrorV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrResponseV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrTopicErrorV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaderAndIsrResponseV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaderAndIsrResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<LeaderAndIsrTopicErrorV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class LeaderAndIsrResponseV0Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV0Deserializer>{
public:
  LeaderAndIsrResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaderAndIsrResponseV1Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV1Deserializer>{
public:
  LeaderAndIsrResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaderAndIsrResponseV2Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV2Deserializer>{
public:
  LeaderAndIsrResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaderAndIsrResponseV3Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV3Deserializer>{
public:
  LeaderAndIsrResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaderAndIsrResponseV4Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV4Deserializer>{
public:
  LeaderAndIsrResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaderAndIsrResponseV5Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV5Deserializer>{
public:
  LeaderAndIsrResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaderAndIsrResponseV6Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV6Deserializer>{
public:
  LeaderAndIsrResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaderAndIsrResponseV7Parser:
  public ResponseDataParser<
    LeaderAndIsrResponse, LeaderAndIsrResponseV7Deserializer>{
public:
  LeaderAndIsrResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct StopReplicaPartitionError {

  
  
  const std::string topic_name_;
  const int32_t partition_index_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  StopReplicaPartitionError(std::string topic_name, int32_t partition_index, int16_t error_code): topic_name_{topic_name}, partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  StopReplicaPartitionError(std::string topic_name, int32_t partition_index, int16_t error_code, TaggedFields tagged_fields): topic_name_{topic_name}, partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const StopReplicaPartitionError& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class StopReplicaPartitionErrorV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaPartitionError
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class StopReplicaPartitionErrorV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaPartitionError
    ,
      StringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class StopReplicaPartitionErrorV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    StopReplicaPartitionError
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaPartitionErrorV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    StopReplicaPartitionError
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaPartitionErrorV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    StopReplicaPartitionError
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct StopReplicaResponse {

  
  
  const int16_t error_code_;
  const std::vector<StopReplicaPartitionError> partition_errors_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  StopReplicaResponse(int16_t error_code, std::vector<StopReplicaPartitionError> partition_errors): error_code_{error_code}, partition_errors_{partition_errors}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  StopReplicaResponse(int16_t error_code, std::vector<StopReplicaPartitionError> partition_errors, TaggedFields tagged_fields): error_code_{error_code}, partition_errors_{partition_errors}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partition_errors_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(partition_errors_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(partition_errors_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(partition_errors_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const StopReplicaResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && partition_errors_ == rhs.partition_errors_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class StopReplicaResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    StopReplicaResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<StopReplicaPartitionErrorV0Deserializer>
    >{};

class StopReplicaResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    StopReplicaResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<StopReplicaPartitionErrorV1Deserializer>
    >{};

class StopReplicaResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<StopReplicaPartitionErrorV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<StopReplicaPartitionErrorV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class StopReplicaResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    StopReplicaResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<StopReplicaPartitionErrorV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class StopReplicaResponseV0Parser:
  public ResponseDataParser<
    StopReplicaResponse, StopReplicaResponseV0Deserializer>{
public:
  StopReplicaResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class StopReplicaResponseV1Parser:
  public ResponseDataParser<
    StopReplicaResponse, StopReplicaResponseV1Deserializer>{
public:
  StopReplicaResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class StopReplicaResponseV2Parser:
  public ResponseDataParser<
    StopReplicaResponse, StopReplicaResponseV2Deserializer>{
public:
  StopReplicaResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class StopReplicaResponseV3Parser:
  public ResponseDataParser<
    StopReplicaResponse, StopReplicaResponseV3Deserializer>{
public:
  StopReplicaResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class StopReplicaResponseV4Parser:
  public ResponseDataParser<
    StopReplicaResponse, StopReplicaResponseV4Deserializer>{
public:
  StopReplicaResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct UpdateMetadataResponse {

  
  
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5]
  UpdateMetadataResponse(int16_t error_code): error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8]
  UpdateMetadataResponse(int16_t error_code, TaggedFields tagged_fields): error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateMetadataResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateMetadataResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    >{};

class UpdateMetadataResponseV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    >{};

class UpdateMetadataResponseV2Deserializer:
  public CompositeDeserializerWith1Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    >{};

class UpdateMetadataResponseV3Deserializer:
  public CompositeDeserializerWith1Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    >{};

class UpdateMetadataResponseV4Deserializer:
  public CompositeDeserializerWith1Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    >{};

class UpdateMetadataResponseV5Deserializer:
  public CompositeDeserializerWith1Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    >{};

class UpdateMetadataResponseV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataResponseV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateMetadataResponseV8Deserializer:
  public CompositeDeserializerWith2Delegates<
    UpdateMetadataResponse
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class UpdateMetadataResponseV0Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV0Deserializer>{
public:
  UpdateMetadataResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV1Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV1Deserializer>{
public:
  UpdateMetadataResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV2Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV2Deserializer>{
public:
  UpdateMetadataResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV3Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV3Deserializer>{
public:
  UpdateMetadataResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV4Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV4Deserializer>{
public:
  UpdateMetadataResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV5Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV5Deserializer>{
public:
  UpdateMetadataResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV6Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV6Deserializer>{
public:
  UpdateMetadataResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV7Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV7Deserializer>{
public:
  UpdateMetadataResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateMetadataResponseV8Parser:
  public ResponseDataParser<
    UpdateMetadataResponse, UpdateMetadataResponseV8Deserializer>{
public:
  UpdateMetadataResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct RemainingPartition {

  
  
  const std::string topic_name_;
  const int32_t partition_index_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  RemainingPartition(std::string topic_name, int32_t partition_index): topic_name_{topic_name}, partition_index_{partition_index}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  RemainingPartition(std::string topic_name, int32_t partition_index, TaggedFields tagged_fields): topic_name_{topic_name}, partition_index_{partition_index}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(topic_name_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partition_index_);
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
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(topic_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RemainingPartition& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partition_index_ == rhs.partition_index_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RemainingPartitionV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    RemainingPartition
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class RemainingPartitionV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    RemainingPartition
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class RemainingPartitionV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    RemainingPartition
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class RemainingPartitionV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    RemainingPartition
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ControlledShutdownResponse {

  
  
  const int16_t error_code_;
  const std::vector<RemainingPartition> remaining_partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  ControlledShutdownResponse(int16_t error_code, std::vector<RemainingPartition> remaining_partitions): error_code_{error_code}, remaining_partitions_{remaining_partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  ControlledShutdownResponse(int16_t error_code, std::vector<RemainingPartition> remaining_partitions, TaggedFields tagged_fields): error_code_{error_code}, remaining_partitions_{remaining_partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(remaining_partitions_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(remaining_partitions_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(remaining_partitions_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(remaining_partitions_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ControlledShutdownResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && remaining_partitions_ == rhs.remaining_partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ControlledShutdownResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ControlledShutdownResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<RemainingPartitionV0Deserializer>
    >{};

class ControlledShutdownResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ControlledShutdownResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<RemainingPartitionV1Deserializer>
    >{};

class ControlledShutdownResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ControlledShutdownResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<RemainingPartitionV2Deserializer>
    >{};

class ControlledShutdownResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    ControlledShutdownResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<RemainingPartitionV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class ControlledShutdownResponseV0Parser:
  public ResponseDataParser<
    ControlledShutdownResponse, ControlledShutdownResponseV0Deserializer>{
public:
  ControlledShutdownResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ControlledShutdownResponseV1Parser:
  public ResponseDataParser<
    ControlledShutdownResponse, ControlledShutdownResponseV1Deserializer>{
public:
  ControlledShutdownResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ControlledShutdownResponseV2Parser:
  public ResponseDataParser<
    ControlledShutdownResponse, ControlledShutdownResponseV2Deserializer>{
public:
  ControlledShutdownResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ControlledShutdownResponseV3Parser:
  public ResponseDataParser<
    ControlledShutdownResponse, ControlledShutdownResponseV3Deserializer>{
public:
  ControlledShutdownResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct OffsetCommitResponsePartition {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7]
  OffsetCommitResponsePartition(int32_t partition_index, int16_t error_code): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  OffsetCommitResponsePartition(int32_t partition_index, int16_t error_code, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 9) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetCommitResponsePartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetCommitResponsePartitionV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class OffsetCommitResponsePartitionV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetCommitResponseTopic {

  
  
  const std::string name_;
  const std::vector<OffsetCommitResponsePartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5, 6, 7]
  OffsetCommitResponseTopic(std::string name, std::vector<OffsetCommitResponsePartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  OffsetCommitResponseTopic(std::string name, std::vector<OffsetCommitResponsePartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const OffsetCommitResponseTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetCommitResponseTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV0Deserializer>
    >{};

class OffsetCommitResponseTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV1Deserializer>
    >{};

class OffsetCommitResponseTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV2Deserializer>
    >{};

class OffsetCommitResponseTopicV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV3Deserializer>
    >{};

class OffsetCommitResponseTopicV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV4Deserializer>
    >{};

class OffsetCommitResponseTopicV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV5Deserializer>
    >{};

class OffsetCommitResponseTopicV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV6Deserializer>
    >{};

class OffsetCommitResponseTopicV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetCommitResponsePartitionV7Deserializer>
    >{};

class OffsetCommitResponseTopicV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitResponseTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetCommitResponsePartitionV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetCommitResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<OffsetCommitResponseTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  OffsetCommitResponse(std::vector<OffsetCommitResponseTopic> topics): throttle_time_ms_{0}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4, 5, 6, 7]
  OffsetCommitResponse(int32_t throttle_time_ms, std::vector<OffsetCommitResponseTopic> topics): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [8]
  OffsetCommitResponse(int32_t throttle_time_ms, std::vector<OffsetCommitResponseTopic> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 9) {
      written += encoder.computeSize(throttle_time_ms_);
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

    
    if (api_version >= 3 && api_version < 9) {
      written += encoder.encode(throttle_time_ms_, dst);
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

  
  bool operator==(const OffsetCommitResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetCommitResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetCommitResponse
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV0Deserializer>
    >{};

class OffsetCommitResponseV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetCommitResponse
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV1Deserializer>
    >{};

class OffsetCommitResponseV2Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetCommitResponse
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV2Deserializer>
    >{};

class OffsetCommitResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV3Deserializer>
    >{};

class OffsetCommitResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV4Deserializer>
    >{};

class OffsetCommitResponseV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV5Deserializer>
    >{};

class OffsetCommitResponseV6Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV6Deserializer>
    >{};

class OffsetCommitResponseV7Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetCommitResponseTopicV7Deserializer>
    >{};

class OffsetCommitResponseV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetCommitResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<OffsetCommitResponseTopicV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class OffsetCommitResponseV0Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV0Deserializer>{
public:
  OffsetCommitResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV1Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV1Deserializer>{
public:
  OffsetCommitResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV2Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV2Deserializer>{
public:
  OffsetCommitResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV3Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV3Deserializer>{
public:
  OffsetCommitResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV4Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV4Deserializer>{
public:
  OffsetCommitResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV5Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV5Deserializer>{
public:
  OffsetCommitResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV6Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV6Deserializer>{
public:
  OffsetCommitResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV7Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV7Deserializer>{
public:
  OffsetCommitResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetCommitResponseV8Parser:
  public ResponseDataParser<
    OffsetCommitResponse, OffsetCommitResponseV8Deserializer>{
public:
  OffsetCommitResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct OffsetFetchResponsePartition {

  
  
  const int32_t partition_index_;
  const int64_t committed_offset_;
  const int32_t committed_leader_epoch_;
  const absl::optional<std::string> metadata_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  OffsetFetchResponsePartition(int32_t partition_index, int64_t committed_offset, absl::optional<std::string> metadata, int16_t error_code): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{-1}, metadata_{metadata}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  OffsetFetchResponsePartition(int32_t partition_index, int64_t committed_offset, int32_t committed_leader_epoch, absl::optional<std::string> metadata, int16_t error_code): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{committed_leader_epoch}, metadata_{metadata}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7]
  OffsetFetchResponsePartition(int32_t partition_index, int64_t committed_offset, int32_t committed_leader_epoch, absl::optional<std::string> metadata, int16_t error_code, TaggedFields tagged_fields): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{committed_leader_epoch}, metadata_{metadata}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(committed_offset_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(committed_leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(metadata_);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.computeCompactSize(metadata_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(error_code_);
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

    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(committed_offset_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(committed_leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(metadata_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encodeCompact(metadata_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchResponsePartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && committed_offset_ == rhs.committed_offset_
    && committed_leader_epoch_ == rhs.committed_leader_epoch_
    && metadata_ == rhs.metadata_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchResponsePartitionV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponsePartitionV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponsePartitionV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponsePartitionV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponsePartitionV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponsePartitionV5Deserializer:
  public CompositeDeserializerWith5Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponsePartitionV6Deserializer:
  public CompositeDeserializerWith6Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class OffsetFetchResponsePartitionV7Deserializer:
  public CompositeDeserializerWith6Delegates<
    OffsetFetchResponsePartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchResponseTopic {

  
  
  const std::string name_;
  const std::vector<OffsetFetchResponsePartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4, 5]
  OffsetFetchResponseTopic(std::string name, std::vector<OffsetFetchResponsePartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7]
  OffsetFetchResponseTopic(std::string name, std::vector<OffsetFetchResponsePartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 6 && api_version < 8) {
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
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
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

  
  bool operator==(const OffsetFetchResponseTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchResponseTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchResponsePartitionV0Deserializer>
    >{};

class OffsetFetchResponseTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchResponsePartitionV1Deserializer>
    >{};

class OffsetFetchResponseTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchResponsePartitionV2Deserializer>
    >{};

class OffsetFetchResponseTopicV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchResponsePartitionV3Deserializer>
    >{};

class OffsetFetchResponseTopicV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchResponsePartitionV4Deserializer>
    >{};

class OffsetFetchResponseTopicV5Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetFetchResponsePartitionV5Deserializer>
    >{};

class OffsetFetchResponseTopicV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchResponseTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetFetchResponsePartitionV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class OffsetFetchResponseTopicV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchResponseTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetFetchResponsePartitionV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchResponsePartitions {

  
  
  const int32_t partition_index_;
  const int64_t committed_offset_;
  const int32_t committed_leader_epoch_;
  const absl::optional<std::string> metadata_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [8]
  OffsetFetchResponsePartitions(int32_t partition_index, int64_t committed_offset, int32_t committed_leader_epoch, absl::optional<std::string> metadata, int16_t error_code, TaggedFields tagged_fields): partition_index_{partition_index}, committed_offset_{committed_offset}, committed_leader_epoch_{committed_leader_epoch}, metadata_{metadata}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(committed_offset_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(committed_leader_epoch_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(metadata_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(committed_offset_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(committed_leader_epoch_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(metadata_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchResponsePartitions& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && committed_offset_ == rhs.committed_offset_
    && committed_leader_epoch_ == rhs.committed_leader_epoch_
    && metadata_ == rhs.metadata_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchResponsePartitionsV8Deserializer:
  public CompositeDeserializerWith6Delegates<
    OffsetFetchResponsePartitions
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchResponseTopics {

  
  
  const std::string name_;
  const std::vector<OffsetFetchResponsePartitions> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [8]
  OffsetFetchResponseTopics(std::string name, std::vector<OffsetFetchResponsePartitions> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 8 && api_version < 9) {
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

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
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

  
  bool operator==(const OffsetFetchResponseTopics& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchResponseTopicsV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchResponseTopics
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetFetchResponsePartitionsV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchResponseGroup {

  
  
  const std::string group_id_;
  const std::vector<OffsetFetchResponseTopics> topics_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [8]
  OffsetFetchResponseGroup(std::string group_id, std::vector<OffsetFetchResponseTopics> topics, int16_t error_code, TaggedFields tagged_fields): group_id_{group_id}, topics_{topics}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeSize(error_code_);
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
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchResponseGroup& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && topics_ == rhs.topics_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchResponseGroupV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponseGroup
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OffsetFetchResponseTopicsV8Deserializer>
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetFetchResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<OffsetFetchResponseTopic> topics_;
  const int16_t error_code_;
  const std::vector<OffsetFetchResponseGroup> groups_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  OffsetFetchResponse(std::vector<OffsetFetchResponseTopic> topics): throttle_time_ms_{0}, topics_{topics}, error_code_{0}, groups_{std::vector<OffsetFetchResponseGroup>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  OffsetFetchResponse(std::vector<OffsetFetchResponseTopic> topics, int16_t error_code): throttle_time_ms_{0}, topics_{topics}, error_code_{error_code}, groups_{std::vector<OffsetFetchResponseGroup>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4, 5]
  OffsetFetchResponse(int32_t throttle_time_ms, std::vector<OffsetFetchResponseTopic> topics, int16_t error_code): throttle_time_ms_{throttle_time_ms}, topics_{topics}, error_code_{error_code}, groups_{std::vector<OffsetFetchResponseGroup>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7]
  OffsetFetchResponse(int32_t throttle_time_ms, std::vector<OffsetFetchResponseTopic> topics, int16_t error_code, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, error_code_{error_code}, groups_{std::vector<OffsetFetchResponseGroup>{}}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [8]
  OffsetFetchResponse(int32_t throttle_time_ms, std::vector<OffsetFetchResponseGroup> groups, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{std::vector<OffsetFetchResponseTopic>{}}, error_code_{0}, groups_{groups}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 3 && api_version < 9) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 8) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.computeCompactSize(groups_);
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

    
    if (api_version >= 3 && api_version < 9) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 6 && api_version < 8) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 8) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 8 && api_version < 9) {
      written += encoder.encodeCompact(groups_, dst);
    }
    
    if (api_version >= 6 && api_version < 9) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetFetchResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && error_code_ == rhs.error_code_
    && groups_ == rhs.groups_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetFetchResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetFetchResponse
    ,
      ArrayDeserializer<OffsetFetchResponseTopicV0Deserializer>
    >{};

class OffsetFetchResponseV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetFetchResponse
    ,
      ArrayDeserializer<OffsetFetchResponseTopicV1Deserializer>
    >{};

class OffsetFetchResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetFetchResponse
    ,
      ArrayDeserializer<OffsetFetchResponseTopicV2Deserializer>
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetFetchResponseTopicV3Deserializer>
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetFetchResponseTopicV4Deserializer>
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponseV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetFetchResponseTopicV5Deserializer>
    ,
      Int16Deserializer
    >{};

class OffsetFetchResponseV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<OffsetFetchResponseTopicV6Deserializer>
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class OffsetFetchResponseV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    OffsetFetchResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<OffsetFetchResponseTopicV7Deserializer>
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class OffsetFetchResponseV8Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetFetchResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<OffsetFetchResponseGroupV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class OffsetFetchResponseV0Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV0Deserializer>{
public:
  OffsetFetchResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV1Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV1Deserializer>{
public:
  OffsetFetchResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV2Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV2Deserializer>{
public:
  OffsetFetchResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV3Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV3Deserializer>{
public:
  OffsetFetchResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV4Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV4Deserializer>{
public:
  OffsetFetchResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV5Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV5Deserializer>{
public:
  OffsetFetchResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV6Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV6Deserializer>{
public:
  OffsetFetchResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV7Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV7Deserializer>{
public:
  OffsetFetchResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetFetchResponseV8Parser:
  public ResponseDataParser<
    OffsetFetchResponse, OffsetFetchResponseV8Deserializer>{
public:
  OffsetFetchResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct Coordinator {

  
  
  const std::string key_;
  const int32_t node_id_;
  const std::string host_;
  const int32_t port_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [4]
  Coordinator(std::string key, int32_t node_id, std::string host, int32_t port, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): key_{key}, node_id_{node_id}, host_{host}, port_{port}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(key_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(node_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(host_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(port_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encodeCompact(key_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(node_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(host_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(port_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const Coordinator& rhs) const {
  
    return true
    && key_ == rhs.key_
    && node_id_ == rhs.node_id_
    && host_ == rhs.host_
    && port_ == rhs.port_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CoordinatorV4Deserializer:
  public CompositeDeserializerWith7Delegates<
    Coordinator
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct FindCoordinatorResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const int32_t node_id_;
  const std::string host_;
  const int32_t port_;
  const std::vector<Coordinator> coordinators_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  FindCoordinatorResponse(int16_t error_code, int32_t node_id, std::string host, int32_t port): throttle_time_ms_{0}, error_code_{error_code}, error_message_{{""}}, node_id_{node_id}, host_{host}, port_{port}, coordinators_{std::vector<Coordinator>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2]
  FindCoordinatorResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, int32_t node_id, std::string host, int32_t port): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, node_id_{node_id}, host_{host}, port_{port}, coordinators_{std::vector<Coordinator>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  FindCoordinatorResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, int32_t node_id, std::string host, int32_t port, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, node_id_{node_id}, host_{host}, port_{port}, coordinators_{std::vector<Coordinator>{}}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  FindCoordinatorResponse(int32_t throttle_time_ms, std::vector<Coordinator> coordinators, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{0}, error_message_{{""}}, node_id_{0}, host_{""}, port_{0}, coordinators_{coordinators}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(node_id_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(host_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(host_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(port_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(coordinators_);
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

    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(node_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(host_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(host_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(port_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(coordinators_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const FindCoordinatorResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && node_id_ == rhs.node_id_
    && host_ == rhs.host_
    && port_ == rhs.port_
    && coordinators_ == rhs.coordinators_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FindCoordinatorResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    FindCoordinatorResponse
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class FindCoordinatorResponseV1Deserializer:
  public CompositeDeserializerWith6Delegates<
    FindCoordinatorResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class FindCoordinatorResponseV2Deserializer:
  public CompositeDeserializerWith6Delegates<
    FindCoordinatorResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      Int32Deserializer
    >{};

class FindCoordinatorResponseV3Deserializer:
  public CompositeDeserializerWith7Delegates<
    FindCoordinatorResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class FindCoordinatorResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    FindCoordinatorResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<CoordinatorV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class FindCoordinatorResponseV0Parser:
  public ResponseDataParser<
    FindCoordinatorResponse, FindCoordinatorResponseV0Deserializer>{
public:
  FindCoordinatorResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FindCoordinatorResponseV1Parser:
  public ResponseDataParser<
    FindCoordinatorResponse, FindCoordinatorResponseV1Deserializer>{
public:
  FindCoordinatorResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FindCoordinatorResponseV2Parser:
  public ResponseDataParser<
    FindCoordinatorResponse, FindCoordinatorResponseV2Deserializer>{
public:
  FindCoordinatorResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FindCoordinatorResponseV3Parser:
  public ResponseDataParser<
    FindCoordinatorResponse, FindCoordinatorResponseV3Deserializer>{
public:
  FindCoordinatorResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class FindCoordinatorResponseV4Parser:
  public ResponseDataParser<
    FindCoordinatorResponse, FindCoordinatorResponseV4Deserializer>{
public:
  FindCoordinatorResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct JoinGroupResponseMember {

  
  
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const Bytes metadata_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3, 4]
  JoinGroupResponseMember(std::string member_id, Bytes metadata): member_id_{member_id}, group_instance_id_{absl::nullopt}, metadata_{metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  JoinGroupResponseMember(std::string member_id, absl::optional<std::string> group_instance_id, Bytes metadata): member_id_{member_id}, group_instance_id_{group_instance_id}, metadata_{metadata}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6, 7, 8, 9]
  JoinGroupResponseMember(std::string member_id, absl::optional<std::string> group_instance_id, Bytes metadata, TaggedFields tagged_fields): member_id_{member_id}, group_instance_id_{group_instance_id}, metadata_{metadata}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
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

  
  bool operator==(const JoinGroupResponseMember& rhs) const {
  
    return true
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && metadata_ == rhs.metadata_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class JoinGroupResponseMemberV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupResponseMember
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupResponseMemberV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupResponseMember
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupResponseMemberV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupResponseMember
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupResponseMemberV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupResponseMember
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupResponseMemberV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    JoinGroupResponseMember
    ,
      StringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupResponseMemberV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    JoinGroupResponseMember
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      BytesDeserializer
    >{};

class JoinGroupResponseMemberV6Deserializer:
  public CompositeDeserializerWith4Delegates<
    JoinGroupResponseMember
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupResponseMemberV7Deserializer:
  public CompositeDeserializerWith4Delegates<
    JoinGroupResponseMember
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupResponseMemberV8Deserializer:
  public CompositeDeserializerWith4Delegates<
    JoinGroupResponseMember
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupResponseMemberV9Deserializer:
  public CompositeDeserializerWith4Delegates<
    JoinGroupResponseMember
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct JoinGroupResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const int32_t generation_id_;
  const absl::optional<std::string> protocol_type_;
  const absl::optional<std::string> protocol_name_;
  const std::string leader_;
  const bool skip_assignment_;
  const std::string member_id_;
  const std::vector<JoinGroupResponseMember> members_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  JoinGroupResponse(int16_t error_code, int32_t generation_id, std::string protocol_name, std::string leader, std::string member_id, std::vector<JoinGroupResponseMember> members): throttle_time_ms_{0}, error_code_{error_code}, generation_id_{generation_id}, protocol_type_{absl::nullopt}, protocol_name_{absl::make_optional(protocol_name)}, leader_{leader}, skip_assignment_{false}, member_id_{member_id}, members_{members}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4, 5]
  JoinGroupResponse(int32_t throttle_time_ms, int16_t error_code, int32_t generation_id, std::string protocol_name, std::string leader, std::string member_id, std::vector<JoinGroupResponseMember> members): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, generation_id_{generation_id}, protocol_type_{absl::nullopt}, protocol_name_{absl::make_optional(protocol_name)}, leader_{leader}, skip_assignment_{false}, member_id_{member_id}, members_{members}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [6]
  JoinGroupResponse(int32_t throttle_time_ms, int16_t error_code, int32_t generation_id, std::string protocol_name, std::string leader, std::string member_id, std::vector<JoinGroupResponseMember> members, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, generation_id_{generation_id}, protocol_type_{absl::nullopt}, protocol_name_{absl::make_optional(protocol_name)}, leader_{leader}, skip_assignment_{false}, member_id_{member_id}, members_{members}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [7, 8]
  JoinGroupResponse(int32_t throttle_time_ms, int16_t error_code, int32_t generation_id, absl::optional<std::string> protocol_type, absl::optional<std::string> protocol_name, std::string leader, std::string member_id, std::vector<JoinGroupResponseMember> members, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, generation_id_{generation_id}, protocol_type_{protocol_type}, protocol_name_{protocol_name}, leader_{leader}, skip_assignment_{false}, member_id_{member_id}, members_{members}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [9]
  JoinGroupResponse(int32_t throttle_time_ms, int16_t error_code, int32_t generation_id, absl::optional<std::string> protocol_type, absl::optional<std::string> protocol_name, std::string leader, bool skip_assignment, std::string member_id, std::vector<JoinGroupResponseMember> members, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, generation_id_{generation_id}, protocol_type_{protocol_type}, protocol_name_{protocol_name}, leader_{leader}, skip_assignment_{skip_assignment}, member_id_{member_id}, members_{members}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 2 && api_version < 10) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.computeSize(generation_id_);
    }
    
    if (api_version >= 7 && api_version < 10) {
      written += encoder.computeCompactSize(protocol_type_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(protocol_name_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(protocol_name_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(leader_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(leader_);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.computeSize(skip_assignment_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(members_);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.computeCompactSize(members_);
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

    
    if (api_version >= 2 && api_version < 10) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 10) {
      written += encoder.encode(generation_id_, dst);
    }
    
    if (api_version >= 7 && api_version < 10) {
      written += encoder.encodeCompact(protocol_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(protocol_name_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(protocol_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(leader_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(leader_, dst);
    }
    
    if (api_version >= 9 && api_version < 10) {
      written += encoder.encode(skip_assignment_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(members_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(members_, dst);
    }
    
    if (api_version >= 6 && api_version < 10) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const JoinGroupResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && generation_id_ == rhs.generation_id_
    && protocol_type_ == rhs.protocol_type_
    && protocol_name_ == rhs.protocol_name_
    && leader_ == rhs.leader_
    && skip_assignment_ == rhs.skip_assignment_
    && member_id_ == rhs.member_id_
    && members_ == rhs.members_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class JoinGroupResponseV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    JoinGroupResponse
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupResponseMemberV0Deserializer>
    >{};

class JoinGroupResponseV1Deserializer:
  public CompositeDeserializerWith6Delegates<
    JoinGroupResponse
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupResponseMemberV1Deserializer>
    >{};

class JoinGroupResponseV2Deserializer:
  public CompositeDeserializerWith7Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupResponseMemberV2Deserializer>
    >{};

class JoinGroupResponseV3Deserializer:
  public CompositeDeserializerWith7Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupResponseMemberV3Deserializer>
    >{};

class JoinGroupResponseV4Deserializer:
  public CompositeDeserializerWith7Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupResponseMemberV4Deserializer>
    >{};

class JoinGroupResponseV5Deserializer:
  public CompositeDeserializerWith7Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<JoinGroupResponseMemberV5Deserializer>
    >{};

class JoinGroupResponseV6Deserializer:
  public CompositeDeserializerWith8Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupResponseMemberV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupResponseV7Deserializer:
  public CompositeDeserializerWith9Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupResponseMemberV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupResponseV8Deserializer:
  public CompositeDeserializerWith9Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupResponseMemberV8Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class JoinGroupResponseV9Deserializer:
  public CompositeDeserializerWith10Delegates<
    JoinGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      BooleanDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<JoinGroupResponseMemberV9Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class JoinGroupResponseV0Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV0Deserializer>{
public:
  JoinGroupResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV1Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV1Deserializer>{
public:
  JoinGroupResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV2Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV2Deserializer>{
public:
  JoinGroupResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV3Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV3Deserializer>{
public:
  JoinGroupResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV4Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV4Deserializer>{
public:
  JoinGroupResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV5Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV5Deserializer>{
public:
  JoinGroupResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV6Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV6Deserializer>{
public:
  JoinGroupResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV7Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV7Deserializer>{
public:
  JoinGroupResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV8Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV8Deserializer>{
public:
  JoinGroupResponseV8Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class JoinGroupResponseV9Parser:
  public ResponseDataParser<
    JoinGroupResponse, JoinGroupResponseV9Deserializer>{
public:
  JoinGroupResponseV9Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct HeartbeatResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  HeartbeatResponse(int16_t error_code): throttle_time_ms_{0}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3]
  HeartbeatResponse(int32_t throttle_time_ms, int16_t error_code): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  HeartbeatResponse(int32_t throttle_time_ms, int16_t error_code, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
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

    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const HeartbeatResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class HeartbeatResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    HeartbeatResponse
    ,
      Int16Deserializer
    >{};

class HeartbeatResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    HeartbeatResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class HeartbeatResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    HeartbeatResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class HeartbeatResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    HeartbeatResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class HeartbeatResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    HeartbeatResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class HeartbeatResponseV0Parser:
  public ResponseDataParser<
    HeartbeatResponse, HeartbeatResponseV0Deserializer>{
public:
  HeartbeatResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class HeartbeatResponseV1Parser:
  public ResponseDataParser<
    HeartbeatResponse, HeartbeatResponseV1Deserializer>{
public:
  HeartbeatResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class HeartbeatResponseV2Parser:
  public ResponseDataParser<
    HeartbeatResponse, HeartbeatResponseV2Deserializer>{
public:
  HeartbeatResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class HeartbeatResponseV3Parser:
  public ResponseDataParser<
    HeartbeatResponse, HeartbeatResponseV3Deserializer>{
public:
  HeartbeatResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class HeartbeatResponseV4Parser:
  public ResponseDataParser<
    HeartbeatResponse, HeartbeatResponseV4Deserializer>{
public:
  HeartbeatResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct MemberResponse {

  
  
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [3]
  MemberResponse(std::string member_id, absl::optional<std::string> group_instance_id, int16_t error_code): member_id_{member_id}, group_instance_id_{group_instance_id}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  MemberResponse(std::string member_id, absl::optional<std::string> group_instance_id, int16_t error_code, TaggedFields tagged_fields): member_id_{member_id}, group_instance_id_{group_instance_id}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
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
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.computeSize(error_code_);
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
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 4 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const MemberResponse& rhs) const {
  
    return true
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class MemberResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    MemberResponse
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int16Deserializer
    >{};

class MemberResponseV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    MemberResponse
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class MemberResponseV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    MemberResponse
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct LeaveGroupResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<MemberResponse> members_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  LeaveGroupResponse(int16_t error_code): throttle_time_ms_{0}, error_code_{error_code}, members_{std::vector<MemberResponse>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2]
  LeaveGroupResponse(int32_t throttle_time_ms, int16_t error_code): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, members_{std::vector<MemberResponse>{}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  LeaveGroupResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<MemberResponse> members): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, members_{members}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5]
  LeaveGroupResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<MemberResponse> members, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, members_{members}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(error_code_);
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

    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(error_code_, dst);
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

  
  bool operator==(const LeaveGroupResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && members_ == rhs.members_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class LeaveGroupResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    LeaveGroupResponse
    ,
      Int16Deserializer
    >{};

class LeaveGroupResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaveGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class LeaveGroupResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    LeaveGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class LeaveGroupResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    LeaveGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<MemberResponseV3Deserializer>
    >{};

class LeaveGroupResponseV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaveGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<MemberResponseV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class LeaveGroupResponseV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    LeaveGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<MemberResponseV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class LeaveGroupResponseV0Parser:
  public ResponseDataParser<
    LeaveGroupResponse, LeaveGroupResponseV0Deserializer>{
public:
  LeaveGroupResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaveGroupResponseV1Parser:
  public ResponseDataParser<
    LeaveGroupResponse, LeaveGroupResponseV1Deserializer>{
public:
  LeaveGroupResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaveGroupResponseV2Parser:
  public ResponseDataParser<
    LeaveGroupResponse, LeaveGroupResponseV2Deserializer>{
public:
  LeaveGroupResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaveGroupResponseV3Parser:
  public ResponseDataParser<
    LeaveGroupResponse, LeaveGroupResponseV3Deserializer>{
public:
  LeaveGroupResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaveGroupResponseV4Parser:
  public ResponseDataParser<
    LeaveGroupResponse, LeaveGroupResponseV4Deserializer>{
public:
  LeaveGroupResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class LeaveGroupResponseV5Parser:
  public ResponseDataParser<
    LeaveGroupResponse, LeaveGroupResponseV5Deserializer>{
public:
  LeaveGroupResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct SyncGroupResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> protocol_type_;
  const absl::optional<std::string> protocol_name_;
  const Bytes assignment_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  SyncGroupResponse(int16_t error_code, Bytes assignment): throttle_time_ms_{0}, error_code_{error_code}, protocol_type_{absl::nullopt}, protocol_name_{absl::nullopt}, assignment_{assignment}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3]
  SyncGroupResponse(int32_t throttle_time_ms, int16_t error_code, Bytes assignment): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, protocol_type_{absl::nullopt}, protocol_name_{absl::nullopt}, assignment_{assignment}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  SyncGroupResponse(int32_t throttle_time_ms, int16_t error_code, Bytes assignment, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, protocol_type_{absl::nullopt}, protocol_name_{absl::nullopt}, assignment_{assignment}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5]
  SyncGroupResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> protocol_type, absl::optional<std::string> protocol_name, Bytes assignment, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, protocol_type_{protocol_type}, protocol_name_{protocol_name}, assignment_{assignment}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(protocol_type_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(protocol_name_);
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

    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(protocol_type_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(protocol_name_, dst);
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

  
  bool operator==(const SyncGroupResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && protocol_type_ == rhs.protocol_type_
    && protocol_name_ == rhs.protocol_name_
    && assignment_ == rhs.assignment_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class SyncGroupResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    SyncGroupResponse
    ,
      Int16Deserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    SyncGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    SyncGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    SyncGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      BytesDeserializer
    >{};

class SyncGroupResponseV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    SyncGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class SyncGroupResponseV5Deserializer:
  public CompositeDeserializerWith6Delegates<
    SyncGroupResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



class SyncGroupResponseV0Parser:
  public ResponseDataParser<
    SyncGroupResponse, SyncGroupResponseV0Deserializer>{
public:
  SyncGroupResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SyncGroupResponseV1Parser:
  public ResponseDataParser<
    SyncGroupResponse, SyncGroupResponseV1Deserializer>{
public:
  SyncGroupResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SyncGroupResponseV2Parser:
  public ResponseDataParser<
    SyncGroupResponse, SyncGroupResponseV2Deserializer>{
public:
  SyncGroupResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SyncGroupResponseV3Parser:
  public ResponseDataParser<
    SyncGroupResponse, SyncGroupResponseV3Deserializer>{
public:
  SyncGroupResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SyncGroupResponseV4Parser:
  public ResponseDataParser<
    SyncGroupResponse, SyncGroupResponseV4Deserializer>{
public:
  SyncGroupResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SyncGroupResponseV5Parser:
  public ResponseDataParser<
    SyncGroupResponse, SyncGroupResponseV5Deserializer>{
public:
  SyncGroupResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DescribedGroupMember {

  
  
  const std::string member_id_;
  const absl::optional<std::string> group_instance_id_;
  const std::string client_id_;
  const std::string client_host_;
  const Bytes member_metadata_;
  const Bytes member_assignment_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  DescribedGroupMember(std::string member_id, std::string client_id, std::string client_host, Bytes member_metadata, Bytes member_assignment): member_id_{member_id}, group_instance_id_{absl::nullopt}, client_id_{client_id}, client_host_{client_host}, member_metadata_{member_metadata}, member_assignment_{member_assignment}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DescribedGroupMember(std::string member_id, absl::optional<std::string> group_instance_id, std::string client_id, std::string client_host, Bytes member_metadata, Bytes member_assignment): member_id_{member_id}, group_instance_id_{group_instance_id}, client_id_{client_id}, client_host_{client_host}, member_metadata_{member_metadata}, member_assignment_{member_assignment}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  DescribedGroupMember(std::string member_id, absl::optional<std::string> group_instance_id, std::string client_id, std::string client_host, Bytes member_metadata, Bytes member_assignment, TaggedFields tagged_fields): member_id_{member_id}, group_instance_id_{group_instance_id}, client_id_{client_id}, client_host_{client_host}, member_metadata_{member_metadata}, member_assignment_{member_assignment}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(member_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(member_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(group_instance_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(group_instance_id_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(client_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(client_id_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(client_host_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(client_host_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(member_metadata_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(member_metadata_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(member_assignment_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(member_assignment_);
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
      written += encoder.encode(member_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(member_id_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(group_instance_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(group_instance_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(client_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(client_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(client_host_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(client_host_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(member_metadata_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(member_metadata_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(member_assignment_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(member_assignment_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribedGroupMember& rhs) const {
  
    return true
    && member_id_ == rhs.member_id_
    && group_instance_id_ == rhs.group_instance_id_
    && client_id_ == rhs.client_id_
    && client_host_ == rhs.client_host_
    && member_metadata_ == rhs.member_metadata_
    && member_assignment_ == rhs.member_assignment_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribedGroupMemberV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribedGroupMember
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      BytesDeserializer
    >{};

class DescribedGroupMemberV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribedGroupMember
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      BytesDeserializer
    >{};

class DescribedGroupMemberV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribedGroupMember
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      BytesDeserializer
    >{};

class DescribedGroupMemberV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribedGroupMember
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      BytesDeserializer
    >{};

class DescribedGroupMemberV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribedGroupMember
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      BytesDeserializer
    >{};

class DescribedGroupMemberV5Deserializer:
  public CompositeDeserializerWith7Delegates<
    DescribedGroupMember
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribedGroup {

  
  
  const int16_t error_code_;
  const std::string group_id_;
  const std::string group_state_;
  const std::string protocol_type_;
  const std::string protocol_data_;
  const std::vector<DescribedGroupMember> members_;
  const int32_t authorized_operations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  DescribedGroup(int16_t error_code, std::string group_id, std::string group_state, std::string protocol_type, std::string protocol_data, std::vector<DescribedGroupMember> members): error_code_{error_code}, group_id_{group_id}, group_state_{group_state}, protocol_type_{protocol_type}, protocol_data_{protocol_data}, members_{members}, authorized_operations_{INT32_MIN}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4]
  DescribedGroup(int16_t error_code, std::string group_id, std::string group_state, std::string protocol_type, std::string protocol_data, std::vector<DescribedGroupMember> members, int32_t authorized_operations): error_code_{error_code}, group_id_{group_id}, group_state_{group_state}, protocol_type_{protocol_type}, protocol_data_{protocol_data}, members_{members}, authorized_operations_{authorized_operations}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  DescribedGroup(int16_t error_code, std::string group_id, std::string group_state, std::string protocol_type, std::string protocol_data, std::vector<DescribedGroupMember> members, int32_t authorized_operations, TaggedFields tagged_fields): error_code_{error_code}, group_id_{group_id}, group_state_{group_state}, protocol_type_{protocol_type}, protocol_data_{protocol_data}, members_{members}, authorized_operations_{authorized_operations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(group_state_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(group_state_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(protocol_type_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(protocol_type_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(protocol_data_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(protocol_data_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(members_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(members_);
    }
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.computeSize(authorized_operations_);
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

    
    if (api_version >= 0 && api_version < 6) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(group_state_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(group_state_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(protocol_type_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(protocol_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(protocol_data_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(protocol_data_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(members_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(members_, dst);
    }
    
    if (api_version >= 3 && api_version < 6) {
      written += encoder.encode(authorized_operations_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribedGroup& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && group_id_ == rhs.group_id_
    && group_state_ == rhs.group_state_
    && protocol_type_ == rhs.protocol_type_
    && protocol_data_ == rhs.protocol_data_
    && members_ == rhs.members_
    && authorized_operations_ == rhs.authorized_operations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribedGroupV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribedGroup
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribedGroupMemberV0Deserializer>
    >{};

class DescribedGroupV1Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribedGroup
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribedGroupMemberV1Deserializer>
    >{};

class DescribedGroupV2Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribedGroup
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribedGroupMemberV2Deserializer>
    >{};

class DescribedGroupV3Deserializer:
  public CompositeDeserializerWith7Delegates<
    DescribedGroup
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribedGroupMemberV3Deserializer>
    ,
      Int32Deserializer
    >{};

class DescribedGroupV4Deserializer:
  public CompositeDeserializerWith7Delegates<
    DescribedGroup
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribedGroupMemberV4Deserializer>
    ,
      Int32Deserializer
    >{};

class DescribedGroupV5Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribedGroup
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribedGroupMemberV5Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeGroupsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<DescribedGroup> groups_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeGroupsResponse(std::vector<DescribedGroup> groups): throttle_time_ms_{0}, groups_{groups}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4]
  DescribeGroupsResponse(int32_t throttle_time_ms, std::vector<DescribedGroup> groups): throttle_time_ms_{throttle_time_ms}, groups_{groups}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5]
  DescribeGroupsResponse(int32_t throttle_time_ms, std::vector<DescribedGroup> groups, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, groups_{groups}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(groups_);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.computeCompactSize(groups_);
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

    
    if (api_version >= 1 && api_version < 6) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(groups_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(groups_, dst);
    }
    
    if (api_version >= 5 && api_version < 6) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeGroupsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && groups_ == rhs.groups_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeGroupsResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DescribeGroupsResponse
    ,
      ArrayDeserializer<DescribedGroupV0Deserializer>
    >{};

class DescribeGroupsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeGroupsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribedGroupV1Deserializer>
    >{};

class DescribeGroupsResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeGroupsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribedGroupV2Deserializer>
    >{};

class DescribeGroupsResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeGroupsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribedGroupV3Deserializer>
    >{};

class DescribeGroupsResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeGroupsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribedGroupV4Deserializer>
    >{};

class DescribeGroupsResponseV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeGroupsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DescribedGroupV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeGroupsResponseV0Parser:
  public ResponseDataParser<
    DescribeGroupsResponse, DescribeGroupsResponseV0Deserializer>{
public:
  DescribeGroupsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeGroupsResponseV1Parser:
  public ResponseDataParser<
    DescribeGroupsResponse, DescribeGroupsResponseV1Deserializer>{
public:
  DescribeGroupsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeGroupsResponseV2Parser:
  public ResponseDataParser<
    DescribeGroupsResponse, DescribeGroupsResponseV2Deserializer>{
public:
  DescribeGroupsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeGroupsResponseV3Parser:
  public ResponseDataParser<
    DescribeGroupsResponse, DescribeGroupsResponseV3Deserializer>{
public:
  DescribeGroupsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeGroupsResponseV4Parser:
  public ResponseDataParser<
    DescribeGroupsResponse, DescribeGroupsResponseV4Deserializer>{
public:
  DescribeGroupsResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeGroupsResponseV5Parser:
  public ResponseDataParser<
    DescribeGroupsResponse, DescribeGroupsResponseV5Deserializer>{
public:
  DescribeGroupsResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ListedGroup {

  
  
  const std::string group_id_;
  const std::string protocol_type_;
  const std::string group_state_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  ListedGroup(std::string group_id, std::string protocol_type): group_id_{group_id}, protocol_type_{protocol_type}, group_state_{""}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  ListedGroup(std::string group_id, std::string protocol_type, TaggedFields tagged_fields): group_id_{group_id}, protocol_type_{protocol_type}, group_state_{""}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  ListedGroup(std::string group_id, std::string protocol_type, std::string group_state, TaggedFields tagged_fields): group_id_{group_id}, protocol_type_{protocol_type}, group_state_{group_state}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(protocol_type_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(protocol_type_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(group_state_);
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
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(protocol_type_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(protocol_type_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(group_state_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListedGroup& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && protocol_type_ == rhs.protocol_type_
    && group_state_ == rhs.group_state_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListedGroupV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListedGroup
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class ListedGroupV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListedGroup
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class ListedGroupV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListedGroup
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class ListedGroupV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListedGroup
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class ListedGroupV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListedGroup
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ListGroupsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<ListedGroup> groups_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListGroupsResponse(int16_t error_code, std::vector<ListedGroup> groups): throttle_time_ms_{0}, error_code_{error_code}, groups_{groups}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2]
  ListGroupsResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<ListedGroup> groups): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, groups_{groups}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4]
  ListGroupsResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<ListedGroup> groups, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, groups_{groups}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(groups_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(groups_);
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

    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(groups_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(groups_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListGroupsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && groups_ == rhs.groups_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListGroupsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ListGroupsResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<ListedGroupV0Deserializer>
    >{};

class ListGroupsResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListGroupsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<ListedGroupV1Deserializer>
    >{};

class ListGroupsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ListGroupsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<ListedGroupV2Deserializer>
    >{};

class ListGroupsResponseV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListGroupsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ListedGroupV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ListGroupsResponseV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListGroupsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ListedGroupV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class ListGroupsResponseV0Parser:
  public ResponseDataParser<
    ListGroupsResponse, ListGroupsResponseV0Deserializer>{
public:
  ListGroupsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListGroupsResponseV1Parser:
  public ResponseDataParser<
    ListGroupsResponse, ListGroupsResponseV1Deserializer>{
public:
  ListGroupsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListGroupsResponseV2Parser:
  public ResponseDataParser<
    ListGroupsResponse, ListGroupsResponseV2Deserializer>{
public:
  ListGroupsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListGroupsResponseV3Parser:
  public ResponseDataParser<
    ListGroupsResponse, ListGroupsResponseV3Deserializer>{
public:
  ListGroupsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ListGroupsResponseV4Parser:
  public ResponseDataParser<
    ListGroupsResponse, ListGroupsResponseV4Deserializer>{
public:
  ListGroupsResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct SaslHandshakeResponse {

  
  
  const int16_t error_code_;
  const std::vector<std::string> mechanisms_;
  
  // constructor used in versions: [0, 1]
  SaslHandshakeResponse(int16_t error_code, std::vector<std::string> mechanisms): error_code_{error_code}, mechanisms_{mechanisms} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(mechanisms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(mechanisms_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const SaslHandshakeResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && mechanisms_ == rhs.mechanisms_;
  };

};



class SaslHandshakeResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    SaslHandshakeResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<StringDeserializer>
    >{};

class SaslHandshakeResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    SaslHandshakeResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<StringDeserializer>
    >{};



class SaslHandshakeResponseV0Parser:
  public ResponseDataParser<
    SaslHandshakeResponse, SaslHandshakeResponseV0Deserializer>{
public:
  SaslHandshakeResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SaslHandshakeResponseV1Parser:
  public ResponseDataParser<
    SaslHandshakeResponse, SaslHandshakeResponseV1Deserializer>{
public:
  SaslHandshakeResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ApiVersion {

  
  
  const int16_t api_key_;
  const int16_t min_version_;
  const int16_t max_version_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  ApiVersion(int16_t api_key, int16_t min_version, int16_t max_version): api_key_{api_key}, min_version_{min_version}, max_version_{max_version}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  ApiVersion(int16_t api_key, int16_t min_version, int16_t max_version, TaggedFields tagged_fields): api_key_{api_key}, min_version_{min_version}, max_version_{max_version}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(api_key_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(min_version_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(max_version_);
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
      written += encoder.encode(api_key_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(min_version_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(max_version_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ApiVersion& rhs) const {
  
    return true
    && api_key_ == rhs.api_key_
    && min_version_ == rhs.min_version_
    && max_version_ == rhs.max_version_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ApiVersionV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ApiVersion
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    >{};

class ApiVersionV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ApiVersion
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    >{};

class ApiVersionV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ApiVersion
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    >{};

class ApiVersionV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    ApiVersion
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ApiVersionsResponse {

  
  
  const int16_t error_code_;
  const std::vector<ApiVersion> api_keys_;
  const int32_t throttle_time_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ApiVersionsResponse(int16_t error_code, std::vector<ApiVersion> api_keys): error_code_{error_code}, api_keys_{api_keys}, throttle_time_ms_{0}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2]
  ApiVersionsResponse(int16_t error_code, std::vector<ApiVersion> api_keys, int32_t throttle_time_ms): error_code_{error_code}, api_keys_{api_keys}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  ApiVersionsResponse(int16_t error_code, std::vector<ApiVersion> api_keys, int32_t throttle_time_ms, TaggedFields tagged_fields): error_code_{error_code}, api_keys_{api_keys}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(api_keys_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(api_keys_);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(api_keys_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(api_keys_, dst);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ApiVersionsResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && api_keys_ == rhs.api_keys_
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ApiVersionsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ApiVersionsResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<ApiVersionV0Deserializer>
    >{};

class ApiVersionsResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ApiVersionsResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<ApiVersionV1Deserializer>
    ,
      Int32Deserializer
    >{};

class ApiVersionsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ApiVersionsResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<ApiVersionV2Deserializer>
    ,
      Int32Deserializer
    >{};

class ApiVersionsResponseV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    ApiVersionsResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ApiVersionV3Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class ApiVersionsResponseV0Parser:
  public ResponseDataParser<
    ApiVersionsResponse, ApiVersionsResponseV0Deserializer>{
public:
  ApiVersionsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ApiVersionsResponseV1Parser:
  public ResponseDataParser<
    ApiVersionsResponse, ApiVersionsResponseV1Deserializer>{
public:
  ApiVersionsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ApiVersionsResponseV2Parser:
  public ResponseDataParser<
    ApiVersionsResponse, ApiVersionsResponseV2Deserializer>{
public:
  ApiVersionsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ApiVersionsResponseV3Parser:
  public ResponseDataParser<
    ApiVersionsResponse, ApiVersionsResponseV3Deserializer>{
public:
  ApiVersionsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct CreatableTopicConfigs {

  
  
  const std::string name_;
  const absl::optional<std::string> value_;
  const bool read_only_;
  const int8_t config_source_;
  const bool is_sensitive_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [5, 6, 7]
  CreatableTopicConfigs(std::string name, absl::optional<std::string> value, bool read_only, int8_t config_source, bool is_sensitive, TaggedFields tagged_fields): name_{name}, value_{value}, read_only_{read_only}, config_source_{config_source}, is_sensitive_{is_sensitive}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(value_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(read_only_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(config_source_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(is_sensitive_);
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

    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(value_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(read_only_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(config_source_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(is_sensitive_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatableTopicConfigs& rhs) const {
  
    return true
    && name_ == rhs.name_
    && value_ == rhs.value_
    && read_only_ == rhs.read_only_
    && config_source_ == rhs.config_source_
    && is_sensitive_ == rhs.is_sensitive_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatableTopicConfigsV5Deserializer:
  public CompositeDeserializerWith6Delegates<
    CreatableTopicConfigs
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableTopicConfigsV6Deserializer:
  public CompositeDeserializerWith6Delegates<
    CreatableTopicConfigs
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableTopicConfigsV7Deserializer:
  public CompositeDeserializerWith6Delegates<
    CreatableTopicConfigs
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct CreatableTopicResult {

  
  
  const std::string name_;
  const Uuid topic_id_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const int32_t num_partitions_;
  const int16_t replication_factor_;
  const absl::optional<std::vector<CreatableTopicConfigs>> configs_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  CreatableTopicResult(std::string name, int16_t error_code): name_{name}, topic_id_{Uuid{0, 0}}, error_code_{error_code}, error_message_{{""}}, num_partitions_{-1}, replication_factor_{-1}, configs_{{std::vector<CreatableTopicConfigs>{}}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3, 4]
  CreatableTopicResult(std::string name, int16_t error_code, absl::optional<std::string> error_message): name_{name}, topic_id_{Uuid{0, 0}}, error_code_{error_code}, error_message_{error_message}, num_partitions_{-1}, replication_factor_{-1}, configs_{{std::vector<CreatableTopicConfigs>{}}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6]
  CreatableTopicResult(std::string name, int16_t error_code, absl::optional<std::string> error_message, int32_t num_partitions, int16_t replication_factor, absl::optional<std::vector<CreatableTopicConfigs>> configs, TaggedFields tagged_fields): name_{name}, topic_id_{Uuid{0, 0}}, error_code_{error_code}, error_message_{error_message}, num_partitions_{num_partitions}, replication_factor_{replication_factor}, configs_{configs}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [7]
  CreatableTopicResult(std::string name, Uuid topic_id, int16_t error_code, absl::optional<std::string> error_message, int32_t num_partitions, int16_t replication_factor, absl::optional<std::vector<CreatableTopicConfigs>> configs, TaggedFields tagged_fields): name_{name}, topic_id_{topic_id}, error_code_{error_code}, error_message_{error_message}, num_partitions_{num_partitions}, replication_factor_{replication_factor}, configs_{configs}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 7 && api_version < 8) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(num_partitions_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeSize(replication_factor_);
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
    
    if (api_version >= 7 && api_version < 8) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 8) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(num_partitions_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encode(replication_factor_, dst);
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

  
  bool operator==(const CreatableTopicResult& rhs) const {
  
    return true
    && name_ == rhs.name_
    && topic_id_ == rhs.topic_id_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && num_partitions_ == rhs.num_partitions_
    && replication_factor_ == rhs.replication_factor_
    && configs_ == rhs.configs_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatableTopicResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class CreatableTopicResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class CreatableTopicResultV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class CreatableTopicResultV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class CreatableTopicResultV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class CreatableTopicResultV5Deserializer:
  public CompositeDeserializerWith7Delegates<
    CreatableTopicResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactArrayDeserializer<CreatableTopicConfigsV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableTopicResultV6Deserializer:
  public CompositeDeserializerWith7Delegates<
    CreatableTopicResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactArrayDeserializer<CreatableTopicConfigsV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatableTopicResultV7Deserializer:
  public CompositeDeserializerWith8Delegates<
    CreatableTopicResult
    ,
      CompactStringDeserializer
    ,
      UuidDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactArrayDeserializer<CreatableTopicConfigsV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct CreateTopicsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<CreatableTopicResult> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreateTopicsResponse(std::vector<CreatableTopicResult> topics): throttle_time_ms_{0}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  CreateTopicsResponse(int32_t throttle_time_ms, std::vector<CreatableTopicResult> topics): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [5, 6, 7]
  CreateTopicsResponse(int32_t throttle_time_ms, std::vector<CreatableTopicResult> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 2 && api_version < 8) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.computeCompactSize(topics_);
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

    
    if (api_version >= 2 && api_version < 8) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 5 && api_version < 8) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreateTopicsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreateTopicsResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    CreateTopicsResponse
    ,
      ArrayDeserializer<CreatableTopicResultV0Deserializer>
    >{};

class CreateTopicsResponseV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    CreateTopicsResponse
    ,
      ArrayDeserializer<CreatableTopicResultV1Deserializer>
    >{};

class CreateTopicsResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateTopicsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<CreatableTopicResultV2Deserializer>
    >{};

class CreateTopicsResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateTopicsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<CreatableTopicResultV3Deserializer>
    >{};

class CreateTopicsResponseV4Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateTopicsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<CreatableTopicResultV4Deserializer>
    >{};

class CreateTopicsResponseV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateTopicsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<CreatableTopicResultV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreateTopicsResponseV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateTopicsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<CreatableTopicResultV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreateTopicsResponseV7Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateTopicsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<CreatableTopicResultV7Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class CreateTopicsResponseV0Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV0Deserializer>{
public:
  CreateTopicsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateTopicsResponseV1Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV1Deserializer>{
public:
  CreateTopicsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateTopicsResponseV2Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV2Deserializer>{
public:
  CreateTopicsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateTopicsResponseV3Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV3Deserializer>{
public:
  CreateTopicsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateTopicsResponseV4Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV4Deserializer>{
public:
  CreateTopicsResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateTopicsResponseV5Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV5Deserializer>{
public:
  CreateTopicsResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateTopicsResponseV6Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV6Deserializer>{
public:
  CreateTopicsResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateTopicsResponseV7Parser:
  public ResponseDataParser<
    CreateTopicsResponse, CreateTopicsResponseV7Deserializer>{
public:
  CreateTopicsResponseV7Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DeletableTopicResult {

  
  
  const absl::optional<std::string> name_;
  const Uuid topic_id_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  DeletableTopicResult(std::string name, int16_t error_code): name_{absl::make_optional(name)}, topic_id_{Uuid{0, 0}}, error_code_{error_code}, error_message_{absl::nullopt}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DeletableTopicResult(std::string name, int16_t error_code, TaggedFields tagged_fields): name_{absl::make_optional(name)}, topic_id_{Uuid{0, 0}}, error_code_{error_code}, error_message_{absl::nullopt}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [5]
  DeletableTopicResult(std::string name, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): name_{absl::make_optional(name)}, topic_id_{Uuid{0, 0}}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [6]
  DeletableTopicResult(absl::optional<std::string> name, Uuid topic_id, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): name_{name}, topic_id_{topic_id}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.computeSize(topic_id_);
    }
    
    if (api_version >= 0 && api_version < 7) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 5 && api_version < 7) {
      written += encoder.computeCompactSize(error_message_);
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

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 6 && api_version < 7) {
      written += encoder.encode(topic_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 7) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 5 && api_version < 7) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeletableTopicResult& rhs) const {
  
    return true
    && name_ == rhs.name_
    && topic_id_ == rhs.topic_id_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeletableTopicResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeletableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class DeletableTopicResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeletableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class DeletableTopicResultV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeletableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class DeletableTopicResultV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeletableTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class DeletableTopicResultV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeletableTopicResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DeletableTopicResultV5Deserializer:
  public CompositeDeserializerWith4Delegates<
    DeletableTopicResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DeletableTopicResultV6Deserializer:
  public CompositeDeserializerWith5Delegates<
    DeletableTopicResult
    ,
      NullableCompactStringDeserializer
    ,
      UuidDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteTopicsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<DeletableTopicResult> responses_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DeleteTopicsResponse(std::vector<DeletableTopicResult> responses): throttle_time_ms_{0}, responses_{responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3]
  DeleteTopicsResponse(int32_t throttle_time_ms, std::vector<DeletableTopicResult> responses): throttle_time_ms_{throttle_time_ms}, responses_{responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4, 5, 6]
  DeleteTopicsResponse(int32_t throttle_time_ms, std::vector<DeletableTopicResult> responses, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, responses_{responses}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 7) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(responses_);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.computeCompactSize(responses_);
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

    
    if (api_version >= 1 && api_version < 7) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(responses_, dst);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.encodeCompact(responses_, dst);
    }
    
    if (api_version >= 4 && api_version < 7) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteTopicsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && responses_ == rhs.responses_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteTopicsResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    DeleteTopicsResponse
    ,
      ArrayDeserializer<DeletableTopicResultV0Deserializer>
    >{};

class DeleteTopicsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteTopicsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeletableTopicResultV1Deserializer>
    >{};

class DeleteTopicsResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteTopicsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeletableTopicResultV2Deserializer>
    >{};

class DeleteTopicsResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteTopicsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeletableTopicResultV3Deserializer>
    >{};

class DeleteTopicsResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteTopicsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DeletableTopicResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteTopicsResponseV5Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteTopicsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DeletableTopicResultV5Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteTopicsResponseV6Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteTopicsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DeletableTopicResultV6Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DeleteTopicsResponseV0Parser:
  public ResponseDataParser<
    DeleteTopicsResponse, DeleteTopicsResponseV0Deserializer>{
public:
  DeleteTopicsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteTopicsResponseV1Parser:
  public ResponseDataParser<
    DeleteTopicsResponse, DeleteTopicsResponseV1Deserializer>{
public:
  DeleteTopicsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteTopicsResponseV2Parser:
  public ResponseDataParser<
    DeleteTopicsResponse, DeleteTopicsResponseV2Deserializer>{
public:
  DeleteTopicsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteTopicsResponseV3Parser:
  public ResponseDataParser<
    DeleteTopicsResponse, DeleteTopicsResponseV3Deserializer>{
public:
  DeleteTopicsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteTopicsResponseV4Parser:
  public ResponseDataParser<
    DeleteTopicsResponse, DeleteTopicsResponseV4Deserializer>{
public:
  DeleteTopicsResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteTopicsResponseV5Parser:
  public ResponseDataParser<
    DeleteTopicsResponse, DeleteTopicsResponseV5Deserializer>{
public:
  DeleteTopicsResponseV5Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteTopicsResponseV6Parser:
  public ResponseDataParser<
    DeleteTopicsResponse, DeleteTopicsResponseV6Deserializer>{
public:
  DeleteTopicsResponseV6Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DeleteRecordsPartitionResult {

  
  
  const int32_t partition_index_;
  const int64_t low_watermark_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteRecordsPartitionResult(int32_t partition_index, int64_t low_watermark, int16_t error_code): partition_index_{partition_index}, low_watermark_{low_watermark}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteRecordsPartitionResult(int32_t partition_index, int64_t low_watermark, int16_t error_code, TaggedFields tagged_fields): partition_index_{partition_index}, low_watermark_{low_watermark}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(low_watermark_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(low_watermark_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteRecordsPartitionResult& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && low_watermark_ == rhs.low_watermark_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteRecordsPartitionResultV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteRecordsPartitionResult
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    >{};

class DeleteRecordsPartitionResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteRecordsPartitionResult
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    >{};

class DeleteRecordsPartitionResultV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    DeleteRecordsPartitionResult
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteRecordsTopicResult {

  
  
  const std::string name_;
  const std::vector<DeleteRecordsPartitionResult> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteRecordsTopicResult(std::string name, std::vector<DeleteRecordsPartitionResult> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteRecordsTopicResult(std::string name, std::vector<DeleteRecordsPartitionResult> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const DeleteRecordsTopicResult& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteRecordsTopicResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DeleteRecordsPartitionResultV0Deserializer>
    >{};

class DeleteRecordsTopicResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DeleteRecordsPartitionResultV1Deserializer>
    >{};

class DeleteRecordsTopicResultV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteRecordsTopicResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DeleteRecordsPartitionResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteRecordsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<DeleteRecordsTopicResult> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteRecordsResponse(int32_t throttle_time_ms, std::vector<DeleteRecordsTopicResult> topics): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteRecordsResponse(int32_t throttle_time_ms, std::vector<DeleteRecordsTopicResult> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(throttle_time_ms_);
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

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(throttle_time_ms_, dst);
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

  
  bool operator==(const DeleteRecordsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteRecordsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeleteRecordsTopicResultV0Deserializer>
    >{};

class DeleteRecordsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteRecordsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeleteRecordsTopicResultV1Deserializer>
    >{};

class DeleteRecordsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteRecordsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DeleteRecordsTopicResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DeleteRecordsResponseV0Parser:
  public ResponseDataParser<
    DeleteRecordsResponse, DeleteRecordsResponseV0Deserializer>{
public:
  DeleteRecordsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteRecordsResponseV1Parser:
  public ResponseDataParser<
    DeleteRecordsResponse, DeleteRecordsResponseV1Deserializer>{
public:
  DeleteRecordsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteRecordsResponseV2Parser:
  public ResponseDataParser<
    DeleteRecordsResponse, DeleteRecordsResponseV2Deserializer>{
public:
  DeleteRecordsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct InitProducerIdResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  InitProducerIdResponse(int32_t throttle_time_ms, int16_t error_code, int64_t producer_id, int16_t producer_epoch): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  InitProducerIdResponse(int32_t throttle_time_ms, int16_t error_code, int64_t producer_id, int16_t producer_epoch, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 5) {
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

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
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

  
  bool operator==(const InitProducerIdResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class InitProducerIdResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    InitProducerIdResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    >{};

class InitProducerIdResponseV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    InitProducerIdResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    >{};

class InitProducerIdResponseV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    InitProducerIdResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class InitProducerIdResponseV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    InitProducerIdResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class InitProducerIdResponseV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    InitProducerIdResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class InitProducerIdResponseV0Parser:
  public ResponseDataParser<
    InitProducerIdResponse, InitProducerIdResponseV0Deserializer>{
public:
  InitProducerIdResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class InitProducerIdResponseV1Parser:
  public ResponseDataParser<
    InitProducerIdResponse, InitProducerIdResponseV1Deserializer>{
public:
  InitProducerIdResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class InitProducerIdResponseV2Parser:
  public ResponseDataParser<
    InitProducerIdResponse, InitProducerIdResponseV2Deserializer>{
public:
  InitProducerIdResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class InitProducerIdResponseV3Parser:
  public ResponseDataParser<
    InitProducerIdResponse, InitProducerIdResponseV3Deserializer>{
public:
  InitProducerIdResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class InitProducerIdResponseV4Parser:
  public ResponseDataParser<
    InitProducerIdResponse, InitProducerIdResponseV4Deserializer>{
public:
  InitProducerIdResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct EpochEndOffset {

  
  
  const int16_t error_code_;
  const int32_t partition_;
  const int32_t leader_epoch_;
  const int64_t end_offset_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  EpochEndOffset(int16_t error_code, int32_t partition, int64_t end_offset): error_code_{error_code}, partition_{partition}, leader_epoch_{-1}, end_offset_{end_offset}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2, 3]
  EpochEndOffset(int16_t error_code, int32_t partition, int32_t leader_epoch, int64_t end_offset): error_code_{error_code}, partition_{partition}, leader_epoch_{leader_epoch}, end_offset_{end_offset}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  EpochEndOffset(int16_t error_code, int32_t partition, int32_t leader_epoch, int64_t end_offset, TaggedFields tagged_fields): error_code_{error_code}, partition_{partition}, leader_epoch_{leader_epoch}, end_offset_{end_offset}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(partition_);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(end_offset_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(partition_, dst);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(end_offset_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EpochEndOffset& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && partition_ == rhs.partition_
    && leader_epoch_ == rhs.leader_epoch_
    && end_offset_ == rhs.end_offset_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class EpochEndOffsetV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    EpochEndOffset
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class EpochEndOffsetV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    EpochEndOffset
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class EpochEndOffsetV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    EpochEndOffset
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class EpochEndOffsetV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    EpochEndOffset
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    >{};

class EpochEndOffsetV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    EpochEndOffset
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetForLeaderTopicResult {

  
  
  const std::string topic_;
  const std::vector<EpochEndOffset> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  OffsetForLeaderTopicResult(std::string topic, std::vector<EpochEndOffset> partitions): topic_{topic}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  OffsetForLeaderTopicResult(std::string topic, std::vector<EpochEndOffset> partitions, TaggedFields tagged_fields): topic_{topic}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const OffsetForLeaderTopicResult& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetForLeaderTopicResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<EpochEndOffsetV0Deserializer>
    >{};

class OffsetForLeaderTopicResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<EpochEndOffsetV1Deserializer>
    >{};

class OffsetForLeaderTopicResultV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<EpochEndOffsetV2Deserializer>
    >{};

class OffsetForLeaderTopicResultV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<EpochEndOffsetV3Deserializer>
    >{};

class OffsetForLeaderTopicResultV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetForLeaderTopicResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<EpochEndOffsetV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OffsetForLeaderEpochResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<OffsetForLeaderTopicResult> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  OffsetForLeaderEpochResponse(std::vector<OffsetForLeaderTopicResult> topics): throttle_time_ms_{0}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  OffsetForLeaderEpochResponse(int32_t throttle_time_ms, std::vector<OffsetForLeaderTopicResult> topics): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  OffsetForLeaderEpochResponse(int32_t throttle_time_ms, std::vector<OffsetForLeaderTopicResult> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
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

    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encode(throttle_time_ms_, dst);
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

  
  bool operator==(const OffsetForLeaderEpochResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OffsetForLeaderEpochResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetForLeaderEpochResponse
    ,
      ArrayDeserializer<OffsetForLeaderTopicResultV0Deserializer>
    >{};

class OffsetForLeaderEpochResponseV1Deserializer:
  public CompositeDeserializerWith1Delegates<
    OffsetForLeaderEpochResponse
    ,
      ArrayDeserializer<OffsetForLeaderTopicResultV1Deserializer>
    >{};

class OffsetForLeaderEpochResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderEpochResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetForLeaderTopicResultV2Deserializer>
    >{};

class OffsetForLeaderEpochResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetForLeaderEpochResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetForLeaderTopicResultV3Deserializer>
    >{};

class OffsetForLeaderEpochResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetForLeaderEpochResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<OffsetForLeaderTopicResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class OffsetForLeaderEpochResponseV0Parser:
  public ResponseDataParser<
    OffsetForLeaderEpochResponse, OffsetForLeaderEpochResponseV0Deserializer>{
public:
  OffsetForLeaderEpochResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetForLeaderEpochResponseV1Parser:
  public ResponseDataParser<
    OffsetForLeaderEpochResponse, OffsetForLeaderEpochResponseV1Deserializer>{
public:
  OffsetForLeaderEpochResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetForLeaderEpochResponseV2Parser:
  public ResponseDataParser<
    OffsetForLeaderEpochResponse, OffsetForLeaderEpochResponseV2Deserializer>{
public:
  OffsetForLeaderEpochResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetForLeaderEpochResponseV3Parser:
  public ResponseDataParser<
    OffsetForLeaderEpochResponse, OffsetForLeaderEpochResponseV3Deserializer>{
public:
  OffsetForLeaderEpochResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class OffsetForLeaderEpochResponseV4Parser:
  public ResponseDataParser<
    OffsetForLeaderEpochResponse, OffsetForLeaderEpochResponseV4Deserializer>{
public:
  OffsetForLeaderEpochResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AddPartitionsToTxnPartitionResult {

  
  
  const int32_t partition_index_;
  const int16_t partition_error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  AddPartitionsToTxnPartitionResult(int32_t partition_index, int16_t partition_error_code): partition_index_{partition_index}, partition_error_code_{partition_error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4]
  AddPartitionsToTxnPartitionResult(int32_t partition_index, int16_t partition_error_code, TaggedFields tagged_fields): partition_index_{partition_index}, partition_error_code_{partition_error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(partition_error_code_);
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

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(partition_error_code_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddPartitionsToTxnPartitionResult& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && partition_error_code_ == rhs.partition_error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddPartitionsToTxnPartitionResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AddPartitionsToTxnPartitionResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AddPartitionsToTxnPartitionResultV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AddPartitionsToTxnPartitionResultV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class AddPartitionsToTxnPartitionResultV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct AddPartitionsToTxnTopicResult {

  
  
  const std::string name_;
  const std::vector<AddPartitionsToTxnPartitionResult> results_by_partition_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  AddPartitionsToTxnTopicResult(std::string name, std::vector<AddPartitionsToTxnPartitionResult> results_by_partition): name_{name}, results_by_partition_{results_by_partition}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3, 4]
  AddPartitionsToTxnTopicResult(std::string name, std::vector<AddPartitionsToTxnPartitionResult> results_by_partition, TaggedFields tagged_fields): name_{name}, results_by_partition_{results_by_partition}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(results_by_partition_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeCompactSize(results_by_partition_);
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
      written += encoder.encode(results_by_partition_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(results_by_partition_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddPartitionsToTxnTopicResult& rhs) const {
  
    return true
    && name_ == rhs.name_
    && results_by_partition_ == rhs.results_by_partition_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddPartitionsToTxnTopicResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnPartitionResultV0Deserializer>
    >{};

class AddPartitionsToTxnTopicResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnPartitionResultV1Deserializer>
    >{};

class AddPartitionsToTxnTopicResultV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnPartitionResultV2Deserializer>
    >{};

class AddPartitionsToTxnTopicResultV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnTopicResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<AddPartitionsToTxnPartitionResultV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AddPartitionsToTxnTopicResultV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnTopicResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<AddPartitionsToTxnPartitionResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AddPartitionsToTxnResult {

  
  
  const std::string transactional_id_;
  const std::vector<AddPartitionsToTxnTopicResult> topic_results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [4]
  AddPartitionsToTxnResult(std::string transactional_id, std::vector<AddPartitionsToTxnTopicResult> topic_results, TaggedFields tagged_fields): transactional_id_{transactional_id}, topic_results_{topic_results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(topic_results_);
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
      written += encoder.encodeCompact(topic_results_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddPartitionsToTxnResult& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && topic_results_ == rhs.topic_results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddPartitionsToTxnResultV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<AddPartitionsToTxnTopicResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AddPartitionsToTxnResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<AddPartitionsToTxnResult> results_by_transaction_;
  const std::vector<AddPartitionsToTxnTopicResult> results_by_topic_v3_and_below_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  AddPartitionsToTxnResponse(int32_t throttle_time_ms, std::vector<AddPartitionsToTxnTopicResult> results_by_topic_v3_and_below): throttle_time_ms_{throttle_time_ms}, error_code_{0}, results_by_transaction_{std::vector<AddPartitionsToTxnResult>{}}, results_by_topic_v3_and_below_{results_by_topic_v3_and_below}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  AddPartitionsToTxnResponse(int32_t throttle_time_ms, std::vector<AddPartitionsToTxnTopicResult> results_by_topic_v3_and_below, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{0}, results_by_transaction_{std::vector<AddPartitionsToTxnResult>{}}, results_by_topic_v3_and_below_{results_by_topic_v3_and_below}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  AddPartitionsToTxnResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<AddPartitionsToTxnResult> results_by_transaction, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, results_by_transaction_{results_by_transaction}, results_by_topic_v3_and_below_{std::vector<AddPartitionsToTxnTopicResult>{}}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(results_by_transaction_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(results_by_topic_v3_and_below_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(results_by_topic_v3_and_below_);
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

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(results_by_transaction_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(results_by_topic_v3_and_below_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(results_by_topic_v3_and_below_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddPartitionsToTxnResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && results_by_transaction_ == rhs.results_by_transaction_
    && results_by_topic_v3_and_below_ == rhs.results_by_topic_v3_and_below_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddPartitionsToTxnResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnTopicResultV0Deserializer>
    >{};

class AddPartitionsToTxnResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnTopicResultV1Deserializer>
    >{};

class AddPartitionsToTxnResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddPartitionsToTxnResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AddPartitionsToTxnTopicResultV2Deserializer>
    >{};

class AddPartitionsToTxnResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddPartitionsToTxnResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<AddPartitionsToTxnTopicResultV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AddPartitionsToTxnResponseV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    AddPartitionsToTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<AddPartitionsToTxnResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class AddPartitionsToTxnResponseV0Parser:
  public ResponseDataParser<
    AddPartitionsToTxnResponse, AddPartitionsToTxnResponseV0Deserializer>{
public:
  AddPartitionsToTxnResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AddPartitionsToTxnResponseV1Parser:
  public ResponseDataParser<
    AddPartitionsToTxnResponse, AddPartitionsToTxnResponseV1Deserializer>{
public:
  AddPartitionsToTxnResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AddPartitionsToTxnResponseV2Parser:
  public ResponseDataParser<
    AddPartitionsToTxnResponse, AddPartitionsToTxnResponseV2Deserializer>{
public:
  AddPartitionsToTxnResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AddPartitionsToTxnResponseV3Parser:
  public ResponseDataParser<
    AddPartitionsToTxnResponse, AddPartitionsToTxnResponseV3Deserializer>{
public:
  AddPartitionsToTxnResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AddPartitionsToTxnResponseV4Parser:
  public ResponseDataParser<
    AddPartitionsToTxnResponse, AddPartitionsToTxnResponseV4Deserializer>{
public:
  AddPartitionsToTxnResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AddOffsetsToTxnResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  AddOffsetsToTxnResponse(int32_t throttle_time_ms, int16_t error_code): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  AddOffsetsToTxnResponse(int32_t throttle_time_ms, int16_t error_code, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AddOffsetsToTxnResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AddOffsetsToTxnResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddOffsetsToTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AddOffsetsToTxnResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddOffsetsToTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AddOffsetsToTxnResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    AddOffsetsToTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AddOffsetsToTxnResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    AddOffsetsToTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class AddOffsetsToTxnResponseV0Parser:
  public ResponseDataParser<
    AddOffsetsToTxnResponse, AddOffsetsToTxnResponseV0Deserializer>{
public:
  AddOffsetsToTxnResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AddOffsetsToTxnResponseV1Parser:
  public ResponseDataParser<
    AddOffsetsToTxnResponse, AddOffsetsToTxnResponseV1Deserializer>{
public:
  AddOffsetsToTxnResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AddOffsetsToTxnResponseV2Parser:
  public ResponseDataParser<
    AddOffsetsToTxnResponse, AddOffsetsToTxnResponseV2Deserializer>{
public:
  AddOffsetsToTxnResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AddOffsetsToTxnResponseV3Parser:
  public ResponseDataParser<
    AddOffsetsToTxnResponse, AddOffsetsToTxnResponseV3Deserializer>{
public:
  AddOffsetsToTxnResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct EndTxnResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  EndTxnResponse(int32_t throttle_time_ms, int16_t error_code): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  EndTxnResponse(int32_t throttle_time_ms, int16_t error_code, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EndTxnResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class EndTxnResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    EndTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class EndTxnResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    EndTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class EndTxnResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    EndTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class EndTxnResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    EndTxnResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class EndTxnResponseV0Parser:
  public ResponseDataParser<
    EndTxnResponse, EndTxnResponseV0Deserializer>{
public:
  EndTxnResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class EndTxnResponseV1Parser:
  public ResponseDataParser<
    EndTxnResponse, EndTxnResponseV1Deserializer>{
public:
  EndTxnResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class EndTxnResponseV2Parser:
  public ResponseDataParser<
    EndTxnResponse, EndTxnResponseV2Deserializer>{
public:
  EndTxnResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class EndTxnResponseV3Parser:
  public ResponseDataParser<
    EndTxnResponse, EndTxnResponseV3Deserializer>{
public:
  EndTxnResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct WritableTxnMarkerPartitionResult {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  WritableTxnMarkerPartitionResult(int32_t partition_index, int16_t error_code): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  WritableTxnMarkerPartitionResult(int32_t partition_index, int16_t error_code, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const WritableTxnMarkerPartitionResult& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class WritableTxnMarkerPartitionResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    WritableTxnMarkerPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class WritableTxnMarkerPartitionResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    WritableTxnMarkerPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct WritableTxnMarkerTopicResult {

  
  
  const std::string name_;
  const std::vector<WritableTxnMarkerPartitionResult> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  WritableTxnMarkerTopicResult(std::string name, std::vector<WritableTxnMarkerPartitionResult> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  WritableTxnMarkerTopicResult(std::string name, std::vector<WritableTxnMarkerPartitionResult> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(partitions_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(partitions_);
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
      written += encoder.encode(partitions_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(partitions_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const WritableTxnMarkerTopicResult& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class WritableTxnMarkerTopicResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    WritableTxnMarkerTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<WritableTxnMarkerPartitionResultV0Deserializer>
    >{};

class WritableTxnMarkerTopicResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    WritableTxnMarkerTopicResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<WritableTxnMarkerPartitionResultV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct WritableTxnMarkerResult {

  
  
  const int64_t producer_id_;
  const std::vector<WritableTxnMarkerTopicResult> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  WritableTxnMarkerResult(int64_t producer_id, std::vector<WritableTxnMarkerTopicResult> topics): producer_id_{producer_id}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  WritableTxnMarkerResult(int64_t producer_id, std::vector<WritableTxnMarkerTopicResult> topics, TaggedFields tagged_fields): producer_id_{producer_id}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(topics_);
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
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const WritableTxnMarkerResult& rhs) const {
  
    return true
    && producer_id_ == rhs.producer_id_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class WritableTxnMarkerResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    WritableTxnMarkerResult
    ,
      Int64Deserializer
    ,
      ArrayDeserializer<WritableTxnMarkerTopicResultV0Deserializer>
    >{};

class WritableTxnMarkerResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    WritableTxnMarkerResult
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<WritableTxnMarkerTopicResultV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct WriteTxnMarkersResponse {

  
  
  const std::vector<WritableTxnMarkerResult> markers_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  WriteTxnMarkersResponse(std::vector<WritableTxnMarkerResult> markers): markers_{markers}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  WriteTxnMarkersResponse(std::vector<WritableTxnMarkerResult> markers, TaggedFields tagged_fields): markers_{markers}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const WriteTxnMarkersResponse& rhs) const {
  
    return true
    && markers_ == rhs.markers_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class WriteTxnMarkersResponseV0Deserializer:
  public CompositeDeserializerWith1Delegates<
    WriteTxnMarkersResponse
    ,
      ArrayDeserializer<WritableTxnMarkerResultV0Deserializer>
    >{};

class WriteTxnMarkersResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    WriteTxnMarkersResponse
    ,
      CompactArrayDeserializer<WritableTxnMarkerResultV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class WriteTxnMarkersResponseV0Parser:
  public ResponseDataParser<
    WriteTxnMarkersResponse, WriteTxnMarkersResponseV0Deserializer>{
public:
  WriteTxnMarkersResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class WriteTxnMarkersResponseV1Parser:
  public ResponseDataParser<
    WriteTxnMarkersResponse, WriteTxnMarkersResponseV1Deserializer>{
public:
  WriteTxnMarkersResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct TxnOffsetCommitResponsePartition {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  TxnOffsetCommitResponsePartition(int32_t partition_index, int16_t error_code): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  TxnOffsetCommitResponsePartition(int32_t partition_index, int16_t error_code, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const TxnOffsetCommitResponsePartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TxnOffsetCommitResponsePartitionV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class TxnOffsetCommitResponsePartitionV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class TxnOffsetCommitResponsePartitionV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class TxnOffsetCommitResponsePartitionV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    TxnOffsetCommitResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct TxnOffsetCommitResponseTopic {

  
  
  const std::string name_;
  const std::vector<TxnOffsetCommitResponsePartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  TxnOffsetCommitResponseTopic(std::string name, std::vector<TxnOffsetCommitResponsePartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  TxnOffsetCommitResponseTopic(std::string name, std::vector<TxnOffsetCommitResponsePartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const TxnOffsetCommitResponseTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TxnOffsetCommitResponseTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<TxnOffsetCommitResponsePartitionV0Deserializer>
    >{};

class TxnOffsetCommitResponseTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<TxnOffsetCommitResponsePartitionV1Deserializer>
    >{};

class TxnOffsetCommitResponseTopicV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<TxnOffsetCommitResponsePartitionV2Deserializer>
    >{};

class TxnOffsetCommitResponseTopicV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    TxnOffsetCommitResponseTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<TxnOffsetCommitResponsePartitionV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct TxnOffsetCommitResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<TxnOffsetCommitResponseTopic> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2]
  TxnOffsetCommitResponse(int32_t throttle_time_ms, std::vector<TxnOffsetCommitResponseTopic> topics): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  TxnOffsetCommitResponse(int32_t throttle_time_ms, std::vector<TxnOffsetCommitResponseTopic> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
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

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(throttle_time_ms_, dst);
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

  
  bool operator==(const TxnOffsetCommitResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TxnOffsetCommitResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TxnOffsetCommitResponseTopicV0Deserializer>
    >{};

class TxnOffsetCommitResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TxnOffsetCommitResponseTopicV1Deserializer>
    >{};

class TxnOffsetCommitResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    TxnOffsetCommitResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<TxnOffsetCommitResponseTopicV2Deserializer>
    >{};

class TxnOffsetCommitResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    TxnOffsetCommitResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<TxnOffsetCommitResponseTopicV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class TxnOffsetCommitResponseV0Parser:
  public ResponseDataParser<
    TxnOffsetCommitResponse, TxnOffsetCommitResponseV0Deserializer>{
public:
  TxnOffsetCommitResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class TxnOffsetCommitResponseV1Parser:
  public ResponseDataParser<
    TxnOffsetCommitResponse, TxnOffsetCommitResponseV1Deserializer>{
public:
  TxnOffsetCommitResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class TxnOffsetCommitResponseV2Parser:
  public ResponseDataParser<
    TxnOffsetCommitResponse, TxnOffsetCommitResponseV2Deserializer>{
public:
  TxnOffsetCommitResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class TxnOffsetCommitResponseV3Parser:
  public ResponseDataParser<
    TxnOffsetCommitResponse, TxnOffsetCommitResponseV3Deserializer>{
public:
  TxnOffsetCommitResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AclDescription {

  
  
  const std::string principal_;
  const std::string host_;
  const int8_t operation_;
  const int8_t permission_type_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AclDescription(std::string principal, std::string host, int8_t operation, int8_t permission_type): principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  AclDescription(std::string principal, std::string host, int8_t operation, int8_t permission_type, TaggedFields tagged_fields): principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
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

  
  bool operator==(const AclDescription& rhs) const {
  
    return true
    && principal_ == rhs.principal_
    && host_ == rhs.host_
    && operation_ == rhs.operation_
    && permission_type_ == rhs.permission_type_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AclDescriptionV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    AclDescription
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class AclDescriptionV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    AclDescription
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      Int8Deserializer
    >{};

class AclDescriptionV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    AclDescription
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

class AclDescriptionV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    AclDescription
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


struct DescribeAclsResource {

  
  
  const int8_t resource_type_;
  const std::string resource_name_;
  const int8_t pattern_type_;
  const std::vector<AclDescription> acls_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeAclsResource(int8_t resource_type, std::string resource_name, std::vector<AclDescription> acls): resource_type_{resource_type}, resource_name_{resource_name}, pattern_type_{3}, acls_{acls}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DescribeAclsResource(int8_t resource_type, std::string resource_name, int8_t pattern_type, std::vector<AclDescription> acls): resource_type_{resource_type}, resource_name_{resource_name}, pattern_type_{pattern_type}, acls_{acls}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribeAclsResource(int8_t resource_type, std::string resource_name, int8_t pattern_type, std::vector<AclDescription> acls, TaggedFields tagged_fields): resource_type_{resource_type}, resource_name_{resource_name}, pattern_type_{pattern_type}, acls_{acls}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(pattern_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(acls_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(acls_);
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
      written += encoder.encode(pattern_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(acls_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(acls_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeAclsResource& rhs) const {
  
    return true
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && pattern_type_ == rhs.pattern_type_
    && acls_ == rhs.acls_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeAclsResourceV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeAclsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AclDescriptionV0Deserializer>
    >{};

class DescribeAclsResourceV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeAclsResource
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      Int8Deserializer
    ,
      ArrayDeserializer<AclDescriptionV1Deserializer>
    >{};

class DescribeAclsResourceV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeAclsResource
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<AclDescriptionV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeAclsResourceV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeAclsResource
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      Int8Deserializer
    ,
      CompactArrayDeserializer<AclDescriptionV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeAclsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<DescribeAclsResource> resources_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeAclsResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, std::vector<DescribeAclsResource> resources): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, resources_{resources}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribeAclsResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, std::vector<DescribeAclsResource> resources, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, resources_{resources}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resources_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(resources_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resources_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(resources_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeAclsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && resources_ == rhs.resources_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeAclsResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeAclsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<DescribeAclsResourceV0Deserializer>
    >{};

class DescribeAclsResponseV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeAclsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<DescribeAclsResourceV1Deserializer>
    >{};

class DescribeAclsResponseV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeAclsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeAclsResourceV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeAclsResponseV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeAclsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeAclsResourceV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeAclsResponseV0Parser:
  public ResponseDataParser<
    DescribeAclsResponse, DescribeAclsResponseV0Deserializer>{
public:
  DescribeAclsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeAclsResponseV1Parser:
  public ResponseDataParser<
    DescribeAclsResponse, DescribeAclsResponseV1Deserializer>{
public:
  DescribeAclsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeAclsResponseV2Parser:
  public ResponseDataParser<
    DescribeAclsResponse, DescribeAclsResponseV2Deserializer>{
public:
  DescribeAclsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeAclsResponseV3Parser:
  public ResponseDataParser<
    DescribeAclsResponse, DescribeAclsResponseV3Deserializer>{
public:
  DescribeAclsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AclCreationResult {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AclCreationResult(int16_t error_code, absl::optional<std::string> error_message): error_code_{error_code}, error_message_{error_message}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  AclCreationResult(int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AclCreationResult& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AclCreationResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AclCreationResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class AclCreationResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AclCreationResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class AclCreationResultV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AclCreationResult
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class AclCreationResultV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    AclCreationResult
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct CreateAclsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<AclCreationResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreateAclsResponse(int32_t throttle_time_ms, std::vector<AclCreationResult> results): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreateAclsResponse(int32_t throttle_time_ms, std::vector<AclCreationResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(results_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreateAclsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreateAclsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateAclsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AclCreationResultV0Deserializer>
    >{};

class CreateAclsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreateAclsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AclCreationResultV1Deserializer>
    >{};

class CreateAclsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateAclsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<AclCreationResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreateAclsResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreateAclsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<AclCreationResultV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class CreateAclsResponseV0Parser:
  public ResponseDataParser<
    CreateAclsResponse, CreateAclsResponseV0Deserializer>{
public:
  CreateAclsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateAclsResponseV1Parser:
  public ResponseDataParser<
    CreateAclsResponse, CreateAclsResponseV1Deserializer>{
public:
  CreateAclsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateAclsResponseV2Parser:
  public ResponseDataParser<
    CreateAclsResponse, CreateAclsResponseV2Deserializer>{
public:
  CreateAclsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateAclsResponseV3Parser:
  public ResponseDataParser<
    CreateAclsResponse, CreateAclsResponseV3Deserializer>{
public:
  CreateAclsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DeleteAclsMatchingAcl {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const int8_t resource_type_;
  const std::string resource_name_;
  const int8_t pattern_type_;
  const std::string principal_;
  const std::string host_;
  const int8_t operation_;
  const int8_t permission_type_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DeleteAclsMatchingAcl(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name, std::string principal, std::string host, int8_t operation, int8_t permission_type): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, pattern_type_{3}, principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DeleteAclsMatchingAcl(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name, int8_t pattern_type, std::string principal, std::string host, int8_t operation, int8_t permission_type): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, pattern_type_{pattern_type}, principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DeleteAclsMatchingAcl(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name, int8_t pattern_type, std::string principal, std::string host, int8_t operation, int8_t permission_type, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, pattern_type_{pattern_type}, principal_{principal}, host_{host}, operation_{operation}, permission_type_{permission_type}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(error_message_);
    }
    
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
      written += encoder.computeSize(pattern_type_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
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
      written += encoder.encode(pattern_type_, dst);
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

  
  bool operator==(const DeleteAclsMatchingAcl& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && pattern_type_ == rhs.pattern_type_
    && principal_ == rhs.principal_
    && host_ == rhs.host_
    && operation_ == rhs.operation_
    && permission_type_ == rhs.permission_type_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteAclsMatchingAclV0Deserializer:
  public CompositeDeserializerWith8Delegates<
    DeleteAclsMatchingAcl
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
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

class DeleteAclsMatchingAclV1Deserializer:
  public CompositeDeserializerWith9Delegates<
    DeleteAclsMatchingAcl
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
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

class DeleteAclsMatchingAclV2Deserializer:
  public CompositeDeserializerWith10Delegates<
    DeleteAclsMatchingAcl
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
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

class DeleteAclsMatchingAclV3Deserializer:
  public CompositeDeserializerWith10Delegates<
    DeleteAclsMatchingAcl
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
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


struct DeleteAclsFilterResult {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<DeleteAclsMatchingAcl> matching_acls_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteAclsFilterResult(int16_t error_code, absl::optional<std::string> error_message, std::vector<DeleteAclsMatchingAcl> matching_acls): error_code_{error_code}, error_message_{error_message}, matching_acls_{matching_acls}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DeleteAclsFilterResult(int16_t error_code, absl::optional<std::string> error_message, std::vector<DeleteAclsMatchingAcl> matching_acls, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, matching_acls_{matching_acls}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(matching_acls_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(matching_acls_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(matching_acls_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(matching_acls_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteAclsFilterResult& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && matching_acls_ == rhs.matching_acls_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteAclsFilterResultV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteAclsFilterResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<DeleteAclsMatchingAclV0Deserializer>
    >{};

class DeleteAclsFilterResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteAclsFilterResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<DeleteAclsMatchingAclV1Deserializer>
    >{};

class DeleteAclsFilterResultV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    DeleteAclsFilterResult
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<DeleteAclsMatchingAclV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteAclsFilterResultV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    DeleteAclsFilterResult
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<DeleteAclsMatchingAclV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteAclsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<DeleteAclsFilterResult> filter_results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteAclsResponse(int32_t throttle_time_ms, std::vector<DeleteAclsFilterResult> filter_results): throttle_time_ms_{throttle_time_ms}, filter_results_{filter_results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DeleteAclsResponse(int32_t throttle_time_ms, std::vector<DeleteAclsFilterResult> filter_results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, filter_results_{filter_results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(filter_results_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(filter_results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(filter_results_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(filter_results_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteAclsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && filter_results_ == rhs.filter_results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteAclsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteAclsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeleteAclsFilterResultV0Deserializer>
    >{};

class DeleteAclsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteAclsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeleteAclsFilterResultV1Deserializer>
    >{};

class DeleteAclsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteAclsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DeleteAclsFilterResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DeleteAclsResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteAclsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DeleteAclsFilterResultV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DeleteAclsResponseV0Parser:
  public ResponseDataParser<
    DeleteAclsResponse, DeleteAclsResponseV0Deserializer>{
public:
  DeleteAclsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteAclsResponseV1Parser:
  public ResponseDataParser<
    DeleteAclsResponse, DeleteAclsResponseV1Deserializer>{
public:
  DeleteAclsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteAclsResponseV2Parser:
  public ResponseDataParser<
    DeleteAclsResponse, DeleteAclsResponseV2Deserializer>{
public:
  DeleteAclsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteAclsResponseV3Parser:
  public ResponseDataParser<
    DeleteAclsResponse, DeleteAclsResponseV3Deserializer>{
public:
  DeleteAclsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DescribeConfigsSynonym {

  
  
  const std::string name_;
  const absl::optional<std::string> value_;
  const int8_t source_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [1, 2, 3]
  DescribeConfigsSynonym(std::string name, absl::optional<std::string> value, int8_t source): name_{name}, value_{value}, source_{source}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DescribeConfigsSynonym(std::string name, absl::optional<std::string> value, int8_t source, TaggedFields tagged_fields): name_{name}, value_{value}, source_{source}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(value_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(value_);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(source_);
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

    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(value_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(value_, dst);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(source_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeConfigsSynonym& rhs) const {
  
    return true
    && name_ == rhs.name_
    && value_ == rhs.value_
    && source_ == rhs.source_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeConfigsSynonymV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsSynonym
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    >{};

class DescribeConfigsSynonymV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsSynonym
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    >{};

class DescribeConfigsSynonymV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsSynonym
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    >{};

class DescribeConfigsSynonymV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeConfigsSynonym
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeConfigsResourceResult {

  
  
  const std::string name_;
  const absl::optional<std::string> value_;
  const bool read_only_;
  const bool is_default_;
  const int8_t config_source_;
  const bool is_sensitive_;
  const std::vector<DescribeConfigsSynonym> synonyms_;
  const int8_t config_type_;
  const absl::optional<std::string> documentation_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeConfigsResourceResult(std::string name, absl::optional<std::string> value, bool read_only, bool is_default, bool is_sensitive): name_{name}, value_{value}, read_only_{read_only}, is_default_{is_default}, config_source_{-1}, is_sensitive_{is_sensitive}, synonyms_{std::vector<DescribeConfigsSynonym>{}}, config_type_{0}, documentation_{{""}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1, 2]
  DescribeConfigsResourceResult(std::string name, absl::optional<std::string> value, bool read_only, int8_t config_source, bool is_sensitive, std::vector<DescribeConfigsSynonym> synonyms): name_{name}, value_{value}, read_only_{read_only}, is_default_{false}, config_source_{config_source}, is_sensitive_{is_sensitive}, synonyms_{synonyms}, config_type_{0}, documentation_{{""}}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [3]
  DescribeConfigsResourceResult(std::string name, absl::optional<std::string> value, bool read_only, int8_t config_source, bool is_sensitive, std::vector<DescribeConfigsSynonym> synonyms, int8_t config_type, absl::optional<std::string> documentation): name_{name}, value_{value}, read_only_{read_only}, is_default_{false}, config_source_{config_source}, is_sensitive_{is_sensitive}, synonyms_{synonyms}, config_type_{config_type}, documentation_{documentation}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DescribeConfigsResourceResult(std::string name, absl::optional<std::string> value, bool read_only, int8_t config_source, bool is_sensitive, std::vector<DescribeConfigsSynonym> synonyms, int8_t config_type, absl::optional<std::string> documentation, TaggedFields tagged_fields): name_{name}, value_{value}, read_only_{read_only}, is_default_{false}, config_source_{config_source}, is_sensitive_{is_sensitive}, synonyms_{synonyms}, config_type_{config_type}, documentation_{documentation}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(name_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(value_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(value_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(read_only_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(is_default_);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.computeSize(config_source_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(is_sensitive_);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.computeSize(synonyms_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(synonyms_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(config_type_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeSize(documentation_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(documentation_);
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
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(name_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(value_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(value_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(read_only_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(is_default_, dst);
    }
    
    if (api_version >= 1 && api_version < 5) {
      written += encoder.encode(config_source_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(is_sensitive_, dst);
    }
    
    if (api_version >= 1 && api_version < 4) {
      written += encoder.encode(synonyms_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(synonyms_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(config_type_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encode(documentation_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(documentation_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeConfigsResourceResult& rhs) const {
  
    return true
    && name_ == rhs.name_
    && value_ == rhs.value_
    && read_only_ == rhs.read_only_
    && is_default_ == rhs.is_default_
    && config_source_ == rhs.config_source_
    && is_sensitive_ == rhs.is_sensitive_
    && synonyms_ == rhs.synonyms_
    && config_type_ == rhs.config_type_
    && documentation_ == rhs.documentation_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeConfigsResourceResultV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeConfigsResourceResult
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    >{};

class DescribeConfigsResourceResultV1Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribeConfigsResourceResult
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<DescribeConfigsSynonymV1Deserializer>
    >{};

class DescribeConfigsResourceResultV2Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribeConfigsResourceResult
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<DescribeConfigsSynonymV2Deserializer>
    >{};

class DescribeConfigsResourceResultV3Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribeConfigsResourceResult
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      BooleanDeserializer
    ,
      ArrayDeserializer<DescribeConfigsSynonymV3Deserializer>
    ,
      Int8Deserializer
    ,
      NullableStringDeserializer
    >{};

class DescribeConfigsResourceResultV4Deserializer:
  public CompositeDeserializerWith9Delegates<
    DescribeConfigsResourceResult
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      BooleanDeserializer
    ,
      Int8Deserializer
    ,
      BooleanDeserializer
    ,
      CompactArrayDeserializer<DescribeConfigsSynonymV4Deserializer>
    ,
      Int8Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeConfigsResult {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const int8_t resource_type_;
  const std::string resource_name_;
  const std::vector<DescribeConfigsResourceResult> configs_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  DescribeConfigsResult(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name, std::vector<DescribeConfigsResourceResult> configs): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, configs_{configs}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DescribeConfigsResult(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name, std::vector<DescribeConfigsResourceResult> configs, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, configs_{configs}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(error_message_);
    }
    
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
      written += encoder.computeSize(configs_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(configs_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
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
      written += encoder.encode(configs_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(configs_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeConfigsResult& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && configs_ == rhs.configs_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeConfigsResultV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeConfigsResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeConfigsResourceResultV0Deserializer>
    >{};

class DescribeConfigsResultV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeConfigsResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeConfigsResourceResultV1Deserializer>
    >{};

class DescribeConfigsResultV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeConfigsResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeConfigsResourceResultV2Deserializer>
    >{};

class DescribeConfigsResultV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeConfigsResult
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeConfigsResourceResultV3Deserializer>
    >{};

class DescribeConfigsResultV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribeConfigsResult
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeConfigsResourceResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeConfigsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<DescribeConfigsResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  DescribeConfigsResponse(int32_t throttle_time_ms, std::vector<DescribeConfigsResult> results): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [4]
  DescribeConfigsResponse(int32_t throttle_time_ms, std::vector<DescribeConfigsResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(results_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(results_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeConfigsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeConfigsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeConfigsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribeConfigsResultV0Deserializer>
    >{};

class DescribeConfigsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeConfigsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribeConfigsResultV1Deserializer>
    >{};

class DescribeConfigsResponseV2Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeConfigsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribeConfigsResultV2Deserializer>
    >{};

class DescribeConfigsResponseV3Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeConfigsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribeConfigsResultV3Deserializer>
    >{};

class DescribeConfigsResponseV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeConfigsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DescribeConfigsResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeConfigsResponseV0Parser:
  public ResponseDataParser<
    DescribeConfigsResponse, DescribeConfigsResponseV0Deserializer>{
public:
  DescribeConfigsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeConfigsResponseV1Parser:
  public ResponseDataParser<
    DescribeConfigsResponse, DescribeConfigsResponseV1Deserializer>{
public:
  DescribeConfigsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeConfigsResponseV2Parser:
  public ResponseDataParser<
    DescribeConfigsResponse, DescribeConfigsResponseV2Deserializer>{
public:
  DescribeConfigsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeConfigsResponseV3Parser:
  public ResponseDataParser<
    DescribeConfigsResponse, DescribeConfigsResponseV3Deserializer>{
public:
  DescribeConfigsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeConfigsResponseV4Parser:
  public ResponseDataParser<
    DescribeConfigsResponse, DescribeConfigsResponseV4Deserializer>{
public:
  DescribeConfigsResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AlterConfigsResourceResponse {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const int8_t resource_type_;
  const std::string resource_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterConfigsResourceResponse(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterConfigsResourceResponse(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(resource_type_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resource_name_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(resource_name_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(resource_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resource_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(resource_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterConfigsResourceResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterConfigsResourceResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterConfigsResourceResponse
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    >{};

class AlterConfigsResourceResponseV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterConfigsResourceResponse
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    >{};

class AlterConfigsResourceResponseV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    AlterConfigsResourceResponse
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterConfigsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<AlterConfigsResourceResponse> responses_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterConfigsResponse(int32_t throttle_time_ms, std::vector<AlterConfigsResourceResponse> responses): throttle_time_ms_{throttle_time_ms}, responses_{responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterConfigsResponse(int32_t throttle_time_ms, std::vector<AlterConfigsResourceResponse> responses, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, responses_{responses}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(responses_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(responses_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(responses_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(responses_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterConfigsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && responses_ == rhs.responses_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterConfigsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterConfigsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AlterConfigsResourceResponseV0Deserializer>
    >{};

class AlterConfigsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterConfigsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AlterConfigsResourceResponseV1Deserializer>
    >{};

class AlterConfigsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterConfigsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<AlterConfigsResourceResponseV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class AlterConfigsResponseV0Parser:
  public ResponseDataParser<
    AlterConfigsResponse, AlterConfigsResponseV0Deserializer>{
public:
  AlterConfigsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterConfigsResponseV1Parser:
  public ResponseDataParser<
    AlterConfigsResponse, AlterConfigsResponseV1Deserializer>{
public:
  AlterConfigsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterConfigsResponseV2Parser:
  public ResponseDataParser<
    AlterConfigsResponse, AlterConfigsResponseV2Deserializer>{
public:
  AlterConfigsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AlterReplicaLogDirPartitionResult {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterReplicaLogDirPartitionResult(int32_t partition_index, int16_t error_code): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterReplicaLogDirPartitionResult(int32_t partition_index, int16_t error_code, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterReplicaLogDirPartitionResult& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterReplicaLogDirPartitionResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AlterReplicaLogDirPartitionResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};

class AlterReplicaLogDirPartitionResultV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterReplicaLogDirPartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterReplicaLogDirTopicResult {

  
  
  const std::string topic_name_;
  const std::vector<AlterReplicaLogDirPartitionResult> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterReplicaLogDirTopicResult(std::string topic_name, std::vector<AlterReplicaLogDirPartitionResult> partitions): topic_name_{topic_name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterReplicaLogDirTopicResult(std::string topic_name, std::vector<AlterReplicaLogDirPartitionResult> partitions, TaggedFields tagged_fields): topic_name_{topic_name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topic_name_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(topic_name_);
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
      written += encoder.encode(topic_name_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(topic_name_, dst);
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

  
  bool operator==(const AlterReplicaLogDirTopicResult& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterReplicaLogDirTopicResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AlterReplicaLogDirPartitionResultV0Deserializer>
    >{};

class AlterReplicaLogDirTopicResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirTopicResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<AlterReplicaLogDirPartitionResultV1Deserializer>
    >{};

class AlterReplicaLogDirTopicResultV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterReplicaLogDirTopicResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<AlterReplicaLogDirPartitionResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterReplicaLogDirsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<AlterReplicaLogDirTopicResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  AlterReplicaLogDirsResponse(int32_t throttle_time_ms, std::vector<AlterReplicaLogDirTopicResult> results): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  AlterReplicaLogDirsResponse(int32_t throttle_time_ms, std::vector<AlterReplicaLogDirTopicResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(results_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterReplicaLogDirsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterReplicaLogDirsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AlterReplicaLogDirTopicResultV0Deserializer>
    >{};

class AlterReplicaLogDirsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterReplicaLogDirsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<AlterReplicaLogDirTopicResultV1Deserializer>
    >{};

class AlterReplicaLogDirsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterReplicaLogDirsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<AlterReplicaLogDirTopicResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class AlterReplicaLogDirsResponseV0Parser:
  public ResponseDataParser<
    AlterReplicaLogDirsResponse, AlterReplicaLogDirsResponseV0Deserializer>{
public:
  AlterReplicaLogDirsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterReplicaLogDirsResponseV1Parser:
  public ResponseDataParser<
    AlterReplicaLogDirsResponse, AlterReplicaLogDirsResponseV1Deserializer>{
public:
  AlterReplicaLogDirsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterReplicaLogDirsResponseV2Parser:
  public ResponseDataParser<
    AlterReplicaLogDirsResponse, AlterReplicaLogDirsResponseV2Deserializer>{
public:
  AlterReplicaLogDirsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DescribeLogDirsPartition {

  
  
  const int32_t partition_index_;
  const int64_t partition_size_;
  const int64_t offset_lag_;
  const bool is_future_key_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeLogDirsPartition(int32_t partition_index, int64_t partition_size, int64_t offset_lag, bool is_future_key): partition_index_{partition_index}, partition_size_{partition_size}, offset_lag_{offset_lag}, is_future_key_{is_future_key}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  DescribeLogDirsPartition(int32_t partition_index, int64_t partition_size, int64_t offset_lag, bool is_future_key, TaggedFields tagged_fields): partition_index_{partition_index}, partition_size_{partition_size}, offset_lag_{offset_lag}, is_future_key_{is_future_key}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(partition_size_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(offset_lag_);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(is_future_key_);
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
      written += encoder.encode(partition_index_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(partition_size_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(offset_lag_, dst);
    }
    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.encode(is_future_key_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeLogDirsPartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && partition_size_ == rhs.partition_size_
    && offset_lag_ == rhs.offset_lag_
    && is_future_key_ == rhs.is_future_key_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeLogDirsPartitionV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeLogDirsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    >{};

class DescribeLogDirsPartitionV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeLogDirsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    >{};

class DescribeLogDirsPartitionV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeLogDirsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsPartitionV3Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeLogDirsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsPartitionV4Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeLogDirsPartition
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeLogDirsTopic {

  
  
  const std::string name_;
  const std::vector<DescribeLogDirsPartition> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeLogDirsTopic(std::string name, std::vector<DescribeLogDirsPartition> partitions): name_{name}, partitions_{partitions}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3, 4]
  DescribeLogDirsTopic(std::string name, std::vector<DescribeLogDirsPartition> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(name_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(name_);
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
      written += encoder.encode(name_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(name_, dst);
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

  
  bool operator==(const DescribeLogDirsTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeLogDirsTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeLogDirsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeLogDirsPartitionV0Deserializer>
    >{};

class DescribeLogDirsTopicV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeLogDirsTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeLogDirsPartitionV1Deserializer>
    >{};

class DescribeLogDirsTopicV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeLogDirsTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsPartitionV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsTopicV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeLogDirsTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsPartitionV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsTopicV4Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeLogDirsTopic
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsPartitionV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeLogDirsResult {

  
  
  const int16_t error_code_;
  const std::string log_dir_;
  const std::vector<DescribeLogDirsTopic> topics_;
  const int64_t total_bytes_;
  const int64_t usable_bytes_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeLogDirsResult(int16_t error_code, std::string log_dir, std::vector<DescribeLogDirsTopic> topics): error_code_{error_code}, log_dir_{log_dir}, topics_{topics}, total_bytes_{-1}, usable_bytes_{-1}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribeLogDirsResult(int16_t error_code, std::string log_dir, std::vector<DescribeLogDirsTopic> topics, TaggedFields tagged_fields): error_code_{error_code}, log_dir_{log_dir}, topics_{topics}, total_bytes_{-1}, usable_bytes_{-1}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [4]
  DescribeLogDirsResult(int16_t error_code, std::string log_dir, std::vector<DescribeLogDirsTopic> topics, int64_t total_bytes, int64_t usable_bytes, TaggedFields tagged_fields): error_code_{error_code}, log_dir_{log_dir}, topics_{topics}, total_bytes_{total_bytes}, usable_bytes_{usable_bytes}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(log_dir_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(log_dir_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(topics_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(topics_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(total_bytes_);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.computeSize(usable_bytes_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(log_dir_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(log_dir_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(topics_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(topics_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(total_bytes_, dst);
    }
    
    if (api_version >= 4 && api_version < 5) {
      written += encoder.encode(usable_bytes_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeLogDirsResult& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && log_dir_ == rhs.log_dir_
    && topics_ == rhs.topics_
    && total_bytes_ == rhs.total_bytes_
    && usable_bytes_ == rhs.usable_bytes_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeLogDirsResultV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeLogDirsResult
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeLogDirsTopicV0Deserializer>
    >{};

class DescribeLogDirsResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeLogDirsResult
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      ArrayDeserializer<DescribeLogDirsTopicV1Deserializer>
    >{};

class DescribeLogDirsResultV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeLogDirsResult
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsTopicV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsResultV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeLogDirsResult
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsTopicV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsResultV4Deserializer:
  public CompositeDeserializerWith6Delegates<
    DescribeLogDirsResult
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsTopicV4Deserializer>
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeLogDirsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<DescribeLogDirsResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeLogDirsResponse(int32_t throttle_time_ms, std::vector<DescribeLogDirsResult> results): throttle_time_ms_{throttle_time_ms}, error_code_{0}, results_{results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DescribeLogDirsResponse(int32_t throttle_time_ms, std::vector<DescribeLogDirsResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{0}, results_{results}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [3, 4]
  DescribeLogDirsResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<DescribeLogDirsResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 5) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(results_);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 3 && api_version < 5) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 5) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeLogDirsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeLogDirsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeLogDirsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribeLogDirsResultV0Deserializer>
    >{};

class DescribeLogDirsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeLogDirsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DescribeLogDirsResultV1Deserializer>
    >{};

class DescribeLogDirsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeLogDirsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsResponseV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeLogDirsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsResultV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeLogDirsResponseV4Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeLogDirsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<DescribeLogDirsResultV4Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeLogDirsResponseV0Parser:
  public ResponseDataParser<
    DescribeLogDirsResponse, DescribeLogDirsResponseV0Deserializer>{
public:
  DescribeLogDirsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeLogDirsResponseV1Parser:
  public ResponseDataParser<
    DescribeLogDirsResponse, DescribeLogDirsResponseV1Deserializer>{
public:
  DescribeLogDirsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeLogDirsResponseV2Parser:
  public ResponseDataParser<
    DescribeLogDirsResponse, DescribeLogDirsResponseV2Deserializer>{
public:
  DescribeLogDirsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeLogDirsResponseV3Parser:
  public ResponseDataParser<
    DescribeLogDirsResponse, DescribeLogDirsResponseV3Deserializer>{
public:
  DescribeLogDirsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeLogDirsResponseV4Parser:
  public ResponseDataParser<
    DescribeLogDirsResponse, DescribeLogDirsResponseV4Deserializer>{
public:
  DescribeLogDirsResponseV4Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct SaslAuthenticateResponse {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const Bytes auth_bytes_;
  const int64_t session_lifetime_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  SaslAuthenticateResponse(int16_t error_code, absl::optional<std::string> error_message, Bytes auth_bytes): error_code_{error_code}, error_message_{error_message}, auth_bytes_{auth_bytes}, session_lifetime_ms_{0}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  SaslAuthenticateResponse(int16_t error_code, absl::optional<std::string> error_message, Bytes auth_bytes, int64_t session_lifetime_ms): error_code_{error_code}, error_message_{error_message}, auth_bytes_{auth_bytes}, session_lifetime_ms_{session_lifetime_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  SaslAuthenticateResponse(int16_t error_code, absl::optional<std::string> error_message, Bytes auth_bytes, int64_t session_lifetime_ms, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, auth_bytes_{auth_bytes}, session_lifetime_ms_{session_lifetime_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(auth_bytes_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(auth_bytes_);
    }
    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.computeSize(session_lifetime_ms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(auth_bytes_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(auth_bytes_, dst);
    }
    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.encode(session_lifetime_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const SaslAuthenticateResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && auth_bytes_ == rhs.auth_bytes_
    && session_lifetime_ms_ == rhs.session_lifetime_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class SaslAuthenticateResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    SaslAuthenticateResponse
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      BytesDeserializer
    >{};

class SaslAuthenticateResponseV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    SaslAuthenticateResponse
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      BytesDeserializer
    ,
      Int64Deserializer
    >{};

class SaslAuthenticateResponseV2Deserializer:
  public CompositeDeserializerWith5Delegates<
    SaslAuthenticateResponse
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class SaslAuthenticateResponseV0Parser:
  public ResponseDataParser<
    SaslAuthenticateResponse, SaslAuthenticateResponseV0Deserializer>{
public:
  SaslAuthenticateResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SaslAuthenticateResponseV1Parser:
  public ResponseDataParser<
    SaslAuthenticateResponse, SaslAuthenticateResponseV1Deserializer>{
public:
  SaslAuthenticateResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class SaslAuthenticateResponseV2Parser:
  public ResponseDataParser<
    SaslAuthenticateResponse, SaslAuthenticateResponseV2Deserializer>{
public:
  SaslAuthenticateResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct CreatePartitionsTopicResult {

  
  
  const std::string name_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreatePartitionsTopicResult(std::string name, int16_t error_code, absl::optional<std::string> error_message): name_{name}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreatePartitionsTopicResult(std::string name, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): name_{name}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatePartitionsTopicResult& rhs) const {
  
    return true
    && name_ == rhs.name_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatePartitionsTopicResultV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class CreatePartitionsTopicResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsTopicResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class CreatePartitionsTopicResultV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreatePartitionsTopicResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreatePartitionsTopicResultV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    CreatePartitionsTopicResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct CreatePartitionsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<CreatePartitionsTopicResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreatePartitionsResponse(int32_t throttle_time_ms, std::vector<CreatePartitionsTopicResult> results): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  CreatePartitionsResponse(int32_t throttle_time_ms, std::vector<CreatePartitionsTopicResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(results_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreatePartitionsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreatePartitionsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatePartitionsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<CreatePartitionsTopicResultV0Deserializer>
    >{};

class CreatePartitionsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    CreatePartitionsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<CreatePartitionsTopicResultV1Deserializer>
    >{};

class CreatePartitionsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<CreatePartitionsTopicResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class CreatePartitionsResponseV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    CreatePartitionsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<CreatePartitionsTopicResultV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class CreatePartitionsResponseV0Parser:
  public ResponseDataParser<
    CreatePartitionsResponse, CreatePartitionsResponseV0Deserializer>{
public:
  CreatePartitionsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreatePartitionsResponseV1Parser:
  public ResponseDataParser<
    CreatePartitionsResponse, CreatePartitionsResponseV1Deserializer>{
public:
  CreatePartitionsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreatePartitionsResponseV2Parser:
  public ResponseDataParser<
    CreatePartitionsResponse, CreatePartitionsResponseV2Deserializer>{
public:
  CreatePartitionsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreatePartitionsResponseV3Parser:
  public ResponseDataParser<
    CreatePartitionsResponse, CreatePartitionsResponseV3Deserializer>{
public:
  CreatePartitionsResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct CreateDelegationTokenResponse {

  
  
  const int16_t error_code_;
  const std::string principal_type_;
  const std::string principal_name_;
  const std::string token_requester_principal_type_;
  const std::string token_requester_principal_name_;
  const int64_t issue_timestamp_ms_;
  const int64_t expiry_timestamp_ms_;
  const int64_t max_timestamp_ms_;
  const std::string token_id_;
  const Bytes hmac_;
  const int32_t throttle_time_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  CreateDelegationTokenResponse(int16_t error_code, std::string principal_type, std::string principal_name, int64_t issue_timestamp_ms, int64_t expiry_timestamp_ms, int64_t max_timestamp_ms, std::string token_id, Bytes hmac, int32_t throttle_time_ms): error_code_{error_code}, principal_type_{principal_type}, principal_name_{principal_name}, token_requester_principal_type_{""}, token_requester_principal_name_{""}, issue_timestamp_ms_{issue_timestamp_ms}, expiry_timestamp_ms_{expiry_timestamp_ms}, max_timestamp_ms_{max_timestamp_ms}, token_id_{token_id}, hmac_{hmac}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  CreateDelegationTokenResponse(int16_t error_code, std::string principal_type, std::string principal_name, int64_t issue_timestamp_ms, int64_t expiry_timestamp_ms, int64_t max_timestamp_ms, std::string token_id, Bytes hmac, int32_t throttle_time_ms, TaggedFields tagged_fields): error_code_{error_code}, principal_type_{principal_type}, principal_name_{principal_name}, token_requester_principal_type_{""}, token_requester_principal_name_{""}, issue_timestamp_ms_{issue_timestamp_ms}, expiry_timestamp_ms_{expiry_timestamp_ms}, max_timestamp_ms_{max_timestamp_ms}, token_id_{token_id}, hmac_{hmac}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [3]
  CreateDelegationTokenResponse(int16_t error_code, std::string principal_type, std::string principal_name, std::string token_requester_principal_type, std::string token_requester_principal_name, int64_t issue_timestamp_ms, int64_t expiry_timestamp_ms, int64_t max_timestamp_ms, std::string token_id, Bytes hmac, int32_t throttle_time_ms, TaggedFields tagged_fields): error_code_{error_code}, principal_type_{principal_type}, principal_name_{principal_name}, token_requester_principal_type_{token_requester_principal_type}, token_requester_principal_name_{token_requester_principal_name}, issue_timestamp_ms_{issue_timestamp_ms}, expiry_timestamp_ms_{expiry_timestamp_ms}, max_timestamp_ms_{max_timestamp_ms}, token_id_{token_id}, hmac_{hmac}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
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
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(token_requester_principal_type_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(token_requester_principal_name_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(issue_timestamp_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(expiry_timestamp_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(max_timestamp_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(token_id_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(token_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(hmac_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(hmac_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
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
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(token_requester_principal_type_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(token_requester_principal_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(issue_timestamp_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(expiry_timestamp_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(max_timestamp_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(token_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(token_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(hmac_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(hmac_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CreateDelegationTokenResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && principal_type_ == rhs.principal_type_
    && principal_name_ == rhs.principal_name_
    && token_requester_principal_type_ == rhs.token_requester_principal_type_
    && token_requester_principal_name_ == rhs.token_requester_principal_name_
    && issue_timestamp_ms_ == rhs.issue_timestamp_ms_
    && expiry_timestamp_ms_ == rhs.expiry_timestamp_ms_
    && max_timestamp_ms_ == rhs.max_timestamp_ms_
    && token_id_ == rhs.token_id_
    && hmac_ == rhs.hmac_
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CreateDelegationTokenResponseV0Deserializer:
  public CompositeDeserializerWith9Delegates<
    CreateDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      Int32Deserializer
    >{};

class CreateDelegationTokenResponseV1Deserializer:
  public CompositeDeserializerWith9Delegates<
    CreateDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      Int32Deserializer
    >{};

class CreateDelegationTokenResponseV2Deserializer:
  public CompositeDeserializerWith10Delegates<
    CreateDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class CreateDelegationTokenResponseV3Deserializer:
  public CompositeDeserializerWith12Delegates<
    CreateDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class CreateDelegationTokenResponseV0Parser:
  public ResponseDataParser<
    CreateDelegationTokenResponse, CreateDelegationTokenResponseV0Deserializer>{
public:
  CreateDelegationTokenResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateDelegationTokenResponseV1Parser:
  public ResponseDataParser<
    CreateDelegationTokenResponse, CreateDelegationTokenResponseV1Deserializer>{
public:
  CreateDelegationTokenResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateDelegationTokenResponseV2Parser:
  public ResponseDataParser<
    CreateDelegationTokenResponse, CreateDelegationTokenResponseV2Deserializer>{
public:
  CreateDelegationTokenResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class CreateDelegationTokenResponseV3Parser:
  public ResponseDataParser<
    CreateDelegationTokenResponse, CreateDelegationTokenResponseV3Deserializer>{
public:
  CreateDelegationTokenResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct RenewDelegationTokenResponse {

  
  
  const int16_t error_code_;
  const int64_t expiry_timestamp_ms_;
  const int32_t throttle_time_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  RenewDelegationTokenResponse(int16_t error_code, int64_t expiry_timestamp_ms, int32_t throttle_time_ms): error_code_{error_code}, expiry_timestamp_ms_{expiry_timestamp_ms}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  RenewDelegationTokenResponse(int16_t error_code, int64_t expiry_timestamp_ms, int32_t throttle_time_ms, TaggedFields tagged_fields): error_code_{error_code}, expiry_timestamp_ms_{expiry_timestamp_ms}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(expiry_timestamp_ms_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(expiry_timestamp_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const RenewDelegationTokenResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && expiry_timestamp_ms_ == rhs.expiry_timestamp_ms_
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class RenewDelegationTokenResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    RenewDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class RenewDelegationTokenResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    RenewDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class RenewDelegationTokenResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    RenewDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class RenewDelegationTokenResponseV0Parser:
  public ResponseDataParser<
    RenewDelegationTokenResponse, RenewDelegationTokenResponseV0Deserializer>{
public:
  RenewDelegationTokenResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class RenewDelegationTokenResponseV1Parser:
  public ResponseDataParser<
    RenewDelegationTokenResponse, RenewDelegationTokenResponseV1Deserializer>{
public:
  RenewDelegationTokenResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class RenewDelegationTokenResponseV2Parser:
  public ResponseDataParser<
    RenewDelegationTokenResponse, RenewDelegationTokenResponseV2Deserializer>{
public:
  RenewDelegationTokenResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ExpireDelegationTokenResponse {

  
  
  const int16_t error_code_;
  const int64_t expiry_timestamp_ms_;
  const int32_t throttle_time_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  ExpireDelegationTokenResponse(int16_t error_code, int64_t expiry_timestamp_ms, int32_t throttle_time_ms): error_code_{error_code}, expiry_timestamp_ms_{expiry_timestamp_ms}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  ExpireDelegationTokenResponse(int16_t error_code, int64_t expiry_timestamp_ms, int32_t throttle_time_ms, TaggedFields tagged_fields): error_code_{error_code}, expiry_timestamp_ms_{expiry_timestamp_ms}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(expiry_timestamp_ms_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(expiry_timestamp_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ExpireDelegationTokenResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && expiry_timestamp_ms_ == rhs.expiry_timestamp_ms_
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ExpireDelegationTokenResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ExpireDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class ExpireDelegationTokenResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ExpireDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    >{};

class ExpireDelegationTokenResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    ExpireDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class ExpireDelegationTokenResponseV0Parser:
  public ResponseDataParser<
    ExpireDelegationTokenResponse, ExpireDelegationTokenResponseV0Deserializer>{
public:
  ExpireDelegationTokenResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ExpireDelegationTokenResponseV1Parser:
  public ResponseDataParser<
    ExpireDelegationTokenResponse, ExpireDelegationTokenResponseV1Deserializer>{
public:
  ExpireDelegationTokenResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ExpireDelegationTokenResponseV2Parser:
  public ResponseDataParser<
    ExpireDelegationTokenResponse, ExpireDelegationTokenResponseV2Deserializer>{
public:
  ExpireDelegationTokenResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DescribedDelegationTokenRenewer {

  
  
  const std::string principal_type_;
  const std::string principal_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribedDelegationTokenRenewer(std::string principal_type, std::string principal_name): principal_type_{principal_type}, principal_name_{principal_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribedDelegationTokenRenewer(std::string principal_type, std::string principal_name, TaggedFields tagged_fields): principal_type_{principal_type}, principal_name_{principal_name}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const DescribedDelegationTokenRenewer& rhs) const {
  
    return true
    && principal_type_ == rhs.principal_type_
    && principal_name_ == rhs.principal_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribedDelegationTokenRenewerV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribedDelegationTokenRenewer
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class DescribedDelegationTokenRenewerV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribedDelegationTokenRenewer
    ,
      StringDeserializer
    ,
      StringDeserializer
    >{};

class DescribedDelegationTokenRenewerV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribedDelegationTokenRenewer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DescribedDelegationTokenRenewerV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribedDelegationTokenRenewer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribedDelegationToken {

  
  
  const std::string principal_type_;
  const std::string principal_name_;
  const std::string token_requester_principal_type_;
  const std::string token_requester_principal_name_;
  const int64_t issue_timestamp_;
  const int64_t expiry_timestamp_;
  const int64_t max_timestamp_;
  const std::string token_id_;
  const Bytes hmac_;
  const std::vector<DescribedDelegationTokenRenewer> renewers_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribedDelegationToken(std::string principal_type, std::string principal_name, int64_t issue_timestamp, int64_t expiry_timestamp, int64_t max_timestamp, std::string token_id, Bytes hmac, std::vector<DescribedDelegationTokenRenewer> renewers): principal_type_{principal_type}, principal_name_{principal_name}, token_requester_principal_type_{""}, token_requester_principal_name_{""}, issue_timestamp_{issue_timestamp}, expiry_timestamp_{expiry_timestamp}, max_timestamp_{max_timestamp}, token_id_{token_id}, hmac_{hmac}, renewers_{renewers}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DescribedDelegationToken(std::string principal_type, std::string principal_name, int64_t issue_timestamp, int64_t expiry_timestamp, int64_t max_timestamp, std::string token_id, Bytes hmac, std::vector<DescribedDelegationTokenRenewer> renewers, TaggedFields tagged_fields): principal_type_{principal_type}, principal_name_{principal_name}, token_requester_principal_type_{""}, token_requester_principal_name_{""}, issue_timestamp_{issue_timestamp}, expiry_timestamp_{expiry_timestamp}, max_timestamp_{max_timestamp}, token_id_{token_id}, hmac_{hmac}, renewers_{renewers}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [3]
  DescribedDelegationToken(std::string principal_type, std::string principal_name, std::string token_requester_principal_type, std::string token_requester_principal_name, int64_t issue_timestamp, int64_t expiry_timestamp, int64_t max_timestamp, std::string token_id, Bytes hmac, std::vector<DescribedDelegationTokenRenewer> renewers, TaggedFields tagged_fields): principal_type_{principal_type}, principal_name_{principal_name}, token_requester_principal_type_{token_requester_principal_type}, token_requester_principal_name_{token_requester_principal_name}, issue_timestamp_{issue_timestamp}, expiry_timestamp_{expiry_timestamp}, max_timestamp_{max_timestamp}, token_id_{token_id}, hmac_{hmac}, renewers_{renewers}, tagged_fields_{tagged_fields} {};

  
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
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(token_requester_principal_type_);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.computeCompactSize(token_requester_principal_name_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(issue_timestamp_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(expiry_timestamp_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(max_timestamp_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(token_id_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(token_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(hmac_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(hmac_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(renewers_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(renewers_);
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
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(token_requester_principal_type_, dst);
    }
    
    if (api_version >= 3 && api_version < 4) {
      written += encoder.encodeCompact(token_requester_principal_name_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(issue_timestamp_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(expiry_timestamp_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(max_timestamp_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(token_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(token_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(hmac_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(hmac_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(renewers_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(renewers_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribedDelegationToken& rhs) const {
  
    return true
    && principal_type_ == rhs.principal_type_
    && principal_name_ == rhs.principal_name_
    && token_requester_principal_type_ == rhs.token_requester_principal_type_
    && token_requester_principal_name_ == rhs.token_requester_principal_name_
    && issue_timestamp_ == rhs.issue_timestamp_
    && expiry_timestamp_ == rhs.expiry_timestamp_
    && max_timestamp_ == rhs.max_timestamp_
    && token_id_ == rhs.token_id_
    && hmac_ == rhs.hmac_
    && renewers_ == rhs.renewers_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribedDelegationTokenV0Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribedDelegationToken
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      ArrayDeserializer<DescribedDelegationTokenRenewerV0Deserializer>
    >{};

class DescribedDelegationTokenV1Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribedDelegationToken
    ,
      StringDeserializer
    ,
      StringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      StringDeserializer
    ,
      BytesDeserializer
    ,
      ArrayDeserializer<DescribedDelegationTokenRenewerV1Deserializer>
    >{};

class DescribedDelegationTokenV2Deserializer:
  public CompositeDeserializerWith9Delegates<
    DescribedDelegationToken
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      CompactArrayDeserializer<DescribedDelegationTokenRenewerV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribedDelegationTokenV3Deserializer:
  public CompositeDeserializerWith11Delegates<
    DescribedDelegationToken
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactBytesDeserializer
    ,
      CompactArrayDeserializer<DescribedDelegationTokenRenewerV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeDelegationTokenResponse {

  
  
  const int16_t error_code_;
  const std::vector<DescribedDelegationToken> tokens_;
  const int32_t throttle_time_ms_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeDelegationTokenResponse(int16_t error_code, std::vector<DescribedDelegationToken> tokens, int32_t throttle_time_ms): error_code_{error_code}, tokens_{tokens}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2, 3]
  DescribeDelegationTokenResponse(int16_t error_code, std::vector<DescribedDelegationToken> tokens, int32_t throttle_time_ms, TaggedFields tagged_fields): error_code_{error_code}, tokens_{tokens}, throttle_time_ms_{throttle_time_ms}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(tokens_);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.computeCompactSize(tokens_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(tokens_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tokens_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 2 && api_version < 4) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeDelegationTokenResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && tokens_ == rhs.tokens_
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeDelegationTokenResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<DescribedDelegationTokenV0Deserializer>
    ,
      Int32Deserializer
    >{};

class DescribeDelegationTokenResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<DescribedDelegationTokenV1Deserializer>
    ,
      Int32Deserializer
    >{};

class DescribeDelegationTokenResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<DescribedDelegationTokenV2Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeDelegationTokenResponseV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeDelegationTokenResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<DescribedDelegationTokenV3Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeDelegationTokenResponseV0Parser:
  public ResponseDataParser<
    DescribeDelegationTokenResponse, DescribeDelegationTokenResponseV0Deserializer>{
public:
  DescribeDelegationTokenResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeDelegationTokenResponseV1Parser:
  public ResponseDataParser<
    DescribeDelegationTokenResponse, DescribeDelegationTokenResponseV1Deserializer>{
public:
  DescribeDelegationTokenResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeDelegationTokenResponseV2Parser:
  public ResponseDataParser<
    DescribeDelegationTokenResponse, DescribeDelegationTokenResponseV2Deserializer>{
public:
  DescribeDelegationTokenResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeDelegationTokenResponseV3Parser:
  public ResponseDataParser<
    DescribeDelegationTokenResponse, DescribeDelegationTokenResponseV3Deserializer>{
public:
  DescribeDelegationTokenResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DeletableGroupResult {

  
  
  const std::string group_id_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeletableGroupResult(std::string group_id, int16_t error_code): group_id_{group_id}, error_code_{error_code}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeletableGroupResult(std::string group_id, int16_t error_code, TaggedFields tagged_fields): group_id_{group_id}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(group_id_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(group_id_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(group_id_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(group_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeletableGroupResult& rhs) const {
  
    return true
    && group_id_ == rhs.group_id_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeletableGroupResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeletableGroupResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class DeletableGroupResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeletableGroupResult
    ,
      StringDeserializer
    ,
      Int16Deserializer
    >{};

class DeletableGroupResultV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeletableGroupResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DeleteGroupsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<DeletableGroupResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DeleteGroupsResponse(int32_t throttle_time_ms, std::vector<DeletableGroupResult> results): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  DeleteGroupsResponse(int32_t throttle_time_ms, std::vector<DeletableGroupResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(results_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DeleteGroupsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DeleteGroupsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteGroupsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeletableGroupResultV0Deserializer>
    >{};

class DeleteGroupsResponseV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    DeleteGroupsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<DeletableGroupResultV1Deserializer>
    >{};

class DeleteGroupsResponseV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    DeleteGroupsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DeletableGroupResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DeleteGroupsResponseV0Parser:
  public ResponseDataParser<
    DeleteGroupsResponse, DeleteGroupsResponseV0Deserializer>{
public:
  DeleteGroupsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteGroupsResponseV1Parser:
  public ResponseDataParser<
    DeleteGroupsResponse, DeleteGroupsResponseV1Deserializer>{
public:
  DeleteGroupsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DeleteGroupsResponseV2Parser:
  public ResponseDataParser<
    DeleteGroupsResponse, DeleteGroupsResponseV2Deserializer>{
public:
  DeleteGroupsResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct PartitionResult {

  
  
  const int32_t partition_id_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  PartitionResult(int32_t partition_id, int16_t error_code, absl::optional<std::string> error_message): partition_id_{partition_id}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  PartitionResult(int32_t partition_id, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): partition_id_{partition_id}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(partition_id_);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encode(partition_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const PartitionResult& rhs) const {
  
    return true
    && partition_id_ == rhs.partition_id_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class PartitionResultV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    PartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class PartitionResultV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    PartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    >{};

class PartitionResultV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    PartitionResult
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ReplicaElectionResult {

  
  
  const std::string topic_;
  const std::vector<PartitionResult> partition_result_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  ReplicaElectionResult(std::string topic, std::vector<PartitionResult> partition_result): topic_{topic}, partition_result_{partition_result}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  ReplicaElectionResult(std::string topic, std::vector<PartitionResult> partition_result, TaggedFields tagged_fields): topic_{topic}, partition_result_{partition_result}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(partition_result_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(partition_result_);
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
      written += encoder.encode(partition_result_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(partition_result_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ReplicaElectionResult& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && partition_result_ == rhs.partition_result_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ReplicaElectionResultV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ReplicaElectionResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionResultV0Deserializer>
    >{};

class ReplicaElectionResultV1Deserializer:
  public CompositeDeserializerWith2Delegates<
    ReplicaElectionResult
    ,
      StringDeserializer
    ,
      ArrayDeserializer<PartitionResultV1Deserializer>
    >{};

class ReplicaElectionResultV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ReplicaElectionResult
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<PartitionResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ElectLeadersResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<ReplicaElectionResult> replica_election_results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ElectLeadersResponse(int32_t throttle_time_ms, std::vector<ReplicaElectionResult> replica_election_results): throttle_time_ms_{throttle_time_ms}, error_code_{0}, replica_election_results_{replica_election_results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  ElectLeadersResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<ReplicaElectionResult> replica_election_results): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, replica_election_results_{replica_election_results}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [2]
  ElectLeadersResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<ReplicaElectionResult> replica_election_results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, replica_election_results_{replica_election_results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 3) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(replica_election_results_);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.computeCompactSize(replica_election_results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 1 && api_version < 3) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(replica_election_results_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(replica_election_results_, dst);
    }
    
    if (api_version >= 2 && api_version < 3) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ElectLeadersResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && replica_election_results_ == rhs.replica_election_results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ElectLeadersResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ElectLeadersResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ReplicaElectionResultV0Deserializer>
    >{};

class ElectLeadersResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ElectLeadersResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<ReplicaElectionResultV1Deserializer>
    >{};

class ElectLeadersResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    ElectLeadersResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ReplicaElectionResultV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class ElectLeadersResponseV0Parser:
  public ResponseDataParser<
    ElectLeadersResponse, ElectLeadersResponseV0Deserializer>{
public:
  ElectLeadersResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ElectLeadersResponseV1Parser:
  public ResponseDataParser<
    ElectLeadersResponse, ElectLeadersResponseV1Deserializer>{
public:
  ElectLeadersResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class ElectLeadersResponseV2Parser:
  public ResponseDataParser<
    ElectLeadersResponse, ElectLeadersResponseV2Deserializer>{
public:
  ElectLeadersResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct IncrementalAlterConfigsResponseAlterConfigsResourceResponse {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const int8_t resource_type_;
  const std::string resource_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  IncrementalAlterConfigsResponseAlterConfigsResourceResponse(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  IncrementalAlterConfigsResponseAlterConfigsResourceResponse(int16_t error_code, absl::optional<std::string> error_message, int8_t resource_type, std::string resource_name, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, resource_type_{resource_type}, resource_name_{resource_name}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(resource_type_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(resource_name_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(resource_name_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(resource_type_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(resource_name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(resource_name_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const IncrementalAlterConfigsResponseAlterConfigsResourceResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && resource_type_ == rhs.resource_type_
    && resource_name_ == rhs.resource_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class IncrementalAlterConfigsResponseAlterConfigsResourceResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    IncrementalAlterConfigsResponseAlterConfigsResourceResponse
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      Int8Deserializer
    ,
      StringDeserializer
    >{};

class IncrementalAlterConfigsResponseAlterConfigsResourceResponseV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    IncrementalAlterConfigsResponseAlterConfigsResourceResponse
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      Int8Deserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct IncrementalAlterConfigsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<IncrementalAlterConfigsResponseAlterConfigsResourceResponse> responses_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  IncrementalAlterConfigsResponse(int32_t throttle_time_ms, std::vector<IncrementalAlterConfigsResponseAlterConfigsResourceResponse> responses): throttle_time_ms_{throttle_time_ms}, responses_{responses}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  IncrementalAlterConfigsResponse(int32_t throttle_time_ms, std::vector<IncrementalAlterConfigsResponseAlterConfigsResourceResponse> responses, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, responses_{responses}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(responses_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(responses_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(responses_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(responses_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const IncrementalAlterConfigsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && responses_ == rhs.responses_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class IncrementalAlterConfigsResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    IncrementalAlterConfigsResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<IncrementalAlterConfigsResponseAlterConfigsResourceResponseV0Deserializer>
    >{};

class IncrementalAlterConfigsResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    IncrementalAlterConfigsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<IncrementalAlterConfigsResponseAlterConfigsResourceResponseV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class IncrementalAlterConfigsResponseV0Parser:
  public ResponseDataParser<
    IncrementalAlterConfigsResponse, IncrementalAlterConfigsResponseV0Deserializer>{
public:
  IncrementalAlterConfigsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class IncrementalAlterConfigsResponseV1Parser:
  public ResponseDataParser<
    IncrementalAlterConfigsResponse, IncrementalAlterConfigsResponseV1Deserializer>{
public:
  IncrementalAlterConfigsResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ReassignablePartitionResponse {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ReassignablePartitionResponse(int32_t partition_index, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ReassignablePartitionResponse& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ReassignablePartitionResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    ReassignablePartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ReassignableTopicResponse {

  
  
  const std::string name_;
  const std::vector<ReassignablePartitionResponse> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ReassignableTopicResponse(std::string name, std::vector<ReassignablePartitionResponse> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const ReassignableTopicResponse& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ReassignableTopicResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ReassignableTopicResponse
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ReassignablePartitionResponseV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterPartitionReassignmentsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<ReassignableTopicResponse> responses_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AlterPartitionReassignmentsResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, std::vector<ReassignableTopicResponse> responses, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, responses_{responses}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(responses_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(responses_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterPartitionReassignmentsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && responses_ == rhs.responses_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterPartitionReassignmentsResponseV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    AlterPartitionReassignmentsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<ReassignableTopicResponseV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class AlterPartitionReassignmentsResponseV0Parser:
  public ResponseDataParser<
    AlterPartitionReassignmentsResponse, AlterPartitionReassignmentsResponseV0Deserializer>{
public:
  AlterPartitionReassignmentsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct OngoingPartitionReassignment {

  
  
  const int32_t partition_index_;
  const std::vector<int32_t> replicas_;
  const std::vector<int32_t> adding_replicas_;
  const std::vector<int32_t> removing_replicas_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  OngoingPartitionReassignment(int32_t partition_index, std::vector<int32_t> replicas, std::vector<int32_t> adding_replicas, std::vector<int32_t> removing_replicas, TaggedFields tagged_fields): partition_index_{partition_index}, replicas_{replicas}, adding_replicas_{adding_replicas}, removing_replicas_{removing_replicas}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeCompactSize(adding_replicas_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(removing_replicas_);
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
      written += encoder.encodeCompact(adding_replicas_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(removing_replicas_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OngoingPartitionReassignment& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && replicas_ == rhs.replicas_
    && adding_replicas_ == rhs.adding_replicas_
    && removing_replicas_ == rhs.removing_replicas_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OngoingPartitionReassignmentV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    OngoingPartitionReassignment
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct OngoingTopicReassignment {

  
  
  const std::string name_;
  const std::vector<OngoingPartitionReassignment> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  OngoingTopicReassignment(std::string name, std::vector<OngoingPartitionReassignment> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const OngoingTopicReassignment& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class OngoingTopicReassignmentV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    OngoingTopicReassignment
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<OngoingPartitionReassignmentV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct ListPartitionReassignmentsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<OngoingTopicReassignment> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListPartitionReassignmentsResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, std::vector<OngoingTopicReassignment> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
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

  
  bool operator==(const ListPartitionReassignmentsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListPartitionReassignmentsResponseV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    ListPartitionReassignmentsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<OngoingTopicReassignmentV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class ListPartitionReassignmentsResponseV0Parser:
  public ResponseDataParser<
    ListPartitionReassignmentsResponse, ListPartitionReassignmentsResponseV0Deserializer>{
public:
  ListPartitionReassignmentsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct OffsetDeleteResponsePartition {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  
  // constructor used in versions: [0]
  OffsetDeleteResponsePartition(int32_t partition_index, int16_t error_code): partition_index_{partition_index}, error_code_{error_code} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetDeleteResponsePartition& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_;
  };

};



class OffsetDeleteResponsePartitionV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetDeleteResponsePartition
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    >{};


struct OffsetDeleteResponseTopic {

  
  
  const std::string name_;
  const std::vector<OffsetDeleteResponsePartition> partitions_;
  
  // constructor used in versions: [0]
  OffsetDeleteResponseTopic(std::string name, std::vector<OffsetDeleteResponsePartition> partitions): name_{name}, partitions_{partitions} {};

  
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

  
  bool operator==(const OffsetDeleteResponseTopic& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_;
  };

};



class OffsetDeleteResponseTopicV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    OffsetDeleteResponseTopic
    ,
      StringDeserializer
    ,
      ArrayDeserializer<OffsetDeleteResponsePartitionV0Deserializer>
    >{};


struct OffsetDeleteResponse {

  
  
  const int16_t error_code_;
  const int32_t throttle_time_ms_;
  const std::vector<OffsetDeleteResponseTopic> topics_;
  
  // constructor used in versions: [0]
  OffsetDeleteResponse(int16_t error_code, int32_t throttle_time_ms, std::vector<OffsetDeleteResponseTopic> topics): error_code_{error_code}, throttle_time_ms_{throttle_time_ms}, topics_{topics} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const OffsetDeleteResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_;
  };

};



class OffsetDeleteResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    OffsetDeleteResponse
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<OffsetDeleteResponseTopicV0Deserializer>
    >{};



class OffsetDeleteResponseV0Parser:
  public ResponseDataParser<
    OffsetDeleteResponse, OffsetDeleteResponseV0Deserializer>{
public:
  OffsetDeleteResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DescribeClientQuotasResponseResponseEntityData {

  
  
  const std::string entity_type_;
  const absl::optional<std::string> entity_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeClientQuotasResponseResponseEntityData(std::string entity_type, absl::optional<std::string> entity_name): entity_type_{entity_type}, entity_name_{entity_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DescribeClientQuotasResponseResponseEntityData(std::string entity_type, absl::optional<std::string> entity_name, TaggedFields tagged_fields): entity_type_{entity_type}, entity_name_{entity_name}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const DescribeClientQuotasResponseResponseEntityData& rhs) const {
  
    return true
    && entity_type_ == rhs.entity_type_
    && entity_name_ == rhs.entity_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeClientQuotasResponseResponseEntityDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeClientQuotasResponseResponseEntityData
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class DescribeClientQuotasResponseResponseEntityDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeClientQuotasResponseResponseEntityData
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ValueData {

  
  
  const std::string key_;
  const double value_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ValueData(std::string key, double value): key_{key}, value_{value}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  ValueData(std::string key, double value, TaggedFields tagged_fields): key_{key}, value_{value}, tagged_fields_{tagged_fields} {};

  
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
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ValueData& rhs) const {
  
    return true
    && key_ == rhs.key_
    && value_ == rhs.value_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ValueDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ValueData
    ,
      StringDeserializer
    ,
      Float64Deserializer
    >{};

class ValueDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ValueData
    ,
      CompactStringDeserializer
    ,
      Float64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeClientQuotasResponseResponseEntryData {

  
  
  const std::vector<DescribeClientQuotasResponseResponseEntityData> entity_;
  const std::vector<ValueData> values_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeClientQuotasResponseResponseEntryData(std::vector<DescribeClientQuotasResponseResponseEntityData> entity, std::vector<ValueData> values): entity_{entity}, values_{values}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DescribeClientQuotasResponseResponseEntryData(std::vector<DescribeClientQuotasResponseResponseEntityData> entity, std::vector<ValueData> values, TaggedFields tagged_fields): entity_{entity}, values_{values}, tagged_fields_{tagged_fields} {};

  
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
      written += encoder.computeSize(values_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(values_);
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
      written += encoder.encode(values_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(values_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeClientQuotasResponseResponseEntryData& rhs) const {
  
    return true
    && entity_ == rhs.entity_
    && values_ == rhs.values_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeClientQuotasResponseResponseEntryDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    DescribeClientQuotasResponseResponseEntryData
    ,
      ArrayDeserializer<DescribeClientQuotasResponseResponseEntityDataV0Deserializer>
    ,
      ArrayDeserializer<ValueDataV0Deserializer>
    >{};

class DescribeClientQuotasResponseResponseEntryDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeClientQuotasResponseResponseEntryData
    ,
      CompactArrayDeserializer<DescribeClientQuotasResponseResponseEntityDataV1Deserializer>
    ,
      CompactArrayDeserializer<ValueDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeClientQuotasResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const absl::optional<std::vector<DescribeClientQuotasResponseResponseEntryData>> entries_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeClientQuotasResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, absl::optional<std::vector<DescribeClientQuotasResponseResponseEntryData>> entries): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, entries_{entries}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  DescribeClientQuotasResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, absl::optional<std::vector<DescribeClientQuotasResponseResponseEntryData>> entries, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, entries_{entries}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entries_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entries_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entries_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entries_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeClientQuotasResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && entries_ == rhs.entries_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeClientQuotasResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    DescribeClientQuotasResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      NullableArrayDeserializer<DescribeClientQuotasResponseResponseEntryDataV0Deserializer>
    >{};

class DescribeClientQuotasResponseV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeClientQuotasResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      NullableCompactArrayDeserializer<DescribeClientQuotasResponseResponseEntryDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeClientQuotasResponseV0Parser:
  public ResponseDataParser<
    DescribeClientQuotasResponse, DescribeClientQuotasResponseV0Deserializer>{
public:
  DescribeClientQuotasResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeClientQuotasResponseV1Parser:
  public ResponseDataParser<
    DescribeClientQuotasResponse, DescribeClientQuotasResponseV1Deserializer>{
public:
  DescribeClientQuotasResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ResponseEntityData {

  
  
  const std::string entity_type_;
  const absl::optional<std::string> entity_name_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ResponseEntityData(std::string entity_type, absl::optional<std::string> entity_name): entity_type_{entity_type}, entity_name_{entity_name}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  ResponseEntityData(std::string entity_type, absl::optional<std::string> entity_name, TaggedFields tagged_fields): entity_type_{entity_type}, entity_name_{entity_name}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const ResponseEntityData& rhs) const {
  
    return true
    && entity_type_ == rhs.entity_type_
    && entity_name_ == rhs.entity_name_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ResponseEntityDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    ResponseEntityData
    ,
      StringDeserializer
    ,
      NullableStringDeserializer
    >{};

class ResponseEntityDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseEntityData
    ,
      CompactStringDeserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ResponseEntryData {

  
  
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<ResponseEntityData> entity_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ResponseEntryData(int16_t error_code, absl::optional<std::string> error_message, std::vector<ResponseEntityData> entity): error_code_{error_code}, error_message_{error_message}, entity_{entity}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  ResponseEntryData(int16_t error_code, absl::optional<std::string> error_message, std::vector<ResponseEntityData> entity, TaggedFields tagged_fields): error_code_{error_code}, error_message_{error_message}, entity_{entity}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_message_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entity_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entity_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_message_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entity_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entity_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ResponseEntryData& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && entity_ == rhs.entity_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ResponseEntryDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseEntryData
    ,
      Int16Deserializer
    ,
      NullableStringDeserializer
    ,
      ArrayDeserializer<ResponseEntityDataV0Deserializer>
    >{};

class ResponseEntryDataV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    ResponseEntryData
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<ResponseEntityDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterClientQuotasResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<ResponseEntryData> entries_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AlterClientQuotasResponse(int32_t throttle_time_ms, std::vector<ResponseEntryData> entries): throttle_time_ms_{throttle_time_ms}, entries_{entries}, tagged_fields_{TaggedFields({})} {};
  // constructor used in versions: [1]
  AlterClientQuotasResponse(int32_t throttle_time_ms, std::vector<ResponseEntryData> entries, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, entries_{entries}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(entries_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeCompactSize(entries_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(entries_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(entries_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterClientQuotasResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && entries_ == rhs.entries_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterClientQuotasResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    AlterClientQuotasResponse
    ,
      Int32Deserializer
    ,
      ArrayDeserializer<ResponseEntryDataV0Deserializer>
    >{};

class AlterClientQuotasResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterClientQuotasResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<ResponseEntryDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class AlterClientQuotasResponseV0Parser:
  public ResponseDataParser<
    AlterClientQuotasResponse, AlterClientQuotasResponseV0Deserializer>{
public:
  AlterClientQuotasResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterClientQuotasResponseV1Parser:
  public ResponseDataParser<
    AlterClientQuotasResponse, AlterClientQuotasResponseV1Deserializer>{
public:
  AlterClientQuotasResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct CredentialInfo {

  
  
  const int8_t mechanism_;
  const int32_t iterations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  CredentialInfo(int8_t mechanism, int32_t iterations, TaggedFields tagged_fields): mechanism_{mechanism}, iterations_{iterations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(mechanism_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(iterations_);
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
      written += encoder.encode(mechanism_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(iterations_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const CredentialInfo& rhs) const {
  
    return true
    && mechanism_ == rhs.mechanism_
    && iterations_ == rhs.iterations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class CredentialInfoV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    CredentialInfo
    ,
      Int8Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeUserScramCredentialsResult {

  
  
  const std::string user_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<CredentialInfo> credential_infos_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeUserScramCredentialsResult(std::string user, int16_t error_code, absl::optional<std::string> error_message, std::vector<CredentialInfo> credential_infos, TaggedFields tagged_fields): user_{user}, error_code_{error_code}, error_message_{error_message}, credential_infos_{credential_infos}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(user_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(credential_infos_);
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
      written += encoder.encodeCompact(user_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(credential_infos_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeUserScramCredentialsResult& rhs) const {
  
    return true
    && user_ == rhs.user_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && credential_infos_ == rhs.credential_infos_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeUserScramCredentialsResultV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeUserScramCredentialsResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<CredentialInfoV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeUserScramCredentialsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<DescribeUserScramCredentialsResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeUserScramCredentialsResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, std::vector<DescribeUserScramCredentialsResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeUserScramCredentialsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeUserScramCredentialsResponseV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeUserScramCredentialsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeUserScramCredentialsResultV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeUserScramCredentialsResponseV0Parser:
  public ResponseDataParser<
    DescribeUserScramCredentialsResponse, DescribeUserScramCredentialsResponseV0Deserializer>{
public:
  DescribeUserScramCredentialsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AlterUserScramCredentialsResult {

  
  
  const std::string user_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AlterUserScramCredentialsResult(std::string user, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): user_{user}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(user_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encodeCompact(user_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterUserScramCredentialsResult& rhs) const {
  
    return true
    && user_ == rhs.user_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterUserScramCredentialsResultV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterUserScramCredentialsResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterUserScramCredentialsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<AlterUserScramCredentialsResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AlterUserScramCredentialsResponse(int32_t throttle_time_ms, std::vector<AlterUserScramCredentialsResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AlterUserScramCredentialsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterUserScramCredentialsResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    AlterUserScramCredentialsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<AlterUserScramCredentialsResultV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class AlterUserScramCredentialsResponseV0Parser:
  public ResponseDataParser<
    AlterUserScramCredentialsResponse, AlterUserScramCredentialsResponseV0Deserializer>{
public:
  AlterUserScramCredentialsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct VoteResponseResponsePartitionData {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  const bool vote_granted_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  VoteResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int32_t leader_id, int32_t leader_epoch, bool vote_granted, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, leader_id_{leader_id}, leader_epoch_{leader_epoch}, vote_granted_{vote_granted}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(leader_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(vote_granted_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(leader_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(vote_granted_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const VoteResponseResponsePartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_
    && vote_granted_ == rhs.vote_granted_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class VoteResponseResponsePartitionDataV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    VoteResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct VoteResponseResponseTopicData {

  
  
  const std::string topic_name_;
  const std::vector<VoteResponseResponsePartitionData> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  VoteResponseResponseTopicData(std::string topic_name, std::vector<VoteResponseResponsePartitionData> partitions, TaggedFields tagged_fields): topic_name_{topic_name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const VoteResponseResponseTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class VoteResponseResponseTopicDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    VoteResponseResponseTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<VoteResponseResponsePartitionDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct VoteResponse {

  
  
  const int16_t error_code_;
  const std::vector<VoteResponseResponseTopicData> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  VoteResponse(int16_t error_code, std::vector<VoteResponseResponseTopicData> topics, TaggedFields tagged_fields): error_code_{error_code}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
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

  
  bool operator==(const VoteResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class VoteResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    VoteResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<VoteResponseResponseTopicDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class VoteResponseV0Parser:
  public ResponseDataParser<
    VoteResponse, VoteResponseV0Deserializer>{
public:
  VoteResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct BeginQuorumEpochResponseResponsePartitionData {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  
  // constructor used in versions: [0]
  BeginQuorumEpochResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int32_t leader_id, int32_t leader_epoch): partition_index_{partition_index}, error_code_{error_code}, leader_id_{leader_id}, leader_epoch_{leader_epoch} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
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

  
  bool operator==(const BeginQuorumEpochResponseResponsePartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_;
  };

};



class BeginQuorumEpochResponseResponsePartitionDataV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    BeginQuorumEpochResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    >{};


struct BeginQuorumEpochResponseResponseTopicData {

  
  
  const std::string topic_name_;
  const std::vector<BeginQuorumEpochResponseResponsePartitionData> partitions_;
  
  // constructor used in versions: [0]
  BeginQuorumEpochResponseResponseTopicData(std::string topic_name, std::vector<BeginQuorumEpochResponseResponsePartitionData> partitions): topic_name_{topic_name}, partitions_{partitions} {};

  
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

  
  bool operator==(const BeginQuorumEpochResponseResponseTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_;
  };

};



class BeginQuorumEpochResponseResponseTopicDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    BeginQuorumEpochResponseResponseTopicData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<BeginQuorumEpochResponseResponsePartitionDataV0Deserializer>
    >{};


struct BeginQuorumEpochResponse {

  
  
  const int16_t error_code_;
  const std::vector<BeginQuorumEpochResponseResponseTopicData> topics_;
  
  // constructor used in versions: [0]
  BeginQuorumEpochResponse(int16_t error_code, std::vector<BeginQuorumEpochResponseResponseTopicData> topics): error_code_{error_code}, topics_{topics} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BeginQuorumEpochResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && topics_ == rhs.topics_;
  };

};



class BeginQuorumEpochResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    BeginQuorumEpochResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<BeginQuorumEpochResponseResponseTopicDataV0Deserializer>
    >{};



class BeginQuorumEpochResponseV0Parser:
  public ResponseDataParser<
    BeginQuorumEpochResponse, BeginQuorumEpochResponseV0Deserializer>{
public:
  BeginQuorumEpochResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct EndQuorumEpochResponseResponsePartitionData {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  
  // constructor used in versions: [0]
  EndQuorumEpochResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int32_t leader_id, int32_t leader_epoch): partition_index_{partition_index}, error_code_{error_code}, leader_id_{leader_id}, leader_epoch_{leader_epoch} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
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

  
  bool operator==(const EndQuorumEpochResponseResponsePartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_;
  };

};



class EndQuorumEpochResponseResponsePartitionDataV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    EndQuorumEpochResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    >{};


struct EndQuorumEpochResponseResponseTopicData {

  
  
  const std::string topic_name_;
  const std::vector<EndQuorumEpochResponseResponsePartitionData> partitions_;
  
  // constructor used in versions: [0]
  EndQuorumEpochResponseResponseTopicData(std::string topic_name, std::vector<EndQuorumEpochResponseResponsePartitionData> partitions): topic_name_{topic_name}, partitions_{partitions} {};

  
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

  
  bool operator==(const EndQuorumEpochResponseResponseTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_;
  };

};



class EndQuorumEpochResponseResponseTopicDataV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    EndQuorumEpochResponseResponseTopicData
    ,
      StringDeserializer
    ,
      ArrayDeserializer<EndQuorumEpochResponseResponsePartitionDataV0Deserializer>
    >{};


struct EndQuorumEpochResponse {

  
  
  const int16_t error_code_;
  const std::vector<EndQuorumEpochResponseResponseTopicData> topics_;
  
  // constructor used in versions: [0]
  EndQuorumEpochResponse(int16_t error_code, std::vector<EndQuorumEpochResponseResponseTopicData> topics): error_code_{error_code}, topics_{topics} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(topics_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EndQuorumEpochResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && topics_ == rhs.topics_;
  };

};



class EndQuorumEpochResponseV0Deserializer:
  public CompositeDeserializerWith2Delegates<
    EndQuorumEpochResponse
    ,
      Int16Deserializer
    ,
      ArrayDeserializer<EndQuorumEpochResponseResponseTopicDataV0Deserializer>
    >{};



class EndQuorumEpochResponseV0Parser:
  public ResponseDataParser<
    EndQuorumEpochResponse, EndQuorumEpochResponseV0Deserializer>{
public:
  EndQuorumEpochResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ReplicaState {

  
  
  const int32_t replica_id_;
  const int64_t log_end_offset_;
  const int64_t last_fetch_timestamp_;
  const int64_t last_caught_up_timestamp_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ReplicaState(int32_t replica_id, int64_t log_end_offset, TaggedFields tagged_fields): replica_id_{replica_id}, log_end_offset_{log_end_offset}, last_fetch_timestamp_{-1}, last_caught_up_timestamp_{-1}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [1]
  ReplicaState(int32_t replica_id, int64_t log_end_offset, int64_t last_fetch_timestamp, int64_t last_caught_up_timestamp, TaggedFields tagged_fields): replica_id_{replica_id}, log_end_offset_{log_end_offset}, last_fetch_timestamp_{last_fetch_timestamp}, last_caught_up_timestamp_{last_caught_up_timestamp}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(replica_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(log_end_offset_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(last_fetch_timestamp_);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.computeSize(last_caught_up_timestamp_);
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
      written += encoder.encode(replica_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(log_end_offset_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(last_fetch_timestamp_, dst);
    }
    
    if (api_version >= 1 && api_version < 2) {
      written += encoder.encode(last_caught_up_timestamp_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ReplicaState& rhs) const {
  
    return true
    && replica_id_ == rhs.replica_id_
    && log_end_offset_ == rhs.log_end_offset_
    && last_fetch_timestamp_ == rhs.last_fetch_timestamp_
    && last_caught_up_timestamp_ == rhs.last_caught_up_timestamp_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ReplicaStateV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ReplicaState
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class ReplicaStateV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    ReplicaState
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeQuorumResponseResponsePartitionData {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  const int64_t high_watermark_;
  const std::vector<ReplicaState> current_voters_;
  const std::vector<ReplicaState> observers_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeQuorumResponseResponsePartitionData(int32_t partition_index, int16_t error_code, int32_t leader_id, int32_t leader_epoch, int64_t high_watermark, std::vector<ReplicaState> current_voters, std::vector<ReplicaState> observers, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, leader_id_{leader_id}, leader_epoch_{leader_epoch}, high_watermark_{high_watermark}, current_voters_{current_voters}, observers_{observers}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(leader_id_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(high_watermark_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(current_voters_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(observers_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(leader_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(high_watermark_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(current_voters_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(observers_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeQuorumResponseResponsePartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_
    && high_watermark_ == rhs.high_watermark_
    && current_voters_ == rhs.current_voters_
    && observers_ == rhs.observers_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeQuorumResponseResponsePartitionDataV0Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribeQuorumResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<ReplicaStateV0Deserializer>
    ,
      CompactArrayDeserializer<ReplicaStateV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeQuorumResponseResponsePartitionDataV1Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribeQuorumResponseResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int32Deserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      CompactArrayDeserializer<ReplicaStateV1Deserializer>
    ,
      CompactArrayDeserializer<ReplicaStateV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeQuorumResponseResponseTopicData {

  
  
  const std::string topic_name_;
  const std::vector<DescribeQuorumResponseResponsePartitionData> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeQuorumResponseResponseTopicData(std::string topic_name, std::vector<DescribeQuorumResponseResponsePartitionData> partitions, TaggedFields tagged_fields): topic_name_{topic_name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const DescribeQuorumResponseResponseTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeQuorumResponseResponseTopicDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeQuorumResponseResponseTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeQuorumResponseResponsePartitionDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeQuorumResponseResponseTopicDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeQuorumResponseResponseTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<DescribeQuorumResponseResponsePartitionDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeQuorumResponse {

  
  
  const int16_t error_code_;
  const std::vector<DescribeQuorumResponseResponseTopicData> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  DescribeQuorumResponse(int16_t error_code, std::vector<DescribeQuorumResponseResponseTopicData> topics, TaggedFields tagged_fields): error_code_{error_code}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
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
      written += encoder.encode(error_code_, dst);
    }
    
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

  
  bool operator==(const DescribeQuorumResponse& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeQuorumResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeQuorumResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<DescribeQuorumResponseResponseTopicDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class DescribeQuorumResponseV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeQuorumResponse
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<DescribeQuorumResponseResponseTopicDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeQuorumResponseV0Parser:
  public ResponseDataParser<
    DescribeQuorumResponse, DescribeQuorumResponseV0Deserializer>{
public:
  DescribeQuorumResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class DescribeQuorumResponseV1Parser:
  public ResponseDataParser<
    DescribeQuorumResponse, DescribeQuorumResponseV1Deserializer>{
public:
  DescribeQuorumResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ResponsePartitionData {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const int32_t leader_id_;
  const int32_t leader_epoch_;
  const std::vector<int32_t> isr_;
  const int8_t leader_recovery_state_;
  const int32_t partition_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ResponsePartitionData(int32_t partition_index, int16_t error_code, int32_t leader_id, int32_t leader_epoch, std::vector<int32_t> isr, int32_t partition_epoch, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, leader_id_{leader_id}, leader_epoch_{leader_epoch}, isr_{isr}, leader_recovery_state_{0}, partition_epoch_{partition_epoch}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [1, 2, 3]
  ResponsePartitionData(int32_t partition_index, int16_t error_code, int32_t leader_id, int32_t leader_epoch, std::vector<int32_t> isr, int8_t leader_recovery_state, int32_t partition_epoch, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, leader_id_{leader_id}, leader_epoch_{leader_epoch}, isr_{isr}, leader_recovery_state_{leader_recovery_state}, partition_epoch_{partition_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(leader_id_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(leader_epoch_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeCompactSize(isr_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(leader_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(leader_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encodeCompact(isr_, dst);
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

  
  bool operator==(const ResponsePartitionData& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && leader_id_ == rhs.leader_id_
    && leader_epoch_ == rhs.leader_epoch_
    && isr_ == rhs.isr_
    && leader_recovery_state_ == rhs.leader_recovery_state_
    && partition_epoch_ == rhs.partition_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ResponsePartitionDataV0Deserializer:
  public CompositeDeserializerWith7Delegates<
    ResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
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

class ResponsePartitionDataV1Deserializer:
  public CompositeDeserializerWith8Delegates<
    ResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
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

class ResponsePartitionDataV2Deserializer:
  public CompositeDeserializerWith8Delegates<
    ResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
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

class ResponsePartitionDataV3Deserializer:
  public CompositeDeserializerWith8Delegates<
    ResponsePartitionData
    ,
      Int32Deserializer
    ,
      Int16Deserializer
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


struct ResponseTopicData {

  
  
  const std::string topic_name_;
  const Uuid topic_id_;
  const std::vector<ResponsePartitionData> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  ResponseTopicData(std::string topic_name, std::vector<ResponsePartitionData> partitions, TaggedFields tagged_fields): topic_name_{topic_name}, topic_id_{Uuid{0, 0}}, partitions_{partitions}, tagged_fields_{tagged_fields} {};
  // constructor used in versions: [2, 3]
  ResponseTopicData(Uuid topic_id, std::vector<ResponsePartitionData> partitions, TaggedFields tagged_fields): topic_name_{""}, topic_id_{topic_id}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const ResponseTopicData& rhs) const {
  
    return true
    && topic_name_ == rhs.topic_name_
    && topic_id_ == rhs.topic_id_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ResponseTopicDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ResponsePartitionDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ResponseTopicDataV1Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ResponsePartitionDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ResponseTopicDataV2Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseTopicData
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<ResponsePartitionDataV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class ResponseTopicDataV3Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseTopicData
    ,
      UuidDeserializer
    ,
      CompactArrayDeserializer<ResponsePartitionDataV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct AlterPartitionResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<ResponseTopicData> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1, 2, 3]
  AlterPartitionResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<ResponseTopicData> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 4) {
      written += encoder.encode(error_code_, dst);
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

  
  bool operator==(const AlterPartitionResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AlterPartitionResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ResponseTopicDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AlterPartitionResponseV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ResponseTopicDataV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AlterPartitionResponseV2Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ResponseTopicDataV2Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class AlterPartitionResponseV3Deserializer:
  public CompositeDeserializerWith4Delegates<
    AlterPartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ResponseTopicDataV3Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class AlterPartitionResponseV0Parser:
  public ResponseDataParser<
    AlterPartitionResponse, AlterPartitionResponseV0Deserializer>{
public:
  AlterPartitionResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterPartitionResponseV1Parser:
  public ResponseDataParser<
    AlterPartitionResponse, AlterPartitionResponseV1Deserializer>{
public:
  AlterPartitionResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterPartitionResponseV2Parser:
  public ResponseDataParser<
    AlterPartitionResponse, AlterPartitionResponseV2Deserializer>{
public:
  AlterPartitionResponseV2Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class AlterPartitionResponseV3Parser:
  public ResponseDataParser<
    AlterPartitionResponse, AlterPartitionResponseV3Deserializer>{
public:
  AlterPartitionResponseV3Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct UpdatableFeatureResult {

  
  
  const std::string feature_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  UpdatableFeatureResult(std::string feature, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): feature_{feature}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(feature_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdatableFeatureResult& rhs) const {
  
    return true
    && feature_ == rhs.feature_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdatableFeatureResultV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdatableFeatureResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};

class UpdatableFeatureResultV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    UpdatableFeatureResult
    ,
      CompactStringDeserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct UpdateFeaturesResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<UpdatableFeatureResult> results_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  UpdateFeaturesResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, std::vector<UpdatableFeatureResult> results, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, results_{results}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeCompactSize(results_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(results_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UpdateFeaturesResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && results_ == rhs.results_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UpdateFeaturesResponseV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    UpdateFeaturesResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<UpdatableFeatureResultV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};

class UpdateFeaturesResponseV1Deserializer:
  public CompositeDeserializerWith5Delegates<
    UpdateFeaturesResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<UpdatableFeatureResultV1Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class UpdateFeaturesResponseV0Parser:
  public ResponseDataParser<
    UpdateFeaturesResponse, UpdateFeaturesResponseV0Deserializer>{
public:
  UpdateFeaturesResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class UpdateFeaturesResponseV1Parser:
  public ResponseDataParser<
    UpdateFeaturesResponse, UpdateFeaturesResponseV1Deserializer>{
public:
  UpdateFeaturesResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct EnvelopeResponse {

  
  
  const absl::optional<Bytes> response_data_;
  const int16_t error_code_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  EnvelopeResponse(absl::optional<Bytes> response_data, int16_t error_code, TaggedFields tagged_fields): response_data_{response_data}, error_code_{error_code}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(response_data_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encodeCompact(response_data_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const EnvelopeResponse& rhs) const {
  
    return true
    && response_data_ == rhs.response_data_
    && error_code_ == rhs.error_code_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class EnvelopeResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    EnvelopeResponse
    ,
      NullableCompactBytesDeserializer
    ,
      Int16Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class EnvelopeResponseV0Parser:
  public ResponseDataParser<
    EnvelopeResponse, EnvelopeResponseV0Deserializer>{
public:
  EnvelopeResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ResponseSnapshotId {

  
  
  const int64_t end_offset_;
  const int32_t epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ResponseSnapshotId(int64_t end_offset, int32_t epoch, TaggedFields tagged_fields): end_offset_{end_offset}, epoch_{epoch}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const ResponseSnapshotId& rhs) const {
  
    return true
    && end_offset_ == rhs.end_offset_
    && epoch_ == rhs.epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ResponseSnapshotIdV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseSnapshotId
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ResponsePartitionSnapshot {

  
  
  const int32_t index_;
  const int16_t error_code_;
  const ResponseSnapshotId snapshot_id_;
  const int64_t size_;
  const int64_t position_;
  const Bytes unaligned_records_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ResponsePartitionSnapshot(int32_t index, int16_t error_code, ResponseSnapshotId snapshot_id, int64_t size, int64_t position, Bytes unaligned_records, TaggedFields tagged_fields): index_{index}, error_code_{error_code}, snapshot_id_{snapshot_id}, size_{size}, position_{position}, unaligned_records_{unaligned_records}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(snapshot_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(size_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(position_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(unaligned_records_);
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
      written += encoder.encode(index_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(snapshot_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(size_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(position_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(unaligned_records_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ResponsePartitionSnapshot& rhs) const {
  
    return true
    && index_ == rhs.index_
    && error_code_ == rhs.error_code_
    && snapshot_id_ == rhs.snapshot_id_
    && size_ == rhs.size_
    && position_ == rhs.position_
    && unaligned_records_ == rhs.unaligned_records_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ResponsePartitionSnapshotV0Deserializer:
  public CompositeDeserializerWith7Delegates<
    ResponsePartitionSnapshot
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      ResponseSnapshotIdV0Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      CompactBytesDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ResponseTopicSnapshot {

  
  
  const std::string name_;
  const std::vector<ResponsePartitionSnapshot> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ResponseTopicSnapshot(std::string name, std::vector<ResponsePartitionSnapshot> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const ResponseTopicSnapshot& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ResponseTopicSnapshotV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    ResponseTopicSnapshot
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<ResponsePartitionSnapshotV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct FetchSnapshotResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<ResponseTopicSnapshot> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  FetchSnapshotResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<ResponseTopicSnapshot> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
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

  
  bool operator==(const FetchSnapshotResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class FetchSnapshotResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    FetchSnapshotResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<ResponseTopicSnapshotV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class FetchSnapshotResponseV0Parser:
  public ResponseDataParser<
    FetchSnapshotResponse, FetchSnapshotResponseV0Deserializer>{
public:
  FetchSnapshotResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DescribeClusterBroker {

  
  
  const int32_t broker_id_;
  const std::string host_;
  const int32_t port_;
  const absl::optional<std::string> rack_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeClusterBroker(int32_t broker_id, std::string host, int32_t port, absl::optional<std::string> rack, TaggedFields tagged_fields): broker_id_{broker_id}, host_{host}, port_{port}, rack_{rack}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(broker_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(host_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(port_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(rack_);
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
      written += encoder.encodeCompact(host_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(port_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(rack_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeClusterBroker& rhs) const {
  
    return true
    && broker_id_ == rhs.broker_id_
    && host_ == rhs.host_
    && port_ == rhs.port_
    && rack_ == rhs.rack_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeClusterBrokerV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    DescribeClusterBroker
    ,
      Int32Deserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeClusterResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::string cluster_id_;
  const int32_t controller_id_;
  const std::vector<DescribeClusterBroker> brokers_;
  const int32_t cluster_authorized_operations_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeClusterResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, std::string cluster_id, int32_t controller_id, std::vector<DescribeClusterBroker> brokers, int32_t cluster_authorized_operations, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, cluster_id_{cluster_id}, controller_id_{controller_id}, brokers_{brokers}, cluster_authorized_operations_{cluster_authorized_operations}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(cluster_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(controller_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(brokers_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(cluster_authorized_operations_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(cluster_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(controller_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(brokers_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(cluster_authorized_operations_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeClusterResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && cluster_id_ == rhs.cluster_id_
    && controller_id_ == rhs.controller_id_
    && brokers_ == rhs.brokers_
    && cluster_authorized_operations_ == rhs.cluster_authorized_operations_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeClusterResponseV0Deserializer:
  public CompositeDeserializerWith8Delegates<
    DescribeClusterResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<DescribeClusterBrokerV0Deserializer>
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeClusterResponseV0Parser:
  public ResponseDataParser<
    DescribeClusterResponse, DescribeClusterResponseV0Deserializer>{
public:
  DescribeClusterResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ProducerState {

  
  
  const int64_t producer_id_;
  const int32_t producer_epoch_;
  const int32_t last_sequence_;
  const int64_t last_timestamp_;
  const int32_t coordinator_epoch_;
  const int64_t current_txn_start_offset_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ProducerState(int64_t producer_id, int32_t producer_epoch, int32_t last_sequence, int64_t last_timestamp, int32_t coordinator_epoch, int64_t current_txn_start_offset, TaggedFields tagged_fields): producer_id_{producer_id}, producer_epoch_{producer_epoch}, last_sequence_{last_sequence}, last_timestamp_{last_timestamp}, coordinator_epoch_{coordinator_epoch}, current_txn_start_offset_{current_txn_start_offset}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(producer_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(last_sequence_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(last_timestamp_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(coordinator_epoch_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(current_txn_start_offset_);
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
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(producer_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(last_sequence_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(last_timestamp_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(coordinator_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(current_txn_start_offset_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ProducerState& rhs) const {
  
    return true
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && last_sequence_ == rhs.last_sequence_
    && last_timestamp_ == rhs.last_timestamp_
    && coordinator_epoch_ == rhs.coordinator_epoch_
    && current_txn_start_offset_ == rhs.current_txn_start_offset_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ProducerStateV0Deserializer:
  public CompositeDeserializerWith7Delegates<
    ProducerState
    ,
      Int64Deserializer
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
      TaggedFieldsDeserializer
    >{};


struct PartitionResponse {

  
  
  const int32_t partition_index_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const std::vector<ProducerState> active_producers_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  PartitionResponse(int32_t partition_index, int16_t error_code, absl::optional<std::string> error_message, std::vector<ProducerState> active_producers, TaggedFields tagged_fields): partition_index_{partition_index}, error_code_{error_code}, error_message_{error_message}, active_producers_{active_producers}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(partition_index_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(active_producers_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(active_producers_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const PartitionResponse& rhs) const {
  
    return true
    && partition_index_ == rhs.partition_index_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && active_producers_ == rhs.active_producers_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class PartitionResponseV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    PartitionResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      CompactArrayDeserializer<ProducerStateV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct TopicResponse {

  
  
  const std::string name_;
  const std::vector<PartitionResponse> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  TopicResponse(std::string name, std::vector<PartitionResponse> partitions, TaggedFields tagged_fields): name_{name}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
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

  
  bool operator==(const TopicResponse& rhs) const {
  
    return true
    && name_ == rhs.name_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TopicResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    TopicResponse
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<PartitionResponseV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeProducersResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<TopicResponse> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeProducersResponse(int32_t throttle_time_ms, std::vector<TopicResponse> topics, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
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
      written += encoder.encode(throttle_time_ms_, dst);
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

  
  bool operator==(const DescribeProducersResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeProducersResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeProducersResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<TopicResponseV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeProducersResponseV0Parser:
  public ResponseDataParser<
    DescribeProducersResponse, DescribeProducersResponseV0Deserializer>{
public:
  DescribeProducersResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct BrokerRegistrationResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const int64_t broker_epoch_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0, 1]
  BrokerRegistrationResponse(int32_t throttle_time_ms, int16_t error_code, int64_t broker_epoch, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, broker_epoch_{broker_epoch}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.computeSize(broker_epoch_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encode(broker_epoch_, dst);
    }
    
    if (api_version >= 0 && api_version < 2) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BrokerRegistrationResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && broker_epoch_ == rhs.broker_epoch_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class BrokerRegistrationResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    BrokerRegistrationResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};

class BrokerRegistrationResponseV1Deserializer:
  public CompositeDeserializerWith4Delegates<
    BrokerRegistrationResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class BrokerRegistrationResponseV0Parser:
  public ResponseDataParser<
    BrokerRegistrationResponse, BrokerRegistrationResponseV0Deserializer>{
public:
  BrokerRegistrationResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};

class BrokerRegistrationResponseV1Parser:
  public ResponseDataParser<
    BrokerRegistrationResponse, BrokerRegistrationResponseV1Deserializer>{
public:
  BrokerRegistrationResponseV1Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct BrokerHeartbeatResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const bool is_caught_up_;
  const bool is_fenced_;
  const bool should_shut_down_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  BrokerHeartbeatResponse(int32_t throttle_time_ms, int16_t error_code, bool is_caught_up, bool is_fenced, bool should_shut_down, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, is_caught_up_{is_caught_up}, is_fenced_{is_fenced}, should_shut_down_{should_shut_down}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(is_caught_up_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(is_fenced_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(should_shut_down_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(is_caught_up_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(is_fenced_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(should_shut_down_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const BrokerHeartbeatResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && is_caught_up_ == rhs.is_caught_up_
    && is_fenced_ == rhs.is_fenced_
    && should_shut_down_ == rhs.should_shut_down_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class BrokerHeartbeatResponseV0Deserializer:
  public CompositeDeserializerWith6Delegates<
    BrokerHeartbeatResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      BooleanDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



class BrokerHeartbeatResponseV0Parser:
  public ResponseDataParser<
    BrokerHeartbeatResponse, BrokerHeartbeatResponseV0Deserializer>{
public:
  BrokerHeartbeatResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct UnregisterBrokerResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const absl::optional<std::string> error_message_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  UnregisterBrokerResponse(int32_t throttle_time_ms, int16_t error_code, absl::optional<std::string> error_message, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, error_message_{error_message}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(error_message_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(error_message_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const UnregisterBrokerResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && error_message_ == rhs.error_message_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class UnregisterBrokerResponseV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    UnregisterBrokerResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      NullableCompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};



class UnregisterBrokerResponseV0Parser:
  public ResponseDataParser<
    UnregisterBrokerResponse, UnregisterBrokerResponseV0Deserializer>{
public:
  UnregisterBrokerResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct DescribeTransactionsResponseResponseTopicData {

  
  
  const std::string topic_;
  const std::vector<int32_t> partitions_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeTransactionsResponseResponseTopicData(std::string topic, std::vector<int32_t> partitions, TaggedFields tagged_fields): topic_{topic}, partitions_{partitions}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(topic_);
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
      written += encoder.encodeCompact(topic_, dst);
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

  
  bool operator==(const DescribeTransactionsResponseResponseTopicData& rhs) const {
  
    return true
    && topic_ == rhs.topic_
    && partitions_ == rhs.partitions_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeTransactionsResponseResponseTopicDataV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeTransactionsResponseResponseTopicData
    ,
      CompactStringDeserializer
    ,
      CompactArrayDeserializer<Int32Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct TransactionState {

  
  
  const int16_t error_code_;
  const std::string transactional_id_;
  const std::string transaction_state_;
  const int32_t transaction_timeout_ms_;
  const int64_t transaction_start_time_ms_;
  const int64_t producer_id_;
  const int16_t producer_epoch_;
  const std::vector<DescribeTransactionsResponseResponseTopicData> topics_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  TransactionState(int16_t error_code, std::string transactional_id, std::string transaction_state, int32_t transaction_timeout_ms, int64_t transaction_start_time_ms, int64_t producer_id, int16_t producer_epoch, std::vector<DescribeTransactionsResponseResponseTopicData> topics, TaggedFields tagged_fields): error_code_{error_code}, transactional_id_{transactional_id}, transaction_state_{transaction_state}, transaction_timeout_ms_{transaction_timeout_ms}, transaction_start_time_ms_{transaction_start_time_ms}, producer_id_{producer_id}, producer_epoch_{producer_epoch}, topics_{topics}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(transaction_state_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(transaction_timeout_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(transaction_start_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(producer_epoch_);
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
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(transaction_state_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(transaction_timeout_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(transaction_start_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(producer_epoch_, dst);
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

  
  bool operator==(const TransactionState& rhs) const {
  
    return true
    && error_code_ == rhs.error_code_
    && transactional_id_ == rhs.transactional_id_
    && transaction_state_ == rhs.transaction_state_
    && transaction_timeout_ms_ == rhs.transaction_timeout_ms_
    && transaction_start_time_ms_ == rhs.transaction_start_time_ms_
    && producer_id_ == rhs.producer_id_
    && producer_epoch_ == rhs.producer_epoch_
    && topics_ == rhs.topics_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class TransactionStateV0Deserializer:
  public CompositeDeserializerWith9Delegates<
    TransactionState
    ,
      Int16Deserializer
    ,
      CompactStringDeserializer
    ,
      CompactStringDeserializer
    ,
      Int32Deserializer
    ,
      Int64Deserializer
    ,
      Int64Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<DescribeTransactionsResponseResponseTopicDataV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};


struct DescribeTransactionsResponse {

  
  
  const int32_t throttle_time_ms_;
  const std::vector<TransactionState> transaction_states_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  DescribeTransactionsResponse(int32_t throttle_time_ms, std::vector<TransactionState> transaction_states, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, transaction_states_{transaction_states}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(transaction_states_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(transaction_states_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const DescribeTransactionsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && transaction_states_ == rhs.transaction_states_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class DescribeTransactionsResponseV0Deserializer:
  public CompositeDeserializerWith3Delegates<
    DescribeTransactionsResponse
    ,
      Int32Deserializer
    ,
      CompactArrayDeserializer<TransactionStateV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class DescribeTransactionsResponseV0Parser:
  public ResponseDataParser<
    DescribeTransactionsResponse, DescribeTransactionsResponseV0Deserializer>{
public:
  DescribeTransactionsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct ListTransactionsResponseTransactionState {

  
  
  const std::string transactional_id_;
  const int64_t producer_id_;
  const std::string transaction_state_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListTransactionsResponseTransactionState(std::string transactional_id, int64_t producer_id, std::string transaction_state, TaggedFields tagged_fields): transactional_id_{transactional_id}, producer_id_{producer_id}, transaction_state_{transaction_state}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(transactional_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(producer_id_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(transaction_state_);
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
      written += encoder.encodeCompact(transactional_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(producer_id_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(transaction_state_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListTransactionsResponseTransactionState& rhs) const {
  
    return true
    && transactional_id_ == rhs.transactional_id_
    && producer_id_ == rhs.producer_id_
    && transaction_state_ == rhs.transaction_state_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListTransactionsResponseTransactionStateV0Deserializer:
  public CompositeDeserializerWith4Delegates<
    ListTransactionsResponseTransactionState
    ,
      CompactStringDeserializer
    ,
      Int64Deserializer
    ,
      CompactStringDeserializer
    ,
      TaggedFieldsDeserializer
    >{};


struct ListTransactionsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const std::vector<std::string> unknown_state_filters_;
  const std::vector<ListTransactionsResponseTransactionState> transaction_states_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  ListTransactionsResponse(int32_t throttle_time_ms, int16_t error_code, std::vector<std::string> unknown_state_filters, std::vector<ListTransactionsResponseTransactionState> transaction_states, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, unknown_state_filters_{unknown_state_filters}, transaction_states_{transaction_states}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(unknown_state_filters_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeCompactSize(transaction_states_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(unknown_state_filters_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(transaction_states_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const ListTransactionsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && unknown_state_filters_ == rhs.unknown_state_filters_
    && transaction_states_ == rhs.transaction_states_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class ListTransactionsResponseV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    ListTransactionsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      CompactArrayDeserializer<CompactStringDeserializer>
    ,
      CompactArrayDeserializer<ListTransactionsResponseTransactionStateV0Deserializer>
    ,
      TaggedFieldsDeserializer
    >{};



class ListTransactionsResponseV0Parser:
  public ResponseDataParser<
    ListTransactionsResponse, ListTransactionsResponseV0Deserializer>{
public:
  ListTransactionsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};


struct AllocateProducerIdsResponse {

  
  
  const int32_t throttle_time_ms_;
  const int16_t error_code_;
  const int64_t producer_id_start_;
  const int32_t producer_id_len_;
  const TaggedFields tagged_fields_;
  
  // constructor used in versions: [0]
  AllocateProducerIdsResponse(int32_t throttle_time_ms, int16_t error_code, int64_t producer_id_start, int32_t producer_id_len, TaggedFields tagged_fields): throttle_time_ms_{throttle_time_ms}, error_code_{error_code}, producer_id_start_{producer_id_start}, producer_id_len_{producer_id_len}, tagged_fields_{tagged_fields} {};

  
  uint32_t computeSize(const EncodingContext& encoder) const {
    const int16_t api_version = encoder.apiVersion();
    uint32_t written{0};

    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(throttle_time_ms_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(error_code_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(producer_id_start_);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.computeSize(producer_id_len_);
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
      written += encoder.encode(throttle_time_ms_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(error_code_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(producer_id_start_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encode(producer_id_len_, dst);
    }
    
    if (api_version >= 0 && api_version < 1) {
      written += encoder.encodeCompact(tagged_fields_, dst);
    }
    

    return written;
  }

  uint32_t encodeCompact(Buffer::Instance& dst, EncodingContext& encoder) const {
    return encode(dst, encoder);
  }

  
  bool operator==(const AllocateProducerIdsResponse& rhs) const {
  
    return true
    && throttle_time_ms_ == rhs.throttle_time_ms_
    && error_code_ == rhs.error_code_
    && producer_id_start_ == rhs.producer_id_start_
    && producer_id_len_ == rhs.producer_id_len_
    && tagged_fields_ == rhs.tagged_fields_;
  };

};



class AllocateProducerIdsResponseV0Deserializer:
  public CompositeDeserializerWith5Delegates<
    AllocateProducerIdsResponse
    ,
      Int32Deserializer
    ,
      Int16Deserializer
    ,
      Int64Deserializer
    ,
      Int32Deserializer
    ,
      TaggedFieldsDeserializer
    >{};



class AllocateProducerIdsResponseV0Parser:
  public ResponseDataParser<
    AllocateProducerIdsResponse, AllocateProducerIdsResponseV0Deserializer>{
public:
  AllocateProducerIdsResponseV0Parser(ResponseContextSharedPtr context):
    ResponseDataParser{context} {};
};



}}}}