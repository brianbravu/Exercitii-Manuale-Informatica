// Generarea combinarilor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int n, m, c[40];
ofstream fout("comb.out"); // Fisierul de iesire

void Afisare()
{
    for (int i = 1; i <= m; i++) fout << c[i] << ' ';
    fout << endl;
}

void GenCombinari(int k) // Cand apelam functia GenCombinari cu parametrul k pozitiile 1, 2, ..., k-1 din vectorul c sunt fixate
{
    if (k - 1 == m) // Solutia este completa
        Afisare(); // Prelucrarea solutiei consta in afisare
    else // Continuam generarea
        for (int i = c[k - 1] + 1; i <= n - m + k; i++) // Determin candidatii pentru pozitia k
        {
            c[k] = i; // i este un candidat, deoarece nu este imaginea nici unuia alt element fixat
            GenCombinari(k + 1); //Apel recursiv
        }
}

int main()
{
    cout << "n= "; cin >> n; cout << "m= "; cin >> m;
    GenCombinari(1);
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
