#ifndef COMPUTEREXCEPTION_H
#define COMPUTEREXCEPTION_H

#include <QString>
/*!
 * \brief The ComputerException class : classes permettnt de générer l'ensemble des exceptions.
 * Ces execptions sont redirigées vers la zône de texte au dessus de la pile.
 */
class ComputerException {
    QString info;
public:
    ///Constructeur. Permet l'affectation depuis une QString que l'on throw.
    ComputerException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

#endif // COMPUTEREXCEPTION_H

