#include <iostream>
#include <fstream>
#include "Order.h"

using namespace std;


Order createOrder(char* type,unsigned id, double money)
{
    Order o;
    strcpy(o.type,type);
    o.walletId = id;
    o.fmiCoins = money;



    return o;
}



void printOrder(Order &o)
{
    cout << "Type: " << o.type

         << "\tId: " << o.walletId

         << "\tfmiCoins: " << o.fmiCoins

         << endl;
}


//write one object
void writeBinaryFileOrders(const Order &o)
{
    if(validWaller(o.walletId))
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
        cout << "Sorry id is not valid! \n";

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


