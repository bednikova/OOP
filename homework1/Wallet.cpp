#include <iostream>
#include <fstream>
#include <string.h>
#include "Wallet.h"
#include "Transaction.cpp"

using namespace std;



//create wallet -> helper function for read of binary files
Wallet createWallet(char* name, double money, int idd)  //char* id)//unsigned id)
{
      Wallet w;
      strcpy(w.owner,name);
      w.id = idd;   // problem ;d
      //strcpy(w.id, id);
      w.fiatMoney = money;


      return w;
}





//print wallet ->
//id: .. name: .. money: ..
void printWallet(Wallet w)
{
    std::cout << "Id: " << w.id << "\tName: " << w.owner << "\tMoney: " << w.fiatMoney << "\n";
}






//Emo
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


//Emo
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
        int id;
        //unsigned id;
        //char* id;
        myfile.read((char*)&id, sizeof(id));
        double fiatMoney;
        //myfile.read((char*)&id, sizeof(id));
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
        int id;
        //unsigned id;
        //char* id;
        myfile.read((char*)&id, sizeof(id));
        double fiatMoney;
        //myfile.read((char*)&id, sizeof(id));
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
    //Wallet w;
    ifstream myfile("wallet.dat", ios::binary);  //open

    do  // for( ; myfile; )
    {


        Wallet w;
        if(myfile)
        {
            int len;
            myfile.read((char*)&len, sizeof(len));
            char* buff = new char[len+1];
            myfile.read(buff, len);
            //unsigned id;
            int id;
            double fiatMoney;
            myfile.read((char*)&id, sizeof(id));
            myfile.read((char*)&fiatMoney, sizeof(fiatMoney));

            //..
            /*
            int len1;
            myfile.read((char*)&len1, sizeof(len1));
            char* id = new char[len1+1];
            myfile.read(id, len1);
            */

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


//probrem function
void searchWaller(int idd)
{
    //Wallet w;
    ifstream myfile("wallet.dat", ios::binary);  //open

    do  // for( ; myfile; )
    {


        Wallet w;
        if(myfile)
        {
            int len;
            myfile.read((char*)&len, sizeof(len));
            char* buff = new char[len+1];
            myfile.read(buff, len);
            //unsigned id;
            int id;
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
