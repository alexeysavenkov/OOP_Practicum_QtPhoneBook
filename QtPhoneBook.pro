#-------------------------------------------------
#
# Project created by QtCreator 2017-05-20T22:17:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtPhoneBook
TEMPLATE = app


SOURCES += main.cpp\
    EditableStringList.cpp \
    PhoneBook.cpp \
    MainWindow.cpp

HEADERS  += \
    EditableStringList.h \
    PhoneBook.h \
    MainWindow.h

FORMS    += \
    EditableStringList.ui \
    MainWindow.ui \
    PhoneBook.ui

DISTFILES += \
    iconclose.png
