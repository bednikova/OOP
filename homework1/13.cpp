#include <iostream>
#include <fstream>

using namespace std;


int main()
{

    ofstream myfile("13.txt", ios::app);
    if(myfile)
    {

        unsigned id = 5;
        myfile.write((char*)&id, sizeof(id));
        //cout << id << " " ;

    }
    else
    {
        cout << "Error \n";
    }
    myfile.close();

    ifstream myfile1("13.txt");
    if(myfile1)
    {

        unsigned id;
        myfile1.read((char*)&id, sizeof(id));
        cout << id << " " ;

    }
    else
    {
        cout << "Error \n";
    }


}
