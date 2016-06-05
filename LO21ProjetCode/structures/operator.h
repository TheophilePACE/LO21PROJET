#ifndef OPERATOR_H
#define OPERATOR_H
#include "stack.h"
#include "../litteral/complex.h"


#include "structures/structures.h"

class OperatorAbstract {
public:
    virtual void loadOperand(Stack *s) = 0;
    virtual Litteral* execute( )=0;
};

class OperatorUnaire : public OperatorAbstract {
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
    void loadOperand (Stack *s);
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


class OperatorDiv : public OperatorBinary {
public:
    OperatorDiv(): OperatorBinary(){}
    Litteral* execute( );
};



#endif
