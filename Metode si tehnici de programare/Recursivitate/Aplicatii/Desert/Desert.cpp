// Desert.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define InFile "desert.in"
#define OutFile "desert.out"

int n, k;
long double p;

long double dist(int n)
{
    if (n <= 2) return k * n / p;
    return k / ((2 * n - 3) * p) + dist(n - 1);
}

int main()
{
    FILE* fin, * fout;
    long double d;
    errno_t err = fopen_s(&fin, InFile, "rt");
    fscanf_s(fin, "%d %d %Lf", &n, &k, &p);
    fclose(fin);
    p = p / 100;
    d = dist(n);
    err = fopen_s(&fout, OutFile, "wt");
    fprintf_s(fout, "%.3Lf\n", d);
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
