// Plata unei sume cu monede de valori date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define NrMaxMonede 20

unsigned V[NrMaxMonede], M[NrMaxMonede], P[NrMaxMonede];
unsigned n, S, Sum, NrSol;
ofstream fout("suma.out");

void Citire()
{
    // Citesc datele de intrare din fisierul suma.in
    ifstream fin("suma.in");
    fin >> n >> S;
    for (int i = 0; i < n; i++) fin >> V[i] >> M[i];
    fin.close();
}

void Afisare()
{
    // Afisez o solutie in fisierul de iesire
    fout << "Solutia nr. " << ++NrSol << endl;
    for (int i = 0; i < n; i++)
        if (P[i])
            fout << P[i] << " monede cu valoarea " << V[i] << endl;
}

void Plata(int k)
{
    // Cand apelam Plata(k) am selectat deja monede din saculetii 0, 1, ..., k-1
    if (k == n) // Am selectat monede de toate tipurile
        if (Sum == S) // Valoarea monedelor selectate e egala cu S
            Afisare();
        else;
    else // Mai selectam monede din saculetii k, k+1, ..., n-1
        for (int j = 0; j <= M[k] && Sum + j * V[k] <= S; j++)
        {
            P[k] = j; // Selectez j monede din saculetul k
            Sum += j * V[k]; // Adaug valoarea monedelor selectate din saculetul k la valoarea totala a monedelor selectate memorara in Sum
            Plata(k + 1); // Apel recursiv
            Sum -= j * V[k]; // Restaurez dupa apel valoarea variabilei globale Sum
        }
}

int main()
{
    Citire();
    Plata(0);
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
