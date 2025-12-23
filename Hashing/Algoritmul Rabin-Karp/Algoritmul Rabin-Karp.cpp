// Algoritmul Rabin-Karp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMAX 1000

char T[NMAX], P[NMAX];
int n, m;

unsigned long putere(int d, int m)
{
    int i;
    unsigned long p = 1;
    for (i = 1; i < m; i++) p *= d;
    return p;
}

int EQ(char* P, char* T, int k)
{
    int i;
    for (i = 0; i < m; i++)
        if (P[i] != T[k + 1]) return 0;
    return 1;
}

int RABIN_KARP(char* T, char* P, int d, int q)
{
    unsigned long h, p, t0;
    int i, k;
    n = strlen(T); m = strlen(P);
    h = putere(d, m) % q;
    p = 0; t0 = 0;
    for (i = 0; i < m; i++) // Preprocesare pattern
    {
        p = (d * p + P[i]) % q; // Calculez p
        t0 = (d * t0 + T[i]) % q; // si t0 initial
    }
    for (k = 0; k <= n - m; k++)
    {
        if (p == t0) // Incerc toate posibilele deplasamente
            if (EQ(P, T, k)) return k; // Am gasit la pozitia k
        t0 = (t0 + d * q - T[k] * h) % q; // Recalculez t0
        t0 = (t0 * d + T[k + m]) % q;
    }
    return -1; // Nu am gasit
}

int main()
{
    int poz;
    FILE* stream;
    errno_t err;
    err = freopen_s(&stream, "rk_sir.in", "r", stdin);
    err = freopen_s(&stream, "rk_sir.out", "w", stdout);
    gets_s(T);
    gets_s(P);
    fclose(stdin);
    poz = RABIN_KARP(T, P, 128, 131); // d=128, q=131
    if (poz >= 0) printf_s("Gasit in pozitia %d\n", poz);
    else printf("Subsir negasit\n");
    fclose(stdout);
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
