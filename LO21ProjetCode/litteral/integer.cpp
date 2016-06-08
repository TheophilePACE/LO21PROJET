#include "integer.h"
#include "rationnal.h"

void Integer::print(QTextStream& f)const
{
    f<<getSignedValue();
}
std::string Integer::toString()const{
    return std::to_string(num);
}
QString Integer::toQStringPars()const{
    return QString::number(num);
}
long Integer::setValue(long integer) {
    this->num=integer;
    return getSignedValue();
}
Integer Integer::operator+(Integer integer) const
{
    Integer *rslt = new Integer(this->getSignedValue()+integer.getSignedValue()); //creation de a+b
    return *rslt; //passage par valeur. Necessaire car rslt sera locale à la boucle sinon.

}
Integer Integer::operator-(Integer integer) const {
    Integer *rslt = new Integer(this->getSignedValue()-integer.getSignedValue());
    return *rslt;

}
Integer Integer::operator*(Integer integer) const {

    Integer *rslt = new Integer (this->getSignedValue()*integer.getSignedValue());
    return *rslt;
}

Integer Integer::MOD(Integer integer) const
{
    long mod = getNum()%integer.getNum();
    Integer * Rslt = new Integer(mod);
    return *Rslt;
}

Integer Integer::DIV(Integer integer) const {
    long div = getNum()-(getNum()%integer.getNum());
    div = div/integer.getNum();
    Integer *Rslt = new Integer(div);
    return *Rslt;
}
