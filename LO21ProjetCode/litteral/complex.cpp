#include "complex.h"

void Complex::print(QTextStream& f)const
{
    pReal->print(f);
    f<<" + ";
    pImag->print(f);
    f<<"i";
}
std::string Complex::toString()const {
    return (*pReal).toString() + " + " + (*pImag).toString() + "i";
}
std::string Complex::toStringPars()const {
    return (*pReal).toString() + "$" + (*pImag).toString();
}


//operatior entre complex. Pas besoin de gérer Complex/Num, fait par l'operator
Complex Complex::operator+(const Complex & Cx) const
{
    Numeric * N1 = new Numeric (0,1,0);
    *N1= (*pReal+ *(Cx.pReal));
    Numeric* N2 = new Numeric(0,1,0);
    *N2=((*pImag)+(*Cx.pImag));
    return Complex(N1,N2);
}
Complex Complex::operator-(const Complex & Cx) const
{
    Numeric * N1 = new Numeric (0,1,0);
    *N1= (*pReal - *(Cx.pReal));
    Numeric* N2 = new Numeric(0,1,0);
    *N2=((*pImag) - (*Cx.pImag));
    return Complex(N1,N2);
}
Complex Complex::operator*(const Complex & Cx) const
{ //voir regeles de calculs ;)
    Numeric * N1 = new Numeric (0,1,0);
    *N1= (*pReal * (*(Cx.pReal)))-( (*pImag) * (*Cx.pImag)) ;
    Numeric* N2 = new Numeric(0,1,0);
    *N2=((*pReal) * (*Cx.pImag)) + ((*Cx.pReal) * (*pImag));
    return Complex(N1,N2);
}
Complex Complex::operator/(const Complex& Cx) const
{
    Numeric * N1 = new Numeric (0,1,0);
    //grosse formule des familles merci wikipedia
    *N1= ((*pReal)*(*Cx.pReal) + ((*pImag) * (*Cx.pImag)))   /   ((*Cx.pReal) * (*Cx.pReal) + (*Cx.pImag) *(*Cx.pImag))  ;
    Numeric* N2 = new Numeric(0,1,0);
    *N2=((*Cx.pReal) *(*pImag) - (*pReal * (*Cx.pImag)))   /   ((*Cx.pReal) * (*Cx.pReal) + (*Cx.pImag) *(*Cx.pImag))   ;
    return Complex(N1,N2);
}



void numericCast(Numeric ** N)
{
    if((*N)->numIsInteger()) /*||(((*N)->getDenum()==0)&&((*N)->getMantisse()==0)))*/
        *N = new Integer((long)(*N)->getNum());
    else if((*N)->numIsRationnal())
    {
        *N = new Rationnal((long)(*N)->getNum(),(long)(*N)->getDenum());
        if((*N)->numIsInteger())
            *N = new Integer((long)(*N)->getNum());
    }
    else if((*N)->numIsReal())
        *N = new Real( (*N)->getNum()+(*N)->getMantisse() );
    else
        *N = new Real( (*N)->getNum()+(*N)->getMantisse() );
}

Complex Complex::operator=(const Complex& Cx){
    GeneralManager * m = &(GeneralManager::getInstance());
    m->removeLitteral(pReal);
           pReal= new Numeric();
           *pReal = *(Cx.pReal);
           numericCast(&pReal);
    m->removeLitteral(pImag);
            pImag=new Numeric();
            *pImag = (*(Cx.pImag));
            numericCast(&pImag);
    return *this;
}

bool Complex::operator==(const Complex& Cx) const {
    return ((*pReal== *Cx.pReal)&&(*pImag== *Cx.pImag));
}

Complex Complex::NEG() const{

    Numeric* N1 = new Numeric();
    *N1=pReal->NEG();
    Numeric* N2 = new Numeric();
    *N2=pImag->NEG();
    Complex C(N1,N2);
    return C;
}





