#include "TypeInt.h"
#include <iostream>
#include <string.h>

using namespace std;


TypeInt::TypeInt() : value(0)
{

}


TypeInt::TypeInt(char* data)
{
    if(IntValid(data))
    {
        //syzdava obekt
    }
    else
    {
        //greshka i ne syzdava obekt
    }
}

bool TypeInt::IntValid(char* data)
{
    //int len = strlen(data) + 1;
    //if(data[0] == '-' || data[0] == '+')
    //{

    //}
}

int TypeInt::getValue() const
{
    return value;
}


void TypeInt::printData()
{
    cout << value;
}
