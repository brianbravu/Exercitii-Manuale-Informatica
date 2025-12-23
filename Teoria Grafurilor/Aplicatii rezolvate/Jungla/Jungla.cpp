// Jungla.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 10000
#define InFile "jungla.in"
#define OutFile "jungla.out"
#define Infinit NMax+10
typedef struct lista
{
    int nr; // Numarul de noduri din lista de adiacenta
    int* l; // Adresa de inceput a listei de adiacenta
} lista;
typedef lista graph[NMax];
int n, caz, bffound;
long int m;
graph G;
int d[NMax], p[NMax], o[NMax], r[NMax];
int C[NMax], B, E; // C este coada; B este inceputul, iar E este sfarsitul cozii
int Cycle[NMax], P; // Cycle este ciclul curent; P este lungimea sa
int MinCycle[NMax], Pmin = Infinit; // MinCycle este cel mai scurt ciclu; Pmin este lungimea sa
int changes = 0, bf = 0;

void read(void);
void init(int);
int BFS(int);
void write_solution(void);
void determine_cicle1(int, int);
void determine_cicle2(int, int);
void determine_cicle3(int, int);


int main()
{
    int a, found, i;
    read();
    for (a = 1; a <= n; a++)
    {
        found = BFS(a);
        bf++;
        if(found)
            if (P < Pmin)
            {
                Pmin = P;
                changes++;
                bffound = bf - 1;
                caz = found;
                for (i = 0; i < P; i++)
                    MinCycle[i] = Cycle[i];
            }
    }
    if (Pmin == Infinit)
        printf_s("Eroare! Nu exista solutie.\n");
    write_solution();
}

void read(void)
{
    FILE* in;
    errno_t err = fopen_s(&in, InFile, "r");
    long int i;
    int x, y;
    fscanf_s(in, "%d %ld", &n, &m);
    for (i = 1; i <= n; i++)
    {
        G[i].l = NULL;
        G[i].nr = 0;
    }
    for (i = 1; i <= m; i++)
    {
        fscanf_s(in, "%d %d", &x, &y);
        G[x].nr++;
        G[x].l = (int*)realloc(G[x].l, G[x].nr * sizeof(int));
        G[x].l[G[x].nr - 1] = y;
        G[y].nr++;
        G[y].l = (int*)realloc(G[y].l, G[y].nr * sizeof(int));
        G[y].l[G[y].nr - 1] = x;
    }
    fclose(in);
}

void init(int a)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        d[i] = Infinit;
        p[i] = o[i] = r[i] = 0;
    }
    d[a] = 0;
    C[0] = a;
    B = E = 0;
}

int BFS(int a)
{
    int i, v, u;
    init(a);
    while (B <= E)
    {
        v = C[B++];
        if (d[v] > Pmin + 2) return 0;
        for (i = 0; i < G[v].nr; i++)
        {
            u = G[v].l[i];
            if (d[u] == d[v] - 1) continue;
            if (d[u] == Infinit)
            {
                d[u] = 1 + d[v];
                p[u] = v;
                C[++E] = u;
                continue;
            }
            if (d[u] == d[v] + 1)
            {
                determine_cicle1(v, u);
                return 1;
            }
            if (d[u] == d[v] && o[v] == u) continue;
            if (d[u] == d[v] && o[v] + o[u])
            {
                determine_cicle2(v, u);
                return 2;
            }
            if (d[u] == d[v] && !o[u] && !o[v])
                if (r[v] == r[u])
                {
                    o[u] = v;
                    o[v] = u;
                }
                else
                {
                    determine_cicle3(v, u);
                    return 3;
                }
        }
        for (i = 0; i < G[v].nr; i++)
        {
            u = G[v].l[i];
            if (p[u] == v)
                if (!r[v] && o[v])
                    r[u] = v;
                else r[u] = r[v];
        }
    }
}

void determine_cicle1(int v, int u)
{
    int c1 = v, c2 = p[u], lg = 1, i;
    int P1[NMax / 2], P2[NMax / 2];
    P1[0] = v;
    P2[0] = u;
    P2[1] = p[u];
    while (c1 != c2)
    {
        c1 = p[c1];
        P1[lg] = c1;
        c2 = p[c2];
        P2[++lg] = c2;
    }
    for (i = 0; i < lg; i++)
    {
        Cycle[i] = P1[lg - i - 1];
        Cycle[i + lg] = P2[i];
    }
    P = 2 * lg;
}

void determine_cicle2(int v, int u)
{
    int x, aux;
    int c1, c2, lg = 1, i, j;
    int P1[NMax / 2], P2[NMax / 2];
    if (o[u])
    {
        aux = u;
        u = v;
        v = aux;
    }
    x = o[v];
    c1 = x;
    c2 = u;
    P1[0] = x;
    P2[0] = u;
    while (c1 != c2)
    {
        c1 = p[c1];
        P1[lg] = c1;
        c2 = p[c2];
        P2[lg++] = c2;
    }
    Cycle[0] = v;
    for (i = 1; i <= lg; i++) Cycle[i] = P1[i - 1];
    for (j = lg - 2; j >= 0; j--, i++) Cycle[i] = P2[j];
    P = i;
}

void determine_cicle3(int v, int u)
{
    int c1, c2, lg1 = 1, lg2, i, lvx, aux, x, y, j, pozx, pozy;
    int xx, yy, dlca, lg;
    int P1[NMax / 2], P2[NMax / 2];
    if (r[u])
    {
        aux = u;
        u = v;
        v = aux;
    }
    x = r[v];
    y = o[x];
    P1[0] = y;
    P2[0] = u;
    c1 = y;
    c2 = u;
    lg1 = lg2 = 1;
    while (p[c1])
    {
        c1 = p[c1];
        P1[lg1++] = c1;
    }
    while (p[c2])
    {
        c2 = p[c2];
        P2[lg2++] = c2;
    }
    dlca = -1;
    for (xx = 0; xx < lg1; xx++)
        for (yy = 0; yy < lg2; yy++)
            if (P1[xx] == P2[yy] && dlca < d[P1[xx]])
            {
                dlca = d[P1[xx]];
                pozx = xx;
                pozy = yy;
            }
    for (i = 0; i <= pozx; i++) Cycle[i] = P1[pozx - i];
    lg = pozx + 1;
    P1[0] = v;
    lvx = 0;
    while (P1[lvx] != x)
    {
        P1[lvx + 1] = p[P1[lvx]];
        lvx++;
    }
    for (j = lvx; j >= 0; j++)
        Cycle[lg++] = P1[j];
    Cycle[lg++] = u;
    for (j = 1; j < pozy; j++)
        Cycle[lg++] = P2[j];
    P = lg;
}

void write_solution()
{
    FILE* out;
    errno_t err = fopen_s(&out, OutFile, "w");
    int i;
    fprintf_s(out, "%d\n", Pmin);
    for (i = 0; i < Pmin - 1; i++)
        fprintf_s(out, "%d ", MinCycle[i]);
    fprintf_s(out, "%d\n", MinCycle[Pmin - 1]);
    fclose(out);
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
