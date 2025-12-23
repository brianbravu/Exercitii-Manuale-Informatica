// Minimul a doua valori.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

// Declaratie
template <class T>
T minim(T x, T y);

int main()
{
    string s1("Ana are mere"), s2("Anatol");
    int i1 = 8, i2 = 5;
    double x1 = 3.14, x2 = 1.5;
    // Apel
    cout << "Min string: " << minim(s1, s2) << '\n';
    cout << "Min int:    " << minim(i1, i2) << '\n';
    cout << "Min double: " << minim(x1, x2) << '\n';
    return 0;
}

template<class T>
T minim(T x, T y)
{
    if (x < y) return x;
    return y;
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
