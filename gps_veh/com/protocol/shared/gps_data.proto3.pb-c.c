/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: com/protocol/shared/gps_data.proto3 */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "com/protocol/shared/gps_data.proto3.pb-c.h"
void   com__protocol__shared__gps_data__init
                     (Com__Protocol__Shared__GpsData         *message)
{
  static Com__Protocol__Shared__GpsData init_value = COM__PROTOCOL__SHARED__GPS_DATA__INIT;
  *message = init_value;
}
size_t com__protocol__shared__gps_data__get_packed_size
                     (const Com__Protocol__Shared__GpsData *message)
{
  assert(message->base.descriptor == &com__protocol__shared__gps_data__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t com__protocol__shared__gps_data__pack
                     (const Com__Protocol__Shared__GpsData *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &com__protocol__shared__gps_data__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t com__protocol__shared__gps_data__pack_to_buffer
                     (const Com__Protocol__Shared__GpsData *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &com__protocol__shared__gps_data__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Com__Protocol__Shared__GpsData *
       com__protocol__shared__gps_data__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Com__Protocol__Shared__GpsData *)
     protobuf_c_message_unpack (&com__protocol__shared__gps_data__descriptor,
                                allocator, len, data);
}
void   com__protocol__shared__gps_data__free_unpacked
                     (Com__Protocol__Shared__GpsData *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &com__protocol__shared__gps_data__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor com__protocol__shared__gps_data__field_descriptors[5] =
{
  {
    "latitude",
    1,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_FLOAT,
    offsetof(Com__Protocol__Shared__GpsData, has_latitude),
    offsetof(Com__Protocol__Shared__GpsData, latitude),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "longitude",
    2,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_FLOAT,
    offsetof(Com__Protocol__Shared__GpsData, has_longitude),
    offsetof(Com__Protocol__Shared__GpsData, longitude),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "elevation",
    3,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(Com__Protocol__Shared__GpsData, has_elevation),
    offsetof(Com__Protocol__Shared__GpsData, elevation),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "heading",
    4,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_INT32,
    offsetof(Com__Protocol__Shared__GpsData, has_heading),
    offsetof(Com__Protocol__Shared__GpsData, heading),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "reversed",
    5,
    PROTOBUF_C_LABEL_OPTIONAL,
    PROTOBUF_C_TYPE_BOOL,
    offsetof(Com__Protocol__Shared__GpsData, has_reversed),
    offsetof(Com__Protocol__Shared__GpsData, reversed),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned com__protocol__shared__gps_data__field_indices_by_name[] = {
  2,   /* field[2] = elevation */
  3,   /* field[3] = heading */
  0,   /* field[0] = latitude */
  1,   /* field[1] = longitude */
  4,   /* field[4] = reversed */
};
static const ProtobufCIntRange com__protocol__shared__gps_data__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 5 }
};
const ProtobufCMessageDescriptor com__protocol__shared__gps_data__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "com.protocol.shared.GpsData",
  "GpsData",
  "Com__Protocol__Shared__GpsData",
  "com.protocol.shared",
  sizeof(Com__Protocol__Shared__GpsData),
  5,
  com__protocol__shared__gps_data__field_descriptors,
  com__protocol__shared__gps_data__field_indices_by_name,
  1,  com__protocol__shared__gps_data__number_ranges,
  (ProtobufCMessageInit) com__protocol__shared__gps_data__init,
  NULL,NULL,NULL    /* reserved[123] */
};
