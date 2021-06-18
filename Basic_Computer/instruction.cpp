#include "instruction.h"
#include "instructions.h"
#include "parser.h"
#include "microoperation.h"
#include "Hardware.h"

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
            if(part_number == 3)
            {
                this->indirect = true;
            }
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

    if(address != 0)
    {
        if(this->type == instructions::mem_ref)
        {
            QVector<bool> temp(16);
            if(this->indirect)
            {
                temp[15] = 1;
            }
            else
            {
                temp[15] = 0;
            }
            ////////////////
        }

        else
        {
            QString kemp = "";
            if(this->name == "CLA")
            {
                kemp = "7800";
            }
            else if(this->name == "CLE")
            {
                kemp = "7400";
            }
            else if(this->name == "CMA")
            {
                kemp = "7200";
            }
            else if(this->name == "CME")
            {
                kemp = "7100";
            }
            else if(this->name == "CIR")
            {
                kemp = "7080";
            }
            else if(this->name == "CIL")
            {
                kemp = "7040";
            }
            else if(this->name == "INC")
            {
                kemp = "7020";
            }
            else if(this->name == "SPA")
            {
                kemp = "7010";
            }
            else if(this->name == "SNA")
            {
                kemp = "7008";
            }
            else if(this->name == "SZA")
            {
                kemp = "7004";
            }
            else if(this->name == "SZE")
            {
                kemp = "7002";
            }
            int value = kemp.toInt(nullptr, 16);
            hardware::RAM.write(this->address, value);
        }

    }
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

void Instruction::execute()
{
    if(this->syntax_valid == false)
    {
        return;
    }
    else
    {
        this->fetch();
        this->decode();
        if(this->getType() == instructions::mem_ref)
        {
            if(this->indirect == true)
            {
                this->getDirectAddress();
            }
            else
            {
                ////////////////////////////
            }

            if(this->name == "AND")
            {
                Microoperation temp("AND");
                temp.run();
            }
            else if(this->name == "ADD")
            {
                Microoperation temp("ADD");
                temp.run();
            }
            else if(this->name == "LDA")
            {
                Microoperation temp("LDA");
                temp.run();
            }
            else if(this->name == "STA")
            {
                Microoperation temp("STA");
                temp.run();
            }
        }
        else
        {
            if(this->name == "CLA")
            {
                Microoperation temp("CLA");
                temp.run();
            }
            else if(this->name == "CLE")
            {
                Microoperation temp("CLE");
                temp.run();
            }
            else if(this->name == "CMA")
            {
                Microoperation temp("CMA");
                temp.run();
            }
            else if(this->name == "CME")
            {
                Microoperation temp("CME");
                temp.run();
            }
            else if(this->name == "CIR")
            {
                Microoperation temp("CIR");
                temp.run();
            }
            else if(this->name == "CIL")
            {
                Microoperation temp("CIL");
                temp.run();
            }
            else if(this->name == "INC")
            {
                Microoperation temp("INCAC");
                temp.run();
            }
            else if(this->name == "SPA")
            {
                Microoperation temp("SPA");
                temp.run();
            }
            else if(this->name == "SNA")
            {
                Microoperation temp("SNA");
                temp.run();
            }
            else if(this->name == "SZA")
            {
                Microoperation temp("SZA");
                temp.run();
            }


        }
    }
}

void Instruction::getDirectAddress()
{
    Microoperation temp("MARTOAR");
    temp.run();
}

void Instruction::fetch()
{
    Microoperation temp1("PCTOAR"), temp2("INCPC"), temp3("MARTOIR");
    temp1.run();
    temp2.run();
    temp3.run();
}

void Instruction::decode()
{
    Microoperation temp1("IRTOAR"), temp2("IRTOI");
    temp1.run();
    temp2.run();
}
