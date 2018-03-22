#include <string.h>


struct Order {
    //enum Type { SELL, BUY } type;
    char type[5];
    //unsigned walletId;
    int walletId;
    double fmiCoins;


    Order()
    {
        //type = t;
        //type = "";
        strcpy(type,"");
        walletId = 0;
        fmiCoins = 0.0;
    }
    Order(char* t,int id, double fmiC)
    {
        //type = t;
        strcpy(type,t);
        walletId = id;
        fmiCoins = fmiC;
    }
};
