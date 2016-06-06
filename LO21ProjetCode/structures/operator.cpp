#include "operator.h"

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
void OperatorSum::loadOperand(Stack *s)
{
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!(typeid(*l1)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l1)))||(!(typeid(*l2)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l2))))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numeriques ou complexe pour +";
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
        *C= C1 - (*C2);
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
void OperatorSub::loadOperand(Stack *s)
{
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!(typeid(*l1)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l1)))||(!(typeid(*l2)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l2))))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numeriques ou complexe pour -";
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
void OperatorMul::loadOperand(Stack *s){
l2=s->top();
s->pop();

l1=s->top();
s->pop();
if((!(typeid(*l1)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l1)))||(!(typeid(*l2)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l2))))
{
    Item * I1 =new Item();
    Item * I2 =new Item();
    I1->setLit(l1);
    I2->setLit(l2);
    s->push(*I1);
    s->push(*I2);
    throw "BAD TYPE: il faut 2 Numeriques ou complexe pour *";
}}

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
        Integer I1(0);
        Complex C2(dynamic_cast<Numeric*>(l2),&I1);
        if(C2.isImag()) // càd nul
        {
            throw  ("Impossible de diviser par une valeur nulle !");
             Integer * I = new Integer(0);
             return I;
        }
        Complex* C= new Complex();
        *C= ((*C1) / (C2));
        return C;
    }
    if(typeid(*l1)!=typeid(Complex)&&typeid(*l2)==typeid(Complex))
    {
        Complex* C2 =dynamic_cast<Complex*>(l2);
        Integer I1(0);
        Complex C1(dynamic_cast<Numeric*>(l1),&I1);
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
void OperatorDivision::loadOperand(Stack *s) {
    l2=s->top();
    s->pop();

    l1=s->top();
    s->pop();
    if((!(typeid(*l1)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l1)))||(!(typeid(*l2)==typeid(Complex))&&(!dynamic_cast<Numeric*>(l2))))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "BAD TYPE: il faut 2 Numeriques ou complexe pour /";
    }
    if(((dynamic_cast<Numeric*>(l2))&&dynamic_cast<Numeric*>(l2)->isNull())||((dynamic_cast<Complex*>(l2))&&(dynamic_cast<Complex*>(l2)->isImag()&&dynamic_cast<Complex*>(l2)->isReal())))
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "Impossible de / par 0";
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
    if(dynamic_cast<Numeric*>(l2)->isNull())
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "DIV par 0";
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
    if(dynamic_cast<Numeric*>(l2)->isNull())
    {
        Item * I1 =new Item();
        Item * I2 =new Item();
        I1->setLit(l1);
        I2->setLit(l2);
        s->push(*I1);
        s->push(*I2);
        throw "MOD par 0";
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
        Numeric* Rslt = new Numeric();
        (*Rslt) = (dynamic_cast<Numeric*>(l1))->NEG();
        numericCast(&Rslt);
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

void OperatorSTO::loadOperand(Stack *s){
    l1=s->top();
    s->pop();

    //Litteral* I1 =dynamic_cast<Litteral*>(l1);
    Item * I = new Item;
    I->setLit(l1);
    l2=s->top();
    s->push(*I);
    s->setMessage("Variable Affectée");
}
Litteral * OperatorSTO::execute(){
    Litteral* I1 =dynamic_cast<Litteral*>(l1);
    Expression* I2 =dynamic_cast<Expression*>(l2);
    if(!(I2))
        throw"Problème de type pour le STO!";

    QString str = toQString(I2->toString());
    str.remove(0,1);
    str.remove(str.size()-1,1);

    IdentifierManager * idMng = &(IdentifierManager::getInstance());
    IdentifierManager::Iterator it = idMng->getIterator();
    unsigned int NbElements =0;
    Parser p = Parser::getInstance();

    if(p.getType(str) != "Atom")
        throw "Type Error of the identifier";
    while(!it.isDone() &&
          it.getCurrent().getLib()->toString()!=str.toStdString())
    {
        it.next(); ++NbElements;
    }
    std::string type = p.getType(toQString(I1->toString()));
    if(type!="Atom" && type !="Program")
        if(NbElements!=idMng->size())
            if(typeid(*(it.getCurrent().getPValue()))!=typeid(Program))
                it.getCurrent().setValue(I1);
            else
                throw "Modification d'un' Programme Impossible avec STO";
        else
            idMng->addIdentifier(str.toStdString(),I1);
    else
        throw "Type Error Creation Var";
    return l1;
}

Litteral*  OperatorNUM::execute()
{

    Numeric * N1 = dynamic_cast<Numeric *>(l1);
    Integer* Rslt = new Integer(N1->getNum());
    return Rslt;

}
void OperatorNUM::loadOperand(Stack *s){
    l1=s->top();
    s->pop();
    if(!(dynamic_cast<Integer*>(l1)||dynamic_cast<Rationnal*>(l1)))
    {
        Item * I1 =new Item();
        I1->setLit(l1);
        s->push(*I1);
        throw "BAD TYPE: il faut un rationnel ou un entier pour NUM";
    }
}

Litteral*  OperatorDEN::execute()
{

    Numeric * N1 = dynamic_cast<Numeric *>(l1);
    Integer* Rslt = new Integer(N1->getDenum());
    return Rslt;

}
void OperatorDEN::loadOperand(Stack *s){
    l1=s->top();
    s->pop();
    if(!(dynamic_cast<Integer*>(l1)||dynamic_cast<Rationnal*>(l1)))
    {
        Item * I1 =new Item();
        I1->setLit(l1);
        s->push(*I1);
        throw "BAD TYPE: il faut un rationnel ou un entier pour DEN";
    }
}

Litteral*  OperatorRE::execute()
{
    if(dynamic_cast<Numeric*>(l1)){
        return l1;
    }
    Complex * C1 = dynamic_cast<Complex *>(l1);
    Numeric* Rslt = new Numeric(C1->getReal());
    numericCast(&Rslt);
    return Rslt;

}
void OperatorRE::loadOperand(Stack *s){
    l1=s->top();
    s->pop();
    if(!(dynamic_cast<Numeric*>(l1)||dynamic_cast<Complex*>(l1)))
    {
        Item * I1 =new Item();
        I1->setLit(l1);
        s->push(*I1);
        throw "BAD TYPE: il faut un numerique ou un complx pour RE";
    }
}

Litteral*  OperatorIM::execute()
{
    if(dynamic_cast<Numeric*>(l1)){
        Numeric* Rslt = new Integer(0);
        return Rslt;
    }
    Complex * C1 = dynamic_cast<Complex *>(l1);
    Numeric* Rslt = new Numeric(C1->getImag());
    numericCast(&Rslt);
    return Rslt;

}
void OperatorIM::loadOperand(Stack *s){
    l1=s->top();
    s->pop();
    if(!(dynamic_cast<Numeric*>(l1)||dynamic_cast<Complex*>(l1)))
    {
        Item * I1 =new Item();
        I1->setLit(l1);
        s->push(*I1);
        throw "BAD TYPE: il faut un numerique ou un complx pour IM";
    }
}
void OperatorEVAL::loadOperand(Stack *s){
    l1=s->top();
    //s->pop();
}
Litteral * OperatorEVAL::execute(){
    Parser p = Parser::getInstance();
    Expression * exp = dynamic_cast<Expression *>(l1);
    QString str = toQString(exp->toString());
    str.remove(0,1);
    str.remove(str.size()-1,1);
    std::vector<std::string> vect;
    bool number = false;
    int i=0,j=0;
    QString temp ="";
    while(i<str.size()) {
        if(i==(str.size()-1)){
            if(number) {
                vect.insert(vect.begin()+j,temp.toStdString());
                vect.insert(vect.begin()+(++j),std::string(1,str.toStdString().at(i)));
            }
            else
            vect.insert(vect.begin()+j,std::string(1,str.toStdString().at(i)));
        }
        else if ((number) &&
                ((str.at(i)=='(')||(str.at(i)==')')||
                 p.isOperator(QString(str.at(i))))) {
            number = false;
            vect.insert(vect.begin()+j,temp.toStdString());
            vect.insert(vect.begin()+(++j),std::string(1,str.toStdString().at(i)));
            temp = "";
            j++;
        }
        else if(((str.at(i)=='(')||(str.at(i)==')')||
                 p.isOperator(QString(str.at(i))))
                &&(!number)) {
            vect.insert(vect.begin()+j,std::string(1,str.toStdString().at(i)));
            j++;
        }
        else {
            number = true;
            temp = temp + toQString(std::string(1,str.toStdString().at(i)));
        }
        i++;
    }
    temp = "";
    int size = vect.size();
    std::vector<std::string> strArray;
    infixToRPN(vect,size,strArray);
    //for(unsigned int i=0;i<strArray.size();i++)
    //    temp = temp + toQString(strArray[i]);
    std::cout << temp.toStdString();
    ctrl->command(temp);
    return nullptr;
}


