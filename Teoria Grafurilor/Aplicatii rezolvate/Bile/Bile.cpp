// Bile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define maxn 301
#define infile "bile.in"
#define outfile "bile.out"

int n, m, res, nrviz;
int g[maxn][maxn], gt[maxn][maxn];
int d[maxn], dt[maxn], viz[maxn];

void dfs(int);
void dfsT(int);
void citire();
void rezolvare();
void afisare();

int main()
{
    citire();
    rezolvare();
    afisare();
}

void citire()
{
    int tmp1, tmp2, i, j;
    for (i = 0; i < maxn; i++)
    {
        d[i] = 0; dt[i] = 0;
        for (j = 0; j < maxn; j++)
            g[i][j] = gt[i][j] = 0;
    }
    ifstream indat(infile);
    indat >> n >> m;
    // Construim graful G si graful transpus GT
    for (i = 0; i < m; i++)
    {
        indat >> tmp1 >> tmp2;
        tmp1--; tmp2--;
        g[tmp1][d[tmp1]] = tmp2; d[tmp1]++;
        gt[tmp2][dt[tmp2]] = tmp1; dt[tmp2]++;
    }
    indat.close();
}

void rezolvare()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        // Pentru fiecare bila i
        nrviz = 0;
        for (j = 0; j < n; j++) viz[j] = 0;
        // Determin numarul de bile mai grele decat bila i
        dfs(i);
        if (nrviz >= (n + 1) / 2) res++;
        else
        {
            nrviz = 0;
            for (j = 0; j < n; j++) viz[j] = 0;
            // Determin nr. de bile mai usoare decat bila i
            dfsT(i);
            if (nrviz >= (n + 1) / 2) res++;
        }
    }
}

void afisare()
{
    ofstream outdat(outfile);
    outdat << res << "\n";
    outdat.close();
}

void dfs(int i)
{
    int j;
    for (j = 0; j < d[i]; j++)
        if (viz[g[i][j]] == 0)
        {
            viz[g[i][j]] = 1;
            nrviz++;
            dfs(g[i][j]);
        }
}

void dfsT(int i)
{
    int j;
    for (j = 0; j < dt[i]; j++)
        if (viz[gt[i][j]] == 0)
        {
            viz[gt[i][j]] = 1;
            nrviz++;
            dfsT(gt[i][j]);
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
