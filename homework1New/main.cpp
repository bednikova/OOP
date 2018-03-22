#include <iostream>
#include "functions.cpp"

using namespace std;

int main()
{
    do{
        char c = ' ';  //delim
        std::string comand;
        std::getline (std::cin,comand,c);



      if(comand == "add-wallet")
      {
          //create wallet
          addWallet();
      }
      else if(comand == "make-order")
      {
            makeOrder();
      }
      else if(comand == "wallet-info")
      {
            walletInfo();
      }
      else if(comand == "attract-investors")
      {
            attractInvestors();
      }
      else if(comand == "quit")
      {
            quit();
            return 0;
      }
      else
      {

      }

    }while(true);

    return 0;
}
