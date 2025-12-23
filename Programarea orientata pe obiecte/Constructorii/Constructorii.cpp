// Constructorii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "fractie.h"
using namespace std;

int main()
{
    fractie f1, f2(5), f3(8, 12);

    cout << f1.GetNumarator() << '/' << f1.GetNumitor() << '\n';
    cout << f2.GetNumarator() << '/' << f2.GetNumitor() << '\n';
    cout << f3.GetNumarator() << '/' << f3.GetNumitor() << '\n';

    f3.Simplifica();

    cout << f3.GetNumarator() << '/' << f3.GetNumitor() << '\n';
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
