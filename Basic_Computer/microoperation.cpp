#include "Microoperation.h"
#include "Hardware.h"
#include "values.h"
#include "QDebug"
#include "mytime.h"
QMap<QString, Microoperation> Microoperation::micops;

bool Microoperation::exists(const QString &nick_text)
{

    auto it = micops.find(nick_text);
    return !(it == micops.end());
}

Microoperation::Microoperation(const QString &nick_text, const QString& text)
{
    this->nick_text = nick_text;
    if(text != "") this->text = text;
    else
    {
        if(exists(nick_text))
        {
            auto it = micops.find(nick_text);
            this->text = (*it).getText();
        }
    }
    return;
}

QString Microoperation::getText() const
{
    return this->text;
}

QString Microoperation::getNickText()
{
    return this->nick_text;
}

void Microoperation::run(int sleep_time)
{
    if(this->nick_text == "PCTOAR")
    {
        hardware::AR.load(hardware::PC.output());
    }
    else if(this->nick_text == "INCPC")
    {
        hardware::PC.increment();
    }
    else if(this->nick_text == "MARTOIR")
    {
        hardware::IR.load(hardware::RAM.read(hardware::AR.output()));
    }
    else if(this->nick_text == "IRTOAR")
    {
        Register::copy(hardware::IR, 0, 11, hardware::AR, 0, 11);
    }
    else if(this->nick_text == "IRTOI")
    {
        Register::copy(hardware::IR, 15, hardware::I);
    }
    else if(this->nick_text == "MARTOAR")
    {
        hardware::AR.load(hardware::RAM.read(hardware::AR.output()));
    }
    else if(this->nick_text == "CMA")
    {
        qDebug()<<hardware::AC.output();
        hardware::AC.onesComplement();
        qDebug()<<hardware::AC.output();
    }
    else if(this->nick_text == "CLA")
    {
        hardware::AC.clear();
    }
    else if(this->nick_text == "CLE")
    {
        hardware::E.setValue(0);
    }
    else if(this->nick_text == "CME")
    {
        hardware::E.complement();
    }
    else if(this->nick_text == "CIR")
    {
        Flag temp;
        Register::copy(hardware::AC, 0, temp);
        hardware::AC.shiftRight(hardware::E.getValue());
        hardware::E.setValue(temp.getValue());
    }
    else if(this->nick_text == "CIL")
    {
        Flag temp;
        Register::copy(hardware::AC, 15, temp);
        hardware::AC.shiftLeft(hardware::E.getValue());
        hardware::E.setValue(temp.getValue());
    }
    else if(this->nick_text == "INCAC")
    {
        hardware::AC.increment();
    }
    else if(this->nick_text == "SPA")
    {
        if(hardware::AC.at(15) == 0)
        {
            hardware::PC.increment();
        }
    }
    else if(this->nick_text == "SNA")
    {
        if(hardware::AC.at(15) == 1)
        {
            hardware::PC.increment();
        }
    }
    else if(this->nick_text == "SZA")
    {
        if(hardware::AC.isZero())
        {
            hardware::PC.increment();
        }
    }
    else if(this->nick_text == "SZE")
    {
        if(hardware::E.getValue() == 0)
        {
            hardware::PC.increment();
        }
    }
    else if(this->nick_text=="INCSC")
    {
        hardware::SC.increment();
    }
    else if(this->nick_text == "INCSC")
    {
        hardware::SC.clear();
    }

    else if(this->nick_text == "AND")
    {
        hardware::AC.load(hardware::AC.output() & hardware::RAM.read(hardware::AR.output()));
    }
    else if(this->nick_text == "ADD")
    {
        hardware::AC.load(hardware::AC.output() + hardware::RAM.read(hardware::AR.output()));
    }
    else if(this->nick_text == "LDA")
    {
        hardware::AC.load(hardware::RAM.read(hardware::AR.output()));
    }
    else if(this->nick_text == "STA")
    {
        qDebug() << hardware::AC.output() << '\n';
        qDebug() << hardware::RAM.read(hardware::AR.output()) << '\n';
        hardware::RAM.write(hardware::AR.output(), hardware::AC.output());
        qDebug() << hardware::RAM.read(hardware::AR.output()) << '\n';
    }
    else if(this->nick_text =="MARTOPC")
    {
        hardware::PC.load(hardware::RAM.read(hardware::AR.output()));
    }
    else if(this->nick_text == "BSA")
    {
        hardware::RAM.write(hardware::AR.output(),hardware::PC.output());
        hardware::PC.load(hardware::RAM.read(hardware::AR.output())+1);

    }
    else if(this->nick_text == "INCMAR")
    {
        hardware::RAM.write(hardware::AR.output(),hardware::RAM.read(hardware::AR.output())+1);

    }
    mytime::delay(sleep_time);
    values::current_microoperation_text.setValue(text);

}

void Microoperation::setupMicrooperation()
{
    micops.clear();
    micops.insert("PCTOAR", Microoperation("PCTOAR", "AR <- PC"));
    micops.insert("INCPC", Microoperation("INCPC", "PC <- PC + 1"));
    micops.insert("MARTOIR", Microoperation("MARTOIR", "IR <- M[AR]"));
    micops.insert("IRTOAR", Microoperation("IRTOAR", "AR <- IR[0:11]"));
    micops.insert("IRTOI", Microoperation("IRTOI", "I <- IR[15]"));
    micops.insert("MARTOAR", Microoperation("MARTOAR", "AR <- M[AR]"));
    micops.insert("CMA", Microoperation("CMA", "CMA <- not CMA"));
    micops.insert("CLA", Microoperation("CLA", "AC <- 0"));
    micops.insert("CLE", Microoperation("CLE", "E <- 0"));
    micops.insert("CME", Microoperation("CME", "E <- not E"));
    micops.insert("CIR", Microoperation("CIR", "AC(0...14) <- AC(1...15), AC(15) <- E, E <- AC(0)"));
    micops.insert("CIL", Microoperation("CIL", "AC(1...15) <- AC(0...14), AC(0) <- E, E <- AC(15)"));
    micops.insert("INCAC", Microoperation("INCAC", "AC <- AC + 1"));
    micops.insert("SPA", Microoperation("SPA", "if(AC(15) = 0) PC <- PC + 1"));
    micops.insert("SNA", Microoperation("SNA", "if(AC(15) = 1) PC <- PC + 1"));
    micops.insert("SZA", Microoperation("SZA", "if(AC = 0) PC <- PC + 1"));
    micops.insert("SZE", Microoperation("SZE", "if(E = 0) PC <- PC + 1"));

    micops.insert("AND", Microoperation("AND", "AC <- AC AND (M[XXX] or M[M[XXX]])"));
    micops.insert("ADD", Microoperation("ADD", "AC <- AC + (M[XXX] or M[M[XXX]])"));
    micops.insert("LDA", Microoperation("LDA", "AC <- M[XXX] or M[M[XXX]]"));
    micops.insert("STA", Microoperation("STA", "M[XXX] or M[M[XXX]] <- AC"));
    micops.insert("STA", Microoperation("INCSC", "SC<-SC+1"));
    micops.insert("STA", Microoperation("CLSC", "SC<-0"));
    micops.insert("MARTOPC", Microoperation("MARTOPC", "PC <-(M[XXX] or M[M[XXX]])"));
    micops.insert("BSA",Microoperation("BSA","PC <-(M[XXX] or M[M[XXX]])+1), (M[XXX] or M[M[XXX]])<-PC"));
    micops.insert("INCMAR",Microoperation("INCMAR","M[XX]<-M[XX]+1"));

    //micops.insert("PCTOAR", Microoperation("PCTOAR", "AR <- PC"));

}
