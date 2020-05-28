TEMPLATE= app
TARGET=ogis-modern-cxx-future-cpp_examples

QT      -= core gui qt
CONFIG  += console c++17

DESTDIR += bin

INCLUDEPATH +=  ./includes ../ogis-cpp-loop/includes
HEADERS += \
    examples/asciishapes.hpp \
    examples/matrix.hpp \
    examples/matrix_io.hpp
	
SOURCES += \
    examples/asciishapes.cpp \
    examples/asciishapes_old_style.cpp \
    examples/main.cpp \
    examples/matrix.cpp

DISTFILES +=
