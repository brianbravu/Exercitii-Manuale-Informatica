// Magic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define Nmax 10
#define InFile "magic.in"
#define OutFile "magic.out"
using namespace std;
FILE* stream;

struct Element
{
    int conf, nr;
};
struct Element st, fin;
queue<Element>Q;
vector<bool>viz(50000, false);
int ST[Nmax], FIN[Nmax], f[Nmax];

void perm_ord(int p[], int& nr)
{
    int i, j, pwr[Nmax];
    nr = 0;
    for (i = 0; i < Nmax; i++) pwr[i] = 0;
    for (i = 1; i <= 8; i++)
    {
        nr += (p[i] - pwr[p[i]] - 1) * f[8 - i];
        for (j = p[i] + 1; j <= 8; j++) pwr[j]++;
    }
}

void ord_perm(int ord, int p[])
{
    int i, j, a, nr, pwr[Nmax], v[Nmax];
    for (i = 0; i < Nmax; i++) pwr[i] = v[i] = 0;
    for (i = 1; i <= 8; i++)
    {
        a = ord / f[8 - i];
        nr = 0;
        for (j = 0; j < 8; j++)
            if (!v[j])
            {
                if (nr == a)
                {
                    p[i] = j + 1, v[j] = 1;
                    break;
                }
                nr++;
            }
        ord -= (p[i] - pwr[p[i]] - 1) * f[8 - i];
        for (j = p[i] + 1; j <= 8; j++) pwr[j]++;
    }
}

void copy(int A[], int B[])
{
    for (int i = 1; i <= 8; i++) A[i] = B[i];
}

int calcul()
{
    struct Element x, y;
    int t, X[Nmax], Y[Nmax];
    Q.push(st); viz[st.conf] = true;
    while (!Q.empty())
    {
        x = Q.front(); Q.pop(); // Extrag configuratia curenta
        if (x.conf == fin.conf) return x.nr; // Am gasit
        else
        {
            ord_perm(x.conf, X);
            y.nr = x.nr + 1;
            // Miscare de tipul A
            copy(Y, X);
            t = Y[2]; Y[2] = Y[1], Y[1] = Y[5], Y[5] = Y[6]; Y[6] = t;
            perm_ord(Y, y.conf);
            if (!viz[y.conf])
            {
                Q.push(y);
                viz[y.conf] = true;
            }
            // Miscare de tip B
            copy(Y, X);
            t = Y[3]; Y[3] = Y[2], Y[2] = Y[6], Y[6] = Y[7]; Y[7] = t;
            perm_ord(Y, y.conf);
            if (!viz[y.conf])
            {
                Q.push(y);
                viz[y.conf] = true;
            }
            // Miscare de tipul C
            copy(Y, X);
            t = Y[4]; Y[4] = Y[3], Y[3] = Y[7], Y[7] = Y[8]; Y[8] = t;
            perm_ord(Y, y.conf);
            if (!viz[y.conf])
            {
                Q.push(y);
                viz[y.conf] = true;
            }
            // Miscare de tipul D
            copy(Y, X);
            swap(Y[1], Y[5]), perm_ord(Y, y.conf);
            if (!viz[y.conf])
            {
                Q.push(y);
                viz[y.conf] = true;
            }
        }
    }
    return 0;
}

int main()
{
    int i;
    freopen_s(&stream, InFile, "r", stdin);
    freopen_s(&stream, OutFile, "w", stdout);
    for (f[0] = i = 1; i < Nmax; i++) f[i] = f[i - 1] * i;
    for (i = 1; i <= 8; i++) scanf_s("%d", &ST[i]);
    for (i = 1; i <= 8; i++) scanf_s("%d", &FIN[i]);
    perm_ord(ST, st.conf); perm_ord(FIN, fin.conf);
    printf("%d\n", calcul());
    return 0;
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
