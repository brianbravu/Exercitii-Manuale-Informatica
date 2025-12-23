// Cautarea binara.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int a[100], n, x;

void Citire()
{
    cout << "n= "; cin >> n;
    cout << "Introduceti elementele, ordonate crescator ";
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "x= "; cin >> x;
}

int Cautare(int prim, int ultim)
{
    // functia cauta valoarea x in vectorul a de la pozitia prim pana la pozitia ultim si intoarce o pozitie pe care apare x, respectiv valoarea -1, daca x nu apare in sir
    if (prim > ultim) return -1; // spatiul de cautare este vid
    int mijloc = (prim + ultim) / 2;
    if (x == a[mijloc]) return mijloc; // x se gaseste in mijloc
    // x poate fi doar in stanga
    if (x < a[mijloc]) return Cautare(prim, mijloc - 1);
    // x poate fi doar in dreapta
    return Cautare(mijloc + 1, ultim);
}

int main()
{
    Citire();
    int poz = Cautare(0, n - 1);
    if (poz < 0) cout << x << " nu se gaseste in sir\n";
    else cout << x << " apare pe pozitia " << poz;
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
