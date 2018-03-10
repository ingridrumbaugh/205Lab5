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

HEADERS += ../tools/configuration.h
SOURCES += ../tools/configuration.cpp

HEADERS += ../tools/log.h
SOURCES += ../tools/log.cpp

HEADERS += ../tools/baseclass.h
SOURCES += ../tools/baseclass.cpp

### add any other source or header files you may need
