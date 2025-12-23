// Rucsac.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define NMax 101
#define MaxG 301

int n, GMax;
int c[NMax], g[NMax];
int CMax[MaxG], Uz[MaxG][NMax];

void Citire();
void Rezolvare();
void Afisare();

int main()
{
    Citire();
    Rezolvare();
    Afisare();
}

void Citire()
{
    ifstream fin("rucsac.in");
    int i, j;
    fin >> n >> GMax;
    for (i = 1; i <= n; i++) fin >> g[i];
    for (i = 1; i <= n; i++) fin >> c[i];
    fin.close();
}

void Rezolvare()
{
    int S, k, i;
    for (S = 1; S <= GMax; S++) CMax[S] = -1;
    for (S = 1; S <= GMax; S++)
        for (i = 1; i <= n; i++)
            if (g[i] <= S && CMax[S - g[i]] != -1 && !Uz[S - g[i]][i])
                if (CMax[S] < c[i] + CMax[S - g[i]])
                {
                    CMax[S] = c[i] + CMax[S - g[i]];
                    for (k = 1; k <= n; k++)
                        Uz[S][k] = Uz[S - g[i]][k];
                    Uz[S][i] = 1;
                }
}

void Afisare()
{
    ofstream fout("rucsac.out");
    if (CMax[GMax] == -1) fout << "IMPOSIBIL";
    else
    {
        fout << CMax[GMax] << endl;
        for (int k = 1; k <= n; k++)
            if (Uz[GMax][k]) fout << k << " ";
        fout << endl;
        fout.close();
    }
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
