#ifndef ATOM_H
#define ATOM_H

#include "expression.h"

class Atom : public ExpressionMaterial {
    std::string lib;
public:
    Atom(std::string& s):lib(s){}
    void print(QTextStream& f) const {f<<toQString(lib);}
    std::string toString()const{return lib;}
    ~Atom(){}
};

#endif // ATOM_H
