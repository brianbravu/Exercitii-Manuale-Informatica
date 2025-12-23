// Submultimi cu sume egale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, m, a[101][51], i, j, d, nr = 1;
    cout << "n="; cin >> n;
    m = 2 * n - 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) a[i][j] = a[i + n][j] = nr++;
    // Parcurgem pseudodiagonalele
    for (d = 0; d < n; d++)
    {
        // Afisez elementele de pe pseudodiagonala d
        cout << "Submultimea " << d + 1 << ": { ";
        for (j = 0; j < n; j++) cout << a[j + d][j] << ' ';
        cout << "}\n";
    }
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
