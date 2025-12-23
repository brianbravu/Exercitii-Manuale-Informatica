// Functiile membre statice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class ExStatic
{
private:
    static int n;
    int m;
public:
    ExStatic() // Constructor
    {
        n++;
    }
    ~ExStatic() // Destructor
    {
        n--;
    }
    void Set(int a, int b)
    {
        n = a;
        m = b;
    }
    static void Scrie()
    {
        cout << n << ' ';
    }
};

int ExStatic::n = 0; // Definirea datei membre statice si initializarea acesteia

void f()
{
    ExStatic ob; // Se creaza obiectul local ob
    ob.Scrie(); // Scrie 7
}

int main()
{
    ExStatic a; // Creez un obiect
    ExStatic::Scrie(); // Scrie 1
    ExStatic b[5]; // Creez un vector cu 5 obiecte
    ExStatic::Scrie(); // Scrie 6
    ExStatic* c = new ExStatic; // Creez dinamic un obiect
    a.Scrie(); // Scrie 7
    delete c; // Eliberez dinamic obiectul c
    ExStatic::Scrie(); // Scrie 6
    f(); // Apelez functia f
    ExStatic::Scrie(); // Scrie 6
    a.Set(100, 200); // Apelez functia set
    ExStatic::Scrie(); // Scrie 100
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
