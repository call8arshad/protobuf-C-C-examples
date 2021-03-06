/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: com/protocol/unitcom/vehicle.proto3 */

#ifndef PROTOBUF_C_com_2fprotocol_2funitcom_2fvehicle_2eproto3__INCLUDED
#define PROTOBUF_C_com_2fprotocol_2funitcom_2fvehicle_2eproto3__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "com/protocol/shared/gps_data.proto3.pb-c.h"

typedef struct _Com__Protocol__Unitcom__VehicleMessage Com__Protocol__Unitcom__VehicleMessage;
typedef struct _Com__Protocol__Unitcom__FleetMessage Com__Protocol__Unitcom__FleetMessage;


/* --- enums --- */

typedef enum _Com__Protocol__Unitcom__VehicleMessage__Type {
  COM__PROTOCOL__UNITCOM__VEHICLE_MESSAGE__TYPE__FLEET = 0
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(COM__PROTOCOL__UNITCOM__VEHICLE_MESSAGE__TYPE)
} Com__Protocol__Unitcom__VehicleMessage__Type;

/* --- messages --- */

struct  _Com__Protocol__Unitcom__VehicleMessage
{
  ProtobufCMessage base;
  protobuf_c_boolean has_type;
  Com__Protocol__Unitcom__VehicleMessage__Type type;
  protobuf_c_boolean has_timestamp;
  uint64_t timestamp;
  Com__Protocol__Unitcom__FleetMessage *fleet_message;
};
#define COM__PROTOCOL__UNITCOM__VEHICLE_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&com__protocol__unitcom__vehicle_message__descriptor) \
    , 0,(Com__Protocol__Unitcom__VehicleMessage__Type)0, 0,0, NULL }


struct  _Com__Protocol__Unitcom__FleetMessage
{
  ProtobufCMessage base;
  Com__Protocol__Shared__GpsData *gps;
};
#define COM__PROTOCOL__UNITCOM__FLEET_MESSAGE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&com__protocol__unitcom__fleet_message__descriptor) \
    , NULL }


/* Com__Protocol__Unitcom__VehicleMessage methods */
void   com__protocol__unitcom__vehicle_message__init
                     (Com__Protocol__Unitcom__VehicleMessage         *message);
size_t com__protocol__unitcom__vehicle_message__get_packed_size
                     (const Com__Protocol__Unitcom__VehicleMessage   *message);
size_t com__protocol__unitcom__vehicle_message__pack
                     (const Com__Protocol__Unitcom__VehicleMessage   *message,
                      uint8_t             *out);
size_t com__protocol__unitcom__vehicle_message__pack_to_buffer
                     (const Com__Protocol__Unitcom__VehicleMessage   *message,
                      ProtobufCBuffer     *buffer);
Com__Protocol__Unitcom__VehicleMessage *
       com__protocol__unitcom__vehicle_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   com__protocol__unitcom__vehicle_message__free_unpacked
                     (Com__Protocol__Unitcom__VehicleMessage *message,
                      ProtobufCAllocator *allocator);
/* Com__Protocol__Unitcom__FleetMessage methods */
void   com__protocol__unitcom__fleet_message__init
                     (Com__Protocol__Unitcom__FleetMessage         *message);
size_t com__protocol__unitcom__fleet_message__get_packed_size
                     (const Com__Protocol__Unitcom__FleetMessage   *message);
size_t com__protocol__unitcom__fleet_message__pack
                     (const Com__Protocol__Unitcom__FleetMessage   *message,
                      uint8_t             *out);
size_t com__protocol__unitcom__fleet_message__pack_to_buffer
                     (const Com__Protocol__Unitcom__FleetMessage   *message,
                      ProtobufCBuffer     *buffer);
Com__Protocol__Unitcom__FleetMessage *
       com__protocol__unitcom__fleet_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   com__protocol__unitcom__fleet_message__free_unpacked
                     (Com__Protocol__Unitcom__FleetMessage *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Com__Protocol__Unitcom__VehicleMessage_Closure)
                 (const Com__Protocol__Unitcom__VehicleMessage *message,
                  void *closure_data);
typedef void (*Com__Protocol__Unitcom__FleetMessage_Closure)
                 (const Com__Protocol__Unitcom__FleetMessage *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor com__protocol__unitcom__vehicle_message__descriptor;
extern const ProtobufCEnumDescriptor    com__protocol__unitcom__vehicle_message__type__descriptor;
extern const ProtobufCMessageDescriptor com__protocol__unitcom__fleet_message__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_com_2fprotocol_2funitcom_2fvehicle_2eproto3__INCLUDED */
