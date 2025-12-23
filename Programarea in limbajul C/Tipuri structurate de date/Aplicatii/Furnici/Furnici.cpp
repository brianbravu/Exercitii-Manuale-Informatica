// Furnici.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define INFILE "furnici.in"
#define OUTFILE "furnici.out"
#define MaxF 10000 + 1
#define MaxLoc 10000 + 1
#define Infinit 200000000

long int l, m, n, nr_loc, maxL, maxR, rez = Infinit;
long int loc[MaxLoc];
int main()
{
    ifstream fin(INFILE);
    long int i, timp, st, dr, poz;
    fin >> l >> nr_loc; // Lungime tunel si numar locuri speciale
    for (i = 1; i <= nr_loc; i++) fin >> loc[i];
    fin >> m; // Cate furnici intra prin stanga
    maxL = 0; // Ultimul moment la care intra o furnica in stanga
    maxR = 0; // Ultimul moment la care intra o furnica in dreapta
    for (i = 1; i <= m; i++)
        // Retin timpul cand ultima furnica intra prin stanga
    {
        // Restul nu intereseaza
        fin >> timp;
        if (timp > maxL) maxL = timp;
    }
    fin >> n; // Cate furnici intra prin dreapta
    for (i = 1; i <= n; i++)
        // Retin timpul cand ultima furnica intra prin dreapta
    {
        // Restul nu intereseaza
        fin >> timp;
        if (timp > maxR) maxR = timp;
    }
    loc[0] = 0; // Primul loc special este 0 (intrarea din stanga)
    // Ultimul loc special este intrarea din dreapta
    loc[nr_loc + 1] = 1;
    fin.close();
    // Nu ne intereseaza decat ultimele furnici 
    // care intra in tunel prin stanga si prin dreapta,
    // deci pentru aceste doua furnici se face calculul timpului
    for (i = 0; i <= nr_loc + 1; i++)
    {
        // Pentru fiecare dintre locurile speciale 
        // determin timpul maxim
        // cand ajunge ultima furnica din stanga in acest loc
        st = maxL + loc[i];
        // si timpul maxim
        // cand ajunge ultima furnica din stanga in acest loc
        dr = maxR - loc[i] + l;
        // In acest loc se ajunge dupa poz secunde,
        // poz fiind maximul dintre furnica stanga si furnica dreapta
        if (st > dr) poz = st;
        else poz = dr;
        // Se adauga eventualul timp de asteptare
        // pana ajunge cealalta furnica
        if (loc[i] > l - loc[i]) poz = poz + loc[i];
        else poz = poz + l - loc[i];
        // Se retine minimul pana in acest moment
        if (poz < rez) rez = poz;
    }
    // Afisare
    ofstream fout(OUTFILE);
    fout << rez << '\n';
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
