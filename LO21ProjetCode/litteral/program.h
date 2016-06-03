#ifndef PROGRAM_H
#define PROGRAM_H

#include "litteral.h"

class Program : public Litteral {
    std::string instructions;
public:
    Program(std::string s):instructions(s){}
    void print(QTextStream& f)const;
    std::string toString()const{return instructions;}
    std::string toStringPars()const{return toString();}
};

#endif // PROGRAM_H
