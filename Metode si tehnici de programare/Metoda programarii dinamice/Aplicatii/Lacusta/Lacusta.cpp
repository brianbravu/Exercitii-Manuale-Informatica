// Lacusta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define M 100

int main()
{
    FILE* fin, * fout;
    unsigned A[M][M], B[M][M], m, n, i, j, min1, min2, jmin;
    errno_t err = fopen_s(&fin, "lacusta.in", "rt");
    fscanf_s(fin, "%u %u", &m, &n);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            fscanf_s(fin, "%u", &A[i][j]);
    fclose(fin);
    B[1][0] = 32000; // Infinit
    for (i = 1; i <= n; i++) // Initializarea celei de-a doua linii
        B[1][i] = A[0][0] + A[0][i] + A[1][i];
    for (i = 1; i < m - 1; i++) // Calculez doua valori minime pe linia i
    {
        if (B[i][0] <= B[i][1])
        {
            min1 = B[i][0]; min2 = B[i][1]; jmin = 0;
        }
        else
        {
            min1 = B[i][1]; min2 = B[i][0]; jmin = 1;
        }
        for (j = 2; j < n; j++) // Parcurgem linia
            if (B[i][j] < min1)
            {
                min2 = min1; min1 = B[i][j]; jmin = j;
            }
            else if(B[i][j] < min2) min2 = B[i][j];
        for (j = 0; j < n; j++)
            if (j != jmin)
                B[i + 1][j] = min1 + A[i][j] + A[i + 1][j];
            else
                B[i + 1][j] = min2 + A[i][j] + A[i + 1][j];
    }
    min1 = B[m - 1][0];
    for (j = 1; j < n; j++)
        if (B[m - 1][j] < min1)
            min1 = B[m - 1][j];
    err = fopen_s(&fout, "lacusta.out", "wt");
    fprintf_s(fout, "%u\n", min1 + A[m - 1][n - 1]);
    fclose(fout);
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
