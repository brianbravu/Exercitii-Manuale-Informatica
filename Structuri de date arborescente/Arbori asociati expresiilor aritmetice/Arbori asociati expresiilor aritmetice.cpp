// Arbori asociati expresiilor aritmetice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define LgMax 101
struct Nod
{
    char inf;
    struct Nod* st, * dr;
};
typedef struct Nod* Arbore;
Arbore rad;
char e[LgMax]; // Expresia
int lg; // Lungimea expresiei
Arbore CreareArbore(int& i);
Arbore Factor(int& i);
Arbore Termen(int& i);
Arbore Factor(int& i) // Construieste arborele binar asociat unui factor
{
    Arbore p;
    if (e[i] == '(')
    {
        ++i;
        p = CreareArbore(i);
        i++;
        return p;
    }
    p = new Nod; p->inf = e[i++]; p->st = p->dr = NULL;
    return p;
}

Arbore Termen(int& i) // Construieste arborele binar asociat unui termen
{
    Arbore p, r1;
    r1 = Factor(i);
    if (i > lg || e[i] != '*') return r1;
    p = new Nod;
    p->inf = e[i++]; p->st = r1; p->dr = Termen(i);
    return p;
}

Arbore CreareArbore(int& i) // Construieste arborele binar asociat expresiei ariitmetice
{
    Arbore p, r1;
    if (i > lg) return NULL;
    r1 = Termen(i);
    if (i > lg || e[i] == ')') return r1;
    p = new Nod;
    p->inf = e[i++]; p->st = r1; p->dr = CreareArbore(i);
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
