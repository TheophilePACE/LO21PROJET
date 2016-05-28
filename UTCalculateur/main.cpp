#include <stdio.h>

#include "numeric.h"
#include "integer.h"
#include "rationnal.h"
#include "real.h"
#include "complex.h"

int main ()
{
    //Numeric N1(5), N2(6);
    Integer I1(56), I2(67);
    Rationnal F1(45,56);
    Rationnal F2(I1,I2);
    //Numeric N3;
    //N3= N1+N2;
    Real R1(10,0);
    Real R2(-1.5);
    Rationnal Rslt(1,1);
    F2=I1*F1;
    Complex C1(&F1,&R2), C2(&I1,&F2);
    std::cout<<F1.toString()<<"  "<<R2.toString()<<"  "<<I1.toString()<<"  "<<F2.toString()<<"\n";
    std::cout<<C1.toString()<<"     "<<C2.toString();

    return 0;

}
