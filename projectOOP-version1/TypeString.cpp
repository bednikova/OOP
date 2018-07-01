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
            if(value[index] == '\"' && (index == 0 || index == strlen(value)-1))
            {
                //cout << '\"';
            }
            else if(value[index] == '\"' && !(index == 0 || index == strlen(value)-1))
            {
                cout << '"';
            }
            else if(value[index] == '\\' && value[index+1] != '\\')
            {
                //cout << '\\';
            }
            else if(value[index] == '\\' && value[index+1] == '\\')
            {
                cout << value[index];
            }
            else
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

int TypeString::getIntValue()
{
    if(!value)
    {
        return 0;
    }
    //cout << value << " int -> " << atoi(value);
    return atoi(value);
}


bool TypeString::operator>(const TypeString& t)
{
    int len = strlen(value)+1;
    if(len < strlen(t.value)+1)
    {
        return false;
    }

    if(len > strlen(t.value)+1)
    {
        return true;
    }

    for(int index = 0; index < len; ++index)
    {
        if(value[index] < t.value[index])
        {
            return false;
        }
    }

    return true;
}
