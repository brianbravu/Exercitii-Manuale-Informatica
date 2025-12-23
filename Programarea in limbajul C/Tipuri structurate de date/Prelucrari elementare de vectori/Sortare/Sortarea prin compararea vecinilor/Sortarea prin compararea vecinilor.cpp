// Sortarea prin compararea vecinilor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[100], n, i, schimb, aux;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    do
    {
        schimb = 0; // Initial nu am facut nicio schimbare
        for (i = 0; i < n - 1; i++) // Parcurg vectorul
            if (a[i] > a[i + 1]) // Compar doua elemente vecine
            {
                // Nu sunt in ordine, le interschimb
                aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                schimb = 1; // Retin ca am facut schimbari
            }
    } while (schimb); // Procesul se repeta cat timp se executa schimbari
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
