// Labirint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define DimMax 20

int Dx[8] = { -1,-1,0,1,1,1,0,-1 };
int Dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int L[DimMax][DimMax];
int n, m, xs, ys, xb, yb, NrSol;
ofstream fout("labirint.out");

void Citire()
{
    ifstream f("labirint.in");
    f >> n >> m >> xs >> ys >> xb >> yb;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) f >> L[i][j];
    f.close();
}

void Bordare()
{
    // Bordam labirintul cu cate un perete
    for (int i = 0; i <= n + 1; i++) // Peretele la stanga si la dreapta
        L[i][0] = L[i][m + 1] = 1;
    for (int i = 0; i <= m + 1; i++) // Peretele sus si jos
        L[0][i] = L[n + 1][i] = 1;
}

void Afisare()
{
    fout << "Solutia nr. " << ++NrSol << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (L[i][j] == 2) fout << '*';
            else fout << L[i][j];
        fout << endl;
    }
}

void Cauta(int x, int y)
{
    L[x][y] = 2;
    if (x == xb && y == yb) Afisare(); // Marchez pozitia x, y
    else for (int dir = 0; dir < 8; dir++)
        if (!L[x + Dx[dir]][y + Dy[dir]]) // Culoar nevizitat
            Cauta(x + Dx[dir], y + Dy[dir]);
    L[x][y] = 0; // La intoarcere, sterg marcajul, pentru a putea explora acest culoar si in alta varianta
}
int main()
{
    Citire(); Bordare();
    Cauta(xs, ys);
    if (!NrSol) fout << "Nu exista solutii!\n";
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
