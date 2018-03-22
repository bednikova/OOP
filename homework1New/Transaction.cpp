#include <iostream>
#include <fstream>
#include "Transaction.h"
#pragma once

using namespace std;

Transaction createTransaction(Wallet &w, unsigned _senderId = 4294967295)
{
    Transaction t;

    t.time = time(NULL);
    t.fmiCoins = w.fiatMoney/375;
    t.senderId = _senderId;
    t.receiverId = w.id;


    return t;
}


Transaction createTransaction1(unsigned _senderId, unsigned _receiverId, double _fmiCoins,long long _time)
{
    Transaction t;

    t.time = _time;
    t.fmiCoins = _fmiCoins;
    t.senderId = _senderId;
    t.receiverId = _receiverId;


    return t;
}

void printTransaction(Transaction &t)
{
    cout << "Time: " << t.time
         << "\tSenderId: " << t.senderId
         << "\tReceiverId: " << t.receiverId
         << "\tfmiCoins: " << t.fmiCoins
         << endl;
}


//write one object
void writeBinaryFileTransactions(const Transaction &t)
{
    ofstream myfile("transaction.dat", ios::binary|ios::app);
    if(myfile)
    {
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

        if(myfile)
            printTransaction(t);
    }while(myfile);

    myfile.close();

}



void searchTransaction(unsigned idd)
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


