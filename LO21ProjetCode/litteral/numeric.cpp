#include "numeric.h"

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


// Numeric Numeric::operator+ (const Numeric& N) const
// {
//     long nnum,ndenum;
//     double nmantisse,temp;
//     temp= (mantisse+num)*N.denum + (N.num+N.mantisse)*denum;
//     nnum = trunc(temp);
//     ndenum = denum*N.denum;
//     nmantisse = temp-nnum;
//     Numeric Rslt(nnum,ndenum,nmantisse);
//     return Rslt;
// }
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
// Numeric& Numeric::operator* (const Numeric& N) const




