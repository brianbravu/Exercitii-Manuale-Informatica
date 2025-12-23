// Implementare dinamica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
int n;
int* A[NMax];

void Citire();
void Afisare();

int main()
{
    Citire();
    Afisare();
}

void Citire()
{
    FILE* fin;
    errno_t err; 
    err = fopen_s(&fin, "grafn.in", "r");
    int x, y, m, i;
    fscanf_s(fin, "%d %d", &n, &m);
    // Aloc memorie pentru gradul fiecarui varf
    for (i = 1; i <= n; i++)
    {
        A[i] = (int*)realloc(A[i], sizeof(int));
        A[i][0] = 0;
    }
    for (i = 0; i < m; i++)
    {
        fscanf_s(fin, "%d %d", &x, &y);
        A[x][0]++; // Incrementam gradul varfului x
        // Realocam memorie pentru lista de adiacenta a lui x
        A[x] = (int*)realloc(A[x], (A[x][0] + 1) * sizeof(int));
        // Memoram pe y in lista de adiacenta a lui x
        A[x][A[x][0]] = y;
        A[y][0]++; // Incrementam gradul varfului y
        // Realocam memorie pentru lista de adiacenta a lui y
        A[y] = (int*)realloc(A[y], (A[y][0] + 1) * sizeof(int));
        // Memoram pe x in lista de adiacenta a lui y
        A[y][A[y][0]] = x;
    }
}

void Afisare()
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        printf_s("Lista de adiacenta a varfului %d: ", i);
        for (j = 1; j <= A[i][0]; j++) printf_s("%d ", A[i][j]);
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
