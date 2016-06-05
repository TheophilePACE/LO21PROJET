#ifndef PARSER_H
#define PARSER_H

#include <QString>
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
    bool isOperatorUnary(QString s);
    static Parser& getInstance();
    static void freeInstance();
    std::string getType(QString s);
    bool isOperator(QString s);
    long getNum(QString s);
    long getDenum(QString s);
    long getInteger(QString s); //renvoie tout ce qu'il y a avant le .

    double getMantisse(QString s);
    float getFloat(QString s); //non implémentée
    QString getRealPart(QString s); //renvoie la premiereparti du ima
    QString getImPart(QString s);

};

#endif // PARSER_H
