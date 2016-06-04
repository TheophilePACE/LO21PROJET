#include "numeric.h"
#include "real.h"
#include "rationnal.h"
#include "complex.h"

int main(int argc, char* argv[]) {
    double de =10.5 ;
    Real *N1= new Real    ( de );
    Rationnal *N2= new Rationnal(1,3);
    std::cout<<typeid((*N2).getSignedValue() + N1->getSignedValue()).name()<<"    "<<typeid(*N2).name() ;

    std::cout<< (*N2).getSignedValue()<<"    "<<typeid(*N2).name() ;

    //Numeric N3 = *N1 + *N2;
    //Complex C1(R1,I1);
    std::cout<<typeid(*N2).name() ;
    return 0;
}
