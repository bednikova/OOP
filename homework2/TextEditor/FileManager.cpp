#include <iostream>
#include <string.h>
#include <fstream>
#include "FileManager.h"

using namespace std;


FileManager::FileManager() : content(NULL), numberOfLines(0)
{

}

FileManager::FileManager(const FileManager& m)
{
    copyHelp(m);
}

FileManager::~FileManager()
{
    deleteHelp();
}

FileManager& FileManager::operator=(const FileManager& m)
{
    if (this != &m) {
        deleteHelp();
        copyHelp(m);
    }

    return *this;
}


void FileManager::print() const
{
    for (int i = 0; i < numberOfLines; ++i)
    {
        cout << content[i] << endl;
    }
}



const char* FileManager::getLineAt(int index) const
{
    return content[index-1];
}



void FileManager::readFile(char* fileName)
{
    std::ifstream input(fileName);

    int numLines = 0;
    if (input)
    {
        char buffer[1024];  //1025?

        while(input.getline(buffer, 1024))
        {
            numLines++;
        }
    }
    else
    {
        cout << "Error \n";  //trqbva da ima exceptions
    }

    input.close();

    numberOfLines = numLines;
    content = new char*[numberOfLines];
    for(int index = 0; index <  numberOfLines; ++index)
    {
        content[index] = new char[1024];
    }


    std::ifstream input1(fileName);
    if(input1)
    {
        char buffer[1024];
        int currentLine = 0;
        while (input1.getline(buffer, 1024))
        {
            int lenght = strlen(buffer) + 1;
            content[currentLine] = new char[lenght];
            strcpy(content[currentLine], buffer);

            currentLine++;
        }
    }
    else
    {
        cout << "Error! Fili not open \n"; //exception
    }

    input1.close();
}



void FileManager::makeHeading(int line)
{
    line = line - 1;
    char* currentLine = content[line];
    int length = strlen(content[line]) + 3;

    char* headingLine = new char[length];

    strcpy(headingLine, "# ");
    strcat(headingLine, currentLine);

    delete [] currentLine;
    content[line] = headingLine;
}


void FileManager::saveMdFile(char* fileName)
{
    int fileNameLength = strlen(fileName);
    char* newFileName = new char[fileNameLength];
    int len = strlen(fileName) - 4;

    for(int index = 0; index < len; index++)
    {
        newFileName[index] = fileName[index];
    }
    strcat(newFileName, ".md");

    ofstream myfile(newFileName);

    if(myfile)
    {
        for(int i = 0; i < numberOfLines; i++)
           myfile << content[i] << endl;
    }
    else
    {
        cout << "Error not create new file \n";
    }

    myfile.close();
}


void FileManager::addContent(char* lineContent)
{
    char** contentNew = new char*[numberOfLines + 1];

    for(int index = 0; index < numberOfLines; index++)
    {
        int length = strlen(content[index]) + 1;
        contentNew[index] = new char[length];
        strcpy(contentNew[index], content[index]);
    }

    int newLineLength = strlen(lineContent) + 1;
    contentNew[numberOfLines] = new char[newLineLength];
    strcpy(contentNew[numberOfLines], lineContent);

    deleteHelp();

    content = contentNew;
    numberOfLines++;
}


void FileManager::removeLine(int line)
{
    int actualLine = line - 1;

    if (actualLine >= 0 && actualLine < numberOfLines)
    {
        char** tempContent = new char*[numberOfLines - 1];

        for(int index = 0; index < actualLine; index++)
        {
            int length = strlen(content[index]) + 1;
            tempContent[index] = new char[length];
            strcpy(tempContent[index], content[index]);
        }

        for (int index = actualLine + 1; index < numberOfLines; index++)
        {
            tempContent[index - 1] = new char[1024];
            strcpy(tempContent[index - 1], content[index]);
        }

        deleteHelp();
        content = tempContent;
        numberOfLines--;
    }
}


void FileManager::copyHelp(const FileManager &m)
{
    numberOfLines = m.numberOfLines;
    content = new char*[numberOfLines];

    for(int index = 0; index < numberOfLines; index++)
    {
        content[index] = new char[1024];
        strcpy(content[index], m.content[index]);
    }
}


void FileManager::deleteHelp()
{
    for (int index = 0; index < numberOfLines; index++)
    {
        delete [] content[index];
    }

    delete [] content;
}


void FileManager::helper(int currentLine, int fromWord, int toWord, int count)
{
    currentLine = currentLine-1;
    char* curLine = content[currentLine];

    int length = strlen(curLine)+1;
    char* newLine  = new char[length + 2*count+3];
    int numWords = 1;
    bool prefixAdded = false;
    bool sufixAdded = false;
    int tempIndex = 0;
    int count1 = 0;
    int count2 = 0;
    for (int index = 0; index < length; index++, tempIndex++)
    {
        if(curLine[index] == '#' && index == 0)
        {
            newLine[index] = '#';
            newLine[index+1] = ' ';
            index++;
            tempIndex++;
        }
        else
        {
            if(numWords == fromWord && count1 == 0 && index < length-1 && !prefixAdded)
            {
                    count1++;
                    prefixAdded = true;
                    for(int i = 0; i < count; i++)
                    {
                        newLine[tempIndex+i] = '*';
                    }
                    tempIndex += count;
            }

            if(curLine[index] == ' ')
            {
                numWords++;
            }

            if(numWords-1 == toWord && count2 == 0 && index < length-1 && !sufixAdded)
            {
                    count2++;
                    sufixAdded = true;
                    for(int i = 0; i < count; i++)
                    {
                        newLine[tempIndex+i] = '*';
                    }
                    tempIndex += count;
            }

            newLine[tempIndex] = curLine[index];
        }

    }

    if(!sufixAdded && prefixAdded)
    {
        if(count == 1)
        {
            strcat(newLine,"*");
        }
        if(count == 2)
        {
            strcat(newLine, "**");
        }
        if(count == 3)
        {
            strcat(newLine, "***");
        }
        tempIndex += count;
    }

    newLine[tempIndex+1] = '\0';
    delete [] curLine;
    content[currentLine] = newLine;
}


void FileManager::combine(int currentLine, int fromWord, int toWord)
{
    helper(currentLine, fromWord, toWord, 3);
}

void FileManager::bold(int currentLine, int fromWord, int toWord)
{
    helper(currentLine, fromWord, toWord, 2);
}


void FileManager::italic(int currentLine, int fromWord, int toWord)
{
    helper(currentLine, fromWord, toWord, 1);
}






