#include <iostream>
#include <string.h>


using namespace std;

struct Wallet {
    char owner[256];
    unsigned id;
    double fiatMoney;
    static int idd;
    Wallet()
    {
         strcpy(owner,"");
         fiatMoney = 0.0;
         //id = 0;
    }
    Wallet(char* name, double money)
    {
         strcpy(owner,name);
         fiatMoney = money;
         id = ++idd;
    }
};

int Wallet::idd = 0;
