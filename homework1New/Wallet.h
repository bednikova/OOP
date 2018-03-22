#include <iostream>
#include <string.h>
#include "idGen.cpp"

using namespace std;

struct Wallet {
    char owner[256];
    unsigned id;
    double fiatMoney;

    Wallet()
    {
         strcpy(owner,"");
         fiatMoney = 0.0;
    }

    Wallet(char* name, double money)
    {
         strcpy(owner,name);
         fiatMoney = money;
         id = returnId();
         saveId(id);
    }


};

