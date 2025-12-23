// Albina.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAX 1000

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int t[32][32], a[32][32], n, m, i_prim, j_prim, l_s, l_j;

void citire(void)
{
    int i, j;
    FILE* f;
    errno_t err = fopen_s(&f, "albina.in", "r");
    fscanf_s(f, "%d %d", &n, &m);
    fscanf_s(f, "%d %d", &i_prim, &j_prim);
    fscanf_s(f, "%d %d", &l_s, &l_j);
    for (int i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) fscanf_s(f, "%d", &a[i][j]);
    fclose(f);
}

void bordare(void)
{
    int i, j;
    for (i = 0; i <= n + 1; i++) a[i][0] = a[i][m + 1] = MAX;
    for (j = 0; j <= m + 1; j++) a[0][j] = a[n + 1][j] = MAX;
}

void depune(int i, int j)
{
    int i_nou, j_nou, l;
    t[i][j] = 1;
    for (l = 0; l < 4; l++)
    {
        i_nou = i + dx[l]; j_nou = j + dy[l];
        if (t[i_nou][j_nou] == 0)
        {
            if ((a[i][j] >= a[i_nou][j_nou]) && (a[i][j] - a[i_nou][j_nou] <= l_j))
                depune(i_nou, j_nou);
            if ((a[i][j] < a[i_nou][j_nou]) && (a[i_nou][j_nou] - a[i][j] <= l_s))
                depune(i_nou, j_nou);
        }
    }
}

int aria(void)
{
    int i, j, k, l, il, jl;
    int Max = 0, p;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (t[i][j]) // Pentru fiecare floare polenizata
                for (k = i; k <= n; k++) // Colt stanga-sus
                    for (l = j; l <= m; l++) // Se cauta o alta floare polenizata
                        if (t[k][l]) // Colt dreapta-jos
                        {
                            // In dreptunghiul determinat de aceste doua flori se face
                            // Produsul elementelor (1 - polenizata sau 0 - nu)
                            p = 1;
                            for (il = i; il <= k; il++)
                                for (jl = j; jl <= l; jl++)
                                    p *= t[il][jl];
                            if (p) // Daca toate au fost 1
                                if ((k - i + 1) * (l - j + 1) > Max) // Am determinat un dreptunghi plin
                                    Max = (k - i + 1) * (l - j + 1); // Retin maximul aflat pana acum
                        }
    return Max;
}

int main()
{
    FILE* g;
    citire();
    bordare();
    depune(i_prim, j_prim);
    errno_t err;
    err = fopen_s(&g, "albina.out", "w");
    fprintf_s(g, "%d", aria());
    fclose(g);
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
