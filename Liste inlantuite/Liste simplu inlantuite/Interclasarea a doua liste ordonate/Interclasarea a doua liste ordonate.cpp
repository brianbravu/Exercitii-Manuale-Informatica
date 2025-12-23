// Interclasarea a doua liste ordonate.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

void Afisare(Lista Prim)
{
    Lista p;
    for (p = Prim; p; p = p->urm)
        std::cout << p->inf << " ";
    std::cout << "\n";
}

Lista Interclasare(Lista L1, Lista L2)
{
    Lista L3; // L3 indica inceputul listei rezultat
    Lista p; // p indica nodul curent din lista in care ne deplasam
    Lista q; // q indica nodul curent din cealalta lista
    if (!L1) return L2;
    if (!L2) return L1;
    L3 = L2;
    p = L2;
    q = L1;
    if (L1->inf < L2->inf)
    {
        L3 = L1;
        p = L1;
        q = L2;
    }
    while (q)
    {
        while (p->urm && p->urm->inf <= q->inf) p = p->urm;
        Lista aux = p->urm;
        p->urm = q;
        p = q;
        q = aux;
    }
    return L3;
}

int main()
{
    int n, x;
    Lista Prim;
    Prim = NULL;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cin >> x;
        if (!Prim || Prim->inf > x)
            Insert(Prim, NULL, x);
        else
        {
            Lista p;
            for (p = Prim; p->urm && p->urm->inf < x; p = p->urm);
            Insert(Prim, p, x);
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
