#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include "QColor"
#include "instructions.h"
void MainWindow::text_edit_changed()
{
    static bool is_run=false;
    if (is_run)
        return;
    QTextCursor c=ui->text_edit->textCursor();
    c.movePosition(QTextCursor::PreviousCharacter,QTextCursor::KeepAnchor,1);
    QString temp=c.selectedText();
    QChar new_line(8233);
    if (temp==" " || temp==new_line|| temp==",")
    {

        int cnt=0;
        for(;;cnt++)
        {
            c.movePosition(QTextCursor::PreviousCharacter,QTextCursor::KeepAnchor,1);
             temp=c.selectedText();
             QChar ch=temp[0];
            if(temp[0]==' '|| temp[0]==new_line|| temp[0]==',' || c.atStart())
                break;
        }
        is_run=true;
        c.removeSelectedText();
        QString temp2="";
        QString first="";
        first.append(temp[0]);
        this->ui->text_edit->insertPlainText(first);
        for(int i=1;i<temp.size()-1;i++)
            temp2.append(temp[i]);
        if(instructions::instruction_kind(temp2)==instructions::mem_ref)
            this->ui->text_edit->setTextColor(styles::mem_ref_color[styles::mode]);
        else if (instructions::instruction_kind(temp2)==instructions::reg_ref)
            this->ui->text_edit->setTextColor(styles::reg_ref_color[styles::mode]);
        else {
            this->ui->text_edit->setTextColor(QColor(255,255,255));
        }
        this->ui->text_edit->insertPlainText(temp2);
        this->ui->text_edit->setTextColor(QColor(255,255,255));
        QString end="";
        end.append(temp[temp.size()-1]);
        this->ui->text_edit->insertPlainText(end);
        QString contain=ui->text_edit->toPlainText();
        temp="";
        is_run=false;

    }



}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->text_edit->setStyleSheet(styles::bg_styles[styles::mode]);

    connect(this->ui->text_edit,SIGNAL(textChanged()),this,SLOT(text_edit_changed()));
    this->ui->text_edit->insertPlainText("hello world ADD");

}

MainWindow::~MainWindow()
{
    delete ui;
}
