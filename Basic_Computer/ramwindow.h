#ifndef RAMWINDOW_CXCAGXAVXABHXB
#define RAMWINDOW_CXCAGXAVXABHXB

#include <QMainWindow>
#include <QTableWidget>
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
    void addItem(QTableWidget* table,int row,int column,const QString& content);
    ~RamWindow();

private slots:
    void run();
    void updateRam(int address);
    void updateRegisters();
    void updateFlags();
    void updateMicrooperationText(const QString& text);
private:
    Ui::RamWindow *ui;

signals:
    void closed();
};

#endif
