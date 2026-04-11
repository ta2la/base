TARGET     = geogebra
CONFIG    += staticlib
TEMPLATE   = lib
#######################################################################################
CONFIG += c++11
wasm {
    CONFIG(debug, debug|release): SOURCEDIR = debug_wasm
    else:                         SOURCEDIR = release_wasm
} else {
    CONFIG(debug, debug|release): SOURCEDIR = debug
    else:                         SOURCEDIR = release
}
DESTDIR = $$PWD/../../BUILD/$$TARGET/$$SOURCEDIR

INCLUDEPATH += $$PWD/include
INCLUDEPATH += $$PWD/../base/include

SOURCES += $$PWD/*.cpp
HEADERS += $$PWD/*.h

#QT += core testlib
