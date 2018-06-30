#ifndef __TYPEDATE_H__
#define __TYPEDATE_H__
#include "Type.h"
#include "Manager.h"

class TypeDate : public Type
{
    public:
        TypeDate() : day(1), month(1), year(1900) {}
        TypeDate(char* data);
        bool isValid(char* data);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        void setValue(char* data);
        void print() const;
    private:
        Manager m;
        int day;
        int month;
        int year;
};
#endif

