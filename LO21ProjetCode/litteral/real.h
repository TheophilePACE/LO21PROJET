#ifndef REAL_H
#define REAL_H

#include "litteral.h"
#include "integer.h"
#include "rationnal.h"

class Real : public Numeric {
private:
public:
    Real(Real& R): Numeric(R.getNum()+R.getMantisse()) {std::cout<<"\nConstruction Real\n";}
    bool simplify() ;
    double getSignedValue() const ;
    Real(double a=0): Numeric(a){}
    Real(long in, double ma): Numeric(in+ma) {} //ma est entre 0 et 1
    bool getSign() const {return num>=0;} //négatif
    bool isInteger() const;
    void print(QTextStream& f)const;
    std::string toString()const;
    std::string toStringPars()const;
    Real operator+(Real re) const;
    Real operator-(Real re)const ;
    Real operator*(Real re) const ;
    Real operator/(Real re) const;
    //~Real() {delete integer; delete ;} inutile
};

Real operator+(Real Re, Rationnal Ra);
Real operator+(Rationnal Ra, Real Re);
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
