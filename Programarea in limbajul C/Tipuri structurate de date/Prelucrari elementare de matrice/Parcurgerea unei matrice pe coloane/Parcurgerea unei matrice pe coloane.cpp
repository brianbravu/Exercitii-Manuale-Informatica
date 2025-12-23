// Parcurgerea unei matrice pe coloane.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[100][100], n, m, i, j, s;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) cin >> a[i][j];
    for (j = 0; j < m; j++)
    {
        for (s = 0, i = 0; i < n; i++) s += a[i][j];
        cout << "Suma de pe coloana " << j << " este " << s << '\n';
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
