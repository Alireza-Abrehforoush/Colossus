#ifndef STYLE_H
#define STYLE_H
#include <QString>
#include <QColor>
#include <QVector>
using namespace  std;
namespace fonts
{
    int font_size=14;
    QString font_style="font: "+QString::number(font_size)+"pt \"Consolas\"";

}
namespace styles
{
    int dark_mode=0;
    int default_mode=1;
    int mode=dark_mode;
    QString bg_styles[4]={"background-color: rgb(30, 30, 30);\ncolor: rgb(255, 255, 255);\n"+fonts::font_style+";","background-color: rgb(250, 250, 250);\ncolor: rgb(0, 0, 0);\n"+fonts::font_style+";"};
    QColor mem_ref_color[4]={QColor(0,190,190)};
    QColor reg_ref_color[4]={QColor(0,235,0)};
}

#endif // STYLE_H
