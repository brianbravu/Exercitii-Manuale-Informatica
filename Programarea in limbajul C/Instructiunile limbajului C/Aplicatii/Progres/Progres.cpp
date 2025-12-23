// Progres.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, i, a = 0, b, lg = 0, lgmax = 0;
    cout << "Numarul de note este "; cin >> n;
    cout << "Introduceti notele: ";
    for (i = 1; i <= n; i++)
    {
        cin >> b; // Citesc o nota
        if (a <= b) lg++; // Maresc lungimea secventei curente
        else // S-a terminat o secventa crescatoare
        {
            if (lgmax < lg) // Compar lg cu lungimea maxima
                lgmax = lg;
            lg = 1; // Incepe o noua secventa
        }
        a = b; // Nota curenta devine nota precedenta
    }
    if (lgmax < lg) lgmax = lg; // Compar si lungimea ultimei secvente
    cout << "Lungimea maxima este " << lgmax << '\n';
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
