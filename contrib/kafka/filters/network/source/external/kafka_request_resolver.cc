
#include "contrib/kafka/filters/network/source/external/requests.h"
#include "contrib/kafka/filters/network/source/kafka_request_parser.h"
#include "contrib/kafka/filters/network/source/parser.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace Kafka {

// Implements declaration from 'kafka_request.h'.
bool requestUsesTaggedFieldsInHeader(const uint16_t api_key, const uint16_t api_version) {
  switch (api_key) {
    
    case 0:
      switch (api_version) {
        
        case 9:
          return true;
        
        default:
          return false;
      }
    
    case 1:
      switch (api_version) {
        
        case 12:
          return true;
        
        case 13:
          return true;
        
        case 14:
          return true;
        
        case 15:
          return true;
        
        default:
          return false;
      }
    
    case 2:
      switch (api_version) {
        
        case 6:
          return true;
        
        case 7:
          return true;
        
        case 8:
          return true;
        
        default:
          return false;
      }
    
    case 3:
      switch (api_version) {
        
        case 9:
          return true;
        
        case 10:
          return true;
        
        case 11:
          return true;
        
        case 12:
          return true;
        
        default:
          return false;
      }
    
    case 4:
      switch (api_version) {
        
        case 4:
          return true;
        
        case 5:
          return true;
        
        case 6:
          return true;
        
        case 7:
          return true;
        
        default:
          return false;
      }
    
    case 5:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 6:
      switch (api_version) {
        
        case 6:
          return true;
        
        case 7:
          return true;
        
        case 8:
          return true;
        
        default:
          return false;
      }
    
    case 7:
      switch (api_version) {
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 8:
      switch (api_version) {
        
        case 8:
          return true;
        
        default:
          return false;
      }
    
    case 9:
      switch (api_version) {
        
        case 6:
          return true;
        
        case 7:
          return true;
        
        case 8:
          return true;
        
        default:
          return false;
      }
    
    case 10:
      switch (api_version) {
        
        case 3:
          return true;
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 11:
      switch (api_version) {
        
        case 6:
          return true;
        
        case 7:
          return true;
        
        case 8:
          return true;
        
        case 9:
          return true;
        
        default:
          return false;
      }
    
    case 12:
      switch (api_version) {
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 13:
      switch (api_version) {
        
        case 4:
          return true;
        
        case 5:
          return true;
        
        default:
          return false;
      }
    
    case 14:
      switch (api_version) {
        
        case 4:
          return true;
        
        case 5:
          return true;
        
        default:
          return false;
      }
    
    case 15:
      switch (api_version) {
        
        case 5:
          return true;
        
        default:
          return false;
      }
    
    case 16:
      switch (api_version) {
        
        case 3:
          return true;
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 17:
      switch (api_version) {
        
        default:
          return false;
      }
    
    case 18:
      switch (api_version) {
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 19:
      switch (api_version) {
        
        case 5:
          return true;
        
        case 6:
          return true;
        
        case 7:
          return true;
        
        default:
          return false;
      }
    
    case 20:
      switch (api_version) {
        
        case 4:
          return true;
        
        case 5:
          return true;
        
        case 6:
          return true;
        
        default:
          return false;
      }
    
    case 21:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 22:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 23:
      switch (api_version) {
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 24:
      switch (api_version) {
        
        case 3:
          return true;
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 25:
      switch (api_version) {
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 26:
      switch (api_version) {
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 27:
      switch (api_version) {
        
        case 1:
          return true;
        
        default:
          return false;
      }
    
    case 28:
      switch (api_version) {
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 29:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 30:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 31:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 32:
      switch (api_version) {
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 33:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 34:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 35:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        case 4:
          return true;
        
        default:
          return false;
      }
    
    case 36:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 37:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 38:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 39:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 40:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 41:
      switch (api_version) {
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 42:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 43:
      switch (api_version) {
        
        case 2:
          return true;
        
        default:
          return false;
      }
    
    case 44:
      switch (api_version) {
        
        case 1:
          return true;
        
        default:
          return false;
      }
    
    case 45:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 46:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 47:
      switch (api_version) {
        
        default:
          return false;
      }
    
    case 48:
      switch (api_version) {
        
        case 1:
          return true;
        
        default:
          return false;
      }
    
    case 49:
      switch (api_version) {
        
        case 1:
          return true;
        
        default:
          return false;
      }
    
    case 50:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 51:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 52:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 53:
      switch (api_version) {
        
        default:
          return false;
      }
    
    case 54:
      switch (api_version) {
        
        default:
          return false;
      }
    
    case 55:
      switch (api_version) {
        
        case 0:
          return true;
        
        case 1:
          return true;
        
        default:
          return false;
      }
    
    case 56:
      switch (api_version) {
        
        case 0:
          return true;
        
        case 1:
          return true;
        
        case 2:
          return true;
        
        case 3:
          return true;
        
        default:
          return false;
      }
    
    case 57:
      switch (api_version) {
        
        case 0:
          return true;
        
        case 1:
          return true;
        
        default:
          return false;
      }
    
    case 58:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 59:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 60:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 61:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 62:
      switch (api_version) {
        
        case 0:
          return true;
        
        case 1:
          return true;
        
        default:
          return false;
      }
    
    case 63:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 64:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 65:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 66:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    case 67:
      switch (api_version) {
        
        case 0:
          return true;
        
        default:
          return false;
      }
    
    default:
      return false;
  }
}

/**
 * Creates a parser that corresponds to provided key and version.
 * If corresponding parser cannot be found (what means a newer version of Kafka protocol),
 * a sentinel parser is returned.
 * @param api_key Kafka request key
 * @param api_version Kafka request's version
 * @param context parse context
 */
RequestParserSharedPtr RequestParserResolver::createParser(int16_t api_key, int16_t api_version,
                                                           RequestContextSharedPtr context) const {


  if (0 == api_key
    && 0 == api_version) {
    return std::make_shared<ProduceRequestV0Parser>(context);
  }
  if (0 == api_key
    && 1 == api_version) {
    return std::make_shared<ProduceRequestV1Parser>(context);
  }
  if (0 == api_key
    && 2 == api_version) {
    return std::make_shared<ProduceRequestV2Parser>(context);
  }
  if (0 == api_key
    && 3 == api_version) {
    return std::make_shared<ProduceRequestV3Parser>(context);
  }
  if (0 == api_key
    && 4 == api_version) {
    return std::make_shared<ProduceRequestV4Parser>(context);
  }
  if (0 == api_key
    && 5 == api_version) {
    return std::make_shared<ProduceRequestV5Parser>(context);
  }
  if (0 == api_key
    && 6 == api_version) {
    return std::make_shared<ProduceRequestV6Parser>(context);
  }
  if (0 == api_key
    && 7 == api_version) {
    return std::make_shared<ProduceRequestV7Parser>(context);
  }
  if (0 == api_key
    && 8 == api_version) {
    return std::make_shared<ProduceRequestV8Parser>(context);
  }
  if (0 == api_key
    && 9 == api_version) {
    return std::make_shared<ProduceRequestV9Parser>(context);
  }
  if (1 == api_key
    && 0 == api_version) {
    return std::make_shared<FetchRequestV0Parser>(context);
  }
  if (1 == api_key
    && 1 == api_version) {
    return std::make_shared<FetchRequestV1Parser>(context);
  }
  if (1 == api_key
    && 2 == api_version) {
    return std::make_shared<FetchRequestV2Parser>(context);
  }
  if (1 == api_key
    && 3 == api_version) {
    return std::make_shared<FetchRequestV3Parser>(context);
  }
  if (1 == api_key
    && 4 == api_version) {
    return std::make_shared<FetchRequestV4Parser>(context);
  }
  if (1 == api_key
    && 5 == api_version) {
    return std::make_shared<FetchRequestV5Parser>(context);
  }
  if (1 == api_key
    && 6 == api_version) {
    return std::make_shared<FetchRequestV6Parser>(context);
  }
  if (1 == api_key
    && 7 == api_version) {
    return std::make_shared<FetchRequestV7Parser>(context);
  }
  if (1 == api_key
    && 8 == api_version) {
    return std::make_shared<FetchRequestV8Parser>(context);
  }
  if (1 == api_key
    && 9 == api_version) {
    return std::make_shared<FetchRequestV9Parser>(context);
  }
  if (1 == api_key
    && 10 == api_version) {
    return std::make_shared<FetchRequestV10Parser>(context);
  }
  if (1 == api_key
    && 11 == api_version) {
    return std::make_shared<FetchRequestV11Parser>(context);
  }
  if (1 == api_key
    && 12 == api_version) {
    return std::make_shared<FetchRequestV12Parser>(context);
  }
  if (1 == api_key
    && 13 == api_version) {
    return std::make_shared<FetchRequestV13Parser>(context);
  }
  if (1 == api_key
    && 14 == api_version) {
    return std::make_shared<FetchRequestV14Parser>(context);
  }
  if (1 == api_key
    && 15 == api_version) {
    return std::make_shared<FetchRequestV15Parser>(context);
  }
  if (2 == api_key
    && 0 == api_version) {
    return std::make_shared<ListOffsetsRequestV0Parser>(context);
  }
  if (2 == api_key
    && 1 == api_version) {
    return std::make_shared<ListOffsetsRequestV1Parser>(context);
  }
  if (2 == api_key
    && 2 == api_version) {
    return std::make_shared<ListOffsetsRequestV2Parser>(context);
  }
  if (2 == api_key
    && 3 == api_version) {
    return std::make_shared<ListOffsetsRequestV3Parser>(context);
  }
  if (2 == api_key
    && 4 == api_version) {
    return std::make_shared<ListOffsetsRequestV4Parser>(context);
  }
  if (2 == api_key
    && 5 == api_version) {
    return std::make_shared<ListOffsetsRequestV5Parser>(context);
  }
  if (2 == api_key
    && 6 == api_version) {
    return std::make_shared<ListOffsetsRequestV6Parser>(context);
  }
  if (2 == api_key
    && 7 == api_version) {
    return std::make_shared<ListOffsetsRequestV7Parser>(context);
  }
  if (2 == api_key
    && 8 == api_version) {
    return std::make_shared<ListOffsetsRequestV8Parser>(context);
  }
  if (3 == api_key
    && 0 == api_version) {
    return std::make_shared<MetadataRequestV0Parser>(context);
  }
  if (3 == api_key
    && 1 == api_version) {
    return std::make_shared<MetadataRequestV1Parser>(context);
  }
  if (3 == api_key
    && 2 == api_version) {
    return std::make_shared<MetadataRequestV2Parser>(context);
  }
  if (3 == api_key
    && 3 == api_version) {
    return std::make_shared<MetadataRequestV3Parser>(context);
  }
  if (3 == api_key
    && 4 == api_version) {
    return std::make_shared<MetadataRequestV4Parser>(context);
  }
  if (3 == api_key
    && 5 == api_version) {
    return std::make_shared<MetadataRequestV5Parser>(context);
  }
  if (3 == api_key
    && 6 == api_version) {
    return std::make_shared<MetadataRequestV6Parser>(context);
  }
  if (3 == api_key
    && 7 == api_version) {
    return std::make_shared<MetadataRequestV7Parser>(context);
  }
  if (3 == api_key
    && 8 == api_version) {
    return std::make_shared<MetadataRequestV8Parser>(context);
  }
  if (3 == api_key
    && 9 == api_version) {
    return std::make_shared<MetadataRequestV9Parser>(context);
  }
  if (3 == api_key
    && 10 == api_version) {
    return std::make_shared<MetadataRequestV10Parser>(context);
  }
  if (3 == api_key
    && 11 == api_version) {
    return std::make_shared<MetadataRequestV11Parser>(context);
  }
  if (3 == api_key
    && 12 == api_version) {
    return std::make_shared<MetadataRequestV12Parser>(context);
  }
  if (4 == api_key
    && 0 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV0Parser>(context);
  }
  if (4 == api_key
    && 1 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV1Parser>(context);
  }
  if (4 == api_key
    && 2 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV2Parser>(context);
  }
  if (4 == api_key
    && 3 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV3Parser>(context);
  }
  if (4 == api_key
    && 4 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV4Parser>(context);
  }
  if (4 == api_key
    && 5 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV5Parser>(context);
  }
  if (4 == api_key
    && 6 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV6Parser>(context);
  }
  if (4 == api_key
    && 7 == api_version) {
    return std::make_shared<LeaderAndIsrRequestV7Parser>(context);
  }
  if (5 == api_key
    && 0 == api_version) {
    return std::make_shared<StopReplicaRequestV0Parser>(context);
  }
  if (5 == api_key
    && 1 == api_version) {
    return std::make_shared<StopReplicaRequestV1Parser>(context);
  }
  if (5 == api_key
    && 2 == api_version) {
    return std::make_shared<StopReplicaRequestV2Parser>(context);
  }
  if (5 == api_key
    && 3 == api_version) {
    return std::make_shared<StopReplicaRequestV3Parser>(context);
  }
  if (5 == api_key
    && 4 == api_version) {
    return std::make_shared<StopReplicaRequestV4Parser>(context);
  }
  if (6 == api_key
    && 0 == api_version) {
    return std::make_shared<UpdateMetadataRequestV0Parser>(context);
  }
  if (6 == api_key
    && 1 == api_version) {
    return std::make_shared<UpdateMetadataRequestV1Parser>(context);
  }
  if (6 == api_key
    && 2 == api_version) {
    return std::make_shared<UpdateMetadataRequestV2Parser>(context);
  }
  if (6 == api_key
    && 3 == api_version) {
    return std::make_shared<UpdateMetadataRequestV3Parser>(context);
  }
  if (6 == api_key
    && 4 == api_version) {
    return std::make_shared<UpdateMetadataRequestV4Parser>(context);
  }
  if (6 == api_key
    && 5 == api_version) {
    return std::make_shared<UpdateMetadataRequestV5Parser>(context);
  }
  if (6 == api_key
    && 6 == api_version) {
    return std::make_shared<UpdateMetadataRequestV6Parser>(context);
  }
  if (6 == api_key
    && 7 == api_version) {
    return std::make_shared<UpdateMetadataRequestV7Parser>(context);
  }
  if (6 == api_key
    && 8 == api_version) {
    return std::make_shared<UpdateMetadataRequestV8Parser>(context);
  }
  if (7 == api_key
    && 0 == api_version) {
    return std::make_shared<ControlledShutdownRequestV0Parser>(context);
  }
  if (7 == api_key
    && 1 == api_version) {
    return std::make_shared<ControlledShutdownRequestV1Parser>(context);
  }
  if (7 == api_key
    && 2 == api_version) {
    return std::make_shared<ControlledShutdownRequestV2Parser>(context);
  }
  if (7 == api_key
    && 3 == api_version) {
    return std::make_shared<ControlledShutdownRequestV3Parser>(context);
  }
  if (8 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetCommitRequestV0Parser>(context);
  }
  if (8 == api_key
    && 1 == api_version) {
    return std::make_shared<OffsetCommitRequestV1Parser>(context);
  }
  if (8 == api_key
    && 2 == api_version) {
    return std::make_shared<OffsetCommitRequestV2Parser>(context);
  }
  if (8 == api_key
    && 3 == api_version) {
    return std::make_shared<OffsetCommitRequestV3Parser>(context);
  }
  if (8 == api_key
    && 4 == api_version) {
    return std::make_shared<OffsetCommitRequestV4Parser>(context);
  }
  if (8 == api_key
    && 5 == api_version) {
    return std::make_shared<OffsetCommitRequestV5Parser>(context);
  }
  if (8 == api_key
    && 6 == api_version) {
    return std::make_shared<OffsetCommitRequestV6Parser>(context);
  }
  if (8 == api_key
    && 7 == api_version) {
    return std::make_shared<OffsetCommitRequestV7Parser>(context);
  }
  if (8 == api_key
    && 8 == api_version) {
    return std::make_shared<OffsetCommitRequestV8Parser>(context);
  }
  if (9 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetFetchRequestV0Parser>(context);
  }
  if (9 == api_key
    && 1 == api_version) {
    return std::make_shared<OffsetFetchRequestV1Parser>(context);
  }
  if (9 == api_key
    && 2 == api_version) {
    return std::make_shared<OffsetFetchRequestV2Parser>(context);
  }
  if (9 == api_key
    && 3 == api_version) {
    return std::make_shared<OffsetFetchRequestV3Parser>(context);
  }
  if (9 == api_key
    && 4 == api_version) {
    return std::make_shared<OffsetFetchRequestV4Parser>(context);
  }
  if (9 == api_key
    && 5 == api_version) {
    return std::make_shared<OffsetFetchRequestV5Parser>(context);
  }
  if (9 == api_key
    && 6 == api_version) {
    return std::make_shared<OffsetFetchRequestV6Parser>(context);
  }
  if (9 == api_key
    && 7 == api_version) {
    return std::make_shared<OffsetFetchRequestV7Parser>(context);
  }
  if (9 == api_key
    && 8 == api_version) {
    return std::make_shared<OffsetFetchRequestV8Parser>(context);
  }
  if (10 == api_key
    && 0 == api_version) {
    return std::make_shared<FindCoordinatorRequestV0Parser>(context);
  }
  if (10 == api_key
    && 1 == api_version) {
    return std::make_shared<FindCoordinatorRequestV1Parser>(context);
  }
  if (10 == api_key
    && 2 == api_version) {
    return std::make_shared<FindCoordinatorRequestV2Parser>(context);
  }
  if (10 == api_key
    && 3 == api_version) {
    return std::make_shared<FindCoordinatorRequestV3Parser>(context);
  }
  if (10 == api_key
    && 4 == api_version) {
    return std::make_shared<FindCoordinatorRequestV4Parser>(context);
  }
  if (11 == api_key
    && 0 == api_version) {
    return std::make_shared<JoinGroupRequestV0Parser>(context);
  }
  if (11 == api_key
    && 1 == api_version) {
    return std::make_shared<JoinGroupRequestV1Parser>(context);
  }
  if (11 == api_key
    && 2 == api_version) {
    return std::make_shared<JoinGroupRequestV2Parser>(context);
  }
  if (11 == api_key
    && 3 == api_version) {
    return std::make_shared<JoinGroupRequestV3Parser>(context);
  }
  if (11 == api_key
    && 4 == api_version) {
    return std::make_shared<JoinGroupRequestV4Parser>(context);
  }
  if (11 == api_key
    && 5 == api_version) {
    return std::make_shared<JoinGroupRequestV5Parser>(context);
  }
  if (11 == api_key
    && 6 == api_version) {
    return std::make_shared<JoinGroupRequestV6Parser>(context);
  }
  if (11 == api_key
    && 7 == api_version) {
    return std::make_shared<JoinGroupRequestV7Parser>(context);
  }
  if (11 == api_key
    && 8 == api_version) {
    return std::make_shared<JoinGroupRequestV8Parser>(context);
  }
  if (11 == api_key
    && 9 == api_version) {
    return std::make_shared<JoinGroupRequestV9Parser>(context);
  }
  if (12 == api_key
    && 0 == api_version) {
    return std::make_shared<HeartbeatRequestV0Parser>(context);
  }
  if (12 == api_key
    && 1 == api_version) {
    return std::make_shared<HeartbeatRequestV1Parser>(context);
  }
  if (12 == api_key
    && 2 == api_version) {
    return std::make_shared<HeartbeatRequestV2Parser>(context);
  }
  if (12 == api_key
    && 3 == api_version) {
    return std::make_shared<HeartbeatRequestV3Parser>(context);
  }
  if (12 == api_key
    && 4 == api_version) {
    return std::make_shared<HeartbeatRequestV4Parser>(context);
  }
  if (13 == api_key
    && 0 == api_version) {
    return std::make_shared<LeaveGroupRequestV0Parser>(context);
  }
  if (13 == api_key
    && 1 == api_version) {
    return std::make_shared<LeaveGroupRequestV1Parser>(context);
  }
  if (13 == api_key
    && 2 == api_version) {
    return std::make_shared<LeaveGroupRequestV2Parser>(context);
  }
  if (13 == api_key
    && 3 == api_version) {
    return std::make_shared<LeaveGroupRequestV3Parser>(context);
  }
  if (13 == api_key
    && 4 == api_version) {
    return std::make_shared<LeaveGroupRequestV4Parser>(context);
  }
  if (13 == api_key
    && 5 == api_version) {
    return std::make_shared<LeaveGroupRequestV5Parser>(context);
  }
  if (14 == api_key
    && 0 == api_version) {
    return std::make_shared<SyncGroupRequestV0Parser>(context);
  }
  if (14 == api_key
    && 1 == api_version) {
    return std::make_shared<SyncGroupRequestV1Parser>(context);
  }
  if (14 == api_key
    && 2 == api_version) {
    return std::make_shared<SyncGroupRequestV2Parser>(context);
  }
  if (14 == api_key
    && 3 == api_version) {
    return std::make_shared<SyncGroupRequestV3Parser>(context);
  }
  if (14 == api_key
    && 4 == api_version) {
    return std::make_shared<SyncGroupRequestV4Parser>(context);
  }
  if (14 == api_key
    && 5 == api_version) {
    return std::make_shared<SyncGroupRequestV5Parser>(context);
  }
  if (15 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeGroupsRequestV0Parser>(context);
  }
  if (15 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeGroupsRequestV1Parser>(context);
  }
  if (15 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeGroupsRequestV2Parser>(context);
  }
  if (15 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeGroupsRequestV3Parser>(context);
  }
  if (15 == api_key
    && 4 == api_version) {
    return std::make_shared<DescribeGroupsRequestV4Parser>(context);
  }
  if (15 == api_key
    && 5 == api_version) {
    return std::make_shared<DescribeGroupsRequestV5Parser>(context);
  }
  if (16 == api_key
    && 0 == api_version) {
    return std::make_shared<ListGroupsRequestV0Parser>(context);
  }
  if (16 == api_key
    && 1 == api_version) {
    return std::make_shared<ListGroupsRequestV1Parser>(context);
  }
  if (16 == api_key
    && 2 == api_version) {
    return std::make_shared<ListGroupsRequestV2Parser>(context);
  }
  if (16 == api_key
    && 3 == api_version) {
    return std::make_shared<ListGroupsRequestV3Parser>(context);
  }
  if (16 == api_key
    && 4 == api_version) {
    return std::make_shared<ListGroupsRequestV4Parser>(context);
  }
  if (17 == api_key
    && 0 == api_version) {
    return std::make_shared<SaslHandshakeRequestV0Parser>(context);
  }
  if (17 == api_key
    && 1 == api_version) {
    return std::make_shared<SaslHandshakeRequestV1Parser>(context);
  }
  if (18 == api_key
    && 0 == api_version) {
    return std::make_shared<ApiVersionsRequestV0Parser>(context);
  }
  if (18 == api_key
    && 1 == api_version) {
    return std::make_shared<ApiVersionsRequestV1Parser>(context);
  }
  if (18 == api_key
    && 2 == api_version) {
    return std::make_shared<ApiVersionsRequestV2Parser>(context);
  }
  if (18 == api_key
    && 3 == api_version) {
    return std::make_shared<ApiVersionsRequestV3Parser>(context);
  }
  if (19 == api_key
    && 0 == api_version) {
    return std::make_shared<CreateTopicsRequestV0Parser>(context);
  }
  if (19 == api_key
    && 1 == api_version) {
    return std::make_shared<CreateTopicsRequestV1Parser>(context);
  }
  if (19 == api_key
    && 2 == api_version) {
    return std::make_shared<CreateTopicsRequestV2Parser>(context);
  }
  if (19 == api_key
    && 3 == api_version) {
    return std::make_shared<CreateTopicsRequestV3Parser>(context);
  }
  if (19 == api_key
    && 4 == api_version) {
    return std::make_shared<CreateTopicsRequestV4Parser>(context);
  }
  if (19 == api_key
    && 5 == api_version) {
    return std::make_shared<CreateTopicsRequestV5Parser>(context);
  }
  if (19 == api_key
    && 6 == api_version) {
    return std::make_shared<CreateTopicsRequestV6Parser>(context);
  }
  if (19 == api_key
    && 7 == api_version) {
    return std::make_shared<CreateTopicsRequestV7Parser>(context);
  }
  if (20 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteTopicsRequestV0Parser>(context);
  }
  if (20 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteTopicsRequestV1Parser>(context);
  }
  if (20 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteTopicsRequestV2Parser>(context);
  }
  if (20 == api_key
    && 3 == api_version) {
    return std::make_shared<DeleteTopicsRequestV3Parser>(context);
  }
  if (20 == api_key
    && 4 == api_version) {
    return std::make_shared<DeleteTopicsRequestV4Parser>(context);
  }
  if (20 == api_key
    && 5 == api_version) {
    return std::make_shared<DeleteTopicsRequestV5Parser>(context);
  }
  if (20 == api_key
    && 6 == api_version) {
    return std::make_shared<DeleteTopicsRequestV6Parser>(context);
  }
  if (21 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteRecordsRequestV0Parser>(context);
  }
  if (21 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteRecordsRequestV1Parser>(context);
  }
  if (21 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteRecordsRequestV2Parser>(context);
  }
  if (22 == api_key
    && 0 == api_version) {
    return std::make_shared<InitProducerIdRequestV0Parser>(context);
  }
  if (22 == api_key
    && 1 == api_version) {
    return std::make_shared<InitProducerIdRequestV1Parser>(context);
  }
  if (22 == api_key
    && 2 == api_version) {
    return std::make_shared<InitProducerIdRequestV2Parser>(context);
  }
  if (22 == api_key
    && 3 == api_version) {
    return std::make_shared<InitProducerIdRequestV3Parser>(context);
  }
  if (22 == api_key
    && 4 == api_version) {
    return std::make_shared<InitProducerIdRequestV4Parser>(context);
  }
  if (23 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetForLeaderEpochRequestV0Parser>(context);
  }
  if (23 == api_key
    && 1 == api_version) {
    return std::make_shared<OffsetForLeaderEpochRequestV1Parser>(context);
  }
  if (23 == api_key
    && 2 == api_version) {
    return std::make_shared<OffsetForLeaderEpochRequestV2Parser>(context);
  }
  if (23 == api_key
    && 3 == api_version) {
    return std::make_shared<OffsetForLeaderEpochRequestV3Parser>(context);
  }
  if (23 == api_key
    && 4 == api_version) {
    return std::make_shared<OffsetForLeaderEpochRequestV4Parser>(context);
  }
  if (24 == api_key
    && 0 == api_version) {
    return std::make_shared<AddPartitionsToTxnRequestV0Parser>(context);
  }
  if (24 == api_key
    && 1 == api_version) {
    return std::make_shared<AddPartitionsToTxnRequestV1Parser>(context);
  }
  if (24 == api_key
    && 2 == api_version) {
    return std::make_shared<AddPartitionsToTxnRequestV2Parser>(context);
  }
  if (24 == api_key
    && 3 == api_version) {
    return std::make_shared<AddPartitionsToTxnRequestV3Parser>(context);
  }
  if (24 == api_key
    && 4 == api_version) {
    return std::make_shared<AddPartitionsToTxnRequestV4Parser>(context);
  }
  if (25 == api_key
    && 0 == api_version) {
    return std::make_shared<AddOffsetsToTxnRequestV0Parser>(context);
  }
  if (25 == api_key
    && 1 == api_version) {
    return std::make_shared<AddOffsetsToTxnRequestV1Parser>(context);
  }
  if (25 == api_key
    && 2 == api_version) {
    return std::make_shared<AddOffsetsToTxnRequestV2Parser>(context);
  }
  if (25 == api_key
    && 3 == api_version) {
    return std::make_shared<AddOffsetsToTxnRequestV3Parser>(context);
  }
  if (26 == api_key
    && 0 == api_version) {
    return std::make_shared<EndTxnRequestV0Parser>(context);
  }
  if (26 == api_key
    && 1 == api_version) {
    return std::make_shared<EndTxnRequestV1Parser>(context);
  }
  if (26 == api_key
    && 2 == api_version) {
    return std::make_shared<EndTxnRequestV2Parser>(context);
  }
  if (26 == api_key
    && 3 == api_version) {
    return std::make_shared<EndTxnRequestV3Parser>(context);
  }
  if (27 == api_key
    && 0 == api_version) {
    return std::make_shared<WriteTxnMarkersRequestV0Parser>(context);
  }
  if (27 == api_key
    && 1 == api_version) {
    return std::make_shared<WriteTxnMarkersRequestV1Parser>(context);
  }
  if (28 == api_key
    && 0 == api_version) {
    return std::make_shared<TxnOffsetCommitRequestV0Parser>(context);
  }
  if (28 == api_key
    && 1 == api_version) {
    return std::make_shared<TxnOffsetCommitRequestV1Parser>(context);
  }
  if (28 == api_key
    && 2 == api_version) {
    return std::make_shared<TxnOffsetCommitRequestV2Parser>(context);
  }
  if (28 == api_key
    && 3 == api_version) {
    return std::make_shared<TxnOffsetCommitRequestV3Parser>(context);
  }
  if (29 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeAclsRequestV0Parser>(context);
  }
  if (29 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeAclsRequestV1Parser>(context);
  }
  if (29 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeAclsRequestV2Parser>(context);
  }
  if (29 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeAclsRequestV3Parser>(context);
  }
  if (30 == api_key
    && 0 == api_version) {
    return std::make_shared<CreateAclsRequestV0Parser>(context);
  }
  if (30 == api_key
    && 1 == api_version) {
    return std::make_shared<CreateAclsRequestV1Parser>(context);
  }
  if (30 == api_key
    && 2 == api_version) {
    return std::make_shared<CreateAclsRequestV2Parser>(context);
  }
  if (30 == api_key
    && 3 == api_version) {
    return std::make_shared<CreateAclsRequestV3Parser>(context);
  }
  if (31 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteAclsRequestV0Parser>(context);
  }
  if (31 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteAclsRequestV1Parser>(context);
  }
  if (31 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteAclsRequestV2Parser>(context);
  }
  if (31 == api_key
    && 3 == api_version) {
    return std::make_shared<DeleteAclsRequestV3Parser>(context);
  }
  if (32 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeConfigsRequestV0Parser>(context);
  }
  if (32 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeConfigsRequestV1Parser>(context);
  }
  if (32 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeConfigsRequestV2Parser>(context);
  }
  if (32 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeConfigsRequestV3Parser>(context);
  }
  if (32 == api_key
    && 4 == api_version) {
    return std::make_shared<DescribeConfigsRequestV4Parser>(context);
  }
  if (33 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterConfigsRequestV0Parser>(context);
  }
  if (33 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterConfigsRequestV1Parser>(context);
  }
  if (33 == api_key
    && 2 == api_version) {
    return std::make_shared<AlterConfigsRequestV2Parser>(context);
  }
  if (34 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterReplicaLogDirsRequestV0Parser>(context);
  }
  if (34 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterReplicaLogDirsRequestV1Parser>(context);
  }
  if (34 == api_key
    && 2 == api_version) {
    return std::make_shared<AlterReplicaLogDirsRequestV2Parser>(context);
  }
  if (35 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeLogDirsRequestV0Parser>(context);
  }
  if (35 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeLogDirsRequestV1Parser>(context);
  }
  if (35 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeLogDirsRequestV2Parser>(context);
  }
  if (35 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeLogDirsRequestV3Parser>(context);
  }
  if (35 == api_key
    && 4 == api_version) {
    return std::make_shared<DescribeLogDirsRequestV4Parser>(context);
  }
  if (36 == api_key
    && 0 == api_version) {
    return std::make_shared<SaslAuthenticateRequestV0Parser>(context);
  }
  if (36 == api_key
    && 1 == api_version) {
    return std::make_shared<SaslAuthenticateRequestV1Parser>(context);
  }
  if (36 == api_key
    && 2 == api_version) {
    return std::make_shared<SaslAuthenticateRequestV2Parser>(context);
  }
  if (37 == api_key
    && 0 == api_version) {
    return std::make_shared<CreatePartitionsRequestV0Parser>(context);
  }
  if (37 == api_key
    && 1 == api_version) {
    return std::make_shared<CreatePartitionsRequestV1Parser>(context);
  }
  if (37 == api_key
    && 2 == api_version) {
    return std::make_shared<CreatePartitionsRequestV2Parser>(context);
  }
  if (37 == api_key
    && 3 == api_version) {
    return std::make_shared<CreatePartitionsRequestV3Parser>(context);
  }
  if (38 == api_key
    && 0 == api_version) {
    return std::make_shared<CreateDelegationTokenRequestV0Parser>(context);
  }
  if (38 == api_key
    && 1 == api_version) {
    return std::make_shared<CreateDelegationTokenRequestV1Parser>(context);
  }
  if (38 == api_key
    && 2 == api_version) {
    return std::make_shared<CreateDelegationTokenRequestV2Parser>(context);
  }
  if (38 == api_key
    && 3 == api_version) {
    return std::make_shared<CreateDelegationTokenRequestV3Parser>(context);
  }
  if (39 == api_key
    && 0 == api_version) {
    return std::make_shared<RenewDelegationTokenRequestV0Parser>(context);
  }
  if (39 == api_key
    && 1 == api_version) {
    return std::make_shared<RenewDelegationTokenRequestV1Parser>(context);
  }
  if (39 == api_key
    && 2 == api_version) {
    return std::make_shared<RenewDelegationTokenRequestV2Parser>(context);
  }
  if (40 == api_key
    && 0 == api_version) {
    return std::make_shared<ExpireDelegationTokenRequestV0Parser>(context);
  }
  if (40 == api_key
    && 1 == api_version) {
    return std::make_shared<ExpireDelegationTokenRequestV1Parser>(context);
  }
  if (40 == api_key
    && 2 == api_version) {
    return std::make_shared<ExpireDelegationTokenRequestV2Parser>(context);
  }
  if (41 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeDelegationTokenRequestV0Parser>(context);
  }
  if (41 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeDelegationTokenRequestV1Parser>(context);
  }
  if (41 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeDelegationTokenRequestV2Parser>(context);
  }
  if (41 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeDelegationTokenRequestV3Parser>(context);
  }
  if (42 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteGroupsRequestV0Parser>(context);
  }
  if (42 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteGroupsRequestV1Parser>(context);
  }
  if (42 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteGroupsRequestV2Parser>(context);
  }
  if (43 == api_key
    && 0 == api_version) {
    return std::make_shared<ElectLeadersRequestV0Parser>(context);
  }
  if (43 == api_key
    && 1 == api_version) {
    return std::make_shared<ElectLeadersRequestV1Parser>(context);
  }
  if (43 == api_key
    && 2 == api_version) {
    return std::make_shared<ElectLeadersRequestV2Parser>(context);
  }
  if (44 == api_key
    && 0 == api_version) {
    return std::make_shared<IncrementalAlterConfigsRequestV0Parser>(context);
  }
  if (44 == api_key
    && 1 == api_version) {
    return std::make_shared<IncrementalAlterConfigsRequestV1Parser>(context);
  }
  if (45 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterPartitionReassignmentsRequestV0Parser>(context);
  }
  if (46 == api_key
    && 0 == api_version) {
    return std::make_shared<ListPartitionReassignmentsRequestV0Parser>(context);
  }
  if (47 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetDeleteRequestV0Parser>(context);
  }
  if (48 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeClientQuotasRequestV0Parser>(context);
  }
  if (48 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeClientQuotasRequestV1Parser>(context);
  }
  if (49 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterClientQuotasRequestV0Parser>(context);
  }
  if (49 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterClientQuotasRequestV1Parser>(context);
  }
  if (50 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeUserScramCredentialsRequestV0Parser>(context);
  }
  if (51 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterUserScramCredentialsRequestV0Parser>(context);
  }
  if (52 == api_key
    && 0 == api_version) {
    return std::make_shared<VoteRequestV0Parser>(context);
  }
  if (53 == api_key
    && 0 == api_version) {
    return std::make_shared<BeginQuorumEpochRequestV0Parser>(context);
  }
  if (54 == api_key
    && 0 == api_version) {
    return std::make_shared<EndQuorumEpochRequestV0Parser>(context);
  }
  if (55 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeQuorumRequestV0Parser>(context);
  }
  if (55 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeQuorumRequestV1Parser>(context);
  }
  if (56 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterPartitionRequestV0Parser>(context);
  }
  if (56 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterPartitionRequestV1Parser>(context);
  }
  if (56 == api_key
    && 2 == api_version) {
    return std::make_shared<AlterPartitionRequestV2Parser>(context);
  }
  if (56 == api_key
    && 3 == api_version) {
    return std::make_shared<AlterPartitionRequestV3Parser>(context);
  }
  if (57 == api_key
    && 0 == api_version) {
    return std::make_shared<UpdateFeaturesRequestV0Parser>(context);
  }
  if (57 == api_key
    && 1 == api_version) {
    return std::make_shared<UpdateFeaturesRequestV1Parser>(context);
  }
  if (58 == api_key
    && 0 == api_version) {
    return std::make_shared<EnvelopeRequestV0Parser>(context);
  }
  if (59 == api_key
    && 0 == api_version) {
    return std::make_shared<FetchSnapshotRequestV0Parser>(context);
  }
  if (60 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeClusterRequestV0Parser>(context);
  }
  if (61 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeProducersRequestV0Parser>(context);
  }
  if (62 == api_key
    && 0 == api_version) {
    return std::make_shared<BrokerRegistrationRequestV0Parser>(context);
  }
  if (62 == api_key
    && 1 == api_version) {
    return std::make_shared<BrokerRegistrationRequestV1Parser>(context);
  }
  if (63 == api_key
    && 0 == api_version) {
    return std::make_shared<BrokerHeartbeatRequestV0Parser>(context);
  }
  if (64 == api_key
    && 0 == api_version) {
    return std::make_shared<UnregisterBrokerRequestV0Parser>(context);
  }
  if (65 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeTransactionsRequestV0Parser>(context);
  }
  if (66 == api_key
    && 0 == api_version) {
    return std::make_shared<ListTransactionsRequestV0Parser>(context);
  }
  if (67 == api_key
    && 0 == api_version) {
    return std::make_shared<AllocateProducerIdsRequestV0Parser>(context);
  }
  return std::make_shared<SentinelParser>(context);
}

} // namespace Kafka
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy