#include "instruction.h"
#include "instructions.h"
#include "parser.h"
#include "microoperation.h"
#include "Hardware.h"
#include "assembe.h"
#include "mytime.h"

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
        else if(main_part[0]=="DEC"|| main_part[0]=="HEX" || main_part[0] == "BIN")
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
            QVector<bool> total(16);
            //put indirection bit
            if(this->indirect)
            {
                total[15] = 1;
            }
            else
            {
                total[15] = 0;
            }
            ////////////////
            //put OPCode
            if(this->name == "AND")
            {
                total[14]=0;
                total[13]=0;
                total[12]=0;
            }
            else if(this->name == "ADD")
            {
                total[14]=0;
                total[13]=0;
                total[12]=1;
            }
            else if(this->name == "LDA")
            {
                total[14]=0;
                total[13]=1;
                total[12]=0;
            }
            else if(this->name == "STA")
            {
                total[14]=0;
                total[13]=1;
                total[12]=1;
            }
            else if(this->name == "BUN")
            {
                total[14]=1;
                total[13]=0;
                total[12]=0;
            }
            else if(this->name == "BSA")
            {
                total[14]=1;
                total[13]=0;
                total[12]=1;
            }
            else if(this->name == "ISZ")
            {
                total[14]=1;
                total[13]=1;
                total[12]=0;
            }
            //PUT ADDRESS
            if(AssemblyVariable::existVariableName(this->var)==false)
            {

            }
            else
            {
                int addr=AssemblyVariable::getVariableAddress(this->var);
                Register temp(12,false);
                temp.load(addr);
                QVector<bool>vec =temp.getVec();
                for(int i=0;i<12;i++)
                {
                    total[i]=vec[i];
                }
                Register r(total,16,false);
                hardware::RAM.write(this->address,r.output());

            }

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

Instruction::Instruction()
{

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

int Instruction::getAddress() const
{
    return this->address;
}

QString Instruction::getVar()
{
    return this->var;
}

void Instruction::execute(int sleep_time)
{
    if(this->syntax_valid == false)
    {
        return;
    }
    else
    {
        Microoperation sc("CLSC");
        this->fetch(sleep_time);
        this->decode(sleep_time);
        if(this->getType() == instructions::mem_ref)
        {
            if(this->indirect == true)
            {
                this->getDirectAddress(sleep_time);
            }
            else
            {
                ////////////////////////////
            }

            if(this->name == "AND")
            {
                Microoperation temp("AND");
                temp.run(sleep_time);
            }
            else if(this->name == "ADD")
            {
                Microoperation temp("ADD");
                temp.run(sleep_time);
            }
            else if(this->name == "LDA")
            {
                Microoperation temp("LDA");
                temp.run(sleep_time);
            }
            else if(this->name == "STA")
            {
                Microoperation temp("STA");
                temp.run(sleep_time);
            }
            else if(this->name == "BUN")
            {
                Microoperation temp("MARTOPC");
                temp.run(sleep_time);
            }
        }
        else
        {
            if(this->name == "CLA")
            {
                Microoperation temp("CLA");
                temp.run(sleep_time);
            }
            else if(this->name == "CLE")
            {
                Microoperation temp("CLE");
                temp.run(sleep_time);
            }
            else if(this->name == "CMA")
            {
                Microoperation temp("CMA");
                temp.run(sleep_time);
            }
            else if(this->name == "CME")
            {
                Microoperation temp("CME");
                temp.run(sleep_time);
            }
            else if(this->name == "CIR")
            {
                Microoperation temp("CIR");
                temp.run(sleep_time);
            }
            else if(this->name == "CIL")
            {
                Microoperation temp("CIL");
                temp.run(sleep_time);
            }
            else if(this->name == "INC")
            {
                Microoperation temp("INCAC");
                temp.run(sleep_time);
            }
            else if(this->name == "SPA")
            {
                Microoperation temp("SPA");
                temp.run(sleep_time);
            }
            else if(this->name == "SNA")
            {
                Microoperation temp("SNA");
                temp.run(sleep_time);
            }
            else if(this->name == "SZA")
            {
                Microoperation temp("SZA");
                temp.run(sleep_time);
            }
            else if(this->name == "BSA")
            {
                Microoperation temp("BSA");
                temp.run(sleep_time);
            }
            else if(this->name == "ISZ")
            {
                Microoperation temp("INCMAR");
                temp.run(sleep_time);
                sc.run(sleep_time);
                Microoperation temp2("INCPC");
                if(hardware::RAM.read(hardware::AR.output())==0)
                {
                    temp2.run(sleep_time);
                }
            }


            sc.run(sleep_time);
        }
    }
    mytime::m_timer.start();
}

Instruction::~Instruction()
{

}

void Instruction::getDirectAddress(int sleep_time)
{
    Microoperation temp("MARTOAR");
    temp.run(sleep_time);
}

void Instruction::fetch(int sleep_time)
{
    Microoperation temp1("PCTOAR"), temp2("INCPC"), temp3("MARTOIR");
    Microoperation sc("INCSC");
    temp1.run(sleep_time);
    temp2.run(sleep_time);
    sc.run(sleep_time);
    temp3.run(sleep_time);
    sc.run(sleep_time);
}

void Instruction::decode(int sleep_time)
{
    Microoperation temp1("IRTOAR"), temp2("IRTOI");
    Microoperation sc("INCSC");
    temp1.run(sleep_time);
    temp2.run(sleep_time);
    sc.run(sleep_time);
}
