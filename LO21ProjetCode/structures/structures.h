#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QSound>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QApplication>
#include "litteral/litteral.h"
#include "litteral/integer.h"
#include "litteral/real.h"
#include "litteral/program.h"
#include "generalManager.h"
#include "stack.h"

/*Fichier contenant les structures de controle*/

class ComputerException {
    QString info;
public:
    ComputerException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

class Controller {
    GeneralManager& genMng;
    Stack * stack;
public:
    Controller(GeneralManager& m,Stack * p):genMng(m), stack(p){}
    void command(const QString& c);
    void setStack(Stack * s) { /*delete stack*/ stack = s;}

};

#endif // STRUCTURES_H
