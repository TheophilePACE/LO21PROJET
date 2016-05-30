#include"identifierManager.h"

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

Identifier* IdentifierManager::getIdentifier(Atom& a){
    IdentifierManager::Iterator it = IdentifierManager::getInstance().getIterator();
    while(!it.isDone() && it.getCurrent().getLib()->toString()!=a.toString()) {
        it.next();
    }
    if(it.isDone())
        return NULL;
    return &(it.getCurrent());
}
