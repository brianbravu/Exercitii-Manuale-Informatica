// Numarul de ordine al unei combinari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

unsigned long nr, c[10], n, m, nrord, k;
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
    cout << "Numar de ordine="; cin >> nrord;
    if (nrord > comb(n, m))
    {
        cout << "EROARE!";
        return 0;
    }
    cout << nrord << ' ';
    for (i = 1; i <= m; i++) // Determin cifra i
    {
        j = c[i - 1] + 1; // Incep determinarea de la valoarea imediat urmatoare valorii anterior determinate
        while (nr + comb(n - j, m - i) <= nrord) // Cat timp numarul de combinari anterior determinate + cea curenta nu a depasit numarul de ordine dat
        {
            nr += comb(n - j, m - i); //  Adaug la cele determinate cea curenta si trec la urmatoarea
            j++;
        }
        c[i] = j; // Am detectat valoarea cautata o retin si o afisez
        cout << c[i] << ' ';
    }
    cout << endl;
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
