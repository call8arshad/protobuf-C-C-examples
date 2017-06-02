#include <stdio.h>
#include <stdlib.h>
#include "com/protocol/unitcom/vehicle.proto3.pb-c.h"
#define MAX_MSG_SIZE 1024

static size_t
read_buffer (unsigned max_length, uint8_t *out)
{
    size_t cur_len = 0;
    size_t nread;
    while ((nread=fread(out + cur_len, 1, max_length - cur_len, stdin)) != 0)
    {
      cur_len += nread;
      if (cur_len == max_length)
      {
        fprintf(stderr, "max message length exceeded\n");
        exit(1);
      }
    }
    return cur_len;
}


int main (int argc, const char * argv[]) 
{
    Com__Protocol__Unitcom__VehicleMessage *fleetMsg ;
    Com__Protocol__Unitcom__FleetMessage *fmsg ;
    Com__Protocol__Shared__GpsData *gps;

    // Read packed message from standard-input.
    uint8_t buf[MAX_MSG_SIZE];

    size_t msg_len = read_buffer(MAX_MSG_SIZE, buf);

    // Unpack the message using protobuf-c.
    fleetMsg = com__protocol__unitcom__vehicle_message__unpack(NULL, msg_len, buf);
    if (fleetMsg == NULL)
    {
      fprintf(stderr, "error unpacking incoming message\n");
      exit(1);
    }

    // display the message's fields.
    printf("Received: type = %d\n",fleetMsg->type);  // required field
    printf("timestamp = %lu\n",fleetMsg->timestamp);
    fmsg = fleetMsg->fleet_message;
    if (fmsg) {
        fprintf(stderr, "hi ... fleet Msg is present ...,\n");
        gps = fmsg->gps;
        if (!gps) return 0;
        printf("gpsData: ----------->\n");
        printf("latitude: %f\n", gps->latitude);
        printf("longitude: %f\n", gps->longitude);
        printf("elevation: %d\n", gps->elevation);
        printf("heading: %d\n", gps->heading);
        printf("\n");
    }

    // Free the unpacked message
    com__protocol__unitcom__vehicle_message__free_unpacked(fleetMsg, NULL);
    return 0;
}
