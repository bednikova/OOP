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


//valid id
//function valid waller id
bool validWallet(unsigned idd)
{
    ifstream myfile("wallet.dat", ios::binary);  //open

    do
    {
        Wallet w;
        if(myfile)
        {
            int len;
            myfile.read((char*)&len, sizeof(len));
            char* buff = new char[len+1];
            myfile.read(buff, len);
            unsigned id;
            double fiatMoney;
            myfile.read((char*)&id, sizeof(id));
            myfile.read((char*)&fiatMoney, sizeof(fiatMoney));

            w = createWallet(buff, fiatMoney, id);

            delete [] buff;
        }
        else
        {
            cout << "Error \n";
        }

        if(myfile && w.id == idd)   //not read -> end files
        {
                myfile.close();
                return true;
        }
        if(!myfile)
            //cout << "Sorry id is not valid! \n";
            return false;
    }while(myfile);

    myfile.close();
}


//return fmiCoins
double searchWalletIdMoney(unsigned idd)
{

    double fmiCoinsNew = 0.0;
    ifstream myfile("transaction.dat", ios::binary);

    do
    {
        Transaction t;
        if(myfile)
        {
            long long time;
            unsigned senderId;
            unsigned receiverId;
            double fmiCoins;
            myfile.read((char*)&time, sizeof(time));
            myfile.read((char*)&senderId, sizeof(senderId));
            myfile.read((char*)&receiverId, sizeof(receiverId));
            myfile.read((char*)&fmiCoins, sizeof(fmiCoins));

            t = createTransaction1(senderId, receiverId, fmiCoins,time);
        }
        else
        {
            cout << "Error \n";
        }

        if(myfile && t.receiverId == idd)
            fmiCoinsNew += t.fmiCoins;
        if(myfile && t.senderId == idd)
            fmiCoinsNew -= t.fmiCoins;
    }while(myfile);

    myfile.close();


    return fmiCoinsNew;

}



//return fiatMoney
double searchWalletIdFiatMoney(unsigned idd)
{


    ifstream myfile("transaction.dat", ios::binary);
    double  money;

    do
    {
        Transaction t;
        if(myfile)
        {
            long long time;
            unsigned senderId;
            unsigned receiverId;
            double fmiCoins;
            myfile.read((char*)&time, sizeof(time));
            myfile.read((char*)&senderId, sizeof(senderId));
            myfile.read((char*)&receiverId, sizeof(receiverId));
            myfile.read((char*)&fmiCoins, sizeof(fmiCoins));

            t = createTransaction1(senderId, receiverId, fmiCoins,time);
        }
        else
        {
            cout << "Error \n";
        }
        if(myfile && t.senderId == 4294967295)
            money += t.fmiCoins*375;

        if(myfile && t.senderId == idd)
            money -= t.fmiCoins*375;
        if(myfile && t.receiverId == idd && t.senderId != 4294967295)
            money += t.fmiCoins*375;
    }while(myfile);

    myfile.close();


    return money;

}

//za kupuvane na moneti
//t.e. sme sigurni che e buy
//proverqvame dali parite shte mu stignat
//da napravi pokupka na moneti
bool isValidSELL(const Order &o)
{
    //po wallet id -> tyrsi v wallet.dat
    //vzavisimost ot tova dali prodava ili kupuva dali ima dostatychno pari
    //ako nqma vyobshe nqma da go zaspisva vyy faila sys narejdaniqta ;d
    //cout << "Sorry not money or fmiCoins";
    //cout << "FmiCoins: \t " << searchWalletIdMoney(o.walletId) << endl;
    //cout << "SearchWallet divided by 375: \t " << searchWalletIdMoney(o.walletId)/375 << endl;
    //cout << "o.fmicoins: \t " << o.fmiCoins << endl;

    if(validWallet(o.walletId) && searchWalletIdMoney(o.walletId) >= o.fmiCoins)
    {
            return true;
    }
    else
        return false;

}



//buy
bool isValidBUY(const Order &o)
{
    //cout << "FiatMoney: \t " << searchWalletIdFiatMoney(o.walletId) << endl;
    if(validWallet(o.walletId) && searchWalletIdFiatMoney(o.walletId) >= o.fmiCoins*375)
    {
            return true;
    }
    else
        return false;



}






//write one object
void writeBinaryFileOrders(const Order &o)
{
    if((isValidBUY(o) && strcmp(o.type, "BUY")) || (isValidSELL(o) && strcmp(o.type, "SELL")))
    {
        ofstream myfile("order.dat", ios::binary|ios::app);  //open

        if(myfile)
        {
            int len = strlen(o.type)+1;
            myfile.write((char*)&len, sizeof(len));
            myfile.write(o.type, len);
            myfile.write((char*)&o.walletId, sizeof(o.walletId));
            myfile.write((char*)&o.fmiCoins, sizeof(o.fmiCoins));
        }
        else
        {
            cout << "Error \n";
        }
        myfile.close();
    }
    else
        cout << "Sorry! \n";

}



//read file
void readBinaryFileOrder()
{

    ifstream myfile("order.dat", ios::binary);  //open

    do
    {
        Order o;
        if(myfile)
        {
            int len;
            myfile.read((char*)&len, sizeof(len));
            char* buff = new char[len+1];
            myfile.read(buff, len);

            unsigned id;
            double fmiCoins;

            myfile.read((char*)&id, sizeof(id));
            myfile.read((char*)&fmiCoins, sizeof(fmiCoins));


            o = createOrder(buff,id, fmiCoins);

            delete [] buff;


        }
        else
        {
            cout << "Error \n";
        }

        if(myfile)   //not read -> end files
            printOrder(o);
    }while(myfile);

    myfile.close();

}




void searchTransaction(unsigned idd)
{

    if(validWallet(idd))
    {
            ifstream myfile("transaction.dat", ios::binary);

            do
            {
                Transaction t;
                if(myfile)
                {
                    long long time;
                    unsigned senderId;
                    unsigned receiverId;
                    double fmiCoins;
                    myfile.read((char*)&time, sizeof(time));
                    myfile.read((char*)&senderId, sizeof(senderId));
                    myfile.read((char*)&receiverId, sizeof(receiverId));
                    myfile.read((char*)&fmiCoins, sizeof(fmiCoins));

                    t = createTransaction1(senderId, receiverId, fmiCoins, time);
                }
                else
                {
                    cout << "Error \n";
                }

                if(myfile && (t.receiverId == idd || t.senderId == idd))
                    printTransaction(t);
            }while(myfile);

            myfile.close();
    }
    else
        cout << "Error is not valid id! \n";

}









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
          //readBinaryFileTransaction();

          writeBinary(w);
          //std::cout << endl;

          //read first/last wallet
          //readBinary();

          //test
          //read binary file
          //readBinaryFile();


          //zapisva vyv fail obshtata inf
          //GroupInfo groupInfo = createGroupInfo(w,t);
          //saveWalletInfo(groupInfo);

          std::cout << endl;

}



void makeOrder()
{
            //make-order

            char type[5];
            cin >> type;


            unsigned walletId;
            cin >> walletId;


            double fmiCoins;
            cin >> fmiCoins;



            //....
            Order o = createOrder(type,walletId, fmiCoins);
            writeBinaryFileOrders(o);

            //test
            //readBinaryFileOrder();
}



void walletInfo()
{
          unsigned walletId;
          cin >> walletId;

          //function
          //-> info  for  walletId

          //info
          //groupSearch(walletId);

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


