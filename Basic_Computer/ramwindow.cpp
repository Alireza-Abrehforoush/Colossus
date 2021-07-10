#include "ramwindow.h"
#include "ui_ramwindow.h"
#include "Hardware.h"
#include "values.h"
#include "assembe.h"
#include <QDebug>
#include <QThread>
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
    ui->microoperation_line_edit->setReadOnly(true);
    ui->microoperation_line_edit->setAlignment(Qt::AlignCenter);
    //
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setRowCount(4096);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Label"));
    ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Address"));
    ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Instruction"));
    ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Hex"));

    ui->register_table->verticalHeader()->setVisible(false);
    ui->register_table->setColumnCount(2);
    ui->register_table->setRowCount(8);
    ui->register_table->setHorizontalHeaderItem(0,new QTableWidgetItem("name"));
    ui->register_table->setHorizontalHeaderItem(0,new QTableWidgetItem("value"));

    ui->flags_table->verticalHeader()->setVisible(false);
    ui->flags_table->setColumnCount(2);
    ui->flags_table->setRowCount(7);
    ui->flags_table->setHorizontalHeaderItem(0,new QTableWidgetItem("name"));
    ui->flags_table->setHorizontalHeaderItem(0,new QTableWidgetItem("value"));

    /////////////////////
    this->updateRegisters();
    this->updateFlags();

    for(int i = 0; i < 4096; i++)
    {
        this->addItem(i, 1, QString::number(i, 16));
        this->addItem(i, 3, QString::number(hardware::RAM.read(i), 16));
    }
    for(int i=0;i<AssemblyVariable::Variables_list.size();i++)
    {

            this->addItem(AssemblyVariable::Variables_list[i]->getAddress(),0,AssemblyVariable::Variables_list[i]->getName());

    }
    for(int i=0;i<AssemblyVariable::Instruction_list.size();i++)
    {

         this->addItem(AssemblyVariable::Instruction_list[i].getAddress(),2,AssemblyVariable::Instruction_list[i].getName());

    }


    connect(&hardware::RAM, SIGNAL(valueChanged(int)), this, SLOT(updateRam(int)));
    connect(this->ui->run, SIGNAL(clicked()), this, SLOT(run()));
    connect(&values::current_microoperation_text, &CapsulatedValue::valueChanged, this, &RamWindow::updateMicrooperationText);

    connect(&hardware::AC,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));
    connect(&hardware::PC,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));
    connect(&hardware::AR,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));
    connect(&hardware::DR,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));
    connect(&hardware::IR,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));
    connect(&hardware::SC,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));
    connect(&hardware::INPR,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));
    connect(&hardware::OUTR,SIGNAL(valueChanged()),this,SLOT(updateRegisters()));



     connect(&hardware::I,SIGNAL(valueChanged()),this,SLOT(updateFlags()));
      connect(&hardware::S,SIGNAL(valueChanged()),this,SLOT(updateFlags()));
      connect(&hardware::R,SIGNAL(valueChanged()),this,SLOT(updateFlags()));
      connect(&hardware::E,SIGNAL(valueChanged()),this,SLOT(updateFlags()));
      connect(&hardware::IEN,SIGNAL(valueChanged()),this,SLOT(updateFlags()));
      connect(&hardware::FGI,SIGNAL(valueChanged()),this,SLOT(updateFlags()));
      connect(&hardware::FGO,SIGNAL(valueChanged()),this,SLOT(updateFlags()));


    //connect(&values::current_microoperation_text, SIGNAL(valueChanged(const QString&)), this, SLOT(updateMicrooperationText(const QString&)));
}

void RamWindow::addItem(int row, int column, const QString &content)
{

    QTableWidgetItem* address = new QTableWidgetItem(content);
    address->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    address->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(row, column, address);

}

void RamWindow::addItem(QTableWidget *table, int row, int column, const QString &content)
{

    QTableWidgetItem* address = new QTableWidgetItem(content);
    address->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    address->setTextAlignment(Qt::AlignCenter);
    table->setItem(row, column, address);
}

RamWindow::~RamWindow()
{
    delete ui;
}

void RamWindow::run()
{

    int sleep_time=(100-ui->speed->value())/**10*/;
    hardware::PC.load(AssemblyVariable::Instruction_list[0].getAddress());
    for(int i=0;i<AssemblyVariable::Instruction_list.size();i++)
    {
        AssemblyVariable::Instruction_list[i].execute(sleep_time);
    }

}

void RamWindow::updateRam(int address)
{
    this->addItem(address, 3, QString::number(hardware::RAM.read(address), 16));

}

void RamWindow::updateRegisters()
{
    this->addItem(ui->register_table,0,0,"AC");
    this->addItem(ui->register_table,0,1,QString::number(hardware::AC.output()));
    this->addItem(ui->register_table,1,0,"IR");
    this->addItem(ui->register_table,1,1,QString::number(hardware::IR.output()));
    this->addItem(ui->register_table,2,0,"AR");
    this->addItem(ui->register_table,2,1,QString::number(hardware::AR.output()));
    this->addItem(ui->register_table,3,0,"DR");
    this->addItem(ui->register_table,3,1,QString::number(hardware::DR.output()));
    this->addItem(ui->register_table,4,0,"INPR");
    this->addItem(ui->register_table,4,1,QString::number(hardware::INPR.output()));
    this->addItem(ui->register_table,5,0,"OUTR");
    this->addItem(ui->register_table,5,1,QString::number(hardware::OUTR.output()));
    this->addItem(ui->register_table,6,0,"AC");
    this->addItem(ui->register_table,6,1,QString::number(hardware::AC.output()));
    this->addItem(ui->register_table,7,0,"SC");
    this->addItem(ui->register_table,7,1,QString::number(hardware::SC.output()));

}

void RamWindow::updateFlags()
{
    this->addItem(ui->flags_table,0,0,"I");
    this->addItem(ui->flags_table,0,1,QString::number(hardware::I.getValue()));
    this->addItem(ui->flags_table,1,0,"E");
    this->addItem(ui->flags_table,1,1,QString::number(hardware::E.getValue()));
    this->addItem(ui->flags_table,2,0,"R");
    this->addItem(ui->flags_table,2,1,QString::number(hardware::S.getValue()));
    this->addItem(ui->flags_table,3,0,"S");
    this->addItem(ui->flags_table,3,1,QString::number(hardware::IEN.getValue()));
    this->addItem(ui->flags_table,4,0,"IEN");
    this->addItem(ui->flags_table,4,1,QString::number(hardware::IEN.getValue()));
    this->addItem(ui->flags_table,5,0,"FGI");
    this->addItem(ui->flags_table,5,1,QString::number(hardware::FGI.getValue()));
    this->addItem(ui->flags_table,6,0,"FGO");
    this->addItem(ui->flags_table,6,1,QString::number(hardware::FGO.getValue()));
}

void RamWindow::updateMicrooperationText(const QString &text)
{
    ui->microoperation_line_edit->setText(text);
    return;
}
