// Pseudodiagonale.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, m, a[100][100], i, j, d, s;
    cout << "n="; cin >> n;
    cout << "m="; cin >> m;
    cout << "Introduceti elementele matricei, linie cu linie\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) cin >> a[i][j];
    // Parcurgem pseudodiagonalele principale
    for (d = 0; d < m - n + 1; d++)
    {
        s = 0; // Suma elementelor de pe pseudodiagonala d
        for (i = 0; i < n; i++)
            s += a[i][i + d];
        cout << "Suma elementelor de pe pseudodiagonala principala " << d << " este " << s << '\n';
    }
    // Parcurgem pseudodiagonalele secundare
    for (d = 0; d < m - n + 1; d++)
    {
        s = 0; // Suma elementelor de pe pseudodiagonala d
        for (i = 0; i < n; i++)
            s += a[i][m - d - i - 1];
        cout << "Suma elementelor de pe pseudodiagonala secundara " << d << " este " << s << '\n';
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
