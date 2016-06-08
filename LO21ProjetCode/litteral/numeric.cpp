#include "numeric.h"
#include "real.h"
#include "complex.h"

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
    return toQStringPars().toStdString();
}
QString Numeric::toQStringPars()const{
    QString s = "";
    if(mantisse!=0){
    s += num;
    if(denum!=1)
        s+=("/"+QString::number(denum));}
    else
            //(mantisse!=0)
        s+=(QString::number(num+mantisse));
    return s;
}

//Operations sur les numerics
 Numeric Numeric::operator+ (const Numeric& N) const
 {
     double nmantisse,temp;
     temp= (mantisse+num)*N.getDenum() + (N.getNum()+N.getMantisse())*denum;
     nmantisse =temp-trunc(temp);

     if(nmantisse==0)
         {Rationnal *Rslt = new Rationnal((long)(temp), (N.getDenum()*getDenum()) );
          return *Rslt;}
     if(nmantisse !=0)
     {
         double d = getVal() + N.getVal();
         Real * Rslt = new Real(d);
         return *Rslt;}
     else
     {
         Numeric * N = new Numeric(0,1);
         return *N;
     }

 }
 Numeric Numeric::operator- (const Numeric& N) const
 {
     double nmantisse,temp;
     temp=  (mantisse+num)*N.getDenum() -((N.getNum()+N.getMantisse())*denum) ;
     nmantisse =temp-trunc(temp);

     if(nmantisse==0)
         {Rationnal * Rslt = new Rationnal((long)(temp), (long)(N.getDenum()*getDenum()) );
          return *Rslt;}
     if(nmantisse !=0)
     {
         double d = getVal() - N.getVal();
         Real * Rslt = new Real(d);
         return *Rslt;}
     else
     {
         Numeric * N = new Numeric(0,1);
         return *N;
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
          {Rationnal * Rslt = new Rationnal(nnum, ndenum);
           return *Rslt;}
      if(nmantisse !=0)
      {
          Real * Rslt = new Real(temp/ndenum);
          return *Rslt;}
      else
      {
          Numeric * N = new Numeric(0,1);
          return *N;
      }  }


  Numeric Numeric::operator/ (const Numeric& N) const
  {   long ndenum,nnum;
      double dtemp,ntemp;
      dtemp= (N.num+N.mantisse)*(getDenum());
      ntemp = N.denum*(getNum()+getMantisse());
      nnum= trunc(ntemp);
      ndenum=trunc(dtemp);
      if((ntemp==nnum)&&(ndenum==dtemp)) //integer et ratio ou simplification
          {Rationnal * Rslt = new Rationnal(nnum,ndenum);
           return *Rslt;}

          Real * Rslt = new Real(ntemp/dtemp);
          return *Rslt;}


  bool  Numeric::operator==(const Numeric& N) const{
      return ((num==N.getNum())&&(denum==N.getDenum())&&(mantisse==N.getMantisse()));
  }

  Numeric Numeric::NEG() const
  {
      Numeric *N = new Numeric(-num,denum,-mantisse);
      numericCast(&N);
      return *N;
  }

