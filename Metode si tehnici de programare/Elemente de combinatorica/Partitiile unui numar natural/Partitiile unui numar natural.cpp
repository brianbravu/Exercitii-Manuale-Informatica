// Partitiile unui numar natural.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int n, ValP, p[50];
ofstream fout("partnr.out");

void Afisare(int lg)
{
    fout << n << '=';
    for (int i = 1; i < lg; i++) fout << p[i] << " + ";
    fout << p[lg] << endl;
}

void ConstrPart(int k) // Cand apelam ConstrPart(k) am fixat p[1], p[2], ..., p[k-1]
{
    if (ValP == n) Afisare(k - 1); // Am obtinut o solutie
    else for (int i = p[k - 1]; i <= n - ValP; i++)
    {
        p[k] = i;
        ValP += i; // Maresc ValP cu valoarea noului element
        ConstrPart(k + 1); // Apel recursiv
        ValP -= i; // Restaurez valoarea variabilei ValP
    }
}

int main()
{
    cout << "n= "; cin >> n;
    p[0] = 1;
    ConstrPart(1);
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
