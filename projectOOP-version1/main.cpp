#include <iostream>
#include "ReadFromFile.h"

using namespace std;

int main()
{
    char name[1024];
    cin >> name;

    readFile(name);
    arrayOfCountColumns(name);

    char proba[30];
    cin >> proba;

    cout << (isInt(proba) ? "Yes\n" : "No\n");
    int result = castStringToInt(proba);
    cout << result << " " << result+1 << endl;
    cout << (isDouble(proba) ? "Yes\n" : "No\n");
    double result1 = castStringToDouble(proba);
    cout << result1 << " " << result1+1 << endl;
    cout << (isDate(proba) ? "Yes\n" : "No\n");


    return 0;
}
