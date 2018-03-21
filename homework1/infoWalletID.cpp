#include <iostream>
#include "Wallet.cpp"
//#include "Order.cpp"
//#include "Transaction.cpp"
#include <fstream>
#pragma once

using namespace std;

//info for waller
void searchWaller(int walletId)
{
        //Wallet w = infoInReadBinary();
        if(infoInReadBinary().id == walletId)
        {
            printWallet(infoInReadBinary());
        }

}

/*

//info for transaction
void searchTransaction(unsigned walletId)
{

}

//info for order
void searchOrder(unsigned walletId)
{

}

//print info for wallerId
void printInfoWaller(unsigned walletId)
{

}


*/
