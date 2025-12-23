// Codul Gray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 10
#define NrMaxS (1<<NMax)

int n, C[NrMaxS][NMax];

void Afisare();
void GenerareCod(int);

int main()
{
    cout << "n= "; cin >> n;
    GenerareCod(n);
    Afisare();
}

void Afisare()
{
    ofstream g("Gray.out");
    for (int i = 0; i < 1 << n; i++) // 1 << n este 2 la puterea n
    {
        for (int j = 0; j < n; j++) g << C[i][j];
        g << endl;
    }
    g.close();
}

void GenerareCod(int x)
{
    if (x == 1) C[1][0] = 1;
    else
    {
        GenerareCod(x - 1);
        for (int i = (1 << (x - 1)) - 1; i >= 0; i--) // oglindim C(x-1) si completam cu 1 coloana x-1
        {
            for (int j = 0; j < x - 1; j++) C[(1 << x) - i - 1][j] = C[i][j];
            C[(1 << x) - i - 1][x - 1] = 1;
        }
    }
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
