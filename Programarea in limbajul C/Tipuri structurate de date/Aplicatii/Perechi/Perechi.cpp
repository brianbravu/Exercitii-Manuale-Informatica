// Perechi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    long int s, a, b, aux;
    int k, cifrea[10], cifreb[10];
    cout << "s = "; cin >> s;
    for (a = 0; a < s / 2; a++)
    {
        b = s - a;
        // Determinam multimea cifrelor lui a
        for (k = 0; k < 10; k++) cifrea[k] = 0;
        aux = a;
        do
        {
            cifrea[aux % 10] = 1;
            aux /= 10;
        } while (aux);
        // Determinam multimea cifrelor lui b
        for (k = 0; k < 10; k++) cifreb[k] = 0;
        aux = b;
        do
        {
            cifrea[aux % 10] = 1;
            aux /= 10;
        } while (aux);
        // Verificam daca cifrele sunt distincte
        for (k = 0; k < 10 && !(cifrea[k] && cifreb[k]); k++);
        if (k == 10) cout << a << ' ' << b << '\n';
        }
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
