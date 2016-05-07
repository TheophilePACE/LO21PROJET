#include "litteral.h"
#include "structures.h"
#include <QString>


void Pile::increaseCap() {
    Item* newtab=new Item[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=items[i];
    Item*  old=items;
    items=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}

void Pile::push(Litteral* e){
    if (nb==nbMax) increaseCap();
    items[nb].setLit(e);
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
}/*
GeneralManager::Singleton GeneralManager::sing=GeneralManager::Singleton();
GeneralManager& GeneralManager::getInstance(){
    if(sing.instance==nullptr) sing.instance = new GeneralManager;
    return *sing.instance;
}

void GeneralManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}*/


void Controller::command(const QString& c){
    if (estUnNombre(c)){
        //stack.push(/*expMng.addExpression(c.toInt())*/);
    }else{

        if (estUnOperateur(c)){
            if (stack.size()>=2) {
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
                /*Expression& e=expMng.addExpression(res);
                expAff.push(e);*/
            }else{
                /*expAff.setMessage("Erreur : pas assez d'arguments");*/
            }
        }//else expAff.setMessage("Erreur : commande inconnue");
    }
}
