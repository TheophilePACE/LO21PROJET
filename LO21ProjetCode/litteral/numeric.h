#ifndef NUMERIC_H
#define NUMERIC_H

#include "expression.h"
//!Classe mère pour tous les types de nombres dans R.
/*!
  Ceci est la classe mère pour les numériques dans R, c'est à dire les réels, entiers et rationnels.
  Il n'y a pas d'objet permanents de cette classe, elle n'est instanciée que de manière temporaire.
  Les objets sont alors cast vers les classes filles, correspondant aux types de R.
  */
class Numeric : public Litteral {


protected://! Valeur d'un entier ou numérateur d'une fraction, ou encore partie entière d'un réel.
    long num; //! dénominateur d'une fraction
    long denum; //! partie décimale d'un réel.
    double mantisse;

public:
    const long&  getNum() const { return num;}
    const long&  getDenum() const { return denum;}
    const double& getMantisse() const { return mantisse;}
    bool isNull() const {return (num+mantisse ==0);}
    virtual Numeric operator+ (const Numeric& N) const;
    virtual Numeric operator- (const Numeric& N) const;
    virtual Numeric operator/ (const Numeric& N) const;
    virtual Numeric operator* (const Numeric& N) const;
    bool operator== (const Numeric& N) const;
    Numeric NEG() const;
    /*! Fonctions surchargées dans les classes filles de manière à n'afficher que les parties utiles (différentes des valeurs standards) du nombre.
    */
    //@{
    virtual void print(QTextStream& f)const; //implémentée
    virtual std::string toString()const;//implémentée
    virtual QString toQStringPars()const;//implémentée
    //@}

    ~Numeric(){}
    Numeric(long n,long d,double m): num(n), denum(d), mantisse(m) {}
    Numeric(long n,long d): num(n), denum(d), mantisse(0) {}
    //Numeric(long n): num(n), denum(1), mantisse(0) {}
    Numeric(double m): num(trunc(m)), denum(1), mantisse(m-trunc(m)) {}
    Numeric(): num(0), denum(1), mantisse(0) {}
    Numeric (Numeric& N): num(N.num), denum(N.denum), mantisse(N.mantisse) {}
    /*! \name Fonctions pour les conversions vers classes filles
     */
    //@{
      //! Teste si le numeric est dans Z, ensemble des entiers.
    bool numIsInteger() const {return ((mantisse==0)&&(denum==1));}
    //! Teste si le numeric est dans Q, ensemble des rationnels.
    bool numIsRationnal() const {return ((mantisse==0)&&(denum!=1));}
    //! Teste si le numeric est dans R, ensemble des réel.
    bool numIsReal() const {return ((mantisse!=0)&&(denum==1));} //! retourne la valeur approché du nombre, c'est à dire Num/denum pour Q, num+mantisse pour R. La veleur est donc un float.
    //@}

    double getVal() const;
};






#endif // NUMERIC_H
