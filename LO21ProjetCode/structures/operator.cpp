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

Litteral* OperatorSum::execute(Stack *s)
{
    if(typeid(*l1)==typeid(Complex)||typeid(*l2)==typeid(Complex))
    {
        //Rslt = new Complex();

    }
    else //2 numeriques
    {
        Numeric* N1 =dynamic_cast<Numeric*>(l1);
        Numeric* N2 =dynamic_cast<Numeric*>(l2);
        numericCast(&N1);
        numericCast(&N2);


        Item* I3 = new Item();
        Numeric* N= new Numeric();
        *N=(*N1) + (*N2);
        numericCast(&N);

        s->push(*I3);
        return N;

    }




}
