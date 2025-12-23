// Scara.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAX_N 121
#define FIN "scara.in"
#define FOUT "scara.out"
#define INF 10000
#define cmp(a, b, c, d) (((a)<(c)||((a)==(c))&&(b)<(d)))

int N, apa[MAX_N], suc[MAX_N];
int nrpasi[MAX_N], sum[MAX_N];

void citire(void);
void afisare(void);
void dinamic(void);

int main()
{
    citire();
    dinamic();
    afisare();
}

void citire()
{
    int i, j, K;
    FILE* fin;
    errno_t err = fopen_s(&fin, FIN, "r");
    fscanf_s(fin, "%d", &N);
    fscanf_s(fin, "%d", &K);

    for (; K > 0; K--)
    {
        fscanf_s(fin, "%d %d", &i, &j);
        apa[i] = j;
    }
    fscanf_s(fin, "%d", &K);
    for (; K > 0; K--)
    {
        fscanf_s(fin, "%d %d", &i, &j);
        suc[i] = j;
    }
    fclose(fin);
}

void afisare()
{
    FILE* fout;
    errno_t err = fopen_s(&fout, FOUT, "w");
    fprintf_s(fout, "%d %d\n", nrpasi[N], sum[N]);
    fclose(fout);
}

void dinamic()
{
    int i, q;
    nrpasi[1] = 1;
    for (i = 2; i <= N; i++) nrpasi[i] = INF;
    for (i = 1; i <= N; i++)
    {
        if (i < N && cmp(nrpasi[i] + 1, sum[i], nrpasi[i + 1], sum[i + 1])) // Fac un pas "normal"
        {
            nrpasi[i + 1] = nrpasi[i] + 1;
            sum[i + 1] = sum[i];
        }
        if (apa[i]) // Daca este apa pe treapta i
            for (q = 1; q <= apa[i] && i + q <= N; q++) // Beau q dl de apa
                if (cmp(nrpasi[i] + 1, sum[i], nrpasi[i + q], sum[i + q]))
                {
                    nrpasi[i + q] = nrpasi[i] + 1;
                    sum[i + q] = sum[i];
                }
        if (suc[i]) // Daca este suc pe treapta i
            for (q = 1; q <= 2 * suc[i] && i + q <= N; q++) // Beau q dl de apa
                if (cmp(nrpasi[i] + 1, sum[i] + ((q + 1) / 2), nrpasi[i + q], sum[i + q]))
                {
                    nrpasi[i + q] = nrpasi[i] + 1;
                    sum[i + q] = sum[i] + ((q + 1) / 2);
                }
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
