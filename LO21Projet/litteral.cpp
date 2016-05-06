#include "litteral.h"

void Expression::print(std::ostream& f)const{
    for(unsigned int i=0;i<nb;i++)
        (*tab[i]).print(f);
        f<<" ";
}

void Program::print(std::ostream& f)const{
    f<<instructions;
}

void Expression::increaseCap()
{
    max = max*2+1;
    ExpressionMaterial ** newtab = new ExpressionMaterial*[max];
    for(unsigned int i=0;i<nb;i++)
        newtab[i]=tab[i];
    ExpressionMaterial ** old = tab;
    tab = newtab;
    delete[] old;
}
void Expression::operator<<(ExpressionMaterial* e)
{
    if(nb==max)
       increaseCap();
    tab[nb++]=e;
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


//Fonction mathématiques
int PGCD(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
//INTEGER
void Integer::print (std::ostream& f)const
{
    f<<(Integer::getSignedValue());
}
int Integer::setValue(int entier) {
    this->val=(abs(entier));
    sign=(entier>=0);
    return getSignedValue();
}
Integer Integer::operator +(Integer entier) const
{
    Integer rslt(this->getSignedValue()+entier.getSignedValue()); //creation de a+b
    return rslt; //passage par valeur. Necessaire car rslt sera locale à la boucle sinon.
    
}
Integer Integer::operator-  (Integer entier) const {
    Integer rslt(this->getSignedValue()-entier.getSignedValue());
    return rslt;
    
}
Integer Integer::operator * (Integer entier) const {
    
    Integer rslt (this->getSignedValue()*entier.getSignedValue());
    return rslt;
}
Rationnal Integer::operator / (Integer entier) const {
    Rationnal R(*this,entier);
    return R;
}


//Rationnal
Numerique* Rationnal::Simplify(){

    int p=PGCD(Num->getAbsoluteValue(),Denum->getAbsoluteValue());
    if(p==Denum->getAbsoluteValue()){
        Integer* N = new Integer(Num->getSignedValue()/Denum->getSignedValue());
        return N;}
   // if (p>1) //simplifiable
    
        Num->setValue(Num->getAbsoluteValue()/p);
        Denum->setValue(Denum->getAbsoluteValue()/p);
    return this;
}
Rationnal::Rationnal(int a, int b) //Attention au simplicification
{
    Num= new Integer(a);
    Denum = new Integer(b);
    Simplify();
    
}

void Rationnal::print(std::ostream& f)const{
    Num->print(f);
    f<<"/";
    Denum->print(f);
}

Rationnal Rationnal::operator +(Rationnal frac) const
{
    int NvNum= Num->getSignedValue()*frac.Denum->getSignedValue()+frac.Num->getSignedValue()*Denum->getSignedValue();
    int NvDenum = Denum->getSignedValue()*frac.Denum->getSignedValue();
    Rationnal Rslt(NvNum,NvDenum);
    return Rslt;
}
Rationnal Rationnal::operator- (Rationnal frac)const
{
    int NvNum= Num->getSignedValue()*frac.Denum->getSignedValue()-frac.Num->getSignedValue()*Denum->getSignedValue();
    int NvDenum = Denum->getSignedValue()*frac.Denum->getSignedValue();
    Rationnal Rslt(NvNum,NvDenum);
    return Rslt;

}
Rationnal Rationnal::operator * (Rationnal frac) const
{
    Rationnal Rslt(Num->getSignedValue()*frac.Num->getSignedValue(),Denum->getSignedValue()*frac.Denum->getSignedValue());
    return Rslt;
}
Rationnal Rationnal::operator / (Rationnal frac) const //multiplier par l'inverse
{
    int NvNum=Num->getSignedValue()*frac.Denum->getSignedValue();
    int NvDenum=Denum->getSignedValue()*frac.Num->getSignedValue();
    Rationnal Rslt(NvNum,NvDenum);
    return Rslt;
}







