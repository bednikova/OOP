#include <iostream>
#include <fstream>
#include "Transaction.h"
//#include "Wallet.cpp"
#pragma once

using namespace std;

Transaction createTransaction(Wallet &w, int s = 4294967295)
{
    Transaction t;
    t.time = time(NULL);
    t.fmiCoins = w.fiatMoney/375;
    t.senderId = s;
    t.receiverId = w.id;


    return t;
}


Transaction createTransaction1(int s, int r, double fmi,long long time)
{
    Transaction t;
    t.time = time;
    t.fmiCoins = fmi;
    t.senderId = s;
    t.receiverId = r;


    return t;
}

void printTransaction(Transaction &t)
{
    cout << "Time: " << t.time
         << "\tSenderId: " << t.senderId
         << "\tReceiverId: " << t.receiverId
         << "\tfmiCoins: " << t.fmiCoins << endl;
}


//write one object
void writeBinaryFileTransactions(const Transaction &t)
{
    ofstream myfile("transaction.dat", ios::binary|ios::app);  //open

    if(myfile)
    {
        //int len = strlen(w.owner)+1;
        //myfile.write((char*)&len, sizeof(len));
        //myfile.write(w.owner, len);
        myfile.write((char*)&t.time, sizeof(t.time));
        myfile.write((char*)&t.senderId, sizeof(t.senderId));
        myfile.write((char*)&t.receiverId, sizeof(t.receiverId));
        myfile.write((char*)&t.fmiCoins, sizeof(t.fmiCoins));
    }
    else
    {
        cout << "Error \n";
    }


    myfile.close();
}



//read file
void readBinaryFileTransaction()
{

    ifstream myfile("transaction.dat", ios::binary);  //open

    do
    {


        Transaction t;
        if(myfile)
        {
            long long time;
            int senderId;
            int receiverId;
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

        if(myfile)   //not read -> end files
            printTransaction(t);
    }while(myfile);

    myfile.close();

}



void searchTransaction(int idd)
{
    ifstream myfile("transaction.dat", ios::binary);  //open

    do
    {


        Transaction t;
        if(myfile)
        {
            long long time;
            int senderId;
            int receiverId;
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

        if(myfile && (t.receiverId == idd || t.senderId == idd))   //not read -> end files
            printTransaction(t);
        //if(!myfile)
         //   cout << "Sorry id is not valid! \n";
    }while(myfile);

    myfile.close();
}


