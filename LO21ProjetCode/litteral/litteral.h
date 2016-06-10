#ifndef LITTERAL_H
#define LITTERAL_H

#include <string>
#include <iostream>
#include <stack>
#include <QString>
#include <QTextStream>
#include <QObject>
#include <QDebug>
#include <math.h>
#include <cmath>        // pour std::abs
#include "../structures/generalManager.h"

QString toQString(std::string s);
std::string doubleToString(double f);
unsigned int pgcd(int a, int b);

//! Classe utilisée sous forme de pointeur. Pointeur  les plus généraux de la calculette. Pointe vers tout objet pouvant être évalué en un nombre (complexe, numerique, expression ou programme).
//! Cette classe abstraite sert principalement à la manipulation des éléments de la pile ou des expressions / propgrammes. Les pointeurs sur littéral servent à la manipulation des classes filles.
//!
class Litteral {
public:
    ///La création et la destruction d'une littérale est gérée par le General Manager. Le constructeur fait donc explicitememnt à la fonction add litteral de ce dernier.
    Litteral(){(&(GeneralManager::getInstance()))->addLitteral(this);}
     /*! Ces fonctions sont redéfinies dans les classes filles. Elles permettent d'uniformiser l'affichage des éléments présents dans la pile. */
    //@{
    virtual void print(QTextStream& f)const=0;
    virtual std::string toString()const=0;
    virtual QString toQStringPars()const=0;
    //@}
    virtual ~Litteral(){(&(GeneralManager::getInstance()))->removeLitteral(this);}
};

#endif // LITTERAL_H
