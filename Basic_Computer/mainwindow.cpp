#include <QDebug>
#include <QTableWidget>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "style.h"
#include "QColor"
#include "QKeyEvent"
#include "instructions.h"
#include "variable.h"
#include "instruction.h"
#include "assembe.h"
#include "parser.h"
#include "Hardware.h"
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
    QVector<QString>temp=Variable::var_pre_assemble+instructions::mem_ref_vec+instructions::reg_ref_vec+instructions::io_ref_vec+instructions::directives_vec;
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

QVector<QString> MainWindow::ignoreComments(const QString &raw_text)
{
    QVector<QString> plain_text = raw_text.split("\n").toVector();
    QVector<QString> refined_text;
    refined_text.push_back("");
    bool comment_began = false;
    for(long long int i = 0; i < plain_text.size(); i++)
    {
        QString current_line = "";
        for(long long int j = 0; j < plain_text[i].size(); j++)
        {
            if(plain_text[i].at(j) == '/')
            {
                if(j == plain_text[i].size() - 1)
                {
                    continue;
                }
                else
                {
                    if(comment_began)
                    {
                        while(j < plain_text[i].size() - 1 && !(plain_text[i].at(j) == '*' && plain_text[i].at(j + 1) == '/'))
                        {
                            j++;
                        }
                        if(plain_text[i].at(j) == '*')
                        {
                            j += 2;
                            comment_began = false;
                        }
                    }
                    else if(plain_text[i].at(j + 1) == '/')
                    {
                        j += 2;
                        while(j < plain_text[i].size())
                        {
                            j++;
                        }
                    }
                    else if(plain_text[i].at(j + 1) == '*')
                    {
                        j += 2;
                        comment_began = true;
                        while(j < plain_text[i].size() - 1 && !(plain_text[i].at(j) == '*' && plain_text[i].at(j + 1) == '/'))
                        {
                            j++;
                        }
                        if(plain_text[i].at(j) == '*')
                        {
                            j += 2;
                            comment_began = false;
                        }

                    }
                }
            }
            current_line += plain_text[i].at(j);
        }
        refined_text.push_back(current_line);
    }
    return refined_text;
}

QVector<QString> MainWindow::detectVariable(QVector<QString> total)
{
    int address = 0;
    QVector<QString> instructions;
    for(long long int i = 0; i < total.size(); i++)
    {
        if(total[i].indexOf(',') >= 0)
        {
            Variable* kemp = new Variable(total[i], address, i, this);
            if(kemp->getSyntaxValid() == false)
            {
                continue;
            }
            AssemblyVariable::Variables_list.push_back(kemp);
            instructions.push_back("");
            address++;
        }
        else
        {
            instructions.push_back(total[i]);
            Instruction temp(total[i]);
            if(temp.getSyntaxValid())
            {
                if(temp.getName() == "ORG")
                {
                    address = temp.getVar().toInt();
                    address++;
                }
            }
            if(Parser::isEmptyLine(total[i]) == false)
            {
                address++;
            }
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

QVector<QString> MainWindow::detectInstruction(QVector<QString> total)
{

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
    QVector<QString> main_part=p.GetMainPart();
    QVector<QString>ignored_part=p.GetIgnoredPart();
    if(main_part.size()==0)
    {
        return;
    }
    else if (line.indexOf(",")>=0)
    {
        is_run=true;
        c.removeSelectedText();

        if(Variable::checkSyntaxValid(line) == false)
        {
            ui->text_edit->setFontUnderline(true);
        }
        else
        {
            ui->text_edit->setFontUnderline(false);
        }

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
    else// it is instruction
    {
        Instruction ins(line);
        is_run=true;
        c.removeSelectedText();
        if (ins.getSyntaxValid()==false)
        {
            ui->text_edit->setFontUnderline(true);
        }
        else
        {
             ui->text_edit->setFontUnderline(false);
//             if (ins.getType()==instructions::mem_ref)
//             {
//                 QString var=ins.getVar();
//                 if(Variable::var_pre_assemble.indexOf(var)<0)
//                 {
//                     Variable::var_pre_assemble.push_back(var);
//                 }
//             }
        }
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
    if(ram_window != nullptr)
    {
        return;
    }
    QVector<QString> text_without_comment = this->ignoreComments(this->ui->text_edit->toPlainText());
    QVector<QString> instructions = this->detectVariable(text_without_comment);
    this->ram_window = new RamWindow();
    this->ram_window->show();
    this->setupVariableTable();
    connect(this->ram_window, SIGNAL(closed()), this, SLOT(deleteRamWindow()));
    Instruction cma("CMA", 2, 258);
    cma.execute();
}

void MainWindow::deleteRamWindow()
{
    delete ram_window;
    ram_window = nullptr;
    hardware::RAM.clearAll();
    this->clearVariableTable();
    ui->variable_table->setHidden(true);
    return;
}

void MainWindow::setupVariableTable()
{
    ui->variable_table->setColumnCount(3);
    ui->variable_table->setRowCount(AssemblyVariable::Variables_list.size());
    ui->variable_table->setHorizontalHeaderItem(0, new QTableWidgetItem("Label"));
    ui->variable_table->setHorizontalHeaderItem(1, new QTableWidgetItem("Decimal Value"));
    ui->variable_table->setHorizontalHeaderItem(2, new QTableWidgetItem("Hexadecimal Value"));
    for(int i = 0; i < AssemblyVariable::Variables_list.size(); i++)
    {
        this->addItem(i, 0, AssemblyVariable::Variables_list[i]->getName());
        int address = AssemblyVariable::Variables_list[i]->getAddress();
        this->addItem(i, 1, QString::number(hardware::RAM.read(address), 10));
        this->addItem(i, 2, QString::number(hardware::RAM.read(address), 16));
    }
    ui->variable_table->setHidden(false);
}

void MainWindow::addItem(int row, int column, const QString &content)
{
    QTableWidgetItem* address = new QTableWidgetItem(content);
    address->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
    address->setTextAlignment(Qt::AlignCenter);
    ui->variable_table->setItem(row, column, address);
}

void MainWindow::clearVariableTable()
{
    ui->variable_table->clear();
    AssemblyVariable::Variables_list.clear();
    return;
}

void MainWindow::keyPressedEvent(QKeyEvent *e)
{
    if (e->key()==Qt::DownArrow)
        this->setWindowTitle("Event");
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    text_edit_custom_menu(new QMenu(this))

{

    ui->setupUi(this);
    ui->variable_table->setHidden(true);
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
