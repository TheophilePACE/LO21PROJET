#include "generalManager.h"
#include "litteral/rationnal.h"
#include "litteral/real.h"

GeneralManager::Singleton GeneralManager::sing=GeneralManager::Singleton();
GeneralManager& GeneralManager::getInstance(){
    if(sing.instance==nullptr) sing.instance = new GeneralManager;
    return *sing.instance;
}

void GeneralManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}

Item * GeneralManager::createItem(QString s) {
    Parser p = Parser::getInstance();
    std::string type = p.getType(s);
    if (type=="Integer")
    {
        Integer * newInt = new Integer(s.toInt());
        Item * It = new Item;
        It->setLit(newInt);
        return It;
    }
    if(type=="Rationnal")
    {
        Rationnal * newInt = new Rationnal(p.getNum(s),p.getDenum(s));
        Item * It = new Item;
        It->setLit(newInt);
        return It;
    }
    if(type=="Real")
    {
        Real * newReal = new Real(s.toFloat());
        Item * It = new Item;
        It->setLit(newReal);
        return It;
    }
    if(type=="Complex")
    {
        Real * newReal = new Real(405);
        Item * It = new Item;
        It->setLit(newReal);
        return It;
    }
        else
            throw "Erreur de type";
}
