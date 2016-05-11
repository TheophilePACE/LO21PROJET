QT +=widgets

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

SOURCES += \
    main.cpp \
    computer.cpp \
    qcomputer.cpp

HEADERS += \
    qcomputer.h \
    computer.h
