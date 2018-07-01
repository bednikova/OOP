#include "TypeDouble.h"

TypeDouble::TypeDouble(char* data) : Type(data)
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

int TypeDouble::getIntValue()
{
    int newValue = 0;
    if(getValue() < (int)getValue() + 0.5)
    {
        return (int)getValue();
    }

    return (int)getValue() + 1;
}
