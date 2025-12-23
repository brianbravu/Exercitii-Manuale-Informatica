// Domino.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NrMaxDomino 100

struct Piesa { int prim, ultim; } J[NrMaxDomino]; // Pentru fiecare piesa retin cele doua numere inscrise
int n, LgMax;
int L[NrMaxDomino], LMax[NrMaxDomino], Uz[NrMaxDomino];

void Citire()
{
    ifstream fin("domino.in");
    fin >> n;
    for (int i = 1; i <= n; i++) fin >> J[i].prim >> J[i].ultim;
    fin.close();
}

void Afisare()
{
    cout << "Cel mai lung lant este format din piesele ";
    for (int i = 1; i <= LgMax; i++)
        cout << LMax[i] << ' ';
}

void ConstrLant(int k)
{
    // Lantul contine k-1 piese de domino
    int Se_Poate = 0; // Incerc sa prelungesc lantul
    for (int i = 1; i <= n; i++)
        if (!Uz[i]) // Nu am mai utilizat piesa i
        {
            if (J[i].ultim == J[L[k - 1]].ultim)
            {
                // Intoarce piesa
                int aux = J[i].prim;
                J[i].prim = J[i].ultim; J[i].ultim = aux;
            }
            if (J[i].prim == J[L[k - 1]].ultim)
            {
                // Piesa i "se lipeste"
                L[k] = i; Uz[i] = 1; Se_Poate = 1;
                ConstrLant(k + 1);
                Uz[i] = 0;
            }
        }
    if (!Se_Poate) // Am obtinut o solutie maximala
        if (k - 1 > LgMax) // Compar lantul curent cu cel maxim
        {
            LgMax = k - 1;
            for (int i = 1; i <= LgMax; i++) LMax[i] = L[i];
        }
}

int main()
{
    Citire();
    for (int i = 1; i <= n; i++)
    {
        // Pot incepe lantul cu orice piesa
        L[1] = i; Uz[i] = 1;
        ConstrLant(2);
        Uz[i] = 0;
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
