#include "register.h"
#include "math.h"

void Register::complement()
{
    bool c=false;
    for(int i=0;i<this->size;i++)
    {
        this->value[i]=this->value[i]^c;
        c=c|value[i];

    }
}

Register::Register(int size, bool is_signed, QObject *parent) : QObject(parent)
{
    this->size=size;
    this->is_signed = is_signed;
    for(int i = 0; i < size; i++)
    {
        this->value.push_back(0);
    }
    return;
}

Register::Register(QVector<bool> vec, int size,bool is_signed, QObject *parent):QObject (parent)
{
    if(vec.size() == size)
    {
        for(long long int i = 0; i < vec.size(); i++)
        {
            this->value.push_back(vec[i]);
        }
        this->size = size;
    }
    this->is_signed=is_signed;
}

void Register::load(long long int value)
{

    bool is_negetive=value<0;
    if (is_negetive)
    {
        value=value*-1;
    }
    for(int i=0; value&&i<this->size;i++)
    {
        this->value[i]=value%2;
        value/=2;
    }
    if(is_negetive)
    {
        //complement
        this->complement();
    }
    emit this->valueChanged();
    return;
}

void Register::clear()
{
    this->load(0);
}

void Register::increment()
{
    this->load(this->output()+1);
}

long long int Register::output()
{
    long long int res=0;
    for(int i=0;i<this->size-1;i++)
    {
       res+=(this->value[i]*pow(2,i));
    }
    if(this->value[this->value.size()-1]==1)
    {
        if(this->is_signed)
        {
            res = res-pow(2,this->size-1);
        }
        else
        {
            res += (long long int)pow(2, this->size - 1);
        }
    }
    return res;
}

QVector<bool> Register::getVec() const
{
    return this->value;
}

bool Register::at(int index)
{
    return this->value[index];
}

QString Register::toHex()
{
    long long int res=0;
    for(int i=0;i<this->size;i++)
    {
       res+=(this->value[i]*pow(2,i));
    }
    return QString::number(res,16);
}

void Register::onesComplement()
{
    for(int i = 0; i < this->size; i++)
    {
        this->value[i] = !(this->value[i]);
    }
    return;
}

void Register::shiftLeft(bool carry)
{
    for(int i = 0; i < size - 1; i++)
    {
        value[i] = value[i + 1];
    }
    value[size - 1] = carry;
    return;
}

void Register::shiftRight(bool carry)
{
    for(int i = size - 1; i > 0; i--)
    {
        value[i] = value[i - 1];
    }
    value[0] = carry;
    return;
}

bool Register::isZero()
{
    bool r = false;
    for(int i = 0; i < this->size; i++)
    {
        r = r || value[i];
    }
    return !r;
}

void Register::copy(Register &from, int i0, int j0, Register &to, int i1, int j1)
{
    if(j1 - i1 != j0 - i0)
        return;
    for(int cnt = 0; cnt <= j0 - i0; cnt++)
    {
        to.value[i1 + cnt]=from.value[i0 + cnt];
    }
    emit to.valueChanged();
}

void Register::copy(Register &from, int i, Flag &to)
{
    to.setValue(from.value[i]);
    emit to.valueChanged();
    return;
}

