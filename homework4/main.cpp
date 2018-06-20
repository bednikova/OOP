#include <iostream>
#include "Polinom.h"
using namespace std;



int main(int argc, const char * argv[])
{

    int* arr = new int[4];
    arr[0] = 12;
    arr[1] = 84;
    arr[2] = 112;
    arr[3] = 8;
    Polinom<int> polinom(arr, 3);

    int* arr1 = new int[4];
    arr1[0] = 12;
    arr1[1] = 83;
    arr1[2] = 105;
    arr1[3] = -1;
    Polinom<int> polinom1(arr1, 3);

    double* arr2 = new double[3];
    arr2[0] = 3;
    arr2[1] = 2;
    arr2[2] = 1;
    Polinom<double> polinom2(arr2, 2);

    Polinom<double> polinom3 = polinom2;
    Polinom<double> polinom4 = polinom2;

    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "Difference / of polynomials \n";
    cout << endl << polinom << " / " << polinom1 << " = " <<  polinom / polinom1 << endl;
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "Difference % of polynomials\n";
    cout << endl << polinom << " %  " << polinom1 << " = " <<  polinom % polinom1 << endl;
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "Product and collection of polynomials \n";
    cout << endl << "(" << (polinom / polinom1) << ") * (" << polinom1 << ") + (" << (polinom % polinom1)
        << ") = ("
         << (polinom / polinom1) * polinom1 + (polinom % polinom1) << ")" << endl;
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "Integral of polinom " << polinom2 << "  :   ";
    cout << ++polinom2 << endl;
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "operator( 0, 2 ) of polinom " << polinom3 << " = " << polinom3(0,2) << " \n";
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "operator( 1 ) of polinom \nP(x) = " << polinom3 << " = " << polinom3(1) << " \n";
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "Proizvodna of polinom " << polinom4 << "  : ";
    cout << --polinom4 << endl;



/*
    Polinom<int> p;
    cin >> p;
    Polinom<int>::Iterator i = p.begin();
    for(; i != p.end(); i++)
    {
        std::cout << *i << " ";
    }
    cout << endl;

    --------i;
    ++++i;

    std::cout << *i << " ";

*/
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    double* arr3 = new double[1];
    arr3[0] = 5;
    Polinom<double> m(arr3, 0);
    int* arr4 = new int[1];
    arr4[0] = 0;
    Polinom<int> m2(arr4, 0);
    cout << m << ((!m) ?  "\nzero polynomial \n" : "\n \n");
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << m2 << ((!m2) ?  "\nzero polynomial \n" : "\nnon-zero polynomial \n");
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << polinom << ((!polinom) ?  "\ne nulev polinom \n" : "\nnon-zero polynomial \n");
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << polinom << " > " << polinom1 << " "
         << ((polinom > polinom1) ? "\nYes \n" : "\nNo \n");
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << polinom1 << " <= " << polinom << " "
         << ((polinom1 <= polinom) ? "\nYes \n" : "\nNo \n");
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "(" << polinom << ") *  2 " << " = " << polinom * 2 << endl;
    cout << "--------------------------------------------------------------------------------------------------\n\n";
    cout << "(" << polinom1*4 << ") /  2 " << " = " << polinom1*4 / 2 << endl;
    cout << "--------------------------------------------------------------------------------------------------\n\n";





    return 0;
}
