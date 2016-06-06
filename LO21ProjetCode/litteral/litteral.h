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
#include "../structures/generalManager.h"

QString toQString(std::string s);
std::string doubleToString(double f);
unsigned int pgcd(int a, int b);


class Litteral {
public:
    Litteral(){GeneralManager::getInstance().addLitteral(this);}
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual std::string toStringPars()const=0;
    virtual ~Litteral(){}
};

#endif // LITTERAL_H
