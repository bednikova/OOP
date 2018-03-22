#include <iostream>
#include <string.h>
#include "idGen.cpp"
//#include "Transaction.cpp"


using namespace std;

struct Wallet {
    char owner[256];
    int id;
    //unsigned id;
    //char* id;
    double fiatMoney;
    //static int idd;
    Wallet()
    {
         strcpy(owner,"");
         fiatMoney = 0.0;
         //id = 0;
         //id = returnId()-1;
    }
/*
    char* getUniqueIdentifier()
    {
        static int counter = 0;
        char* id;
        sprintf(id, "%d", counter++);
        return id;
    }
*/

    Wallet(char* name, double money)
    {
         strcpy(owner,name);
         fiatMoney = money;
         id = returnId();
         saveId(id);
         //Transaction t;
    }

    int getID() const
    {
        return id;
    }

};

//int Wallet::idd = ++idd;
