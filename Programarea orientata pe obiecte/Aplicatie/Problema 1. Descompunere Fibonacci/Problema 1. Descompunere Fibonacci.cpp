// Problema 1. Descompunere Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include "BigInt.h"
#define NRMAX 10000
using namespace std;

ifstream fin("fib.in");
ofstream fout("fib.out");

BigInt n;
int nr;
BigInt fib[NRMAX];

void Generare_Fibonacci();

int main()
{
    int poz;
    fin >> n;
    Generare_Fibonacci();
    poz = nr - 1;
    while (!e0(n)) // Caut cel mai mare termen din sirul fibonacci <=n
    {
        for (; n < fib[poz]; poz--);
        fout << fib[poz] << '\n';
        n -= fib[poz];
    }
    fin.close();
    fout.close();
    return 0;
}

void Generare_Fibonacci()
{
    int i;
    fib[0] = BigInt();
    fib[1] = BigInt(1);
    for (i = 1; fib[i] <= n; i++)
        fib[i + 1] = fib[i] + fib[i - 1];
    nr = i;
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
