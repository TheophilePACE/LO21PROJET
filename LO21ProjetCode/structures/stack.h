#ifndef STACK_H
#define STACK_H

#include <QObject>
#include <sstream>
#include "../intermediary.h"
#include "computerException.h"

/*! \name      La Stack ets la structure chargé de stocker les items. Elle est géré en FILO.
* La création des items est gérée par le GeneralManager, la pile ne fait que les stocker.
*
*/

class Stack {
    QString message;
    unsigned int nbItemsDisplayed;
    /*! \name     Attributs classiques de gestion de la pile :
    */
    //@{
    Item* items;
    unsigned int nb;
    unsigned int nbMax;
    //@}
    void increaseCap();
public:
    Stack():items(nullptr),nb(0),nbMax(0),message(""),nbItemsDisplayed(4){}
    Stack(const Stack& s);
    ~Stack();
    /*! \name     Méthodes classiques de gestion de la pile :
    */
    //@{
    void push(Item e);
    void pop();
    bool empty() const { return nb==0; }
    unsigned int size() const { return nb; }
    Litteral* top() const;
    //@}
    ///Renvoie la pile sous forme d'une string où les éléments sont séparées par _
    const QString display() const;
    ///Changer le nombre d'item afficher dans la pile (sur l'interface).
    void setNbItemsDisplayed(unsigned int n) { nbItemsDisplayed=n; }
    unsigned int getNbItemsDisplayed() const { return nbItemsDisplayed; }
    void setMessage(const QString& m) { message=m; }
    QString getMessage() const { return message; }
    class iterator {
        Item* current;
        iterator(Item* u):current(u){}
        friend class Stack;
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
        friend class Stack;
    public:
        const_iterator():current(nullptr){}
        const Litteral* operator*() const { return current->getPLit(); }
        bool operator!=(const_iterator it) const { return current!=it.current; }
        const_iterator& operator++(){ --current; return *this; }
    };
    const_iterator begin() const { return const_iterator(items+nb-1); }
    const_iterator end() const { return const_iterator(items-1); }
};

/*! \name   Classe servant pour les operateurs last(LASTARGS et LASTOP)
* A chaque opération réalisée, le controller s'assure que les (ou le) opérandes utilisé(s) pour cette opération, ainsi que l'opérateur, soit conservés.
* LastStruc garde donc une copie du ou des derniers items utilisés ainsi qu'un QString correspondant à l'opérateur.
*/
class LastStruc {
    Item * item1;
    Item * item2;
    QString ope;
public:
    LastStruc():  ope("") {item1 = new Item;item1->setLit(nullptr); item2 = new Item;item2->setLit(nullptr); }
    ~LastStruc(){delete item1; delete item2;}
    ///En cas d'utilisation d'un operateur UNaire charge la litterale et l'operateur
    void getOpe1(Stack* s,QString op);
    ///En cas d'utilisation d'un operateur Binaire charge les litterales et l'operateur
    void getOpe2(Stack* s,QString op);
    ///Rempile les items stockés
    void lastArgu (Stack* s);
    ///Réexcute le dernier operateur
    QString lastOpe () const ;
};

#endif // STACK_H
