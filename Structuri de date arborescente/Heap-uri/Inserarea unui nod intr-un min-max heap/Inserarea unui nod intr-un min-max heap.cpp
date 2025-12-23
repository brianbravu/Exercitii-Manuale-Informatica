// Inserarea unui nod intr-un min-max heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
int n, H[NMax];

void CombHeap(int i, int n)
{
    int v = H[i], tata = i, fiu = 2 * i; // tata indica pozitia pe care va fi plasata valoarea v
    while (fiu <= n)
    {
        if (fiu < n) // Exista fiu drept
            if (H[fiu] < H[fiu + 1]) fiu++;
        if (v < H[fiu]) // fiu indica fiul cu valoarea cea mai mare
        {
            H[tata] = H[fiu];
            tata = fiu; // v coboara in adancime
            fiu = fiu * 2;
        }
        else fiu = n + 1; // Am gasit pozitia corecta pentru v
    }
    H[tata] = v;
}

void CreareHeap()
{
    int i;
    for (i = n / 2; i; i--)
        CombHeap(i, n);
}

void Insert(int x)
{
    int niv, fiu, tata;
    H[++n] = x;
    if (n <= 1) return;
    fiu = n; // Pozitia curenta a valorii x
    niv = log2(n); // Nivelul pe care este inserat noul lod
    if (niv % 2 == 0) // Nodul este inserat pe un nivel minim
    {
        tata = n / 2; // Nodul tata situat pe nivel maxim
        if (x > H[tata]) // Compar cu nodurile maxime de pe drumul spre radacina
        {
            while (tata && x > H[tata])
            {
                H[fiu] = H[tata];
                fiu = tata;
                tata = fiu / 4;
            }
            H[fiu] = x;
        }
        else // Compar cu nodurile minime de pe drumul spre radacina
        {
            tata = fiu / 4;
            while (tata && x < H[tata])
            {
                H[fiu] = H[tata];
                fiu = tata;
                tata = fiu / 4;
            }
            H[fiu] = x;
        }
    }
    else // Nodul este inserat pe un nivel maxim
    {
        tata = n / 2; // Nodul tata situat pe nivel minim
        if (x < H[tata]) // Compar cu nodurile minime de pe drumul spre radacina
        {
            while (tata && x < H[tata])
            {
                H[fiu] = H[tata];
                fiu = tata;
                tata = fiu / 4;
            }
            H[fiu] = x;
        }
        else // Compar cu nodurile maxime de pe drumul spre radacina
        {
            tata = fiu / 4;
            while (tata && x > H[tata])
            {
                H[fiu] = H[tata];
                fiu = tata;
                tata = fiu / 4;
            }
            H[fiu] = x;
        }
    }
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
