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
        //chete faila i vrysha broq na redovete
        int countRowsInFile(char* fileName);

        //vrysha broq na kolonite za daden red
        int countColumns(char* row);

        //proverqva dali string e int
        bool isInt(char* data);

        //proverqva dali string e double
        bool isDouble(char* data);

        //proverqva dali string e date
        bool isDate(char* data);

        //proverqva dali daden string e string ;d
        bool isString(char* data);

        //preobrazuva string kym chislo (int or double)
        //int
        int castStringToInt(char* data);
        //double
        double castStringToDouble(char* data);

        //razdelq na grupi, i vrysha masiv ot kletki
        //ne sym q realizirala
        char** rowsMember(char* data);

        //vrysha day, month or year // data
        int dateMember(char* data, char* date);

        //trim
        char* LTrim(char* szX);
        char* RTrim(char* szX);
        char* Trim(char* szX);

    private:

};
#endif
