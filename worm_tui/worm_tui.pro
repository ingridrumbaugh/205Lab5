TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \

HEADERS += ../worm/wormengine.h
SOURCES += ../worm/wormengine.cpp
HEADERS += ../tools/baseclass.h
SOURCES += ../tools/baseclass.cpp

HEADERS += ../games/gametoken.h
SOURCES += ../games/gametoken.cpp

HEADERS += ../games/playertoken.h
SOURCES += ../games/playertoken.cpp

HEADERS += ../games/robottoken.h
SOURCES += ../games/robottoken.cpp

HEADERS += ../games/trashtoken.h
SOURCES += ../games/trashtoken.cpp

HEADERS += ../games/walltoken.h
SOURCES += ../games/walltoken.cpp

HEADERS += ../games/gameboard.h

HEADERS += ../games/gameengine.h
SOURCES += ../games/gameengine.cpp


HEADERS += ../games/foodtoken.h
SOURCES += ../games/foodtoken.cpp

LIBS    += -lncurses
