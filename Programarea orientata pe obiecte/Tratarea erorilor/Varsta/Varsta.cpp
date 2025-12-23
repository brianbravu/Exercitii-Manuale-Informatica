// Varsta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Varsta()
{
    int v, i;
    char s[100];
    cout << "Introduceti varsta! (0-99) "; cin >> s;
    for (i = 0; s[i]; i++)
        if (!(s[i] >= '0' && s[i] <= '9'))
            throw("Varsta trebuie sa contina doar cifre!");
    v = atoi(s);
    if (v < 18 || v>99) throw(v);
    return v;
}

int main()
{
    int v;
    try
    {
        v = Varsta();
    }
    catch (const char s[])
    {
        cout << "A aparut o eroare la introducerea varstei: ";
        cout << s << '\n';
    }
    catch (const int val)
    {
        cout << "Pentru permis varsta este intre 18 si 99 ani, nu ";
        cout << val << " ani!\n";
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
