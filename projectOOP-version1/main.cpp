#include <iostream>
#include "ReadFromFile.h"

using namespace std;

int main()
{
    char name[1024];
    cin >> name;

    readFile(name);

    return 0;
}
