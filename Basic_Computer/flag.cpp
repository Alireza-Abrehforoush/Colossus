#include "flag.h"

Flag::Flag(QObject *parent) : QObject(parent)
{

}

void Flag::setValue(bool value)
{
    this->value = value;
    return;
}

bool Flag::getValue()
{
    return this->value;
}
