#ifndef FLAG_ZERXRGFCYYYGVG
#define FLAG_ZERXRGFCYYYGVG

#include <QObject>

class Flag : public QObject
{
    Q_OBJECT
private:
    bool value;
public:
    explicit Flag(QObject *parent = nullptr);
    void complement();
    void setValue(bool value);
    bool getValue();

signals:
    void valueChanged();
};

#endif // FLAG_H
