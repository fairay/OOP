TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    errors.cpp \
    baselist.cpp

HEADERS += \
    errors.h \
    baselist.h \
    list.h \
    node.h \
    iter.h \
    baseiter.h \
    const_iter.h \
    list.hpp \
    iter.hpp \
    const_iter.hpp \
    node.hpp \
    baseiter.hpp
