#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "litteral/integer.h"

class Parser {
    struct Singleton{
        Parser* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    static Parser& getInstance();
    static void freeInstance();
    std::string getType(QString s);
    bool isOperator(QString s);
    Integer getNum(QString s);
    Integer getDenum(QString s);
    Integer getInteger(QString s);
    float getMantisse(QString s);
    float getFloat(QString s);
    Integer getRealPart(QString s);
    Integer getImPart(QString s);
};

#endif // PARSER_H
