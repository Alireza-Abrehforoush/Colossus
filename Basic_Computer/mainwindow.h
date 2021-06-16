#ifndef MAINWINDOW_BNBVCMNNBCMNBMCJNKMXMSL
#define MAINWINDOW_BNBVCMNNBCMNBMCJNKMXMSL

#include <QMainWindow>
#include <QTextCursor>
#include "autocompleteaction.h"

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
    QString ignoreComments(const QString& text);
    QVector<QString> detectVariable(const QString& text);
    void setTextEditColor(int instruction);
private slots:
    void text_edit_correct_color();
    void text_edit_check_syntax();
    void text_edit_update_autocomplete();
    void auto_complete_selected(const QString& content);
    void assemble_triggered();
protected:
    void keyPressedEvent(QKeyEvent* e);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif
