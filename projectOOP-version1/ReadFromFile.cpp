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
    int len = strlen(data)+1;


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


    if((data[0] == '-') || (data[0] == '+') || isdigit(data[0]) == '0-9')
    {
        return true;
    }
}


bool isDouble(char* data)
{
    int len = strlen(data)+1;


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

    if((data[0] == '-') || (data[0] == '+') || isdigit(data[0]) == '0-9')
    {
        return true;
    }
}


bool isString(char* data)
{
    int len = strlen(data)+1;


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
    int len = strlen(data)+1;


    for(int index = 0; index < len; ++index)
    {
        if(isalpha(data[index]))
        {
            return false;
        }
    }

    for(int index = 0; index < len; ++index)
    {
        if((data[index] == '\"') || (data[index] == ' ') || (data[index] == '-') || (data[index] == '+'))
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

    if(count > 2)
    {
        return false;
    }

    //2+4+2+2
    return (len == 11) ? true : false;
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
