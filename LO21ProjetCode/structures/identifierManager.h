#ifndef IDENTIFIERMANAGER_H
#define IDENTIFIERMANAGER_H

#include "structures.h"

class IdentifierManager {
    Identifier** identifiers;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    IdentifierManager():identifiers(nullptr),nb(0),max(0){}
    IdentifierManager& operator=(const IdentifierManager& m);
    //friend class QComputer;
    struct Singleton{
        IdentifierManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    ~IdentifierManager(){}
    IdentifierManager(const IdentifierManager& m);
    void addIdentifier(std::string s, Litteral* l);
    void removeIdentifier(Identifier& e);
    Identifier * getIdentifier(Atom& a) const;
    const std::string displayVar() const;
    const std::string displayProg() const;
    unsigned int size() const {return nb;}
    unsigned int sizeAtoms() const;
    static IdentifierManager& getInstance();
    static void setInstance(IdentifierManager * id);
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
    Iterator getIterator() const {
        return Iterator(identifiers,nb);
    }
};

#endif // IDENTIFIERMANAGER_H
