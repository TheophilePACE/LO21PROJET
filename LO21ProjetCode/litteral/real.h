#ifndef REAL_H
#define REAL_H

#include "rationnal.h"

class Litteral;
class Integer;
//! Classe représentant les nombres de R, les réels.
//! la valeur d'un réels est stocké dans le num et la mantisse  déclarés dans Numeric. le denum garde sa valeur par défaut   c'est à dire 1 .
//! Cette classe ne comporte donc pas de nouveaux attributs.
//! La mantisse est toujours comprise entre 0 et 1. Si elle vaut plus de 1 ou moins de -1, la valeur est ramené entre 0 et 1 en ajustant num.
class Real : public Numeric {
private:
public:
    Real(Real& R): Numeric(R.getNum()+R.getMantisse()) {}
    ~Real(){}
    ///Vérifie que -1<mantisse<1. Augmente ou diminue mantisse de 1, en répercutant le changement sur num sinon.
    bool simplify() ;
    ///Renvoie la valeur du réel, c'est à dire la somme de num et mantisse sous forme de double.
    double getSignedValue() const ;
    ///Construction à partir d'une valeur double: permet la construction à partir de la valeur approchée du résultat d'une opération, ou en saisie directe de l'utilisateur.
    Real(double a=0): Numeric(a){}
    Real(long in, double ma): Numeric(in+ma) {} //ma est entre 0 et 1
    bool getSign() const {return num>=0;} //négatif
    void print(QTextStream& f)const;
    std::string toString()const;
    QString toQStringPars()const;
     /*! Operateurs de R vers R
    Le changement de type sera assurer par la classe operateur au travers de numericcast.*/

    //@{
    Real operator+(Real re) const;
    Real operator-(Real re)const ;
    Real operator*(Real re) const ;
    Real operator/(Real re) const;
    //@}

};

 /*! Le changement de type sera assurer par la classe operateur au travers de numericcast.*/
//@{
 /*! Operateurs de R et Q vers R*/

//@{
Real operator+(Real Re, Rationnal Ra);
Real operator+(Rationnal Ra, Real Re);
Real operator-(Real Re, Rationnal Ra);
Real operator-(Rationnal Ra,Real Re);
Real operator*(Real Re, Rationnal Ra);
Real operator/(Real Re, Rationnal Ra);
Real operator/(Rationnal Ra, Real Re);
//@}
 /*! Operateurs de R et Z vers R*/
//@{
Real operator+(Integer a, Real Re);
Real operator-(Integer a, Real Re);
Real operator-(Real Re, Integer a);
Real operator*(Integer a, Real Re);
Real operator/(Integer a, Real Re);
Real operator/(Real Re, Integer a);
//@}
//@}
#endif // REAL_H
