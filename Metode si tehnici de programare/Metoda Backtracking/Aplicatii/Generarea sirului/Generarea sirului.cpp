// Generarea sirului.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 11

int s[NMax];
int n, lg;
long nrsol;
ofstream fout("sir.out");
void Afisare();

void Gen(int k)
{
    // Cand apelam Gen(k), am fixat in sir k valori
    if (k == lg) // Sirul este complet
        Afisare();
    else
    {
        if (s[k - 1] > 1 && s[k - 1] - 1 >= n - lg + 1 + k)
        {
            s[k] = s[k - 1] - 1;
            Gen(k + 1);
        }
        if (s[k - 1] + 1 <= n + lg - 1 - k)
        {
            s[k] = s[k - 1] + 1;
            Gen(k + 1);
        }
    }
}

int main()
{
    cout << "n, lg="; cin >> n >> lg;
    s[0] = n;
    Gen(1);
    if (!nrsol) fout << "Nu exista solutii\n";
    fout.close();
}

void Afisare()
{
    int i;
    if (s[lg - 1] == n)
    {
        nrsol++;
        for (i = 0; i < lg; i++) fout << s[i] << ' ';
        fout << endl;
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
