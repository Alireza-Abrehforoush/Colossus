#include "mainwindow.h"
#include "ramwindow.h"
#include "Hardware.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    ///////////
    RamWindow rw;
    rw.show();
    ///////////
    return a.exec();
}
