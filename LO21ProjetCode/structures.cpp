#include "litteral.h"
#include "structures.h"
#include <QString>
#include <QStringList>

void Pile::increaseCap() {
    Item* newtab=new Item[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=items[i];
    Item*  old=items;
    items=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}

void Pile::push(Item e){
    if (nb==nbMax) increaseCap();
    items[nb]=e;
    nb++;
    stateModification();
}

void Pile::pop(){
    nb--;
    items[nb].raz();
    stateModification();
}

void Pile::display(QTextStream& f) const{
    f<<"********************************************* \n";
    f<<"M : "<<message<<"\n";
    f<<"---------------------------------------------\n";
    for(unsigned int i=nbItemsDisplayed; i>0; i--) {
        if (i<=nb)
            {
                f<<i<<": ";
                (*(items[nb-i].getPLit())).print(f);
            }
        else f<<i<<": \n";
    }
    f<<"---------------------------------------------\n";
}


Pile::~Pile(){
    delete[] items;
}

Litteral* Pile::top() const {

    if (nb==0) throw ComputerException("aucune expression sur la pile");
    return items[nb-1].getPLit();
}

void ProgramManager::increaseCap()
{
    max = max*2+1;
    Program ** newtab = new Program*[max];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=programs[i];
    Program ** old = programs;
    programs = newtab;
    delete[] old;
}
void ProgramManager::addProgram(std::string chaine){
    if(nb==max)
       increaseCap();
    Program * prog = new Program(chaine);
    programs[nb++]=prog;
}
void ProgramManager::removeProgram(Program& p){
    unsigned int i;

    for(i=0;(i<nb) && (&p != programs[i]);i++){}
    if(i==nb)
        throw "Suppression Impossible";
    delete programs[i];

    do
    {
        programs[i]=programs[i+1];
        i++;
    }while(i<--nb);

}

ProgramManager::Singleton ProgramManager::sing=ProgramManager::Singleton();

ProgramManager& ProgramManager::getInstance(){
    if(sing.instance==nullptr) sing.instance = new ProgramManager;
    return *sing.instance;
}

void ProgramManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}


void IdentifierManager::increaseCap()
{
    max = max*2+1;
    Identifier ** newtab = new Identifier*[max];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=identifiers[i];
    Identifier ** old = identifiers;
    identifiers = newtab;
    delete[] old;
}
void IdentifierManager::addIdentifier(std::string s, Litteral* l){
    if(nb==max)
       increaseCap();
    Atom * at = new Atom(s);
    Identifier* ident = new Identifier;
    ident->setLib(*at);
    ident->setValue(l);
    identifiers[nb++]=ident;
}
void IdentifierManager::removeIdentifier(Identifier& p){
    unsigned int i=0;

    while((i<nb) && (&p != identifiers[i])){i++;}
    if(i==nb)
        throw "Suppression Impossible";
    delete identifiers[i];
    do
    {
        identifiers[i]=identifiers[i+1];
        i++;
    }while(i<--nb);

}
IdentifierManager::Singleton IdentifierManager::sing=IdentifierManager::Singleton();
IdentifierManager& IdentifierManager::getInstance(){
    if(sing.instance==nullptr) sing.instance = new IdentifierManager;
    return *sing.instance;
}

void IdentifierManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}
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
    else if(type=="Rationnal")
            {
                Rationnal * newInt = new Rationnal(p.getNum(s),p.getDenum(s));
                Item * It = new Item;
                It->setLit(newInt);
                return It;
            }
    else
            throw ComputerException("Erreur de type");
}

Parser::Singleton Parser::sing=Parser::Singleton();
Parser& Parser::getInstance(){
    if(sing.instance==nullptr) sing.instance = new Parser;
    return *sing.instance;
}
bool Parser::isOperator(QString s) {
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    return false;
}

std::string Parser::getType(QString s)
{
    return "Rationnal";
}
Integer Parser::getNum(QString s){
    return Integer(s.split('/').first().toInt());
}
Integer Parser::getDenum(QString s){
    return Integer(s.split('/').at(1).toInt());
}
Integer Parser::getInteger(QString s){
    return Integer(s.split('.').first().toInt());
}
float Parser::getMantisse(QString s){
    return s.split('.').at(1).toFloat();
}/*
Integer Parser::getRealPart(QString s){
    return Integer(s.split('$').first().toInt());
}
Integer Parser::getImPart(QString s){
    return Integer(s.split('$').at(1).toInt());
}
*/
void Controller::command(const QString& c){
    Parser p = Parser::getInstance();
    QStringList list = c.split(" ");
    for (int i = 0; i < list.size(); ++i) {
        if(p.isOperator(c)) {
            /*if (stack.size()>=2) {
                int v2=2;//expAff.top().getValue();
                //expMng.removeExpression(expAff.top());
                stack.pop();
                int v1=2;//expAff.top().getValue();
                //expMng.removeExpression(expAff.top());
                stack.pop();
                int res;
                if (c=="+") res=v1+v2;
                if (c=="-") res=v1-v2;
                if (c=="*") res=v1*v2;
                if (c=="/") {
                    if (v2!=0) res=v1/v2;
                    else {
                        //expAff.setMessage("Erreur : division par zéro");
                        res=v1;
                    }
                }
                Expression& e=expMng.addExpression(res);
                expAff.push(e);
            }else{
                expAff.setMessage("Erreur : pas assez d'arguments");
            }
        }//else expAff.setMessage("Erreur : commande inconnue");
    }*/}
     else {
            Item * I = genMng.createItem(c);
                    if(I)
                        stack.push(*I);
                    else
                    {
                        stack.setMessage("Erreur : commande inconnue");
                        break;
                    }
        }
    }
}
