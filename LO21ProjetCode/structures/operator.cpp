#include "operator.h"
#include "stack.h"
#include "../litteral/complex.h"
#include "../litteral/litteral.h"


void OperatorBinary::loadOperand(Stack *s) {
l2=s->top();
s->pop();

l1=s->top();
s->pop();
}

void OperatorUnaire::loadOperand(Stack * s) {
    l1=s->top();
    s->pop();
}


//Somme
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

Litteral* OperatorSub::execute()
{
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex* C2 =dynamic_cast<Complex*>(l2);
        Complex* C= new Complex();
        *C=(*C1) - (*C2);
        return C;
    }
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)!=typeid(Complex)) // NotComplex = numeric et classes filles
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex C2(dynamic_cast<Numeric*>(l2),nullptr);
        Complex* C= new Complex();
        *C=(*C1) - (C2);
        return C;
    }
    if(typeid(*l1)!=typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex C1 =(dynamic_cast<Numeric*>(l1),nullptr);
        Complex* C2 =dynamic_cast<Complex*>(l2);
        Complex* C= new Complex();
        *C=C1 - (*C2);
        return C;
    }
    else //Pointeurs sur classe filles de numeric. bcp de possibilités.
    {
        Numeric* N1 =dynamic_cast<Numeric*>(l1);
        Numeric* N2 =dynamic_cast<Numeric*>(l2);
        Numeric* N= new Numeric();
        *N=(*N1) - (*N2);
        numericCast(&N);
        return N;
    }
}

Litteral* OperatorMul::execute()
{
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex* C2 =dynamic_cast<Complex*>(l2);
        Complex* C= new Complex();
        *C=(*C1) * (*C2);
        return C;
    }
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)!=typeid(Complex)) // NotComplex = numeric et classes filles
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex C2(dynamic_cast<Numeric*>(l2),nullptr);
        Numeric* N1 = new Numeric();
        Numeric * N2 = new Numeric() ;
        Complex* C= new Complex(N1,N2);
        *C=(*C1) * (C2);
        return C;
    }
    if(typeid(*l1)!=typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C1 =dynamic_cast<Complex*>(l2);
        Complex C2(dynamic_cast<Numeric*>(l1),nullptr);
        Numeric* N1 = new Numeric();
        Numeric * N2 = new Numeric() ;
        Complex* C= new Complex(N1,N2);
        *C=(*C1) * (C2);
        return C;
    }
    else //Pointeurs sur classe filles de numeric. bcp de possibilités.
    {
        Numeric* N1 =dynamic_cast<Numeric*>(l1);
        Numeric* N2 =dynamic_cast<Numeric*>(l2);
        Numeric* N= new Numeric();
        *N=(*N1) * (*N2);
        numericCast(&N);
        return N;
    }
}

Litteral* OperatorDiv::execute()
{
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex* C2 =dynamic_cast<Complex*>(l2);


        if((C2->isImag())&&C2->isReal()) // càd nul
        {
            throw ("Impossible de diviser par une valeur nulle !");
             Integer * I = new Integer(0);
             return I;
        }


        Complex* C= new Complex();
        *C=(*C1) / (*C2);
        return C;
    }
    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)!=typeid(Complex)) // NotComplex = numeric et classes filles
    {
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex C2(dynamic_cast<Numeric*>(l2),nullptr);
        if(C2.isImag()) // càd nul
        {
            throw  ("Impossible de diviser par une valeur nulle !");
             Integer * I = new Integer(0);
             return I;
        }
        Complex* C= new Complex();
        *C=(*C1) / (C2);
        return C;
    }
    if(typeid(*l1)!=typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C2 =dynamic_cast<Complex*>(l2);
        Complex C1(dynamic_cast<Numeric*>(l1),nullptr);
        if((C2->isImag())&&C2->isReal()) // càd nul
        {
            throw  ("Impossible de diviser par une valeur nulle !");
             Integer * I = new Integer(0);
             return I;
        }
        Complex* C= new Complex();
        *C=(C1) / (*C2);
        return C;
    }
    else //Pointeurs sur classe filles de numeric. bcp de possibilités.
    {
        Numeric* N1 =dynamic_cast<Numeric*>(l1);
        Numeric* N2 =dynamic_cast<Numeric*>(l2);
        if(N2->isNull()) // càd nul
        {
            throw  ("Impossible de diviser par une valeur nulle !");
             Integer * I = new Integer(0);
             return I;
        }
        Numeric* N= new Numeric();
        *N=(*N1) / (*N2);
        numericCast(&N);
        return N;
    }

}

//Litteral* OperatorSub::execute()
//{
//    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)==typeid(Complex))
//    {
//        Complex* C1 =dynamic_cast<Complex*>(l1);
//        Complex* C2 =dynamic_cast<Complex*>(l2);
//        Complex* C= new Complex();
//        *C=(*C1) - (*C2);
//        return C;

//    }
//    if(typeid(*l1)==typeid(Complex)&&typeid(*l2)!=typeid(Complex)) // NotComplex = numeric et classes filles
//    {
//        Complex* C1 =dynamic_cast<Complex*>(l1);
//        Complex C2(dynamic_cast<Numeric*>(l2),nullptr);
//        Numeric* N1 = new Numeric();
//        Numeric * N2 = new Numeric() ;
//        Complex* C= new Complex(N1,N2);
//        *C=(*C1) - (C2);
//        return C;

//    }
//    if(typeid(*l1)!=typeid(Complex)&&typeid(*l2)==typeid(Complex))
//    {
//        Complex* C1 =dynamic_cast<Complex*>(l2);
//        Complex C2(dynamic_cast<Numeric*>(l1),nullptr);
//        Numeric* N1 = new Numeric();
//        Numeric * N2 = new Numeric() ;
//        Complex* C= new Complex(N1,N2);
//        *C=(*C1) - (C2);
//        return C;
//    }
//    else //Pointeurs sur classe filles de numeric. bcp de possibilités.
//    {
//        Numeric* N1 =dynamic_cast<Numeric*>(l1);
//        Numeric* N2 =dynamic_cast<Numeric*>(l2);
//        Numeric* N= new Numeric();
//        *N=(*N1) - (*N2);
//        numericCast(&N);
//        return N;
//    }
//}
