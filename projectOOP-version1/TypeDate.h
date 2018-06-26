#include "Type.h"
#ifndef __TYPEDATE_H__
#define __TYPEDATE_H__

class TypeDate : public Type
{
    public:
        TypeDate(const char* text);
        void printData();
    private:
        int day;
        int month;
        int year;

};


#endif
