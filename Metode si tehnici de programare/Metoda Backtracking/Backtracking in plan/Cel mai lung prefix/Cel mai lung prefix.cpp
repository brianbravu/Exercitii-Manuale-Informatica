// Cel mai lung prefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define DimMax 30 // Dimensiunea maxima a labirintului

int Dx[8] = { -1,-1,0,1,1,1,0,-1 };
int Dy[8] = { 0,1,1,1,0,-1,-1,-1 };
char s[200];
int Lg, LgMax, n, m;
char C[DimMax][DimMax];

void Citire()
{
    ifstream fin("prefix.in");
    fin.getline(s, sizeof(s)); fin >> n >> m; fin.get();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            fin.get(C[i][j]);
        fin.get();
    }
    fin.close();
}

void Bordare()
{
    // Bordez matricea cu spatii
    for (int i = 0; i <= n + 1; i++) C[i][0] = C[i][m + 1] = ' ';
    for (int i = 0; i <= m + 1; i++) C[0][i] = C[0][n + 1] = ' ';
}

void Cauta(int i, int j)
{
    // Verific daca elementul de pe linia i, coloana j coincide cu litera de pe pozitia Lg din cuvant
    if (tolower(C[i][j]) == tolower(s[Lg])) // Am gasit o litera
    {
        Lg++; // Lungimea prefixului curent creste
        for (int k = 0; k < 8; k++) Cauta(i + Dx[k], j + Dy[k]);
        Lg--; // Restaurez lungimea prefixului curent
    }
    else // Prefixul este maximal
        if (Lg > LgMax) LgMax = Lg; // Am comparat lungimea prefixului curent cu lungimea maxima obtinuta pana acum si, daca e cazul, o retin
}

int main()
{
    Bordare(); Citire();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) Cauta(i, j);
    s[LgMax] = NULL;
    cout << "Prefixul maximal este " << s;
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
