#ifndef INSTRUCTIONS_GVCGVSVGWVUVBXJWBJX
#define INSTRUCTIONS_GVCGVSVGWVUVBXJWBJX
#include <QString>
#include <QVector>
using namespace  std;

namespace instructions
{
    const int mem_ref = 0, reg_ref = 1, io_ref = 2, directives = 3, non = 4;
    const QVector<QString> mem_ref_vec  {"AND", "ADD","LDA","STA", "BUN", "BSA", "ISZ"};
    const QVector<QString> reg_ref_vec {"CLA", "CLE", "CMA", "CME", "CIR", "CIL", "INC", "SPA", "SNA", "SZA", "SZE"};
    const QVector<QString> io_ref_vec {"INP", "OUT", "SKI", "SKO", "ION", "IOF"};
    const QVector<QString> directives_vec  {"ORG", "START", "END", "DEC", "HEX"};
    int instruction_kind(QString instruction);
}
#endif
