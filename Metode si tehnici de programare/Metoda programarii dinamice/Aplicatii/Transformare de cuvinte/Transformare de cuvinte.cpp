// Transformare de cuvinte.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <cstring>
using namespace std;
#define DMax 101
#define COPY 0
#define DELETE 1
#define INSERT 2
#define REPLACE 3
#define TWIDDLE 4
#define KILL 5

int n, m;
int cost[6];
int op[DMax][DMax], cm[DMax][DMax];
char X[DMax], Y[DMax];
void Citire();
void Rezolvare();
void Afisare();

int main()
{
    Citire();
    Rezolvare();
    Afisare();
}

void Citire()
{
    int i;
    ifstream fin("sir.in");
    fin.getline(X, DMax); m = strlen(X);
    fin.getline(Y, DMax); n = strlen(Y);
    for (i = 0; i < 6; i++) fin >> cost[i];
    fin.close();
}

void Rezolvare()
{
    int i, j;
    for (j = 0; j < n; j++) // Initializare
    {
        cm[m][j] = (n - j) * cost[INSERT]; op[m][j] = INSERT;
    }
    for (i = 0; i < m; i++)
    {
        cm[i][n] = cost[KILL]; op[i][n] = KILL;
        if (cm[i][n] > (m - i) * cost[DELETE])
        {
            cm[i][n] = (m - i) * cost[DELETE]; op[i][n] = DELETE;
        }
    }
    cm[n][m] = 0;
    for (i = m - 1; i >= 0; i--)
        for (j = n - 1; j >= 0; j--)
        {
            cm[i][j] = cost[KILL] + cm[m][j]; op[i][j] = KILL;
            if (X[i] == Y[j] && cm[i][j] > cost[COPY] + cm[i + 1][j + 1])
            {
                cm[i][j] = cost[COPY] + cm[i + 1][j + 1];
                op[i][j] = COPY;
            }
            if (cm[i][j] > cost[DELETE] + cm[i + 1][j])
            {
                cm[i][j] = cost[DELETE] + cm[i + 1][j];
                op[i][j] = DELETE;
            }
            if (cm[i][j] > cost[INSERT] + cm[i][j + 1])
            {
                cm[i][j] = cost[INSERT] + cm[i][j + 1];
                op[i][j] = INSERT;
            }
            if (cm[i][j] > cost[REPLACE] + cm[i + 1][j + 1])
            {
                cm[i][j] = cost[REPLACE] + cm[i + 1][j + 1];
                op[i][j] = REPLACE;
            }
            if (i < m - 1 && j < n - 1 && X[i] == Y[j + 1] && X[i + 1] == Y[j] && cm[i][j] > cost[TWIDDLE] + cm[i + 2][j + 2])
            {
                cm[i][j] = cost[TWIDDLE] + cm[i + 2][j + 2];
                op[i][j] = TWIDDLE;
            }
        }
}

void Afisare()
{
    int i, j;
    ofstream fout("sir.out");
    fout << cm[0][0] << endl;
    i = 0; j = 0;
    while (i < m || j < n)
        switch (op[i][j])
        {
        case COPY: fout << "COPY\n"; i++; j++; break;
        case DELETE: fout << "DELETE\n"; i++; break;
        case INSERT: fout << "INSERT\n"; j++; break;
        case REPLACE: fout << "REPLACE\n"; i++; j++; break;
        case TWIDDLE: fout << "TWIDDLE\n"; i+=2; j+=2; break;
        case KILL: fout << "KILL\n"; i = m; break;
        default:
            break;
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
