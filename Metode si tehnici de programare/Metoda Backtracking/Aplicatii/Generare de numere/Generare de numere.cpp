// Generare de numere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int c[10];
int n, lg;
unsigned long x;
ofstream fout("sir.out");
void Determina_Cifre(int);

void Gen(int k)
{
    // Cand apelam Gen(k), am fixat in numar k cifre
    int i;
    if (k == lg) // Numarul este complet
        fout << x << endl;
    else for (i = 0; i < 10; i++)
        if (c[i]) // Cifra i apare in n?
        {
            x = x * 10 + i; // Adaug la sfarsitul lui x cifra i
            Gen(k + 1); // Generez in continuare
            x /= 10; // Sterg cifra adaugata
        }
}

int main()
{
    cout << "n, lg="; cin >> n >> lg;
    Determina_Cifre(n);
    Gen(0);
    fout.close();
}

void Determina_Cifre(int x)
{
    do
    {
        c[x % 10] = 1;
        x /= 10;
    } while (x);
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
