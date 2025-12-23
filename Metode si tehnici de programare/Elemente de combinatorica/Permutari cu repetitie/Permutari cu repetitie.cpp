// Permutari cu repetitie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 20

int n, m[NMax], s[NMax], uz[NMax], p; // uz[i] = numarul curent de aparitii ale valorii i in sirul s
ofstream fout("permrep.out");

void gen(int k) // Cand apelam gen(k), am fixat elementele s[1], ..., s[k-1]
{
    int i;
    if (k == p + 1) // Solutia este completa
    {
        for (i = 1; i <= n; i++)
            fout << s[i] << ' ';
        fout << endl;
    }
    else // Continuam generarea
        for (i = 1; i <= n; i++)
            if (uz[i] < m[i]) // Numarul curent de aparitii ale valorii i este mai mic decat multiplicitatealui i
            {
                s[k] = i;
                uz[i]++;
                gen(k + 1);
                uz[i]--;
            }
}

int main()
{
    int i;
    cout << "n="; cin >> n;
    cout << "Multiplicitatile: ";
    for (i = 1; i <= n; i++)
    {
        cin >> m[i]; p += m[i];
    }
    gen(1);
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
