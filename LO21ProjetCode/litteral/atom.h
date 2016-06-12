#ifndef ATOM_H
#define ATOM_H

#include "expression.h"
///Un atom sert à nommer un programme ou une variable. Il est toujours utilisé dans un identifier.
class Atom : public Litteral {
    QString lib;
public:
    Atom(QString s):lib(s){}
    void print(QTextStream& f) const {f<<lib;}
    std::string toString()const{return lib.toStdString();}
    QString toQStringPars()const{return lib;}
    ~Atom(){}
};

#endif // ATOM_H
