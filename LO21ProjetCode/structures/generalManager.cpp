#include "generalManager.h"
#include "litteral/rationnal.h"
#include "litteral/real.h"
#include "litteral/complex.h"

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
    if(type=="Integer"||type=="Rationnal"||type=="Real")
        return createSimpleItem(s); //creation numeric

    if(type=="Complex")
    {
//        Item* tempR, *tempI;
        Item* itRe= createSimpleItem(p.getRealPart(s));
        Item* itIm = createSimpleItem(p.getImPart(s));
        Complex * newCplx = new Complex(dynamic_cast<Numeric *>(itRe->getPLit()),dynamic_cast<Numeric *>(itIm->getPLit()));

        Item * It = new Item;
        It->setLit(newCplx);
        return It;
    }
        else
            throw "Erreur de type";
}

Item *  GeneralManager::createSimpleItem(QString s) //factoriser la création de numeric
{
    Parser p = Parser::getInstance();
    std::string type = p.getType(s);
    if (type=="Integer")
    {

        Integer * newInt = new Integer(p.getInteger(s));
        Item * It = new Item;
        It->setLit(newInt);
        return It;
    }
    if(type=="Rationnal")
    {
        Rationnal * newRat = new Rationnal(p.getNum(s),p.getDenum(s));
        if(newRat->isInteger()) //simplification vers integer
        {
            long val = newRat->getNum();
            delete newRat;
            Integer * newRat = new Integer(val);

        }
        Item * It = new Item;
        It->setLit(newRat);
        return It;
    }
    if(type=="Real")
    {
        Real * newReal = new Real(s.toDouble());
        Item * It = new Item;
        It->setLit(newReal);
        return It;
    }
    else
        throw "Erreur de type";
}
