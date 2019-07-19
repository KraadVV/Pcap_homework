#include "typeanalysis.h"
#include <printfunc.h>
#include <stdio.h>

typeAnalysis::typeAnalysis()
{

}
typeAnalysis::~typeAnalysis()
{}


int typeAnalysis::checkType(const uint8_t *packet)
{
            //check if this is IP protocol and TCP protocol
            if(((packet[12]<<8)|packet[13]) == 0x0800)
            {
                printf("\nIP Protocol detected\n");
                if((packet[23]) == 0x06)
                {
                    printf("TCP Protocol Detected\n");

                }
                else {
                    printf("Not TCP, return 0;");
                    return 0;
                }
            }


            else
            {
                return 0;
            }



}
