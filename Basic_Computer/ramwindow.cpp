#include "ramwindow.h"
#include "ui_ramwindow.h"

RamWindow::RamWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RamWindow)
{
    ui->setupUi(this);
}

RamWindow::~RamWindow()
{
    delete ui;
}
