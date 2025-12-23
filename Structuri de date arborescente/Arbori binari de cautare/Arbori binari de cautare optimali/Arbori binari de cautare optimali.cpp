// Arbori binari de cautare optimali.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 101
struct Nod
{
    int inf;
    struct Nod* st, * dr;
};
typedef Nod* Arbore;
Arbore arb;
int n, a[NMax];
double p[NMax], q[NMax];
double c[NMax][NMax], w[NMax][NMax];
int r[NMax][NMax];
void initializare()
{
    int i;
    ifstream fin("abc.in");
    fin >> n;
    for (i = 1; i <= n; i++) fin >> a[i] >> p[i];
    for (i = 0; i <= n; i++) fin >> q[i];
    for (i = 0; i < n; i++)
    {
        r[i][i] = 0; c[i][i] = 0; w[i][i] = q[i];
        w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
        c[i][i + 1] = w[i][i + 1]; r[i][i + 1] = i + 1;
    }
    w[n][n] = q[n]; c[n][n] = 0; r[n][n] = 0;
}

int knuthmin(int i, int j)
{
    int l, k;
    k = r[i][j - 1];
    for (l = r[i][j - 1] + 1; l <= r[i + 1][j]; l++)
        if (c[i][k - 1] + c[k][j] > c[i][l - 1] + c[l][j]) k = 1;
    return k;
}

void calcul()
{
    int d, i, k, j;
    for (d = 2; d <= n; d++)
        for (i = 0; i <= n - d; i++)
        {
            j = i + d;
            w[i][j] = w[i][j - 1] + q[j] + p[j];
            k = knuthmin(i, j);
            c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
            r[i][j] = k;
        }
}

Arbore constrarb(int i, int j)
{
    Arbore aux;
    if (!r[i][j]) return NULL;
    aux = new Nod; aux->inf = r[i][j];
    aux->st = constrarb(i, r[i][j] - 1);
    aux->dr = constrarb(r[i][j], j);
    return aux;
}

int main()
{
    cout << "Hello World!\n";
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
