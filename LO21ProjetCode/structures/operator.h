#ifndef OPERATOR_H
#define OPERATOR_H
#include "stack.h"
#include "../litteral/complex.h"
#include "identifierManager.h"
#include "parser.h"


#include "structures/structures.h"

class OperatorAbstract {
public:
    virtual void loadOperand(Stack *s) = 0;
    virtual Litteral* execute( )=0;
};

class OperatorUnary : public OperatorAbstract {
protected:
    Litteral * l1;
public:
    void loadOperand(Stack *s);
    virtual Litteral* execute( )=0;
};

class OperatorBinary : public OperatorAbstract {
protected:
    Litteral * l1;
    Litteral * l2;
public:
    OperatorBinary(): l1(nullptr),l2(nullptr){}
    virtual void loadOperand (Stack *s);
    virtual Litteral* execute( )=0;
};

class OperatorSum : public OperatorBinary {
public:
    OperatorSum(): OperatorBinary(){}
    Litteral* execute( );
};

class OperatorSub : public OperatorBinary {
public:
    OperatorSub(): OperatorBinary(){}
    Litteral* execute( );
};

class OperatorMul : public OperatorBinary {
public:
    OperatorMul(): OperatorBinary(){}
    Litteral* execute( );
};


class  OperatorDivision : public OperatorBinary {
public:
     OperatorDivision(): OperatorBinary(){}
    Litteral* execute( );
};

class  OperatorDiv : public OperatorBinary {
public:
     OperatorDiv(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);

};


class  OperatorMod : public OperatorBinary {
public:
     OperatorMod(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);

};

class  OperatorSupS : public OperatorBinary {
public:
     OperatorSupS(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);

};
class  OperatorSupE : public OperatorBinary {
public:
     OperatorSupE(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);

};
class  OperatorLessS : public OperatorBinary {
public:
     OperatorLessS(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);

};
class  OperatorLessE : public OperatorBinary {
public:
     OperatorLessE(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);

};

class  OperatorEqu : public OperatorBinary {
public:
     OperatorEqu(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);

};

class  OperatorNEqu : public OperatorBinary {
public:
     OperatorNEqu(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};

class  OperatorCplx : public OperatorBinary {
public:
     OperatorCplx(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};

class  OperatorAND : public OperatorBinary {
public:
     OperatorAND(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};
class  OperatorSTO : public OperatorBinary {
public:
    OperatorSTO(): OperatorBinary(){}
    Litteral * execute();
    void loadOperand(Stack *s);
};
class  OperatorOR : public OperatorBinary {
public:
     OperatorOR(): OperatorBinary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};
//OPE UNAIRE
class  OperatorNOT : public OperatorUnary {
public:
    OperatorNOT(): OperatorUnary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};

class  OperatorNEG : public OperatorUnary {
public:
    OperatorNEG(): OperatorUnary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};

class  OperatorNUM : public OperatorUnary {
public:
    OperatorNUM(): OperatorUnary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};

class  OperatorDEN : public OperatorUnary {
public:
    OperatorDEN(): OperatorUnary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};

class  OperatorIM : public OperatorUnary {
public:
    OperatorIM(): OperatorUnary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};

class  OperatorRE : public OperatorUnary {
public:
    OperatorRE(): OperatorUnary(){}
    Litteral* execute( );
    void loadOperand(Stack *s);
};


#endif
