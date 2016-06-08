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
void GeneralManager::increaseCap()
{
    max = max*2+1;
    Litteral ** newtab = new Litteral*[max];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=litterals[i];
    Litteral ** old = litterals;
    litterals = newtab;
    delete[] old;
}
void GeneralManager::addLitteral(Litteral* const l){
    if(nb==max)
       increaseCap();
    litterals[nb++]=l;
    std::cout << "\nJ'add la litérale" << nb <<"\n";
}
void GeneralManager::removeLitteral(Litteral * p){
    unsigned int i=nb;

    //while((i>0) && (p != litterals[i])){i--;}
    //if(i==nb)
    //    throw ComputerException("Suppression Impossible");
    //delete litterals[i];
    //std::cout << "\nJe remove la litérale" << nb-i <<"\n";
    //do
    //{
    //    litterals[i]=litterals[i+1];
    //    i++;
    //}while(i<--nb);

}

GeneralManager::~GeneralManager(){
   // for(unsigned int i=0;i<nb;i++)
        //delete litterals[i];
    delete[] litterals;
}

void GeneralManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}
Item * GeneralManager::createProgram(QString s){
    Program * newProg = new Program(s);
    Item * It = new Item;
    It->setLit(newProg);
    return It;
}

Item * GeneralManager::createItem(QString s) {
    Parser p = Parser::getInstance();


    std::string type = p.getType(s);
    if(type=="Integer"||type=="Rationnal"||type=="Real"||type=="Atom"||type=="Expression"||type=="Program")
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
            throw ComputerException("Erreur de type");
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
            removeLitteral(newRat);
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
        if(p.isOperator(s))
        {
            throw ComputerException("C'est un operateur donc pas de création");
        }
        else
        {
            Identifier * id = IdentifierManager::getInstance().getIdentifier(*(new Atom(s)));
            if(id==NULL)
            {
                Expression * newExp = new Expression(s.insert(0,'\'').insert(s.size()+1,'\''));
                Item * It = new Item;
                It->setLit(newExp);
                return It;
            }
            else
            {
                if(typeid((*id->getPValue()))==typeid(Program))
                    return NULL;
                else {
                    Item * It = new Item;
                    It->setLit(id->getPValue());
                    return It;
                }
            }

        }

    }
    if (type=="Expression")
    {
        Expression * newExp = new Expression(s);
        Item * It = new Item;
        It->setLit(newExp);
        return It;
    }
    if (type=="Program")
    {
        if(s[1]==' ') s.remove(1,1);
        if(s[s.size()-2]==' ') s.remove(s.size()-2,1);
        Program * newProg = new Program(s);
        Item * It = new Item;
        It->setLit(newProg);
        return It;
    }
    else
        throw ComputerException("Erreur de type");
}
