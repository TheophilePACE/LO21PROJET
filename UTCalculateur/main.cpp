#include "numeric.h"
#include "real.h"
#include "rationnal.h"
#include "complex.h"

int main(int argc, char* argv[]) {
    double de =10.5 ;
    Numeric *N1= new Numeric    ( de );
    Numeric *N2= new Numeric();
    std::cout<< N1->getMantisse()<<"    "<<typeid(*N2).name() ;

    numericCast(&N1);
    numericCast(&N2);
    double a,b,c,d;
    a = 10.5;
    b = -10;
    c= a- trunc(a);
    d= b-trunc(b);

    //Complex C1(R1,I1);
    std::cout<< N1->getMantisse()<<"    "<<typeid(*N2).name() ;
    std::cout<<"\n"<<c<<"    "<<d ;
    return 0;
}
