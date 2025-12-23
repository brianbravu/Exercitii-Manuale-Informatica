// Excursie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    long int n, Start, x, i;
    cin >> n;
    if (n < 5 || (n * (n + 1)) % 3)
    {
        cout << "Nu exista solutie";
        return 0;
    }
    if (!((n - 9) % 6))
    {
        Start = 10;
        x = (n - 9) / 6;
    }
    if (!((n - 8) % 6))
    {
        Start = 9;
        x = (n - 8) / 6;
    }
    if (!((n - 6) % 6))
    {
        Start = 7;
        x = (n - 6) / 6;
    }
    if (!((n - 5) % 6))
    {
        Start = 6;
        x = (n - 5) / 6;
    }
    switch (Start) // Masina 1
    {
    case 10:
        cout << "1 2 3 4 5 ";
        break;
    case 9:
        cout << "1 2 3 6 ";
        break;
    case 7:
        cout << "3 4 ";
        break;
    case 6:
        cout << 5 << ' ';
        break;
    default:
        break;
    }
    for (i = 0; i < x; i++) cout << Start + 6 * i << ' ' << Start + 5 + 6 * i << ' ';
    cout << '\n';
    switch (Start) // Masina 2
    {
    case 10:
        cout << 7 << ' ' << 8 << ' ';
        break;
    case 9:
        cout << 5 << ' ' << 7 << ' ';
        break;
    case 7:
        cout << 2 << ' ' << 5 << ' ';
        break;
    case 6:
        cout << 2 << ' ' << 3 << ' ';
        break;
    default:
        break;
    }
    for (i = 0; i < x; i++) cout << Start + 1 + 6 * i << ' ' << Start + 4 + 6 * i << ' ';
    cout << '\n';
    switch (Start) // Masina 3
    {
    case 10:
        cout << 6 << ' ' << 9 << ' ';
        break;
    case 9:
        cout << 4 << ' ' << 8 << ' ';
        break;
    case 7:
        cout << 1 << ' ' << 6 << ' ';
        break;
    case 6:
        cout << 1 << ' ' << 4 << ' ';
        break;
    default:
        break;
    }
    for (i = 0; i < x; i++) cout << Start + 2 + 6 * i << ' ' << Start + 3 + 6 * i << ' ';
    cout << '\n';
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
