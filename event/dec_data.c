#include <stdio.h>
#include <stdlib.h>
#include "com/protocol/fleet_message.pb-c.h"
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
    Com__Protocol__FleetMessage *fleetMsg;
    Com__Protocol__FleetEvent *fleetevent;
    Com__Protocol__FleetEvent__PositionEvent *pos;
    Com__Protocol__GpsLocation  *loc;

    // Read packed message from standard-input.
    uint8_t buf[MAX_MSG_SIZE];
    int i;

    size_t msg_len = read_buffer(MAX_MSG_SIZE, buf);

    // Unpack the message using protobuf-c.
    fleetMsg = com__protocol__fleet_message__unpack(NULL, msg_len, buf);
    if (fleetMsg == NULL) {
      fprintf(stderr, "error unpacking incoming message\n");
      exit(1);
    }

    // display the message's fields.
    printf("Received: type = %d\n",fleetMsg->type);  // required field
    for (i = 0; i < fleetMsg->n_event; i++) {
        fleetevent = fleetMsg->event[i];
        pos = fleetevent->position;

        if (fleetevent->has_type)
            printf("Fleet event type: %d\n", fleetevent->type);

        if (pos) {
            if (pos->has_routerid)
                printf("routerid: %d\n", pos->routerid);
            if (pos->has_timestamp)
                printf("timestamp : %d\n", pos->timestamp);

            if (pos->location) {
                loc = pos->location;
                if (loc->has_latitude)
                    printf("latitude: %f\n", loc->latitude);
                if (loc->has_longitude)
                    printf("longitude: %f\n", loc->longitude);
                if (loc->has_elevation)
                    printf("elevation: %d\n", loc->elevation);
                if (loc->has_heading)
                    printf("heading: %d\n", loc->heading);
                if (loc->has_reversed)
                    printf("reversed: %d\n", loc->reversed);
            }

            if (pos->has_speed)
                printf("speed: %d\n", pos->speed);
            if (pos->has_ignition_on)
                printf("ignition_on: %d\n", pos->ignition_on);

        }
    }

    // Free the unpacked message
    com__protocol__fleet_message__free_unpacked(fleetMsg, NULL);
    return 0;
}
