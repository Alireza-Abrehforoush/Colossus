#ifndef FLAG_H
#define FLAG_H

#include <QObject>

class Flag : public QObject
{
    Q_OBJECT
private:
    bool value;
public:
    explicit Flag(QObject *parent = nullptr);
    void setValue(bool value);
    bool getValue();

signals:
    void valueChanged();
};

#endif // FLAG_H
