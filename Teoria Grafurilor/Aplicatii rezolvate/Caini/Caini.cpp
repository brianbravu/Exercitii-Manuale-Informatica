// Caini.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define InFile "caini.in"
#define OutFile "caini.out"
#define MAXN 14
#define DoiLa 8192
#define Inf 30000

typedef struct { int T[MAXN], mal; } Config;
FILE* out;
int c[DoiLa];
int G[MAXN][MAXN];
int n; // Numarul de caini
int max = -1; // Numarul maxim de caini astfel incat oricare doi sa nu se dusmaneasca
int nrc = 0; // Numarul de configuratii din c
int NrCaini = 0;
Config S;
int Dusman[MAXN];
int ConfigToNr(Config);
void NrToConfig(int, Config*);
void Succesor(int);
void CitGraf(void);
int NrMinMutari(int);
void Afisare(int, int);

int ConfigToNr(Config S)
{
    int rez = 0, i;
    for (i = n; i > 0; i--) rez = rez * 2 + S.T[i];
    return rez * 2 + S.mal;
}

void NrToConfig(int k, Config* S)
{
    int i;
    S->mal = k % 2; k /= 2;
    for (i = 1; i <= n; i++)
    {
        S->T[i] = k % 2;
        k /= 2;
    }
}

void Succesor(int k)
// Cand apelam Succesor(k) in vectorul S
// sunt fixate pozitiile 0, 1, ..., k-1
{
    int i;
    if (k > n) // Am obtinut o multime de caini
    {
        if (NrCaini > max)
            max = NrCaini;
        S.mal = 0;
        // O plasez pe malul 0, apoi pe malul 1
        // Si retin in c aceste configuratii
        c[nrc++] = ConfigToNr(S);
        S.mal = 1;
        c[nrc++] = ConfigToNr(S);
    }
    else // Generam in continuare
    {
        S.T[k] = 0;
        Succesor(k + 1);
        if (!Dusman[k])
            // Cainele k nu are dusmani in configuratia curenta
        {
            for (i = 1; i <= G[k][0]; i++)
                Dusman[G[k][i]]++;
            S.T[k] = 1;
            NrCaini++;
            Succesor(k + 1);
            for (i = 1; i <= G[k][0]; i++)
                Dusman[G[k][i]]--;
            NrCaini--;
        }
    }
}

void CitGraf()
{
    FILE* in;
    errno_t err = fopen_s(&in, InFile, "rt");
    int K, a, b, i;
    fscanf_s(in, "%d %d", &n, &K);
    for (i = 0; i < K; i++)
    {
        fscanf_s(in, "%d %d", &a, &b);
        G[a][0]++; G[a][G[a][0]] = b;
        G[b][0]++; G[b][G[b][0]] = a;
    }
    fclose(in);
}

int NrMinMutari(int maxloc)
// Functia returneaza
// numarul minim de transporturi cu o barca de maxloc locuri
// sau -1 daca nu este posibil
{
    int Dist[DoiLa], Q[DoiLa], p, u, i, k, j, start, cati;
    Config S, S1;
    // Dist[i] = numarul de transporturi efectuate pentru a ajunge din configuratia 0 in configuratia i
    // sau -1 daca nu este posibil sa ajungem de la configuratia 0 la configuratia 1
    for (i = 0; i < DoiLa; Dist[i++] = -1);
    Dist[0] = 0;
    // Parcurgem BFS incepand din configuratia 0, configuratia finala,
    // pana ajungem la configuratia 1, cea initiala
    Q[0] = 0; p = u = 0;
    // Q este coada, p indica primul element, iar u ultimul
    while (p <= u)
    {
        k = Q[p++]; // Extrag prima configuratie
        NrToConfig(k, &S);
        start = (S.mal) ? 0 : 1; // Celalalt mal
        for (i = start; i < nrc; i += 2)
            // Parcurg toate configuratiile care corespund
        {
            int k1 = c[i];
            NrToConfig(k1, &S1);
            if (Dist[k1] == -1)
            {
                // Verific daca se poate ajunge de la configuratia k1 la configuratia k intr-un singur transport,
                // folosind o barca cu maxloc locuri
                cati = 0;
                // Numar cati caini au fost transportati de pe malul configuratiei k1 pe malul configuratiei k
                for (j = 1; j <= n; j++)
                    if (S1.T[j])
                    {
                        if (S.T[j])
                        {
                            cati = Inf;
                            break;
                        }
                    }
                    else
                        if (!S.T[j]) cati++;
                if (cati <= maxloc)
                    // Incap in barca cainii transportati?
                {
                    Dist[k1] = Dist[k] + 1;
                    if (k1 == 1) return Dist[k1];
                    // Am transportat toti cainii
                    Q[++u] = k1;
                }
            }
        }
    }
    return -1;
}

void Afisare(int minmut, int minloc)
{
    int temp[DoiLa], i, j;
    FILE* out;
    errno_t err = fopen_s(&out, OutFile, "wt");
    fprintf_s(out, "%d %d\n", minloc, minmut);
    fclose(out);
}

int main()
{
    int t;
    CitGraf();
    // Generez toate configuratiile de caini care nu se ataca
    Succesor(1);
    t = NrMinMutari(n - max);
    if (t != -1) Afisare(t, n - max + 1);
    else Afisare(NrMinMutari(n - max + 1), n - max + 2);
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
