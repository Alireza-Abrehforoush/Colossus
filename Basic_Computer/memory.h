#ifndef MEMORY_BUVBBCHJEWBCHNCUBEUI
#define MEMORY_BUVBBCHJEWBCHNCUBEUI

#include <QObject>
#include "register.h"

class Memory : public QObject
{
    Q_OBJECT
private:
    Register array[1024];
public:
    explicit Memory(QObject *parent = nullptr);
    void write(int address, long long int value);
    long long int read(int address);
signals:
    void valueChanged(int address);
};

#endif
