TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += C++11
CONFIG += --no-as-needed
#CONFIG += pthread

SOURCES += main.cpp
LIBS += -L/usr/local/lib -lboost_system
LIBS += -L/usr/lib -lpthread
#g++ -Wl,--no-as-needed -std=c++11 -pthread  -L/usr/local/lib -lboost_system main.cpp
