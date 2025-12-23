// Pachete.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 100001
#define InFile "pachete.in"
#define OutFile "pachete.out"
#define max(x,y) ((x)>(y)?(x):(y))

int Inst[NMax], D[NMax], min[NMax];

int main(void)
{
    FILE* fin;
    errno_t err = fopen_s(&fin, InFile, "r");
    FILE* fout;
    err = fopen_s(&fout, OutFile, "w");
    int n, i;
    fscanf_s(fin, "%d", &n);
    for (i = 0; i < n; i++)
        fscanf_s(fin, "%d %d", &Inst[i], &D[i]);
    fclose(fin);
    min[n - 1] = D[n - 1];
    for (i = n - 2; i >= 0; i--)
        min[i] = D[i] + max(0, min[i + 1] - Inst[i]);
    fprintf_s(fout, "%d\n", min[0]);
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
