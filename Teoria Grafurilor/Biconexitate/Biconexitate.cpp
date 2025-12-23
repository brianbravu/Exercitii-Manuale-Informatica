// Biconexitate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
#define MMax NMax*(NMax-1)/2

int n, num, VfS, nrfii, nr, start = 3;
int A[NMax][NMax];
int dfn[NMax], low[NMax], Art[NMax];

struct Muchie { int f, t; } S[NMax];
void Citire(void);
void Biconex(int, int);
void Initializare(void);
void Afisare_Comp_Biconexa(int, int);

int main()
{
    int i;
    Citire();
    Initializare();
    Biconex(start, -1);
    // Afisez punctele de articulatie
    if (nrfii > 1) // start este punct de articulatie
        Art[start] = 1;
    printf_s("Punctele de articulatie sunt: ");
    for (i = 1; i <= n; i++)
        if (Art[i]) printf_s("%d ", i);
}

void Citire()
{
    FILE* fin;
    errno_t err = fopen_s(&fin, "graf.in", "r");
    int x, y, m, i;
    fscanf_s(fin, "%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        fscanf_s(fin, "%d %d", &x, &y);
        A[x][0]++; A[x][A[x][0]] = y;
        A[y][0]++; A[y][A[y][0]] = x;
    }
}

void Initializare()
{
    int i;
    for (i = 1; i <= n; i++) dfn[i] = low[i] = -1;
    S[0].f = start; S[0].t = -1; VfS = 0;
}

int min(int x, int y)
{
    if (x < y) return x;
    return y;
}

void Biconex(int u, int tu) 
// u este mnodul curent; tu este nodul parinte al lui u
{
    int x, p;
    dfn[u] = low[u] = ++num;
    // Parcurg lista de adiacenta a nodului u
    for (p = 1; p <= A[u][0]; p++)
    {
        x = A[u][p]; // x este un nod adiacent cu u
        if (x != tu && dfn[x] < dfn[u])
            // Insereaza in stiva S muchia [u,x]
        {
            S[++VfS].f = x;
            S[VfS].t = u;
        }
        if (dfn[x] == -1) // x nu a mai fost vizitat
        {
            if (u == start) // Am gasit un fiu al varfului start
                nrfii++;
            Biconex(x, u);
            low[u] = min(low[u], low[x]);
            if (low[x] >= dfn[u]) // u este un punct de articulatie
                // Am identificat o componenta biconexa,
                // formata din muchiile din stiva S
                // pana la intalnirea muchiei [u,x]
            {
                if (u != start) Art[u] = 1;
                Afisare_Comp_Biconexa(x, u);
            }
        }
        else // x a mai fost vizitat
            if (x != tu)
                // x nu este tatal lui u,
                // deci [u,x] e muchie de intoarcere la u la x
                low[u] = min(low[u], dfn[x]);
    }
}

void Afisare_Comp_Biconexa(int x, int u)
// Afiseaza componenta biconexa a muchiei [x,u]
{
    Muchie p;
    nr++; // Incrementez numarul de componente biconexe
    printf_s("Componenta biconexa %d contine muchiile:\n", nr);
    do
    {
        p = S[VfS--]; // Extrag o muchie din stiva
        printf_s("%d %d\n", p.t, p.f);
    } while (p.t != u || p.f != x);
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
