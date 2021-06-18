#ifndef INSTRUCTION_HJFKDSJLKFSQAQA
#define INSTRUCTION_HJFKDSJLKFSQAQA

#include <QString>
#include "variable.h"

class Instruction
{
private:
    QString name;
    QString var;
    int type;
    long long int line_no;
    int address;
    bool syntax_valid;
    QString error_content;
    bool indirect = false;

    static void getDirectAddress(int sleep_time);
    static void fetch(int sleep_time);
    static void decode(int sleep_time);
public:
    Instruction(const QString& line, long long int line_no = 0, int address = 0);
    Instruction();
    bool getSyntaxValid();
    QString getName();
    int getType();
    int getAddress()const;
    QString getVar();
    void execute(int sleep_time);
    ~Instruction();
};

#endif
