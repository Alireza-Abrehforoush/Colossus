#include "mytimer.h"

MyTimer::MyTimer(int interval)
{
    this->interval = interval;
    return;
}

void MyTimer::run()
{
    QTime dieTime = QTime::currentTime().addMSecs(this->interval);
    while(QTime::currentTime() < dieTime);
    emit this->timeout();
}

void MyTimer::setInterval(int interval)
{
    this->interval = interval;
    return;
}
