#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <iostream>
#include <stack>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include "litteral.h"
#include "intermediary.h"

/*Fichier contenant les structures de controle*/

class ComputerException {
    QString info;
public:
    ComputerException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

class Pile : public QObject {
    Q_OBJECT

    Item* items;
    unsigned int nb;
    unsigned int nbMax;
    QString message;
    void increaseCap();
    unsigned int nbItemsDisplayed;
public:
    Pile():items(nullptr),nb(0),nbMax(0),message(""),nbItemsDisplayed(4){}
    ~Pile();
    void push(Litteral* e);
    void pop();
    bool empty() const { return nb==0; }
    unsigned int size() const { return nb; }
    void display(QTextStream& f) const;
    Litteral* top() const;
    void setNbItemsDisplayed(unsigned int n) { nbItemsDisplayed=n; }
    unsigned int getNbItemsDisplayed() const { return nbItemsDisplayed; }
    void setMessage(const QString& m) { message=m; stateModification(); }
    QString getMessage() const { return message; }
    class iterator {
        Item* current;
        iterator(Item* u):current(u){}
        friend class Pile;
    public:
        iterator():current(nullptr){}
        Litteral* operator*() const { return current->getPLit(); }
        bool operator!=(iterator it) const { return current!=it.current; }
        iterator& operator++(){ --current; return *this; }
    };
    iterator begin() { return iterator(items+nb-1); }
    iterator end() { return iterator(items-1); }

    class const_iterator {
        Item* current;
        const_iterator(Item* u):current(u){}
        friend class Pile;
    public:
        const_iterator():current(nullptr){}
        const Litteral* operator*() const { return current->getPLit(); }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ --current; return *this; }
    };
    const_iterator begin() const { return const_iterator(items+nb-1); }
    const_iterator end() const { return const_iterator(items-1); }

signals:
    void stateModification();
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

class Controller {
    //ExpressionManager& expMng;
    Pile& stack;
public:
    Controller(/*ExpressionManager& m,*/Pile& p):/*expMng(m),*/ stack(p){}
    void command(const QString& c);

};

#endif // STRUCTURES_H
