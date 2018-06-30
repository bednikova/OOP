#include "Table.h"
#include "Manager.h"

using namespace std;

Table::~Table()
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        for ( int colIndex = 0; colIndex < columnsSize[rowIndex]; ++colIndex)
        {
            delete matrix[rowIndex][colIndex];
        }

        delete matrix[rowIndex];
    }

    delete matrix;
    delete columnsSize;
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
        columnsSize = new int[numRows];

        //count columns

        for ( int index = 0 ; index < numRows; ++index)
        {
            char buff[1024];
            input.getline(buff, 1024);
            int numOfColumns = m.countColumns(buff);
            columnsSize[index] = numOfColumns;
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
                             << rowAttributes[colIndex] << " is not valid data! \n";

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
            int numCols = maxColumns;

            for (int colIndex = 0; colIndex < numCols; ++colIndex)
            {
                output <<  matrix[index][colIndex]->getData();

                if(colIndex < numCols-1)
                {
                    output << ", ";


                }
            }

            output << " \n";

        }
    }
    output.close();
}


void Table::editCell(int row, int column, char* content)
{
    Manager m;

    //proveri dali sa korektni redyt i kolonata!!!
    if(row > rowCount || column > maxColumns)
    {
        cout << "Not valid row or column!!!\n";
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


void Table::sort(int column)
{
    /*
    if(column > maxColumns)
    {
        cout << "Not valid column! \n";
        return;
    }

    char** matrixHelp = new Type*[rowCount];
    for(int indexRow = 0; indexRow < rowCount; ++index)
    {
        matrixHelp[indexRow] = new Type();
        matrix[indexRow][column-1];
    }
    */
}
