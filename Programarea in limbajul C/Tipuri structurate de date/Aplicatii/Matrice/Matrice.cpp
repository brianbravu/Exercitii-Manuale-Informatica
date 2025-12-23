// Matrice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMax 100

int main()
{
    int a[NMax][NMax], n, i, j;
    cout << "n="; cin >> n;
    // Completam diagonala principala cu 0
    for (i = 0; i < n; i++) a[i][i] = 0;
    // Completam diagonala secundara cu 0
    for (i = 0; i < n; i++) a[i][n - i - 1] = 0;
    // Completam zona 1
    for (i = 0; i < n / 2; i++)
        for (j = i + 1; j < n - i - 1; j++) a[i][j] = 1;
    // Completam zona 2
    for (j = 0; j < n / 2; j++)
        for (i = j + 1; i < n - j - 1; i++) a[i][j] = 2;
    // Completam zona 3
    for (i = n / 2 + 1; i < n; i++)
        for (j = n - i; j < i; j++) a[i][j] = 3;
    // Completam zona 4
    for (j = n / 2 + 1; j < n; j++)
        for (i = n - j; i < n; i++) a[i][j] = 4;
    // Afisam matricea
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << '\n';
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
