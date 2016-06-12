#ifndef IDENTIFIERMANAGER_H
#define IDENTIFIERMANAGER_H

#include "structures.h"
#include "computerException.h"

/*! \name       L'IdentifierManager gère les Identifier au sein d'un snapshot.
* Ce manager conserve un tableau des identifiers présent dans un snapshot.
* Il existe un IdentifierManager par snapshot.
*/
class IdentifierManager {
    ///Tableau des identifiers présents dans le snapshot.
    Identifier** identifiers;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    IdentifierManager():identifiers(nullptr),nb(0),max(0){}
    ///Interdiction de la recopie d'un Identifier manager : il faut éviter les partages d'identifiers. On utilisera le constructeur de recopie.
    IdentifierManager& operator=(const IdentifierManager& m);
    struct Singleton{
        IdentifierManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    ~IdentifierManager();
    IdentifierManager(const IdentifierManager& m);
    void addIdentifier(QString s, Litteral* l);
    void removeIdentifier(Identifier& e);
    Identifier * getIdentifier(Atom& a) const;
    const QString displayVar() const;
    const QString displayProg() const;
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
                throw ComputerException("Erreur : Itérateur Terminé");
            nbRemain--;
            current++;
        }
        Identifier& getCurrent() const {
            if (isDone())
                throw ComputerException("Erreur : Itérateur Terminé");
            return **current;
        }
    };
    Iterator getIterator() const {
        return Iterator(identifiers,nb);
    }
};

#endif // IDENTIFIERMANAGER_H
