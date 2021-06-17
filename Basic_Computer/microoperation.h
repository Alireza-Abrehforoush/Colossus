#ifndef MICROOPERATION_H
#define MICROOPERATION_H

#include "QString"
#include "QMap"

class Microoperation
{
private:
    QString text;
    QString nick_text;
    static bool exists(const QString& nick_text);
    static QMap<QString, Microoperation> micops;
public:
    Microoperation(const QString& nick_text, const QString& text = "");
    void run();

    static void setupMicrooperation();
};

#endif
