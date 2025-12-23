// Evaluarea unei expresii aritmetice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

struct { char ns; int v; } TS[200];

char e[200];
int i, lg;

void Citire();
int eval(char);
int EvaluareExpresie();
int EvaluareFactor();
int EvaluareTermen();

int main()
{
    Citire();
    cout << "Valoarea expresiei este: " << EvaluareExpresie();
}

void Citire()
{
    ifstream fin("expres.in");
    int NrS = 0;
    fin.getline(e, 200); lg = strlen(e);
    while (!fin.eof())
    {
        fin >> TS[NrS].ns >> TS[NrS].v;
        NrS++;
    }
    fin.close();
}

int eval(char c)
{
    // functia intoarce valoarea operandului c
    if (c > '0' && c < '9') return c - '0';
    // caut valoarea variabilei in tabela de simboluri
    int k;
    for (k = 0; TS[k].ns != c; k++);
    return TS[k].v;
}

int EvaluareFactor()
{
    int f;
    if (e[i] == '(') // factorul e o expresie intre paranteze
    {
        i++; // trec peste '('
        f = EvaluareExpresie();
        i++; // trec peste ')'
    }
    else // factorul este o litera sau o cifra
    {
        f = eval(e[i]);
        i++; // trec peste factor
    }
    return f;
}

int EvaluareTermen()
{
    int f = EvaluareFactor(); // validez primul factor din termen
    while (i < lg && e[i] == '*') // mai urmeaza factori
    {
        i++; // trec peste '*'
        f *= EvaluareFactor();
    }
    return f;
}

int EvaluareExpresie()
{
    int t = EvaluareTermen(); // validez primul termen
    while (i < lg && e[i] == '+') // mai urmeaza termeni
    {
        i++; // trec peste '+'
        t += EvaluareTermen();
    }
    return t;
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
