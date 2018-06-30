#include <iostream>
#include <string.h>
#include <fstream>
#include "Manager.h"

using namespace std;

#ifndef __TYPE_H__
#define __TYPE_H__

class Type
{
    public:
        Type() : data(NULL) {}
        Type(char* _data)
        {
            data = new char[strlen(_data)+1];
            strcpy(data, _data);
        }
        Type(const Type& s)
        {
            copy(s);
        }
        Type& operator=(const Type& t)
        {
            if(this != &t)
            {
                deleteHelp();
                copy(t);
            }

            return *this;
        }

        virtual ~Type()
        {
            deleteHelp();
        }

        virtual void print() const = 0;

        const char* getData() const
        {
            return data;
        }

    protected:

        char* data;

        void deleteHelp()
        {
            delete [] data;
        }

        void copy(const Type& t)
        {
            data = new char[strlen(t.data)+1];
            strcpy(data, t.data);

        }

};
#endif
