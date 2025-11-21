TARGET       = base
TEMPLATE     = lib
CONFIG      += staticlib
#######################################################################################
CONFIG += c++11
DESTDIR = $$PWD/debug

SOURCES     += $$PWD/src/*.cpp
HEADERS     += $$PWD/include/*.h

INCLUDEPATH += $$PWD/include
