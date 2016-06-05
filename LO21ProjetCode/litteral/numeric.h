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
    virtual Numeric operator+ (const Numeric& N) const;
    virtual Numeric operator- (const Numeric& N) const;
    virtual Numeric operator/ (const Numeric& N) const;
    virtual Numeric operator* (const Numeric& N) const;
    //virtual Numeric operator< (const Numeric& N) const;
    virtual void print(QTextStream& f)const; //implémentée
    virtual std::string toString()const;//implémentée
    virtual std::string toStringPars()const;//implémentée
    ~Numeric(){}
    Numeric(long n,long d,double m): num(n), denum(d), mantisse(m) {std::cout<<"\nConstruction Num\n";}
    Numeric(long n,long d): num(n), denum(d), mantisse(0) {std::cout<<"\nConstruction Num type frac\n";}
    //Numeric(long n): num(n), denum(1), mantisse(0) {std::cout<<"\nConstruction Num\n";}
    Numeric(double m): num(trunc(m)), denum(1), mantisse(m-trunc(m)) {std::cout<<"\nConstruction Num Avec Double\n";}
    Numeric(): num(0), denum(1), mantisse(0) {std::cout<<"\nConstruction Num sans arg \n";}
    Numeric (Numeric& N): num(N.num), denum(N.denum), mantisse(N.mantisse) {}
    //FONCTION POUR LES CONVERSIONS
    bool numIsInteger() const {return ((mantisse==0)&&(denum==1));} // A.0/1
    bool numIsRationnal() const {return ((mantisse==0)&&(denum!=1));}//A.0/B, A PEUT ETRE 0, PAS B
    bool numIsReal() const {return ((mantisse!=0)&&(denum==1));}//A.B/1
    double getVal() const;
   // Numeric operator=(Numeric N );
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


#endif // NUMERIC_H
