// Crearea interactiva a unui arbore binar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Nod
{
    int inf;
    struct Nod* st, * dr;
};
typedef struct Nod* Arbore;
Arbore r;

Arbore Creare()
{
    char c;
    Arbore p = new Nod;
    std::cout << "Informatia nodului: "; std::cin >> p->inf;
    std::cout << "Exista fiu stang? (d/n) "; std::cin >> c;
    if (c == 'd') p->st = Creare();
    else p->st = NULL;
    std::cout << "Exista fiu drept? (d/n) "; std::cin >> c;
    if (c == 'd') p->dr = Creare();
    else p->dr = NULL;
    return p;
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
