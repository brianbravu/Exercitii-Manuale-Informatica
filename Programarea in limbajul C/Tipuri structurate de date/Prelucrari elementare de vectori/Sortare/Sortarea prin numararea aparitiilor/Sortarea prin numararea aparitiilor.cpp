// Sortarea prin numararea aparitiilor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define Max 1000
#define NrMax 10000

int n, V[Max], a[NrMax];
int main()
{
    int x, i, j, nr;
    cout << "n="; cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x; // Citesc o noua valoare
        V[x]++; // Marim numarul de aparitii ale valorii x
    }
    // Plasam in ordine elementele in vectorul a
    for (nr = i = 0; i < Max; i++)
        for (j = 0; j < V[i]; j++)
            a[nr++] = i;
    for (i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
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
