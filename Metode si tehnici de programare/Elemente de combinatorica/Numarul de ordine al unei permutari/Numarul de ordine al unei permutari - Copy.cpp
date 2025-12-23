// Numarul de ordine al unei permutari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n, p[40];
long int fact[40];
long nr;

int main()
{
    int i, j;
    cout << "n= "; cin >> n;
    cout << "Permutarea: "; for (int i = 1; i <= n; i++) cin >> p[i];
    fact[1] = 1;
    for (i = 2; i <= n; i++) fact[i] = i * fact[i - 1];
    for (i = 1; i <= n; i++)
    {
        nr += (p[i] - 1) * fact[n - i];
        for (j = i + 1; j <= n; j++)
            if (p[j] > p[i]) p[j]--;
    }
    cout << nr << endl;
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
