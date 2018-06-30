#ifndef __TYPESTRING_H__
#define __TYPESTRING_H__
#include "Type.h"

class TypeString : public Type
{
    public:
        TypeString() : value(0) {}
        TypeString(char* data);
        TypeString(const TypeString&);
        ~TypeString();
        TypeString& operator=(const TypeString&);

        bool isValid(char* data);
        const char* getValue() const;
        void setValue(char* data);
        void print() const;
    private:
        char* value;
        Manager m;
        void deleteHelp();
        void copy(const TypeString&);
};
#endif
