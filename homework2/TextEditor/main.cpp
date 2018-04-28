#include <iostream>
#include "FileManager.h"
#include "FileEditor.h"
#include <string.h>

using namespace std;

int main(int argc, char* argsv[])
{
    char* fileName = new char[strlen(argsv[1]) + 1];
    strcpy(fileName, argsv[1]);


    FileManager m;
    m.readFile(fileName);


    while(true)
    {
        char buffer[20];
        cin >> buffer;

        if(strcmp("makeCombine", buffer) == 0)
        {
            int line, from, to;
            cin >> line >> from >> to;

            FileEditor e(line, from, to);
            e.makeCombine(m);
            cout << endl;
            cin.ignore();
        }
        else if(strcmp("makeHeading", buffer) == 0)
        {
            int line;
            cin >> line;

            FileEditor e(line);
            e.makeHeading(m);
            cout << endl;
            cin.ignore();
        }
        else if(strcmp("makeItalic", buffer) == 0)
        {
            int line, from, to;
            cin >> line >> from >> to;

            FileEditor e(line, from, to);
            e.makeItalic(m);
            cout << endl;
            cin.ignore();
        }
        else if(strcmp("makeBold", buffer) == 0)
        {
            int line, from, to;
            cin >> line >> from >> to;

            FileEditor e(line, from, to);
            e.makeBold(m);
            cout << endl;
            cin.ignore();
        }
        else if(strcmp("addLine", buffer) == 0)
        {
            cin.ignore();
            char lineContent[1024];
            cin.getline(lineContent, 1024);

            FileEditor e(0, 0, 0);
            e.addLine(m,lineContent);
            cout << endl;
        }
        else if(strcmp("remove", buffer) == 0)
        {
            cin.ignore();
            int lineNumber;
            cin >> lineNumber;

            FileEditor e(0, 0, 0);
            e.remove(m, lineNumber);
            cout << endl;
        }

        else if(strcmp("exit", buffer) == 0)
        {
            m.saveMdFile(fileName);
            cin.ignore();
            break;
        }


    }


    return 0;

}
