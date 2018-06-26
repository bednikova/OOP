#include <iostream>
#include <fstream>
#include <string.h>
#include "ReadFromFile.h"

using namespace std;

void readFile(char* fileName)
{
    ifstream myFile(fileName);

    if(myFile)
    {
        char buff[1024];
        while(myFile.getline(buff, 1024))
        {
            char* row = new char[strlen(buff)+1];
            strcpy(row, buff);
            cout << row << endl;
        }
    }

    myFile.close();
}


