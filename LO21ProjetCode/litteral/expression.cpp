#include "expression.h"
#include <sstream>

std::string Expression::toString()const {
    return  instructions.toStdString();
}
QString Expression::toQStringPars()const {
    return instructions;
}
void Expression::print(QTextStream& f)const{
    f<<instructions;
}
