// Problema plierilor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMax 50

int n, efinal[NMax]; // efinal[i] este 1 daca si numai dacai e element final
char m[NMax][50]; // m[i] = codificarea plierilor care ne duc la elementul i

void Pliaza(int p, int q)
{
    // pliaza un vector cu componentele numerotate de la p la q
    int Ls, Ld, i; // Ls, Ld - pozitiile de pliere spre stanga, respectiv dreapta
    char ss[50], sd[50], aux[50]; // ss, sd - sirurile care se obtin din pozitiile de pliere
    if (p == q) efinal[p] = 1; // vectorul contine un singur element
    else
    {
        if ((q - p + 1) % 2) // vectorul are numar impar de elemente
            Ls = (p + q) / 2 - 1;
        else Ls = (p + q) / 2;
        Ld = (p + q) / 2 + 1;
        Pliaza(p, Ls); // pliez prima jumatate
        _itoa_s(Ls, ss, 10); _itoa_s(Ld, sd, 10);
        // elementele finale din prima jumatate se obtin
        // printr-o pliere prealabila la stanga
        for (i = p; i <= Ls; i++)
        {
            strcpy_s(aux, "S"); strcat_s(aux, ss); strcat_s(aux, " ");
            strcat_s(aux, m[i]); strcpy_s(m[i], aux);
        }
        Pliaza(Ld, q);
        // elementele din cea de a doua jumatate se obtin
        // printr-o pliere prealabila la dreapta
        for (i = Ld; i <= q; i++)
        {
            strcpy_s(aux, "D"); strcat_s(aux, sd); strcat_s(aux, " ");
            strcat_s(aux, m[i]); strcpy_s(m[i], aux);
        }
    }
}

int main()
{
    cout << "n= "; cin >> n;
    Pliaza(1, n);
    cout << "Elementele finale sunt:" << endl;
    for (int i = 1; i <= n; i++)
        if (efinal[i])
            cout << i << ": " << m[i] << endl;
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
