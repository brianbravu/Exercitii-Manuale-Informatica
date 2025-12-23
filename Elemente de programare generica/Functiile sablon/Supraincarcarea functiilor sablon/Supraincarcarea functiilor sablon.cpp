// Supraincarcarea functiilor sablon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

template <class T>
void inv(T& x);

template <class T>
void inv(T& a, T& b);
int main()
{
    int i1 = 8, i2 = 5;
    double x1 = 3.14, x2 = 1.5;
    inv(i1); inv(i1, i2);
    inv(x2); inv(x1, x2);
    cout << ' ' << i1 << "  " << i2 << '\n';
    cout << x1 << ' ' << x2 << '\n';
    return 0;
}

template<class T>
void inv(T& x)
{
    x = -x;
}

template<class T>
void inv(T& a, T& b)
{
    T aux = a;
    a = b;
    b = aux;
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
