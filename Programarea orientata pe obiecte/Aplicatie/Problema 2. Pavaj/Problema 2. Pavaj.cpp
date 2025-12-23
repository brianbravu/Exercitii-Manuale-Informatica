// Problema 2. Pavaj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include "BigInt.h"
using namespace std;
#define NMAX 251
#define LMAX 701

ifstream fin("pavaj.in");
ofstream fout("pavaj.out");

int n, L;
int d[NMAX];
BigInt nr[LMAX];

int main()
{
    int i, x;
    // Citire
    fin >> L >> n;
    for (i = 1; i <= n; i++) fin >> d[i];
    // Programare dinamica
    nr[0] = BigInt(1);
    for (x = 1; x <= L; x++)
        for (i = 1; i <= n; i++)
            if (d[i] <= x) nr[x] += nr[x - d[i]];
    // Afisare
    fout << nr[L] << '\n';
    fin.close();
    fout.close();
    return 0;
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
