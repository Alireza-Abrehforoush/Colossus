#ifndef INSTRUCTIONS_GVCGVSVGWVUVBXJWBJX
#define INSTRUCTIONS_GVCGVSVGWVUVBXJWBJX
#include <QString>
#include <QVector>
using namespace  std;

namespace instructions
{
    const int mem_ref = 0, reg_ref = 1, io_ref = 2, directives = 3, non = 3;
    const QVector<QString> mem_ref_vec  {"AND", "ADD","LDA","STA", "BUN", "BSA", "ISZ"};
    const QVector<QString> reg_ref_vec {"CLA", "CLE", "CMA", "CME", "CIR", "CIL", "INC", "SPA", "SNA", "SZA", "SZE"};
    const QVector<QString> io_ref_vec {"INP", "OUT", "SKI", "SKO", "ION", "IOF"};
    const QVector<QString> directives_vec  {"ORG", "START", "END", "DEC", "HEX"};
    int instruction_kind(QString instruction)
    {
        for(int i=0; i < mem_ref_vec.size(); i++)
            if (instruction==mem_ref_vec[i])
                return mem_ref;
        for(int i=0; i < reg_ref_vec.size();i++)
            if (instruction==reg_ref_vec[i])
                return reg_ref;
        for(int i=0; i < io_ref_vec.size(); i++)
            if (instruction == io_ref_vec[i])
                return io_ref;
        for(int i=0; i < directives_vec.size();i++)
            if (instruction == directives_vec[i])
                return directives;
        return non;
    }
}
#endif
