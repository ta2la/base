TARGET     = geogebra
CONFIG    += staticlib
TEMPLATE   = lib
#######################################################################################
CONFIG += c++11
DESTDIR = $$PWD/debug

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../base/include

SOURCES += $$PWD/*.cpp
HEADERS += $$PWD/*.h

#QT += core testlib
