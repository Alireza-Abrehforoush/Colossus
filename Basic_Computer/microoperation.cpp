#include "microoperation.h"
#include "Hardware.h"

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
            this->text = micops[nick_text].getText();
        }
    }
    return;
}

QString Microoperation::getText()
{
    return this->text;
}

QString Microoperation::getNickText()
{
    return this->nick_text;
}

void Microoperation::run()
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

}

void Microoperation::setupMicrooperation()
{
    micops.clear();
    micops.insert("PCTOAR", Microoperation("PCTOAR", "AR <- PC"));
    micops.insert("INCPC", Microoperation("INCPC", "PC <- PC + 1"));
    micops.insert("MARTOIR", Microoperation("MARTOIR", "IR <- M[AR]"));
    micops.insert("IRTOAR", Microoperation("IRTOAR", "AR <- IR[0:11]"));
    micops.insert("IRTOI", Microoperation("IRTOI", "I <- IR[15]"));
    //micops.insert("PCTOAR", Microoperation("PCTOAR", "AR <- PC"));

}
