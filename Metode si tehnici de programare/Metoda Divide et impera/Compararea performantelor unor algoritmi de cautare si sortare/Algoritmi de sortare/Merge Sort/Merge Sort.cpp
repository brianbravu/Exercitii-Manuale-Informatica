// Merge Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int a[100], n;

void Citire()
{
    ifstream fin("sort.in");
    fin >> n;
    for (int i = 0; i < n; i++) fin >> a[i];
    fin.close();
}

void Afisare()
{
    cout << "Vectorul sortat este ";
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
}

void Interclasare(int p, int m, int q)
{
    // interclaseaza subsirurile sortate a[p...m] si a[m+1...q]
    int i = p, j = m + 1, k = 0; // cu i parcurg portiunea a[p...m], cu j portiunea a[m+1...q]
    int b[100]; // vector in care retinem temporar rezultatul interclasarii
    while (i <= m && j <= q)
        if (a[i] < a[j]) b[k++] = a[i++];
        else b[k++] = a[j++];
    while (i <= m) b[k++] = a[i++];
    while (j <= q) b[k++] = a[j++];
    // transfer rezultatul interclasarii in vectorul a
    for (i = p; i <= q; i++) a[i] = b[i - p];
}

void MSort(int p, int q)
{
    // sorteaza elementele a[p], ..., a[q]
    if (q > p)
    {
        int m = (p + q) / 2;
        MSort(p, m);
        MSort(m + 1, q);
        Interclasare(p, m, q);
    }
}

int main()
{
    Citire();
    MSort(0, n - 1);
    Afisare();
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
