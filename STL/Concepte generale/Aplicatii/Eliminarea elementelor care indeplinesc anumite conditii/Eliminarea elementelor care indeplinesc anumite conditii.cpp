// Eliminarea elementelor care indeplinesc anumite conditii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int a[] = { 10,11,12,13,14,15,16,17,18,19 };
int n = 10;
bool EstePar(int x) { return x % 2 == 0; }
int main()
{
    int st = 3, dr = 7, nr;
    int* psf = std::remove_if(a + st, a + dr, EstePar);
    nr = a + dr - psf; // Determin numarul de elemente eliminate
    std::copy(a + dr, a + n, psf); // Copiez restul vectorului
    n -= nr; // Actualizez dimensiunea vectorului
    for (int i = 0; i < n; i++) std::cout << a[i] << ' ';
    std::cout << '\n';
    return 0;
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
