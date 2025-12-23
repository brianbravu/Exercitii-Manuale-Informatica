// Stergerea unui nod dintr-o lista dublu inlantuita.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Nod
{
    int inf;
    struct Nod* urm, * pre;
};

typedef struct Nod* Lista;

void Insert(Lista& Prim, Lista p, int x)
{
    Lista q = new Nod;
    q->inf = x;
    q->pre = p;
    if (!p) // Inserare la inceputul listei
    {
        q->urm = Prim;
        if (Prim) Prim->pre = q;
        Prim = q;
    }
    else
    {
        q->urm = p->urm;
        p->urm = q;
        if (q->urm) q->urm->pre = q;
    }
}

void Delete(Lista& Prim, Lista q)
{
    Lista p = q->pre;
    Lista r = q->urm;
    if (p) p->urm = r;
    else Prim = r;
    if (r) r->pre = p;
    delete q;
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
