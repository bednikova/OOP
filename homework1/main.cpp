#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Wallet.cpp"
#include "Transaction.cpp"
#include "Order.cpp"
//#pragma once

using namespace std;


int main()
{

    char c = ' ';  //delim
    std::string comand;
    std::getline (std::cin,comand,c);



  if(comand == "add-wallet")
  {
      //create wallet
      std::cout << "ok";
      //std::string fiatMoney;
      double fiatMoney;
      cin >> fiatMoney;
      //std::getline (std::cin,fiatMoney,c);

       //std::string name;
       //std::getline (std::cin,name);
       char name[256];
       cin >> name;

      //create object wallet
      //and save in the files

      Wallet w = createWallet(name, fiatMoney);
      printWallet(w);


  }
  else if(comand == "make-order")
  {
        //info
        std::string type;
        std::getline (std::cin, type, c);

        double fmiCoins;
        cin >> fmiCoins;
        //std::string fmiCoins;
        //std::getline (std::cin, fmiCoins, c);

        unsigned walletId;
        cin >> walletId;
        //std::string walletId;
        //std::getline (std::cin, walletId);


        //....


  }
  else if(comand == "wallet-info")
  {
      std::string walletId;
      std::getline (std::cin, walletId);

      //function
      //-> info  for  walletId
  }
  else if(comand == "attract-investors")
  {
      std::string finaly;
      std::getline (std::cin, finaly);

      //function
      //info - > 10 ...

  }
  else if(comand == "quit")
  {
      //for final
      std::string finaly;
      std::getline (std::cin, finaly);
      //...

      return 0;
  }
  else
  {
      std::cout << " : ( ";
  }







    return 0;
}
