
TEMPLATE = app
TARGET = future-cpp-loop
INCLUDEPATH += . ogis-cpp-loop/include ogis-cpp-loop/

QT -= core gui
CONFIG += debug console

# there is an issue with compiling pedantic,
# as strict/pedantic C++11 does NOT allow  OPTIONAL variadic arguments.
# since C++20 this problem is solved.

#win32-g++: QMAKE_CXXFLAGS += -pedantic-errors -pedantic
#linux-g++: QMAKE_CXXFLAGS += -pedantic-errors -pedantic


# Input
HEADERS += ogis-cpp-loop.examples/examples/asciishapes.hpp \
           ogis-cpp-loop.examples/examples/matrix.hpp \
           ogis-cpp-loop.examples/examples/matrix_io.hpp \
           ogis-cpp-loop/asciiart.hpp \
           ogis-cpp-loop/include/cpploop.h \
           ogis-cpp-loop/include/loop \


SOURCES += \
           ogis-cpp-loop.examples/examples/tests_loops.cpp \
           ogis-cpp-loop.examples/examples/asciishapes_using_for.cpp \
           ogis-cpp-loop.examples/examples/asciishapes_using_loop.cpp \
           ogis-cpp-loop.examples/examples/example_matrix.cpp \
           ogis-cpp-loop.examples/examples/main.cpp \
           ogis-godbolt.examples/ogis-loop-godbolt-example.cpp

DISTFILES += \
  INSTALL.txt
