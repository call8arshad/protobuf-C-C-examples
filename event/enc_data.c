#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com/protocol/fleet_message.pb-c.h"

#define true 1
int main (int argc, const char * argv[]) 
{
    Com__Protocol__FleetMessage fleetMsg;
    Com__Protocol__FleetEvent **fleetevent = NULL;
    Com__Protocol__FleetEvent__PositionEvent pos;
    Com__Protocol__GpsLocation  loc;

    void *buf;          // Buffer to store serialized data
    unsigned len;       // Length of serialized data
    int i;

    /* initialization ... */
    com__protocol__fleet_message__init(&fleetMsg);
    fleetMsg.has_type = true;
    fleetMsg.type = COM__PROTOCOL__FLEET_MESSAGE__MESSAGE_TYPE__EVENT;
    fleetMsg.n_event = 1;    /*consider only one event for now ..*/

    fleetevent = malloc(sizeof(Com__Protocol__FleetEvent *) * fleetMsg.n_event);
    for (i = 0; i < fleetMsg.n_event; i++) {
        fleetevent[i] = malloc(sizeof (Com__Protocol__FleetEvent));
        com__protocol__fleet_event__init(fleetevent[i]);
        fleetevent[i]->has_type = true;
        fleetevent[i]->type = COM__PROTOCOL__FLEET_EVENT__EVENT_TYPE__POSITION; //  = 0
        fleetevent[i]->position = &pos;
    }
    fleetMsg.event = fleetevent;

    com__protocol__fleet_event__position_event__init(&pos);
    pos.has_routerid = true;
    pos.routerid = 1234;
    pos.has_timestamp =  true;
    pos.timestamp = time(NULL);
    pos.location = &loc;
    pos.has_speed = true;
    pos.speed = 20; //MPH
    pos.has_ignition_on = true;
    pos.ignition_on = 1; //on or off

    com__protocol__gps_location__init(&loc);
    loc.has_latitude = true;
    loc.latitude = 11.111111;
    loc.has_longitude = true;
    loc.longitude = 22.222222;
    loc.has_elevation = true;
    loc.elevation = 123;
    loc.has_heading = true;
    loc.heading = 22;
    loc.has_reversed = true;
    loc.reversed = 999;

    len = com__protocol__fleet_message__get_packed_size(&fleetMsg);
fprintf(stderr,"... packet size: %d\n", len);
    buf = malloc(len);
    com__protocol__fleet_message__pack(&fleetMsg, buf);

    fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
    fwrite(buf, len, 1, stdout); // Write to stdout to allow direct command line piping

    free(buf); // Free the allocated serialized buffer


fprintf(stderr,"%s - %d\n", __func__, __LINE__);
    len = com__protocol__fleet_message__get_packed_size(&fleetMsg);
fprintf(stderr,"%s - %d\n", __func__, __LINE__);
    buf = malloc(len);
    com__protocol__fleet_message__pack(&fleetMsg, buf);

    fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
    fwrite(buf, len, 1, stdout); // Write to stdout to allow direct command line piping

    for (i = 0; i < fleetMsg.n_event; i++) {
        free(fleetevent[i]);
    }
    free(fleetevent);

    return 0;
}
