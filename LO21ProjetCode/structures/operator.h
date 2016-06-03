#ifndef OPERATOR_H
#define OPERATOR_H
#include "structures/stack.h"
#include "stack.h"
#include "complex.h"


#include "structures/structures.h"

class OperatorAbstract {
public:
    virtual void loadOperand(Stack *s) = 0;
    virtual Litteral* execute(Stack *s)=0;
};

class OperatorUnaire : public OperatorAbstract {
protected:
    Litteral * l1;
public:
    void loadOperand(Stack *s);
    virtual Litteral* execute(Stack *s)=0;
};

class OperatorBinary : public OperatorAbstract {
protected:
    Litteral * l1;
    Litteral * l2;
public:
    OperatorBinary(): l1(nullptr),l2(nullptr){}
    void loadOperand (Stack *s);
    virtual Litteral* execute(Stack *s)=0;
};

class OperatorSum : public OperatorBinary {
public:
    OperatorSum(): OperatorBinary(){}
    Litteral* execute(Stack *s);
};





#endif
