#pragma once

#ifndef PRINTFUNC_H
#define PRINTFUNC_H
#include <stdint.h>


class printfunc
{
public:
    printfunc();
    ~printfunc();

    enum setting {MAC = 1, IP = 2, PORT = 3 };
    enum headto{SOURCE = 1, DESTINATION = 2};
    void print(headto hd,setting set,const uint8_t *packet);
    void printdata(const uint8_t *packet);
};


#endif // PRINTFUNC_H
