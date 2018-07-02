#include <iostream>
#include <string.h>
#include <stdlib.h>     //atoi
#include <stdio.h>
#include <ctype.h>
#include <fstream>

using namespace std;

#ifndef __MANAGER_H__
#define __MANAGER_H__

class Manager
{
    public:
        int countRowsInFile(char* fileName);

        int countColumns(char* row);

        bool isInt(char* data);
        bool isDouble(char* data);
        bool isDate(char* data);
        bool isString(char* data);

        //int
        int castStringToInt(char* data);
        //double
        double castStringToDouble(char* data);

        char** rowsMember(char* data);

        //day, month or year // data
        int dateMember(char* data, char* date);

        //trim
        char* LTrim(char* szX);
        char* RTrim(char* szX);
        char* Trim(char* szX);

        //valid Date
        bool validDate(char* data);

        //max count of columns
        int maxOfCountColumns(char* fileName);

    private:

};
#endif
