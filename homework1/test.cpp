// extract to string
#include <iostream>
#include <string>

int main ()
{
  std::string name;
  std::string f;
  char c = ' ';
  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  //std::getline (std::cin,f,c);
  std::cout << "Hello, " << name <<"!\n";

  return 0;
}
