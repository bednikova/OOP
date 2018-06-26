#include "Type.h"
#ifndef __TYPEINT_H__
#define __TYPEINT_H__

class TypeInt : public Type
{
    public:

        TypeInt();
        TypeInt(char* data);

        bool IntValid(char* data);

        int getValue() const;
        void printData();

    private:

         int value;

};

#endif
