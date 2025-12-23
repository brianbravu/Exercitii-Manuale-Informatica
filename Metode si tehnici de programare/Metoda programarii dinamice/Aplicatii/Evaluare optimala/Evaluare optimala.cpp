// Evaluare optimala.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define NMax 101

ofstream fout("eval.out");

int n, p;
int x[NMax];
int op[NMax][NMax], c[NMax][NMax];
int M[NMax][NMax], rez[NMax][NMax];

void Citire();
void Rezolvare();
void Afisare(int,int);

int main()
{
    Citire();
    Rezolvare();
    Afisare(1, p);
    fout.close();
}

void Citire()
{
    ifstream fin("eval.in");
    int i, j;
    fin >> n >> p;
    for (i = 1; i <= p; i++) fin >> x[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) fin >> op[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) fin >> c[i][j];
    fin.close();
}

void Rezolvare()
{
    int nr, i, j, k, kmin, min, Infinit = 10000;
    for (i = 1; i <= p; i++) rez[i][i] = x[i];
    for (nr = 2; nr <= p; nr++) // nr = numarul de valori din secventa
        for (i = 1; i <= p - nr + 1; i++) // i - inceputul secventei de nr valori
        {
            j = i + nr - 1; // j - sfarsitul secventei de nr valori
            for (k = i, min = Infinit; k < j; k++) // Determin minimul si pozitia sa
                if (min > M[i][k] + M[k + 1][j] + c[rez[i][k]][rez[k + 1][j]])
                {
                    min = M[i][k] + M[k + 1][j] + c[rez[i][k]][rez[k + 1][j]];
                    kmin = k;
                }
            M[i][j] = min; M[j][i] = kmin;
            rez[i][j] = op[rez[i][kmin]][rez[kmin + 1][j]];
        }
}

void Afisare(int i, int j) // Afiseaza parantezarea optimala a expresiei xi...xj
{
    if (i == M[j][i]) fout << x[i];
    else
    {
        fout << "("; Afisare(i, M[j][i]); fout << ")";
    }
    fout << "o";
    if (j == M[j][i] + 1) fout << x[j];
    else
    {
        fout << "("; Afisare(M[j][i] + 1, j); fout << ")";
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
