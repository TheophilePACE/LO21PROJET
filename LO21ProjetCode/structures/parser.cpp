#include "parser.h"

Parser::Singleton Parser::sing=Parser::Singleton();
Parser& Parser::getInstance(){
    if(sing.instance==nullptr) sing.instance = new Parser;
    return *sing.instance;
}
bool Parser::isOperator(QString s) {
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    return false;
}

std::string Parser::getType(QString s)
{
    if(isInteger(s))
        return "Integer";
    if(isRationnal(s))
        return "Rationnal";
    if(isReal(s))
        return "Real";
    if(isComplex(s))
        return "Complex";
    throw "Type inconnu !!";

}
long Parser::getNum(QString s){
    long ln =s.split('/').first().toLong();
    return ln;
}
long Parser::getDenum(QString s){
    long ln= (s.split('/').at(1).toLong());
    return ln;
}
long Parser::getInteger(QString s){
     long ln =(s.split('.').first().toLong());
    return ln;
}
double Parser::getMantisse(QString s){
    return s.split('.').at(1).toDouble();
}


Integer Parser::getRealPart(QString s){
    Integer I(s.split('$').first().toLong());
    return I;
}
Integer Parser::getImPart(QString s){
     Integer I( s.split('$').at(1).toLong());
     return I;
}

