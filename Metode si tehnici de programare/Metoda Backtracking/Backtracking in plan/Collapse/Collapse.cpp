// Collapse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;
#define DMax 52
#define InFile "joc.in"
#define OutFile "joc.out"
#define Dir 4

int dl[] = { -1,0,1,0 };
int dc[] = { 0,-1,0,1 };

struct poz
{
    char cul; // Culoarea celulei
    int gr; // Numarul grupului din care face parte celula
};

poz T[DMax][DMax]; // Tabla de joc
int n, m, linmax, colmin, nrclic; // linmax si colmin reprezinta coordonatele celulei din unul dintre grupurile de dimensiune maxima, care se afla la cel mai in stanga-jos

void citire();
void afisare();
int prelucrare_tabla();
int det_grup(int, int, int, char);
void sterge_grup(int, int, int);
void refa_tabla(int, int);

int main()
{
    int dim;
    citire();
    do
    {
        linmax = 0; colmin = m + 1;
        dim = prelucrare_tabla();
        if (dim > 1)
        {
            nrclic++;
            refa_tabla(linmax, colmin);
        }
    } while (dim > 1);
    afisare();
}

void citire()
{
    int i, j;
    ifstream fin(InFile);
    fin >> n >> m; fin.get();
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            fin >> T[i][j].cul; fin.get();
        }
    // Bordare
    for (i = 0; i <= n + 1; i++)
        T[i][0].gr = T[i][m + 1].gr = DMax * DMax + 1;
    for (j = 0; j <= m + 1; j++)
        T[0][j].gr = T[n + 1][j].gr = DMax * DMax + 1;
    fin.close();
}

int det_grup(int grnum, int i, int j, char ch)
{
    int sum = 1, k;
    if (T[i][j].cul != ch) return 0;
    T[i][j].gr = grnum;
    for (k = 0; k < Dir; k++)
        if (T[i + dl[k]][j + dc[k]].gr == 0)
            sum += det_grup(grnum, i + dl[k], j + dc[k], ch);
    return sum;
}

int prelucrare_tabla() // Identifica toate grupurile si returneaza dimensiunea grupului maxim
{
    int maxdim = 0, dim, grnum = 1, i, j;
    for (j = 1; j <= m; j++)
        for (i = n; i >= 1; i--)
            if (T[i][j].gr == 0 && T[i][j].cul != ' ') // Aceasta celula nu apartine nici unui grup
            {
                dim = det_grup(grnum, i, j, T[i][j].cul); // Marcam grupul
                if (dim > maxdim)
                {
                    maxdim = dim; linmax = i; colmin = j;
                }
                else if (dim == maxdim)
                    if (j < colmin)
                    {
                        colmin = j; linmax = i;
                    }
                else if (j == colmin)
                    if (i > linmax) linmax = i;
                grnum++;
            }
    return maxdim;
}

void sterge_grup(int grnum, int i, int j)
{
    if (T[i][j].gr == grnum && T[i][j].cul != ' ')
    {
        T[i][j].cul = ' ';
        sterge_grup(grnum, i - 1, j);
        sterge_grup(grnum, i, j - 1);
        sterge_grup(grnum, i + 1, j);
        sterge_grup(grnum, i, j + 1);
    }
}

void refa_tabla(int lin, int col)
{
    int i, j, i2, j2;
    sterge_grup(T[lin][col].gr, lin, col);
    for (j = 1; j <= m; j++) // Prelucram coloana j
    {
        for (i = n; i >= 1; i--)
            if (T[i][j].cul == ' ')
            {
                for (i2 = i - 1; i2 >= 1 && T[i2][j].cul == ' '; i2--); // Caut mai sus un element colorat
                if (i2) // Am gasit
                {
                    T[i][j] = T[i2][j]; T[i2][j].cul = ' ';
                }
                else break;
            }
    }
    for (j = 1; j <= m; j++) // Eliminam coloanele goale
        if (T[n][j].cul == ' ') // Coloana j este vida
        {
            for (j2 = j + 1; j2 <= m && T[n][j2].cul == ' '; j2++); // Caut in dreapta o coloana vida
            if (j2 <= m) // Am gasit
                for (i = 1; i <= n; i++)
                {
                    T[i][j] = T[i][j2]; // Copiez coloana j2 peste coloana j
                    T[i][j2].cul = ' '; // Sterg coloana j2
                }
            else break;
        }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            T[i][j].gr = 0;
}

void afisare()
{
    ofstream fout(OutFile);
    fout << nrclic << endl;
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
