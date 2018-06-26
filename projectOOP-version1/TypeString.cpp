#include "TypeString.h"
#include <iostream>
#include <string.h>

using namespace std;


void TypeString::deleteHelp()
{
    delete [] text;
}


void TypeString::copy(const TypeString& s)
{
    int length = strlen(s.text) + 1;
    text = new char[length];
    strcpy(text, s.text);
}


TypeString::TypeString(char* newText): text(NULL)
{

}

TypeString::TypeString(TypeString& s): text(NULL)
{
    copy(s);
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

TypeString::~TypeString()
{
    deleteHelp();
}

void TypeString::printData()
{
    cout << text;
}

void TypeString::setText(char* text)
{

}

const char* TypeString::getText() const
{
    return text;
}
