#ifndef GENERALMANAGER_H
#define GENERALMANAGER_H

#include "parser.h"
#include "../intermediary.h"

class GeneralManager {
    Litteral** litterals;
    unsigned int nb;
    unsigned int max;
    void increaseCap();
    GeneralManager():litterals(nullptr),nb(0),max(0){}
    struct Singleton{
        GeneralManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    static GeneralManager& getInstance();
    void addLitteral(Litteral * const);
    ~GeneralManager();
    static void freeInstance();
    Item * createItem(QString s);
    Item * createProgram(QString s);
    Item * createSimpleItem(QString s); //factoriser la création de numeric
    std::string getTypeLit(QString s);
};

#endif // GENERALMANAGER_H
