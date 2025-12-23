// Expresii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

unsigned long f[38][19];
int n, d;

unsigned long nr(int n, int d)
{
    int i, j, n1, d1, k;
    unsigned long s;
    f[0][0] = 1;
    for (i = 2; i <= n; i += 2)
        for (j = i / 2; j > 0; j--)
        {
            f[i][j] = f[i - 2][j - 1];
            for (n1 = i - 2; n1 >= 2; n1 -= 2)
            {
                s = 0;
                for (k = 0; k <= j; k++) s += f[i - n1][k];
                f[i][j] += s * f[n1 - 2][j - 1];
                for (d1 = j - 1; d1 > 0; d1--)
                    f[i][j] += f[n1 - 2][d1 - 1] * f[i - n1][j];
            }
        }
    return f[n][d];
}

int main()
{
    cout << "n, d= "; cin >> n >> d;
    cout << nr(n, d) << endl;
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
