#ifndef VARIABLE_AWEDQWCWCEWUYIHBKJ
#define VARIABLE_AWEDQWCWCEWUYIHBKJ

#include <QObject>

class Variable : public QObject
{
    Q_OBJECT
private:
    QString name;
    int address;
    long long int line_no;
    bool syntax_valid;
    int getAddress();
public:
    explicit Variable(const QString& line, int address = 0, long long int line_no = 0, QObject *parent = nullptr);
    bool getSyntaxValid();
    static bool checkSyntaxValid(const QString& line);
signals:

};



#endif
