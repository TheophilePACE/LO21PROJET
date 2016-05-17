#ifndef LITTERAL_H
#define LITTERAL_H


#include <string>
#include <iostream>
#include <stack>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <math.h>
#include <cmath>        // pour std::abs

/*Fichier contenant les définitions des littérales selon l'énoncé*/

QString toQString(std::string s);

class Litteral {
public:
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual ~Litteral(){}
};

class ExpressionMaterial : public Litteral {
public:
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual ~ExpressionMaterial(){}
};

class Expression : public Litteral {
    ExpressionMaterial ** tab;
    unsigned int nb;
    unsigned int max;
public:
    Expression(): tab(nullptr), nb(0),max(0){}
    ~Expression(){nb = 0; max = 0; delete[] tab;}
    void increaseCap();
    void operator<<(ExpressionMaterial* e);
    std::string toString()const;
    void print(QTextStream& f)const;
};

class Program : public Litteral {
    std::string instructions;
public:
    Program(std::string s):instructions(s){}
    void print(QTextStream& f)const;
    std::string toString()const{return instructions;}
};

class Atom : public ExpressionMaterial {
    std::string lib;
public:
    Atom(std::string& s):lib(s){}
    void print(QTextStream& f) const {f<<toQString(lib);}
    std::string toString()const{return lib;}
    ~Atom(){}
};

bool estUnOperateur(const QString s);
bool estUnNombre(const QString s);

//ressemble fortement à la classe ExpressionMaterial. Egalement virtuelle.
unsigned int PGCD(int a, int b);
class Numerique : public ExpressionMaterial
{
public:
    //virtual Numerique operator+ (Numerique N) const =0;
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual ~Numerique(){}
    //virtual Numerique& operator+ (Numerique* N1) =0;


};


//Classes concrètes



class Rationnal;

class Integer: public Numerique{
private:
    int val;
   // bool sign; //0 --> negatif, 1 --> positif. 0 considéré comme positif
public:
    Integer(int entier=0): val(entier) {} //abs pour absolute value, c'est dans STD
    ~Integer() {}
    bool getSign() const {return val>=0;} //négatif == 0
    unsigned int getAbsoluteValue() const {return std::abs(val);}
    int getSignedValue() const {return val;}
    void print (QTextStream& f)const;
    std::string toString()const;
    int setValue(int entier) ;
    Integer operator +(Integer entier) const;
    Integer operator- (Integer entier)const ;
    Integer operator * (Integer entier) const ;
    Rationnal operator / (Integer entier) const;
    Integer NEG(){return -val;} //le retour permet une opération du type A+NEG(B)
};


class Rationnal : public Numerique {
private:
    int num;
    int denum;
public:
    const int&  getnum() const { return num;}
    const int&  getdenum() const { return denum;}
    Rationnal(int N, int D ): num(N), denum(D) {simplify();} //utile en cas de division. Comment gérer le retour?
    Rationnal(Integer a, Integer b); //Attention au simplicifications
    void print(QTextStream& f)const;
    std::string toString()const;
    Rationnal simplify() ; //retour de type pointeur sur classe mere
    Rationnal operator +(Rationnal frac) const;
    Rationnal operator- (Rationnal frac)const ;
    Rationnal operator * (Rationnal frac) const ;
    Rationnal operator / (Rationnal frac) const;
    bool getSign() const {return ((num>=0)==(denum>=0));}
    bool IsInteger () const;
    float getSignedValue() const {return num/denum;}

};

class Real : public Numerique {
private:
    int entier;
    float mantisse; //toujours entre 0 et 1.
public:
    bool Simplify() ;
    float getSignedValue() const ;
    Real(float a): entier(static_cast<int>(truncf(a))), mantisse(a-truncf(a)){} ;
    bool getSign() const {return entier>=0;} //négatif
    bool IsInteger() const;
    void print(QTextStream& f)const;
    std::string toString()const;
    Real operator +(Real re) const;
    Real operator  - (Real re)const ;
    Real operator * (Real re) const ;
    Real operator / (Real re) const;
    //~Real() {delete entier; delete ;} inutile
};

//OPERATIONS ENTRE NUMERIQUES DEFINIES

Rationnal operator+(int a, Rationnal Ra) ;
Rationnal operator-(int a, Rationnal Ra) ;
Rationnal operator-(Rationnal Ra,int a);
Rationnal operator*(int a, Rationnal Ra) ;
Rationnal operator/(int a, Rationnal Ra) ;
Rationnal operator/(Rationnal Ra,int a);


Real operator+(Real Re, Rationnal Ra) ;
Real operator-(Real Re, Rationnal Ra) ;
Real operator-(Rationnal Ra,Real Re) ;
Real operator*(Real Re, Rationnal Ra) ;
Real operator/(Real Re, Rationnal Ra) ;
Real operator/( Rationnal Ra,Real Re) ;

Real operator+(int a, Real Re) ;
Real operator-(int a, Real Re) ;
Real operator-(Real Re, int a) ;
Real operator*(int a, Real Re) ;
Real operator/(int a, Real Re) ;
Real operator/( Real Re,int a) ;


//TEMPLATE POUR ADDITION NUMERIQUE
/*template <class T1, class T2>
Numerique* addNum (T1* N1,T2* N2)
{
    Numerique * Rslt;
    Rslt=dynamic_cast<Numerique*>( &( *(N1) + *(N2) ) );
    return Rslt;
}
*/



class Complex : public ExpressionMaterial {
private:
    Numerique* Preal;
    Numerique* Pimag;
public:
    Complex (Numerique* Re, Numerique* Im): Preal(Re), Pimag(Im) {} //correspond à la construction avec  $ (voir sujet)
    void print(QTextStream& f)const;
    std::string toString()const;
    ~Complex(){};
    Complex operator +(Complex Cx) const;
    Complex operator  - (Complex Cx)const ;
    Complex operator * (Complex Cx) const ;
    Complex operator / (Complex Cx) const;
    bool IsReal() const {return !(Pimag);} //check si la partie imaginaire est nulle
    bool IsImag() const {return !(Preal);}

};




#endif // LITTERAL_H
