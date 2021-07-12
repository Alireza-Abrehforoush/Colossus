#include "variable.h"
#include "parser.h"
#include "Hardware.h"
#include <QDebug>
QVector<QString> Variable::var_pre_assemble;
int Variable::getAddress()
{
    return this->address;
}

Variable::Variable(const QString& line, int address, long long int line_no, QObject *parent) : QObject(parent)
{
    QString temp_value = "";
    this->address = address;
    this->line_no = line_no;
    Parser p(line);
    QVector<QString> main_part=p.GetMainPart();
    QVector<QString>ignored_part=p.GetIgnoredPart();
    int part_number=main_part.size();
    if(part_number < 2)
    {
        this->syntax_valid=false;
        this->is_instruction = false;
        return;
    }
    if(line.indexOf("DEC") < 0 && line.indexOf("HEX") < 0 && line.indexOf("BIN") < 0)
    {
        if(ignored_part[1].indexOf(",") >= 0)
        {
            this->syntax_valid = true;
            this->is_instruction = true;
            this->name = main_part[0];
            return;
        }
    }

    if(part_number!=3)
    {
        this->syntax_valid=false;
        this->is_instruction = false;
        return;
    }
    if(ignored_part[3].indexOf(',') >= 0 || ignored_part[0].indexOf(',') >= 0 || ignored_part[2].indexOf(',') >= 0)
    {
        this->syntax_valid=false;
        return;
    }
    temp_value=main_part[2];
//    for(int i=0;i<temp_value.size();i++)
//    {
//        if(i == 0 && temp_value[i] == '-')
//        {
//            continue;
//        }
//        if (temp_value[i].isDigit()==false)
//        {
//            this->syntax_valid=false;
//            return;
//        }
//    }
    this->name=main_part[0];
    if(main_part[1]=="DEC")
    {
        hardware::RAM.write(this->address, temp_value.toLongLong());
        //qDebug()<<hardware::RAM.read(this->address);
    }
    else if(main_part[1]=="HEX")
    {
        hardware::RAM.write(this->address, temp_value.toLongLong(nullptr,16));
    }
    else
    {
        this->syntax_valid=false;
        return;
    }

    syntax_valid = true;
    is_instruction = false;
}

bool Variable::getSyntaxValid()
{
    return this->syntax_valid;
}

QString Variable::getName()
{
    return this->name;
}

bool Variable::getIsInstruction()
{
    return this->is_instruction;
}

QString Variable::purify(const QString &line)
{
    QString result = "";
    for(long long int i = line.indexOf(',') + 1; i < line.size(); i++)
    {
        result.append(line.at(i));
    }
    return result;
}

bool Variable::checkSyntaxValid(const QString &line)
{
    QString temp_value = "";
    Parser p(line);
    QVector<QString> main_part=p.GetMainPart();
    QVector<QString>ignored_part=p.GetIgnoredPart();
    int part_number=main_part.size();
    if(part_number!=3)
    {
        return false;
    }
    if(ignored_part[3].indexOf(',') >= 0 || ignored_part[0].indexOf(',') >= 0 || ignored_part[2].indexOf(',') >= 0)
    {
        return false;
    }
    temp_value=main_part[2];
//    for(int i=0;i<temp_value.size();i++)
//    {
//        if (temp_value[i].isDigit()==false)
//        {
//            return false;
//        }
//    }
    if(main_part[1]=="DEC")
    {
    }
    else if(main_part[1]=="HEX")
    {
    }
    else if(main_part[1] == "BIN")
    {
    }
    else
    {
        return false;
    }

    return true;
}
