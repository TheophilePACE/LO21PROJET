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

void OperatorUnary::loadOperand(Stack * s) {
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
Litteral*  OperatorDivision::execute()
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

Litteral*  OperatorDiv::execute()
{
        Integer* I1 =dynamic_cast<Integer*>(l1);
        Integer* I2 =dynamic_cast<Integer*>(l2);
        Integer* Rslt = new Integer();
        *Rslt =(*I1).DIV(*I2);
        return Rslt;
}
void OperatorDiv::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if(typeid(*l1)!=typeid(Integer)||typeid(*l2)!=typeid(Integer))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 entiers pour Div";
    }
}

Litteral*  OperatorMod::execute()
{
        Integer* I1 =dynamic_cast<Integer*>(l1);
        Integer* I2 =dynamic_cast<Integer*>(l2);
        Integer* Rslt = new Integer();
        *Rslt =(*I1).MOD(*I2);
        return Rslt;
}
void OperatorMod::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if(typeid(*l1)!=typeid(Integer)||typeid(*l2)!=typeid(Integer))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 entiers pour Mod";
    }
}


Litteral*  OperatorSupS::execute()
{
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Numeric* I2 =dynamic_cast<Numeric*>(l2);
        if((I1->getVal())>(I2->getVal())){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;
}
void OperatorSupS::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!dynamic_cast<Numeric*>(l1))||(!dynamic_cast<Numeric*>(l2))) //L1 ou L2 n'est pas convertible en numcad pointe vers complx  ou autre type non numerique
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numerique pour >";
    }
}

Litteral*  OperatorSupE::execute()
{
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Numeric* I2 =dynamic_cast<Numeric*>(l2);
        if((I1->getVal())>=(I2->getVal())){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;
}
void OperatorSupE::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!dynamic_cast<Numeric*>(l1))||(!dynamic_cast<Numeric*>(l2))) //L1 ou L2 n'est pas convertible en numcad pointe vers complx  ou autre type non numerique
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numerique pour >=";
    }
}

Litteral*  OperatorLessS::execute()
{
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Numeric* I2 =dynamic_cast<Numeric*>(l2);
        if((I1->getVal())<(I2->getVal())){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;
}
void OperatorLessS::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!dynamic_cast<Numeric*>(l1))||(!dynamic_cast<Numeric*>(l2))) //L1 ou L2 n'est pas convertible en numcad pointe vers complx  ou autre type non numerique
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numerique pour <";
    }
}

Litteral*  OperatorLessE::execute()
{
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Numeric* I2 =dynamic_cast<Numeric*>(l2);
        if((I1->getVal())<=(I2->getVal())){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;}
void OperatorLessE::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!dynamic_cast<Numeric*>(l1))||(!dynamic_cast<Numeric*>(l2))) //L1 ou L2 n'est pas convertible en numcad pointe vers complx  ou autre type non numerique
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numerique pour <=";
    }
}

Litteral*  OperatorEqu::execute()
{
    if((dynamic_cast<Numeric*>(l1))&&(dynamic_cast<Numeric*>(l2))){
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Numeric* I2 =dynamic_cast<Numeric*>(l2);
        if((*I1)==(*I2)){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;}
    else{ //2 complexe
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex* C2 =dynamic_cast<Complex*>(l2);
        if((*C1)==(*C2)){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;}
}

void OperatorEqu::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if(!(((dynamic_cast<Numeric*>(l1))&&(dynamic_cast<Numeric*>(l2)))||((dynamic_cast<Complex*>(l1))&&(dynamic_cast<Complex*>(l2))))) //L1 ou L2 n'est pas convertible en numcad pointe vers complx  ou autre type non numerique
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numerique pour =";
    }
}


Litteral*  OperatorNEqu::execute()
{
    if((dynamic_cast<Numeric*>(l1))&&(dynamic_cast<Numeric*>(l2))){
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Numeric* I2 =dynamic_cast<Numeric*>(l2);
        if(!((*I1)==(*I2))){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;}
    else{ //2 complexe
        Complex* C1 =dynamic_cast<Complex*>(l1);
        Complex* C2 =dynamic_cast<Complex*>(l2);
        if(!((*C1)==(*C2))){
            Integer* Rslt = new Integer(1);
            return Rslt;
        }
        Integer* Rslt = new Integer(0);
        return Rslt;}
}
void OperatorNEqu::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if(!(((dynamic_cast<Numeric*>(l1))&&(dynamic_cast<Numeric*>(l2)))||((dynamic_cast<Complex*>(l1))&&(dynamic_cast<Complex*>(l2))))) //L1 ou L2 n'est pas convertible en numcad pointe vers complx  ou autre type non numerique
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numerique pour !=";
    }
}

Litteral*  OperatorCplx::execute()
{
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Numeric* I2 =dynamic_cast<Numeric*>(l2);

       Complex * Rslt = new Complex(I1,I2);

        return Rslt;
}
void OperatorCplx::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!dynamic_cast<Numeric*>(l1))||(!dynamic_cast<Numeric*>(l2))) //L1 ou L2 n'est pas convertible en numcad pointe vers complx  ou autre type non numerique
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numerique pour $";
    }
}

Litteral*  OperatorAND::execute()
{
        Integer* I1 =dynamic_cast<Integer*>(l1);
        Integer* I2 =dynamic_cast<Integer*>(l2);
        if(I1->getAbsoluteValue() * (I2->getAbsoluteValue()))
        {
            Integer* I = new Integer(1);
            return I;
        }
        Integer* I = new Integer(0);
        return I;
}
void OperatorAND::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if(typeid(*l1)!=typeid(Integer)||typeid(*l2)!=typeid(Integer))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 entiers pour Mod";
    }
}

Litteral*  OperatorOR::execute()
{
        Integer* I1 =dynamic_cast<Integer*>(l1);
        Integer* I2 =dynamic_cast<Integer*>(l2);
        if((I1->getAbsoluteValue())||(I2->getAbsoluteValue()))
        {
            Integer* I = new Integer(1);
            return I;
        }
        Integer* I = new Integer(0);
        return I;
}
void OperatorOR::loadOperand(Stack *s){
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if(typeid(*l1)!=typeid(Integer)||typeid(*l2)!=typeid(Integer))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 entiers pour OR";
    }
}

Litteral*  OperatorNOT::execute()
{
        Integer* I1 =dynamic_cast<Integer*>(l1);
        if(I1->getAbsoluteValue())
        {
            Integer* I = new Integer(0);
            return I;
        }
        Integer* I = new Integer(1);
        return I;
}
void OperatorNOT::loadOperand(Stack *s){
    l1=s->top();
    s->pop();
    if(typeid(*l1)!=typeid(Integer))
    {
        Item * I1 =new Item();
        I1->setLit(l1);
        s->push(*I1);
        throw "BAD TYPE: il faut un entier pour NOT";
    }
}

Litteral*  OperatorNEG::execute()
{
    if(dynamic_cast<Numeric*>(l1)){
        Numeric* I1 =dynamic_cast<Numeric*>(l1);
        Integer* Rslt = new Integer(0);
        //(*Rslt)= I1->NEG();
        return Rslt;}
    //complexe
    Complex * C1 = dynamic_cast<Complex *>(l1);
    Complex * Rslt = new Complex();
    *Rslt = C1->NEG();
    return Rslt;

}
void OperatorNEG::loadOperand(Stack *s){
    l1=s->top();
    s->pop();
    if(!(dynamic_cast<Numeric*>(l1)||dynamic_cast<Complex*>(l1)))
    {
        Item * I1 =new Item();
        I1->setLit(l1);
        s->push(*I1);
        throw "BAD TYPE: il faut un numerique ou un complex pour NEG";
    }
}
