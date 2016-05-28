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
    Complex (Numeric* Re, Numeric* Im): pReal(Re), pImag(Im) {std::cout<<"\nConstruction Cplx\n";} //correspond à la construction avec  $ (voir sujet)
    void print(QTextStream& f)const;
    std::string toString()const;
    ~Complex(){}
    Complex operator+(Complex Cx) const;
//    Complex operator-(Complex Cx)const ;
//    Complex operator*(Complex Cx) const ;
//    Complex operator/(Complex Cx) const;
    bool isReal() const {return pImag->isNull();} //check si la partie imaginaire est nulle
    bool isImag() const {return pReal->isNull();}

};

#endif // COMPLEX_H
