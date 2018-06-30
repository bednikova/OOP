#ifndef __TYPEDATE_H__
#define __TYPEDATE_H__
#include "Type.h"
#include "Manager.h"

class TypeDate : public Type
{
    public:
        TypeDate() : Type("01.01.1900"),day(1), month(1), year(1900) {}
        TypeDate(char* data);
        bool isValid(char* data);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        //char* getValue() const;
        void setValue(char* data);
        void print() const;

        int castDate();
    private:
        Manager m;
        int day;
        int month;
        int year;
};
#endif

