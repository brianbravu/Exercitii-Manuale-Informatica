// Paragrafare optimala.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define InFile "text.in"
#define OutFile "text.out"
#define NMax 101
#define MMax 51
#define p3(x) ((x)*(x)*(x))

int N, M;
int slg[NMax];
char c[NMax][MMax];
long cost[NMax], ultim[NMax];

void citire();
void dinamica();
void afisare();

int main()
{
    citire();
    dinamica();
    afisare();
}

void citire()
{
    int i;
    ifstream fin(InFile);
    fin >> N >> M;
    fin.get();
    for (i = 1; i <= N; i++)
    {
        fin.getline(c[i], MMax);
        slg[i] = slg[i - 1] + strlen(c[i]);
    }
    fin.close();
}

void dinamica()
{
    int i, j;
    cost[N] = 0; ultim[N] = N;
    for (i = N - 1; i > 0; i--)
        if (slg[N] - slg[i - 1] + N - i <= M) // Cuvintele i, i+1, ..., N incap pe ultima linie
        {
            cost[i] = 0; ultim[i] = N;
        }
        else // Cuvantul i este plasat singur pe o linie
        {
            cost[i] = p3(M - slg[i] + slg[i - 1]) + cost[i + 1];
            ultim[i] = i;
            for (j = i + 1; j < N; j++) // Plasam cuvintele i, ..., j pe aceeasi linie
            {
                if (slg[j] - slg[i - 1] + j - i > M) // Daca nu incap
                    break;
                if (cost[i] > cost[j + 1] + p3(M - (slg[j] - slg[i - 1] + j - i)))
                {
                    cost[i] = cost[j + 1] + p3(M - (slg[j] - slg[i - 1] + j - i));
                    ultim[i] = j;
                }
            }
        }
}

void afisare()
{
    int i, poz;
    ofstream fout(OutFile);
    fout << cost[1] << endl;
    poz = 0; // Ultimul cuvant afisat
    while (poz + 1 <= N)
    {
        for (i = poz + 1; i < ultim[poz + 1]; i++)
            fout << c[i] << ' ';
        fout << c[ultim[poz + 1]] << endl;
        poz = ultim[poz + 1];
    }
    fout.close();
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
