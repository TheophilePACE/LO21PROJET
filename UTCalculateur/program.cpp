#include "program.h"

void Program::print(QTextStream& f)const{
    f<<toQString(instructions);
}

