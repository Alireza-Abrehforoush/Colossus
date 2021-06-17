#ifndef HARDWARE_YGBYBVHNCJUHND
#define HARDWARE_YGBYBVHNCJUHND

#include "memory.h"
#include "register.h"
#include "flag.h"

namespace hardware
{
    extern Memory RAM;
    extern Register SC;
    extern Register PC;
    extern Register AR;
    extern Register IR;
    extern Register DR;
    extern Register AC;
    extern Register TR;
    extern Register INPR;
    extern Register OUTR;
    extern Register MAR;
    extern Flag I;
    extern Flag S;
    extern Flag E;
    extern Flag R;
    extern Flag IEN;
    extern Flag FGI;
    extern Flag FGO;
}
#endif
