// Verificarea corectitudinii sintactice a unei expresii aritmetice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char e[200], op[] = "0123456789abcdefghijklmnopqrstuvwxyz";
int lg, i, ND;

int ValidareExpresie();
int ValidareTermen();
int ValidareFactor();

int main()
{
    cout << "Introduceti expresia "; cin.getline(e, 200);
    lg = strlen(e);
    if (ValidareExpresie()) cout << "Expresia este sintactic corecta!\n";
}

int ValidareFactor()
{
    int r = 1;
    if (e[i] == '(') // factorul e o expresie intre paranteze
    {
        ND++; // numar o paranteza deschisa care nu e inchisa
        i++; // trec peste '('
        r = ValidareExpresie(); // validez expresia din paranteze
        if (!r) return r; // expresie incorecta
        if (e[i] != ')') // paranteza este inchisa corect?
        {
            cout << "Eroare! Pe pozitia " << i << " este necesara )";
            r = 0;
        }
        else
        {
            i++; // trec peste ')'
            ND--; // scad numarul de paranteze ramase deschise
        }
    }
    else // verific daca factorul este o litera sau o cifra
        if (!strchr(op, tolower(e[i])))
        {
            cout << "Eroare! Pe pozitia " << i << " trebuie un operand";
            r = 0;
        }
        else i++; // trec peste factor
    return r;
}

int ValidareTermen()
{
    int r = ValidareFactor(); // validez primul factor din termen
    while (r && i < lg && e[i] == '*') // mai urmeaza factori
    {
        i++; // trec peste '*'
        r = ValidareFactor();
    }
    return r;
}

int ValidareExpresie()
{
    int r = ValidareTermen(); // validez primul termen
    while (r && i < lg && e[i] == '+') // mai urmeaza termeni
    {
        i++; // trec peste '+'
        r = ValidareTermen();
    }
    if (r && i < lg)
        if (e[i] != ')' || e[i] == ')' && !ND)
        {
            cout << "Eroare!";
            r = 0;
        }
    return r;
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
