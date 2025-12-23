// Permutare ciclica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[100], n, p, i, aux, j;
    cout << "n, p = "; cin >> n >> p;
    cout << "Elementele vectorului: ";
    for (i = 0; i < n; i++) cin >> a[i];
    // Inversam elementele vectorului de la 0 la n-p-1
    for (i = 0, j = n - p - 1; i < j; i++, j--)
    {
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }
    // Inversam elementele vectorului de la n-p la n-1
    for (i = n - p, j = n - 1; i < j; i++, j--)
    {
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }
    // Inversam intreg vectorul
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        aux = a[i];
        a[i] = a[j];
        a[j] = aux;
    }
    for (i = 0; i < n; i++) cout << a[i] << ' '; cout << '\n';
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
