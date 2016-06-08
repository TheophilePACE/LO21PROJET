#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "litteral.h"

///Cette classe représente les instructions telles que décrites dans le sujet: suite d'instructions pouvant être empilées et évaluées. Une expression doit pouvoir renvoyer une valeur de type numérique ou complexe.
/// Une expression est donc une suite de caractères entourée par deux guillemets : 'expression'.
class Expression : public Litteral {
    ///L'expression tapée par l'utilisateur. Elle n'est pas interprétée pour l'instant.
    QString instructions;
public:
    Expression(QString s): instructions(s){}
    std::string toString()const;
    QString toQStringPars()const;
    void setInstructions(QString s){instructions = s;}
    void print(QTextStream& f)const;
};

#endif // EXPRESSION_H
