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
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual ~Numerique(){}
};


//Classes concrètes


//Abandon de la classe Integer au profit de int :
/*
class Rationnal;
class Integer: public Numerique{
private:
    unsigned int val;
    bool sign; //0 --> negatif, 1 --> positif. 0 considéré comme positif
public:
    Integer(int entier=0): val(std::abs(entier)),sign(entier>=0) {} //abs pour absolute value, c'est dans STD
    ~Integer() {}
    bool getSign() const {return sign;} //négatif == 0
    unsigned int getAbsoluteValue() const {return val;}
    int getSignedValue() const {return (getSign()*getAbsoluteValue());}
    void print (QTextStream& f)const;
    std::string toString()const;
    int setValue(int entier) ;
    Integer operator +(Integer entier) const;
    Integer operator- (Integer entier)const ;
    Integer operator * (Integer entier) const ;
    Rationnal operator / (Integer entier) const;
    Integer NEG(){sign= !sign;
        return *this;} //le retour permet une opération du type A+NEG(B)
};*/


class Rationnal : public Numerique {
private:
    int num;
    int denum;
public:
    Rationnal(int N, int D ): num(N), denum(D) {simplify();} //utile en cas de division. Comment gérer le retour?
    //Rationnal(int a, int b); //Attention au simplicifications
    void print(QTextStream& f)const;
    std::string toString()const;
    Rationnal simplify() ; //retour de type pointeur sur classe mere
    Rationnal operator +(Rationnal frac) const;
    Rationnal operator- (Rationnal frac)const ;
    Rationnal operator * (Rationnal frac) const ;
    Rationnal operator / (Rationnal frac) const;
    bool getSign() const {return ((num>=0)==(denum>=0));}
    bool IsInteger () const;


    
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

class Complex : public ExpressionMaterial {
private:
    Numerique* Preal;
    Numerique* Pimag;
public:
    Complex (Numerique* Re, Numerique* Im): Preal(Re), Pimag(Im) {} //correspond à la construction avec  $ (voir sujet)
    void print(QTextStream& f)const;
    std::string toString()const;
    ~Complex(){};
    Complex operator +(Complex re) const;
    Complex operator  - (Complex re)const ;
    Complex operator * (Complex re) const ;
    Complex operator / (Complex re) const;
    //bool IsReal() const {return (Pimag->getSignedValue);}


};


#endif // LITTERAL_H
