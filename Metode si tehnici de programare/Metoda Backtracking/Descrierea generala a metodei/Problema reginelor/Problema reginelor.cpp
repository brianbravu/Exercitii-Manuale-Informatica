// Problema reginelor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;

int n, NrSol, C[30];

void Plaseaza_Regina(int);

int main()
{
    cout << "n= "; cin >> n;
    Plaseaza_Regina(0);
}

void Afisare()
{
    int i, j;
    cout << "Solutia nr. " << ++NrSol << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (j == C[i]) cout << " * ";
            else cout << " o ";
        cout << endl;
    }
    cout << endl; i = _getch();
}

void Plaseaza_Regina(int k)
{
    // cand apelam functia Plaseaza_Regina cu parametrul k,
    // am plasat deja regine pe liniile 0, 1, ..., k-1
    int i, j, ok;
    if (k == n) // am obtinut o solutie
        Afisare(); // prelucrarea soutiei consta in afisare
    else // trebuie sa mai plasam regine pe liniile k, k+1, ..., n-1
        for (i = 0; i < n; i++) // verific daca pot plasa regina de pe linia k in coloana i
        {
            for (ok = 1, j = 0; j < k; j++)
                if (C[j] == i || abs(C[j] - i) == (k - j)) ok = 0;
            // regina s-ar gasi pe aceeasi coloana sau aceeasi diagonala
            // cu o regina deja plasata
            if (ok) // valoarea i respecta conditiile interne
            {
                C[k] = i; // i este un candidat, il extrag imediat
                Plaseaza_Regina(k + 1);
            }
        }
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
