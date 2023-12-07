
#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <vector>

#include "envoy/buffer/buffer.h"
#include "envoy/common/exception.h"
#include "envoy/common/pure.h"

#include "source/common/common/byte_order.h"
#include "source/common/common/fmt.h"

#include "contrib/kafka/filters/network/source/kafka_types.h"
#include "contrib/kafka/filters/network/source/serialization.h"

#include "absl/strings/string_view.h"

namespace Envoy {
namespace Extensions {
namespace NetworkFilters {
namespace Kafka {

/**
 * This header contains only composite deserializers.
 * The basic design is composite deserializer creating delegates DeserializerType1..N.
 * Result of type ResponseType is constructed by getting results of each of delegates.
 * These deserializers can throw, if any of the delegate deserializers can.
 */

/**
 * Composite deserializer that uses 0 deserializer(s) (corner case).
 * Does not consume any bytes, and is always ready to return the result.
 * Creates a result value using the no-arg ResponseType constructor.
 * @param ResponseType type of deserialized data.
 */
template <typename ResponseType>
class CompositeDeserializerWith0Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith0Delegates(){};
  uint32_t feed(absl::string_view&) override { return 0; }
  bool ready() const override { return true; }
  ResponseType get() const override { return {}; }
};


/**
 * Composite deserializer that uses 1 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
 */
template <
  typename ResponseType,
  typename DeserializerType1
>
class CompositeDeserializerWith1Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith1Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate1_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
};

/**
 * Composite deserializer that uses 2 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2
>
class CompositeDeserializerWith2Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith2Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate2_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
};

/**
 * Composite deserializer that uses 3 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3
>
class CompositeDeserializerWith3Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith3Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate3_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
};

/**
 * Composite deserializer that uses 4 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4
>
class CompositeDeserializerWith4Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith4Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate4_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
};

/**
 * Composite deserializer that uses 5 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5
>
class CompositeDeserializerWith5Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith5Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate5_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
};

/**
 * Composite deserializer that uses 6 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
.
 * @param DeserializerType6 deserializer 6.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5,
  typename DeserializerType6
>
class CompositeDeserializerWith6Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith6Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    consumed += delegate6_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate6_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      delegate6_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
  DeserializerType6 delegate6_;
  
};

/**
 * Composite deserializer that uses 7 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
.
 * @param DeserializerType6 deserializer 6.
.
 * @param DeserializerType7 deserializer 7.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5,
  typename DeserializerType6,
  typename DeserializerType7
>
class CompositeDeserializerWith7Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith7Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    consumed += delegate6_.feed(data);
    
    consumed += delegate7_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate7_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      delegate6_.get(),
      delegate7_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
  DeserializerType6 delegate6_;
  
  DeserializerType7 delegate7_;
  
};

/**
 * Composite deserializer that uses 8 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
.
 * @param DeserializerType6 deserializer 6.
.
 * @param DeserializerType7 deserializer 7.
.
 * @param DeserializerType8 deserializer 8.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5,
  typename DeserializerType6,
  typename DeserializerType7,
  typename DeserializerType8
>
class CompositeDeserializerWith8Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith8Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    consumed += delegate6_.feed(data);
    
    consumed += delegate7_.feed(data);
    
    consumed += delegate8_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate8_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      delegate6_.get(),
      delegate7_.get(),
      delegate8_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
  DeserializerType6 delegate6_;
  
  DeserializerType7 delegate7_;
  
  DeserializerType8 delegate8_;
  
};

/**
 * Composite deserializer that uses 9 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
.
 * @param DeserializerType6 deserializer 6.
.
 * @param DeserializerType7 deserializer 7.
.
 * @param DeserializerType8 deserializer 8.
.
 * @param DeserializerType9 deserializer 9.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5,
  typename DeserializerType6,
  typename DeserializerType7,
  typename DeserializerType8,
  typename DeserializerType9
>
class CompositeDeserializerWith9Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith9Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    consumed += delegate6_.feed(data);
    
    consumed += delegate7_.feed(data);
    
    consumed += delegate8_.feed(data);
    
    consumed += delegate9_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate9_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      delegate6_.get(),
      delegate7_.get(),
      delegate8_.get(),
      delegate9_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
  DeserializerType6 delegate6_;
  
  DeserializerType7 delegate7_;
  
  DeserializerType8 delegate8_;
  
  DeserializerType9 delegate9_;
  
};

/**
 * Composite deserializer that uses 10 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
.
 * @param DeserializerType6 deserializer 6.
.
 * @param DeserializerType7 deserializer 7.
.
 * @param DeserializerType8 deserializer 8.
.
 * @param DeserializerType9 deserializer 9.
.
 * @param DeserializerType10 deserializer 10.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5,
  typename DeserializerType6,
  typename DeserializerType7,
  typename DeserializerType8,
  typename DeserializerType9,
  typename DeserializerType10
>
class CompositeDeserializerWith10Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith10Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    consumed += delegate6_.feed(data);
    
    consumed += delegate7_.feed(data);
    
    consumed += delegate8_.feed(data);
    
    consumed += delegate9_.feed(data);
    
    consumed += delegate10_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate10_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      delegate6_.get(),
      delegate7_.get(),
      delegate8_.get(),
      delegate9_.get(),
      delegate10_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
  DeserializerType6 delegate6_;
  
  DeserializerType7 delegate7_;
  
  DeserializerType8 delegate8_;
  
  DeserializerType9 delegate9_;
  
  DeserializerType10 delegate10_;
  
};

/**
 * Composite deserializer that uses 11 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
.
 * @param DeserializerType6 deserializer 6.
.
 * @param DeserializerType7 deserializer 7.
.
 * @param DeserializerType8 deserializer 8.
.
 * @param DeserializerType9 deserializer 9.
.
 * @param DeserializerType10 deserializer 10.
.
 * @param DeserializerType11 deserializer 11.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5,
  typename DeserializerType6,
  typename DeserializerType7,
  typename DeserializerType8,
  typename DeserializerType9,
  typename DeserializerType10,
  typename DeserializerType11
>
class CompositeDeserializerWith11Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith11Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    consumed += delegate6_.feed(data);
    
    consumed += delegate7_.feed(data);
    
    consumed += delegate8_.feed(data);
    
    consumed += delegate9_.feed(data);
    
    consumed += delegate10_.feed(data);
    
    consumed += delegate11_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate11_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      delegate6_.get(),
      delegate7_.get(),
      delegate8_.get(),
      delegate9_.get(),
      delegate10_.get(),
      delegate11_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
  DeserializerType6 delegate6_;
  
  DeserializerType7 delegate7_;
  
  DeserializerType8 delegate8_;
  
  DeserializerType9 delegate9_;
  
  DeserializerType10 delegate10_;
  
  DeserializerType11 delegate11_;
  
};

/**
 * Composite deserializer that uses 12 deserializer(s).
 * Passes data to each of the underlying deserializers (deserializers that are already ready do not
 * consume data, so it's safe).
 * The composite deserializer is ready when the last deserializer is ready (what means that all
 * deserializers before it are ready too).
 * Constructs the result of type ResponseType using { delegate1_.get(), delegate2_.get() ... }.
 *
 * @param ResponseType type of deserialized data.
 * @param DeserializerType1 deserializer 1.
.
 * @param DeserializerType2 deserializer 2.
.
 * @param DeserializerType3 deserializer 3.
.
 * @param DeserializerType4 deserializer 4.
.
 * @param DeserializerType5 deserializer 5.
.
 * @param DeserializerType6 deserializer 6.
.
 * @param DeserializerType7 deserializer 7.
.
 * @param DeserializerType8 deserializer 8.
.
 * @param DeserializerType9 deserializer 9.
.
 * @param DeserializerType10 deserializer 10.
.
 * @param DeserializerType11 deserializer 11.
.
 * @param DeserializerType12 deserializer 12.
 */
template <
  typename ResponseType,
  typename DeserializerType1,
  typename DeserializerType2,
  typename DeserializerType3,
  typename DeserializerType4,
  typename DeserializerType5,
  typename DeserializerType6,
  typename DeserializerType7,
  typename DeserializerType8,
  typename DeserializerType9,
  typename DeserializerType10,
  typename DeserializerType11,
  typename DeserializerType12
>
class CompositeDeserializerWith12Delegates : public Deserializer<ResponseType> {
public:
  CompositeDeserializerWith12Delegates(){};

  uint32_t feed(absl::string_view& data) override {
    uint32_t consumed = 0;
    
    consumed += delegate1_.feed(data);
    
    consumed += delegate2_.feed(data);
    
    consumed += delegate3_.feed(data);
    
    consumed += delegate4_.feed(data);
    
    consumed += delegate5_.feed(data);
    
    consumed += delegate6_.feed(data);
    
    consumed += delegate7_.feed(data);
    
    consumed += delegate8_.feed(data);
    
    consumed += delegate9_.feed(data);
    
    consumed += delegate10_.feed(data);
    
    consumed += delegate11_.feed(data);
    
    consumed += delegate12_.feed(data);
    
    return consumed;
  }

  bool ready() const override { return delegate12_.ready(); }

  ResponseType get() const override {
    return {
      delegate1_.get(),
      delegate2_.get(),
      delegate3_.get(),
      delegate4_.get(),
      delegate5_.get(),
      delegate6_.get(),
      delegate7_.get(),
      delegate8_.get(),
      delegate9_.get(),
      delegate10_.get(),
      delegate11_.get(),
      delegate12_.get(),
      };
  }

protected:
  
  DeserializerType1 delegate1_;
  
  DeserializerType2 delegate2_;
  
  DeserializerType3 delegate3_;
  
  DeserializerType4 delegate4_;
  
  DeserializerType5 delegate5_;
  
  DeserializerType6 delegate6_;
  
  DeserializerType7 delegate7_;
  
  DeserializerType8 delegate8_;
  
  DeserializerType9 delegate9_;
  
  DeserializerType10 delegate10_;
  
  DeserializerType11 delegate11_;
  
  DeserializerType12 delegate12_;
  
};


} // namespace Kafka
} // namespace NetworkFilters
} // namespace Extensions
} // namespace Envoy