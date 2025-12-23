// Problema rucsacului.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int o[50]; // Ordinea obiectelor
float c[100], g[100], x[100], Gr, GMax;
int n;
int main()
{
    int i, schimb, aux;
    cout << "n="; cin >> n; // Citire
    cout << "GMax="; cin >> GMax;
    cout << "Castigul si greutatea pentru fiecare obiect\n";
    for (i = 0; i < n; i++)
    {
        o[i] = i;
        cin >> c[i] >> g[i];
    }
    // Ordonez obiectele descrescator dupa castigul unitar
    do
    {
        schimb = 0;
        for (i = 0; i < n - 1; i++)
            if (c[o[i]] / g[o[i]] < c[o[i + 1]] / g[o[i + 1]])
            {
                aux = o[i];
                o[i] = o[i + 1];
                o[i + 1] = aux;
                schimb = 1;
            }
    } while (schimb);
    for (i = 0, Gr = GMax; i<n && Gr>g[o[i]]; i++)
    {
        x[o[i]] = 1;
        Gr -= g[o[i]];
    }
    if (i < n) x[o[i]] = Gr / g[o[i]];
    cout << "Obiectele selectate sunt:\n";
    for (i = 0; i < n; i++)
        if (x[i]) cout << i + 1 << ' ' << x[i] * 100 << "%\n";
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
