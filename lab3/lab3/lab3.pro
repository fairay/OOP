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
    errors/array_errors.cpp \
    errors/object_errors.cpp \
    objects/composite_object.cpp \
    objects/point/base_point.cpp \
    objects/point/point.cpp \
    objects/camera/base_camera.cpp \
    objects/camera/camera.cpp \
    objects/edge/base_edge.cpp \
    objects/edge/edge.cpp \
    objects/carcass/base_carcass.cpp \
    objects/carcass/carcass.cpp \
    objects/visitor/draw_visitor.cpp \
    objects/visitor/transform_visitor.cpp \
    builder/carcass_builder/txt_builder.cpp \
    errors/builder_errors.cpp \
    visualiser/qdrawer.cpp \
    errors/drawer_errors.cpp \
    visualiser/qdrawer_factory.cpp \
    visualiser/visualiser.cpp \
    builder/carcass_builder/director.cpp \
    transform/transformation.cpp \
    scene/base_scene.cpp \
    scene/scene.cpp \
    objects/visitor/object_visitor.cpp \
    builder/carcass_builder/base_builder.cpp \
    managers/scene_manager.cpp \
    errors/managers_errors.cpp \
    command/base_command.cpp \
    command/transform.cpp \
    command/draw_scene.cpp \
    visualiser/base_drawer_factory.cpp \
    command/load.cpp


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
    array/array.hpp \
    errors/object_errors.h \
    objects/simple_object.h \
    objects/scene_object.h \
    objects/composite_object.h \
    objects/camera/base_camera.h \
    objects/carcass/base_carcass.h \
    objects/edge/base_edge.h \
    objects/point/base_point.h \
    objects/point/point.h \
    objects/visitor/object_visitor.h \
    objects/creator/object_creator.h \
    objects/creator/edge_creator.h \
    objects/creator/point_creator.h \
    objects/creator/camera_creator.h \
    objects/camera/camera.h \
    objects/edge/edge.h \
    objects/carcass/carcass.h \
    objects/visitor/draw_visitor.h \
    objects/visitor/transform_visitor.h \
    builder/builder.h \
    builder/build_director.h \
    builder/carcass_builder/base_builder.h \
    builder/carcass_builder/director.h \
    builder/carcass_builder/txt_builder.h \
    errors/builder_errors.h \
    managers/scene_manager.h \
    scene/base_scene.h \
    scene/scene.h \
    scene/scene_interface.h \
    transform/transformator.h \
    transform/tranformation.h \
    visualiser/visualizer.h \
    visualiser/base_drawer.h \
    visualiser/qdrawer.h \
    errors/drawer_errors.h \
    visualiser/base_drawer_factory.h \
    visualiser/qdrawer_factory.h \
    errors/managers_errors.h \
    command/transform.h \
    command/draw_scene.h \
    command/load.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
