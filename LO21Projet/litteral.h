#ifndef LITTERAL_H
#define LITTERAL_H

#include <string>
#include <iostream>
#include <stack>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>

class Litteral {
public:
    virtual void print(std::ostream& f)const=0;
    virtual ~Litteral(){}
};
class Item {
    Litteral * lit;
public:
    Item(): lit(nullptr){}
    void setLit(Litteral* l){lit = l;}
    Litteral* getPLit()const{return lit;}
};

class ExpressionMaterial : public Litteral {
public:
    virtual void print(std::ostream& f)const=0;
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
    void print(std::ostream& f)const;
};

class Program : public Litteral {
    std::string instructions;
public:
    Program(std::string s):instructions(s){}
    void print(std::ostream& f)const;
};

/*class GeneralManager {
    struct Singleton{
        GeneralManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    static GeneralManager& getInstance();
    static void freeInstance();
};*/

class ProgramManager {
    Program** programs;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    ProgramManager():programs(nullptr),nb(0),max(0){}
    ~ProgramManager(){}
    ProgramManager(const ProgramManager& m);
    ProgramManager& operator=(const ProgramManager& m);
    //friend class QComputer;
    struct Singleton{
        ProgramManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    void addProgram(std::string chaine);
    void removeProgram(Program& e);
    static ProgramManager& getInstance();
    static void freeInstance();
    class Iterator {
        friend class ProgramManager;
        Program** current;
        unsigned int nbRemain;
        Iterator(Program** u, unsigned nb):current(u),nbRemain(nb){}
    public:
        Iterator():current(nullptr),nbRemain(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw "error, next on an iterator which is done";
            nbRemain--;
            current++;
        }
        Program& getCurrent() const {
            if (isDone())
                throw "error, indirection on an iterator which is done";
            return **current;
        }
    };
    Iterator getIterator() {
        return Iterator(programs,nb);
    }
};

class Atom : public ExpressionMaterial {
    std::string lib;
public:
    Atom(std::string s):lib(s){}
    void print(std::ostream &f) const {f<<lib;}
    ~Atom(){}
};

class Identifier {
    Atom* lib;
    Litteral* value;
public:
    Identifier():lib(nullptr),value(nullptr){}
    void setLib(Atom a){lib=&a;}
    void setValue(Litteral* l){value = l;}
    void print(std::ostream& f)const{lib->print(f);}
    Litteral* getPValue()const{return value;}
};

class IdentifierManager {
    Identifier** identifiers;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    ~IdentifierManager(){}
    IdentifierManager(const IdentifierManager& m);
    IdentifierManager& operator=(const IdentifierManager& m);
    //friend class QComputer;
    struct Singleton{
        IdentifierManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    IdentifierManager():identifiers(nullptr),nb(0),max(0){}
    void addIdentifier(std::string s, Litteral* l);
    void removeIdentifier(Identifier& e);
    static IdentifierManager& getInstance();
    static void freeInstance();
    class Iterator {
        friend class IdentifierManager;
        Identifier** current;
        unsigned int nbRemain;
        Iterator(Identifier** u, unsigned nb):current(u),nbRemain(nb){}
    public:
        Iterator():current(nullptr),nbRemain(0){}
        bool isDone() const { return nbRemain==0; }
        void next() {
            if (isDone())
                throw "error, next on an iterator which is done";
            nbRemain--;
            current++;
        }
        Identifier& getCurrent() const {
            if (isDone())
                throw "error, indirection on an iterator which is done";
            return **current;
        }
    };
    Iterator getIterator() {
        return Iterator(identifiers,nb);
    }
};

class Controleur {
    //ExpressionManager& expMng;
    std::stack<Litteral>& expAff;
public:
    Controleur(/*ExpressionManager& m,*/std::stack<Litteral>& v):/*expMng(m),*/ expAff(v){}
    void commande(const QString& c);

};

bool estUnOperateur(const QString s);
bool estUnNombre(const QString s);


#endif // LITTERAL_H
