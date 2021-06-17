#ifndef CAPSULATEDVALUE_CRRTCFCYFCFCYHVGFV
#define CAPSULATEDVALUE_CRRTCFCYFCFCYHVGFV

#include <QObject>

class CapsulatedValue : public QObject
{
    Q_OBJECT
private:
    QString value;
public:
    explicit CapsulatedValue(const QString& value, QObject *parent = nullptr);
public:
    void setValue(const QString& value);
    QString getValue();
signals:
    void valueChanged(const QString& value);
};

#endif
