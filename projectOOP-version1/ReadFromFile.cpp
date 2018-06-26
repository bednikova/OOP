#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>     //atoi
#include <stdio.h>
#include <ctype.h>
#include "ReadFromFile.h"

using namespace std;

int readFile(char* fileName)
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


    cout << "count rows: " << countRows << endl;
    return countRows;
}

void arrayOfCountColumns(char* fileName)
{
    int countRows = readFile(fileName);
    int arrayWithcountColumns[countRows];

    int i = 0;

    ifstream myFile1(fileName);
    if(myFile1)
    {
        char buff[1024];
        while(myFile1.getline(buff, 1024))
        {
            char* row = new char[strlen(buff)+1];
            strcpy(row, buff);
            arrayWithcountColumns[i] = countColumns(row);
            ++i;
        }
    }

    myFile1.close();

    for(int index = 0; index < countRows; ++index)
    {
       cout << arrayWithcountColumns[index] << " ";
    }
    cout << endl;
}


int countColumns(char* row)
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

bool isInt(char* data)
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
}


bool isDouble(char* data)
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
}


bool isString(char* data)
{
    int len = strlen(data);


    for(int index = 0; index < len; ++index)
    {
        if(!isalpha(data[index]))
        {
            return false;
        }
    }

    return true;

}

bool isDate(char* data)
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

int castStringToInt(char* data)
{
    int number;

    if(isInt(data))
    {
        number = atoi(data);
    }

    return number;
}

double castStringToDouble(char* data)
{
    double number;

    if(isDouble(data))
    {
        number = atof(data);
    }

    return number;
}


char** rowsMember(char* data)
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
            //cout << "i and count " << i << " " << count << endl;
            end = i;
            buff = new char[count+1];

            for(int j = start, m = 0; j < end; ++m, ++j)
            {
                buff[m] = data[j];
            }

            buff[count] = '\0';
            array[index] = buff;
            ++index;
            delete [] buff;
        }
/*
        for(int id = 0; id < countCol+1; ++id)
        {
            cout << array[id] << " ";
        }

*/
        return array;
}
