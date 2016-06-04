#ifndef RATIONNAL_H
#define RATIONNAL_H

#include "integer.h"
#include "litteral.h"


class Rationnal : public Numeric {
private:
public:

    Rationnal(long N, long D ): Numeric(N,D) {simplify(); std::cout<<"\nConstruction Ratio\n";} //utile en cas de division. Comment gérer le retour?
    Rationnal(Integer a, Integer b); //Attention au simplicifications
    Rationnal(Rationnal& R): Numeric(R.num,R.denum) {}
    void print(QTextStream& f)const;
    std::string toString()const;
    std::string toStringPars()const;
    Rationnal simplify() ; //retour de type pointeur sur classe mere
    Rationnal operator+(Rationnal frac) const;
    Rationnal operator-(Rationnal frac)const;
    Rationnal operator*(Rationnal frac) const;
    Rationnal operator/(Rationnal frac) const;
    bool getSign() const {return ((num>=0)==(denum>=0));}
    bool isInteger () const;
    double getSignedValue() const {return (double)(((double)(getNum())) / (double)((getDenum())));}

};

Rationnal operator+(Integer a, Rationnal Ra);
Rationnal operator-(Integer a, Rationnal Ra);
Rationnal operator-(Rationnal Ra,Integer a);
Rationnal operator*(Integer a, Rationnal Ra);
Rationnal operator/(Integer a, Rationnal Ra);
Rationnal operator/(Rationnal Ra, Integer a);
Rationnal operator/(Integer int1, Integer int2);
#endif // RATIONNAL_H
