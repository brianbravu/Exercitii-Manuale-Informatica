// Crearea unui heap prin inserari succesive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101
int n, H[NMax];

void InsertHeap(int n, int x) // Insereaza valoarea x in heap-ul H de dimensiune n
{
    int fiu = ++n; // fiu indica pozitia pe care trebuie plasata valoarea x
    int tata = n / 2;
    while (tata && H[tata] < x) // Valoarea x trebuie "promovata"
    {
        H[fiu] = H[tata];
        fiu = tata;
        tata = fiu / 2;
    }
    H[fiu] = x;
}

void CreateHeap()
{
    int i;
    for (i = 2; i <= n; i++)
        InsertHeap(i - 1, H[i]);
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
