#include <string.h>


struct Order {
    //enum Type { SELL, BUY } type;
    char type[5];
    unsigned walletId;
    double fmiCoins;


    Order()
    {
        strcpy(type,"");
        walletId = 0;
        fmiCoins = 0.0;
    }

    Order(char* _type,unsigned _walletId, double _fmiCoins)
    {
        strcpy(type,_type);
        walletId = _walletId;
        fmiCoins = _fmiCoins;
    }
};
