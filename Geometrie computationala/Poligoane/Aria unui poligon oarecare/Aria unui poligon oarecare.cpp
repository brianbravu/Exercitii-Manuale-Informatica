// Aria unui poligon oarecare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define DIM 200
typedef struct { double x, y; } Punct;
typedef Punct* Poligon;
Punct P[DIM];
int n;
double dist(Punct A, Punct B)
{
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

double Heron(Punct A, Punct B, Punct C)
{
    double p, a, b, c;
    a = dist(B, C); b = dist(A, C); c = dist(A, B);
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Arie_Triunghi(Punct A, Punct B, Punct C)
{
    return abs((B.x - A.x) * (C.y - A.x) - (C.x - A.x) * (B.y - A.y)) / 2;
}

double arie_convex(Poligon P, int n)
{
    double arie = 0;
    int i;
    for (i = 2; i < n; i++)
        arie += Arie_Triunghi(P[1], P[i], P[i + 1]);
    return arie;
}

double arie_oarecare(Poligon P, int n)
{
    double arie = 0;
    int i;
    for (i = 1; i <= n; i++)
        arie += P[i].x * (P[i + 1].y - P[i - 1].y);
    return abs(arie / 2);
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
