// Windows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define INPUT_FILE "win.in"
#define OUTPUT_FILE "win.out"
#define NMAX 100

int N; // N reprezinta numarul de ferestre
struct { int ls, ld, cs, cd; } f[NMAX]; // f - vector cu N componente in care retinem ferestrele
int inchisa[NMAX]; // inchisa[i] = 0 daca fereastra i e deschisa, respectiv 1 daca fereastra i este inchisa
int rez; // rez - variabila globala in care calculam numarul total de click-uri ramase

void citire(void)
{
    FILE* fin;
    errno_t err = fopen_s(&fin, INPUT_FILE, "rt");
    fscanf_s(fin, "%d", &N);
    for (int i = 0; i < N; i++) fscanf_s(fin, "%d %d %d %d", &f[i].ls, &f[i].cs, &f[i].ld, &f[i].cd);
    fclose(fin);
}

int peste(int a, int b)
{
    // functia returneaza valoarea 1
    // daca fereastra a este peste coltul din dreapta-sus al ferestrei b
    // si 0 in caz contrar
    if (f[a].ls <= f[b].ls && f[a].ld >= f[b].ls && f[a].cs <= f[b].cd && f[a].cd >= f[b].cd) return 1;
    return 0;
}

void inchide(int nr)
{
    // functia inchide fereastra cu numarul nr
    for (int i = N - 1; i >= nr + 1; i--)
        if (!inchisa[i] && peste(i, nr)) inchide(i);
    inchisa[nr] = 1;
    rez++;
}

void rezolvare(void)
{
    for (int i = 0; i < N; i++) inchisa[i] = 0;
    rez = 0;
    inchide(0);
}

void afisare(void)
{
    FILE* fout;
    errno_t err = fopen_s(&fout, OUTPUT_FILE, "wt");
    fprintf_s(fout, "%d\n", rez);
    fclose(fout);
}

int main()
{
    citire();
    rezolvare();
    afisare();
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
