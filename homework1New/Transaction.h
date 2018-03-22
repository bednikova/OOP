#include <iostream>
#include <time.h>


using namespace std;

struct Transaction {
    long long time;
    unsigned senderId;
    unsigned receiverId;
    double fmiCoins;

    Transaction()
    {
        time = 0;     //time(NULL);
        senderId = 4294967295;
        receiverId = 0;
        fmiCoins = 0.0;
    }

};
