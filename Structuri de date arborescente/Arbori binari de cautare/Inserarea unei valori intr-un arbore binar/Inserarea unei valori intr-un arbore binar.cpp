// Inserarea unei valori intr-un arbore binar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Nod
{
    int inf;
    struct Nod* st, * dr;
};
typedef struct Nod* Arbore;
Arbore r;

void Inserare(Arbore& r, int x)
{
    Arbore p = new Nod, q = r;
    p->inf = x; // Ceez nodul terminal cu cheia x
    p->st = p->dr = NULL;
    if (!r) // Arborele este vid
    {
        r = p;
        return;
    }
    while (true) //Caut pozitia valorii x in arbore
    {
        if (q->inf == x) // Valoarea x exista deja in arbore
        {
            delete p;
            return;
        }
        if (x < q->inf)
            if (q->st) q = q->st;
            else
            {
                q->st = p;
                return;
            }
        else if (q->dr) q = q->dr;
        else
        {
            q->dr = p;
            return;
        }
    }
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
