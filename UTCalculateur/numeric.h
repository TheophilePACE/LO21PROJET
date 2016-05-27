#ifndef NUMERIC_H
#define NUMERIC_H

#include "expression.h"




class Numeric : public ExpressionMaterial
{
protected:
    long num;
    double mantisse;
    long denum;
public:
    const long&  getNum() const { return num;}
    const long&  getDenum() const { return denum;}
    const double& getMantisse() const { return mantisse;}
    Numeric operator+ (const Numeric& N) const;
//    virtual Numeric& operator- (const Numeric& N) const;
//    virtual Numeric& operator/ (const Numeric& N) const;
//    virtual Numeric& operator* (const Numeric& N) const;
    virtual void print(QTextStream& f)const; //implémentée
    virtual std::string toString()const;//implémentée
    virtual ~Numeric(){}
    Numeric(long n=0,long d=1,double m=0): num(n), denum(d), mantisse(m) {}
    Numeric (Numeric& N): num(N.num), denum(N.denum), mantisse(N.mantisse) {}
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
