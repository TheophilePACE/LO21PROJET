#include "structures/generalManager.h"
#include "structures/identifierManager.h"
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
Item * GeneralManager::createProgram(QString s){
    Program * newProg = new Program(s.toStdString());
    Item * It = new Item;
    It->setLit(newProg);
    return It;
}

Item * GeneralManager::createItem(QString s) {
    Parser p = Parser::getInstance();


    std::string type = p.getType(s);
    if(type=="Integer"||type=="Rationnal"||type=="Real"||type=="Atom"||type=="Expression")
        return createSimpleItem(s); //creation numeric
    if(type=="Complex")
    {
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
            Item * It = new Item;
            It->setLit(newRat);
            return It;
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
    if(type=="Atom")
    {
        if(isOperator(s))
        {
            throw "C'est un operateur bordel";
        }
        else
        {
            Identifier * id = IdentifierManager::getInstance().getIdentifier(*(new Atom(s.toStdString())));
            if(id==NULL)
            {
                Expression * newExp = new Expression(s.insert(0,'\'').insert(s.size()+1,'\'').toStdString());
                Item * It = new Item;
                It->setLit(newExp);
                return It;
            }
            else
            {
                std::string type2 = typeid((*id->getPValue())).name();
                if(type2=="Program")
                {
                    //Controller::getInstance().command(id.getPValue()->toString());
                    return NULL;
                }

                else if(type2=="Integer" || type2=="Rationnal" || type2=="Complex" || type2=="Real") {
                    Item * It = new Item;
                    It->setLit(id->getPValue());
                    return It;
                }
            }

        }

    }
    if (type=="Expression")
    {
        Expression * newExp = new Expression(s.toStdString());
        Item * It = new Item;
        It->setLit(newExp);
        return It;
    }
    else
        throw "Erreur de type";
}
