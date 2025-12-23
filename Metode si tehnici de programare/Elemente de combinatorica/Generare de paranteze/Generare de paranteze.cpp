// Generare de paranteze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 20

char s[NMax];
int N;
int ND; // ND - numarul total de paranteze deschise
int NI; // NI - numarul total de paranteze inchise
ofstream fout("sir.out");

void Constructie(int k) // Cand apelam Constructie(k), am fixat in sir k paranteze
{
    if (k == N) // Sirul de paranteze este complet
        fout << s << endl;
    else
    {
        if (ND < N / 2) // Se mai pot deschide paranteze
        {
            s[k] = '('; ND++;
            Constructie(k + 1);
            ND--;
        }
        if (NI < ND) // Se poate inchide o paranteza
        {
            s[k] = ')'; NI++;
            Constructie(k + 1);
            NI--;
        }
    }
}

int main()
{
    cout << "N= "; cin >> N;
    Constructie(0);
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
