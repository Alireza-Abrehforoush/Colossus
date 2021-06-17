#ifndef MICROOPERATION_RFHJKMBVYUIO
#define MICROOPERATION_RFHJKMBVYUIO

#include "QString"

class Microoperation
{
private:
    QString text;
    QString nick_text;
public:
    Microoperation(const QString& nick_text, const QString& text = "");
    QString getText();
    QString getNickText();
    void run();
};

#endif // MICROOPERATION_H
