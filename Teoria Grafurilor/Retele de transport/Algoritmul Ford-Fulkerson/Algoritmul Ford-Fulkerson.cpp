// Algoritmul Ford-Fulkerson.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAXV 50
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>0?(x):(-x))

int n, m, s, d, viz[MAXV], Q[MAXV];
int C[MAXV][MAXV]; // Capacitatea fiecarui arc
int F[MAXV][MAXV]; // Fluxul fiecarui arc

void citire(void);
void ek(void);
void afisare(void);
int bfs(void);

int main()
{
    citire();
    ek();
    afisare();
}

void citire()
{
    FILE* fin;
    errno_t err = fopen_s(&fin, "graf.in", "r");
    int i, x, y, c;
    fscanf_s(fin, "%d %d %d %d", &n, &m, &s, &d);
    for (i = 0; i < m; i++)
    {
        fscanf_s(fin, "%d %d %d", &x, &y, &c);
        C[x][y] = c;
    }
}

void afisare()
{
    int i, j, vf = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (F[i][j])
                printf_s("Fluxul arcului (%d, %d) este %d\n", i, j, F[i][j]);
    for (i = 1; i <= n; i++) vf += F[i][d];
    printf_s("Fluxul maxim este %d\n", vf);
}

void ek()
{
    int i, a, b, lg, v;
    int L[MAXV];
    do
    {
        // Marcam varfurile intr-o parcurgere in latime
        for (i = 1; i <= n; i++) viz[i] = 0;
        if (bfs()) return;
        // Determimam lantul de ameliorare in vectorul L
        L[0] = d; lg = 0;
        a = b = 10000;
        while (L[lg] != s)
        {
            ++lg;
            L[lg] = abs(viz[L[lg - 1]]);
            if (viz[L[lg - 1]] > 0)
                a = min(a, C[L[lg]][L[lg - 1]] - F[L[lg]][L[lg - 1]]);
            else
                if (viz[L[lg - 1]] < 0)
                    b = min(b, F[L[lg - 1]][L[lg]]);
        }
        v = min(a, b);
        // Marim fluxul de-a lungul lantului
        for (i = lg; i > 0; i--)
            if (viz[L[i - 1]] > 0)
                F[L[i]][L[i - 1]] += v;
            else
                F[L[i - 1]][L[i]] -= v;
    } while (true);
}

int bfs()
// Returneaza 1 daca iesirea retelei nu a fost marcata
{
    int p, u, i, x;
    Q[0] = s; p = u = 0; viz[s] = 1;
    while (p <= u & !viz[d])
    {
        x = Q[p++];
        for (i = 1; i <= n; i++)
            if(!viz[i])
                if (F[x][i] < C[x][i])
                {
                    viz[i] = x;
                    Q[++u] = i;
                }
                else 
                    if (F[i][x] > 0)
                    {
                        viz[i] = -x;
                        Q[++u] = i;
                    }
    }
    return !viz[d];
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
