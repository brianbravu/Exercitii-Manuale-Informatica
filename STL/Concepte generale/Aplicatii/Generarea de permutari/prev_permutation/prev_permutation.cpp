// prev_permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define NMAX 50
int n;
int p[NMAX];

int main()
{
    int i;
    cout << "n="; cin >> n;
    for (i = 1; i <= n; i++) p[i] = n - i + 1;
    do
    {
        for (i = 1; i <= n; i++) cout << p[i] << ' ';
        cout << '\n';
    } while (prev_permutation(p + 1, p + n + 1));
    return 0;
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
