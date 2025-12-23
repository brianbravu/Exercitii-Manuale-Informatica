// Regula de compresie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
int tata[NMax], h[NMax];

int Find(int x)
{
    while (tata[x])
        x = tata[x];
    return x;
}

void Union(int i, int j)
{
    tata[i] = j;
}

void Union_ponderare(int x, int y)
{
    if (h[x] > h[y]) tata[y] = x;
    else
    {
        tata[x] = y;
        if (h[x] == h[y]) h[y]++;
    }
}

int Find_compresie(int x)
{
    int r = x; // Determinam radacina arborelui
    while (tata[r]) r = tata[r];
    int y = x; // Comprimam drumul de la x la radacina
    while (y != r)
    {
        int t = tata[y];
        tata[y] = r;
        y = t;
    }
    return r;
}

int main()
{
    std::cout << "Hello World!\n";
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
