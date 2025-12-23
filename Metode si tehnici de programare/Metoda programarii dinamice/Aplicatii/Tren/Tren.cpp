// Tren.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define Dim 50000
#define k 3
#define in_file "tren.in"
#define out_file "tren.out"

int s[Dim + 1][4];
int v[Dim + 1]; // v[i] = numarul de pasageri din vagonul i
int sum[Dim + 1]; // sum[i] = v[1] + v[2] + ... + v[i]
int M, n;

int main(void)
{
    int i, j;
    FILE* fin;
    errno_t err = fopen_s(&fin, in_file, "rt");
    FILE* fout;
    err = fopen_s(&fout, out_file, "wt");
    fscanf_s(fin, "%d", &n);
    for (i = 1; i <= n; i++)
    {
        fscanf_s(fin, "%d", &v[i]);
        sum[i] = sum[i - 1] + v[i];
    }
    fscanf_s(fin, "%d", &M);
    for (i = 1; i <= M; i++)
        for (j = 1; j <= k; j++) s[i][j] = sum[i];
    for (i = M + 1; i <= n; i++)
        for (j = 1; j <= k; j++)
        {
            s[i][j] = s[i - 1][j];
            if (s[i][j] < s[i - M][j - 1] + (sum[i] - sum[i - M]))
                s[i][j] = s[i - M][j - 1] + (sum[i] - sum[i - M]);
        }
    fprintf_s(fout, "%d\n", s[n][k]);
    err = _fcloseall();
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
