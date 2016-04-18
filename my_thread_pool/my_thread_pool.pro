TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    my_thread_pool.cpp \
    task_queue.cpp

HEADERS += \
    my_thread_pool.h \
    task_queue.h
CONFIG += C++11
#CONFIG += --no-as-needed
LIBS += -L/usr/local/lib -lboost_system -lboost_thread
#LIBS += -L/usr/lib -lpthread
