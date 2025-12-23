// Latime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define infile "latime.in"
#define outfile "latime.out"

int arb[1000][2]; // arb[a][0]=fiul stang al nodului a; arb[a][1]=fiul drept al nodului a
int col[1000]; // col[i]+1=coloana in care va fi desenat nodul i
int min[1000]; // min[i]=coloana cea mai din stanga pe care se afla un nod de pe nivelul i
int max[1000]; // max[i]=coloana cea mai din dreapta pe care se afla un nod de pe nivelul i
int num; // Numarul de noduri din arbore
int lat, niv;

void citire(void);
void rezolva(void);
void afisare(void);

int main()
{
    citire();
    rezolva();
    afisare();
}

void citire(void)
{
    FILE* fp;
    errno_t err = fopen_s(&fp, infile, "r");
    int a, i;
    fscanf_s(fp, "%d", &num);
    for (i = 0; i < num; i++)
    {
        min[i] = 0x7fffffff;
        max[i] = 0;
    }
    for (i = 0; i < num; i++)
    {
        fscanf_s(fp, "%d", &a);
        a--;
        fscanf_s(fp, "%d %d", &arb[a][0], &arb[a][1]);
        if (arb[a][0] > 0) arb[a][0]--;
        if (arb[a][1] > 0) arb[a][1]--;
    }
    fclose(fp);
}

int nr = 0;
void parcurgere(int x, int nivx)
{
    if (arb[x][0] != -1) // Nodul x are fiu stang?
        parcurgere(arb[x][0], nivx + 1); // Parcurg arborele stang
    if (min[nivx] > nr) min[nivx] = nr; // Compar coloana lui x cu coloana cea mai din stanga,
    if (max[nivx] < nr) max[nivx] = nr; // respectiv cu coloana cea mai din dreapta de pe nivelul nivx
    col[x] = nr++; // Coloana pe care se afla nodul x este 1+numarul de noduri parcurse inaintea lui x
    if (arb[x][0] != -1) // Nodul x are fiu drept?
        parcurgere(arb[x][0], nivx + 1); // Parcurg arborele drept
}

void rezolva()
{
    int i;
    parcurgere(0, 0);
    lat = -1;
    for (i = 0; i < num; i++)
        if (lat < max[i] - min[i])
        {
            lat = max[i] - min[i];
            niv = i;
        }
}

void afisare()
{
    FILE* fp;
    errno_t err = fopen_s(&fp, outfile, "w");
    fprintf_s(fp, "%d %d\n", niv + 1, lat + 1);
    fclose(fp);
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
