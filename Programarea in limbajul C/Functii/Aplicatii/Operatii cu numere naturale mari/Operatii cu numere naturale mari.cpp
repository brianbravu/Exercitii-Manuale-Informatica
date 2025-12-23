// Operatii cu numere naturale mari.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define Lg 200
typedef char NrMare[Lg];

void citire(NrMare x, int& nx)// Citirea unui numar mare
{
    int i;
    char s[Lg + 1];
    cin >> s;
    nx = strlen(s); // Determin numarul de cifre
    for (i = nx - 1; i > -1; i--) x[nx - i - 1] = s[i] - '0';
    for (i = nx; i < Lg; i++) x[i] = 0;
}

void afisare(NrMare x, int nx) // Afisarea unui numar mare
{
    for (int i = nx - 1; i > -1; i--) cout << int(x[i]);
    cout << '\n';
}

void suma(NrMare a, int na, NrMare b, int nb, NrMare s, int& ns) // Suma a doua numere mari: s=a+b
{
    int i, cifra, t = 0, max; // Completam numarul cel mai mic cu zerouri nesemnificative
    if (na < nb)
    {
        max = nb;
        for (i = na; i < nb; i++) a[i] = 0;
    }
    else
    {
        max = na;
        for (i = nb; i < na; i++) b[i] = 0;
    }
    for (i = 0; i < max; i++)
    {
        cifra = a[i] + b[i] + t;
        s[i] = cifra % 10;
        t = cifra / 10;
    }
    if (t) s[i++] = t;
    ns = i;
}

void dif(NrMare a, int na, NrMare b, int nb, NrMare d, int& nd) // Diferenta a doua numere mari: d=a-b
{
    int i, t = 0;
    for (i = 0; i < na; i++)
    {
        d[i] = a[i] - b[i] + t;
        if (d[i] < 0)
        {
            d[i] += 10;
            t = -1;
        }
        else t = 0;
    }
    i--;
    while (i && !d[i]) i--;
    nd = i + 1;
}

void produs(NrMare a, int na, NrMare b, int nb, NrMare p, int& np) // Produsul a doua numere mari: p=a*b
{
    int i, j, t, cifra;
    for (i = 0; i < Lg; i++) p[i] = 0;
    for (i = 0; i < nb; i++)
    {
        for (t = j = 0; j < na; j++)
        {
            cifra = p[i + j] + a[j] * b[i] + t;
            p[i + j] = cifra % 10;
            t = cifra / 10;
        }
        if (t) p[i + j] = t;
    }
    np = na + nb - 1;
    if (p[np]) np++;
}

int compara(NrMare a, int na, NrMare b, int nb) // Compararea a doua numere mari: functia returneaza -1 daca a<b; 0 daca a=b; 1 daca a>b
{
    int i;
    if (na < nb) return -1;
    if (nb < na) return 1;
    for (i = na - 1; i > -1 && a[i] == b[i]; i--);
    if (i < 0) return 0;
    if (a[i] < b[i]) return -1;
    return 1;
}

void p10(NrMare x, int& nx, int nr) // Inmultirea unui numar mare cu o putere a lui 10: inmulteste numarul mare x cu 10^nr
{
    int i;
    for (i = nx - 1; i > -1; i++) x[i + nr] = x[i];
    for (i = 0; i < nr; i++) x[i] = 0;
    nx += nr;
}

void div(NrMare a, int na, NrMare b, int nb, NrMare c, int& nc, NrMare r, int& nr) // Impartirea a doua numere mari: imparte pe a la b; c este catul; r este restul
{
    int i;
    nr = 0; 
    nc = na;
    for (i = na - 1; i > -1; i--)
    {
        p10(r, nr, 1);
        r[0] = a[i];
        c[i] = 0;
        while (compara(b, nb, r, nr) != 1)
        {
            c[i]++;
            dif(r, nr, b, nb, r, nr);
        }
    }
    while (!c[nc - 1] && nc > 1) nc--;
    while (!r[nr - 1] && nr > 1) nr--;
}

int main()
{
    cout << "Hello World!\n";
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
