#ifndef PARSER_H
#define PARSER_H

#include <QString>
#include <QStringList>
#include <string>

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
    bool isOperatorBinary(QString s);
    bool isOperatorUnary(QString s);
    long getNum(QString s);
    long getDenum(QString s);
    long getInteger(QString s); //renvoie tout ce qu'il y a avant le .

    double getMantisse(QString s);
    float getFloat(QString s); //non implémentée
    QString getRealPart(QString s); //renvoie la premiereparti du ima
    QString getImPart(QString s);

};

bool isRationnal(const QString s);
bool isReal(const QString s);
bool isInteger(const QString s);
bool isNumber(const QString s);
bool isComplex(const QString s);
bool isAtom(const QString s);
bool isExpression(const QString s);
bool isProgram(const QString s);

#endif // PARSER_H
