#ifndef TYPEANALYSIS_H
#define TYPEANALYSIS_H
#include <printfunc.h>

class typeAnalysis
{
public:
    typeAnalysis();
    ~typeAnalysis();
    enum type{ip=1,tcp=2,http=3};
    int checkType(const uint8_t *packet);
};

#endif // TYPEANALYSIS_H
