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


int TypeDate::castDate() const
{
    int days = day;
    int helpMonth = month-1;
    int helpYear = year - 1900;



    if(month == 1 && helpYear != 0)
    {
        days += 365*(helpYear-1);
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
            else if(helpMonth % 2 == 0 && helpMonth != 2)
            {
                days += 30;
            }
            else
            {
                days += 31;
            }

            --helpMonth;
        }

        if(helpYear != 0)
        {
            days += 365*(helpYear-1);
        }

    }

    //cout << "date -> int " << days << endl;
    return days;
}


int TypeDate::getIntValue()
{

    return this->castDate();
}


bool TypeDate::operator>(const TypeDate& t)
{
    if(castDate() > t.castDate())
    {
        return false;
    }

    return true;
}


bool TypeDate::operator<(const TypeDate& t)
{
    return (castDate() < t.castDate()) ? true : false;
}
