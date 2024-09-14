#ifndef PACKET_H
#define PACKET_H

typedef struct {
    int source_ip;
    int dest_ip;
    char payload[256];
} Packet;

#endif /* PACKET_H */

