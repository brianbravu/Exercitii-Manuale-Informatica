// Partitiile unei multimi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int n; // Numarul de elemente din multime
int nc; // Numaul de clase
int P[30]; // Partitia
int NrP; // Numarul de partitii
ofstream fout("part.out"); // Fisierul de iesire

void Afisare()
{
    fout << "Partitia " << ++NrP << ": ";
    for (int j = 1; j <= nc; j++) // Afisez clasa nr. j
    {
        fout << " { ";
        for (int i = 1; i <= n; i++)
            if (P[i] == j) fout << i << ' ';
        fout << '}';
    }
    fout << endl;
}

void GenPartitie(int k) // Cand apelam functia GenPartitie, in vectorul P pe primele k-1 pozitii se afla o partitie a multimii 1, 2, ..., k-1 formata din NC clase
{
    if (k - 1 == n) Afisare(); // Partitia este complet construita
    else
    {
        for (int j = 1; j <= nc; j++) // Plasam elementul k in una dintre clasele existente sau elementul k reprezinta o clasa separata
        {
            P[k] = j;
            GenPartitie(k + 1);
        }
        nc++; // Maresc numarul de clase
        P[k] = nc;
        GenPartitie(k + 1);
        nc--; // Restaurez numarul de clase
    }
}

int main()
{
    cout << "n= "; cin >> n;
    GenPartitie(1);
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
