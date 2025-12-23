// Algoritmul lui Kruskal optimizat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <queue>
using namespace std;
#define NMAX 1001

struct Muchie
{
    int x, y;
    double cost;
    friend bool operator>(const Muchie& m1, const Muchie& m2);
};
bool operator>(const Muchie& m1, const Muchie& m2)
{
    return m1.cost > m2.cost;
}

priority_queue<Muchie, vector<Muchie>, greater<Muchie>>H;
vector<Muchie>sol;
int tata[NMAX];
int h[NMAX];
int n;
double costmin;

void Citire();
void Afisare();
int Find(int x);
void Union(int c1, int c2);

int main()
{
    int c1, c2;
    Muchie m;
    Citire();
    while ((sol.size() < n - 1))
        // Cat timp nu am selectat cele n-1 muchii
    {
        // Extrag din H muchia de cost minim
        m = H.top(); H.pop();
        // Determin componentele conexe din care fac parte
        // extremitatile muchiei selectate m
        c1 = Find(m.x); c2 = Find(m.y);
        if (c1 != c2)
            // m nu formeaza cicluri cu muchiile selectate
        {
            // Selectez aceasta muchie
            costmin += m.cost; sol.push_back(m);
            // Unific componentele conexe ale extremitatilor
            Union(c1, c2);
        }
    }
    Afisare();
    return 0;
}

void Citire()
{
    Muchie m;
    int i, nrm;
    FILE* fin;
    errno_t err = fopen_s(&fin, "kruskal.in", "r");
    fscanf_s(fin, "%d %d", &n, &nrm);
    for (i = 0; i < nrm; i++)
    {
        fscanf_s(fin, "%d %d %lf", &m.x, &m.y, &m.cost);
        H.push(m);
    }
    fclose(fin);
}

void Afisare()
{
    FILE* fout;
    errno_t err = fopen_s(&fout, "kruskal.out", "w");
    fprintf_s(fout, "%.2lf\n", costmin);
    for (int i = 0; i < n - 1; i++)
        fprintf_s(fout, "%d %d\n", sol[i].x, sol[i].y);
    fclose(fout);
}

int Find(int x)
{
    int r = x;
    // Determinam radacina arborelui
    while (tata[r]) r = tata[r];
    // Compresam drumul
    int y = x, aux;
    while (y != r)
    {
        aux = tata[y];
        tata[y] = r;
        y = aux;
    }
    return r;
}

void Union(int c1, int c2)
{
    if (h[c1] > h[c2]) tata[c2] = c1;
    else
    {
        tata[c1] = c2;
        if (h[c1] == h[c2]) h[c2]++;
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
