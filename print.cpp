#pragma once

#include "print.h"

void print_mac(u_char *packet) {
    for (int i = 0; i < 6; i++)
    {
        printf(":%02x", packet[i]);
    }
}

void print_ip(uint8_t *ip) {
    printf("%u.%u.%u.%u", ip[0], ip[1], ip[2], ip[3]);
}

void print_port(uint8_t  *port) {
    printf("%2d", (port[0] << 8) | port[1]);
}
