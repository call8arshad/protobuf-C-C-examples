#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "com/protocol/unitcom/vehicle.proto3.pb-c.h"
#include <string>
using namespace std;

#define true 1
#define FLEET 1
void my_fwrite(char *data, int len)
{
    FILE *fp = NULL;
    static int count = 0;
fprintf(stderr, "hi1\n");
    fwrite(data, len, 1, stderr);
    if (count ==  0) {
fprintf(stderr, "hi2\n");
        fp  = fopen("./tmp.txt", "w+");
fprintf(stderr, "hi3\n");
        fwrite(data, len, 1, fp);
fprintf(stderr, "hi4\n");
        fclose(fp);
    }
    count++;
    // Write to stdout to allow direct command line piping

}

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

#if 1
    fleetMsg.has_type = true;
    fleetMsg.type = COM__PROTOCOL__UNITCOM__VEHICLE_MESSAGE__TYPE__FLEET;
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
    buf = malloc(len);
    com__protocol__unitcom__vehicle_message__pack(&fleetMsg, (uint8_t *)buf);

    // See the length of message
    fprintf(stderr,"Writing %d serialized bytes\n",len);

    my_fwrite((char *)buf, len);

    string frame = "this string is used for TEsting\n";
    my_fwrite((char *)frame.c_str(), frame.size());

    free(buf); // Free the allocated serialized buffer
    return 0;
}
