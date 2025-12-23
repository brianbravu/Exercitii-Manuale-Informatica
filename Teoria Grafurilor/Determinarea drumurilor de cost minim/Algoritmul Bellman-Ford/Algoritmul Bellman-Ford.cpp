// Algoritmul Bellman-Ford.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMaxVf 50
#define Inf 10000

int n, x0;
double C[NMaxVf][NMaxVf];
int pre[NMaxVf], M[NMaxVf];
double d[NMaxVf];

void Initializare();
void Afisare();
int Bellman_Ford();

int main()
{
    int i, VfMin, j;
    double dMin;
    Initializare();
    if (!Bellman_Ford()) cout << "Graful contine un circuit de cost negativ.\n";
    else cout << "Graful nu contine un circuit de cost negativ.\n";
    Afisare();
}

void Initializare()
{
    int i, j, m, x, y;
    double c;
    ifstream fin("graf.in");
    fin >> n >> m >> x0;
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++)
            C[j][i] = C[i][j] = Inf;
    for (i = 1; i <= m; i++)
    {
        fin >> x >> y >> c;
        C[x][y] = c;
    }
    for (i = 1; i <= n; i++)
    {
        d[i] = C[x0][i];
        pre[i] = x0;
    }
    M[x0] = 1; pre[x0] = 0;
    fin.close();
}

void Afisare()
{
    int i, j, lg, dr[NMaxVf];
    for (i = 1; i <= n; i++)
        if (i != x0)
        {
            cout << "Costul drumului de cost minim de la " << x0 << " la " << i << " este " << d[i] << "\n";
            cout << "Drumul de cost minim: ";
            dr[0] = i; lg = 0;
            while (pre[dr[lg]])
            {
                lg++;
                dr[lg] = pre[dr[lg - 1]];
            }
            for (j = lg; j >= 0; j--) cout << dr[j] << " ";
            cout << "\n";
        }
}

int Bellman_Ford()
{
    int i, j, k;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++)
                if (C[j][k] != Inf && d[k] > d[j] + C[j][k])
                {
                    d[k] = d[j] + C[j][k];
                    pre[k] = j;
                }
    for (j = 1; j <= n; j++)
        for (k = 1; k <= n; k++)
            if (C[j][k] != Inf && d[k] > d[j] + C[j][k])
                return 0;
    return 1;
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
