#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include "Wallet.cpp"
#include "Order.cpp"
#include "Transaction.cpp"
//#include <cstdlib>
#pragma once

using namespace std;





void addWallet()
{
          //create wallet

          double fiatMoney;
          cin >> fiatMoney;

          char name[256];
          cin >> name;

          //create object wallet
          //and save in the files

          Wallet w(name, fiatMoney);
          //print wallet w
          //printWallet(w);


          Transaction t = createTransaction(w);
          //printTransaction(t);
          writeBinaryFileTransactions(t);

          //test
          readBinaryFileTransaction();

          writeBinary(w);
          //std::cout << endl;

          //read first/last wallet
          //readBinary();

          //test
          //read binary file
          readBinaryFile();

          std::cout << endl;

}



void makeOrder()
{
            //make-order

            char type[6];
            cin >> type;


            unsigned walletId;
            //int walletId;
            cin >> walletId;


            double fmiCoins;
            cin >> fmiCoins;



            //....
            Order o = createOrder(type,walletId, fmiCoins);
            writeBinaryFileOrders(o);
            readBinaryFileOrder();
}



void walletInfo()
{
           unsigned walletId;
          //int walletId;
          cin >> walletId;

          //function
          //-> info  for  walletId

          //info - wallet
          searchWaller(walletId);

          //info - transactions
          searchTransaction(walletId);
}



void attractInvestors()
{
          std::string finaly;
          std::getline (std::cin, finaly);

          //function
          //info - > 10 ...
}


int quit()
{
          //for final
          std::string finaly;
          std::getline (std::cin, finaly);
          //...

          return 0;
}
