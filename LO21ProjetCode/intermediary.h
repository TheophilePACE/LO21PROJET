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
#include "litteral/litteral.h"
#include "litteral/atom.h"

/*Fichier contenant les définitions
    des classes intermédiaires entres littérales et structures de controle */

class Item {
    Litteral * lit;
public:
    Item(): lit(nullptr){}
    ~Item(){}
    void setLit(Litteral* l){lit = l;}
    Litteral* getPLit()const{return lit;}
    void raz() {lit=nullptr;}
};

class Identifier {
    Atom* lib;
    Litteral* value;
public:
    Identifier():lib(nullptr),value(nullptr){}
    void setLib(Atom* a){lib=a;}
    void setValue(Litteral* l){value = l;}
    void print(QTextStream& f)const{lib->print(f);}
    Atom* getLib()const{return lib;}
    Litteral* getPValue()const{return value;}
};

void ExceptionWindow(const char * s);
void CheckButtons();

#endif // INTERMEDIARY_H
