#include "flag.h"

Flag::Flag(QObject *parent) : QObject(parent)
{

}

void Flag::complement()
{
    this->setValue(!(this->value));
    return;
}

void Flag::setValue(bool value)
{
    this->value = value;
    emit this->valueChanged();
    return;
}

bool Flag::getValue()
{
    return this->value;
}
