// Algoritmul lui Prim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMaxVf 100
#define Inf 10000

int n, r, i, VfMin, nrv;
double G[NMaxVf][NMaxVf];
int p[NMaxVf], Z[NMaxVf];
double cmin[NMaxVf], CostMin;

void Initializare()
{
    int i, j, k;
    double c;
    ifstream fin("prim.in");
    fin >> n >> r;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) G[i][j] = Inf;
    for (i = 1; i <= n; i++)
    {
        G[i][i] = 0;
        fin >> nrv; // nrv - nr. de varfuri adiacente cu i
        for (j = 1; j <= nrv; j++)
        {
            // Cttesc varfurile adiacente cu i
            // si costurile muchiilor componente
            fin >> k >> c;
            G[i][k] = c;
        }
    }
    for (i = 1; i <= n; i++)
    {
        cmin[i] = G[r][i];
        p[i] = r; Z[i] = 1;
    }
    Z[r] = 0; p[r] = 0; nrv = n - 1;
    fin.close();
}

void AfisareAPM()
{
    int i;
    double cost = 0;
    cout << "Muchiile APM sunt: ";
    for (i = 1; i <= n; i++)
        if (i != r)
        {
            cout << "{" << p[i] << "," << i << "} ";
            cost += G[i][p[i]];
        }
    cout << "\n" << "Costul APM este " << cost << "\n";
}

int main()
{
    Initializare();
    // Cat timp mai exista varfuri neselectate
    while (nrv)
    {
        // Determin modul din Z de cheie min
        CostMin = Inf;
        for (i = 1; i <= n; i++)
            if (Z[i] && CostMin > cmin[i])
            {
                CostMin = cmin[i];
                VfMin = i;
            }
        // Elimin VfMin din multimea varfurilor neselectate
        Z[VfMin] = 0;
        nrv--;
        // Actualizez cheile varfurilor din Z
        for (i = 1; i <= n; i++)
            if (Z[i] && G[i][VfMin] < cmin[i])
            {
                p[i] = VfMin;
                cmin[i] = G[i][VfMin];
            }
    }
    AfisareAPM();
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
