// Auto.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define InFile "auto.in"
#define OutFile "auto.out"
#define NMax 101
#define MMax 500
#define TMax 101
#define oo 300000000

int n, m, a, b, tf;
int p[NMax];
int mad[NMax][NMax];
int lung[MMax];
int cost_auto[MMax][TMax];
int c_min[NMax][NMax];
void Read_it(void);
void Solve(void);
void Write_it(void);

int main()
{
    Read_it();
    Solve();
    Write_it();
}

void Read_it()
{
    int i, j, o1, o2, l;
    FILE* fin;
    errno_t err = fopen_s(&fin, InFile, "r");
    fscanf_s(fin, "%d %d\n", &n, &m);
    fscanf_s(fin, "%d %d %d\n", &a, &b, &tf);
    a--; b--;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mad[i][j] = -1;
    for (i = 0; i < n; i++)
        fscanf_s(fin, "%d", &p[i]);
    p[a] = p[b] = 0;
    for (i = 0; i < m; i++)
    {
        fscanf_s(fin, "%d %d %d\n", &o1, &o2, &l);
        mad[o1 - 1][o2 - 1] = mad[o2 - 1][o1 - 1] = i;
        lung[i] = l;
        for (j = 0; j < tf; j++)
            fscanf_s(fin, "%d", &cost_auto[i][j]);
    }
    fclose(fin);
}

void Solve()
{
    int i, j, k, l, lm, m;
    for (i = 0; i < n; i++)
        for (j = 0; j < tf; j++) c_min[i][j] = -1;
    c_min[a][0] = 0;
    for (i = 1; i <= tf; i++)
        for (j = 0; j < n; j++)
        {
            c_min[j][i] = oo;
            for (k = 0; k < i; k++)
                for (l = 0; l < n; l++)
                {
                    if (c_min[l][k] == -1) continue;
                    if (mad[j][l] == -1) continue;
                    lm = lung[mad[j][l]];
                    if (lm > i - k) continue;
                    m = c_min[l][k] + cost_auto[mad[j][l]][i - lm] * lm + p[l] * (i - k - lm);
                    if (m < c_min[j][i]) c_min[j][i] = m;
                }
            if (c_min[j][i] == oo) c_min[j][i] = -1;
        }
}

void Write_it()
{
    FILE* fout;
    errno_t err = fopen_s(&fout, OutFile, "w");
    int j, min = oo;
    for (j = 0; j <= tf; j++)
        if (c_min[b][j] != -1 && c_min[b][j] < min)
            min = c_min[b][j];
    fprintf_s(fout, "%d\n", min);
    fclose(fout);
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
