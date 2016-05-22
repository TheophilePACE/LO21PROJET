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
std::string floatToString(float f);
bool isOperator(const QString s);
bool isRationnal(const QString s);
bool isReal(const QString s);
bool isInteger(const QString s);
bool isNumber(const QString s);
bool isComplex(const QString s);
unsigned int pgcd(int a, int b);

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

//ressemble fortement à la classe ExpressionMaterial. Egalement virtuelle.
class Numeric : public ExpressionMaterial
{
public:
    //virtual Numeric& operator+ (const Numeric& N) const =0;
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual ~Numeric(){}
    //virtual Numeric& operator+ (Numeric* N1) =0;


};
//Classes concrètes

class Rationnal;

class Integer: public Numeric{
private:
    int val;
public:
    Integer(int integer=0): val(integer) {} //abs pour absolute value, c'est dans STD
    ~Integer() {}
    bool getSign() const {return val>=0;} //négatif == 0
    unsigned int getAbsoluteValue() const {return std::abs(val);}
    int getSignedValue() const {return val;}
    void print (QTextStream& f)const;
    std::string toString()const;
    int setValue(int integer) ;
    Integer operator+(Integer integer) const;
    Integer operator-(Integer integer)const ;
    Integer operator*(Integer integer) const ;
    Rationnal operator/(Integer integer) const;
    Integer NEG(){return -val;} //le retour permet une opération du type A+NEG(B)
};


class Rationnal : public Numeric {
private:
    int num;
    int denum;
public:
    const int&  getNum() const { return num;}
    const int&  getDenum() const { return denum;}
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
    bool isInteger () const;
    float getSignedValue() const {return num/denum;}

};

class Real : public Numeric {
private:
    int integer;
    float mantisse; //toujours entre 0 et 1.
public:
    bool simplify() ;
    float getSignedValue() const ;
    Real(float a): integer(static_cast<int>(truncf(a))), mantisse(a-truncf(a)){}
    Real(int in, float ma): integer(in), mantisse(ma) {} //ma est entre 0 et 1
    bool getSign() const {return integer>=0;} //négatif
    bool isInteger() const;
    void print(QTextStream& f)const;
    std::string toString()const;
    Real operator+(Real re) const;
    Real operator-(Real re)const ;
    Real operator*(Real re) const ;
    Real operator/(Real re) const;
    //~Real() {delete integer; delete ;} inutile
};

//OPERATIONS ENTRE NumericS DEFINIES

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

Numeric& operator+(const Numeric& N1, const Numeric& N2);

//TEMPLATE POUR ADDITION Numeric
/*template <class T1, class T2>
Numeric* addNum (T1* N1,T2* N2)
{
    Numeric * Rslt;
    Rslt=dynamic_cast<Numeric*>( &( *(N1) + *(N2) ) );
    return Rslt;
}
*/



class Complex : public ExpressionMaterial {
private:
    Numeric* pReal;
    Numeric* pImag;
public:
    Complex (Numeric* Re, Numeric* Im): pReal(Re), pImag(Im) {} //correspond à la construction avec  $ (voir sujet)
    void print(QTextStream& f)const;
    std::string toString()const;
    ~Complex(){}
    Complex operator+(Complex Cx) const;
    Complex operator-(Complex Cx)const ;
    Complex operator*(Complex Cx) const ;
    Complex operator/(Complex Cx) const;
    bool isReal() const {return !(pImag);} //check si la partie imaginaire est nulle
    bool isImag() const {return !(pReal);}

};

#endif // LITTERAL_H
