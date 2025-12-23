// Ghizi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAXV 103
#define MAXN 5001
#define min(x,y) ((x)<(y)?(x):(y))
#define abs(x) ((x)>0?x:-x)

int n, k, s, d, viz[MAXV], Q[MAXV];
int* C[MAXV]; // Capacitatea fiecarui arc
int* F[MAXV]; // Fluxul fiecarui arc
struct arc { int x, y, uz; } G[MAXN];

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
    errno_t err = fopen_s(&fin, "ghizi.in", "r");
    int i, t1, t2;
    for (i = 0; i < MAXV; i++)
    {
        C[i] = (int*)calloc(MAXV, sizeof(int));
        F[i] = (int*)calloc(MAXV, sizeof(int));
    }
    fscanf_s(fin, "%d %d", &n, &k);
    for (i = 1; i <= n; i++)
    {
        fscanf_s(fin, "%d %d", &t1, &t2);
        C[t1 + 1][t2 + 1]++;
        G[i].x = t1 + 1; G[i].y = t2 + 1;
    }
    C[MAXV - 1][1] = k;
    s = MAXV - 1; d = MAXV - 2;
    fclose(fin);
}

void afisare()
{
    int i, j, p, nr = 0;
    FILE* fout;
    errno_t err = fopen_s(&fout, "ghizi.out", "w");
    for (i = 1; i < MAXV - 1; i++)
        for (j = 1; j < MAXV - 1; j++)
            if (F[i][j])
                for (p = 1; p <= n; p++)
                    if (G[p].x == i && G[p].y == j && G[p].uz == 0)
                    {
                        G[p].uz = 1;
                        nr++;
                        break;
                    }
    fprintf_s(fout, "%d\n", nr);
    for (i = 1; i <= n; i++)
        if (G[i].uz) fprintf_s(fout, "%d ", i);
    fclose(fout);
}

void ek()
{
    int i, a, b, lg, v;
    int L[MAXV];
    do
    {
        for (i = 1; i < MAXV; i++) viz[i] = 0;
        if (bfs()) return;
        // Determinam lantul in vectorul L
        L[0] = d; lg = 0;
        a = 10000;
        while (L[lg] != s)
        {
            lg++;
            L[lg] = abs(viz[L[lg - 1]]);
            if (viz[L[lg]] > 0)
                a = min(a, C[L[lg]][L[lg - 1]] - F[L[lg]][L[lg - 1]]);
        }
        // Marim fluxul de-a lungul lantului
        for (i = lg; i > 0; i--) F[L[i]][L[i - 1]] += a;
    } while (true);
}

int bfs()
// Returneaza 1 daca iesirea retelei nu a fost marcata
{
    int p, u, i, x;
    Q[0] = s; p = u = 0; viz[s] = 1;
    while (p <= u && !viz[d])
    {
        x = Q[p++];
        for (i = 1; i < MAXV; i++)
            if(!viz[i])
                if (F[x][i] < C[x][i])
                {
                    viz[i] = x;
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
