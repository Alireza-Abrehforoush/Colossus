#ifndef VARIABLE_AWEDQWCWCEWUYIHBKJ
#define VARIABLE_AWEDQWCWCEWUYIHBKJ

#include <QObject>

class Variable : public QObject
{
    Q_OBJECT
private:
    QString name;
    long long int value;
    long long int line_no;
    bool syntax_valid;
public:
    explicit Variable(const QString& line, QObject *parent = nullptr);

signals:

};



#endif
