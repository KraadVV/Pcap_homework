TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
LIBS += -lpcap
SOURCES += main.cpp \
    printfunc.cpp \
    typeanalysis.cpp

HEADERS += \
    printfunc.h \
    typeanalysis.h
