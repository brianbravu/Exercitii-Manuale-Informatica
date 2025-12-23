// Intersectia a doua segmente de dreapta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
typedef struct { double x, y; } Punct;
typedef struct { Punct A, B; } Segment;
Punct P, P1, P2;
Segment L;
int verifica(Punct P, Punct P1, Punct P2)
{
    return (P.y - P1.y) * (P2.x - P1.x) - (P.x - P1.x) * (P2.y - P1.y);
}

int apartine(Punct P, Punct P1, Punct P2)
{
    if (P1.x == P2.x) // Dreapta verticala
        if (P.y >= min(P1.y, P2.y) && P.y <= max(P1.y, P2.y))
            return 1; // In segment
        else return 0;
    if (P.x >= min(P1.x, P2.x) && P.x <= max(P1.x, P2.x))
        return 1; // In segment
    return 0;
}

int ceas_trig(Punct P0, Punct P1, Punct P2)
{
    return (P1.x - P0.x) * (P2.y - P0.y) - (P2.x - P0.x) * (P1.y - P0.y);
}

int respingere_rapida(Punct P1, Punct P2, Punct P3, Punct P4)
{
    double x1, x2, y1, y2, x3, x4, y3, y4;
    x1 = min(P1.x, P2.x); x2 = max(P1.x, P2.x);
    y1 = min(P1.y, P2.y); y2 = max(P1.y, P2.y);
    x3 = min(P3.x, P4.x); x4 = max(P3.x, P4.x);
    y3 = min(P3.y, P4.y); y4 = max(P3.y, P4.y);
    return !(x2 >= x3 && x4 >= x1 && y2 >= y3 && y4 >= y1);
}

int verific_intersectie(Punct P1, Punct P2, Punct P3, Punct P4)
{
    if (ceas_trig(P1, P2, P3) * ceas_trig(P1, P2, P4) > 0) return 0;
    if (ceas_trig(P3, P4, P1) * ceas_trig(P3, P4, P2) > 0) return 0;
    return 1;
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
