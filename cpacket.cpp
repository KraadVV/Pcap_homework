#include "cpacket.h"
#include <stdint.h>
#include <stdio.h>

class thepacket
{
    public:
        thepacket();
        ~thepacket();
        void print_mac(uint8_t *packet)
            {
            for (int i = 0; i < 6; i++)
                {
                    printf(":%02x", packet[i]);
                }
            }

};
