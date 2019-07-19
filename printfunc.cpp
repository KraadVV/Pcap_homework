
#include <stdio.h>
#include "printfunc.h"
#include <stdint.h>


printfunc::printfunc()
{
}

printfunc::~printfunc()
{
}



void printfunc::print(headto hd,setting set,const uint8_t *packet){
    switch (hd)
    {
    case 1:
        printf("\nSource ");
        break;
    case 2:
        printf("\nDestination ");
        break;
    }
    switch (set)
    {
        case 1:
            printf("MAC");
            for(int i=0;i<6;i++)
            {
                printf(": %x", packet[i]);
            }
            break;

        case 2:
            printf("IP: ");
            for(int i=0;i<4;i++)
            {
                printf(": %d", packet[i]);
            }
            break;
        case 3:
            printf("Port:");
            uint16_t tmp = ((packet[0] << 8)|packet[1]);
            printf("%u", tmp);
            break;

    }

}

void printfunc::printdata(const uint8_t *packet)
{
    int ipStartPoint = 14; //length of eth = 14
    int tcpStartPoint = ipStartPoint+((packet[ipStartPoint]-(16*4))*4); // get length of ip, and calc where would tcp start
    int tcpDataStartPoint = tcpStartPoint+(((packet[tcpStartPoint+12]) >> 4)*5);// get length of tcp, and calc where would tcp data start
    printf("\n Data:"); // separate between head and body
    for(int i=0; i<10; i++)
    {
        printf("%x", packet[tcpDataStartPoint+i]); //print 10 bytes
    }
    printf("\n========================"); //sep btw packets

}
