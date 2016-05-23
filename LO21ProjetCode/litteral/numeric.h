#ifndef NUMERIC_H
#define NUMERIC_H

#include "litteral.h"
#include "expression.h"

class Numeric : public ExpressionMaterial
{
public:
    //virtual Numeric& operator+ (const Numeric& N) const =0;
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual ~Numeric(){}
    //virtual Numeric& operator+ (Numeric* N1) =0;


};

Numeric& operator+(const Numeric& N1, const Numeric& N2);

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
