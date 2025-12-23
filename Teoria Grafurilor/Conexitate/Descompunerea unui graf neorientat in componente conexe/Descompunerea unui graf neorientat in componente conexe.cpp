// Descompunerea unui graf neorientat in componente conexe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
#define MMax NMax*(NMax-1)/2

typedef struct { int x, y; } Muchie;
int n, m;
Muchie G[MMax];
int C[NMax];

void Citire();
void Descompunere_Comp_Conexe();
void Afisare();

int main()
{
    Citire();
    Descompunere_Comp_Conexe();
    Afisare();
}

void Citire()
{
    FILE* fin;
    errno_t err;
    err = fopen_s(&fin, "graf.in", "r");
    int i;
    fscanf_s(fin, "%d %d", &n, &m);
    for (i = 0; i < m; i++)
        fscanf_s(fin, "%d %d", &G[i].x, &G[i].y);
}

void Descompunere_Comp_Conexe()
{
    int i, j, min, max;
    for (i = 1; i <= n; i++) C[i] = i;
    for(j=0;j<=n;j++)
        if (C[G[j].x] != C[G[j].y])
            // Extremitatile muchiei j nu sunt
            // in aceeasi componenta conexa
        {
            if (C[G[j].x] < C[G[j].y])
                min = C[G[j].x], max = C[G[j].y];
            else
                min = C[G[j].y], max = C[G[j].x];
            // Unific componentele conexe ale extremitatilor
            for (i = 1; i <= n; i++)
                if (C[i] == max) C[i] = min;
        }
}

void Afisare()
{
    int nrc = 0, i, j;
    for (i = 1; i <= n; i++)
        if (C[i])
        {
            nrc++;
            printf_s("Componenta conexa %d: %d", nrc, i);
            for (j = i + 1; j <= n; j++)
                if (C[j] == C[i])
                {
                    printf_s(" %d", j);
                    C[j] = 0;
                }
            printf_s("\n");
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
