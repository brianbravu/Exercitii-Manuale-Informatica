// Cel mai mare divizor comun.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMax 20

unsigned a[NMax], n;

void Citire()
{
    ifstream fin("cmmdc.in");
    fin >> n;
    for (int i = 0; i < n; i++) fin >> a[i];
    fin.close();
}

unsigned Euclid(unsigned x, unsigned y)
{
    // calculeaza cmmdc(x,y) prin algoritmul lui Euclid
    unsigned r;
    while (y)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}

unsigned cmmdc(unsigned p, unsigned q)
{
    // functia intoarce cmmdc(a[p], ..., a[q])
    if (q - p <= 1) // cmmdc se poate calcula direct
        return Euclid(a[p], a[q]);
    unsigned m = (p + q) / 2;
    return Euclid(cmmdc(p, m), cmmdc(m + 1, q));
}

int main()
{
    Citire();
    cout << "cmmdc= " << cmmdc(0, n - 1) << endl;
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
