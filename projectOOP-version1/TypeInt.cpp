#include "TypeInt.h"

TypeInt::TypeInt(char* data) : Type(data)
{
    value = m.castStringToInt(data);
}

bool TypeInt::isValid(char* data)
{
    return (m.isInt(data)) ? true : false;
}

int TypeInt::getValue() const
{
    return value;
}

void TypeInt::setValue(char* data)
{
    if(isValid(data))
    {
        value = m.castStringToInt(data);
    }
}

void TypeInt::print() const
{
    cout << value;
}

int TypeInt::getIntValue()
{
    return getValue();
}
