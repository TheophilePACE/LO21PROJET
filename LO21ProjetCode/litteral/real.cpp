#include "real.h"

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

Real operator-(Rationnal Ra, Real Re) {
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

Real operator/(Rationnal Ra, Real Re) {
    Real rslt(Ra.getSignedValue()/Re.getSignedValue());
    return rslt;
}
