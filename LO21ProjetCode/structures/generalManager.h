#ifndef GENERALMANAGER_H
#define GENERALMANAGER_H

#include "parser.h"
#include "../intermediary.h"

class GeneralManager {
    struct Singleton{
        GeneralManager* instance;
        Singleton():instance(nullptr){}
        ~Singleton(){ delete instance; }
    };
    static Singleton sing;
public:
    static GeneralManager& getInstance();
    static void freeInstance();
    Item * createItem(QString s);
    Item * createSimpleItem(QString s); //factoriser la création de numeric
    std::string getTypeLit(QString s);
};

#endif // GENERALMANAGER_H
