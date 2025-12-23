// Fotografie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define DimMax 50

int Dx[4] = { -1,0,1,0 }, Dy[4] = { 0,1,0,-1 };
int a[DimMax][DimMax], m, n, NrObiecte;

void Citire()
{
    ifstream fin("foto.in");
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) fin >> a[i][j];
    fin.close();
}

void Sterge_Obiect(int x, int y)
{
    if (a[x][y])
    {
        a[x][y] = 0; // Sterg acest element de imagine
        // Cautarea continua in cele 4 directii posibile
        for (int dir = 0; dir < 4; dir++)
            Sterge_Obiect(x + Dx[dir], y + Dy[dir]);
    }
}

int main()
{
    Citire();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j]) // Am depistat un obiect
            {
                NrObiecte++;
                Sterge_Obiect(i, j);
            }
    cout << "Nr. obiecte = " << NrObiecte << endl;
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
