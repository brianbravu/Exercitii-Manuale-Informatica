// Accesarea elementului de la varf.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define DimMax 100 // Numarul maxim de elemente din stiva

typedef int Stiva[DimMax]; // Tipul Stiva implementat ca ector
Stiva S; // Stiva
int vf; // Varful stivei
int main()
{
    int x;
    cout << "x="; cin >> x;
    vf = -1;
    if (vf == DimMax - 1) // Stiva este plina
        cout << "Eroare - stiva este plina!\n";
    else // Inseram elementul x in stiva S
        S[++vf] = x;
    if (vf < 0) // Stiva este vida
        cout << "Eroare - stiva este vida!\n";
    else // Extragem elementul de la varf
        x = S[vf--];
    x = S[vf];
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
