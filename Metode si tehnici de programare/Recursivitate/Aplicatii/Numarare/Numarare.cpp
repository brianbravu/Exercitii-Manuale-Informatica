// Numarare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int a[20], n, x;

int Numar(int i)
{
    if (i == n) return 0;
    if (x == a[i]) return 1 + Numar(i + 1);
    return Numar(i + 1);
}

int main()
{
    cout << "n= ", cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "x= ", cin >> x;
    cout << x << " apare in sir de " << Numar(0) << " ori.\n";
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
