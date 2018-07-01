#include "TypeDate.h"

TypeDate::TypeDate(char* data) : Type(data)
{
    day = m.dateMember(data, "day");
    month = m.dateMember(data, "month");
    year = m.dateMember(data, "year");

}

bool TypeDate::isValid(char* data)
{
    return (m.isDate(data) && m.validDate(data)) ? true : false;
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


int TypeDate::castDate()
{
    int days = 0;
    int helpMonth = month-1;


    days += day;
    if(month == 1)
    {
        days += 365*(year-1);
        return days;
    }
    else
    {
        while(helpMonth >= 1)
        {
            if(helpMonth == 2)
            {
                days += 28;
            }
            else if(helpMonth % 2 == 0)
            {
                days += 30;
            }
            else
            {
                days += 31;
            }

            --helpMonth;
        }
        days += 365*(year-1);
    }

    return days;
}


int TypeDate::getIntValue()
{

    return this->castDate();
}
