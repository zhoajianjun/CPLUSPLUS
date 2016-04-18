TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
CONFIG += C++11
#CONFIG += --no-as-needed

LIBS += -L/usr/local/lib -lboost_system -lboost_thread
