#ifndef RAMWINDOW_H
#define RAMWINDOW_H

#include <QMainWindow>

namespace Ui {
class RamWindow;
}

class RamWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RamWindow(QWidget *parent = nullptr);
    ~RamWindow();

private:
    Ui::RamWindow *ui;
};

#endif // RAMWINDOW_H
