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
    if (s=="<") return true;
    if (s==">") return true;
    if (s=="=") return true;
    if (s=="<=") return true;
    if (s==">=") return true;
    if (s=="!=") return true;
    if (s=="=") return true;
    if (s=="DIV") return true;
    if (s=="MOD") return true;
    if (s=="$") return true;
    if (s=="AND") return true;
    if (s=="OR") return true;
    return false;
}

bool Parser::isOperatorUnary(QString s) {
    if (s=="NOT") return true;
    if (s=="NEG") return true;
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
    if(isAtom(s))
        return "Atom";
    if(isExpression(s))
        return "Expression";
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


QString Parser::getRealPart(QString s){

    return  (s.split('$').first());
}
QString Parser::getImPart(QString s){

     return (s.split('$').at(1));
}

