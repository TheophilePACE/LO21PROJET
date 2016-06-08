#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litteral.h"

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
