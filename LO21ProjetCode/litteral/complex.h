#ifndef COMPLEX_H
#define COMPLEX_H

#include "real.h"
#include "rationnal.h"
#include "integer.h"


class Complex : public ExpressionMaterial {
private:
    Numeric* pReal;
    Numeric* pImag;
public:
    Complex (Numeric* Re=nullptr, Numeric* Im=nullptr): pReal(Re), pImag(Im) {if (pImag==nullptr)
                                                                     pImag= new Integer();} //correspond à la construction avec  $ (voir sujet)
    void print(QTextStream& f)const;
    std::string toString()const;
    ~Complex(){}
   Complex operator=(const Complex& Cx );
   Complex operator+(const Complex& Cx) const;
   Complex operator-(const Complex& Cx)const ;
   Complex operator*(const Complex& Cx) const ;
   Complex operator/(const Complex& Cx) const;
    bool isReal() const {return pImag->isNull();} //check si la partie imaginaire est nulle
    bool isImag() const {return pReal->isNull();}

};

void numericCast(Numeric ** N); //cast class fille


#endif // COMPLEX_H
