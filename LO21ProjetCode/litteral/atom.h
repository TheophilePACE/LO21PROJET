#ifndef ATOM_H
#define ATOM_H

#include "expression.h"

class Atom : public ExpressionMaterial {
    std::string lib;
public:
    Atom(std::string s):lib(s){}
    void print(QTextStream& f) const {f<<toQString(lib);}
    std::string toString()const{return lib;}
    std::string toStringPars()const{return toString();}
    ~Atom(){}
};

#endif // ATOM_H
