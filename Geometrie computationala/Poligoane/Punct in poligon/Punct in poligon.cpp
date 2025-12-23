// Punct in poligon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define exterior -1
#define pe_latura 0
#define interior 1
#define NMAX 200

typedef struct { double x, y; } Punct;
typedef Punct Poligon[NMAX];
Poligon P;
Punct M;
int n;

int int_pe_ext(void)
{
    int i, intersectii = 0;
    double t, cy;
    P[n] = P[0];
    for (i = 0; i < n; i++)
    {
        if ((P[i].x < M.x && M.x < P[i + 1].x) || (P[i].x > M.x && M.x > P[i + 1].x))
        {
            t = (M.x - P[i + 1].x) / (P[i].x - P[i + 1].x);
            cy = t * P[i].y + (1 - t) * P[i + 1].y;
            if (M.y == cy) return (pe_latura); // Orizontala
            else if (M.y > cy) intersectii++;
        }
        if (P[i].x == M.x && P[i].y >= M.y && P[i + 1].y <= M.y)
            return (pe_latura); // Pe verticala, P[i] sus
        if (P[i].x == M.x && P[i].y <= M.y)
        {
            if (P[i].y == M.y) return (pe_latura);
            if (P[i + 1].y == M.y)
            {
                if ((P[i].y <= M.y && M.y <= P[i + 1].y) || (P[i].y >= M.y && M.y >= P[i + 1].y))
                    return (pe_latura); // Verticala, P[i] jos
            }
            else // Testare caz (B)
                if (P[i + 1].x > M.x) intersectii++;
            if (P[i - 1].x > M.x) intersectii++;
        }
    }
    if (intersectii % 2) return (interior);
    return (exterior);
}

int main()
{
    int i, v;
    FILE* stream;
    freopen_s(&stream, "puncte.in", "r", stdin);
    scanf_s("%d", &n);
    for (i = 0; i < n; i++) scanf_s("%lf %lf", &P[i].x, &P[i].y);
    v = int_pe_ext();
    puts(v > 0 ? "interior" : v < 0 ? "exterior" : "pe latura");
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
