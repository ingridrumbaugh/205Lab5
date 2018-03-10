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

HEADERS += ../games/gameboard.h \
    ../games/gametoken.h \
    ../games/playertoken.h \
    ../games/trashtoken.h \
    ../games/robottoken.h \
    ../games/walltoken.h \
    ../tools/baseclass.h

SOURCES += ../games/gametoken.cpp \
    ../games/playertoken.cpp \
    ../games/trashtoken.cpp \
    ../games/robottoken.cpp \
    ../games/walltoken.cpp \
    ../tools/baseclass.cpp

LIBS    += -lncurses

### add any other source or header files you may need

