#include "complex.h"

void Complex::print(QTextStream& f)const
{
    pReal->print(f);
    f<<" + ";
    pImag->print(f);
    f<<"i";
}
std::string Complex::toString()const
{
    return (*pReal).toString()+  " + "   + (*pImag).toString() + "i";
}

Complex Complex::operator+(Complex Cx) const
{
    Numeric* N1 = new Numeric();
    *N1=((*pReal)+(*Cx.pReal));
    Numeric* N2 = new Numeric();
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
    }
    else if((*N)->numIsRationnal())
    {
        *N = new Rationnal((long)(*N)->getNum(),(long)(*N)->getDenum());
        printf("ConvRatio\n");

    }
    else if((*N)->numIsReal())
    {
        *N = new Real( (*N)->getNum()+(*N)->getMantisse() );
        printf("ConvReal\n");
    }

        else
        std::cout<<"Num pure WTF \n";
}




