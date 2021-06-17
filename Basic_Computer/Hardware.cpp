#include "Hardware.h"

namespace hardware
{
    Memory RAM;
    Register SC(4);
    Register PC(12);
    Register AR(12);
    Register IR;
    Register DR;
    Register AC;
    Register TR;
    Register INPR(8);
    Register OUTR(8);
    Flag I;
    Flag S;
    Flag E;
    Flag R;
    Flag IEN;
    Flag FGI;
    Flag FGO;
}
