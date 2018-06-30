#include "TypeDouble.h"

TypeDouble::TypeDouble(char* data)
{
    value = m.castStringToDouble(data);
}

bool TypeDouble::isValid(char* data)
{
    return (m.isDouble(data)) ? true : false;
}

double TypeDouble::getValue() const
{
    return value;
}

void TypeDouble::setValue(char* data)
{
    if(isValid(data))
    {
        value = m.castStringToDouble(data);
    }
}

void TypeDouble::print() const
{
    cout << value;
}

