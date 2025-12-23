// Crearea unei cozi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Nod
{
    int inf;
    struct Nod* urm;
};

typedef struct Nod* Lista;

void Insert(Lista& Prim, Lista p, int x)
{
    Lista q = new Nod;
    q->inf = x;
    if (!p)
    {
        q->urm = Prim;
        Prim = q;
    }
    else
    {
        q->urm = p->urm;
        p->urm = q;
    }
}

void Delete(Lista& Prim, Lista p)
{
    Lista q;
    if (p)
    {
        q = p->urm;
        if (q)
        {
            p->urm = q->urm;
            delete q;
        }
    }
    else
    {
        q = Prim;
        if (q)
        {
            Prim = Prim->urm;
            delete q;
        }
    }
}

int main()
{
    int n, x;
    Lista Prim, Ultim;
    Prim = Ultim = NULL;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        if (Prim) // Coada nu este vida
        {
            Insert(Prim, Ultim, x);
            Ultim = Ultim->urm;
        }
        else // Coada este vida
        {
            Insert(Prim, NULL, x);
            Ultim = Prim;
        }
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
