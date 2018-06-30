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
        int numRows = m.countRowsInFile(fileName);
        rowCount = numRows;
        matrix = new Type**[numRows];
        columnsSize = new int[numRows];

        for ( int index = 0 ; index < numRows; ++index)
        {
            char buff[1024];
            input.getline(buff, 1024);
            int numOfColumns = m.countColumns(buff);
            columnsSize[index] = numOfColumns;
            matrix[index] = new Type*[numOfColumns];


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
                else if (m.isDate(m.Trim(rowAttributes[colIndex])))
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
                    cout << "Error: row " << index+1 << ", col " << colIndex+1 << ", "
                         << rowAttributes[colIndex] << " is unknown data type\n";
                   delete [] rowAttributes;
                   input.close();
                   return false;
                }
            }
                delete [] rowAttributes;
            }

        }

    input.close();

    return true;
}

void Table::printTable() const
{
    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex)
    {
        int numCols = columnsSize[rowIndex];

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
            int numCols = columnsSize[index];
            //char content[1024] = "";
            for (int colIndex = 0; colIndex < numCols; ++colIndex)
            {
                output <<  matrix[index][colIndex]->getData();
                //strcpy(content,matrix[index][colIndex]);
                if(colIndex < numCols-1)
                {
                    output << ", ";
                    //strcpy(content,",");

                }
            }
            //strcpy(content,"\n");
            output << "\n";
            //output << content;
        }
    }
    output.close();
}


void Table::editCell(int row, int column, char* content)
{
    Manager m;

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
    else if(m.isDate(m.Trim(content)))
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
