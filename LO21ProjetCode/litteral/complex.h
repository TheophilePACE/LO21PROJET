#ifndef COMPLEX_H
#define COMPLEX_H

#include "real.h"
#include "rationnal.h"
#include "integer.h"
///réprésente un nombre de complexe. Les parties imaginaires et complexes sont donc des numeriques (càd entiers, rationnels ou réel).
//!Les types de chaques parties sont revues en fonction de leur valeur (partie décimale nulle, denominateur égal à 0).

class Complex : public Litteral {
private:///Partie réelle, implémentée par un pointeur sur un numérique. L'objet pointé est en réalité un objet d'une des classes filles de numériques.
    Numeric* pReal;///Partie Imaginaire, implémentée par un pointeur sur un numérique. L'objet pointé est en réalité un objet d'une des classes filles de numériques.
    Numeric* pImag;
public:
    Complex (Numeric* Re=nullptr, Numeric* Im=nullptr): pReal(Re), pImag(Im) {if (pImag==nullptr)
                                                        pImag= new Integer();} //correspond à la construction avec  $ (voir sujet)
    void print(QTextStream& f)const;
    ///Accesseur à la partie réelle du complexe.
    Numeric& getReal() const { return *pReal;}
    ///Accesseur à la partie Imaginaire du complexe.
    Numeric& getImag() const { return *pImag;}
    std::string toString()const;
    QString toQStringPars()const;
    ~Complex(){}
     /*! Operateurs dans Z. le retour se fait également dans Z.
    */
    //@{
   Complex operator=(const Complex& Cx );
   Complex operator+(const Complex& Cx) const;
   Complex operator-(const Complex& Cx)const ;
   Complex operator*(const Complex& Cx) const ;
   Complex operator/(const Complex& Cx) const;
   //@}
   ///Comparaison des deux membres pointés par pReal et pImag.
   bool operator==(const Complex& Cx) const ;
   Complex NEG() const;
    ///Teste si la partie imaginaire est nulle, càd si l'objet est dans R.
    bool isReal() const {return pImag->isNull();} ///Teste si la partie réelle est nulle
    bool isImag() const {return pReal->isNull();}

};

//!Cast d'un objet numeric vers une de ses classes filles
/*!
 * \brief numericCast
 * \param N : pointeur de pointeur: on va modifier le pointeur via dynamic cast, il faut donc passer le pointeur par adresse.
 * Cette fonction va utiliser les différentes fonctions de test présentes dans Numeriic pour déterminer le type d'un objet pointé par un pointeur sur numérique.
 * EN fonction du résultat, elle va créer un objet du type adéquat (un rationnel si la mantisse est nulle et le dénominateur différent de 1, ...)
 * Ensuite, le pointeur situé à l'adresse N va être redirigé vers cette objet. On peut donc le réutiliser, sans avoir à connaître  le type exact de l'objet pointé.
 * Enfin, ce cast permet également de passer d'une classe fille à une autre (simplification lors d'une division dans Q par exemple).
 */
void numericCast(Numeric ** N);


#endif // COMPLEX_H
