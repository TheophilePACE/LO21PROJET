#include "operator.h"
#include "stack.h"
#include "litteral/complex.h"
#include "litteral.h"


void OperatorBinary::loadOperand(Stack *s) {
l1=s->top();
s->pop();

l2=s->top();
s->pop();
}

void OperatorUnaire::loadOperand(Stack * s) {
    l1=s->top();
    s->pop();
}

Litteral* OperatorSum::execute()
{
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex* C2 =dynamic_cast<Complex*>(l2);
        Complex* C= new Complex();
        *C=(*C1) + (*C2);
        return C;

    }
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)!=typeid(Complex)) // NotComplex = numeric et classes filles
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex C2(dynamic_cast<Numeric*>(l2),nullptr);
        Numeric* N1 = new Numeric();
        Numeric * N2 = new Numeric() ;
        Complex* C= new Complex(N1,N2);
        *C=(*C1) + (C2);

        return C;

    }
    if(typeid(*l1)!=typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C1 =dynamic_cast<Complex*>(l2);
        Complex C2(dynamic_cast<Numeric*>(l1),nullptr);
        Numeric* N1 = new Numeric();
        Numeric * N2 = new Numeric() ;
        Complex* C= new Complex(N1,N2);
        *C=(*C1) + (C2);

        return C;


    }
    else //Pointeurs sur classe filles de numeric. bcp de possibilités.
    {
        Numeric* N1 =dynamic_cast<Numeric*>(l1);
        Numeric* N2 =dynamic_cast<Numeric*>(l2);
        Numeric* N= new Numeric();
        *N=(*N1) + (*N2);
        numericCast(&N);
        return N;

    }




}
