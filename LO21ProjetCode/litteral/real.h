#ifndef REAL_H
#define REAL_H

#include "litteral.h"
#include "integer.h"
#include "rationnal.h"

class Real : public Numeric {
private:
    int integer;
    float mantisse; //toujours entre 0 et 1.
public:
    bool simplify() ;
    float getSignedValue() const ;
    Real(float a): integer(static_cast<int>(truncf(a))), mantisse(a-truncf(a)){}
    Real(int in, float ma): integer(in), mantisse(ma) {} //ma est entre 0 et 1
    bool getSign() const {return integer>=0;} //négatif
    bool isInteger() const;
    void print(QTextStream& f)const;
    std::string toString()const;
    Real operator+(Real re) const;
    Real operator-(Real re)const ;
    Real operator*(Real re) const ;
    Real operator/(Real re) const;
    //~Real() {delete integer; delete ;} inutile
};

Real operator+(Real Re, Rationnal Ra);
Real operator-(Real Re, Rationnal Ra);
Real operator-(Rationnal Ra,Real Re);
Real operator*(Real Re, Rationnal Ra);
Real operator/(Real Re, Rationnal Ra);
Real operator/(Rationnal Ra, Real Re);

Real operator+(Integer a, Real Re);
Real operator-(Integer a, Real Re);
Real operator-(Real Re, Integer a);
Real operator*(Integer a, Real Re);
Real operator/(Integer a, Real Re);
Real operator/(Real Re, Integer a);

#endif // REAL_H
