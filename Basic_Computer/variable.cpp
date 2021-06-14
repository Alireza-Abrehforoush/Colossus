#include "variable.h"

Variable::Variable(const QString& line, QObject *parent) : QObject(parent)
{
    QString temp_type = "";
    QString temp_value = "";
    long long int i = 0;
    for(; i < line.size() && (line.at(i) == ' ' || line.at(i) == '\t'); i++)
    {
    }
    for (; i < line.size() && (line.at(i) != ' ' && line.at(i) != '\t' && line.at(i) != ','); i++)
    {
        name.push_back(line.at(i));
    }
    for(; i < line.size() && (line.at(i) == ' ' || line.at(i) == '\t' || line.at(i) == ','); i++)
    {
    }
    if(i == line.size())
    {
        syntax_valid = false;
        return;
    }
    long long int j = 0;
    for (; i < line.size() && (line.at(i) != ' ' && line.at(i) != '\t' && line.at(i) != ',') && j < 3; i++, j++)
    {
        temp_type.push_back(line.at(i));
    }
    for(; i < line.size() && (line.at(i) == ' ' || line.at(i) == '\t' || line.at(i) == ','); i++)
    {
    }
    if(i == line.size())
    {
        syntax_valid = false;
        return;
    }
    for (; i < line.size() && line.at(i).isDigit(); i++)
    {
        temp_value.push_back(line.at(i));
    }
    for(; i < line.size() && (line.at(i) == ' ' || line.at(i) == '\t' || line.at(i) == ','); i++)
    {
    }
    if(i != line.size())
    {
        syntax_valid = false;
        return;
    }

    if(temp_type == "DEC")
    {
        this->value = temp_value.toLongLong();
    }
    else if(temp_type == "HEX")
    {
        this->value = temp_value.toLongLong(nullptr, 16);
    }
    else
    {
        syntax_valid = false;
        return;
    }
    syntax_valid = true;
}
