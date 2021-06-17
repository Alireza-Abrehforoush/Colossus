#include "ramwindow.h"
#include "ui_ramwindow.h"
#include "Hardware.h"

void RamWindow::closeEvent(QCloseEvent *event)
{
    emit this->closed();
    return;
}

RamWindow::RamWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RamWindow)
{
    ui->setupUi(this);


    //setting fixed size for RAM window
    setWindowFlags(Qt::Widget | Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(1080, 600);

    //
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(4096);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Label"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Address"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Instruction"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Hex"));

    for(int i = 0; i < 4096; i++)
    {
        this->addItem(i, 1, QString::number(i, 16));
        this->addItem(i, 3, QString::number(hardware::RAM.read(i), 16));
    }


    connect(&hardware::RAM, SIGNAL(valueChanged(int)), this, SLOT(updateRam(int)));
}

void RamWindow::addItem(int row, int column, const QString &content)
{
    QTableWidgetItem* address = new QTableWidgetItem(content);
    address->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    address->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(row, column, address);
}

RamWindow::~RamWindow()
{
    delete ui;
}

void RamWindow::updateRam(int address)
{
    this->addItem(address, 3, QString::number(hardware::RAM.read(address), 16));

}
