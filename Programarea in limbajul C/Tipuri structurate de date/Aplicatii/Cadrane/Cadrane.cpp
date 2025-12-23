// Cadrane.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMax 100
int main()
{
    int a[NMax][NMax], n, i, j;
    cout << "n="; cin >> n;
    // Completam linia n/2 cu 0
    for (i = 0; i < n; i++) a[n / 2][i] = 0;
    // Completam coloana n/2 cu 0
    for (i = 0; i < n; i++) a[i][n / 2] = 0;
    // Completam cadranul 1
    for (i = 0; i < n / 2; i++)
        for (j = n / 2 + 1; j < n; j++) a[i][j] = 1;
    // Completam cadranul 2
    for (i = 0; i < n / 2; i++)
        for (j = 0; j < n / 2; j++) a[i][j] = 2;
    // Completam cadranul 3
    for (i = n / 2 + 1; i < n; i++)
        for (j = 0; j < n / 2; j++) a[i][j] = 3;
    // Completam cadranul 4
    for (i = n / 2 + 1; i < n; i++)
        for (j = n / 2 + 1; j < n; j++) a[i][j] = 4;
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
