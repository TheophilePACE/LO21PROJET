#ifndef INTEGER_H
#define INTEGER_H

#include "numeric.h"
/*! \brief Classe représentant les nombres de Z, les entiers relatifs.
 *la valeur d'un entier est stockée dans l'attribut  num déclaré dans Numeric. les autres attributs restent à leur valeurs par défaut: 1 pour denum et 0 pour la mantisse.
  * Cette classe ne comporte donc pas de nouveaux attributs.
  */

class Integer: public Numeric{
private:
public:
    //! Fait appel au constructeur de numerique à un argument, en attribuant la valeur passée en argument comme num.
    Integer(long n=0): Numeric(n) {}

    ~Integer() {}
    bool getSign() const {return num>=0;} //négatif == 0
    unsigned long getAbsoluteValue() const {return std::abs(num);}
    long getSignedValue() const {return num;}
    void print (QTextStream& f)const;
    std::string toString()const;
    QString toQStringPars()const;
    long setValue(long integer);

     /*! \brief Operateurs sur Z.
      *  La division exacte créant un rationnel, elle est implémentée avec la classe rationnal dans la fichier rationnal.h
      * Retour par valeur car on connait à l'avance le type de retour.
    */
    //@{

    Integer operator+(Integer integer) const;
    Integer operator-(Integer integer)const ;
    Integer operator*(Integer integer) const ;
    Integer MOD(Integer integer) const ;
    Integer DIV(Integer integer) const ;
    //@}


};
#endif // INTEGER_H
