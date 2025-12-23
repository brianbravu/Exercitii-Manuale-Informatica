// Cetati.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#define NMax 10010
using namespace std;

struct punct { double x, y, tg; } aux;
int n, i, poz, p, p1, p2;
double xmin, ymin;
vector<punct>v(NMax);
stack<int>S;

int arie(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double aria = (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
    return (aria >= 0);
}

int cmp(punct a, punct b)
{
    return a.tg < b.tg;
}

int main()
{
    FILE* f;
    FILE* g;
    errno_t err;
    err = fopen_s(&f, "cetati.in", "r");
    err = fopen_s(&g, "cetati.out", "w");
    fscanf_s(f, "%d", &n);
    fscanf_s(f, "%lf %lf", &v[1].x, &v[1].y);
    poz = 1; xmin = v[1].x; ymin = v[1].y;
    for (i = 2; i <= n; i++)
    {
        fscanf_s(f, "%lf %lf", &v[i].x, &v[i].y);
        if (v[i].x < xmin || (v[i].x == xmin && v[i].y < ymin))
            poz = i, xmin = v[i].x, ymin = v[i].y;
    }
    aux = v[1]; v[1] = v[poz]; v[poz] = aux;
    v[1].x = v[1].y = 0; // Pun v[1] in ordine
    v[n + 1] = v[1]; // Inchei in acelasi punct
    S.push(0); // Fictiv pe pozitia 0
    S.push(1); // 1 pe prima pozitie
    for (i = 2; i <= n; i++) // Pentru celelalte puncte
    {
        v[i].x -= xmin; v[i].y -= ymin; // Translatez punctul
        if (v[i].x == 0) v[i].tg = 1 << 30; // Tangenta infinit
        else v[i].tg = v[i].y / v[i].x; // Tangenta calculata
    }
    sort(v.begin() + 2, v.begin() + 1 + n, cmp); // Ordonez
    for (i = 2; i <= n + 1; i++) // Pentru fiecare punct
    {
        S.push(i); // Pun punctul in stiva
        p = S.top(); S.pop(); // Consider ultimele 3 puncte
        p1 = S.top(); S.pop();
        p2 = S.top();
        while (S.size() > 1 && arie(v[p1].x, v[p1].y, v[p].x, v[p].y, v[p2].x, v[p2].y))
        {
            S.push(p); // Elimin punctul din mijloc
            p = S.top(); S.pop(); // Consider iar ultimele 3 puncte
            p1 = S.top(); S.pop();
            p2 = S.top();
        }
        S.push(p1); // Repun pe stiva ultimele 2 puncte
        S.push(p);
        fprintf_s(g, "%d\n", n - (S.size() - 2));
        fclose(f); fclose(g);
        return 0;
    }
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
