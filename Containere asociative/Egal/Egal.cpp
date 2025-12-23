// Egal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#define NMAX 100001
using namespace std;
int N;
vector<int>G[NMAX];
map<int, int>M[NMAX];
int c[NMAX], cmax[NMAX], nr[NMAX];
vector<bool>viz(NMAX, false);
map<int, int>::iterator it;

void citire();
void DFS(int x);
void afisare();

int main()
{
    citire();
    DFS(1);
    afisare();
    return 0;
}

void citire()
{
    FILE* fin;
    errno_t err = fopen_s(&fin, "egal.in", "r");
    int i, x, y;
    fscanf_s(fin, "%d", &N);
    for (i = 0; i < N - 1; i++)
    {
        fscanf_s(fin, "%d %d", &x, &y);
        G[x].push_back(y); G[y].push_back(x);
    }
    for (i = 1; i <= N; i++) fscanf_s(fin, "%d", &c[i]);
    fclose(fin);
}

void DFS(int x)
{
    int i, maxim, chmax;
    viz[x] = true;
    for (i = 0; i < G[x].size(); ++i)
    {
        if (!viz[G[x][i]])
        {
            DFS(G[x][i]);
            for (it = M[G[x][i]].begin(); it != M[G[x][i]].end(); ++it)
                M[x][it->first] += it->second;
        }
    }

    M[x][c[x]]++;
    maxim = 0;
    for (it = M[x].begin(); it != M[x].end(); ++it)
        if (it->second > maxim)
        {
            maxim = it->second;
            chmax = it->first;
        }
    cmax[x] = chmax; nr[x] = maxim;
}

void afisare()
{
    FILE* fout;
    errno_t err = fopen_s(&fout, "egal.out", "w");
    int x;
    for (x = 1; x <= N; x++)
        fprintf_s(fout, "%d %d\n", cmax[x], nr[x]);
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
