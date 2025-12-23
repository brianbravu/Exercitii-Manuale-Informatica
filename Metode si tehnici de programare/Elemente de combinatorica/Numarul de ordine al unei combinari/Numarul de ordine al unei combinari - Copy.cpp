// Numarul de ordine al unei combinari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

unsigned long c[20], n, m, nrord;
unsigned long comb(unsigned long n, unsigned long m)
{
    if (m > n) return 0;
    if (!m || !n || (n == m)) return 1;
    return comb(n - 1, m) + comb(n - 1, m - 1);
}

int main()
{
    int i, j;
    cout << "n, m ="; cin >> n >> m;
    for (i = 1; i <= m; i++) cin >> c[i];
    for (i = 1; i <= m; i++) // Pentru fiecare element al combinarii numar cate combinari incep cu valori strict mai mici caelementul respectiv
        for (j = c[i - 1] + 1; j < c[i]; j++)
            nrord += comb(n - j, m - i); // Numarul de combinari care au fixate primele i elemente este comb(n-j,m-i)
    cout << nrord << endl;
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
