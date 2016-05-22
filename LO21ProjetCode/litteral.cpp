#include "litteral.h"
#include <QString>
#include <sstream>
#include <QRegExp>

//Functions

QString toQString(std::string s) {
    return QString::fromStdString(s);
}

std::string floatToString(float f) {
   std::ostringstream ost;
   ost<<f;
   return ost.str();

}

bool isOperator(const QString s){
    if (s=="+") return true;
    if (s=="-") return true;
    if (s=="*") return true;
    if (s=="/") return true;
    return false;
}
bool isRationnal(const QString s)
{
    QRegExp ratioExp ("[+-]?\\d+\\/[+-]?\\d+");
    return ratioExp.exactMatch(s);
}
bool isInteger(const QString s)
{
    QRegExp regExp ("[+-]?\\d+\\.?0*");
    return regExp.exactMatch(s);
}
bool isReal(const QString s)
{
    QRegExp regExp ("[+-]?\\d*\\.0*[1-9][0-9]*");
    return regExp.exactMatch(s);
}
bool isComplex(const QString s)
{
    QRegExp regExp ("[+-]?[0-9]*(\\.[0-9]*|\\/[+-]?[0-9]+)?\\$[+-]?[0-9]*(\\.[0-9]*|\\/[+-]?[0-9]+)?");
    return regExp.exactMatch(s);
}
bool isNumber(const QString s){
   bool ok=false;
   s.toInt(&ok);
   return ok;
}

/*
bool isExression(const QString s) {
    QRegExp regExp ("\"")
    unsigned int size = s.size();
    if(((s.data[size-1]=="\"") && (s.data[0]=="\"")) && (s.count("\"")==2))
        return true;
   return false;
}*/
/*
bool isProgram(const QString s) {
    unsigned int size = s.size();
    if((((s.data[size-1]=="[") && (s.data[0]=="]")) && (s.count("[")==1))&&(s.count("]")==1))
        return true;
   return false;
}
bool isAtom(const QString s) {
    if (s.data[0]//nonmaj)
            )
        return false;

}*/

//Math Functions
unsigned int pgcd(int a, int b)
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

//Expression

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

// Program

void Program::print(QTextStream& f)const{
    f<<toQString(instructions);
}

//Numérique


void Integer::print (QTextStream& f)const
{
    f<<getSignedValue();
}
std::string Integer::toString()const{
    return std::to_string(getSignedValue());
}
int Integer::setValue(int integer) {
    this->val=integer;
    return getSignedValue();
}
Integer Integer::operator +(Integer integer) const
{
    Integer rslt(this->getSignedValue()+integer.getSignedValue()); //creation de a+b
    return rslt; //passage par valeur. Necessaire car rslt sera locale à la boucle sinon.
    
}
Integer Integer::operator-  (Integer integer) const {
    Integer rslt(this->getSignedValue()-integer.getSignedValue());
    return rslt;
    
}
Integer Integer::operator * (Integer integer) const {
    
    Integer rslt (this->getSignedValue()*integer.getSignedValue());
    return rslt;
}
Rationnal Integer::operator / (Integer integer) const {
    Rationnal R(getSignedValue(),integer.getSignedValue());
    return R;
}


//Rationnal
Rationnal Rationnal::simplify(){
//ne fait que simplifier, ne prend pas en compte les chgt de types
    unsigned int p=pgcd(abs(num),abs(denum));
   // if (p>1) //simplifiable
    
        num=(num/p);
        denum=(denum/p);
    return *this;
}

Rationnal::Rationnal(Integer a, Integer b) //Attention au simplicification
{
    num= a.getSignedValue();
    denum = b.getSignedValue();
    simplify();
    
}

void Rationnal::print(QTextStream& f)const{
    f<<(toQString(toString()));

}
std::string Rationnal::toString()const{
    std::stringstream sf;
    sf<<num<<"/"<<denum;

    return sf.str();
}
Rationnal Rationnal::operator +(Rationnal frac) const
{
    int NvNum= num*frac.denum+frac.num*denum;
    int Nvdenum = denum*frac.denum;
    Rationnal rslt(NvNum,Nvdenum);
    rslt.simplify();
    return rslt;
}
Rationnal Rationnal::operator- (Rationnal frac)const
{
    int NvNum= num*frac.denum-frac.num*denum;
    int Nvdenum = denum*frac.denum;
    Rationnal rslt(NvNum,Nvdenum);
    rslt.simplify();
    return rslt;

}
Rationnal Rationnal::operator * (Rationnal frac) const
{
    Rationnal rslt(num*frac.num,denum*frac.denum);
    rslt.simplify();
    return rslt;
}
Rationnal Rationnal::operator / (Rationnal frac) const //multiplier par l'inverse
{
    int NvNum=num*frac.denum;
    int Nvdenum=denum*frac.num;
    Rationnal rslt(NvNum,Nvdenum);
    rslt.simplify();
    return rslt;
}

bool Rationnal::isInteger () const{return(denum==1);}

//REAL
float Real::getSignedValue() const{
    return (abs(integer)+mantisse)*(integer/abs(integer)); //integer*abs()integer ==> signe de integer
}
bool Real::simplify() {
    if(mantisse>=1)
    {
        mantisse --;
        integer++;
        return 1;
    }
    return 0;
}
bool Real::isInteger() const{
    return (mantisse==0);
}
std::string Real::toString()const{
    std::string s="";
    //s=s+std::to_string(integer)+"."+floatToString(mantisse);
    s=s+floatToString(integer+mantisse);
    return s;
}
void Real::print(QTextStream& f)const
{
    f<<toQString(this->toString());
}

Real Real::operator +(Real re) const
{
    Real rslt(getSignedValue()+re.getSignedValue());
    rslt.simplify();
    return rslt;
}
Real Real::operator- (Real re)const{
    Real rslt(getSignedValue()-re.getSignedValue());
    rslt.simplify();
    return rslt;
}
Real Real::operator * (Real re) const{
    Real rslt(getSignedValue()*re.getSignedValue());
    rslt.simplify();
    return rslt;
}

Real Real::operator / (Real re) const{
    Real rslt(getSignedValue()/re.getSignedValue());
    rslt.simplify();
    return rslt;
}
//RATIO ET INT
Rationnal operator+(int a, Rationnal Ra)
{
    Rationnal rslt(a*Ra.getDenum()+Ra.getNum(),Ra.getDenum());
    return rslt;
}
Rationnal operator-(int a, Rationnal Ra)
{
    Rationnal rslt(a*Ra.getDenum()-Ra.getNum(),Ra.getDenum());
    return rslt;
}
Rationnal operator-(Rationnal Ra, int a)
{
    Rationnal rslt(-a*Ra.getDenum()+Ra.getNum(),Ra.getDenum());
    return rslt;
}
Rationnal operator*(int a, Rationnal Ra)
{
    Rationnal rslt(a*Ra.getNum(),Ra.getDenum());
    return rslt;
}
Rationnal operator/(int a, Rationnal Ra)
{
    Rationnal rslt(Ra.getNum(),Ra.getDenum()*a);
    return rslt;
}
Rationnal operator/(Rationnal Ra,int a)
{
    Rationnal rslt(Ra.getDenum()*a,Ra.getNum());
    return rslt;
}

//REAL INT
Real operator+(int a, Real Re){
    float af = static_cast<float>(a);
    Real rslt(af+Re.getSignedValue());
    return rslt;
}
Real operator-(int a, Real Re){
    float af = static_cast<float>(a);
    Real rslt(af-Re.getSignedValue());
    return rslt;
}
Real operator-( Real Re,int a){
    float af = static_cast<float>(a);
    Real rslt(-af+Re.getSignedValue());
    return rslt;
}
Real operator*(int a, Real Re){
    float af = static_cast<float>(a);
    Real rslt(af+Re.getSignedValue());
    return rslt;
}
Real operator/(int a, Real Re){
    float af = static_cast<float>(a);
    Real rslt(af/Re.getSignedValue());
    return rslt;
}
Real operator/( Real Re, int a){
    float af = static_cast<float>(a);
    Real rslt(Re.getSignedValue()/af);
    return rslt;
}


//REAL RATIONNAL
Real operator+(Real Re, Rationnal Ra) {
    Real rslt(Re.getSignedValue()+Ra.getSignedValue());
    return rslt;
}

Real operator-(Real Re, Rationnal Ra) {
    Real rslt(Re.getSignedValue()-Ra.getSignedValue());
    return rslt;
}

Real operator-(Rationnal Ra,Real Re) {
    Real rslt(-Re.getSignedValue()+Ra.getSignedValue());
    return rslt;
}

Real operator*(Real Re, Rationnal Ra) {
    Real rslt(Re.getSignedValue()*Ra.getSignedValue());
    return rslt;
}

Real operator/(Real Re, Rationnal Ra) {
    Real rslt(Re.getSignedValue()/Ra.getSignedValue());
    return rslt;
}

Real operator/(Rationnal Ra,Real Re) {
    Real rslt(Ra.getSignedValue()/Re.getSignedValue());
    return rslt;
}

Numeric& operator+(const Numeric& N1, const Numeric& N2)
{
    Numeric* result = &(N1+N2);
    return *result;
}

//Complex

/*
Complex Complex::operator +(Complex Cx) const{
    return Complex(addNum(Cx.pReal,pReal),addNum(Cx.pImag,pImag));
}*/


/*
Complex operator - (Complex Cx)const ;
Complex operator * (Complex Cx) const ;
Complex operator / (Complex Cx) const;
*/
