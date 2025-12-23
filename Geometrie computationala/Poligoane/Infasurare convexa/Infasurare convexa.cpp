// Infasurare convexa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define DIM 200
typedef struct { double x, y; } Punct;
Punct P[DIM];
int n;
int varf;
Punct S[DIM];
void POP();
void PUSH(Punct);
double Produs(Punct, Punct, Punct);
void StangaJos()
{
    ;
}

void Sort()
{
    ;
}

void AfiseazaS()
{
    ;
}

void Graham()
{
    int i; double o;
    StangaJos(); // Determina punctul P0, y-minim, x-minim
    Sort(); // Sorteaza punctele dupa unghiul polar fata de P0
    // in P avem n elemente sortate P[0], P[1], ..., P[n-1]
    // pentru unghi egal sortat dupa distanta
    varf = 0; PUSH(P[0]); PUSH(P[1]);
    for (i = 2; i < n; i++)
    {
        o = Produs(S[varf - 1], S[varf], P[i]);
        if (o == 0) // Coliniare
        {
            POP(); // Elimin punct apropiat
            PUSH(P[i]); // Pun punct departat
        }
        else if (o > 0) PUSH(P[i]); // La stanga
        else
        {
            while (o <= 0 && varf > 1) // Cat timp intoarcere la dreapta si se poate
            {
                POP(); // Elimin varf si recalculeaza
                o = Produs(S[varf - 1], S[varf], P[i]);
            }
            PUSH(P[i]);
        }
    }
    AfiseazaS();
}

void PUSH(Punct P)
{
    ++varf;
    S[varf] = P;
}

void POP()
{
    varf--;
}

double Produs(Punct P1, Punct P2, Punct P3)
{
    return (P2.x - P1.x) * (P3.y - P1.y) - (P3.x - P1.x) * (P2.y - P1.y);
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
