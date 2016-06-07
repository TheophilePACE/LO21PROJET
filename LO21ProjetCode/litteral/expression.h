#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litteral.h"

class ExpressionMaterial : public Litteral {
public:
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual QString toQStringPars()const=0;
    virtual ~ExpressionMaterial(){}
};

class Expression : public Litteral {
    QString instructions;
public:
    Expression(QString s): instructions(s){}
    std::string toString()const;
    QString toQStringPars()const;
    void setInstructions(QString s){instructions = s;}
    void print(QTextStream& f)const;
};

#endif // EXPRESSION_H
