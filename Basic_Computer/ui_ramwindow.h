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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RamWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *run;
    QPushButton *step;
    QPushButton *reset;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QTableWidget *register_table;
    QTableWidget *flags_table;
    QPushButton *help;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *input_enable;
    QPushButton *ouput_enable;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *input_line_edit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSlider *speed;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *microoperation_line_edit;
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
        tableWidget->setGeometry(QRect(490, 40, 571, 491));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(750, 0, 61, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 30, 91, 41));
        label_2->setFont(font);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(300, 30, 61, 41));
        label_6->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(80, 510, 295, 30));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        run = new QPushButton(layoutWidget);
        run->setObjectName(QString::fromUtf8("run"));

        horizontalLayout_3->addWidget(run);

        step = new QPushButton(layoutWidget);
        step->setObjectName(QString::fromUtf8("step"));

        horizontalLayout_3->addWidget(step);

        reset = new QPushButton(layoutWidget);
        reset->setObjectName(QString::fromUtf8("reset"));

        horizontalLayout_3->addWidget(reset);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(32, 80, 391, 401));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        register_table = new QTableWidget(layoutWidget1);
        register_table->setObjectName(QString::fromUtf8("register_table"));

        horizontalLayout_6->addWidget(register_table);

        flags_table = new QTableWidget(layoutWidget1);
        flags_table->setObjectName(QString::fromUtf8("flags_table"));

        horizontalLayout_6->addWidget(flags_table);


        verticalLayout->addLayout(horizontalLayout_6);

        help = new QPushButton(layoutWidget1);
        help->setObjectName(QString::fromUtf8("help"));

        verticalLayout->addWidget(help);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        input_enable = new QPushButton(layoutWidget1);
        input_enable->setObjectName(QString::fromUtf8("input_enable"));

        horizontalLayout_2->addWidget(input_enable);

        ouput_enable = new QPushButton(layoutWidget1);
        ouput_enable->setObjectName(QString::fromUtf8("ouput_enable"));

        horizontalLayout_2->addWidget(ouput_enable);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);

        horizontalLayout->addWidget(label_3);

        input_line_edit = new QLineEdit(layoutWidget1);
        input_line_edit->setObjectName(QString::fromUtf8("input_line_edit"));
        input_line_edit->setFont(font1);

        horizontalLayout->addWidget(input_line_edit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_5->addWidget(label_4);

        speed = new QSlider(layoutWidget1);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setValue(20);
        speed->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(speed);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        microoperation_line_edit = new QLineEdit(layoutWidget1);
        microoperation_line_edit->setObjectName(QString::fromUtf8("microoperation_line_edit"));

        horizontalLayout_4->addWidget(microoperation_line_edit);


        verticalLayout->addLayout(horizontalLayout_4);

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
        label->setText(QCoreApplication::translate("RamWindow", "RAM:", nullptr));
        label_2->setText(QCoreApplication::translate("RamWindow", "Registers:", nullptr));
        label_6->setText(QCoreApplication::translate("RamWindow", "Flags:", nullptr));
        run->setText(QCoreApplication::translate("RamWindow", "Run", nullptr));
        step->setText(QCoreApplication::translate("RamWindow", "Step", nullptr));
        reset->setText(QCoreApplication::translate("RamWindow", "Reset", nullptr));
        help->setText(QCoreApplication::translate("RamWindow", "?", nullptr));
        input_enable->setText(QCoreApplication::translate("RamWindow", "Input Enable", nullptr));
        ouput_enable->setText(QCoreApplication::translate("RamWindow", "Output Enable", nullptr));
        label_3->setText(QCoreApplication::translate("RamWindow", "Input:", nullptr));
        label_4->setText(QCoreApplication::translate("RamWindow", "Speed:", nullptr));
        label_5->setText(QCoreApplication::translate("RamWindow", "Microoperation:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RamWindow: public Ui_RamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RAMWINDOW_H
