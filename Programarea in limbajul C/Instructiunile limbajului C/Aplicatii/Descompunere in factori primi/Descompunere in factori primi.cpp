// Descompunere in factori primi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, d = 2, p;
    cin >> n;
    while (d * d <= n)
    {
        p = 0; // Puterea lui d in descompunere
        while (n % d == 0)
        {
            n /= d;
            p++;
        }
        if (p) cout << d << ' ' << p << '\n';
        d++;
    }
    if (n > 1) cout << n << ' ' << 1 << '\n';
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
