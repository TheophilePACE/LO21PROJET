#ifndef PROGRAM_H
#define PROGRAM_H

#include "litteral.h"

///Un programme est une suite de caractère entre deux crochets. Cette suite de caractère est interprétable par l'UTComputer.
/// Un programme est stocké sous forme de chaine de caractère et est interprété lors de son appel par l'utilisateur.
/// Il est crée et édité dans l'onglet programme de l'UTComputer.
class Program : public Litteral {
    ///Cette attribut stocke le 'code' du programme sous forme de QSTring. C'est donc un ensemble d'instructions qui sera interprété par l'UTComputer.
    QString instructions;
public:
    Program(QString s):instructions(s){}
    ~Program(){}
    void print(QTextStream& f)const;
    std::string toString()const{return instructions.toStdString();}
    ///Permet de donner le code du programme au Parser.
    QString toQStringPars()const{return instructions;}
};

#endif // PROGRAM_H
