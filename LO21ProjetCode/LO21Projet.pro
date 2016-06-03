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
<<<<<<< HEAD
    structures/operator.h
=======
    qvareditor.h \
    qprogrameditor.h
>>>>>>> deca6fb9cd34a36c6f81d7f3bab2e3af8b841c4c

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
<<<<<<< HEAD
    structures/operator.cpp
=======
    qvareditor.cpp \
    qprogrameditor.cpp
>>>>>>> deca6fb9cd34a36c6f81d7f3bab2e3af8b841c4c
    
QMAKE_CXXFLAGS += -std=c++0x
QT += widgets
QT += xml

FORMS += \
    mainwindow.ui
