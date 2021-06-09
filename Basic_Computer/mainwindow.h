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
    QMenu * text_edit_custom_menu=nullptr;
    QString current_word="";
    bool eventFilter(QObject *object, QEvent *event);
    void updateAutoCompleteMembers();
    void text_edit_correct_color(int begin_pos,int end_pos);
private slots:
    void text_edit_correct_color();
    void text_edit_update_autocomplete();
    void auto_complete_selected(const QString& content);
protected:
    void keyPressedEvent(QKeyEvent* e);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
