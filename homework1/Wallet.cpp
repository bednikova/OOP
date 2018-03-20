#include <iostream>
#include <fstream>
#include <string.h>
#include "Wallet.h"

using namespace std;

Wallet createWallet(char* name, double money)
{
      Wallet w;
      strcpy(w.owner,name);
      w.id = ++w.id;   // problem ;d
      w.fiatMoney = money;


      return w;
}


void printWallet(Wallet w)
{
    std::cout << "\nId: " << w.id << "\tName: " << w.owner << "\tMoney: " << w.fiatMoney << endl;
}



//save in binary files
void readInFiles(Wallet w)
{

}
