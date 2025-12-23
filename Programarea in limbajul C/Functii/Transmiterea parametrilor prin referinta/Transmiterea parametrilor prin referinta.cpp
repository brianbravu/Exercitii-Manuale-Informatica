// Transmiterea parametrilor prin referinta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void citire_vector(int&, int*);
void afisare_vector(int, int*);

int main()
{
    int n, a[10], m, b[10];
    citire_vector(n, a);
    citire_vector(m, b);
    afisare_vector(n, a);
    afisare_vector(m, b);
}

void citire_vector(int& nr, int x[10])
{
    cout << "Numarul de elemente: "; cin >> nr;
    cout << "Elementele vectorului: ";
    for (int i = 0; i < nr; i++) cin >> x[i];
}

void afisare_vector(int nr, int a[10])
{
    cout << "Elementele vectorului sunt: ";
    for (int i = 0; i < nr; i++) cout << a[i] << ' ';
    cout << '\n';
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
