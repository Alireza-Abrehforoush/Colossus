#ifndef RAMWINDOW_CXCAGXAVXABHXB
#define RAMWINDOW_CXCAGXAVXABHXB

#include <QMainWindow>

namespace Ui {
class RamWindow;
}

class RamWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void closeEvent(QCloseEvent *event);
public:
    explicit RamWindow(QWidget *parent = nullptr);
    void addItem(int row, int column, const QString& content);
    ~RamWindow();

private slots:
    void updateRam(int address);

private:
    Ui::RamWindow *ui;

signals:
    void closed();
};

#endif // RAMWINDOW_H
