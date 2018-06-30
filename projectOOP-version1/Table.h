#include "TypeInt.h"
#include "Type.h"
#include "TypeDouble.h"
#include "TypeString.h"
#include "TypeDate.h"

#ifndef __TABLE_H__
#define __TABLE_H__

class Table
{
    public:

        Table(): matrix(NULL),columnsSize(NULL), rowCount(0)
        {

        }
        ~Table();

        bool loadDataFromFile(char* fileName);
        void saveDataFromFile(char* fileName);
        void printTable() const;

    private:

        Type*** matrix;
        int* columnsSize;
        int rowCount;

};

#endif
