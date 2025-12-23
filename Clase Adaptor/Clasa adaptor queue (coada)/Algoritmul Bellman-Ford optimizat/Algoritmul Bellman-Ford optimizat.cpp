// Algoritmul Bellman-Ford optimizat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
#define NMAX 50001
using namespace std;
int n, x0;
vector<pair<int, int>>G[NMAX];
int dmin[NMAX];
int nr[NMAX];
bool negativ;
queue<int>C;

void citire();
void bellman_ford();
void afisare();

int main()
{
    citire();
    bellman_ford();
    afisare();
    return 0;
}

void citire()
{
    int i, m, x, y, c;
    FILE* fin;
    errno_t err = fopen_s(&fin, "bellmanford.in", "r");
    fscanf_s(fin, "%d %d %d", &n, &m, &x0);
    for (i = 0; i < m; i++)
    {
        fscanf_s(fin, "%d %d %d", &x, &y, &c);
        G[x].push_back(make_pair(y, c));
    }
    fclose(fin);
}

void bellman_ford()
{
    vector<pair<int, int>>::iterator it;
    int i, x;
    for (i = 1; i <= n; i++) dmin[i] = INF;
    dmin[x0] = 0;
    C.push(x0);
    while (!C.empty() && !negativ)
    {
        x = C.front(); C.pop();
        for (it = G[x].begin(); it != G[x].end(); it++)
            if (dmin[it->first] > dmin[x] + it->second)
            {
                dmin[it->first] = dmin[x] + it->second;
                nr[it->first]++;
                C.push(it->first);
                if (nr[it->first] > n) negativ = true;
            }
    }
}

void afisare()
{
    FILE* fout;
    errno_t err = fopen_s(&fout, "bellmanford.out", "w");
    if (negativ)
        fprintf_s(fout, "Circuit de cost negativ!\n");
    else
    {
        for (int i = 1; i <= n; i++)
            if (i != x0)
                fprintf_s(fout, "%d ", dmin[i] != INF ? dmin[i] : 0);
        fprintf_s(fout, "\n");
    }
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
