#ifndef RATIONNAL_H
#define RATIONNAL_H

#include "integer.h"
#include "litteral.h"


class Rationnal : public Numeric {
private:
    int num;
    int denum;
public:
    const int&  getNum() const { return num;}
    const int&  getDenum() const { return denum;}
    Rationnal(int N, int D ): num(N), denum(D) {simplify();} //utile en cas de division. Comment gérer le retour?
    Rationnal(Integer a, Integer b); //Attention au simplicifications
    void print(QTextStream& f)const;
    std::string toString()const;
    Rationnal simplify() ; //retour de type pointeur sur classe mere
    Rationnal operator+(Rationnal frac) const;
    Rationnal operator-(Rationnal frac)const;
    Rationnal operator*(Rationnal frac) const;
    Rationnal operator/(Rationnal frac) const;
    bool getSign() const {return ((num>=0)==(denum>=0));}
    bool isInteger () const;
    float getSignedValue() const {return num/denum;}

};

Rationnal operator+(Integer a, Rationnal Ra);
Rationnal operator-(Integer a, Rationnal Ra);
Rationnal operator-(Rationnal Ra,Integer a);
Rationnal operator*(Integer a, Rationnal Ra);
Rationnal operator/(Integer a, Rationnal Ra);
Rationnal operator/(Rationnal Ra, Integer a);
Rationnal operator/(Integer int1, Integer int2);
#endif // RATIONNAL_H
