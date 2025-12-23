// Generarea elementelor produsului cartezian.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 100

int main()
{
    int n, L[NMax], E[NMax], i, gata = 0;
    ofstream fout("pc.out");
    // Citire si initializare
    cout << "n="; cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> L[i];
        E[i] = 1;
    }
    while (!gata)
    {
        // Afisam configuratia curenta
        for (i = 0; i < n; i++)
            fout << E[i] << ' ';
        fout << '\n';
        // Generam configuratia urmatoare
        for (i = n - 1; i > -1 && E[i] == L[i]; i--) E[i] = 1;
        if (i < 0) // Aceasta a fost ultima configuratie
            gata = 1;
        else E[i]++;
    }
    fout.close();
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
