#ifndef PARSER_VNJDNVKDJNVLKJMVL
#define PARSER_VNJDNVKDJNVLKJMVL
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
    static bool isEmptyLine(const QString& line);
};

#endif // PARSER_H
