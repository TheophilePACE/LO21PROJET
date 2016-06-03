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
    structures/programManager.h \
    structures/identifierManager.h \
    structures/generalManager.h \
    structures/operator.h

SOURCES += \
    main.cpp \
    qmain.cpp \
    intermediary.cpp \
    mainwindow.cpp \
    litteral/litteral.cpp \
    litteral/atom.cpp \
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
    structures/programManager.cpp \
    structures/identifierManager.cpp \
    structures/generalManager.cpp \
    structures/operator.cpp
    
QMAKE_CXXFLAGS += -std=c++0x
QT += widgets

FORMS += \
    mainwindow.ui
