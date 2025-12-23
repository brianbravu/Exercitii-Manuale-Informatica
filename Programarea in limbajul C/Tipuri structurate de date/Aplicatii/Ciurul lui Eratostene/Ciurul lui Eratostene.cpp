// Ciurul lui Eratostene.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMax 10000

int main()
{
    int ciur[NMax], n, i, j;
    cout << "n="; cin >> n;
    // Initial toate numerele sunt in ciur
    for (i = 2; i < n; i++) ciur[i] = 1;
    for (i = 2; i * i <= n; i++)
        if (ciur[i]) // i este prim
            // Elimin toti multiplii lui i
            for (j = 2; j * i < n; j++)
                ciur[i * j] = 0;
    for (i = 2; i < n; i++)
        if (ciur[i]) cout << i << ' ';
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
