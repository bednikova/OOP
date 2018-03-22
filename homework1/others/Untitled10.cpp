// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/*
int main () {
  string line;

  ifstream myfile ("test.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }

  else cout << "Unable to open file";

  return 0;
}

*/
int main()
{

  //string id;
  int id;
  ifstream myfile ("probaId.txt");
  if (myfile.is_open())
  {

      myfile >> id;
      cout << ++id << '\n';


    myfile.close();
  }
  else cout << "Unable to open file";
  return 0;
}


