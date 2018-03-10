TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    ../tools/baseclass.cpp \
    playertoken.cpp \
    robottoken.cpp \
    trashtoken.cpp \
    walltoken.cpp \
    gametoken.cpp \
    gameengine.cpp \
    foodtoken.cpp

HEADERS += \
    playertoken.h \
    robottoken.h \
    trashtoken.h \
    walltoken.h \
    gametoken.h \
    ../tools/baseclass.h \
    gameengine.h \
    foodtoken.h \
    gameboard.h

LIBS += -lncurses

DISTFILES += \
    README
