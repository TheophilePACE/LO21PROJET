HEADERS += \
    litteral.h \
    qmain.h \
    structures.h \
    intermediary.h

SOURCES += \
    litteral.cpp \
    main.cpp \
    qmain.cpp \
    structures.cpp \
    intermediary.cpp
    
QMAKE_CXXFLAGS += -std=c++0x
QT += widgets
