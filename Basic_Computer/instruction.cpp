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
        if(part_number > 3)
        {
            this->syntax_valid = false;
            return;
        }
        if(part_number == 3 && main_part[3] != "I")
        {
            this->syntax_valid = false;
            return;
        }
    }

}
