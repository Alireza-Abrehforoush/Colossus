#include "mytime.h"
#include <QTime>
void mytime::delay(int ms)
{
    QTime dieTime=QTime::currentTime().addMSecs(ms);
    while(QTime::currentTime()<dieTime);
}
