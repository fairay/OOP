#-------------------------------------------------
#
# Project created by QtCreator 2020-05-21T12:58:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab3
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
        main.cpp \
        mainwindow.cpp \
    array/base_array.cpp \
    errors/base_error.cpp \
    errors/array_errors.cpp

HEADERS += \
        mainwindow.h \
    command/base_command.h \
    array/array.h \
    errors/base_error.h \
    array/base_array.h \
    array/base_iter.h \
    array/base_iter.hpp \
    errors/array_errors.h \
    array/const_iter.h \
    array/iter.h \
    array/const_iter.hpp \
    array/iter.hpp \
    array/array.hpp

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
