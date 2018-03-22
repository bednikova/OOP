// writing on a text file
#include <iostream>
#include <fstream>
using namespace std;
/*
int main () {
  ofstream myfile ("example.txt", ios::app);
  if (myfile.is_open())
  {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
*/


int main () {
  int id = 1;
  ofstream myfile ("probaId.txt", ios::app);
  if (myfile.is_open())
  {
    myfile << id;

    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
