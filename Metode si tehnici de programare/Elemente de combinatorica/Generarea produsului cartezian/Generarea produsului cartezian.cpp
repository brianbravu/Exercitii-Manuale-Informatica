// Generarea produsului cartezian.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define DMax 20
int n, L[DMax], E[DMax];
ofstream fout("pc.out"); // Fisierul de iesire

void citire(void);
void generare(int);
void afisare(void);

int main()
{
    citire();
    generare(1);
    fout.close();
}

void generare(int k) // Cand apelam generare(k) pozitiile 1, 2, ..., k-1 deja sunt ocupate
{
    int j;
    if (k == n + 1) // Am obtinut o solutie, o afisam
        afisare();
    else for (j = 1; j <= L[k]; j++)
    {
        E[k] = j; // Plasam pozitia j pe pozitia k
        generare(k + 1); // Generam in continuare
    }
}

void afisare(void)
{
    int i;
    for (i = 1; i <= n; i++) fout << E[i] << ' ';
    fout << endl;
}

void citire(void)
{
    ifstream fin("pc.in");
    fin >> n;
    for (int i = 1; i <= n; i++) fin >> L[i];
    fin.close();
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
