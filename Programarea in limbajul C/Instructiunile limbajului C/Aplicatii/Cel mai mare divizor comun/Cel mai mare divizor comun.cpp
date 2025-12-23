// Cel mai mare divizor comun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, m, rest;
    cin >> n >> m;
    if (n == 0 && m == 0) cout << "Nu exista solutie";
    else
    {
        while (m)
        {
            rest = n % m; // Calculez restul
            n = m; // Impartitorul devine deimpartit
            m = rest; // Restul devine impartitor
        }
        cout << "cmmdc=" << n; // Ultimul rest diferilt de 0
        cout << '\n';
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
