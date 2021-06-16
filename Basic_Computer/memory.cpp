#include "memory.h"

Memory::Memory(QObject *parent) : QObject(parent)
{

}

void Memory::write(int address, long long int value)
{
    this->array[address].load(value);
    emit this->valueChanged(address);
    return;
}

long long Memory::read(int address)
{
    return this->array[address].output();
}
