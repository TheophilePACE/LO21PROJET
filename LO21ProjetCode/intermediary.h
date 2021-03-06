#ifndef INTERMEDIARY_H
#define INTERMEDIARY_H

#include <string>
#include <iostream>
#include <stack>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <QList>
#include <QApplication>
#include <QCheckBox>
#include <QMainWindow>
#include "litteral/atom.h"

/*Fichier contenant les définitions
    des classes intermédiaires entres littérales et structures de controle */

class Litteral;

/*! \brief      Élement de base de la pile.
* Permet de stocker une littérale. La litterale peut être une Expression, un Numeric un Program un Complexe.
*/
class Item {
    ///Littérale pointée par l'Item
    Litteral * lit;
public:
    Item(): lit(nullptr){}
    ~Item(){}
    Item(Item& i){lit=i.lit;}
    void setLit(Litteral* l){lit = l;}
    Litteral* getPLit()const{return lit;}
    ///Remet à 0 le pointeur sur litteral
    void raz() {lit=nullptr;}
};

/*! \brief     Un identifier est une structure qui relie une littérale à son nom.
* L'atom permet de désigner une littérale par une QString. la valeur correspondant à cette QString est pointée par value.
* Les identifiers désignent des variables, des expressions ou des programmes.
*/
class Identifier {
    ///Libellé de la litteral
    Atom* lib;
    ///Valeur qui sera empilée quand on écrira la désignation.
    Litteral* value;
public:
    Identifier():lib(nullptr),value(nullptr){}
    ~Identifier(){}
    void setLib(Atom* a){lib=a;}
    void setValue(Litteral* l){value = l;}
    Atom* getLib()const{return lib;}
    Litteral* getPValue()const{return value;}
};

void ExceptionWindow(QString s);
void CheckButtons();

#endif // INTERMEDIARY_H
