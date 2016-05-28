#include "rationnal.h"
#include "integer.h"
#include <sstream>

Rationnal Rationnal::simplify(){
//ne fait que simplifier, ne prend pas en compte les chgt de types
    unsigned int p=pgcd(labs (num),labs (denum));
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
    long NvNum= num*frac.denum+frac.num*denum;
    long Nvdenum = denum*frac.denum;
    Rationnal rslt(NvNum,Nvdenum);
    rslt.simplify();
    return rslt;
}
Rationnal Rationnal::operator- (Rationnal frac)const
{
    long NvNum= num*frac.denum-frac.num*denum;
    long Nvdenum = denum*frac.denum;
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
    long NvNum=num*frac.denum;
    long Nvdenum=denum*frac.num;
    Rationnal rslt(NvNum,Nvdenum);
    rslt.simplify();
    return rslt;
}

bool Rationnal::isInteger () const{return(denum==1);}

Rationnal operator+(Integer a, Rationnal Ra)
{
    Rationnal rslt(a.getSignedValue()*Ra.getDenum()+ Ra.getNum()  ,  Ra.getDenum());
    return rslt;
}
Rationnal operator-(Integer a, Rationnal Ra)
{
    Rationnal rslt(a.getSignedValue()*Ra.getDenum()-Ra.getNum(),Ra.getDenum());
    return rslt;
}
Rationnal operator-(Rationnal Ra, Integer a)
{
    Rationnal rslt(-a.getSignedValue()*Ra.getDenum()+Ra.getNum(),Ra.getDenum());
    return rslt;
}
Rationnal operator*(Integer a, Rationnal Ra)
{
    Rationnal rslt(a.getSignedValue()*Ra.getNum(),Ra.getDenum());
    return rslt;
}
Rationnal operator/(Integer a, Rationnal Ra)
{
    Rationnal rslt(Ra.getNum(),Ra.getDenum()*a.getSignedValue());
    return rslt;
}
Rationnal operator/(Rationnal Ra, Integer a)
{
    Rationnal rslt(Ra.getDenum()*a.getSignedValue(),Ra.getNum());
    return rslt;
}
Rationnal operator/(Integer int1, Integer int2) {
    Rationnal R(int1.getSignedValue(),int2.getSignedValue());
    return R;
}
