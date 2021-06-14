#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H
#include <QString>
#include <QVector>
using namespace  std;

namespace instructions
{
    int mem_ref=0,reg_ref=1,non=3;
    const QVector<QString> mem_ref_vec={"ADD","LDA","STA"};
    const QVector<QString> reg_ref_vec={"CMA","INC"};
    int instruction_kind(QString instruction)
    {
        for(int i=0;i<3;i++)
            if (instruction==mem_ref_vec[i])
                return mem_ref;
        for(int i=0;i<2;i++)
            if (instruction==reg_ref_vec[i])
                return reg_ref;
        return non;
    }
}
#endif // INSTRUCTIONS_H
