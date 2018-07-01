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

            /*
            //test
            cout << "copy1 \n";
            Table t2;
            t2 = tablica;
            t2.printTable();
            cout << "copy2 \n";
            Table t3(tablica);
            t3.printTable();
            cout << "copy3 \n";
            Table t4("newFile.txt");
            t4.printTable();
            cout << "copy4 \n";
            Table t5 = tablica;
            t5.printTable();

            */

            //tablica.sortColumns(numberColumn);
            tablica.sort(numberColumn, tablica);
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









