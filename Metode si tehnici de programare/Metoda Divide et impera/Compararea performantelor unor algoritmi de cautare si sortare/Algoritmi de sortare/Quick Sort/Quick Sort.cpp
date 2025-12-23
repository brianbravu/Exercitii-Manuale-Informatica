// Quick Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int Divide(int p, int q)
{
    // plaseaza elementul a[p] pe pozitia sa corecta in vectorul ordonat,
    // in stanga sa fiind plasate numai elemente mai mici,
    // iar in dreapta numai elemente mai mari decat el si intoarce pozitia pe care a fost plasat a[p]
    int st = p, dr = q, x = a[p];
    while (st < dr)
    {
        while (st < dr && a[dr] >= x) dr--;
        a[st] = a[dr];
        while (st < dr && a[st] <= x) st++;
        a[dr] = a[st];
    }
    a[st] = x;
    return st;
}

void QSort(int p, int q)
{
    // sorteaza elementele a[p], ..., a[q]
    if (q > p)
    {
        int m = Divide(p, q);
        if (m - 1 > p) QSort(p, m - 1);
        if (m + 1 < q) QSort(m + 1, q);
    }
}

int main()
{
    Citire();
    QSort(0, n - 1);
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
