TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    log.cpp \
    configuration.cpp \
    baseclass.cpp

HEADERS += \
    log.h \
    configuration.h \
    macro.h \
    baseclass.h
