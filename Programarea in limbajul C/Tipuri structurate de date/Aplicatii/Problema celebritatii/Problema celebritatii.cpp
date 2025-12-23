// Problema celebritatii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[100][100], n, i, j, in, out, p, celebritate = -1;
    cout << "n="; cin >> n;
    cout << "Introduceti matricea relatiilor!\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) cin >> a[i][j];
    for (celebritate = 0, i = 1; i < n; i++)
        if (a[celebritate][i]) celebritate = i;
    for (out = in = i = 0; i < n; i++)
        in += a[i][celebritate], out += a[celebritate][i];
    if (celebritate < 0) cout << "In grup nu exista celebritati!\n";
    else cout << ++celebritate << " este o celebritate.\n";
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
