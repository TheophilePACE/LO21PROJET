#include "integer.h"
#include "rationnal.h"

void Integer::print(QTextStream& f)const
{
    f<<getSignedValue();
}
std::string Integer::toString()const{
    return std::to_string(getSignedValue());
}
long Integer::setValue(long integer) {
    this->num=integer;
    return getSignedValue();
}
Integer Integer::operator+(Integer integer) const
{
    Integer rslt(this->getSignedValue()+integer.getSignedValue()); //creation de a+b
    return rslt; //passage par valeur. Necessaire car rslt sera locale à la boucle sinon.

}
Integer Integer::operator-(Integer integer) const {
    Integer rslt(this->getSignedValue()-integer.getSignedValue());
    return rslt;

}
Integer Integer::operator*(Integer integer) const {

    Integer rslt (this->getSignedValue()*integer.getSignedValue());
    return rslt;
}
