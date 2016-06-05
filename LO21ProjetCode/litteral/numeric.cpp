#include "numeric.h"
#include "real.h"

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
 Numeric Numeric::operator- (const Numeric& N) const
 {
     std::cout<<"utilisation ope num";
     double nmantisse,temp;
     temp=  ((N.getNum()+N.getMantisse())*denum)-(mantisse+num)*N.getDenum() ;
     nmantisse =temp-trunc(temp);

     if(nmantisse==0)
         {Rationnal Rslt((long)(temp), (long)(N.getDenum()*getDenum()) );
         std::cout<<"mantisse 0 ; temp ="<<temp<<"mb1:"<<(mantisse+num)*N.getDenum()<<"mb2"<<((N.getNum()+N.getMantisse())*denum);
          return Rslt;}
     if(nmantisse !=0)
     {
         double d = getVal() - N.getVal();
         Real Rslt(d);
         return Rslt;}
     else
     {
         std::cout<<"construc numeric WTF";
         Numeric N(0,1);
         return N;
     }

 }
 Numeric Numeric::operator* (const Numeric& N) const
  {
      long ndenum,nnum;
      double temp,nmantisse;
      temp= (num+mantisse)*(N.getNum()+N.getMantisse());
      ndenum = denum*N.getDenum();
      nnum= trunc((temp));
      nmantisse = temp - trunc(temp);
      if(nmantisse==0)
          {Rationnal Rslt(nnum, ndenum);
          std::cout<<"mantisse 0 ; temp ="<<temp<<"mb1:"<<(mantisse+num)*N.getDenum()<<"mb2"<<((N.getNum()+N.getMantisse())*denum);
           return Rslt;}
      if(nmantisse !=0)
      {
          Real Rslt(temp/ndenum);
          return Rslt;}
      else
      {
          std::cout<<"construc numeric WTF";
          Numeric N(0,1);
          return N;
      }  }


  Numeric Numeric::operator/ (const Numeric& N) const
  {

      long ndenum,nnum;
      double dtemp,ntemp;
      ntemp= (N.num+N.mantisse)*(getDenum());
      dtemp = N.denum*(getNum()+getMantisse());
      nnum= trunc(ntemp);
      ndenum=trunc(dtemp);
      if((ntemp==nnum)&&(ndenum==dtemp)) //integer et ratio ou simplification
          {Rationnal Rslt(nnum,ndenum);
           return Rslt;}

          Real Rslt(ntemp/dtemp);
          return Rslt;
  }



// Numeric Numeric::operator=(Numeric N){
//     mantisse=N.getMantisse();
//     num=N.getNum();
//     denum=N.getDenum();
//    return *this;
// }

