// Calcul cel mai mare divizor comun a doua numere naturale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

unsigned Cmmdc(unsigned x, unsigned y)
{
    if (!y) return x;
    return Cmmdc(y, x % y);
}

int main()
{
    unsigned a, b;
    cout << "a, b= ", cin >> a >> b;
    cout << "c.m.m.d.c. (" << a << ", " << b << ")= " << Cmmdc(a, b);
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
