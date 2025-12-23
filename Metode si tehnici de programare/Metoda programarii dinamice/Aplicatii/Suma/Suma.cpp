// Suma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define maxn 2000

int a[maxn], L, n;
long smax[4][maxn];

void Citire(void)
{
    FILE* fin;
    errno_t err = fopen_s(&fin, "suma.in", "r");
    int i;
    char sir_nr[maxn] = "", sir[maxn] = "";
    fscanf_s(fin, "%d", &n);
    fgetc(fin);
    fgets(sir_nr, maxn, fin); // Citim numerele intr-un sir de caractere
    int j = 0;
    for (i = 0; i < strlen(sir_nr) - 1; i++) // Concatenam numerele la sirul cifrelor
        if (sir_nr[i] != ' ') sir[j++] = sir_nr[i];
    L = strlen(sir); // Determin numarul total de cifre
    for (i = 1; i <= L; i++)
        a[i] = sir[i - 1] - '0';
    fclose(fin);
}

void Rezolvare(void)
{
    int i, j;
    long suma;
    for (i = 0; i < 4; i++) // Initializare
        for (j = 0; j <= n; j++) smax[i][j] = -1;
    smax[0][0] = 0; smax[1][1] = a[1]; smax[2][1] = a[1] * 10 + a[2];
    if (a[2]) smax[2][2] = a[1] + a[2];
    smax[3][1] = a[1] * 100 + a[2] * 10 + a[3];
    if (a[2]) smax[3][2] = a[1] + a[2] * 10 + a[3];
    if (a[3] && smax[3][2] < a[1] * 10 + a[2] + a[3])
        smax[3][2] = a[1] * 10 + a[2] + a[3];
    if (a[2] && a[3])
        smax[3][3] = a[1] + a[2] + a[3];
    for (i = 4; i <= L; i++)
    {
        smax[i % 4][0] = smax[i % 4][1] = -1;
        for (j = 2; j <= i; j++)
        {
            if (!a[i]) smax[i % 4][j] = -1;
            else // Folosim o singura cifra
            {
                if (smax[(i + 3) % 4][j - 1] != -1)
                {
                    suma = smax[(i + 3) % 4][j - 1] + a[i];
                    smax[i % 4][j] = suma;
                }
            }
            if (a[i - 1]) // Folosim doua cifre
            {
                if (smax[(i + 2) % 4][j - 1] != -1)
                {
                    suma = smax[(i + 2) % 4][j - 1] + a[i - 1] * 10 + a[i];
                    if(suma > smax[i % 4][j]) smax[i % 4][j] = suma;
                }
            }
            if (a[i - 2]) // Folosim trei cifre
            {
                if (smax[(i + 1) % 4][j - 1] != -1)
                {
                    suma = smax[(i + 1) % 4][j - 1] + a[i - 2] * 100 + a[i - 1] * 10 + a[i];
                    if (suma > smax[i % 4][j]) smax[i % 4][j] = suma;
                }
            }
        }
    }
}

void Afisare(void)
{
    FILE* fout;
    errno_t err = fopen_s(&fout, "suma.out", "w");
    fprintf_s(fout, "%ld\n", smax[L % 4][n]);
    fclose(fout);
}

int main(void)
{
    Citire();
    Rezolvare();
    Afisare();
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
