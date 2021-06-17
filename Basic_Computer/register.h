#ifndef REGISTER_BVUDVBCMLMSCLSVQTSYQYQQ
#define REGISTER_BVUDVBCMLMSCLSVQTSYQYQQ

#include <QObject>
#include <QVector>
#include "flag.h"

class Register : public QObject
{
    Q_OBJECT
private:
    QVector<bool> value;
    int size;
    bool is_signed;
    void complement();
public:
    explicit Register(int size = 16, bool is_signed = false, QObject *parent = nullptr);
    void load(long long int value);
    void clear();
    void increment();
    long long int output();
    bool at(int index);
    QString toHex();
    void onesComplement();
    static void copy(Register & from, int i0, int j0, Register & to,int i1,int j1);
    static void copy(Register & from, int i, Flag& to);
signals:
    void valueChanged();

};


#endif
