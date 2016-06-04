#include "expression.h"
#include <sstream>
/*
void Expression::increaseCap()
{
    max = max*2+1;
    ExpressionMaterial ** newtab = new ExpressionMaterial*[max];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=tab[i];
    ExpressionMaterial ** old = tab;
    tab = newtab;
    delete[] old;
}

void Expression::operator<<(ExpressionMaterial* e)
{
    if(nb==max)
       increaseCap();
    tab[nb++]=e;
}

std::string Expression::toString()const {
    std::stringstream f;
    for(unsigned int i=0;i<nb;i++){
        f<<(*tab[i]).toString();
        f<<" ";
    }
    return  f.str();
}
void Expression::print(QTextStream& f)const{
    f<<toQString(toString());
}

*/
std::string Expression::toString()const {
    return  instructions;
}
std::string Expression::toStringPars()const {
    return toString();
}
void Expression::print(QTextStream& f)const{
    f<<toQString(instructions);
}
