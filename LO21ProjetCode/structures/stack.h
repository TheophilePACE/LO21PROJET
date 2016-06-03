#ifndef STACK_H
#define STACK_H

#include <QObject>
#include <sstream>
#include "../intermediary.h"
class Stack : public QObject {
    Q_OBJECT

    Item* items;
    unsigned int nb;
    unsigned int nbMax;
    QString message;
    void increaseCap();
    unsigned int nbItemsDisplayed;
public:
    Stack():items(nullptr),nb(0),nbMax(0),message(""),nbItemsDisplayed(4){}
    ~Stack();
    void push(Item e);
    void pop();
    bool empty() const { return nb==0; }
    unsigned int size() const { return nb; }
    const std::string display() const;
    Litteral* top() const;
    void setNbItemsDisplayed(unsigned int n) { nbItemsDisplayed=n; }
    unsigned int getNbItemsDisplayed() const { return nbItemsDisplayed; }
    void setMessage(const QString& m) { message=m; stateModification(); }
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

signals:
    void stateModification();
};

#endif // STACK_H
