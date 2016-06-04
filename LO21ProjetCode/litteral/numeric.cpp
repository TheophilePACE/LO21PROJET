#include "numeric.h"
#include "real.h"

//ANCIENNE VERSION:
//Numeric& operator+(const Numeric& N1, const Numeric& N2)
//{
//    Numeric* result = &(N1+N2);
//    return *result;
//}
void Numeric::print(QTextStream& f)const{
        if(mantisse!=0){
        f<<num;
        if(denum!=1)
            f<<"/"<<denum;}
        else
                //(mantisse!=0)
            f<<(num+mantisse);

    }

double Numeric::getVal()  const{
    double n = (double)(num);
    double d = (double)(denum);
    double m = (double)(mantisse);
    return (n+m)/d;

}
std::string Numeric::toString()const
{
    std::string s="";
    if(mantisse!=0){
    s+=std::to_string(num);
    if(denum!=1)
        s+=("/"+std::to_string(denum));}
    else
            //(mantisse!=0)
        s+=(std::to_string(num+mantisse));
    return s;
}


 Numeric Numeric::operator+ (const Numeric& N) const
 {
     std::cout<<"utilisation ope num";
     double nmantisse,temp;
     temp= (mantisse+num)*N.getDenum() + (N.getNum()+N.getMantisse())*denum;
     nmantisse =temp-trunc(temp);

     if(nmantisse==0)
         {Rationnal Rslt((long)(temp), (N.getDenum()*getDenum()) );
          return Rslt;}
     if(nmantisse !=0)
     {
         double d = getVal() + N.getVal();
         Real Rslt(d);
         return Rslt;}
     else
     {
         std::cout<<"construc numeric WTF";
         Numeric N(0,1);
         return N;
     }

 }
// Numeric& Numeric::operator- (const Numeric& N) const
// {
//     long nnum,ndenum;
//     double nmantisse;
//     nnum= num*N.denum - N.num*denum;
//     ndenum = denum*N.denum;
//     nmantisse = mantisse-N.mantisse;
//     Numeric Rslt(nnum,ndenum,nmantisse);
//     return Rslt;
// }
// Numeric& Numeric::operator/ (const Numeric& N) const
// {
//     long nnum,ndenum;
//     double nmantisse;
//     nnum= num*N.denum
//     ndenum = denum*N.num;
//     nmantisse = mantisseN.mantisse;
//     Numeric Rslt(nnum,ndenum,nmantisse);
//     return Rslt;
// }

// Numeric Numeric::operator=(Numeric N){
//     mantisse=N.getMantisse();
//     num=N.getNum();
//     denum=N.getDenum();
//    return *this;
// }

