// Pozitia unui punct fata de un segment. Coliniaritate.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

int main()
{
    cout << "Hello World!\n";
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
