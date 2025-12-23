// Eliminare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMax 100

int main()
{
    char s[NMax], c;
    int n, i, j, k, schimb = 1;
    n = 0; // Numarul de litere din secventa
    do
    {
        cin >> c;
        if (c != '.') s[n++] = c;
    } while (c != '.');
    while (schimb)
    {
        for (schimb = i = 0; i < n - 1;)
            if (s[i] == s[i + 1])
                // Incepe o secventa de litere egale
            {
                // Determin sfarsitul acestei secvente
                for (j = i + 1; j < n && s[j] == s[i]; j++);
                // O elimin
                for (k = j; k < n; k++) s[i + k - j] = s[k];
                // Actualizez numarul de elemente din secventa
                n -= j - i;
                schimb = 1;
            }
            else i++; // Trec mai departe
    }
    for (i = 0; i < n; i++) cout << s[i];
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
