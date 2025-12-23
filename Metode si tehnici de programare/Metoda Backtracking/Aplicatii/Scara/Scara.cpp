// Scara.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iomanip>
using namespace std;
#define InFile "scara.in"
#define OutFile "scara.out"
#define NMax 101
#define HMax 101

int sol[NMax], solmin[NMax], uz[HMax], htot;
double ef[NMax], efmin; // ef[i] = efortul minim cu care urc primele i trepte din sol
int N, H, p, M;

void Citire();
void Gen(int);
void Afisare();
double efort();

int main()
{
    Citire();
    efmin = (double)H * N + 1;
    Gen(1);
    Afisare();
}

void Citire()
{
    ifstream fin(InFile);
    fin >> H >> N >> M >> p;
    fin.close();
}

void Afisare()
{
    int i;
    ofstream fout(OutFile);
    fout << setprecision(2) << efmin << endl;
    for (i = 1; i < N; i++)
        fout << solmin[i] << ' ';
    fout << solmin[N] << endl;
    fout.close();
}

double efort()
{
    int k, j;
    double x, sum;
    for (k = 1; k <= N; k++)
    {
        x = sol[k] + ef[k - 1]; // Urc cu efort minim primele k-1 trepte si apoi urc treapta k de inaltime i
        sum = sol[k];
        for (j = 2; k - j >= 0; j++)
        {
            // Urc deodata treptele k, k-1, ..., k-j+1, daca suma inaltimilor este <=M; in sum calculez suma inaltimilor
            sum += sol[k - j + 1];
            if (sum > M) break;
            if (sum / j + p + ef[k - j] < x)
                x = sum / j + ef[k - j] + p;
        }
        ef[k] = x;
    }
    return ef[N];
}

void Gen(int k)
{
    int i;
    double x;
    if (k == N + 1)
    {
        if (htot == H)
        {
            x = efort();
            if (x < efmin && efmin - x > 0.001)
            {
                efmin = x;
                for (i = 1; i <= N; i++) solmin[i] = sol[i];
            }
        }
    }
    else for (i = 1; i <= H && htot + i <= H && i <= M; i++)
        if (!uz[i])
        {
            // Care ar fi efortul minim daca as pune inaltimea treptei k=i?
            sol[k] = i; htot += i; uz[i] = 1;
            Gen(k + 1);
            uz[i] = 0;
            htot -= i;
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
