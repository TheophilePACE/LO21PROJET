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
bool isOperator(const QString s);
bool isRationnal(const QString s);
bool isReal(const QString s);
bool isInteger(const QString s);
bool isNumber(const QString s);
bool isComplex(const QString s);
bool isAtom(const QString s);
bool isExpression(const QString s);
unsigned int pgcd(int a, int b);

class Litteral {
public:
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual std::string toStringPars()const=0;
    virtual ~Litteral(){}
};

#endif // LITTERAL_H
