#include "numeric.h"

Numeric& operator+(const Numeric& N1, const Numeric& N2)
{
    Numeric* result = &(N1+N2);
    return *result;
}
