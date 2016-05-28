#ifndef NUMERIC_H
#define NUMERIC_H

#include "expression.h"




class Numeric : public ExpressionMaterial
{
protected:
    long num;
    long denum;
    double mantisse;

public:
    const long&  getNum() const { return num;}
    const long&  getDenum() const { return denum;}
    const double& getMantisse() const { return mantisse;}
    bool isNull() const {return (num+mantisse ==0);}
  //  Numeric operator+ (const Numeric& N) const;
//    virtual Numeric& operator- (const Numeric& N) const;
//    virtual Numeric& operator/ (const Numeric& N) const;
//    virtual Numeric& operator* (const Numeric& N) const;
    virtual void print(QTextStream& f)const; //implémentée
    virtual std::string toString()const;//implémentée
    ~Numeric(){}
    Numeric(long n=0,long d=1,double m=0): num(n), denum(d), mantisse(m) {std::cout<<"\nConstruction Num\n";}
    Numeric (Numeric& N): num(N.num), denum(N.denum), mantisse(N.mantisse) {}
    //FONCTION POUR LES CONVERSIONS
    bool numIsInteger() const {return ((mantisse==0)&&(denum==1));} // A.0/1
    bool numIsRationnal() const {return ((mantisse==0)&&(denum!=1));}//A.0/B, A PEUT ETRE 0, PAS B
    bool numIsReal() const {return ((mantisse!=0)&&(denum==1));}//A.B/1

};


//TEMPLATE POUR ADDITION Numeric
/*template <class T1, class T2>
Numeric* addNum (T1* N1,T2* N2)
{
    Numeric * Rslt;
    Rslt=dynamic_cast<Numeric*>( &( *(N1) + *(N2) ) );
    return Rslt;
}
*/

//bool castNum(Numeric * N); //cast class fille

#endif // NUMERIC_H
