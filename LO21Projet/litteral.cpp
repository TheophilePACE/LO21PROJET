#include "litteral.h"

void Expression::print(ostream& f)const{
    for(unsigned int i=0;i<nb;i++)
        f<<*tab[i]<<" ";
}

void Program::print(ostream& f)const{
    f<<instructions;
}

void Expression::increaseCap()
{
    max = max*2+1;
    Expression ** newtab = new Expression*[max];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=tab[i];
    Expression ** old = tab;
    tab = newtab;
    delete[] old;
}
void operator<<(Expression e)
{
    if(nb==max)
       increaseCap();
    tab[nb++]=&e;
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

    for(i;(i<--nb);i++)
        programs[i]=programs[i+1];
}
static ProgramManager& getInstance(){
    if(sing.instance==nullptr) sing.instance = new ProgramManager;
    return *sing.instance;
}

static void ProgramManager::freeInstance(){
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
void IdentifierManager::addIdentifier(std::string s, litteral* l){
    if(nb==max)
       increaseCap();
    Atom * at = new Atom(chaine);
    Identifier* ident = new Identifier;
    ident->setLib(at);
    ident->setValue(*l);
    identifiers[nb++]=ident;
}
void IdentifierManager::removeIdentifier(Identifier& p){
    unsigned int i=0;

    while((i<nb) && (&p != identifiers[i])){i++;}
    if(i==nb)
        throw "Suppression Impossible";
    delete identifiers[i];

    for(i;(i<--nb);i++)
        identifiers[i]=identifiers[i+1];
}
static IdentifierManager& getInstance(){
    if(sing.instance==nullptr) sing.instance = new IdentifierManager;
    return *sing.instance;
}

static void IdentifierManager::freeInstance(){
    delete sing.instance;
    sing.instance = nullptr;
}
