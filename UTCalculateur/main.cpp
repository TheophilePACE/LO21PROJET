#include <stdio.h>

#include "numeric.h"
#include "integer.h"
#include "rationnal.h"
#include "real.h"
#include "complex.h"

int main ()
{
    Expression E1;
    Numeric N1(5), N2(6);
    Integer I1(56), I2(67);
    Rationnal F1(45,56);
    Rationnal F2(I1,I2);
    Numeric N3;
    N3= N1+N2;
    Real R1(10,0);
    Real R2(-1.5);
    Rationnal Rslt(1,1);
    F2=I1*F1;
    std::cout<<F1.toString()<<"+"<<R1.toString()<<"=";
    //Rslt =(F1+I1) ;
    std::cout<<F2.toString()<<"\n";

    return 0;

}
