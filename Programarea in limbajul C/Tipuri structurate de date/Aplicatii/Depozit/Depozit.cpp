// Depozit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int SR[100], n, i, j, k, c;
    cout << "n="; cin >> n;
    SR[0] = 0; // Calculez sumele de la citire
    for (i = 1; i <= n; i++)
    {
        cout << 'C' << i << '=';
        cin >> c;
        SR[i] = SR[i - 1] + c;
    }
    for (i = 1; i <= n; i++) SR[i] %= n; // Calculez resturile
    cout << "Solutia este " << '\n';
    for (i = 1; i <= n; i++) // Caut un rest egal cu 0
        if (!SR[i])
        {
            for (k = 1; k <= i; k++) cout << k << ' ';
            return 0;
        }
    // Cazul II
    for (i = 1; i < n; i++) // Caut doua resturi egale
        for (j = i + 1; j <= n; j++)
            if (SR[i] == SR[j])
            {
                for (k = i + 1; k <= j; k++) cout << k << ' ';
                return 0;
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
