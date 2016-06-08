#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litteral.h"

class ExpressionMaterial : public Litteral {
public:
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual std::string toStringPars()const=0;
    virtual ~ExpressionMaterial(){}
};

class Expression : public Litteral {
    std::string instructions;
   /* ExpressionMaterial ** tab;
    unsigned int nb;
    unsigned int max;*/
public:
    Expression(std::string s): instructions(s){}
    /*Expression(): tab(nullptr), nb(0),max(0){}
    ~Expression(){nb = 0; max = 0; delete[] tab;}
    void increaseCap();
    void operator<<(ExpressionMaterial* e);*/
    std::string toString()const;
    std::string toStringPars()const;
    void setInstructions(std::string s){instructions = s;}
    void print(QTextStream& f)const;
};

#endif // EXPRESSION_H
