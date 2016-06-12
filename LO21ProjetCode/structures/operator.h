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

class OperatorAbstract {
public:
    virtual void loadOperand(Stack *s) = 0;
    virtual Litteral* execute( )=0;
    virtual void verify(Stack * s) =0 ;

};

class OperatorUnary : public OperatorAbstract {
protected:
    Litteral * l1;
public:
    void loadOperand(Stack *s);
    virtual Litteral* execute( )=0;
    virtual void verify(Stack * s) =0 ;
};


class OperatorBinary : public OperatorAbstract {
protected:
    Litteral * l1;
    Litteral * l2;
public:
    OperatorBinary(): l1(nullptr),l2(nullptr){}
    void loadOperand (Stack *s);
    virtual Litteral* execute( )=0;
    virtual void verify(Stack * s) =0 ;
};

class OperatorSum : public OperatorBinary {
public:

    OperatorSum(): OperatorBinary(){}
        Litteral* execute( );
             void verify(Stack * s);
};

class OperatorSub : public OperatorBinary {
public:

    OperatorSub(): OperatorBinary(){}
    Litteral* execute( );
         void verify(Stack * s);

};

class OperatorMul : public OperatorBinary {
public:

    OperatorMul(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);
};


class  OperatorDivision : public OperatorBinary {
public:

     OperatorDivision(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);
};

class  OperatorDiv : public OperatorBinary {
public:
     OperatorDiv(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);


};


class  OperatorMod : public OperatorBinary {
public:
     OperatorMod(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);


};

class  OperatorSupS : public OperatorBinary {
public:
     OperatorSupS(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);


};
class  OperatorSupE : public OperatorBinary {
public:
     OperatorSupE(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);


};
class  OperatorLessS : public OperatorBinary {
public:
     OperatorLessS(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);


};
class  OperatorLessE : public OperatorBinary {
public:
     OperatorLessE(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);


};

class  OperatorEqu : public OperatorBinary {
public:
     OperatorEqu(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);


};

class  OperatorNEqu : public OperatorBinary {
public:
     OperatorNEqu(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorCplx : public OperatorBinary {
public:
     OperatorCplx(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorAND : public OperatorBinary {
public:
     OperatorAND(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);

};
class  OperatorSTO : public OperatorBinary {
public:
    OperatorSTO(): OperatorBinary(){}
    Litteral * execute();
    void verify(Stack * s);


};
class  OperatorOR : public OperatorBinary {
public:
     OperatorOR(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);

};
//OPE UNAIRE
class  OperatorNOT : public OperatorUnary {
public:
    OperatorNOT(): OperatorUnary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorNEG : public OperatorUnary {
public:
    OperatorNEG(): OperatorUnary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorNUM : public OperatorUnary {
public:
    OperatorNUM(): OperatorUnary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorDEN : public OperatorUnary {
public:
    OperatorDEN(): OperatorUnary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorIM : public OperatorUnary {
public:
    OperatorIM(): OperatorUnary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorRE : public OperatorUnary {
public:
    OperatorRE(): OperatorUnary(){}
        Litteral* execute( );
      void verify(Stack * s);

};
class  OperatorEVAL : public OperatorUnary {
    Controller * ctrl;
public:
    OperatorEVAL(Controller * c): OperatorUnary(), ctrl(c){}

        Litteral* execute( );
      void verify(Stack * s);
};
class  OperatorFORGET : public OperatorUnary {
public:
    OperatorFORGET(): OperatorUnary(){}

        Litteral* execute( );
      void verify(Stack * s);
};
class  OperatorEDIT : public OperatorUnary {
public:
    OperatorEDIT(): OperatorUnary(){}

        Litteral* execute( );
      void verify(Stack * s);
};


class  OperatorCLEAR : public OperatorUnary {
public:
    OperatorCLEAR(): OperatorUnary(){}
        Litteral* execute( );
      void verify(Stack * s);

};

class  OperatorIFT : public OperatorBinary {
public:
    OperatorIFT(): OperatorBinary(){}
        Litteral* execute( );
      void verify(Stack * s);
};

#endif
