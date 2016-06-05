#ifndef INTEGER_H
#define INTEGER_H

#include "numeric.h"

class Integer: public Numeric{
private:
public:
    Integer(long n=0): Numeric(n) {} //abs pour absolute value, c'est dans STD

    ~Integer() {}
    bool getSign() const {return num>=0;} //négatif == 0
    unsigned long getAbsoluteValue() const {return std::abs(num);}
    long getSignedValue() const {return num;}
    void print (QTextStream& f)const;
    std::string toString()const;
    std::string toStringPars()const;
    long setValue(long integer);
    Integer operator+(Integer integer) const;
    Integer operator-(Integer integer)const ;
    Integer operator*(Integer integer) const ;
    Integer MOD(Integer integer) const ;
    Integer DIV(Integer integer) const ;
    //bool operator/(Integer integer) const;
    Integer NEG() { long a = num;
                    Integer I(-a);
                  return I;} //le retour permet une opération du type A+NEG(B)
};
#endif // INTEGER_H
