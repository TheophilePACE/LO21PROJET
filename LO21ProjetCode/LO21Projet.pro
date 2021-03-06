HEADERS += \
    qmain.h \
    intermediary.h \
    mainwindow.h \
    litteral/litteral.h \
    litteral/atom.h \
    litteral/numeric.h \
    litteral/real.h \
    litteral/rationnal.h \
    litteral/integer.h \
    litteral/complex.h \
    litteral/program.h \
    litteral/expression.h \
    structures/structures.h \
    structures/stack.h \
    structures/parser.h \
    structures/identifierManager.h \
    structures/generalManager.h \
    structures/operator.h\
    qvareditor.h \
    qprogrameditor.h \
    snapshots.h \
    structures/shunting_yard_algorithm.h \
    structures/computerException.h

SOURCES += \
    main.cpp \
    qmain.cpp \
    intermediary.cpp \
    mainwindow.cpp \
    litteral/litteral.cpp \
    litteral/numeric.cpp \
    litteral/real.cpp \
    litteral/rationnal.cpp \
    litteral/integer.cpp \
    litteral/complex.cpp \
    litteral/expression.cpp \
    litteral/program.cpp \
    structures/structures.cpp \
    structures/stack.cpp \
    structures/parser.cpp \
    structures/identifierManager.cpp \
    structures/generalManager.cpp \
    structures/operator.cpp \
    qvareditor.cpp \
    qprogrameditor.cpp \
    snapshots.cpp \
    structures/shunting_yard_algorithm.cpp
    
QMAKE_CXXFLAGS += -std=c++0x
QT += widgets
QT += xml

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

FORMS += \
    mainwindow.ui
