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

    static void getDirectAddress();
    static void fetch();
    static void decode();
public:
    Instruction(const QString& line, long long int line_no = 0, int address = 0);
    bool getSyntaxValid();
    QString getName();
    int getType();
    QString getVar();
    void execute();
};

#endif
