// Interclasarea optimala a n siruri ordonate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define MAXINT 32000
#define LMax 50
#define NMax 20

int n, m;
int L[NMax]; // Lungimile secventelor
int o[NMax * LMax]; // Rezultatul interclasarii
int s[NMax][LMax]; // Secventele
int A[2 * NMax]; // Arborele de selectie
int j[NMax]; // Indicii curenti in secvente

void Citire()
{
    ifstream fin("int.in");
    int i, j;
    fin >> n;
    for (i = 1; i <= n; i++)
    {
        fin >> L[i]; m += L[i];
        s[i][L[i] + 1] = MAXINT;
    }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= L[i]; j++)
            fin >> s[i][j];
}

void ConstrArbSel()
{
    int i;
    for (i = n; i < 2 * n; i++) A[i] = s[i - n + 1][1];
    for (i = n - 1; i > 0; i--) // Initializarea nodurilor terminale
        if (A[2 * i] < A[2 * i + 1]) A[i] = A[2 * i];
        else A[i] = A[2 * i + 1];
    for (i = 1; i <= n; i++) j[i] = 1; // Initializez valorile indicilor in secvente
}

void Restructurare()
{
    int i = 1, tata, frate; // Determin secventa corespunzatoare nodului eliminat
    while (i <= n - 1)
        if (A[i] == A[2 * i]) i = 2 * i;
        else i = 2 * i + 1;
    j[i - n + 1]++; A[i] = s[i - n + 1][j[i - n + 1]];
    while (i > 1)
    {
        tata = i / 2;
        if (i == 2 * tata) frate = 2 * tata + 1;
        else frate = 2 * tata;
        if (A[i] > A[frate]) A[tata] = A[frate];
        else A[tata] = A[i];
        i = tata;
    }
}

int main()
{
    int k;
    Citire();
    ConstrArbSel();
    for (k = 1; k <= m; k++)
    {
        o[k] = A[1];
        Restructurare();
    }
    for (k = 1; k <= m; k++)
        cout << o[k] << " ";
    cout << "\n";
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
