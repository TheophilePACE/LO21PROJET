#ifndef STACK_H
#define STACK_H

#include <QObject>
#include <sstream>
#include "../intermediary.h"
#include "computerException.h"

class Stack {

    Item* items;
    unsigned int nb;
    unsigned int nbMax;
    QString message;
    void increaseCap();
    unsigned int nbItemsDisplayed;
public:
    Stack():items(nullptr),nb(0),nbMax(0),message(""),nbItemsDisplayed(4){}
    Stack(const Stack& s);
    ~Stack();
    void push(Item e);
    void pop();
    bool empty() const { return nb==0; }
    unsigned int size() const { return nb; }
    const QString display() const;
    Litteral* top() const;
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


//class pour les operateurs last
class LastStruc {
    Item * item1;
    Item * item2;
    QString ope;
public:
    LastStruc():  ope("") {item1 = new Item;item1->setLit(nullptr); item2 = new Item;item2->setLit(nullptr); }
    ~LastStruc(){delete item1; delete item2;}
    void getOpe1(Stack* s,QString op);
    void getOpe2(Stack* s,QString op);
    void lastArgu (Stack* s);
    QString lastOpe () const ;
};

#endif // STACK_H
