// Generarea permutarilor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int n, p[40], uz[40];
ofstream fout("perm.out"); // Fisierul de iesire

void Afisare()
{
    for (int i = 1; i <= n; i++) fout << p[i] << ' ';
    fout << endl;
}

void GenPermutari(int k) // Cand apelam functia GenPermutari cu parametrul k pozitiile 1, 2, ..., k-1 din vectorul p sunt fixate
{
    if (k - 1 == n) // Solutia este completa
        Afisare(); // Prelucrarea solutiei consta in afisare
    else // Continuam generarea
        for (int i = 1; i <= n; i++) // Determin candidatii pentru pozitia k
            if (!uz[i]) // Daca nu este utilizat deja in p
            {
                p[k] = i; uz[i] = 1; // i este un candidat, deoarece nu este imaginea nici unuia alt element fixat
                GenPermutari(k + 1); // Apel recursiv
                uz[i] = 0;
            }
}

int main()
{
    cout << "n= "; cin >> n;
    GenPermutari(1);
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
