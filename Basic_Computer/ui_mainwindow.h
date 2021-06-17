/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAssemble_all;
    QAction *actionAssemble_all_2;
    QAction *actionaa;
    QAction *action22;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionSave_CTRL_S;
    QAction *actionSave_all;
    QAction *actionSave_as;
    QAction *actionQuit;
    QAction *actionAssemble_CTRL_D;
    QWidget *centralWidget;
    QTextEdit *text_edit;
    QTableWidget *variable_table;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAssemble;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1500, 700);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionAssemble_all = new QAction(MainWindow);
        actionAssemble_all->setObjectName(QString::fromUtf8("actionAssemble_all"));
        actionAssemble_all_2 = new QAction(MainWindow);
        actionAssemble_all_2->setObjectName(QString::fromUtf8("actionAssemble_all_2"));
        actionaa = new QAction(MainWindow);
        actionaa->setObjectName(QString::fromUtf8("actionaa"));
        action22 = new QAction(MainWindow);
        action22->setObjectName(QString::fromUtf8("action22"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionSave_CTRL_S = new QAction(MainWindow);
        actionSave_CTRL_S->setObjectName(QString::fromUtf8("actionSave_CTRL_S"));
        actionSave_all = new QAction(MainWindow);
        actionSave_all->setObjectName(QString::fromUtf8("actionSave_all"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAssemble_CTRL_D = new QAction(MainWindow);
        actionAssemble_CTRL_D->setObjectName(QString::fromUtf8("actionAssemble_CTRL_D"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        text_edit = new QTextEdit(centralWidget);
        text_edit->setObjectName(QString::fromUtf8("text_edit"));
        text_edit->setGeometry(QRect(10, 0, 1071, 551));
        variable_table = new QTableWidget(centralWidget);
        variable_table->setObjectName(QString::fromUtf8("variable_table"));
        variable_table->setGeometry(QRect(1100, 0, 341, 551));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1500, 26));
        menuBar->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"\n"
"color: rgb(255, 255, 255);"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuAssemble = new QMenu(menuBar);
        menuAssemble->setObjectName(QString::fromUtf8("menuAssemble"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuAssemble->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionSave_CTRL_S);
        menuFile->addAction(actionSave_all);
        menuFile->addAction(actionSave_as);
        menuFile->addAction(actionQuit);
        menuAssemble->addAction(actionAssemble_all_2);
        menuAssemble->addAction(actionAssemble_CTRL_D);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionAssemble_all->setText(QCoreApplication::translate("MainWindow", "Assemble all", nullptr));
        actionAssemble_all_2->setText(QCoreApplication::translate("MainWindow", "Assemble all", nullptr));
        actionaa->setText(QCoreApplication::translate("MainWindow", "aa", nullptr));
        action22->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        actionSave_CTRL_S->setText(QCoreApplication::translate("MainWindow", "Save(CTRL + S)", nullptr));
        actionSave_all->setText(QCoreApplication::translate("MainWindow", "Save all", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionAssemble_CTRL_D->setText(QCoreApplication::translate("MainWindow", "Assemble(CTRL + D)", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuAssemble->setTitle(QCoreApplication::translate("MainWindow", "Assemble", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
