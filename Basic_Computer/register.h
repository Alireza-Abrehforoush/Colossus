#ifndef REGISTER_BVUDVBCMLMSCLSVQTSYQYQQ
#define REGISTER_BVUDVBCMLMSCLSVQTSYQYQQ

#include <QObject>

class Register : public QObject
{
    Q_OBJECT
private:
    //QVector<bool> value;
    int size;
public:
    explicit Register(int size, QObject *parent = nullptr);
    void clear();
    void increment();
    void load(long long int value);
    long long int output();
signals:

};

namespace Registers
{
//    Register SC;
//    Register PC;
//    Register AR;
//    Register IR;
//    Register DR;
//    Register AC;
//    Register TR;
//    Register INPR;
//    Register OUTR;
}
#endif
