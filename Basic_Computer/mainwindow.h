#ifndef MAINWINDOW_BNBVCMNNBCMNBMCJNKMXMSL
#define MAINWINDOW_BNBVCMNNBCMNBMCJNKMXMSL

#include <QMainWindow>
#include <QTextCursor>
#include "autocompleteaction.h"
#include "ramwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QVector<QAction*> auto_complete_members;
    int current_member_index=-1;
    bool is_run=false;
    QMenu * text_edit_custom_menu=nullptr;
    QString current_word="";
    bool eventFilter(QObject *object, QEvent *event);
    void updateAutoCompleteMembers();
    void text_edit_correct_color(int begin_pos,int end_pos);
    QVector<QString> ignoreComments(const QString& text);
    QVector<QString> detectVariable(QVector<QString> total);
    void setTextEditColor(int instruction);
    QVector<QString> detectInstruction(QVector<QString> total);
    RamWindow* ram_window = nullptr;
private slots:
    void text_edit_correct_color();
    void text_edit_check_syntax();
    void text_edit_update_autocomplete();
    void auto_complete_selected(const QString& content);
    void assemble_triggered();
    void deleteRamWindow();
    void setupVariableTable();
    void addItem(int row, int column, const QString &content);
    void clearVariableTable();
protected:
    void keyPressedEvent(QKeyEvent* e);
public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif
