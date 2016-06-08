#ifndef COMPLEX_H
#define COMPLEX_H

#include "real.h"
#include "rationnal.h"
#include "integer.h"

class Complex : public Litteral {///réprésente un nombre de complexe. Les parties imaginaires et complexes sont donc des numeriques (càd entiers, rationnels ou réel).
    ///Les types de chaques parties sont revues en fonction de leur valeur (partie décimale nulle, denominateur égal à 0).
private:
    Numeric* pReal;
    Numeric* pImag;
public:
    Complex (Numeric* Re=nullptr, Numeric* Im=nullptr): pReal(Re), pImag(Im) {if (pImag==nullptr)
                                                        pImag= new Integer();} //correspond à la construction avec  $ (voir sujet)
    void print(QTextStream& f)const;
    Numeric& getReal() const { return *pReal;}
    Numeric& getImag() const { return *pImag;}
    std::string toString()const;
    QString toQStringPars()const;
    ~Complex(){}
   Complex operator=(const Complex& Cx );
   Complex operator+(const Complex& Cx) const;
   Complex operator-(const Complex& Cx)const ;
   Complex operator*(const Complex& Cx) const ;
   Complex operator/(const Complex& Cx) const;
   bool operator==(const Complex& Cx) const ;
   Complex NEG() const;

    bool isReal() const {return pImag->isNull();} //check si la partie imaginaire est nulle
    bool isImag() const {return pReal->isNull();}

};

void numericCast(Numeric ** N); //cast class fille


#endif // COMPLEX_H
