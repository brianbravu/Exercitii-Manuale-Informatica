// Crearea unui arbore binar pe baza parcurgerii preordine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 101

struct Nod
{
    int inf;
    struct Nod* st, * dr;
};
typedef struct Nod* Arbore;
Arbore r;
int in[NMax];

Arbore Creare(int rad, int st, int dr)
// Functia returneaza radacina arborelui unic determinat de parcurgerile inordine si preordine
// rad este indicele radacinii arborelui,
// st si dr sunt limitele intre care se gaseste parcurgerea inordine a arborelui in vectorul in
{
    int IPozRad;
    Arbore r = new Nod; // Aloc memorie pentru radacina
    r->inf = rad; // Retinem informatia
    for (IPozRad = st; in[IPozRad] != rad; IPozRad++); // Determin pozitia radacinii in parcurgerea inordine
    if (IPozRad == st) // Subarborele stang este vid
        r->st = NULL;
    else // in[st...IPozRad-1] contine subarborele stang
        r->st = Creare(rad + 1, st, IPozRad - 1);
    if (IPozRad == dr) // Subarborele drept este vid
        r->dr = NULL;
    else // in[IPozRad+1...dr] contine subarborele drept
        r->st = Creare(rad + IPozRad - st + 1, IPozRad + 1, dr);
    return r;
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
