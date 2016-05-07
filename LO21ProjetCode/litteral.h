#ifndef LITTERAL_H
#define LITTERAL_H


#include <string>
#include <iostream>
#include <stack>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

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
class Rationnal;

class Integer: public Numerique{
private:
    unsigned int val;
    bool sign; //0 --> negatif, 1 --> positif. 0 considéré comme positif
public:
    Integer(int entier=0): val(std::abs(entier)),sign(entier>=0) {} //abs pour absolute value, c'est dans STD
    ~Integer() {}
    bool getSign() const {return sign;} //négatif 
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
};


class Rationnal : public Numerique {
private:
    Integer num;
    Integer denum;
public:
    Rationnal(Integer N, Integer D ): num(N), denum(D) {simplify();} //utile en cas de division. Comment gérer le retour?
    Rationnal(int a, int b); //Attention au simplicification
    void print(QTextStream& f)const;
    std::string toString()const;
    Numerique* simplify() ; //retour de type pointeur sur classe mere
    Rationnal operator +(Rationnal frac) const;
    Rationnal operator- (Rationnal frac)const ;
    Rationnal operator * (Rationnal frac) const ;
    Rationnal operator / (Rationnal frac) const;
    bool getSign() const {return (num.getSign()==denum.getSign());}

    
};


#endif // LITTERAL_H
