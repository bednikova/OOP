#include "TypeString.h"

TypeString::TypeString(char* data) : Type(data), value(NULL)
{
    setValue(data);
}

TypeString::TypeString(const TypeString& s) : Type(data), value(NULL)
{
    copy(s);
}

TypeString::~TypeString()
{
    deleteHelp();
}

TypeString& TypeString::operator=(const TypeString& s)
{
    if (this != &s)
    {
        deleteHelp();
        copy(s);
    }
    return *this;
}

bool TypeString::isValid(char* data)
{
    return (m.isString(data)) ? true : false;
}

const char* TypeString::getValue() const
{
    return value;
}

void TypeString::setValue(char* data)
{
    deleteHelp();
    int length = strlen(data) + 1;
    value = new char[length];
    strcpy(value, data);
}

void TypeString::print() const
{
    if (value)
    {
        for(int index = 0; index < strlen(value)+1; ++index)
        {
            if(value[index] != '\\')  // za C:\\temp\\ opravi go!!!
            {
                cout << value[index];
            }
        }
    }
}


void TypeString::deleteHelp()
{
    delete [] value;
}


void TypeString::copy(const TypeString& s)
{
    int length = strlen(s.value) + 1;
    value = new char[length];
    strcpy(value, s.value);
}
