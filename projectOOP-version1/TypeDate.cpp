#include "TypeDate.h"

TypeDate::TypeDate(char* data) : Type(data)
{
    day = m.dateMember(data, "day");
    month = m.dateMember(data, "month");
    year = m.dateMember(data, "year");

}

bool TypeDate::isValid(char* data)
{
    return (m.isDate(data)) ? true : false;
}

int TypeDate::getDay() const
{
    return day;
}

int TypeDate::getMonth() const
{
    return month;
}

int TypeDate::getYear() const
{
    return year;
}

void TypeDate::setValue(char* data)
{
    if(isValid(data))
    {
        day = m.dateMember(data, "day");
        month = m.dateMember(data, "month");
        year = m.dateMember(data, "year");
    }
}

void TypeDate::print() const
{
    cout << day << "." << month << "." << year;
}
