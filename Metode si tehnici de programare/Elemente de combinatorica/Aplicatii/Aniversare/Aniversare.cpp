// Aniversare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

long int Nr1[100], Nr2[100];
int n, k;

int main()
{
    int i, j, sum;
    cout << "n, k= "; cin >> n >> k;
    Nr1[1] = 1;
    for (i = 4; i <= n; i++)
    {
        for (j = 1; j <= k; j++)
            Nr2[j] = Nr1[j] * 2 * j + Nr1[j - 1] * (i + 1 - 2 * j);
        for (j = 1; j <= k; j++) Nr1[j] = Nr2[j];
    }
    for (sum = Nr1[1], i = 2; i <= k; i++) sum += Nr1[i];
    cout << sum << endl;
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
