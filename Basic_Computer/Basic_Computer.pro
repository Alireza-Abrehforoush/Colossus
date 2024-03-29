#-------------------------------------------------
#
# Project created by QtCreator 2021-06-04T18:03:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Basic_Computer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    assembe.cpp\
    Hardware.cpp \
    capsulatedvalue.cpp \
    flag.cpp \
    instruction.cpp \
    instructions.cpp \
        main.cpp \
        mainwindow.cpp \
    memory.cpp \
    microoperation.cpp \
    mytimer.cpp \
    ramwindow.cpp \
    register.cpp \
    styles.cpp \
    autocompleteaction.cpp \
    values.cpp \
    variable.cpp \
    parser.cpp \
    mytime.cpp

HEADERS += \
    Hardware.h \
    assembe.h \
    capsulatedvalue.h \
    flag.h \
    instruction.h \
        mainwindow.h \
    memory.h \
    microoperation.h \
    mytimer.h \
    ramwindow.h \
    register.h \
    style.h \
    instructions.h \
    autocompleteaction.h \
    values.h \
    variable.h \
    parser.h \
    mytime.h

FORMS += \
        mainwindow.ui \
        ramwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
