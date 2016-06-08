#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litteral.h"

class Expression : public Litteral { ///Cette classe représente les instructions telles que décrites dans le sujet: suite d'instructions pouvant être empilées et évaluées. Une expression doit pouvoir renvoyer une valeur de type numérique ou complexe.
    QString instructions;
public:
    Expression(QString s): instructions(s){}
    std::string toString()const;
    QString toQStringPars()const;
    void setInstructions(QString s){instructions = s;}
    void print(QTextStream& f)const;
};

#endif // EXPRESSION_H
