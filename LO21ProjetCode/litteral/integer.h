#ifndef INTEGER_H
#define INTEGER_H

#include "numeric.h"
//! Classe représentant les nombres de Z, les entiers relatifs.
//! la valeur d'un entier est stocké dans le num déclaré dans Numeric. les autres attributs restent à leur valeurs par défaut: 1 pour denum et 0 pour la mantisse.
 //! Cette classe ne comporte donc pas de nouveaux attributs.

class Integer: public Numeric{
private:
public:
    //! Fait appel au cnstructeur de numerique à un argument, en attribuant la valeur passé en argument comme num.
    Integer(long n=0): Numeric(n) {}

    ~Integer() {}
    bool getSign() const {return num>=0;} //négatif == 0
    unsigned long getAbsoluteValue() const {return std::abs(num);}
    long getSignedValue() const {return num;}
    void print (QTextStream& f)const;
    std::string toString()const;
    QString toQStringPars()const;
    long setValue(long integer);
     /*! Operateurs sur Z. La division décimale créant un rationnel, elle est implémentée avec la classe rationnal dans la fichier rationnal.h
    */
    //@{
    Integer operator+(Integer integer) const;
    Integer operator-(Integer integer)const ;
    Integer operator*(Integer integer) const ;
    Integer MOD(Integer integer) const ;
    Integer DIV(Integer integer) const ;
    //@}
    ///Retourne l'opposé de l'Integer.
    Integer NEG() { long a = num;
                    Integer I(-a);
                  return I;} //le retour permet une opération du type A+NEG(B)
};
#endif // INTEGER_H
