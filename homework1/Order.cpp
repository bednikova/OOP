#include <iostream>
#include <fstream>
#include "Order.h"

using namespace std;


Order createOrder(char* t,int id, double m)
{
    Order o;
    //o.Type = t;
    strcpy(o.type,t);
    o.walletId = id;
    o.fmiCoins = m;



    return o;
}



void printOrder(Order &o)
{
    cout << "Type: " << o.type
         << "\tId: " << o.walletId
         << "\tfmiCoins: " << o.fmiCoins << endl;
}


//write one object
void writeBinaryFileOrders(const Order &o)
{
    ofstream myfile("order.dat", ios::binary|ios::app);  //open

    if(myfile)
    {
        int len = strlen(o.type)+1;
        myfile.write((char*)&len, sizeof(len));
        myfile.write(o.type, len);
        //myfile.write((char*)&o.Type, sizeof(o.Type));
        myfile.write((char*)&o.walletId, sizeof(o.walletId));
        //myfile.write((char*)&t.receiverId, sizeof(t.receiverId));
        myfile.write((char*)&o.fmiCoins, sizeof(o.fmiCoins));
    }
    else
    {
        cout << "Error \n";
    }


    myfile.close();
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

            int id;

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


/*
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

*/
