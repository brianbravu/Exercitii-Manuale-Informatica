// Cautarea unui element intr-un vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, x, st, dr, gasit, mijloc;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    cin >> x;
    for (st = 0, dr = n - 1, gasit = 0; !gasit && st <= dr;) // Cautam pe x de la pozitia st la pozitia dr. Cautarea continua pana gasim sau pana nu mai avem unde cauta
    {
        mijloc = (st + dr) / 2; // Calculam mijlocul
        if (a[mijloc] == x) gasit = 1; // Am gasit pe x
        else if (a[mijloc] < x) st = mijloc + 1; // Caut in stanga
        else dr = mijloc - 1; // Caut in dreapta
    }
    if (gasit) cout << x << " se gaseste pe pozitia " << mijloc;
    else cout << x << " nu se afla in vector";
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
