// Suma a doua polinoame sub forma condensata.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Nod
{
    int c, g;
    struct Nod* urm;
};

typedef struct Nod* Lista;

void Insert(Lista& Prim, Lista p, int x, int y)
{
    Lista q = new Nod;
    q->c = x;
    q->g = y;
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

int eval(Lista Prim, int x0)
{
    int val = 0, gc = 0, p = 1;
    Lista q;
    for (q = Prim; q; q = q->urm)
    {
        // Calculez puterea
        for (; gc < q->g; p *= x0, gc++);
        val += p * q->c;
    }
    return val;
}

Lista Suma(Lista L1, Lista L2)
{
    Lista L3 = NULL, Ultim = NULL, p = L1, q = L2;
    while (p && q)
    {
        if (p->g < q->g)
        {
            Insert(L3, Ultim, p->c, p->g);
            p = p->urm;
            if (Ultim) Ultim = Ultim->urm;
            else Ultim = L3;
        }
        else if (p->g > q->g)
        {
            Insert(L3, Ultim, q->c, q->g);
            q = q->urm;
            if (Ultim) Ultim = Ultim->urm;
            else Ultim = L3;
        }
        else
        {
            if (p->c + q->c)
            {
                Insert(L3, Ultim, p->c + q->c, p->g);
                if (Ultim) Ultim = Ultim->urm;
                else Ultim = L3;
            }
            p = p->urm;
            q = q->urm;
        }
    }
    while (p)
    {
        Insert(L3, Ultim, p->c, p->g);
        p = p->urm;
        Ultim = Ultim->urm;
    }
    while (q)
    {
        Insert(L3, Ultim, q->c, q->g);
        q = q->urm;
        Ultim = Ultim->urm;
    }
    return L3;
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
