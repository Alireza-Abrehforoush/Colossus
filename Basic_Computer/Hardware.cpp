#include "Hardware.h"

namespace hardware
{
    Memory RAM;
    Register SC(4);
    Register PC(12);
    Register AR;
    Register IR;
    Register DR;
    Register AC;
    Register TR;
    Register INPR(8);
    Register OUTR(8);
    Register MAR(12);
    Flag I;
    Flag S;
    Flag E;
    Flag R;
    Flag IEN;
    Flag FGI;
    Flag FGO;
}
