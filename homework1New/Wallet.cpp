#include <iostream>
#include <fstream>
#include <string.h>
#include "Wallet.h"
//#include "Transaction.cpp"

using namespace std;



//create wallet -> helper function for read of binary files
Wallet createWallet(char* name, double money, unsigned _id)
{
      Wallet w;
      strcpy(w.owner,name);
      w.id = _id;
      w.fiatMoney = money;

      return w;
}



//print wallet ->
//id: .. name: .. money: ..
void printWallet(Wallet w)
{
    std::cout << "Id: " << w.id
              << "\tName: " << w.owner
              << "\tMoney: " << w.fiatMoney
              << "\n";
}



//write one object
void writeBinary(const Wallet &w)
{
    ofstream myfile("wallet.dat", ios::binary|ios::app);  //open

    if(myfile)
    {
        int len = strlen(w.owner)+1;
        myfile.write((char*)&len, sizeof(len));
        myfile.write(w.owner, len);
        myfile.write((char*)&w.id, sizeof(w.id));
        myfile.write((char*)&w.fiatMoney, sizeof(w.fiatMoney));
    }
    else
    {
        cout << "Error \n";
    }


    myfile.close();
}


//read first row
void readBinary()
{
    Wallet w;
    ifstream myfile("wallet.dat", ios::binary);  //open

    if(myfile)
    {
        int len;
        myfile.read((char*)&len, sizeof(len));
        char* buff = new char[len+1];
        myfile.read(buff, len);
        unsigned id;
        myfile.read((char*)&id, sizeof(id));
        double fiatMoney;
        myfile.read((char*)&fiatMoney, sizeof(fiatMoney));

        w = createWallet(buff, fiatMoney, id);

        delete [] buff;
    }
    else
    {
        cout << "Error \n";
    }

    printWallet(w);

    myfile.close();
}


//info
Wallet infoInReadBinary()
{
    Wallet w;
    ifstream myfile("wallet.dat", ios::binary);  //open

    if(myfile)
    {
        int len;
        myfile.read((char*)&len, sizeof(len));
        char* buff = new char[len+1];
        myfile.read(buff, len);
        unsigned id;
        myfile.read((char*)&id, sizeof(id));
        double fiatMoney;
        myfile.read((char*)&fiatMoney, sizeof(fiatMoney));

        w = createWallet(buff, fiatMoney, id);

        delete [] buff;
    }
    else
    {
        cout << "Error \n";
    }

    //printWallet(w);

    myfile.close();

    return w;
}


//read file
void readBinaryFile()
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

        if(myfile)   //not read -> end files
            printWallet(w);
    }while(myfile);

    myfile.close();

}


//function search in waller
void searchWaller(unsigned idd)
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
                printWallet(w);
                myfile.close();
                return;
        }
        if(!myfile)
            cout << "Sorry id is not valid! \n";
    }while(myfile);

    myfile.close();
}


//valid id
//function valid waller id
bool validWaller(unsigned idd)
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
