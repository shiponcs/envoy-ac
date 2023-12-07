
#include "contrib/kafka/filters/network/source/external/responses.h"
#include "contrib/kafka/filters/network/source/kafka_response_parser.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace Kafka {

// Implements declaration from 'kafka_response.h'.
bool responseUsesTaggedFieldsInHeader(const uint16_t api_key, const uint16_t api_version) {
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
 * Creates a parser that is going to process data specific for given response.
 * If corresponding parser cannot be found (what means a newer version of Kafka protocol),
 * a sentinel parser is returned.
 * @param context parse context (carries the expected message type information).
 * @return parser that is capable of properly consuming response bytes.
 */
ResponseParserSharedPtr ResponseParserResolver::createParser(
  ResponseContextSharedPtr context) const {

  const int16_t api_key = context->api_key_;
  const int16_t api_version = context->api_version_;


  if (0 == api_key
    && 0 == api_version) {
    return std::make_shared<ProduceResponseV0Parser>(context);
  }
  if (0 == api_key
    && 1 == api_version) {
    return std::make_shared<ProduceResponseV1Parser>(context);
  }
  if (0 == api_key
    && 2 == api_version) {
    return std::make_shared<ProduceResponseV2Parser>(context);
  }
  if (0 == api_key
    && 3 == api_version) {
    return std::make_shared<ProduceResponseV3Parser>(context);
  }
  if (0 == api_key
    && 4 == api_version) {
    return std::make_shared<ProduceResponseV4Parser>(context);
  }
  if (0 == api_key
    && 5 == api_version) {
    return std::make_shared<ProduceResponseV5Parser>(context);
  }
  if (0 == api_key
    && 6 == api_version) {
    return std::make_shared<ProduceResponseV6Parser>(context);
  }
  if (0 == api_key
    && 7 == api_version) {
    return std::make_shared<ProduceResponseV7Parser>(context);
  }
  if (0 == api_key
    && 8 == api_version) {
    return std::make_shared<ProduceResponseV8Parser>(context);
  }
  if (0 == api_key
    && 9 == api_version) {
    return std::make_shared<ProduceResponseV9Parser>(context);
  }
  if (1 == api_key
    && 0 == api_version) {
    return std::make_shared<FetchResponseV0Parser>(context);
  }
  if (1 == api_key
    && 1 == api_version) {
    return std::make_shared<FetchResponseV1Parser>(context);
  }
  if (1 == api_key
    && 2 == api_version) {
    return std::make_shared<FetchResponseV2Parser>(context);
  }
  if (1 == api_key
    && 3 == api_version) {
    return std::make_shared<FetchResponseV3Parser>(context);
  }
  if (1 == api_key
    && 4 == api_version) {
    return std::make_shared<FetchResponseV4Parser>(context);
  }
  if (1 == api_key
    && 5 == api_version) {
    return std::make_shared<FetchResponseV5Parser>(context);
  }
  if (1 == api_key
    && 6 == api_version) {
    return std::make_shared<FetchResponseV6Parser>(context);
  }
  if (1 == api_key
    && 7 == api_version) {
    return std::make_shared<FetchResponseV7Parser>(context);
  }
  if (1 == api_key
    && 8 == api_version) {
    return std::make_shared<FetchResponseV8Parser>(context);
  }
  if (1 == api_key
    && 9 == api_version) {
    return std::make_shared<FetchResponseV9Parser>(context);
  }
  if (1 == api_key
    && 10 == api_version) {
    return std::make_shared<FetchResponseV10Parser>(context);
  }
  if (1 == api_key
    && 11 == api_version) {
    return std::make_shared<FetchResponseV11Parser>(context);
  }
  if (1 == api_key
    && 12 == api_version) {
    return std::make_shared<FetchResponseV12Parser>(context);
  }
  if (1 == api_key
    && 13 == api_version) {
    return std::make_shared<FetchResponseV13Parser>(context);
  }
  if (1 == api_key
    && 14 == api_version) {
    return std::make_shared<FetchResponseV14Parser>(context);
  }
  if (1 == api_key
    && 15 == api_version) {
    return std::make_shared<FetchResponseV15Parser>(context);
  }
  if (2 == api_key
    && 0 == api_version) {
    return std::make_shared<ListOffsetsResponseV0Parser>(context);
  }
  if (2 == api_key
    && 1 == api_version) {
    return std::make_shared<ListOffsetsResponseV1Parser>(context);
  }
  if (2 == api_key
    && 2 == api_version) {
    return std::make_shared<ListOffsetsResponseV2Parser>(context);
  }
  if (2 == api_key
    && 3 == api_version) {
    return std::make_shared<ListOffsetsResponseV3Parser>(context);
  }
  if (2 == api_key
    && 4 == api_version) {
    return std::make_shared<ListOffsetsResponseV4Parser>(context);
  }
  if (2 == api_key
    && 5 == api_version) {
    return std::make_shared<ListOffsetsResponseV5Parser>(context);
  }
  if (2 == api_key
    && 6 == api_version) {
    return std::make_shared<ListOffsetsResponseV6Parser>(context);
  }
  if (2 == api_key
    && 7 == api_version) {
    return std::make_shared<ListOffsetsResponseV7Parser>(context);
  }
  if (2 == api_key
    && 8 == api_version) {
    return std::make_shared<ListOffsetsResponseV8Parser>(context);
  }
  if (3 == api_key
    && 0 == api_version) {
    return std::make_shared<MetadataResponseV0Parser>(context);
  }
  if (3 == api_key
    && 1 == api_version) {
    return std::make_shared<MetadataResponseV1Parser>(context);
  }
  if (3 == api_key
    && 2 == api_version) {
    return std::make_shared<MetadataResponseV2Parser>(context);
  }
  if (3 == api_key
    && 3 == api_version) {
    return std::make_shared<MetadataResponseV3Parser>(context);
  }
  if (3 == api_key
    && 4 == api_version) {
    return std::make_shared<MetadataResponseV4Parser>(context);
  }
  if (3 == api_key
    && 5 == api_version) {
    return std::make_shared<MetadataResponseV5Parser>(context);
  }
  if (3 == api_key
    && 6 == api_version) {
    return std::make_shared<MetadataResponseV6Parser>(context);
  }
  if (3 == api_key
    && 7 == api_version) {
    return std::make_shared<MetadataResponseV7Parser>(context);
  }
  if (3 == api_key
    && 8 == api_version) {
    return std::make_shared<MetadataResponseV8Parser>(context);
  }
  if (3 == api_key
    && 9 == api_version) {
    return std::make_shared<MetadataResponseV9Parser>(context);
  }
  if (3 == api_key
    && 10 == api_version) {
    return std::make_shared<MetadataResponseV10Parser>(context);
  }
  if (3 == api_key
    && 11 == api_version) {
    return std::make_shared<MetadataResponseV11Parser>(context);
  }
  if (3 == api_key
    && 12 == api_version) {
    return std::make_shared<MetadataResponseV12Parser>(context);
  }
  if (4 == api_key
    && 0 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV0Parser>(context);
  }
  if (4 == api_key
    && 1 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV1Parser>(context);
  }
  if (4 == api_key
    && 2 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV2Parser>(context);
  }
  if (4 == api_key
    && 3 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV3Parser>(context);
  }
  if (4 == api_key
    && 4 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV4Parser>(context);
  }
  if (4 == api_key
    && 5 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV5Parser>(context);
  }
  if (4 == api_key
    && 6 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV6Parser>(context);
  }
  if (4 == api_key
    && 7 == api_version) {
    return std::make_shared<LeaderAndIsrResponseV7Parser>(context);
  }
  if (5 == api_key
    && 0 == api_version) {
    return std::make_shared<StopReplicaResponseV0Parser>(context);
  }
  if (5 == api_key
    && 1 == api_version) {
    return std::make_shared<StopReplicaResponseV1Parser>(context);
  }
  if (5 == api_key
    && 2 == api_version) {
    return std::make_shared<StopReplicaResponseV2Parser>(context);
  }
  if (5 == api_key
    && 3 == api_version) {
    return std::make_shared<StopReplicaResponseV3Parser>(context);
  }
  if (5 == api_key
    && 4 == api_version) {
    return std::make_shared<StopReplicaResponseV4Parser>(context);
  }
  if (6 == api_key
    && 0 == api_version) {
    return std::make_shared<UpdateMetadataResponseV0Parser>(context);
  }
  if (6 == api_key
    && 1 == api_version) {
    return std::make_shared<UpdateMetadataResponseV1Parser>(context);
  }
  if (6 == api_key
    && 2 == api_version) {
    return std::make_shared<UpdateMetadataResponseV2Parser>(context);
  }
  if (6 == api_key
    && 3 == api_version) {
    return std::make_shared<UpdateMetadataResponseV3Parser>(context);
  }
  if (6 == api_key
    && 4 == api_version) {
    return std::make_shared<UpdateMetadataResponseV4Parser>(context);
  }
  if (6 == api_key
    && 5 == api_version) {
    return std::make_shared<UpdateMetadataResponseV5Parser>(context);
  }
  if (6 == api_key
    && 6 == api_version) {
    return std::make_shared<UpdateMetadataResponseV6Parser>(context);
  }
  if (6 == api_key
    && 7 == api_version) {
    return std::make_shared<UpdateMetadataResponseV7Parser>(context);
  }
  if (6 == api_key
    && 8 == api_version) {
    return std::make_shared<UpdateMetadataResponseV8Parser>(context);
  }
  if (7 == api_key
    && 0 == api_version) {
    return std::make_shared<ControlledShutdownResponseV0Parser>(context);
  }
  if (7 == api_key
    && 1 == api_version) {
    return std::make_shared<ControlledShutdownResponseV1Parser>(context);
  }
  if (7 == api_key
    && 2 == api_version) {
    return std::make_shared<ControlledShutdownResponseV2Parser>(context);
  }
  if (7 == api_key
    && 3 == api_version) {
    return std::make_shared<ControlledShutdownResponseV3Parser>(context);
  }
  if (8 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetCommitResponseV0Parser>(context);
  }
  if (8 == api_key
    && 1 == api_version) {
    return std::make_shared<OffsetCommitResponseV1Parser>(context);
  }
  if (8 == api_key
    && 2 == api_version) {
    return std::make_shared<OffsetCommitResponseV2Parser>(context);
  }
  if (8 == api_key
    && 3 == api_version) {
    return std::make_shared<OffsetCommitResponseV3Parser>(context);
  }
  if (8 == api_key
    && 4 == api_version) {
    return std::make_shared<OffsetCommitResponseV4Parser>(context);
  }
  if (8 == api_key
    && 5 == api_version) {
    return std::make_shared<OffsetCommitResponseV5Parser>(context);
  }
  if (8 == api_key
    && 6 == api_version) {
    return std::make_shared<OffsetCommitResponseV6Parser>(context);
  }
  if (8 == api_key
    && 7 == api_version) {
    return std::make_shared<OffsetCommitResponseV7Parser>(context);
  }
  if (8 == api_key
    && 8 == api_version) {
    return std::make_shared<OffsetCommitResponseV8Parser>(context);
  }
  if (9 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetFetchResponseV0Parser>(context);
  }
  if (9 == api_key
    && 1 == api_version) {
    return std::make_shared<OffsetFetchResponseV1Parser>(context);
  }
  if (9 == api_key
    && 2 == api_version) {
    return std::make_shared<OffsetFetchResponseV2Parser>(context);
  }
  if (9 == api_key
    && 3 == api_version) {
    return std::make_shared<OffsetFetchResponseV3Parser>(context);
  }
  if (9 == api_key
    && 4 == api_version) {
    return std::make_shared<OffsetFetchResponseV4Parser>(context);
  }
  if (9 == api_key
    && 5 == api_version) {
    return std::make_shared<OffsetFetchResponseV5Parser>(context);
  }
  if (9 == api_key
    && 6 == api_version) {
    return std::make_shared<OffsetFetchResponseV6Parser>(context);
  }
  if (9 == api_key
    && 7 == api_version) {
    return std::make_shared<OffsetFetchResponseV7Parser>(context);
  }
  if (9 == api_key
    && 8 == api_version) {
    return std::make_shared<OffsetFetchResponseV8Parser>(context);
  }
  if (10 == api_key
    && 0 == api_version) {
    return std::make_shared<FindCoordinatorResponseV0Parser>(context);
  }
  if (10 == api_key
    && 1 == api_version) {
    return std::make_shared<FindCoordinatorResponseV1Parser>(context);
  }
  if (10 == api_key
    && 2 == api_version) {
    return std::make_shared<FindCoordinatorResponseV2Parser>(context);
  }
  if (10 == api_key
    && 3 == api_version) {
    return std::make_shared<FindCoordinatorResponseV3Parser>(context);
  }
  if (10 == api_key
    && 4 == api_version) {
    return std::make_shared<FindCoordinatorResponseV4Parser>(context);
  }
  if (11 == api_key
    && 0 == api_version) {
    return std::make_shared<JoinGroupResponseV0Parser>(context);
  }
  if (11 == api_key
    && 1 == api_version) {
    return std::make_shared<JoinGroupResponseV1Parser>(context);
  }
  if (11 == api_key
    && 2 == api_version) {
    return std::make_shared<JoinGroupResponseV2Parser>(context);
  }
  if (11 == api_key
    && 3 == api_version) {
    return std::make_shared<JoinGroupResponseV3Parser>(context);
  }
  if (11 == api_key
    && 4 == api_version) {
    return std::make_shared<JoinGroupResponseV4Parser>(context);
  }
  if (11 == api_key
    && 5 == api_version) {
    return std::make_shared<JoinGroupResponseV5Parser>(context);
  }
  if (11 == api_key
    && 6 == api_version) {
    return std::make_shared<JoinGroupResponseV6Parser>(context);
  }
  if (11 == api_key
    && 7 == api_version) {
    return std::make_shared<JoinGroupResponseV7Parser>(context);
  }
  if (11 == api_key
    && 8 == api_version) {
    return std::make_shared<JoinGroupResponseV8Parser>(context);
  }
  if (11 == api_key
    && 9 == api_version) {
    return std::make_shared<JoinGroupResponseV9Parser>(context);
  }
  if (12 == api_key
    && 0 == api_version) {
    return std::make_shared<HeartbeatResponseV0Parser>(context);
  }
  if (12 == api_key
    && 1 == api_version) {
    return std::make_shared<HeartbeatResponseV1Parser>(context);
  }
  if (12 == api_key
    && 2 == api_version) {
    return std::make_shared<HeartbeatResponseV2Parser>(context);
  }
  if (12 == api_key
    && 3 == api_version) {
    return std::make_shared<HeartbeatResponseV3Parser>(context);
  }
  if (12 == api_key
    && 4 == api_version) {
    return std::make_shared<HeartbeatResponseV4Parser>(context);
  }
  if (13 == api_key
    && 0 == api_version) {
    return std::make_shared<LeaveGroupResponseV0Parser>(context);
  }
  if (13 == api_key
    && 1 == api_version) {
    return std::make_shared<LeaveGroupResponseV1Parser>(context);
  }
  if (13 == api_key
    && 2 == api_version) {
    return std::make_shared<LeaveGroupResponseV2Parser>(context);
  }
  if (13 == api_key
    && 3 == api_version) {
    return std::make_shared<LeaveGroupResponseV3Parser>(context);
  }
  if (13 == api_key
    && 4 == api_version) {
    return std::make_shared<LeaveGroupResponseV4Parser>(context);
  }
  if (13 == api_key
    && 5 == api_version) {
    return std::make_shared<LeaveGroupResponseV5Parser>(context);
  }
  if (14 == api_key
    && 0 == api_version) {
    return std::make_shared<SyncGroupResponseV0Parser>(context);
  }
  if (14 == api_key
    && 1 == api_version) {
    return std::make_shared<SyncGroupResponseV1Parser>(context);
  }
  if (14 == api_key
    && 2 == api_version) {
    return std::make_shared<SyncGroupResponseV2Parser>(context);
  }
  if (14 == api_key
    && 3 == api_version) {
    return std::make_shared<SyncGroupResponseV3Parser>(context);
  }
  if (14 == api_key
    && 4 == api_version) {
    return std::make_shared<SyncGroupResponseV4Parser>(context);
  }
  if (14 == api_key
    && 5 == api_version) {
    return std::make_shared<SyncGroupResponseV5Parser>(context);
  }
  if (15 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeGroupsResponseV0Parser>(context);
  }
  if (15 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeGroupsResponseV1Parser>(context);
  }
  if (15 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeGroupsResponseV2Parser>(context);
  }
  if (15 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeGroupsResponseV3Parser>(context);
  }
  if (15 == api_key
    && 4 == api_version) {
    return std::make_shared<DescribeGroupsResponseV4Parser>(context);
  }
  if (15 == api_key
    && 5 == api_version) {
    return std::make_shared<DescribeGroupsResponseV5Parser>(context);
  }
  if (16 == api_key
    && 0 == api_version) {
    return std::make_shared<ListGroupsResponseV0Parser>(context);
  }
  if (16 == api_key
    && 1 == api_version) {
    return std::make_shared<ListGroupsResponseV1Parser>(context);
  }
  if (16 == api_key
    && 2 == api_version) {
    return std::make_shared<ListGroupsResponseV2Parser>(context);
  }
  if (16 == api_key
    && 3 == api_version) {
    return std::make_shared<ListGroupsResponseV3Parser>(context);
  }
  if (16 == api_key
    && 4 == api_version) {
    return std::make_shared<ListGroupsResponseV4Parser>(context);
  }
  if (17 == api_key
    && 0 == api_version) {
    return std::make_shared<SaslHandshakeResponseV0Parser>(context);
  }
  if (17 == api_key
    && 1 == api_version) {
    return std::make_shared<SaslHandshakeResponseV1Parser>(context);
  }
  if (18 == api_key
    && 0 == api_version) {
    return std::make_shared<ApiVersionsResponseV0Parser>(context);
  }
  if (18 == api_key
    && 1 == api_version) {
    return std::make_shared<ApiVersionsResponseV1Parser>(context);
  }
  if (18 == api_key
    && 2 == api_version) {
    return std::make_shared<ApiVersionsResponseV2Parser>(context);
  }
  if (18 == api_key
    && 3 == api_version) {
    return std::make_shared<ApiVersionsResponseV3Parser>(context);
  }
  if (19 == api_key
    && 0 == api_version) {
    return std::make_shared<CreateTopicsResponseV0Parser>(context);
  }
  if (19 == api_key
    && 1 == api_version) {
    return std::make_shared<CreateTopicsResponseV1Parser>(context);
  }
  if (19 == api_key
    && 2 == api_version) {
    return std::make_shared<CreateTopicsResponseV2Parser>(context);
  }
  if (19 == api_key
    && 3 == api_version) {
    return std::make_shared<CreateTopicsResponseV3Parser>(context);
  }
  if (19 == api_key
    && 4 == api_version) {
    return std::make_shared<CreateTopicsResponseV4Parser>(context);
  }
  if (19 == api_key
    && 5 == api_version) {
    return std::make_shared<CreateTopicsResponseV5Parser>(context);
  }
  if (19 == api_key
    && 6 == api_version) {
    return std::make_shared<CreateTopicsResponseV6Parser>(context);
  }
  if (19 == api_key
    && 7 == api_version) {
    return std::make_shared<CreateTopicsResponseV7Parser>(context);
  }
  if (20 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteTopicsResponseV0Parser>(context);
  }
  if (20 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteTopicsResponseV1Parser>(context);
  }
  if (20 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteTopicsResponseV2Parser>(context);
  }
  if (20 == api_key
    && 3 == api_version) {
    return std::make_shared<DeleteTopicsResponseV3Parser>(context);
  }
  if (20 == api_key
    && 4 == api_version) {
    return std::make_shared<DeleteTopicsResponseV4Parser>(context);
  }
  if (20 == api_key
    && 5 == api_version) {
    return std::make_shared<DeleteTopicsResponseV5Parser>(context);
  }
  if (20 == api_key
    && 6 == api_version) {
    return std::make_shared<DeleteTopicsResponseV6Parser>(context);
  }
  if (21 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteRecordsResponseV0Parser>(context);
  }
  if (21 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteRecordsResponseV1Parser>(context);
  }
  if (21 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteRecordsResponseV2Parser>(context);
  }
  if (22 == api_key
    && 0 == api_version) {
    return std::make_shared<InitProducerIdResponseV0Parser>(context);
  }
  if (22 == api_key
    && 1 == api_version) {
    return std::make_shared<InitProducerIdResponseV1Parser>(context);
  }
  if (22 == api_key
    && 2 == api_version) {
    return std::make_shared<InitProducerIdResponseV2Parser>(context);
  }
  if (22 == api_key
    && 3 == api_version) {
    return std::make_shared<InitProducerIdResponseV3Parser>(context);
  }
  if (22 == api_key
    && 4 == api_version) {
    return std::make_shared<InitProducerIdResponseV4Parser>(context);
  }
  if (23 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetForLeaderEpochResponseV0Parser>(context);
  }
  if (23 == api_key
    && 1 == api_version) {
    return std::make_shared<OffsetForLeaderEpochResponseV1Parser>(context);
  }
  if (23 == api_key
    && 2 == api_version) {
    return std::make_shared<OffsetForLeaderEpochResponseV2Parser>(context);
  }
  if (23 == api_key
    && 3 == api_version) {
    return std::make_shared<OffsetForLeaderEpochResponseV3Parser>(context);
  }
  if (23 == api_key
    && 4 == api_version) {
    return std::make_shared<OffsetForLeaderEpochResponseV4Parser>(context);
  }
  if (24 == api_key
    && 0 == api_version) {
    return std::make_shared<AddPartitionsToTxnResponseV0Parser>(context);
  }
  if (24 == api_key
    && 1 == api_version) {
    return std::make_shared<AddPartitionsToTxnResponseV1Parser>(context);
  }
  if (24 == api_key
    && 2 == api_version) {
    return std::make_shared<AddPartitionsToTxnResponseV2Parser>(context);
  }
  if (24 == api_key
    && 3 == api_version) {
    return std::make_shared<AddPartitionsToTxnResponseV3Parser>(context);
  }
  if (24 == api_key
    && 4 == api_version) {
    return std::make_shared<AddPartitionsToTxnResponseV4Parser>(context);
  }
  if (25 == api_key
    && 0 == api_version) {
    return std::make_shared<AddOffsetsToTxnResponseV0Parser>(context);
  }
  if (25 == api_key
    && 1 == api_version) {
    return std::make_shared<AddOffsetsToTxnResponseV1Parser>(context);
  }
  if (25 == api_key
    && 2 == api_version) {
    return std::make_shared<AddOffsetsToTxnResponseV2Parser>(context);
  }
  if (25 == api_key
    && 3 == api_version) {
    return std::make_shared<AddOffsetsToTxnResponseV3Parser>(context);
  }
  if (26 == api_key
    && 0 == api_version) {
    return std::make_shared<EndTxnResponseV0Parser>(context);
  }
  if (26 == api_key
    && 1 == api_version) {
    return std::make_shared<EndTxnResponseV1Parser>(context);
  }
  if (26 == api_key
    && 2 == api_version) {
    return std::make_shared<EndTxnResponseV2Parser>(context);
  }
  if (26 == api_key
    && 3 == api_version) {
    return std::make_shared<EndTxnResponseV3Parser>(context);
  }
  if (27 == api_key
    && 0 == api_version) {
    return std::make_shared<WriteTxnMarkersResponseV0Parser>(context);
  }
  if (27 == api_key
    && 1 == api_version) {
    return std::make_shared<WriteTxnMarkersResponseV1Parser>(context);
  }
  if (28 == api_key
    && 0 == api_version) {
    return std::make_shared<TxnOffsetCommitResponseV0Parser>(context);
  }
  if (28 == api_key
    && 1 == api_version) {
    return std::make_shared<TxnOffsetCommitResponseV1Parser>(context);
  }
  if (28 == api_key
    && 2 == api_version) {
    return std::make_shared<TxnOffsetCommitResponseV2Parser>(context);
  }
  if (28 == api_key
    && 3 == api_version) {
    return std::make_shared<TxnOffsetCommitResponseV3Parser>(context);
  }
  if (29 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeAclsResponseV0Parser>(context);
  }
  if (29 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeAclsResponseV1Parser>(context);
  }
  if (29 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeAclsResponseV2Parser>(context);
  }
  if (29 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeAclsResponseV3Parser>(context);
  }
  if (30 == api_key
    && 0 == api_version) {
    return std::make_shared<CreateAclsResponseV0Parser>(context);
  }
  if (30 == api_key
    && 1 == api_version) {
    return std::make_shared<CreateAclsResponseV1Parser>(context);
  }
  if (30 == api_key
    && 2 == api_version) {
    return std::make_shared<CreateAclsResponseV2Parser>(context);
  }
  if (30 == api_key
    && 3 == api_version) {
    return std::make_shared<CreateAclsResponseV3Parser>(context);
  }
  if (31 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteAclsResponseV0Parser>(context);
  }
  if (31 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteAclsResponseV1Parser>(context);
  }
  if (31 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteAclsResponseV2Parser>(context);
  }
  if (31 == api_key
    && 3 == api_version) {
    return std::make_shared<DeleteAclsResponseV3Parser>(context);
  }
  if (32 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeConfigsResponseV0Parser>(context);
  }
  if (32 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeConfigsResponseV1Parser>(context);
  }
  if (32 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeConfigsResponseV2Parser>(context);
  }
  if (32 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeConfigsResponseV3Parser>(context);
  }
  if (32 == api_key
    && 4 == api_version) {
    return std::make_shared<DescribeConfigsResponseV4Parser>(context);
  }
  if (33 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterConfigsResponseV0Parser>(context);
  }
  if (33 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterConfigsResponseV1Parser>(context);
  }
  if (33 == api_key
    && 2 == api_version) {
    return std::make_shared<AlterConfigsResponseV2Parser>(context);
  }
  if (34 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterReplicaLogDirsResponseV0Parser>(context);
  }
  if (34 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterReplicaLogDirsResponseV1Parser>(context);
  }
  if (34 == api_key
    && 2 == api_version) {
    return std::make_shared<AlterReplicaLogDirsResponseV2Parser>(context);
  }
  if (35 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeLogDirsResponseV0Parser>(context);
  }
  if (35 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeLogDirsResponseV1Parser>(context);
  }
  if (35 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeLogDirsResponseV2Parser>(context);
  }
  if (35 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeLogDirsResponseV3Parser>(context);
  }
  if (35 == api_key
    && 4 == api_version) {
    return std::make_shared<DescribeLogDirsResponseV4Parser>(context);
  }
  if (36 == api_key
    && 0 == api_version) {
    return std::make_shared<SaslAuthenticateResponseV0Parser>(context);
  }
  if (36 == api_key
    && 1 == api_version) {
    return std::make_shared<SaslAuthenticateResponseV1Parser>(context);
  }
  if (36 == api_key
    && 2 == api_version) {
    return std::make_shared<SaslAuthenticateResponseV2Parser>(context);
  }
  if (37 == api_key
    && 0 == api_version) {
    return std::make_shared<CreatePartitionsResponseV0Parser>(context);
  }
  if (37 == api_key
    && 1 == api_version) {
    return std::make_shared<CreatePartitionsResponseV1Parser>(context);
  }
  if (37 == api_key
    && 2 == api_version) {
    return std::make_shared<CreatePartitionsResponseV2Parser>(context);
  }
  if (37 == api_key
    && 3 == api_version) {
    return std::make_shared<CreatePartitionsResponseV3Parser>(context);
  }
  if (38 == api_key
    && 0 == api_version) {
    return std::make_shared<CreateDelegationTokenResponseV0Parser>(context);
  }
  if (38 == api_key
    && 1 == api_version) {
    return std::make_shared<CreateDelegationTokenResponseV1Parser>(context);
  }
  if (38 == api_key
    && 2 == api_version) {
    return std::make_shared<CreateDelegationTokenResponseV2Parser>(context);
  }
  if (38 == api_key
    && 3 == api_version) {
    return std::make_shared<CreateDelegationTokenResponseV3Parser>(context);
  }
  if (39 == api_key
    && 0 == api_version) {
    return std::make_shared<RenewDelegationTokenResponseV0Parser>(context);
  }
  if (39 == api_key
    && 1 == api_version) {
    return std::make_shared<RenewDelegationTokenResponseV1Parser>(context);
  }
  if (39 == api_key
    && 2 == api_version) {
    return std::make_shared<RenewDelegationTokenResponseV2Parser>(context);
  }
  if (40 == api_key
    && 0 == api_version) {
    return std::make_shared<ExpireDelegationTokenResponseV0Parser>(context);
  }
  if (40 == api_key
    && 1 == api_version) {
    return std::make_shared<ExpireDelegationTokenResponseV1Parser>(context);
  }
  if (40 == api_key
    && 2 == api_version) {
    return std::make_shared<ExpireDelegationTokenResponseV2Parser>(context);
  }
  if (41 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeDelegationTokenResponseV0Parser>(context);
  }
  if (41 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeDelegationTokenResponseV1Parser>(context);
  }
  if (41 == api_key
    && 2 == api_version) {
    return std::make_shared<DescribeDelegationTokenResponseV2Parser>(context);
  }
  if (41 == api_key
    && 3 == api_version) {
    return std::make_shared<DescribeDelegationTokenResponseV3Parser>(context);
  }
  if (42 == api_key
    && 0 == api_version) {
    return std::make_shared<DeleteGroupsResponseV0Parser>(context);
  }
  if (42 == api_key
    && 1 == api_version) {
    return std::make_shared<DeleteGroupsResponseV1Parser>(context);
  }
  if (42 == api_key
    && 2 == api_version) {
    return std::make_shared<DeleteGroupsResponseV2Parser>(context);
  }
  if (43 == api_key
    && 0 == api_version) {
    return std::make_shared<ElectLeadersResponseV0Parser>(context);
  }
  if (43 == api_key
    && 1 == api_version) {
    return std::make_shared<ElectLeadersResponseV1Parser>(context);
  }
  if (43 == api_key
    && 2 == api_version) {
    return std::make_shared<ElectLeadersResponseV2Parser>(context);
  }
  if (44 == api_key
    && 0 == api_version) {
    return std::make_shared<IncrementalAlterConfigsResponseV0Parser>(context);
  }
  if (44 == api_key
    && 1 == api_version) {
    return std::make_shared<IncrementalAlterConfigsResponseV1Parser>(context);
  }
  if (45 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterPartitionReassignmentsResponseV0Parser>(context);
  }
  if (46 == api_key
    && 0 == api_version) {
    return std::make_shared<ListPartitionReassignmentsResponseV0Parser>(context);
  }
  if (47 == api_key
    && 0 == api_version) {
    return std::make_shared<OffsetDeleteResponseV0Parser>(context);
  }
  if (48 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeClientQuotasResponseV0Parser>(context);
  }
  if (48 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeClientQuotasResponseV1Parser>(context);
  }
  if (49 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterClientQuotasResponseV0Parser>(context);
  }
  if (49 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterClientQuotasResponseV1Parser>(context);
  }
  if (50 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeUserScramCredentialsResponseV0Parser>(context);
  }
  if (51 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterUserScramCredentialsResponseV0Parser>(context);
  }
  if (52 == api_key
    && 0 == api_version) {
    return std::make_shared<VoteResponseV0Parser>(context);
  }
  if (53 == api_key
    && 0 == api_version) {
    return std::make_shared<BeginQuorumEpochResponseV0Parser>(context);
  }
  if (54 == api_key
    && 0 == api_version) {
    return std::make_shared<EndQuorumEpochResponseV0Parser>(context);
  }
  if (55 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeQuorumResponseV0Parser>(context);
  }
  if (55 == api_key
    && 1 == api_version) {
    return std::make_shared<DescribeQuorumResponseV1Parser>(context);
  }
  if (56 == api_key
    && 0 == api_version) {
    return std::make_shared<AlterPartitionResponseV0Parser>(context);
  }
  if (56 == api_key
    && 1 == api_version) {
    return std::make_shared<AlterPartitionResponseV1Parser>(context);
  }
  if (56 == api_key
    && 2 == api_version) {
    return std::make_shared<AlterPartitionResponseV2Parser>(context);
  }
  if (56 == api_key
    && 3 == api_version) {
    return std::make_shared<AlterPartitionResponseV3Parser>(context);
  }
  if (57 == api_key
    && 0 == api_version) {
    return std::make_shared<UpdateFeaturesResponseV0Parser>(context);
  }
  if (57 == api_key
    && 1 == api_version) {
    return std::make_shared<UpdateFeaturesResponseV1Parser>(context);
  }
  if (58 == api_key
    && 0 == api_version) {
    return std::make_shared<EnvelopeResponseV0Parser>(context);
  }
  if (59 == api_key
    && 0 == api_version) {
    return std::make_shared<FetchSnapshotResponseV0Parser>(context);
  }
  if (60 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeClusterResponseV0Parser>(context);
  }
  if (61 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeProducersResponseV0Parser>(context);
  }
  if (62 == api_key
    && 0 == api_version) {
    return std::make_shared<BrokerRegistrationResponseV0Parser>(context);
  }
  if (62 == api_key
    && 1 == api_version) {
    return std::make_shared<BrokerRegistrationResponseV1Parser>(context);
  }
  if (63 == api_key
    && 0 == api_version) {
    return std::make_shared<BrokerHeartbeatResponseV0Parser>(context);
  }
  if (64 == api_key
    && 0 == api_version) {
    return std::make_shared<UnregisterBrokerResponseV0Parser>(context);
  }
  if (65 == api_key
    && 0 == api_version) {
    return std::make_shared<DescribeTransactionsResponseV0Parser>(context);
  }
  if (66 == api_key
    && 0 == api_version) {
    return std::make_shared<ListTransactionsResponseV0Parser>(context);
  }
  if (67 == api_key
    && 0 == api_version) {
    return std::make_shared<AllocateProducerIdsResponseV0Parser>(context);
  }
  return std::make_shared<SentinelResponseParser>(context);
}

} // namespace Kafka
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy