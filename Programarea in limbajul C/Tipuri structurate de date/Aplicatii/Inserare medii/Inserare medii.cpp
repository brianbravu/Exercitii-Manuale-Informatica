// Inserare medii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    float a[100];
    int n, i, j;
    cout << "n="; cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "a[" << i << "]=";
        cin >> a[2 * i];
    }
    for (i = 1; i < n; i++)
        a[2 * i - 1] = (a[2 * i] + a[2 * i - 2]) / 2;
    for (i = 0; i < 2 * n - 1; i++) cout << a[i] << ' ';
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
