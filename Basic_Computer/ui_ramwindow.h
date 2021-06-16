/********************************************************************************
** Form generated from reading UI file 'ramwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RAMWINDOW_H
#define UI_RAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RamWindow
{
public:
    QWidget *centralwidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RamWindow)
    {
        if (RamWindow->objectName().isEmpty())
            RamWindow->setObjectName(QString::fromUtf8("RamWindow"));
        RamWindow->resize(450, 600);
        centralwidget = new QWidget(RamWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(180, 30, 261, 341));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 259, 339));
        scrollArea->setWidget(scrollAreaWidgetContents);
        RamWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RamWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 450, 26));
        RamWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(RamWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RamWindow->setStatusBar(statusbar);

        retranslateUi(RamWindow);

        QMetaObject::connectSlotsByName(RamWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RamWindow)
    {
        RamWindow->setWindowTitle(QApplication::translate("RamWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RamWindow: public Ui_RamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAMWINDOW_H
