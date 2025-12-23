// Lanterna.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define MAXN 51
#define MAXK 1001
#define DMax 50000
#define infinit 30000

typedef struct
{
    char i; // Varful
    int k; // Consumul cu care s-a ajuns in vectorul i
} ElemCoada;
ElemCoada* C;

int T[MAXN][MAXN], W[MAXN][MAXN];
int* Tmin[MAXN];
int prieten[MAXN];
char InC[MAXN][MAXN];
int N, K, minTimp, minK;

void citire()
{
    ifstream fin("lanterna.in");
    int i, j, p, M;
    fin >> N >> K;
    for (i = 1; i <= N; i++) fin >> prieten[i];
    fin >> M;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
        {
            T[i][j] = infinit;
            W[i][j] = MAXK + 1;
        }
    for (p = 1; p <= M; p++)
    {
        fin >> i >> j;
        fin >> T[i][j] >> W[i][j];
        T[j][i] = T[i][j];
        W[j][i] = W[i][j];
    }
    // Alocam memorie dinamic pentru coada C si matricea Tmin
    for (i = 0; i <= N; i++)
        Tmin[i] = new int[K + 1];
    C = new ElemCoada[DMax];
}

void afisare()
{
    ofstream fout("lanterna.out");
    fout << minTimp << " " << minK << "\n";
    fout.close();
}

int MinT(int kmax)
// Returneaza timpul minim in care se ajunge de la vf 1 la vf N cu o lanterna de tipul kmax
{
    int i, j, k, p, q, tN, vf, u;
    for (i = 1; i <= N; i++)
        for (j = 0; j <= kmax; j++)
            Tmin[i][j] = infinit;
    Tmin[1][0] = 0; InC[1][0] = 1;
    C[0].i = 1; C[0].k = 0;
    vf = u = 0; tN = infinit;
    while (vf <= u)
    {
        i = C[vf].i; k = C[vf++].k;
        if (Tmin[i][k] < tN)
            for (j = 1; j <= N; j++)
                if (T[i][j] < infinit && k + W[i][j] <= kmax)
                {
                    p = Tmin[i][k] + T[i][j];
                    q = k + W[i][j];
                    if (prieten[j]) q = 0;
                    if (p < Tmin[j][q])
                    {
                        Tmin[j][q] = p;
                        if (j == N && Tmin[j][q] < tN)
                            tN = Tmin[j][q];
                        if (!InC[j][q] && Tmin[j][q] < tN)
                        {
                            InC[j][q] = 1;
                            C[++u].i = j; C[u].k = q;
                        }
                    }
                }
        InC[i][k] = 0;
    }
    return tN;
}

int main()
{
    int li = 1, ls = K - 1, p;
    citire();
    minTimp = MinT(K);
    minK = K;
    while (li <= ls)
    {
        p = (li + ls) >> 1;
        if (MinT(p) == minTimp)
        {
            minK = p;
            ls = p - 1;
        }
        else li = p + 1;
    }
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
