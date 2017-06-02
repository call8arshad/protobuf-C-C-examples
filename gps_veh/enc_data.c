#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com/protocol/unitcom/vehicle.proto3.pb-c.h"

#define true 1
#define FLEET 1
int main (int argc, const char * argv[]) 
{
    Com__Protocol__Unitcom__VehicleMessage fleetMsg;
    Com__Protocol__Unitcom__FleetMessage fmsg;
    Com__Protocol__Shared__GpsData gps;
    void *buf;          // Buffer to store serialized data
    unsigned len;       // Length of serialized data

    /* initialization ... */
    com__protocol__unitcom__vehicle_message__init(&fleetMsg);
    com__protocol__unitcom__fleet_message__init(&fmsg);
    com__protocol__shared__gps_data__init(&gps);

#if 0
    fleetMsg.has_type = true;
    fleetMsg.type = FLEET;
    fleetMsg.has_timestamp = true;
    fleetMsg.timestamp = time(NULL);

    fleetMsg.fleet_message  = &fmsg;
    fleetMsg.fleet_message->gps = &gps;

    gps.has_latitude = true;
    gps.latitude = 11.121212;
    gps.has_longitude = true;
    gps.longitude = 21.212121;
    gps.has_elevation = true;
    gps.elevation = 12;
    gps.has_heading = true;
    gps.heading = 360;
#endif

    len = com__protocol__unitcom__vehicle_message__get_packed_size(&fleetMsg);
fprintf(stderr,"... packet size: %d\n", len);
    buf = malloc(len);
    com__protocol__unitcom__vehicle_message__pack(&fleetMsg, buf);

    fprintf(stderr,"Writing %d serialized bytes\n",len); // See the length of message
    fwrite(buf,len,1,stdout); // Write to stdout to allow direct command line piping

    free(buf); // Free the allocated serialized buffer
    return 0;
}
