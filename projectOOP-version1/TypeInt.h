#include "Manager.h"
#include "Type.h"
#ifndef __TYPEINT_H__
#define __TYPEINT_H__

class TypeInt : public Type
{
    public:
        TypeInt() : value(0)
        {
        }
        TypeInt(char* data);
        bool isValid(char* data);
        int getValue() const;
        void setValue(char* data);
        void print() const;
    private:
        int value;
        Manager m;
};
#endif
