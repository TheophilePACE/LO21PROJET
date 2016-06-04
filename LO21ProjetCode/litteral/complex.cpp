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

Complex Complex::operator+(const Complex & Cx) const
{
    Numeric * N1 = new Numeric (0,1,0);
    *N1= (*pReal+ *(Cx.pReal));
    Numeric* N2 = new Numeric(0,1,0);
    *N2=((*pImag)+(*Cx.pImag));
    return Complex(N1,N2);
}
//Complex Complex::operator-(Complex Cx)const ;
//Complex Complex::operator*(Complex Cx) const ;
//Complex Complex::operator/(Complex Cx) const;
//Complex Complex::operator+(Numeric Cx) const;
//Complex Complex::operator-(Numeric Cx)const ;
//Complex Complex::operator*(Numeric Cx) const ;
//Complex Complex::operator/(Numeric Cx) const;

void numericCast(Numeric ** N)
{
    if((*N)->numIsInteger()) /*||(((*N)->getDenum()==0)&&((*N)->getMantisse()==0)))*/
    {
        *N = new Integer((long)(*N)->getNum());
        printf("ConvInt\n");
        std::cout<< (*N)->getNum()<<"   "<<(*N)->getDenum()<<"   "<< (*N)->getMantisse();
    }
    else if((*N)->numIsRationnal())
    {
        *N = new Rationnal((long)(*N)->getNum(),(long)(*N)->getDenum());
        printf("ConvRatio\n");
        if((*N)->numIsInteger())
            *N = new Integer((long)(*N)->getNum());
        std::cout<< (*N)->getNum()<<"   "<<(*N)->getDenum()<<"   "<< (*N)->getMantisse();


    }
    else if((*N)->numIsReal())
    {
        *N = new Real( (*N)->getNum()+(*N)->getMantisse() );
        printf("ConvReal\n");
        std::cout<< (*N)->getNum()<<"   "<<(*N)->getDenum()<<"   "<< (*N)->getMantisse();

    }

     else{
        *N = new Real( (*N)->getNum()+(*N)->getMantisse() );
        std::cout<< (*N)->getNum()<<"   "<<(*N)->getDenum()<<"   "<< (*N)->getMantisse()  <<"Num pure WTF \n";
    }
}

Complex Complex::operator=(const Complex& Cx){
    delete pReal;
           pReal= new Numeric();
           *pReal = *(Cx.pReal);
           numericCast(&pReal);
    delete pImag;
            pImag=new Numeric();
            *pImag = (*(Cx.pImag));
            numericCast(&pImag);
    return *this;
}





