// Cel mai mare divizor comun cu descompunere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define Dim 20

typedef long Factori[Dim];
typedef int Multiplicitati[Dim];

Factori DivA, DivB;
Multiplicitati OrdA, OrdB;
int CatiA, CatiB;

void Descompune(long, int&, Factori, Multiplicitati);
long Putere(unsigned, unsigned);
long cmmdc();

int main()
{
    long int a, b;
    cout << "a = "; cin >> a;
    cout << "b = "; cin >> b;
    Descompune(a, CatiA, DivA, OrdA);
    Descompune(b, CatiB, DivB, OrdB);
    cout << "c. m. m. d. c. (" << a << ", " << b << ") = "<<cmmdc();
}

void Descompune(long x, int& nx, Factori DivX, Multiplicitati OrdX)
{
    long d = 2;
    nx = 0;
    while (x > 1)
    {
        if (!(x % d)) // Am gasit un factor
        {
            DivX[++nx] = d;
            while (!(x % d)) // Calculez multiplicitate
            {
                x /= d;
                OrdX[nx]++;
            }
        }
        d++;
    }
}

long Putere(unsigned x, unsigned y) // Calculeaza x la puterea y
{
    unsigned i;
    long P = 1;
    for (i = 1; i <= y; i++) P *= x;
    return P;
}

long cmmdc()
{
    int i = 1, j = 1;
    long c = 1;
    while ((i <= CatiA) && (j <= CatiB))
        if (DivA[i] == DivB[j]) // Am gasit un factor comun
        {
            c *= Putere(DivA[i], OrdA[i] < OrdB[j] ? OrdA[i] : OrdB[j]); // Determin puterea minima apoi calculez
            i++; j++; // Trec la factorii urmatori
        }
        else if (DivA[i] < DivB[j]) i++;
        else j++;
    return c;
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
