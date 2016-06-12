#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litteral.h"

/*! \brief Cette classe représente les instructions telles que décrites dans le sujet: suite d'instructions pouvant être empilées et évaluées.
 * Une expression permet d'écrire des calculs en notation classique (par opposition à la notation polonaise inversée)
* Une expression est une suite de caractères entourés par deux guillemets : 'expression'. */
class Expression : public Litteral {
    ///L'expression entrée par l'utilisateur. Elle n'est pas interprétée à la construction.
    QString instructions;
public:
    Expression(QString s): instructions(s){}
    std::string toString()const;
    QString toQStringPars()const;
    void setInstructions(QString s){instructions = s;}
    void print(QTextStream& f)const;
};

#endif // EXPRESSION_H
