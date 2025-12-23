// Caroiaj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iomanip>
using namespace std;
#define DimMax 20
#define DimMaxCoada 400

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }; // Deplasarile pe linie si coloana pe directiile V, N, E, S
struct Element
{
    int l, c; // Pozitia in caroiaj
    unsigned d; // Distanta minima pana la pozitia (l, c)
};
struct Element C[DimMaxCoada], x, y;
int A[DimMax][DimMax], n, m, x0, y00, i, j, k, IncC, SfC;
int main()
{
    ifstream fin("careu.in");
    fin >> n >> m; // Citesc dimensiunile caroiajului
    fin >> x0 >> y00; // Citesc pozitia initiala
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) A[i][j] = -2; // Marchez cu -2 pozitiile libere
    while (fin)
    {
        fin >> i >> j; // Citesc coordonatele obstacolelor
        A[i][j] = -1; // Marchez obstacolele cu -1
    }
    fin.close();
    for (i = 1; i <= n; i++) A[i][0] = A[i][m + 1] = -1; // Bordez caroiajul 
    for (j = 1; j <= m; j++) A[0][j] = A[n + 1][i] = -1; // cu obstacole
    x.l = x0; x.c = y00; x.d = 0; A[x0][y00] = 0; // Initializez coada
    C[IncC] = x; // Pozitia initiala
    while (IncC <= SfC) // Parcurg caroiajul
    {
        x = C[IncC++]; // Extrag un element din coada
        for (k = 0; k < 4; k++) // Ma deplasez in cele 4 directii posibile
        {
            y.l = x.l + dx[k]; y.c = x.c + dy[k]; // y - urmatoarea pozitie in directia k
            if (A[y.l][y.c] == -2) // y - pozitie libera cu distanta minima necalculata
            {
                y.d = x.d + 1; A[y.l][y.c] = y.d;
                C[++SfC] = y; // Inserez pozitia y in coada
            }
        }
    }
    ofstream fout("careu.out");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++) fout << setw(3) << A[i][j] << ' ';
        fout << '\n';
    }
    fout.close();
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
