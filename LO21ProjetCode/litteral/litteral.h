#ifndef LITTERAL_H
#define LITTERAL_H

#include <string>
#include <iostream>
#include <stack>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <math.h>
#include <cmath>        // pour std::abs

QString toQString(std::string s);
std::string doubleToString(double f);
bool isRationnal(const QString s);
bool isReal(const QString s);
bool isInteger(const QString s);
bool isNumber(const QString s);
bool isComplex(const QString s);
bool isAtom(const QString s);
bool isExpression(const QString s);
bool isProgram(const QString s);
unsigned int pgcd(int a, int b);

class GeneralManager;

class Litteral {
public:
    //Litteral(){GeneralManager::getInstance().addIdentifier(this);}
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual std::string toStringPars()const=0;
    virtual ~Litteral(){}
};

#endif // LITTERAL_H
