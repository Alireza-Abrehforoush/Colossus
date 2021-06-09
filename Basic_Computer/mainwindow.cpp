#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include "QColor"
#include "QKeyEvent"
#include "instructions.h"
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object==this->ui->text_edit && event->type()==QEvent::KeyPress)
    {
        QKeyEvent *e = static_cast < QKeyEvent * >(event);
        int t=e->key();
        if (e->key()==16777237)
        {
            if(this->auto_complete_members.empty()==false)
            {
                this->setWindowTitle("Down");
                this->auto_complete_members[0]->hover();
            }
        }
    }
    return QMainWindow::eventFilter(object, event);
}

void MainWindow::updateAutoCompleteMembers()
{
    this->auto_complete_members.clear();
     text_edit_custom_menu->clear();
    QVector<QString>temp=instructions::mem_ref_vec+instructions::reg_ref_vec;
    for (int i=0;i<temp.size();i++)
    {
        if (temp[i].startsWith(current_word))
        {

            AutoCompleteAction* a=new AutoCompleteAction(temp[i],this);
            connect(a,SIGNAL(autocomplete_action_triggered(const QString&)),this,SLOT(auto_complete_selected(const QString&)));
            this->auto_complete_members.push_back(a);
            text_edit_custom_menu->addAction(a);
        }
    }

}

void MainWindow::text_edit_correct_color()
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
        current_word.clear();
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
    else
    {
        current_word=current_word+temp;
    }




}

void MainWindow::text_edit_update_autocomplete()
{

    QRect rect=this->ui->text_edit->cursorRect();
    QPoint p(rect.x(),rect.y());

    this->updateAutoCompleteMembers();

    text_edit_custom_menu->move(p.x(),p.y()+2*14);
   // this->setWindowTitle(QString::number(p.y()));
    //text_edit_custom_menu->show();

}

void MainWindow::auto_complete_selected(const QString &content)
{
    QString res;
    for(int i=current_word.size();i<content.size();i++)
    {
        res.append(content[i]);
    }
    ui->text_edit->insertPlainText(res);
    this->text_edit_custom_menu->clear();
}

void MainWindow::keyPressedEvent(QKeyEvent *e)
{   if (e->key()==Qt::DownArrow)
     this->setWindowTitle("Event");

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    text_edit_custom_menu(new QMenu())

{

    ui->setupUi(this);
    this->ui->text_edit->setStyleSheet(styles::bg_styles[styles::mode]);
    text_edit_custom_menu->setParent(this->ui->text_edit);

    this->ui->text_edit->installEventFilter(this);

    this->text_edit_custom_menu->setStyleSheet("QMenu{background-color : rgb(255,255,255);color : rgb(0,0,0)}\nQMenu::item::selected{background-color : rgb(85,255,255);}");
    this->ui->text_edit->insertPlainText("ORG 100\n");
    connect(this->ui->text_edit,SIGNAL(textChanged()),this,SLOT(text_edit_correct_color()));
    connect(this->ui->text_edit,SIGNAL(textChanged()),this,SLOT(text_edit_update_autocomplete()));


}

MainWindow::~MainWindow()
{
    delete ui;
}
