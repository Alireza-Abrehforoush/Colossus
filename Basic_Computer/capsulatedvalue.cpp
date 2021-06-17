#include "capsulatedvalue.h"

CapsulatedValue::CapsulatedValue(const QString& value, QObject *parent) : QObject(parent)
{
    this->setValue(value);
    return;
}

void CapsulatedValue::setValue(const QString &value)
{
    this->value = value;
    emit this->valueChanged(value);
    return;
}

QString CapsulatedValue::getValue()
{
    return this->value;
}
