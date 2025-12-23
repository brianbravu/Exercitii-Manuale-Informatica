// Potrivire.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int p[1001];
long n, sn, S, D;

void inversez(int i, int j)
{
    int aux = p[i]; p[i] = p[j]; p[j] = aux;
}

int main()
{
    int i;
    cout << "n, S="; cin >> n >> S;
    // Construiesc permutarea identica
    for (i = 1; i <= n; i++) p[i] = i;
    if (S > n * (n + 1) * (2 * n + 1) / 6 || S < n * (n + 1) * (n + 2) / 6) // Nu exista solutie
    {
        cout << 0 << endl;
        return 0;
    }
    D = n * (n + 1) * (2 * n + 1) / 6 - S;
    sn = n;
    while (n > 4)
    {
        if (n * (n - 1) / 2 <= D)
        {
            D -= n * (n - 1) / 2;
            for (i = 1; i <= n; i++) inversez(i, i + 1);
        }
        n--;
    }
    switch (D)
    {
    case 1: inversez(1, 2); break;
    case 2: inversez(1, 2); inversez(3, 4); break;
    case 3: inversez(1, 2); inversez(2, 3); break;
    case 4: inversez(1, 3); break;
    case 5: inversez(1, 3); inversez(3, 4); inversez(4, 2); break;
    case 6: inversez(1, 2); inversez(2, 3); inversez(3, 4); break;
    case 7: inversez(1, 2); inversez(2, 3); inversez(3, 4); inversez(1, 2); break;
    case 8: inversez(1, 3); inversez(2, 4); break;
    case 9: inversez(1, 4); break;
    case 10: inversez(1, 4); inversez(2, 3); break;
    default:
        break;
    }
    for (i = 1; i <= sn; i++) cout << p[i] << ' '; cout << endl;
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
