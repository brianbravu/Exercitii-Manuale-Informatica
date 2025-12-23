// Comis-voiajor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#define NMaxOrase 20

float A[NMaxOrase][NMaxOrase];
int n;
int T[NMaxOrase], TMin[NMaxOrase], v[NMaxOrase];
float Lg, LgMin, Inf;

void Citire()
{
    ifstream f("comis.in");
    int i, j;
    float d;
    f >> n;
    while (!f.eof())
    {
        // De pe fiecare linie citesc doua orase intre care exista legatura directa, precum si distanta dintre ele
        f >> i >> j >> d;
        A[i][j] = A[j][i] = d;
    }
    f.close();
}

float Infinit() // Intoarce un numar suficient de mare
{
    float s = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) s += A[i][j];
    return s + 1;
}

void Afisare()
{
    if (LgMin == Inf) cout << "Nu exista solutii\n";
    else
    {
        cout << "Traseul cel mai scurt are lungimea ";
        cout << setprecision(10) << LgMin << endl;
        cout << "Traseul este ";
        for (int i = 1; i <= n; i++) cout << TMin[i] << ',';
        cout << TMin[1] << endl;
    }
}

void ConstrTraseu(int k)
{
    // Cand apelam ConstrTraseu(k), sunt fixate pe traseu orasele T[1], T[2], ..., T[k-1]
    if (k - 1 == n) // Traseul este complet
        if (A[1][T[n]]) // Poate reveni in orasul 1
            if (Lg + A[1][T[n]] < LgMin)
            {
                for (int i = 1; i <= n; i++) TMin[i] = T[i];
                LgMin = Lg + A[1][T[n]];
            }
            else;
        else;
    else // Construiesc in continuare traseul
        for (int i = 2; i <= n; i++) // Verific daca se poate deplasa in orasul 1
            if (A[i][T[k - 1]] && !v[i])
            {
                T[k] = i; v[i] = 1; Lg += A[i][T[k - 1]];
                if (Lg <= LgMin) ConstrTraseu(k + 1);
                v[i] = 0; Lg -= A[i][T[k - 1]];
            }
}

int main()
{
    Citire();
    T[1] = v[1] = 1; LgMin = Inf = Infinit();
    ConstrTraseu(2);
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
