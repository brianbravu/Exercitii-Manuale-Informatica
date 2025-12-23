// Aplicatie. Desert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
char s[260];
int q, x, y, z, n, nc;
long v[1030], l1;
int Urm[1030], poz[230];
unsigned long contor;
FILE* f, * g;
long s2l(char* s) // Codifica constructia pe biti
{
    long l = 0;
    int i;
    for (i = 0; i < 32; i++)
    {
        l <<= 1;
        if (s[i] == '#') l |= 1;
    }
    return l;
}

int main()
{
    char c;
    errno_t err = fopen_s(&f, "desert.in", "r");
    fscanf_s(f, "%d %d", &n, &nc);
    c = fgetc(f);
    for (q = 1; q <= nc; q++)
    {
        fgets(s, 260, f);
        // c = fgetc(f);
        v[q] = s2l(s);
    }
    for (x = 2; x <= nc; x++) // Se construieste vectorul Urm
    {
        y = Urm[x - 1];
        if (v[x] == v[y + 1])
            Urm[x] = Urm[x - 1] + 1;
        else if (v[x] == v[1]) Urm[x] = 1;
    }
    for (q = 1; q <= n; q++) // Analizez cele n linii ale fotografiei
    {
        fgets(s, 260, f); // Citesc o linie
        // c = fgetc(f);
        l1 = s2l(s); // Codific primele 32 caractere
        for (x = 0; x <= 223; x++) // Parcurg cele 255-32 caractere
        {
            y = poz[x];
            if (v[y + 1] == l1)
            {
                y++; // Am mai gasit o potrivire - o numar
                if (y == nc) // Am detectat o constructie
                {
                    contor++; // O numar
                    y = Urm[y];
                }
            }
            else // Daca NU caut alt deplasament
                while ((y > 0) && (v[y + 1] != l1)) y = Urm[y];
            poz[x] = y;
            l1 <<= 1;
            l1 |= x < 223 && s[x + 32] == '#'; // Codific ultimul bit
        }
    }
    fclose(f);
    err = fopen_s(&g, "desert.out", "w");
    fprintf_s(g, "%lu\n", contor);
    fclose(g);
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
