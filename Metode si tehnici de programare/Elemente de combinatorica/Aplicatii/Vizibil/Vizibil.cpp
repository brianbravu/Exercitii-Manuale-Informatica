// Vizibil.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
#define Mod 997
#define InFile "vizibil.in"
#define OutFile "vizibil.out"

long s[NMax][NMax];
long Comb[NMax], rez;
void Citire(void);
void Afisare(void);
void Determinare_Combinari(void);
void Determinare_S(void);
int n, p, q;

int main()
{
    int k;
    Citire();
    Determinare_Combinari();
    Determinare_S();
    if (p == 1) rez = s[n - 1][q - 1];
    else if (q == 1) rez = s[n - 1][p - 1];
    else for (k = p; k <= n - q + 1; k++)
        rez = (rez + s[k - 1][p - 1] * s[n - k][q - 1] * Comb[k - 1]) % Mod;
    Afisare();
}

void Citire()
{
    FILE* fin;
    errno_t err = fopen_s(&fin, InFile, "r");
    fscanf_s(fin, "%d %d %d", &n, &p, &q);
    fclose(fin);
}

void Afisare()
{
    FILE* fout;
    errno_t err = fopen_s(&fout, OutFile, "w");
    fprintf_s(fout, "%d\n", rez);
    fclose(fout);
}

void Determinare_Combinari()
{
    long C[NMax];
    int i, j;
    C[0] = Comb[0] = C[1] = 1;
    for (i = 2; i < n; i++)
    {
        for (j = 1; j < i; j++) Comb[j] = (C[j] + C[j - 1]) % Mod;
        Comb[i] = 1;
        for (j = 1; j <= i; j++) C[j] = Comb[j];
    }
}

void Determinare_S()
{
    int i, j;
    s[1][1] = 1;
    for (i = 2; i < n; i++)
        s[i][1] = (s[i - 1][1] * (i - 1)) % Mod;
    for (i = 2; i < n; i++)
        for (j = 2; j <= i; j++)
            s[i][j] = (s[i - 1][j - 1] + (i - 1) * s[i - 1][j]) % Mod;
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
