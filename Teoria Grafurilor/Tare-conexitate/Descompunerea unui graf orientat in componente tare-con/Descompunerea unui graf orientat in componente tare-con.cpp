// Descompunerea unui graf orientat in componente tare-con.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
int n, nr, nrc;
int* A[NMax], * AT[NMax];
int postordine[NMax], viz[NMax];

void Citire();
void DFS(int);
void DFST(int);

int main()
{
    int i;
    Citire();
    // Parcurgem graful DFS, determinand ordinea varfurilor
    for (i = 1; i <= n; i++)
        if (!viz[i]) DFS(i);
    // Parcurgem DFS graful transpus,
    // prelucrand varfurile in postordine
    for (i = n; i > 0; i--)
        if (viz[postordine[i]])
            // Componenta tare-conexa din care face parte 
            // varful curent nu a fost determinata
        {
            printf_s("Componenta tare-conexa %d: ", ++nrc);
            DFST(postordine[i]);
            printf_s("\n");
        }
}

void Citire()
{
    // Construim graful si graful transpus
    FILE* fin;
    errno_t err;
    err = fopen_s(&fin, "graf.in", "r");
    int x, y, m, i;
    fscanf_s(fin, "%d %d", &n, &m);
    // Aloc memorie pentru gradul fiecarui varf
    for (i = 1; i <= n; i++)
    {
        A[i] = (int*)realloc(A[i], sizeof(int));
        A[i][0] = 0;
        AT[i] = (int*)realloc(AT[i], sizeof(int));
        AT[i][0] = 0;
    }
    for (i = 0; i < m; i++)
    {
        fscanf_s(fin, "%d %d", &x, &y);
        A[x][0]++;
        A[x] = (int*)realloc(A[x], (A[x][0] + 1) * sizeof(int));
        A[x][A[x][0]] = y;
        AT[y][0]++;
        AT[y] = (int*)realloc(AT[y], (AT[y][0] + 1) * sizeof(int));
        AT[y][AT[y][0]] = x;
    }
}

void DFST(int x)
{
    int i;
    viz[x] = 0; printf_s("%d ", x);
    for (i = 1; i <= AT[x][0]; i++)
        if (viz[AT[x][i]])
            DFST(AT[x][i]);
}

void DFS(int x)
{
    int i;
    viz[x] = 1;
    for (i = 1; i <= A[x][0]; i++)
        if (!viz[A[x][i]])
            DFS(A[x][i]);
    postordine[++nr] = x;
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
