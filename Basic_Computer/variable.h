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
    bool is_instruction = false;
public:
    explicit Variable(const QString& line, int address = 0, long long int line_no = 0, QObject *parent = nullptr);
    bool getSyntaxValid();
    int getAddress();
    QString getName();
    bool getIsInstruction();
    static QString purify(const QString& line);
    static bool checkSyntaxValid(const QString& line);
    static QVector<QString> var_pre_assemble;
signals:

};



#endif
