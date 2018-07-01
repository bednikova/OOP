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

        Table(): matrix(NULL),rowCount(0), maxColumns(0)
        {

        }
        ~Table();
        Table(char* fileName);
        Table(const Table& t);
        Table& operator=(const Table& t);

        bool loadDataFromFile(char* fileName);
        void saveDataFromFile(char* fileName);
        void editCell(int row, int column, char* content);
        void printTable() const;
        void sort(int column, Table table);

    private:

        Type*** matrix;
        //int* columnsSize;
        int rowCount;
        int maxColumns;

        void deleteHelp();
        void copy(const Table& t);

};

#endif
