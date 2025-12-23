// Problema 3. SQR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include "BigInt.h"
using namespace std;
#define NMAX 1001
#define DMAX 100000

ifstream fin("sqr.in");
ofstream fout("sqr.out");

int n;
int a[NMAX];
int p[NMAX];
BigInt nr(1);

int main()
{
    int i, d;
    // Citire
    fin >> n;
    for (i = 1; i <= n; i++) fin >> a[i];
    // Descompunerea in factori primi
    for (i = 1; i <= n; i++)
        for (d = 2; a[i] > 1; d++)
            while (a[i] % d == 0)
            {
                ++p[d];
                a[i] /= d;
            }
    // Determin nr
    for (d = 2; d < DMAX; d++)
        if (p[d] % 2) nr *= d;
    // Afisare
    fout << nr << '\n';
    fin.close();
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
