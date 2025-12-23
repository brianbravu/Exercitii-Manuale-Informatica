// Datele membre statice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class ExStatic
{
public:
    static int n;
    ExStatic() // Constructor
    {
        n++;
    }
    ~ExStatic() // Destructor
    {
        n--;
    }
};

int ExStatic::n = 0; // Definire si initializare

void f()
{
    ExStatic ob; // Se creaza obiectul local ob
    cout << ob.n << ' '; // Scrie 7
}

int main()
{
    ExStatic a; // Creez un obiect
    cout << ExStatic::n << ' '; // Scrie 1
    ExStatic b[5]; // Creez un vector cu 5 obiecte
    cout << ExStatic::n << ' '; // Scrie 6
    ExStatic* c = new ExStatic; // Creez dinamic un obiect
    cout << a.n << ' '; // Scrie 7
    delete c; // Eliberez dinamic obiectul c
    cout << ExStatic::n << ' '; // Scrie 6
    f(); // Apelez functia f
    cout << ExStatic::n << ' '; // Scrie 6
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
