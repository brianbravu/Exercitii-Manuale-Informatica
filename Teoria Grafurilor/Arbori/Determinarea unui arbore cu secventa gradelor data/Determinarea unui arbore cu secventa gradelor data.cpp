// Determinarea unui arbore cu secventa gradelor data.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 101
ifstream fin("graf.in");
ofstream fout("graf.out");
int n;
int d[NMax], a[NMax];

int main()
{
    fin >> n;
    for (int i = 1; i <= n; i++) fin >> d[i];
    int s = 0, i, VfT, VfNt;
    for (i = 1; i <= n; i++) s += d[i];
    if (s != 2 * (n - 1))
        fout << "Suma gradelor trebuie sa fie 2*(n-1)!\n";
    else 
        for (VfT = 1; VfT < n; VfT++)
        {
            // Determin primul varf neterminal
            for (VfNt = VfT + 1; VfNt < n && d[VfNt] == 1; VfNt++);
            a[VfT] = VfNt;
            d[VfNt]--;
        }
    for (i = 1; i < n; i++) fout << a[i] << " ";
    fout << "\n";
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
