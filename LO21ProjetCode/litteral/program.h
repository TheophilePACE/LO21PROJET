#ifndef PROGRAM_H
#define PROGRAM_H

#include "litteral.h"

class Program : public Litteral {
    QString instructions;
public:
    Program(QString s):instructions(s){}
    ~Program(){}
    void print(QTextStream& f)const;
    std::string toString()const{return instructions.toStdString();}
    QString toQStringPars()const{return instructions;}
};

#endif // PROGRAM_H
