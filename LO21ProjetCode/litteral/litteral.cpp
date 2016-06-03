#include "litteral.h"
#include <QString>
#include <sstream>
#include <QRegExp>

//Functions

QString toQString(std::string s) {
    return QString::fromStdString(s);
}

std::string doubleToString(double f) {
   std::ostringstream ost;
   ost<<f;
   return ost.str();

}

bool isOperator(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    if (s=="NEG") return true;
    return false;
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
bool isNumber(const QString s){
   bool ok=false;
   s.toInt(&ok);
   return ok;
}

//Math Functions
unsigned int pgcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
