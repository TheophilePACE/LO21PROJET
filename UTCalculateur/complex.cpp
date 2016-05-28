#include "complex.h"

void Complex::print(QTextStream& f)const
{
    pReal->print(f);
    f<<" + ";
    pImag->print(f);
    f<<"i";
}
std::string Complex::toString()const
{
    return (*pReal).toString()+  " + "   + (*pImag).toString() + "i";
}
