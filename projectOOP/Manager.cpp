#include "Manager.h"

int Manager::countRowsInFile(char* fileName)
{
    int countRows = 0;
    ifstream myFile(fileName);

    if(myFile)
    {
        char buff[1024];
        while(myFile.getline(buff, 1024))
        {
            char* row = new char[strlen(buff)+1];
            strcpy(row, buff);
            ++countRows;
        }
    }

    myFile.close();


    //cout << "count rows: " << countRows << endl;
    return countRows;
}


int Manager::countColumns(char* row)
{
    int size = strlen(row)+1;
    int columns = 0;
    for(int i = 0; i < size; ++i)
    {
        if(row[i] == ',')
        {
            ++columns;
        }
    }
    return columns+1;
}

bool Manager::isInt(char* data)
{
    int len = strlen(data);


    for(int index = 0; index < len; ++index)
    {
        if(isalpha(data[index]))
        {
            return false;
        }
    }

    for(int index = 0; index < len; ++index)
    {
        if((data[index] == '\"') || (data[index] == ' ') || (data[index] == '.'))
        {
            return false;
        }
    }


    if((data[0] == '-') || (data[0] == '+') || isdigit(data[0]))
    {
        for(int index = 1; index < len; ++index)
        {
            if(!isdigit(data[index]))
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool Manager::isDouble(char* data)
{
    int len = strlen(data);


    for(int index = 0; index < len; ++index)
    {
        if(isalpha(data[index]))
        {
            return false;
        }
    }

    for(int index = 0; index < len; ++index)
    {
        if((data[index] == '\"') || (data[index] == ' '))
        {
            return false;
        }
    }

    int count = 0;
    for(int index = 0; index < len; ++index)
    {
        if(data[index] == '.')
        {
            ++count;
        }
    }

    if(count > 1)
    {
        return false;
    }

    if((data[0] == '-') || (data[0] == '+') || isdigit(data[0]))
    {
        for(int index = 1; index < len; ++index)
        {
            if(!isdigit(data[index]) && data[index] != '.')
            {
                return false;
            }
        }

        return true;
    }

    return false;
}

bool Manager::isString(char* data)
{
    int len = strlen(data);
    int count = 0;


    for(int index = 0; index < len; ++index)
    {
        if(data[index] == '\"')
        {
            ++count;
        }
        if(data[0] == '\"' && data[len-1] == '\"')
        {
            return true;
        }
    }

    if(count > 2)
    {
        return true;
    }

    return false;

}


bool Manager::isDate(char* data)
{
    int len = strlen(data);

    if(isInt(data) || isDouble(data))
    {
        return false;
    }

    int count = 0;
    int size1 = 0, size2 = 0, size3 = 0;
    for(int index = 0; index < len; ++index)
    {
        if(!isdigit(data[index]))
        {
            if(data[index] != '.')
            {
                return false;
            }
        }

        if(data[index] == '.')
        {
            ++count;
        }
        if((count == 0) && (data[index] != '.') && (isdigit(data[index])))
        {
            ++size1;
        }
        if((count == 1) && (data[index] != '.') && (isdigit(data[index])))
        {
            ++size2;
        }
        if((count == 2) && (data[index] != '.') && (isdigit(data[index])))
        {
            ++size3;
        }

        if(count > 2)
        {
            return false;
        }
    }

    if(((size1 == 2) && (size2 == 2) && (size3 = 4)) || ((size1 == 4) && (size2 == 2) && (size3 = 2)))
    {
        return true;
    }
    else
    {
        return false;
    }
}


int Manager::castStringToInt(char* data)
{
    int number;

    if(isInt(data))
    {
        number = atoi(data);
    }

    return number;
}

double Manager::castStringToDouble(char* data)
{
    double number;

    if(isDouble(data))
    {
        number = atof(data);
    }

    return number;
}


char** Manager::rowsMember(char* data)
{
    int len = strlen(data);
    int countCol = countColumns(data);
    char** array = new char*[countCol+1];
    int start = 0;
    int end = 0;
    int count = 0;
    int index = 0;
    char* buff;

    for(int i = 0; i < len; ++i)
    {
        start = i;
        count = 0;
        while((data[i] != ',') && i < len)
        {
            ++count;
            ++i;
        }

        end = i;
        buff = new char[count+1];

        for(int j = start, m = 0; j < end; ++m, ++j)
        {
            buff[m] = data[j];
        }

        buff[count] = '\0';
        array[index] = new char[count + 1];
        strcpy(array[index],buff);
        ++index;
        delete [] buff;
    }


    return array;
}


int Manager::dateMember(char* data, char* date)
{
    int len = strlen(data);
    char** array = new char*[3+1];
    int start = 0;
    int end = 0;
    int count = 0;
    int index = 0;
    char* buff;

    for(int i = 0; i < len; ++i)
    {
        start = i;
        count = 0;
        while((data[i] != '.') && i < len)
        {
            ++count;
            ++i;
        }
        end = i;
        buff = new char[count+1];

        for(int j = start, m = 0; j < end; ++m, ++j)
        {
            buff[m] = data[j];
        }

        buff[count] = '\0';
        array[index] = new char[count + 1];
        strcpy(array[index],buff);
        ++index;
        delete [] buff;
    }

    for(int id = 0; id < 3+1; ++id)
    {

        if(strcmp(date, "day") == 0 && (strlen(array[0])==2))
        {
            return castStringToInt(Trim(array[0])); //trim
        }
        else if(strcmp(date, "day") == 0 && (strlen(array[2])==2))
        {
            return castStringToInt(Trim(array[2]));
        }
        else if(strcmp(date,"year") == 0 && (strlen(array[2])==4))
        {
            return castStringToInt(Trim(array[2]));
        }
        else if(strcmp(date,"year") == 0 && (strlen(array[0])==4))
        {
            return castStringToInt(Trim(array[0]));
        }
        else if(strcmp(date,"month") == 0)
        {
            //cout << castStringToInt(trim(array[1]));
            return castStringToInt(Trim(array[1]));
        }


    }
    return 0;
}


char* Manager::LTrim(char* szX)
{
    if((' '==szX[0]) || ('\t'==szX[0]) || ('\f'==szX[0]) ||
       ('\r'==szX[0]) || ('\v'==szX[0]) || ('\n'==szX[0]))
    while(' '== szX[0]) { ++szX;}

    return szX;
}

char* Manager::RTrim(char* szX)
{
    int i = strlen(szX);
    while ((' '==szX[i]) || ('\t' == szX[i]) || ('\v'==szX[i]) ||
           ('\f'==szX[i])  || ('\r'==szX[i]) || ('\n'==szX[i]))
    {
        szX[i] = 0;
        --i;

    }

    return szX;
}

char* Manager::Trim(char* szX)
{
    szX = LTrim(szX);
    szX = RTrim(szX);
    return szX;
}


bool Manager::validDate(char* data)
{
    int day = dateMember(data, "day");
    int month = dateMember(data, "month");
    int year = dateMember(data, "year");

    if(year >= 1900 && year <= 2018)
    {
        if(month <= 12 && month >= 1)
        {
            if((month == 2) && (day <= 28 && day >= 1))
            {
                return true;
            }
            else if((month % 2 != 0) && (day <= 31 && day >= 1))
            {
                return true;
            }
            else if((month % 2 == 0) && (day <= 30 && day >= 1))
            {
                return true;
            }
            else
            {
                return false;
            }

        }
        else
        {
            return false;
        }
    }

    return false;
}


int Manager::maxOfCountColumns(char* fileName)
{
    int countRows = countRowsInFile(fileName);
    int count = 0;

    ifstream myFile1(fileName);
    if(myFile1)
    {
        char buff[1024];
        while(myFile1.getline(buff, 1024))
        {
            char* row = new char[strlen(buff)+1];
            strcpy(row, buff);
            if(count < countColumns(row))
            {
                count = countColumns(row);
            }
        }
    }

    myFile1.close();

    return count;
}
