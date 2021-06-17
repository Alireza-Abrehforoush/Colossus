#include "instruction.h"
#include "instructions.h"
#include "parser.h"

Instruction::Instruction(const QString &line, long long line_no, int address)
{
    this->line_no = line_no;
    this->address = address;
    Parser p(line);
    QVector<QString> main_part = p.GetMainPart();
    QVector<QString>ignored_part = p.GetIgnoredPart();
    int part_number = main_part.size();
    if(part_number <= 0 || part_number > 3)
    {
        this->syntax_valid=false;
        return;
    }
    this->type = instructions::instruction_kind(main_part[0]);
    if(this->type == instructions::non)
    {
        this->syntax_valid = false;
        return;
    }

    if(this->type == instructions::reg_ref || this->type == instructions::io_ref)
    {
        if(part_number != 1)
        {
            this->syntax_valid = false;
            return;
        }

    }
    else if(this->type == instructions::mem_ref)
    {
        if(part_number > 3 || part_number<=1)
        {
            this->syntax_valid = false;
            return;
        }
        else if(part_number == 3 && main_part[3] != "I")
        {
            this->syntax_valid = false;
            return;
        }
        else
        {
            this->var=main_part[1];
        }
    }
    else if(this->type == instructions::directives)
    {
        if (part_number>2)
        {
            this->syntax_valid = false;
            return;
        }
        if (main_part[0]=="ORG")
        {
            if(part_number!=2)
            {
                this->syntax_valid = false;
                return;
            }
            for(int i=0;i<main_part[1].size();i++)
            {
                if (main_part[1][i].isDigit()==false)
                {
                    this->syntax_valid = false;
                    return;
                }
            }
            this->var=main_part[1];
        }
        else if(main_part[0]=="DEC"|| main_part[0]=="HEX")
        {
            this->syntax_valid = false;
            return;
        }
    }

    this->name=main_part[0];
    this->syntax_valid=true;
}

bool Instruction::getSyntaxValid()
{
    return this->syntax_valid;
}

QString Instruction::getName()
{
    return this->name;
}

int Instruction::getType()
{
    return this->type;
}

QString Instruction::getVar()
{
    return this->var;
}

void Instruction::fetch()
{

}
