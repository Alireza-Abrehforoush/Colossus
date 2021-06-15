#ifndef PARSER_H
#define PARSER_H
#include <QVector>
#include <QString>

class Parser
{
    QVector<QString> main_part;
    QVector<QString> ignored_part;
public:
    Parser(QString line);
    QVector<QString>GetMainPart();
    QVector<QString>GetIgnoredPart();
};

#endif // PARSER_H
