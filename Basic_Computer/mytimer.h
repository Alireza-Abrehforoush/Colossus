#ifndef MYTIMER_VGJHGJVHBJH
#define MYTIMER_VGJHGJVHBJH

#include <QObject>
#include <QtCore>

class MyTimer : public QThread
{
    Q_OBJECT
private:
    int interval;

public:
    MyTimer(int interval = 0);
    void run();
    void setInterval(int interval);

signals:
    void timeout();
};

#endif // MYTIMER_H
