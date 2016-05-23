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
Integer Parser::getNum(QString s){
    return Integer(s.split('/').first().toInt());
}
Integer Parser::getDenum(QString s){
    return Integer(s.split('/').at(1).toInt());
}
Integer Parser::getInteger(QString s){
    return Integer(s.split('.').first().toInt());
}
float Parser::getMantisse(QString s){
    return s.split('.').at(1).toFloat();
}


Integer Parser::getRealPart(QString s){
    return Integer(s.split('$').first().toInt());
}
Integer Parser::getImPart(QString s){
    return Integer(s.split('$').at(1).toInt());
}

