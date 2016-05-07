#include "litteral.h"
#include <QString>
#include <sstream>

QString toQString(std::string s) {
    return QString::fromStdString(s);
}

std::string Expression::toString()const {
    std::stringstream f;
    for(unsigned int i=0;i<nb;i++){
        f<<(*tab[i]).toString();
        f<<" ";
    }
    return  f.str();
}
void Expression::print(QTextStream& f)const{
    f<<toQString(toString());
}

void Program::print(QTextStream& f)const{
    f<<toQString(instructions);
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


bool estUnOperateur(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    return false;
}

bool estUnNombre(const QString s){
   bool ok=false;
   s.toInt(&ok);
   return ok;
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
void Integer::print (QTextStream& f)const
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

void Rationnal::print(QTextStream& f)const{
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
