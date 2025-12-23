// Algoritmul Knuth-Morris-Pratt (KMP).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define nMax 1000
#define mMax 255

int Urm[mMax];
char T[nMax], P[nMax];
int n, m;

void Urmatorul(char* P)
{
    int k = -1, x;
    Urm[0] = 0;
    for (x = 1; x < m; x++)
    {
        while (k > 0 && P[k + 1] != P[x]) k = Urm[k];
        if (P[k + 1] == P[x]) k++;
        Urm[x] = k;
    }
}

int main()
{
    int i, x = -1;
    ifstream f("KMP.IN");
    ofstream g("KMP.OUT");
    f.getline(T, 1000); f.getline(P, 255);
    n = strlen(T); m = strlen(P);
    Urmatorul(P);
    for (i = 0; i < n; i++)
    {
        while (x > 0 && P[x + 1] != T[i]) x = Urm[x];
        if (P[x + 1] == T[i]) x++; // S-au potrivit
        if (x == m - 1)
        {
            g << "Am gasit subsirul in pozitia " << i - m + 1 << "\n";
            x = Urm[x];
        }
    }
    g.close();
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
