#ifndef Microoperation_BUJBIUBGVCUHDBUJ
#define Microoperation_BUJBIUBGVCUHDBUJ

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
    QString getText() const;
    QString getNickText();
    void run(int sleep_time);

    static void setupMicrooperation();
};

#endif
