#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include "QColor"
#include "QKeyEvent"
#include "instructions.h"
#include "variable.h"
#include "assembe.h"
#include "parser.h"
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object==this->ui->text_edit && event->type()==QEvent::KeyPress)
    {
        QKeyEvent *e = static_cast < QKeyEvent * >(event);
        int t=e->key();
        int down_key_code=16777237;
        int up_key_code=16777235;
        int tab_key_code=16777217;
        int enter_key_code=16777220;
        if (e->key()==down_key_code)//down key pressed
        {
            if(this->auto_complete_members.empty()==false)
            {



                if(this->current_member_index<this->auto_complete_members.size()-1)
                {
                    this->current_member_index++;

                    this->text_edit_custom_menu->setActiveAction(this->auto_complete_members[this->current_member_index]);
                }

                return true;

            }

        }

        else if(e->key()==up_key_code)//up key pressed
        {
            QAction* act=this->text_edit_custom_menu->activeAction();
            if(act==nullptr)
            {
                return QMainWindow::eventFilter(object,event);
            }
            if(this->auto_complete_members.empty()==false)
            {
                if(this->current_member_index>0)
                {   this->current_member_index--;

                    this->text_edit_custom_menu->setActiveAction(this->auto_complete_members[this->current_member_index]);

                }
                return true;
            }
        }
        else if(e->key()==tab_key_code || e->key()==enter_key_code)
        {

            QAction* active_act=this->text_edit_custom_menu->activeAction();
            if(active_act)

            {
                    active_act->trigger();
                    this->ui->text_edit->insertPlainText(" ");

                    return true;

            }


        }
    }
    return QMainWindow::eventFilter(object, event);
}

void MainWindow::updateAutoCompleteMembers()
{

    this->auto_complete_members.clear();
     text_edit_custom_menu->clear();
     if (current_word=="")
         return;
    QVector<QString>temp=instructions::mem_ref_vec+instructions::reg_ref_vec;
    for (int i=0;i<temp.size();i++)
    {
        if (temp[i].startsWith(current_word))
        {

            AutoCompleteAction* a=new AutoCompleteAction(temp[i],this->text_edit_custom_menu);
            connect(a,SIGNAL(autocomplete_action_triggered(const QString&)),this,SLOT(auto_complete_selected(const QString&)));
            this->auto_complete_members.push_back(a);
            text_edit_custom_menu->addAction(a);
        }
    }

}

void MainWindow::text_edit_correct_color(int begin_pos, int end_pos)
{

 QTextCursor c=ui->text_edit->textCursor();
 c.setPosition(begin_pos);
 while(c.position()<=end_pos)
     c.movePosition(QTextCursor::PreviousCharacter,QTextCursor::KeepAnchor,1);
 QString total_text=c.selectedText();

    QStringList l=total_text.split(" ");
    //qDebug()<<"space number of it is "<<l.size()<<"\n";
}

QString MainWindow::ignoreComments(const QString &raw_text)
{
    QString refined_text = "";
    bool comment_began = false;
    for(long long int i = 0; i < raw_text.size(); i++)
    {

        if(raw_text.at(i) == '/')
        {
            if(i == raw_text.size() - 1)
            {
                continue;
            }
            else
            {
                if(raw_text.at(i + 1) == '/')
                {
                    i += 2;
                    while(raw_text.at(i) != '\n')
                    {
                        i++;
                    }
                }
                else if(raw_text.at(i + 1) == '*')
                {
                    i += 2;
                    while(i < raw_text.size() - 1 && !(raw_text.at(i) == '*' && raw_text.at(i + 1) == '/'))
                    {
                        i++;
                    }
                    i += 2;
                }
            }
        }
        refined_text.push_back(raw_text.at(i));
    }
    return refined_text;
}

QVector<QString> MainWindow::detectVariable(const QString &text)
{
    QVector<QString> total = text.split("\n").toVector();
    QVector<QString> instructions;
    for(long long int i = 0; i < total.size(); i++)
    {
        if(total[i].indexOf(',') >= 0)
        {
            AssemblyVariable::Variables_list.push_back(new Variable(total[i], this));
        }
        else
        {
            instructions.push_back(total[i]);
        }
    }
    return instructions;
}

void MainWindow::setTextEditColor(int instruction)
{
    if (instruction == instructions::mem_ref)
    {
        this->ui->text_edit->setTextColor(styles::mem_ref_color[styles::mode]);
    }
    else if(instruction == instructions::reg_ref)
    {
        this->ui->text_edit->setTextColor(styles::reg_ref_color[styles::mode]);
    }
    else if(instruction == instructions::io_ref)
    {
        this->ui->text_edit->setTextColor(styles::io_ref_color[styles::mode]);
    }
    else if(instruction == instructions::directives)
    {
        this->ui->text_edit->setTextColor(styles::directives_color[styles::mode]);
    }
}

void MainWindow::text_edit_correct_color()
{


    if (is_run)
        return;
      QTextCursor c=ui->text_edit->textCursor();
      c.select(c.WordUnderCursor);
      is_run=true;

       this->current_word=c.selectedText();
      c.removeSelectedText();
      qDebug()<<this->current_word<<"\n";
      this->setTextEditColor(instructions::instruction_kind(current_word));
      this->ui->text_edit->insertPlainText(this->current_word);
      this->ui->text_edit->setTextColor(QColor(255,255,255));
      is_run=false;
}

void MainWindow::text_edit_check_syntax()
{
    if (is_run==true)
        return;
    QTextCursor c=ui->text_edit->textCursor();
    c.select(c.LineUnderCursor);
    QString line=c.selectedText();

    Parser p(line);
    if (line.indexOf(",")>=0)
    {
        is_run=true;
        c.removeSelectedText();
        Variable v(line);
        if(v.getSyntaxValid()==false)
        {
            ui->text_edit->setFontUnderline(true);
        }
        else {
            ui->text_edit->setFontUnderline(false);
        }
            QVector<QString> main_part=p.GetMainPart();
            QVector<QString>ignored_part=p.GetIgnoredPart();
            int cnt=0;
            for(;cnt<main_part.size();cnt++)
            {
                ui->text_edit->insertPlainText(ignored_part[cnt]);
                this->setTextEditColor(instructions::instruction_kind(main_part[cnt]));
                ui->text_edit->insertPlainText(main_part[cnt]);
                ui->text_edit->setTextColor(QColor(255,255,255));
         }
            ui->text_edit->insertPlainText(ignored_part[cnt]);
            ui->text_edit->setFontUnderline(false);
            is_run=false;
    }
}

void MainWindow::text_edit_update_autocomplete()
{
    this->current_member_index=-1;
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

void MainWindow::assemble_triggered()
{
    QString text_without_comment = this->ignoreComments(this->ui->text_edit->toPlainText());
    QVector<QString> instructions = this->detectVariable(text_without_comment);
}

void MainWindow::keyPressedEvent(QKeyEvent *e)
{   if (e->key()==Qt::DownArrow)
     this->setWindowTitle("Event");

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    text_edit_custom_menu(new QMenu(this))

{

    ui->setupUi(this);
    this->ui->text_edit->setStyleSheet(styles::bg_styles[styles::mode]);
    text_edit_custom_menu->setParent(this->ui->text_edit);

    this->ui->text_edit->installEventFilter(this);

    this->text_edit_custom_menu->setStyleSheet("QMenu{background-color : rgb(255,255,255);color : rgb(0,0,0)}\nQMenu::item::selected{background-color : rgb(85,255,255);}");
    this->ui->text_edit->insertPlainText("ORG 100\n");
    connect(this->ui->text_edit, SIGNAL(textChanged()),this,SLOT(text_edit_correct_color()));
    connect(this->ui->text_edit, SIGNAL(textChanged()),this,SLOT(text_edit_update_autocomplete()));
    connect(this->ui->text_edit, SIGNAL(textChanged()),this,SLOT(text_edit_check_syntax()));
    connect(this->ui->actionAssemble_all_2, SIGNAL(triggered()), this, SLOT(assemble_triggered()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
