TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

# if you are having compiler complaints about pthread, uncomment the following
LIBS += -pthread

SOURCES += ../googletest-master/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../googletest-master                                   \
                ../googletest-master/googletest                        \
                ../googletest-master/googletest/include                \
                ../googletest-master/googletest/include/gtest

HEADERS += ../tools/baseclass.h \
    gameboardtemplate.h
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

LIBS    += -lncurses
### add any other source or header files you may need
