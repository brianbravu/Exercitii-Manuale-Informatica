// Stergerea unui nod cheie data dintr-un arbore.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Nod 
{
    int inf;
    struct Nod* st, * dr;
};
typedef struct Nod* Arbore;
Arbore r;

void Stergere(Arbore& r, int x)
{
    Arbore p = r, t = NULL, max, tmax, fiu; // Caut nodul cu cheia x; t indica parintele acestui nod
    while (p && p->inf != x)
    {
        t = p;
        if (x < p->inf) p = p->st;
        else p = p->dr;
    }
    if (!p) return; // Cheia x nu se afla in arbore
    if (p->st && p->dr) // Nodul de sters are 2 fii
    {
        tmax = p; // Determin maximul din subarborele stang
        max = p->st;
        while (max->dr)
        {
            tmax = max;
            max = max->dr;
        }
        p->inf = max->inf; // Copiez informatia
        t = tmax; // Nodul maxim devine nod de sters
        p = max;
     }
    // Nodul de sters are cel mult un fiu
    if (p->st) fiu = p->st;
    else fiu = p->dr;
    if (t)
        if (t->st == p) // p este fiu stang al tatalui sau
            t->st = fiu;
        else // p este fiu drept al tatalui sau
            t->dr = fiu;
    else // Sterg radacina arborelui
        r = fiu;
    delete p;
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
