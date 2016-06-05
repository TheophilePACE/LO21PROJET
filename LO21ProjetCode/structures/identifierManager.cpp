#include"identifierManager.h"

IdentifierManager::IdentifierManager(const IdentifierManager& m){
    Identifier ** newtab = new Identifier*[m.max];
    for(unsigned int i=0;i<m.nb;i++)
        newtab[i]=m.identifiers[i];
    identifiers = newtab;
    max = m.max;
    nb = m.nb;
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
    ident->setLib(at);
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
void IdentifierManager::setInstance(IdentifierManager * id){
    sing.instance=id;
}

void IdentifierManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}

Identifier* IdentifierManager::getIdentifier(Atom& a) const {
    IdentifierManager::Iterator it = IdentifierManager::getInstance().getIterator();
    while(!it.isDone() && it.getCurrent().getLib()->toString()!=a.toString()) {
        it.next();
    }
    if(it.isDone())
        return NULL;
    return &(it.getCurrent());
}
unsigned int IdentifierManager::sizeAtoms() const {
    unsigned int nProg = 0;
    for(IdentifierManager::Iterator it = getIterator(); !it.isDone(); it.next())
    {
        if((typeid(*(it.getCurrent().getPValue())))==typeid(Program))
            nProg++;}
    return size()-nProg;
}

const std::string IdentifierManager::displayVar() const {
    std::stringstream f;
    unsigned int j=0;
    for(unsigned int i=0; i<nb; i++) {
            if((typeid(*(identifiers[i]->getPValue()))!=typeid(Program)))
            {
                j++;
                f << (*(identifiers[i]->getLib())).toStringPars();
                f << "-";
                f << (*(identifiers[i]->getPValue())).toStringPars();
                if(j!=sizeAtoms())
                    f<<" ";
            }
    }
    return f.str();
}
const std::string IdentifierManager::displayProg() const {
    std::stringstream f;
    unsigned int j=0;
    for(unsigned int i=0; i<nb; i++) {
        if((typeid(*(identifiers[i]->getPValue()))==typeid(Program)))
        {
                j++;
                f << (*(identifiers[i]->getLib())).toStringPars();
                f << "[";
                f << (*(identifiers[i]->getPValue())).toStringPars();
                f << "]";
                if(j!=size()-sizeAtoms())
                    f<<"_";
        }
    }
    return f.str();
}
