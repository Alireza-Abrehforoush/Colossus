#ifndef ASSEMBE_NVLSKVDVKNLKEJFM
#define ASSEMBE_NVLSKVDVKNLKEJFM

#include "variable.h"
#include "instruction.h"
#include <QVector>
namespace AssemblyVariable
{
    extern QVector<Variable*> Variables_list;
    extern QVector<Instruction> Instruction_list;
    bool existVariableName(const QString& variable_name);
    int getVariableAddress(const QString & variable_name);
}

#endif
