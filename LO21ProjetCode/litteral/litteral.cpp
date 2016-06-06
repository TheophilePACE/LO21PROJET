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
