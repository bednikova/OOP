#include <iostream>
#include <string.h>

#include <fstream>
#include <stdlib.h>




using namespace std;


char* getUniqueIdentifier() {
    static int eggIdCounter = 0;
    //char name[] = "egg";
    //char* id = new char(strlen(name + 1));
    char* id;
    sprintf(id, "%d", eggIdCounter++);
    //strcat(id, name);
    return id;
}


int main()
{

    for(int i = 0; i < 10; i++)
    {
        char* p = getUniqueIdentifier();
        int t = (int)p;
        cout << p << endl;
    }



}
