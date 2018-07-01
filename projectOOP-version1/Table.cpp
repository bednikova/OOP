#include "Table.h"
#include "Manager.h"

using namespace std;

void Table::deleteHelp()
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        for ( int colIndex = 0; colIndex < maxColumns; ++colIndex)
        {
            delete matrix[rowIndex][colIndex];
        }

        delete matrix[rowIndex];
    }

    delete matrix;
}

void Table::copy(const Table& t)
{
    deleteHelp();
    maxColumns = t.maxColumns;
    rowCount = t.rowCount;
    Manager m;
    matrix = new Type**[rowCount];

    for (int index = 0 ; index < rowCount; ++index)
    {
        //delete matrix[index];
        matrix[index] = new Type*[maxColumns];

        for (int colIndex = 0; colIndex < maxColumns; ++colIndex)
        {
            if (m.isInt(t.matrix[index][colIndex]->getData())) // moje bi bez trim
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeInt(t.matrix[index][colIndex]->getData());
            }
            else if (m.isDouble(t.matrix[index][colIndex]->getData()))
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeDouble(t.matrix[index][colIndex]->getData());
            }
            else if (m.isDate(t.matrix[index][colIndex]->getData()))
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeDate(t.matrix[index][colIndex]->getData());
            }
            else if(m.isString(t.matrix[index][colIndex]->getData()))
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeString(t.matrix[index][colIndex]->getData());
            }
            else
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeString();
            }

        }
    }
}

Table::~Table()
{
    deleteHelp();
}


Table::Table(char* fileName)
{
    try
    {
        if(!loadDataFromFile(fileName))
        {
            throw "Not valid data!\n";
        }
    }
    catch(...)
    {
        cout << "Not valid data!\n";
    }

}

Table::Table(const Table& t)
{
    maxColumns = t.maxColumns;
    rowCount = t.rowCount;
    Manager m;
    matrix = new Type**[rowCount];

    for (int index = 0 ; index < rowCount; ++index)
    {
        //delete matrix[index];
        matrix[index] = new Type*[maxColumns];

        for (int colIndex = 0; colIndex < maxColumns; ++colIndex)
        {
            if (m.isInt(t.matrix[index][colIndex]->getData())) // moje bi bez trim
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeInt(t.matrix[index][colIndex]->getData());
            }
            else if (m.isDouble(t.matrix[index][colIndex]->getData()))
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeDouble(t.matrix[index][colIndex]->getData());
            }
            else if (m.isDate(t.matrix[index][colIndex]->getData()))
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeDate(t.matrix[index][colIndex]->getData());
            }
            else if(m.isString(t.matrix[index][colIndex]->getData()))
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeString(t.matrix[index][colIndex]->getData());
            }
            else
            {
                //delete matrix[index][colIndex];
                matrix[index][colIndex] = new TypeString();
            }

        }
    }
}


Table& Table::operator=(const Table& t)
{
    if(this != &t)
    {
        deleteHelp();
        copy(t);
    }

    return *this;
}


bool Table::loadDataFromFile(char* fileName)
{
    std::ifstream input(fileName);

    if (input)
    {
        Manager m;
        maxColumns = m.maxOfCountColumns(fileName)+1;
        int numRows = m.countRowsInFile(fileName);
        rowCount = numRows;
        matrix = new Type**[numRows];


        //count columns

        for ( int index = 0 ; index < numRows; ++index)
        {
            char buff[1024];
            input.getline(buff, 1024);
            int numOfColumns = m.countColumns(buff);

            matrix[index] = new Type*[maxColumns];//new Type*[numOfColumns];


            char** rowAttributes = m.rowsMember(buff);

            for (int colIndex = 0; colIndex < numOfColumns; ++colIndex)
            {
                if (m.isInt(m.Trim(rowAttributes[colIndex])))
                {
                    //cout << "int\n";
                    //cout << rowAttributes[colIndex] << endl;
                    //cout << m.Trim(rowAttributes[colIndex]) << endl;
                    matrix[index][colIndex] = new TypeInt(m.Trim(rowAttributes[colIndex]));
                }
                else if (m.isDouble(m.Trim(rowAttributes[colIndex])))
                {
                    //cout << "double\n";
                    //cout << rowAttributes[colIndex] << endl;
                    //cout << m.Trim(rowAttributes[colIndex]) << endl;
                    matrix[index][colIndex] = new TypeDouble(m.Trim(rowAttributes[colIndex]));
                }
                else if ((m.isDate(m.Trim(rowAttributes[colIndex]))) && (m.validDate(m.Trim(rowAttributes[colIndex]))))
                {
                    //cout << "date\n";
                    //cout << m.Trim(rowAttributes[colIndex]) << endl;
                    matrix[index][colIndex] = new TypeDate(m.Trim(rowAttributes[colIndex]));
                }
                else if(m.isString(m.Trim(rowAttributes[colIndex])))
                {
                    //cout << "string\n";
                    //cout << m.Trim(rowAttributes[colIndex]) << endl;
                    matrix[index][colIndex] = new TypeString(m.Trim(rowAttributes[colIndex]));
                }
                else if(strlen(rowAttributes[colIndex]) == 0 || strlen(rowAttributes[colIndex]) == 1)
                {
                    //cout << "string - empty string\n";
                    matrix[index][colIndex] = new TypeString();
                }
                else
                {
                    if(m.isDate(m.Trim(rowAttributes[colIndex])))
                    {
                        cout << "Error: row " << index+1 << ", col " << colIndex+1 << ", "
                             << rowAttributes[colIndex] << " is not valid date! \n";

                    }
                    else
                    {
                        cout << "Error: row " << index+1 << ", col " << colIndex+1 << ", "
                             << rowAttributes[colIndex] << " is unknown data type\n";
                    }
                   delete [] rowAttributes;
                   input.close();
                   return false;
                }
            }
                delete [] rowAttributes;


            for (int colIndex = numOfColumns; colIndex < maxColumns; ++colIndex)
            {
                matrix[index][colIndex] = new TypeString();
            }

        }

    }

    input.close();

    return true;
}

void Table::printTable() const
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        //int numCols = columnsSize[rowIndex];
        int numCols = maxColumns;

        for (int colIndex = 0; colIndex < numCols; ++colIndex)
        {
            matrix[rowIndex][colIndex]->print();

            if (colIndex + 1 < numCols)
            {
                cout << " | ";
            }
        }
        cout << endl;
    }
}


void Table::saveDataFromFile(char* fileName)
{
    std::ofstream output(fileName);

    if (output)
    {
        for ( int index = 0; index < rowCount; ++index)
        {
            //int numCols = columnsSize[index];
            int numCols = maxColumns-1; // -1

            for (int colIndex = 0; colIndex < numCols; ++colIndex)
            {
                output <<  matrix[index][colIndex]->getData();

                if(colIndex == numCols-1)  //numCols-1
                {
                    //output << ", ";


                }
                else if(colIndex < numCols)  //numCols-1
                {
                    output << ", ";


                }
            }

            output << "\n";

        }
    }
    output.close();
}


void Table::editCell(int row, int column, char* content)
{
    Manager m;

    //proveri dali sa korektni redyt i kolonata!!!
    if(row > rowCount)
    {
        cout << "Not valid row!!!\n";
        return;
    }
    else if(column > maxColumns) // >=
    {
        cout << "Not valid column!!!\n";
        return;
    }

    if(m.isInt(m.Trim(content)))
    {
        delete matrix[row-1][column-1];
        matrix[row-1][column-1] = new TypeInt(m.Trim(content));
    }
    else if(m.isDouble(m.Trim(content)))
    {
        delete matrix[row-1][column-1];
        matrix[row-1][column-1] = new TypeDouble(m.Trim(content));
    }
    else if(m.isDate(m.Trim(content)) && (m.validDate(m.Trim(content))))
    {
        delete matrix[row-1][column-1];
        matrix[row-1][column-1] = new TypeDate(m.Trim(content));
    }
    else if(m.isString(m.Trim(content)))
    {
        delete matrix[row-1][column-1];
        matrix[row-1][column-1] = new TypeString(m.Trim(content));
    }
    else if(strlen(content) == 0 || strlen(content) == 1)
    {
        delete matrix[row-1][column-1];
        matrix[row-1][column-1] = new TypeString();

    }
    else
    {
        cout << "Error: " << content << " is unknown data type\n";
    }
}


void Table::sort(int column, Table table)
{

    if(column > maxColumns)
    {
        cout << "Not valid column! \n";
        return;
    }

    //Table table;
    //table = *this;
    //table.printTable();

    for(int index = 0; index < maxColumns; ++index)//for (c = 0 ; c < ( n - 1 ); c++)
    {
        for(int indexRow = 0; indexRow < maxColumns - index - 1; ++indexRow)//for (d = 0 ; d < n - c - 1; d++)
        {
          if(matrix[indexRow][column-1]->getIntValue() > (matrix[indexRow+1][column-1]->getIntValue()))
            //if (array[d] > array[d+1])
          {
            //swap       = array[d];
            for(int ind = 0; ind < maxColumns; ++ind)
                table.editCell(indexRow+1, ind+1, matrix[indexRow][ind]->getData());
            //array[d]   = array[d+1];
            for(int ind = 0; ind < maxColumns; ++ind)
                this->editCell(indexRow+1, ind+1, matrix[indexRow+1][ind]->getData());
            //array[d+1] = swap;
            for(int ind = 0; ind < maxColumns; ++ind)
                this->editCell(indexRow+2, ind+1, table.matrix[indexRow][ind]->getData());
          }
        }
    }
}

