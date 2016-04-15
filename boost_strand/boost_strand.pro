TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
CONFIG += --no-as-needed

SOURCES += main.cpp
LIBS += -L/usr/local/lib -lboost_system

LIBS += -L/usr/lib -lpthread
