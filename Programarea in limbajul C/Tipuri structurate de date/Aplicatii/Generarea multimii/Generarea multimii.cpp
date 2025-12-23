// Generarea multimii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, poz2, poz3, A[1000], i, min;
    cout << "n="; cin >> n;
    A[0] = 1; poz2 = poz3 = 0;
    for (i = 1; i < n; i++)
    {
        min = 2 * A[poz2] + 1;
        if (min > 3 * A[poz3] + 1) min = 3 * A[poz3] + 1;
        A[i] = min;
        if (min == 2 * A[poz2] + 1) poz2++;
        if (min == 3 * A[poz3] + 1) poz3++;
    }
    for (i = 0; i < n; i++) cout << A[i] << ' '; cout << '\n';
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
