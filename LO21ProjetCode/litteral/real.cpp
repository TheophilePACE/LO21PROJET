#include "real.h"

double Real::getSignedValue() const{
    return (num+mantisse); //num*abs()num ==> signe de num
}
bool Real::simplify() {
    if(mantisse>=1)
    {
        mantisse --;
        num++;
        return 1;
    }
    if(mantisse<=-1)
    {
        mantisse ++;
        num--;
        return 1;
    }
    return 0;
}

std::string Real::toString()const{
    double f=getSignedValue();
    std::string str = std::to_string(f);
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
    return str;
}
QString Real::toQStringPars()const {
    return toQString(toString()).replace(",",".");
}
void Real::print(QTextStream& f)const
{
    f<<toQString(this->toString());
}

Real Real::operator +(Real re) const
{
    Real * rslt = new Real(getSignedValue()+re.getSignedValue());
    rslt->simplify();
    return *rslt;
}
Real Real::operator- (Real re)const{
    Real * rslt = new Real(getSignedValue()-re.getSignedValue());
    rslt->simplify();
    return *rslt;
}
Real Real::operator * (Real re) const{
    Real * rslt = new Real(getSignedValue()*re.getSignedValue());
    rslt->simplify();
    return *rslt;
}

Real Real::operator / (Real re) const{
    Real * rslt = new Real(getSignedValue()/re.getSignedValue());
    rslt->simplify();
    return *rslt;
}
Real operator+(int a, Real Re){
    double af = static_cast<double>(a);
    Real * rslt = new Real(af+Re.getSignedValue());
    return *rslt;
}
Real operator-(int a, Real Re){
    double af = static_cast<double>(a);
    Real * rslt = new Real(af-Re.getSignedValue());
    return *rslt;
}
Real operator-( Real Re,int a){
    double af = static_cast<double>(a);
    Real * rslt = new Real(-af+Re.getSignedValue());
    return *rslt;
}
Real operator*(int a, Real Re){
    double af = static_cast<double>(a);
    Real * rslt = new Real(af+Re.getSignedValue());
    return *rslt;
}
Real operator/(int a, Real Re){
    double af = static_cast<double>(a);
    Real * rslt = new Real(af/Re.getSignedValue());
    return *rslt;
}
Real operator/( Real Re, int a){
    double af = static_cast<double>(a);
    Real * rslt = new Real(Re.getSignedValue()/af);
    return *rslt;
}


//REAL RATIONNAL
Real operator+(Real Re, Rationnal Ra) {
    Real * rslt = new Real(Re.getSignedValue()+Ra.getSignedValue());
    return *rslt;
}

Real operator+(Rationnal Ra, Real Re){
    Real * rslt = new Real(Re.getSignedValue()+Ra.getSignedValue());
    return * rslt;
}


Real operator-(Real Re, Rationnal Ra) {
    Real * rslt = new Real(Re.getSignedValue()-Ra.getSignedValue());
    return *rslt;
}

Real operator-(Rationnal Ra, Real Re) {
    Real * rslt = new Real(-Re.getSignedValue()+Ra.getSignedValue());
    return * rslt;
}

Real operator*(Real Re, Rationnal Ra) {
    Real * rslt = new Real(Re.getSignedValue()*Ra.getSignedValue());
    return *rslt;
}

Real operator/(Real Re, Rationnal Ra) {
    Real * rslt = new Real(Re.getSignedValue()/Ra.getSignedValue());
    return *rslt;
}

Real operator/(Rationnal Ra, Real Re) {
    Real * rslt = new Real(Ra.getSignedValue()/Re.getSignedValue());
    return *rslt;
}
