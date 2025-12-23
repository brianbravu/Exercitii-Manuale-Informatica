// Pietre.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define NMax 1001

ofstream fout("pietre.out");

int n;
int a[NMax];
int l[NMax], poz[NMax];

void citire();
void relatia_de_recurenta();
void solutia_optima();

int main()
{
    citire();
    relatia_de_recurenta();
    solutia_optima();
    fout.close();
}

void citire()
{
    ifstream fin("pietre.in");
    int i;
    fin >> n;
    for (i = 1; i <= n; i++) fin >> a[i];
    fin.close();
}

void relatia_de_recurenta()
{
    int i, j;
    l[n] = 1; poz[n] = -1;
    for (i = n - 1; i > 0; i--)
        for (l[i] = 1, poz[i] = -1, j = i + 1; j <= n; j++)
            if (a[i] <= a[j] && l[i] < 1 + l[j])
            {
                l[i] = 1 + l[j]; poz[i] = j;
            }
}

void solutia_optima() // Determin maximul din vectorul l
{
    int i, max = l[1], pozmax = 1;
    for (i = 2; i <= n; i++)
        if (max < l[i])
        {
            max = l[i];
            pozmax = i;
        }
    fout << "Lungimea celui mai lung subsir crescator: " << max;
    fout << "\nCel mai lung subsir:\n";
    for (i = pozmax; i != -1; i = poz[i]) fout << a[i] << ' ';
    fout << endl;
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
