// Intersectia a doua dreptunghiuri.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
typedef struct { double x, y; } Punct;
typedef struct { Punct SS, DJ; } DREPTUNGHI;
Punct A[5], B[5];
int PunctInterior(Punct A, DREPTUNGHI r)
{
    return (r.SS.x <= A.x && A.x <= r.DJ.x &&
        r.DJ.y <= A.y && A.y <= r.SS.y);
}

int Intersect(DREPTUNGHI r1, DREPTUNGHI r2)
{
    return PunctInterior(A[1], r2) || PunctInterior(A[2], r2) ||
        PunctInterior(A[3], r2) || PunctInterior(A[4], r2) ||
        // Colt al lui r1 in r2?
        PunctInterior(B[1], r1) || PunctInterior(B[2], r1) ||
        PunctInterior(B[3], r1) || PunctInterior(B[4], r1);
    // Colt al lui r2 in r1?
}

int NuSeIntersect(DREPTUNGHI r1, DREPTUNGHI r2)
{
    return (r1.DJ.x < r2.SS.x || r1.SS.x > r2.DJ.x ||
        r1.DJ.y > r2.SS.y || r1.SS.y < r2.DJ.y);
}

int SeIntersect(DREPTUNGHI r1, DREPTUNGHI r2)
{
    return (r1.DJ.x >= r2.SS.x && r1.SS.x <= r2.DJ.x &&
        r1.DJ.y <= r2.SS.y && r1.SS.y >= r2.DJ.y);
}

Punct StangaSus(DREPTUNGHI r1, DREPTUNGHI r2)
{
    Punct A;
    A.x = max(r1.SS.x, r2.SS.x); A.y = min(r1.SS.y, r2.SS.y);
    return A;
}

Punct DreaptaJos(DREPTUNGHI r1, DREPTUNGHI r2)
{
    Punct A;
    A.x = max(r1.DJ.x, r2.DJ.x); A.y = min(r1.DJ.y, r2.DJ.y);
    return A;
}

double Aria(Punct A, Punct B)
{
    return (B.x - A.x) * (A.y - B.y);
}

double Perim(Punct A, Punct B)
{
    return 2 * ((B.x - A.x) + (A.y - B.y));
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
