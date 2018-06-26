#include <iostream>
#include "ReadFromFile.h"

using namespace std;

int main()
{
    /*
    //fileName
    char name[1024];
    cin >> name;

    readFile(name);
    arrayOfCountColumns(name);
    */
    char proba[30];
    cin >> proba;
///*
    //??type
    cout << (isInt(proba) ? "Yes\n" : "No\n");
    int result = castStringToInt(proba);
    cout << result << " " << result+1 << endl;
    cout << (isDouble(proba) ? "Yes\n" : "No\n");
    double result1 = castStringToDouble(proba);
    cout << result1 << " " << result1+1 << endl;
    cout << (isDate(proba) ? "Yes\n" : "No\n");

//*/


    cout << (isDate(proba) ? "Yes\n" : "No\n");

/*

    //razdelqne na kletki
    char** array = rowsMember(proba);


    for(int id = 0; id < countColumns(proba)+1; ++id)
    {
        cout << array[id] << " ";
    }
*/
    return 0;
}
