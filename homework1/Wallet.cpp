#include <iostream>
#include <fstream>
#include <string.h>
#include "Wallet.h"

using namespace std;




Wallet createWallet(char* name, double money, unsigned id)
{
      Wallet w;
      strcpy(w.owner,name);
      w.id = id;   // problem ;d
      w.fiatMoney = money;


      return w;
}


void printWallet(Wallet w)
{
    std::cout << "\nId: " << w.id << "\tName: " << w.owner << "\tMoney: " << w.fiatMoney << endl;
}






//Emo
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


//Emo
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

    printWallet(w);

    myfile.close();
}



