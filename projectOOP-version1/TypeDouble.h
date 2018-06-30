#ifndef __TYPEDOUBLE_H__
#define __TYPEDOUBLE_H__
#include "Type.h"

class TypeDouble : public Type
{
    public:
        TypeDouble() : value(0.0) {}
        TypeDouble(char* data);
        bool isValid(char* data);
        double getValue() const;
        void setValue(char* data);
        void print() const;
    private:
        double value;
        Manager m;
};
#endif
