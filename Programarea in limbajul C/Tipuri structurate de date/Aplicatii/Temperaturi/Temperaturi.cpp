// Temperaturi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMax 31

int main()
{
    int T[NMax], nrp, nrs = 0, i;
    cout << "Introduceti temperaturile: ";
    for (i = 0; i < 31; i++) cin >> T[i];
    nrp = T[0] > 0 ? 1 : 0;
    for (i = 1; i < 31; i++)
    {
        if (T[i] > 0) nrp++;
        if (T[i - 1] * T[i] < 0) nrs++;
    }
    cout << "Numarul de zile cu temperaturi pozitive este " << nrp << '\n';
    cout << "Numarul de schimbari de semn este " << nrs << '\n';
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
