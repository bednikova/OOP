#ifndef __TYPESTRING_H__
#define __TYPESTRING_H__
#include "Type.h"

class TypeString : public Type
{
    public:
        TypeString() : Type(""),value("") {}
        TypeString(char* data);
        TypeString(const TypeString&);
        ~TypeString();
        TypeString& operator=(const TypeString&);

        bool isValid(char* data);
        const char* getValue() const;
        void setValue(char* data);
        void print() const;
        int getIntValue();
        bool operator>(const TypeString& t);
    private:
        char* value;
        Manager m;
        void deleteHelp();
        void copy(const TypeString&);
};
#endif
