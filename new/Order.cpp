#include <iostream>
#include <fstream>
#include "Order.h"


using namespace std;


Order createOrder(char* type,unsigned id, double money)
{
    Order o;
    strcpy(o.type,type);
    o.walletId = id;
    o.fmiCoins = money;



    return o;
}



void printOrder(Order &o)
{
    cout << "Type: " << o.type

         << "\tId: " << o.walletId

         << "\tfmiCoins: " << o.fmiCoins

         << endl;
}


