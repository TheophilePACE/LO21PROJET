#ifndef LITTERAL_H
#define LITTERAL_H

#include <string>
#include <iostream>
#include <stack>

class Item {
    Litteral * lit;
public:
    Item(): lit(nullptr){}
    void setLit(Litteral l){lit = &l;}
    Litteral getLit()const{return &lit;}
};


class Litteral {
public:
    void print(ostream& f)const=0;
};


class Expression : public Litteral {
    ExpressionMaterial ** tab;
    unsigned int nb;
    unsigned int max;
public:
    Expression(): tab(nullptr), nb(0),max(0){}
    ~Expression(){nb = 0; max = 0; delete[] tab;}
    void increaseCap();
    void operator<<(Expression e);
    void print(ostream& f)const;
};

class Program : public Litteral {
    std::string instructions;
public:
    Program(std::string s):instructions(s){}
    void print(ostream& f)const;
};
/*
class GeneralManager {
public:

};*/

class ProgramManager {
    Program** programs;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    ProgramManager():programs(nullptr),nb(0),max(0){}
    ~ProgramManager();
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
                throw ComputerException("error, next on an iterator which is done");
            nbRemain--;
            current++;
        }
        Program& current() const {
            if (isDone())
                throw ComputerException("error, indirection on an iterator which is done");
            return **current;
        }
    };
    Iterator getIterator() {
        return Iterator(programs,nb);
    }
};

class ExpressionMaterial : public Litteral {
public:
    void print(ostream& f)const=0;
};
class Atom : public ExpressionMaterial {
    std::string lib;
public:
    Atom(std::string s):lib(s){}
    void print(ostream &f) const {f<<lib;}
};

class Identifier {
    Atom* lib;
    Litteral* value;
public:
    Identifier():lib(nullptr),value(nullptr){}
    void setLib(Atom a){lib=&a;}
    void setValue(Litteral l){value = &l;}
    void print(ostream& f)const{lib->print(f);}
    Litteral getValue()const{return *value;}
};

class IdentifierManager {
    Identifier** identifiers;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    IdentifierManager():identifiers(nullptr),nb(0),max(0){}
    ~IdentifierManager();
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
    void addIdentifier(Identifier p);
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
                throw ComputerException("error, next on an iterator which is done");
            nbRemain--;
            current++;
        }
        Identifier& current() const {
            if (isDone())
                throw ComputerException("error, indirection on an iterator which is done");
            return **current;
        }
    };
    Iterator getIterator() {
        return Iterator(identifiers,nb);
    }
};




#endif // LITTERAL_H
