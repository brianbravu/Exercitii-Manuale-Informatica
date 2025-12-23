// Ture.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n, m, k;
unsigned long LNou[50], LVechi[50];

int main()
{
    cout << "n, m, k= "; cin >> n >> m >> k;
    int i, j, aux;
    unsigned long f = 1, cmk;
    // Calculam factorialul
    for (i = 1; i <= k; i++) f *= i;
    // Calculam combinarile
    LNou[0] = LVechi[0] = 1;
    if (n < m)
    {
        aux = n; n = m; m = aux;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
            LNou[j] = LVechi[j] + LVechi[j - 1];
        for (j = 1; j <= i; j++)
            LVechi[j] = LNou[j];
        if (i == m)
            cmk = LNou[k];
    }
    cout << f * cmk * LNou[k] << endl;
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
