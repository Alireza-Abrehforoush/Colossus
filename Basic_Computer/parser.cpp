#include "parser.h"

Parser::Parser(QString line)
{
    int i=0;
    int cnt=0;
    ignored_part.push_back("");
    while(true)
    {

        for(;line[i]==" "|| line[i]=="\t" || line[i]=="," && i<line.size();i++)
            ignored_part[cnt].push_back(line[i]);
        if (i==line.size())
            break;
        main_part.push_back("");
        for(;line[i]!=" "&& line[i]!="\t" && line[i]!="," && i<line.size();i++)
            main_part[cnt].push_back(line[i]);
        ignored_part.push_back("");
        cnt++;
        if(i==line.size())
            break;
    }
}

QVector<QString> Parser::GetMainPart()
{
    return this->main_part;
}

QVector<QString> Parser::GetIgnoredPart()
{
    return this->ignored_part;
}

bool Parser::isEmptyLine(const QString &line)
{
    Parser temp(line);
    QVector<QString> main_part = temp.GetMainPart();
    return main_part.size() == 0;
}
