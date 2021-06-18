#include "assembe.h"

namespace AssemblyVariable
{
QVector<Variable*> Variables_list;
QVector<Instruction> Instruction_list;

int getVariableAddress(const QString& variable_name)
{
    if(existVariableName(variable_name)==false)
        return 0;
    else
    {
        for(int i=0;i<Variables_list.size();i++)
        {
            if(Variables_list[i]->getName()==variable_name)
               return Variables_list[i]->getAddress();

        }
    }
}

bool existVariableName(const QString &variable_name)
{
    for(int i=0;i<Variables_list.size();i++)
    {
        if(Variables_list[i]->getName()==variable_name)
            return true;

    }
    return false;
}

}

