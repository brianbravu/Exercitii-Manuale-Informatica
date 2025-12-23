// Algoritmul lui Kruskal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMaxVf 50
#define NMaxMuchii NMaxVf*(NMaxVf-1)/2

struct Muchie { int e1, e2, cost; };

Muchie G[NMaxMuchii];
int A[NMaxVf], c[NMaxVf];
int n, m;

void Initializare()
{
    int i;
    ifstream fin("Kruskal.in");
    fin >> n >> m;
    for (i = 1; i <= m; i++)
        fin >> G[i].e1 >> G[i].e2 >> G[i].cost;
    for (i = 1; i <= n; i++) c[i] = i;
    fin.close();
}

void Afisare()
{
    int i, CostAPM = 0;
    cout << "Arborele partial de cost minim este: \n";
    for (i = 1; i < n; i++)
    {
        cout << "{" << G[A[i]].e1 << "," << G[A[i]].e2 << "} cost=" << G[A[i]].cost << "\n";
        CostAPM += G[A[i]].cost;
    }
    cout << "Costul APM=" << CostAPM << "\n";
}

void SortareMuchii(int st, int dr)
{
    int i, j;
    Muchie x;
    if (st < dr)
    {
        x = G[st]; i = st; j = dr;
        while (i < j)
        {
            while (i < j && G[j].cost >= x.cost) j--;
            G[i] = G[j];
            while (i < j && G[i].cost <= x.cost) i++;
            G[j] = G[i];
        }
        G[i] = x;
        SortareMuchii(st, i - 1);
        SortareMuchii(i + 1, dr);
    }
}

int main()
{
    int i, j, min, max, NrMSel;
    Initializare();
    SortareMuchii(1, m);
    NrMSel = 0; // Numarul de muchii selectate
    for (i = 1; NrMSel < n - 1; i++)
        if (c[G[i].e1] != c[G[i].e2])
            // Muchia i nu formeaza cicluri cu cele deja selectate
        {
            // Selectez muchia i
            A[++NrMSel] = i;
            // Unific componentele conexe ale extremitatilor
            if (c[G[i].e1] < c[G[i].e2])
            {
                min = c[G[i].e1];
                max = c[G[i].e2];
            }
            else
            {
                min = c[G[i].e2];
                max = c[G[i].e1];
            }
            for (j = 1; j <= n; j++)
                if (c[j] == max) c[j] = min;
        }
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
