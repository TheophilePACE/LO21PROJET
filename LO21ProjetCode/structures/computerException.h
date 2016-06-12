#ifndef COMPUTEREXCEPTION_H
#define COMPUTEREXCEPTION_H

#include <QString>
/*!
 * \brief The ComputerException class : classes permettent de gérer l'ensemble des exceptions.
 * Ces execptions sont redirigées vers la zône de texte au dessus de la pile (dans la vue calculette) ou dans des messages fenetrés (édition de programme).
 */
class ComputerException {
    QString info;
public:
    ///Constructeur. Permet l'affectation depuis une QString que l'on affichera.
    ComputerException(const QString& str):info(str){}
    QString getInfo() const { return info; }
};

#endif // COMPUTEREXCEPTION_H

