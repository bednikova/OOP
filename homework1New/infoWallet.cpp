

//write one object
void writeBinaryFileInfoWallet(const Wallet &w, const Transaction &t)
{

            ofstream myfile("infowallet.dat", ios::binary|ios::app);
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

    if(validWaller(idd))
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
