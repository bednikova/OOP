#include "Type.h"
#include <iostream>
#ifndef __TYPESTRING_H__
#define __TYPESTRING_H__


class TypeString: public Type
{


    public:
        TypeString(): text(NULL)
        {

        }
        TypeString(char* newText);
        TypeString(TypeString& s);
        TypeString& operator=(const TypeString& s);
        ~TypeString();

        void printData();
        void setText(char* text);

        const char* getText() const;

    private:
        char* text;

        void deleteHelp();
        void copy(const TypeString& s);
};

#endif
