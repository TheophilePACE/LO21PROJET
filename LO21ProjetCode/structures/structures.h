#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <string>
#include <iostream>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QSound>
#include <QDebug>
#include <QString>
#include <QStringList>
#include <QApplication>
#include "litteral/litteral.h"
#include "litteral/integer.h"
#include "litteral/real.h"
#include "litteral/program.h"
#include "generalManager.h"
#include "stack.h"

/*Fichier contenant les structures de controle*/

/*! \brief   Interface entre les différents manager.
* A travers la fonction command, le controller fait appel au parser pour déterminer l'action à mener,
* Il fait appel au GeneralManager s'il faut créer un nouvel élément ou aux operateurs s'il faut executer une opération.
*
*/

class Controller {
    ///Singleton qui crée les items ou les programmes ou encore les expressions.
    GeneralManager& genMng;
    ///Pointeur sur la pile actuellement utilisée. En effet, il en existe plusieurs (grâce aux snaphshots)
    Stack * stack;
    ///Structure de sauvegarde de la dernière opération.
    LastStruc * lastStruc;

public:

    Controller(GeneralManager& m,Stack * p):genMng(m), stack(p){lastStruc= new LastStruc;}
    ~Controller(){delete lastStruc;}
    ///Fonction centrale chargée de l'interprétation et de l'execution des entrées de l'utilisateur.
    void command(const QString& c);
    void setStack(Stack * s) {stack = s;}

};

#endif // STRUCTURES_H
