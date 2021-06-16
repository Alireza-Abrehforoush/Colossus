#include "instructions.h"

int instructions::instruction_kind(QString instruction)
{
    for(int i=0; i < mem_ref_vec.size(); i++)
        if (instruction==mem_ref_vec[i])
            return mem_ref;
    for(int i=0; i < reg_ref_vec.size();i++)
        if (instruction==reg_ref_vec[i])
            return reg_ref;
    for(int i=0; i < io_ref_vec.size(); i++)
        if (instruction == io_ref_vec[i])
            return io_ref;
    for(int i=0; i < directives_vec.size();i++)
        if (instruction == directives_vec[i])
            return directives;
    return non;
}
