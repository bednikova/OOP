#include <iostream>
#include <fstream>

using namespace std;


int returnId()
{
  int id = 0;
  ifstream myf("wallet.dat",ios::binary);
  if(!myf)
  {
       id = 1;
       myf.close();
       return id;
  }
  else
  {
      ifstream myfile ("probaId.txt");
      if (myfile.is_open())
      {

          myfile >> id;
          return ++id;
          //cout << ++id << '\n';


        myfile.close();
      }
      else cout << "Unable to open file";
  }

  //id = ++id;
  //return id;
}

void saveId(int id)
{

  ofstream myfile ("probaId.txt", ios::trunc);
  if (myfile.is_open())
  {
    myfile << id;

    myfile.close();
  }
  else cout << "Unable to open file";
}
