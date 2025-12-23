// Sortare prin selectie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, dr, max, pozmax;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    for (dr = n - 1; dr > 0; dr--) // Calculez maximul de la 0 la dr
    {
        for (max = a[0], pozmax = 0, i = 1; i <= dr; i++)
            if (a[i] > max) max = i, pozmax = i;
        a[pozmax] = a[dr]; // Plasez maximul pe pozitia dr
        a[dr] = max;
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
