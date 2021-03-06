#include <iostream>
#include <string.h>
#include "Table.h"

using namespace std;

int main(int argc, const char * argv[])
{

   //fileName
    char fileName[100];
    cout << "Input file name: ";
    cin >> fileName;
    cout << endl;

    Table tablica;



    while(true)
    {
        char buffer[20];
        cin >> buffer;

        if(strcmp("load", buffer) == 0)
        {
            if(!tablica.loadDataFromFile(fileName))
            {
                return 0;
            }
            cout << endl;
            cin.ignore();
        }
        else if(strcmp("save", buffer) == 0)
        {
            tablica.saveDataFromFile("newFile.txt");
            cout << endl;
            cin.ignore();
        }
        else if(strcmp("sort", buffer) == 0)
        {
            int numberColumn;
            cin >> numberColumn;

            char flag;
            cin >> flag;

            //tablica.sortColumns(numberColumn)
            if(flag == 'n')
            {
                tablica.sort2(numberColumn, tablica);
            }
            else
            {
                tablica.sort(numberColumn, tablica);
            }

            //tablica.sort(numberColumn, tablica);
            //tablica.sort(numberColumn, tablica);
            cout << endl;
            cin.ignore();
        }
        else if(strcmp("print", buffer) == 0)
        {
            tablica.printTable();

            cout << endl;
            cin.ignore();
        }
        else if(strcmp("edit", buffer) == 0)
        {
            cin.ignore();
            int row;
            int column;
            cin >> row >> column;

            char content[1024];
            cin.getline(content, 1024);

            tablica.editCell(row, column, content);
            cout << endl;
        }
        else if(strcmp("exit", buffer) == 0)
        {
            cin.ignore();
            break;
        }


    }

    return 0;
}









