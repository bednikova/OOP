#include <iostream>
#include <fstream>

using namespace std;


unsigned returnId()
{
  unsigned id;
  ifstream myf("wallet.dat",ios::binary);
  if(!myf)
  {
       ++id;
       myf.close();
       return id;
  }
  else
  {
      ifstream myfile ("walletId.txt");
      if (myfile.is_open())
      {

          myfile >> id;
          myfile.close();
          return ++id;
      }
      else cout << "Unable to open file";
  }

}

void saveId(unsigned id)
{

  ofstream myfile ("walletId.txt", ios::trunc);
  if (myfile.is_open())
  {
    myfile << id;

    myfile.close();
  }
  else cout << "Unable to open file";
}
