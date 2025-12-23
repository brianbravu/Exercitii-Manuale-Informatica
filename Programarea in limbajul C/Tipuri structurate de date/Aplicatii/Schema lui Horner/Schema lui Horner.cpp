// Schema lui Horner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    float P[100], a;
    int n, i;
    cout << "n="; cin >> n; // Citire
    for (i = 0; i <= n; i++)
    {
        cout << 'P' << i << '=';
        cin >> P[i];
    }
    cout << "a="; cin >> a;
    for (i = 1; i <= n; i++) // Aplic schema lui Horner
        P[i] = P[i - 1] * a + P[i];
    cout << "Coeficientii catului sunt "; // Afisare
    for (i = 0; i < n; i++) cout << P[i] << ' ';
    cout << "\nRestul este " << P[n] << '\n';
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
