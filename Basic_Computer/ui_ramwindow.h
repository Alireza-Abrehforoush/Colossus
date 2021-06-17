/********************************************************************************
** Form generated from reading UI file 'ramwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAMWINDOW_H
#define UI_RAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RamWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RamWindow)
    {
        if (RamWindow->objectName().isEmpty())
            RamWindow->setObjectName(QString::fromUtf8("RamWindow"));
        RamWindow->resize(1080, 600);
        centralwidget = new QWidget(RamWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(460, 10, 601, 521));
        RamWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RamWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1080, 26));
        RamWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RamWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RamWindow->setStatusBar(statusbar);

        retranslateUi(RamWindow);

        QMetaObject::connectSlotsByName(RamWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RamWindow)
    {
        RamWindow->setWindowTitle(QCoreApplication::translate("RamWindow", "RAM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RamWindow: public Ui_RamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAMWINDOW_H
