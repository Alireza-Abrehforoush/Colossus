#include "mainwindow.h"
#include "ramwindow.h"
#include "Hardware.h"
#include "instruction.h"
#include "microoperation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Microoperation::setupMicrooperation();
    w.show();
    ///////////

    //RamWindow rw;
    //rw.show();
    ///////////
    return a.exec();
}
