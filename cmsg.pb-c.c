/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: cmsg.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "cmsg.pb-c.h"
void   cmsg__init
                     (Cmsg         *message)
{
  static Cmsg init_value = CMSG__INIT;
  *message = init_value;
}
size_t cmsg__get_packed_size
                     (const Cmsg *message)
{
  assert(message->base.descriptor == &cmsg__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t cmsg__pack
                     (const Cmsg *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &cmsg__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t cmsg__pack_to_buffer
                     (const Cmsg *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &cmsg__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Cmsg *
       cmsg__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Cmsg *)
     protobuf_c_message_unpack (&cmsg__descriptor,
                                allocator, len, data);
}
void   cmsg__free_unpacked
                     (Cmsg *message,
                      ProtobufCAllocator *allocator)
{
  assert(message->base.descriptor == &cmsg__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor cmsg__field_descriptors[1] =
{
  {
    "c",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_INT32,
    offsetof(Cmsg, n_c),
    offsetof(Cmsg, c),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned cmsg__field_indices_by_name[] = {
  0,   /* field[0] = c */
};
static const ProtobufCIntRange cmsg__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor cmsg__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "cmsg",
  "Cmsg",
  "Cmsg",
  "",
  sizeof(Cmsg),
  1,
  cmsg__field_descriptors,
  cmsg__field_indices_by_name,
  1,  cmsg__number_ranges,
  (ProtobufCMessageInit) cmsg__init,
  NULL,NULL,NULL    /* reserved[123] */
};