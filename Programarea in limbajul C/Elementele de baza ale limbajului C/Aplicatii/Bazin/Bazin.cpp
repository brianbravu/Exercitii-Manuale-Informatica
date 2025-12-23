// Bazin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int x, y, h1, h2, b;
    cout << "h1="; cin >> h1;
    cout << "h2="; cin >> h2;
    cout << "x="; cin >> x;
    cout << "y="; cin >> y;
    cout << "b=" << (b = (x - h1 * (y - x)) / (h2 + h1)) << ' ';
    cout << "a=" << (y - x) + b << '\n';
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
