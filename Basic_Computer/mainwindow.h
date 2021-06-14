#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    QMenu * text_edit_custom_menu=nullptr;
    QString current_word="";
    bool eventFilter(QObject *object, QEvent *event);
    void updateAutoCompleteMembers();
    void text_edit_correct_color(int begin_pos,int end_pos);
    QString ignoreComments(const QString& text);
private slots:
    void text_edit_correct_color();
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

#endif // MAINWINDOW_H
