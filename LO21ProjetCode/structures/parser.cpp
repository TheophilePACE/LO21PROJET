#include "parser.h"

Parser::Singleton Parser::sing=Parser::Singleton();
Parser& Parser::getInstance(){
    if(sing.instance==nullptr) sing.instance = new Parser;
    return *sing.instance;
}
bool Parser::isOperator(const QString s){
    return isOperatorUnary(s)||isOperatorBinary(s);
}

bool Parser::isOperatorBinary(QString s) {
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
    if (s=="STO") return true;
    if (s=="SWAP") return true;
    return false;
}

bool Parser::isOperatorUnary(QString s) {
    if (s=="NOT") return true;
    if (s=="NEG") return true;
    if (s=="RE") return true;
    if (s=="IM") return true;
    if (s=="DEN") return true;
    if (s=="NUM") return true;
    if(s=="DROP") return true;
    if(s=="DUP") return true;
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
    if(isProgram(s))
        return "Program";
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
bool isRationnal(const QString s)
{
    QRegExp ratioExp ("[+-]?\\d+\\/[+-]?\\d+");
    return ratioExp.exactMatch(s);
}
bool isInteger(const QString s)
{
    QRegExp regExp ("[+-]?\\d+\\.?0*");
    return regExp.exactMatch(s);
}
bool isReal(const QString s)
{
    QRegExp regExp ("[+-]?\\d*\\.0*[1-9][0-9]*");
    return regExp.exactMatch(s);
}
bool isComplex(const QString s)
{
    QRegExp regExp ("[+-]?[0-9]*(\\.[0-9]*|\\/[+-]?[0-9]+)?\\$[+-]?[0-9]*(\\.[0-9]*|\\/[+-]?[0-9]+)?");
    return regExp.exactMatch(s);
}
bool isAtom(const QString s)
{
    QRegExp regExp ("[A-Z]([A-Z]|[0-9])*");
    return regExp.exactMatch(s);
}
bool isExpression(const QString s) //Pas fini
{
        QRegExp regExp ("^\\'.*\\'$");
        return regExp.exactMatch(s);
}
bool isProgram(const QString s) //Pas fini
{
        QRegExp regExp ("^\\[.*\\]$");
        return regExp.exactMatch(s);
}
bool isNumber(const QString s){
   bool ok=false;
   s.toInt(&ok);
   return ok;
}
