CONFIG += c++11     
CONFIG += console  
CONFIG += testcase   
QMAKE_CXXFLAGS += -std=c++11

TARGET = tests
TEMPLATE = app

include(../src/src.pri)

SOURCES -= ../src/sources/main.cpp
SOURCES += main.cpp
HEADERS += catch.hpp

CONFIG(debug, debug|release) {
    DESTDIR = ../build/debug/tests
} else {
    DESTDIR = ../build/release/tests
}

OBJECTS_DIR = $$DESTDIR/.obj
