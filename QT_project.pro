#-------------------------------------------------
#
# Project created by QtCreator 2020-08-31T10:27:40
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    registers.cpp \
    newwidget.cpp \
    head.cpp \
    tree_view.cpp \
    set.cpp \
    classifier.cpp \
    record.cpp \
    password.cpp \
    maindebug.cpp \
    index.cpp

HEADERS  += mainwindow.h \
    registers.h \
    newwidget.h \
    head.h \
    tree_view.h \
    set.h \
    classifier.h \
    record.h \
    password.h \
    maindebug.h \
    index.h

FORMS    += mainwindow.ui \
    registers.ui \
    newwidget.ui \
    head.ui \
    tree_view.ui \
    set.ui \
    classifier.ui \
    record.ui \
    password.ui \
    maindebug.ui \
    index.ui

RESOURCES += \
    image/res.qrc

DISTFILES +=
