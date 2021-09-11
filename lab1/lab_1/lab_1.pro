#-------------------------------------------------
#
# Project created by QtCreator 2020-02-21T16:11:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab_1
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
    model_interface.cpp \
    action_interface.cpp \
    point_arr.cpp \
    proj_params.cpp \
    edge_arr.cpp \
    edge.cpp \
    point.cpp \
    transform.cpp \
    pedge.cpp \
    tranform_params.cpp \
    model.cpp \
    draw_module.cpp \
    points_data.cpp \
    edges_data.cpp \
    memory_module.cpp

HEADERS += \
        mainwindow.h \
    defines.h \
    model_interface.h \
    action_interface.h \
    edge.h \
    point.h \
    pedge.h \
    model.h \
    point_arr.h \
    proj_params.h \
    edge_arr.h \
    transform.h \
    transform_params.h \
    draw_module.h \
    points_data.h \
    edges_data.h \
    defines.h \
    memory_module.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    lab_1.pro
