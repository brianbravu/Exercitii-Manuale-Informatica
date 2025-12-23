// Dreptunghi de suma maxima.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int sum[100][100];
int main()
{
    int n, m, a[100][100], i, j, x1, y1, x2, y2;
    int smax, x1max, y1max, x2max, y2max, s;
    cout << "n, m = "; cin >> n >> m;
    cout << "Introduceti elementele matricei, linie cu linie\n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) cin >> a[i][j];
    smax = a[0][0]; x1max = x2max = y1max = y2max = 0;
    for (x1 = 1; x1 <= n; x1++)
        for (y1 = 1; y1 <= m; y1++)
            // Calculez suma elementelor din dreptunghiul 
                    // cu coltul stanga-sus (0, 0) 
                    // si coltul dreapta-jos (x1, y1)
            for (i = 1; i <= x1; i++)
                for (j = 1; j <= y1; j++) sum[x1][y1] += a[i][j];
    for (x1 = 1; x1 <= n; x1++)
        for (y1 = 1; y1 <= m; y1++)
            for (x2 = x1; x2 <= n; x2++)
                for (y2 = y1; y2 <= m; y2++)
                {
                    // Calculez suma elementelor din dreptunghiul 
                    // cu coltul stanga-sus (x1, y1) 
                    // si coltul dreapta-jos (x2, y2)
                    s = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
                    if (s > smax)
                    {
                        smax = s; // Retin suma maxima
                        x1max = x1; y1max = y1; // si colturile
                        x2max = x2; y2max = y2;
                    }
                    else // Aceeasi suma dar arie mai mare?
                        if (s == smax && (x2 - x1 + 1) * (y2 - y1 + 1) > (x2max - x1max + 1) * (y2max - y1max + 1))
                        {
                            x1max = x1; y1max = y1; // Retin colturile
                            x2max = x2; y2max = y2;
                        }
                }
    cout << "Suma maxima: " << smax << '\n';
    cout << "Coltul stanga-sus: " << x1max << ", " << y1max << '\n';
    cout << "Coltul dreapta-jos: " << x2max << ", " << y2max << '\n';
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
