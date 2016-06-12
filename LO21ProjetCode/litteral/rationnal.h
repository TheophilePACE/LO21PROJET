#ifndef RATIONNAL_H
#define RATIONNAL_H


#include "numeric.h"
class Litteral;
class Integer;
//! Classe représentant les nombres de Q, les rationnels ou fractions.
//! la valeur d'un rationnel est stocké dans le num et le denum  déclarés dans Numeric. la mantisse garde sa valeur par défaut   c'est à dire 0 .
//! Cette classe ne comporte donc pas de nouveaux attributs.
class Rationnal : public Numeric {
private:
public:
     /*! Ces méthodes appliquent une simplification via le pgcd de manière à simplifiée la fonction crée. L'objet retourné est toujours un rationnal. le changement de type sera assuré par la manager.*/
    //@{
    //!Création à partir de deux valeurs de type long. Correspond à une construction directe par l'utilisateur.
    Rationnal(long N, long D ): Numeric(N,D) {simplify();} //utile en cas de division. Comment gérer le retour?
    ///Création à partir de deux integer. Correspond à la division d'un entier par un autre.
    Rationnal(Integer a, Integer b); //Attention au simplicifications
    Rationnal(Rationnal& R): Numeric(R.num,R.denum) {}
    //@}
    ~Rationnal(){}
    void print(QTextStream& f)const;
    std::string toString()const;
    QString toQStringPars()const;
    ///Simplification de fraction  vers une fraction irréductible: on divise num et denum par pgcd(num,denum).
    Rationnal simplify() ;
     /*! \name Operateur de Q vers Q.
    * Le changement de type sera assurer par la classe operateur au travers de numericcast.
    */
    //@{
    Rationnal operator+(Rationnal frac) const;
    Rationnal operator-(Rationnal frac)const;
    Rationnal operator*(Rationnal frac) const;
    Rationnal operator/(Rationnal frac) const;
    //@}
    ///Retourne le signe. Evite les erreurs si les signes de num et denum sont différents.
    bool getSign() const {return ((num>=0)==(denum>=0));}
    bool isInteger () const;

    double getSignedValue() const {return (double)(((double)(getNum())) / (double)((getDenum())));}

};
/*! \name Operateur de Q et Z vers Q.
* Le changement de type sera assurer par la classe operateur au travers de numericcast.*/
//@{
Rationnal operator+(Integer a, Rationnal Ra);
Rationnal operator-(Integer a, Rationnal Ra);
Rationnal operator-(Rationnal Ra,Integer a);
Rationnal operator*(Integer a, Rationnal Ra);
Rationnal operator/(Integer a, Rationnal Ra);
Rationnal operator/(Rationnal Ra, Integer a);
///Division décimale dans Z. Retourne int1/int2 sous forme de fraction irréductible.
Rationnal operator/(Integer int1, Integer int2);
//@}

#endif // RATIONNAL_H
