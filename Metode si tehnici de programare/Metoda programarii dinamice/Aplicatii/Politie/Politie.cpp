// Politie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define InFile "politie.in"
#define OutFile "politie.out"
#define NMax 501
#define TMax 302

int nr, S[4], T[4], Tura;
struct Ev { int timp; char tip; } e[NMax];
unsigned int* smax1[TMax], * smax2[TMax];

void citire(void);
void afisare(void);
void rezolva(void);

int main()
{
    citire();
    rezolva();
    afisare();
}

void citire(void)
{
    int x, y, i, N, j;
    FILE* f;
    errno_t err = fopen_s(&f, InFile, "r");
    fscanf_s(f, "%d", &Tura);
    for (i = 1; i < 4; i++) fscanf_s(f, "%d %d", &S[i], &T[i]);
    fscanf_s(f, "%d", &N);
    nr = 0;
    for (i = 1; i <= N; i++)
    {
        fscanf_s(f, "%d %d", &x, &y);
        if (y + T[x] <= Tura)
        {
            nr++; e[nr].timp = y; e[nr].tip = x;
        }
    }
    for (i = 0; i <= Tura + 1; i++)
    {
        smax1[i] = (unsigned*)calloc(Tura + 2, sizeof(unsigned));
        if (!smax1[i])
        {
            printf_s("Memorie insuficienta\n"); exit(1);
        }
    }
    for (i = 0; i <= Tura + 1; i++)
    {
        smax2[i] = (unsigned*)calloc(Tura + 2, sizeof(unsigned));
        if (!smax2[i])
        {
            printf_s("Memorie insuficienta\n"); exit(1);
        }
    }
    for (i = 0; i <= Tura + 1; i++)
        for (j = 0; j <= Tura + 1; j++)
            smax1[i][j] = smax2[i][j] = 0;
    fclose(f);
}

void afisare()
{
    FILE* g;
    errno_t err = fopen_s(&g, OutFile, "w");
    fprintf_s(g, "%u\n", smax2[1][1]);
    fclose(g);
}

void rezolva(void)
{
    int t, tip, i, t1, t2;
    for (i = nr; i >= 1; i--)
    {
        t = e[i].timp; tip = e[i].tip;
        for (t1 = Tura; t1 >= 1; t1--)
            for (t2 = Tura; t2 >= 1; t2--)
            {
                if (tip < 3)
                {
                    if (t1 <= t) // Primul politist da amenda
                        if (smax1[t1][t2] < S[tip] + smax2[t + T[tip]][t2])
                            smax1[t1][t2] = S[tip] + smax2[t + T[tip]][t2];
                    if (t2 <= t) // Al doilea politist da amenda
                        if (smax1[t1][t2] < S[tip] + smax2[t1][t + T[tip]])
                            smax1[t1][t2] = S[tip] + smax2[t1][t + T[tip]];
                }
                else
                {
                    if (t1 <= t && t2 <= t)
                        if (smax1[t1][t2] < S[3] + smax2[t + T[3]][t + T[3]])
                            smax1[t1][t2] = S[3] + smax2[t + T[3]][t + T[3]];
                }
            }
        for (t1 = Tura; t1 >= 1; t1--)
            for (t2 = Tura; t2 >= 1; t2--)
                smax2[t1][t2] = smax1[t1][t2];
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
