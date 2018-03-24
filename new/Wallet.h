#include <iostream>
#include <string.h>
#include "idGen.cpp"

using namespace std;

struct Wallet {
    char owner[256];
    unsigned id;
    double fiatMoney;

    Wallet();

    Wallet(char* name, double money);

};

