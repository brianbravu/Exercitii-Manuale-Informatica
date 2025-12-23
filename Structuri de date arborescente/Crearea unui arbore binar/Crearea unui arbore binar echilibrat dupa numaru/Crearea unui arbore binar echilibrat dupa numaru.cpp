// Crearea unui arbore binar echilibrat dupa numaru.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Nod
{
    int inf;
    struct Nod* st, * dr;
};
typedef struct Nod* Arbore;
Arbore r;

Arbore Creare(int n) // Returneaza adresa radacinii unui arbore binar echilibrat cu n noduri
{
    if (n)
    {
        Arbore p = new Nod;
        std::cout << "Informatia nodului: "; std::cin >> p->inf;
        p->st = Creare(n / 2);
        p->dr = Creare(n - 1 - n / 2);
        return p;
    }
    return NULL;
}

int main()
{
    std::cout << "Hello World!\n";
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
