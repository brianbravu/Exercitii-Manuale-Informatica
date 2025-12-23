// Secvente.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define INFILE "secv.in"
#define OUTFILE "secv.out"
#define MAXN 10000

int b[MAXN + 1], sol[MAXN + 1], stiu[MAXN + 1];
int n, M;
int main()
{
    int i, temp, templ, max;
    // Citire
    ifstream fin(INFILE);
    fin >> n >> M;
    for (i = 1; i <= n; i++) fin >> b[i];
    for (i = 0; i < M; i++)
    {
        fin >> temp >> templ;
        sol[temp] = templ;
        stiu[templ] = 1;
    }
    fin.close();
    int curent = 1, inceput, w, j, ok = 1;
    while (curent <= n && ok)
    {
        inceput = curent;
        while (!b[curent] && curent <= n) curent++;
        if (curent > n) ok = 0;
        // Secventa de la inceput la curent este o permutare a valorilor de la inceput la sfarsit
        for (w = inceput, j = curent; j >= inceput; j--)
            if (!stiu[j])
            {
                while (sol[w]) w++;
                sol[w] = j;
            }
        curent++;
    }
    ofstream fout(OUTFILE);
    if (!ok) fout << "IMPOSIBIL\n";
    else
    {
        // Verific
        for (max = 0, i = 1; i < n && ok; i++)
        {
            if (sol[i] > max) max = sol[i];
            if (b[i] && max != i) ok = 0;
            if (!b[i] && max == i) ok = 0;
        }
        if (!ok) fout << "IMPOSIBIL\n";
        else
        {
            for (i = 1; i < n; i++) fout << sol[i] << ' ';
            fout << sol[n] << '\n';
        }
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
