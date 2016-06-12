#ifndef OPERATOR_H
#define OPERATOR_H
#include "stack.h"
#include "../litteral/complex.h"
#include "identifierManager.h"
#include "parser.h"
#include "../litteral/litteral.h"
#include "structures/structures.h"
#include "shunting_yard_algorithm.h"
#include "qprogrameditor.h"
#include "mainwindow.h"

/*! \brief Classe mère de tous les operateurs
 * Les 4 méthodes sont les seules méthodes à implémenter pour un opérateur. Elle définissent une architecture pour les opérateurs.
 *
 */
class OperatorAbstract {
public:
    ///En cas de problème avec les littérales dépilées, cette fonction permet de rempiler la ou les littérales sur la pile.
    virtual void unLoadOperand(Stack *s) = 0;
    ///Dépile suffisament de littérales puis fait appel à correctType qui vérifie que les littérales correspondent aux types attendus.
    virtual void loadOperand(Stack *s) = 0;
    ///Réalise l'action de l'opérateur à proprement parler. Cette méthode utilise donc les littérales.
    virtual Litteral* execute( )=0;
    ///Vérifie que les littérales récupéres correspond(ent) bien au(x) type(s) attendu(s). Si ce n'est pas la cas, la fonction appelle unLoadOperand.
    virtual void correctType(Stack * s) =0 ;

};

/*! \brief Classe mère de tous les opérateurs Unaires
 * Les méthodes unLoadOperand et loadOperand sont codées ici car elles sont communes à tous les opérateurs unaires. elles ne sont donc pas virtuelles.
 * Les méthodes execute et correctType dépendent de chaque opérateur, elles seront implémentées dans les classes filles.
 *
 */
class OperatorUnary : public OperatorAbstract {
protected:
    ///L'objet que va manipuler l'opérateur.
    Litteral * l1;
public:
    ///Rempile un Item pointant sur l1.
    void unLoadOperand(Stack *s);
    ///Charge le premier élément sur pile.
    void loadOperand(Stack *s);
    virtual Litteral* execute( )=0;
    virtual void correctType(Stack * s) =0 ;
};

/*! \brief Classe mère de tous les operateurs Binaires
 * Les méthodes unLoadOperand et loadOperand sont codées ici car elles sont communes à tous les opérateurs binaires. elles ne sont donc pas virtuelles.
 * Les méthodes execute et correctType dépendent de chaque opérateur, elles seront implémentées dans les classes filles.
 *
 */
class OperatorBinary : public OperatorAbstract {
protected:
    Litteral * l1;
    Litteral * l2;
public:
    OperatorBinary(): l1(nullptr),l2(nullptr){}
    ///Rempile 2 Item pointant sur l1 et l2.
    void unLoadOperand(Stack *s);
    ///Dépile les 2 premiers éléments sur la pile.
    void loadOperand (Stack *s);
    virtual Litteral* execute( )=0;
    virtual void correctType(Stack * s) =0 ;
};

class OperatorSum : public OperatorBinary {
public:

    OperatorSum(): OperatorBinary(){}
        Litteral* execute( );
             void correctType(Stack * s);
};

class OperatorSub : public OperatorBinary {
public:

    OperatorSub(): OperatorBinary(){}
    Litteral* execute( );
         void correctType(Stack * s);

};

class OperatorMul : public OperatorBinary {
public:

    OperatorMul(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);
};


class  OperatorDivision : public OperatorBinary {
public:

     OperatorDivision(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);
};

class  OperatorDiv : public OperatorBinary {
public:
     OperatorDiv(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);


};


class  OperatorMod : public OperatorBinary {
public:
     OperatorMod(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);


};

class  OperatorSupS : public OperatorBinary {
public:
     OperatorSupS(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);


};
class  OperatorSupE : public OperatorBinary {
public:
     OperatorSupE(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);


};
class  OperatorLessS : public OperatorBinary {
public:
     OperatorLessS(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);


};
class  OperatorLessE : public OperatorBinary {
public:
     OperatorLessE(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);


};

class  OperatorEqu : public OperatorBinary {
public:
     OperatorEqu(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);


};

class  OperatorNEqu : public OperatorBinary {
public:
     OperatorNEqu(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorCplx : public OperatorBinary {
public:
     OperatorCplx(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorAND : public OperatorBinary {
public:
     OperatorAND(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};
class  OperatorSTO : public OperatorBinary {
public:
    OperatorSTO(): OperatorBinary(){}
    Litteral * execute();
    void correctType(Stack * s);


};
class  OperatorOR : public OperatorBinary {
public:
     OperatorOR(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};
//OPE UNAIRE
class  OperatorNOT : public OperatorUnary {
public:
    OperatorNOT(): OperatorUnary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorNEG : public OperatorUnary {
public:
    OperatorNEG(): OperatorUnary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorNUM : public OperatorUnary {
public:
    OperatorNUM(): OperatorUnary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorDEN : public OperatorUnary {
public:
    OperatorDEN(): OperatorUnary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorIM : public OperatorUnary {
public:
    OperatorIM(): OperatorUnary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorRE : public OperatorUnary {
public:
    OperatorRE(): OperatorUnary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};
class  OperatorEVAL : public OperatorUnary {
    Controller * ctrl;
public:
    OperatorEVAL(Controller * c): OperatorUnary(), ctrl(c){}

        Litteral* execute( );
      void correctType(Stack * s);
};
class  OperatorFORGET : public OperatorUnary {
public:
    OperatorFORGET(): OperatorUnary(){}

        Litteral* execute( );
      void correctType(Stack * s);
};
class  OperatorEDIT : public OperatorUnary {
public:
    OperatorEDIT(): OperatorUnary(){}

        Litteral* execute( );
      void correctType(Stack * s);
};


class  OperatorCLEAR : public OperatorUnary {
public:
    OperatorCLEAR(): OperatorUnary(){}
        Litteral* execute( );
      void correctType(Stack * s);

};

class  OperatorIFT : public OperatorBinary {
public:
    OperatorIFT(): OperatorBinary(){}
        Litteral* execute( );
      void correctType(Stack * s);
};

#endif
