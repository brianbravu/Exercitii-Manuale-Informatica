// Walls.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 251
#define MMax 201
#define OMax 31

int N, M, L;
char G[NMax][NMax];
char A[NMax][NMax];
int o[NMax];
char AD[OMax][OMax];
int D[OMax][MMax];
char viz[MMax];
int C[MMax]; // Coada
long Min;
int R;

void Citire()
{
    FILE* fin;
    errno_t err = fopen_s(&fin, "walls.in", "r");
    int nr, x, y, j, i, prim;
    fscanf_s(fin, "%d %d %d", &M, &N, &L);
    for (i = 1; i <= L; i++)
    {
        fscanf_s(fin, "%d", &x);
        o[x] = i;
    }
    for (i = 1; i <= M; i++)
    {
        fscanf_s(fin, "%d %d", &nr, &prim);
        x = prim;
        for (j = 1; j <= nr; x = y, j++)
        {
            if (j < nr) fscanf_s(fin, "%d", &y);
            else y = prim;
            G[x][y] = i;
            if (o[y]) AD[o[y]][i] = 1;
            A[i][G[y][x]] = A[G[y][x]][i] = 1;
        }
    }
}

void BFS(int start)
{
    int i, prim = 0, ultim = -1, x;
    for (i = 1; i <= M; i++) viz[i] = 0;
    for (i = 1; i <= M; i++)
        if (AD[start][i])
        {
            C[++ultim] = i; viz[i] = 1;
            D[start][i] = 0;
        }
    while (prim <= ultim)
    {
        x = C[prim++];
        for (i = 1; i <= M; i++)
            if (!viz[i] && A[i][x])
            {
                viz[i] = 1;
                C[++ultim] = i;
                D[start][i] = 1 + D[start][x];
            }
    }
}

void Rezolvare()
{
    int i, j;
    long s;
    for (i = 1; i <= L; i++) BFS(i);
    for (Min = 1000000, i = 1; i <= M; i++)
    {
        for (s = 0, j = 1; j <= L; j++) s += D[j][i];
        if (s < Min)
        {
            Min = s;
            R = i;
        }
    }
}

void Afisare()
{
    FILE* fout;
    errno_t err = fopen_s(&fout, "walls.out", "w");
    fprintf_s(fout, "%ld\n%d\n", Min, R);
    fclose(fout);
}

int main()
{
    Citire();
    Rezolvare();
    Afisare();
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
