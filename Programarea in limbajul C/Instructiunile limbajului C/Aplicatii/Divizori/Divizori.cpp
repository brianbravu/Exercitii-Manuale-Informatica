// Divizori.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, d;
    cin >> n;
    cout << 1 << ' ';
    if (n > 1)
    {
        d = 2; // Caut divizorii de la 2 la sqrt(n) (exclusiv)
        while (d * d < n)
        {
            if (n % d == 0) cout << d << ' ' << n / d << ' ';
            d++;
        }
        if (d * d == n) cout << d << ' '; // Cazul n patrat perfect
        cout << n << '\n';
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
