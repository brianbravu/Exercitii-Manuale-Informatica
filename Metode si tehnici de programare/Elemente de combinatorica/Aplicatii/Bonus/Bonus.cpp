// Bonus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define InFile "bonus.in"
#define OutFile "bonus.out"
#define NMax 35

FILE* fin, * fout;
int n, x;
int s[NMax];
long int nr;

void detsubm(void);
long detnr(void);

int main()
{
    long int m, i, j;
    int tip, a;
    errno_t err = fopen_s(&fin, InFile, "r"); err = fopen_s(&fout, OutFile, "w");
    fscanf_s(fin, "%d", &n); fscanf_s(fin, "%ld", &m);
    for (j = 1; j <= m; j++)
    {
        fscanf_s(fin, "%d", &tip);
        for (i = 0; i <= n; i++) s[i] = 0;
        if (tip == 1)
        {
            fscanf_s(fin, "%d", &x);
            for (i = 0; i < x; i++)
            {
                fscanf_s(fin, "%d", &a); s[a] = 1;
            }
            nr = detnr();
            fprintf_s(fout, "%ld\n", nr);
        }
        else
        {
            fscanf_s(fin, "%ld", &nr);
            detsubm();
            for (i = 1; i <= n; i++)
                if (s[i]) fprintf_s(fout, "%d ", i);
            fprintf_s(fout, "\n");
        }
    }
    fclose(fin);
    fclose(fout);
}

long detnr(void)
{
    long nro = 0, gasit = 0;
    int pas;
    for (pas = 1; pas <= n && gasit < x; pas++)
        if (!s[pas]) nro += 1 << n - pas;
        else
        {
            nro++; gasit++;
        }
    return nro;
}

void detsubm(void)
{
    int pas = 0;
    while (nr)
    {
        pas++;
        if (nr <= 1 << n - pas)
        {
            s[pas] = 1; nr--;
        }
        else
        {
            nr -= 1 << n - pas;
        }
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
