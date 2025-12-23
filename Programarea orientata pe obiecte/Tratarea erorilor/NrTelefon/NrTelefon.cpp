// NrTelefon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int NrTelefon()
{
    int lg, i;
    char s[100];
    cout << "Introduceti numarul de telefon! "; cin >> s;
    lg = strlen(s);
    if (lg != 10)
        throw("Nr invalid: Trebuie sa contina 10 cifre!");
    if (s[0] != '0')
        throw("Nr invalid: Prima cifra trebuie sa fie 0!");
    for (i = 0; i < lg; i++)
        if (!(s[i] >= '0' && s[i] <= '9'))
            throw("Nr invalid: Trebuie sa contina doar cifre!");
    return atoi(s);
}

int main()
{
    int nrt;
    try
    {
        nrt = NrTelefon();
    }
    catch (const char s[])
    {
        cout << "Eroare la introducerea numarului de telefon: ";
        cout << s << '\n';
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
