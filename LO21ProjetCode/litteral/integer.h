#ifndef INTEGER_H
#define INTEGER_H

#include "litteral.h"
#include "numeric.h"

class Integer: public Numeric{
private:
    int val;
public:
    Integer(int integer=0): val(integer) {} //abs pour absolute value, c'est dans STD
    ~Integer() {}
    bool getSign() const {return val>=0;} //négatif == 0
    unsigned int getAbsoluteValue() const {return std::abs(val);}
    int getSignedValue() const {return val;}
    void print (QTextStream& f)const;
    std::string toString()const;
    int setValue(int integer);
    Integer operator+(Integer integer) const;
    Integer operator-(Integer integer)const ;
    Integer operator*(Integer integer) const ;
    //Rationnal operator/(Integer integer) const;
    Integer NEG(){return -val;} //le retour permet une opération du type A+NEG(B)
};
#endif // INTEGER_H
