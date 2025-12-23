// Cod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define NMax 201

char x[NMax], y[NMax], lcs[NMax][NMax], n, m;

void citire()
{
    ifstream fin("cod.in");
    fin.getline(x, NMax); n = strlen(x);
    fin.getline(y, NMax); m = strlen(y);
    fin.close();
}

void dinamic()
{
    int k, h;
    for (k = n - 1; k >= 0; k--)
        for (h = m - 1; h >= 0; h--)
            if (x[k] == y[h])
                lcs[k][h] = 1 + lcs[k + 1][h + 1];
            else if (lcs[k + 1][h] > lcs[k][h + 1])
                lcs[k][h] = lcs[k + 1][h];
            else
                lcs[k][h] = lcs[k][h + 1];
}

void afisare()
{
    ofstream fout("cod.out");
    char d[NMax];
    int h = 0, k = 0, ix, iy, max, poz = 0;
    for (int i = lcs[0][0]; i > 0; i--) // Caut pozitia de inceput a unuisubsir de lungime i care incepe cu cea mai mare cifra
    {
        max = -1;
        for (ix = h; ix < n; ix++)
            for (iy = k; iy < m; iy++)
                if (lcs[ix][iy] == i && x[ix] == y[iy] && max < x[ix])
                {
                    max = x[ix]; h = ix; k = iy;
                }
        d[poz++] = max;
    }
    for (k = 0; k < poz; k++) fout << d[k];
    fout << endl; fout.close();
}

int main()
{
    citire();
    dinamic();
    afisare();
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
