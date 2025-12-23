// Canguri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMAX 500
int n;
int Lg[NMAX];
int main()
{
    int i, a, b, rest, salt_max;
    long long int M, LgMin;
    cin >> n;
    for (i = 0; i < n; i++) cin >> Lg[i];
    M = salt_max = Lg[0];
    for (i = 1; i < n; i++)
    {
        if (salt_max < Lg[i]) salt_max = Lg[i];
        // Calculez cmmmc(M, Lg[i])
        a = M; b = Lg[i]; // Calculez cmmdc(a, b)
        while (b)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
        M = (M * Lg[i]) / a;
    }
    LgMin = M;
    while (LgMin / salt_max < 3) LgMin += M;
    cout << LgMin << '\n';
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
