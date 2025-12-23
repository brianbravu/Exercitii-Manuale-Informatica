// Problema taieturilor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NMaxGauri 20

int n; // numarul de gauri
int x[NMaxGauri], y[NMaxGauri]; // coordonatele gaurilor
int Lp, Hp, Amax, lMax, hmax, xmax, ymax;

void Citire()
{
    ifstream fin("placa.in");
    fin >> Lp >> Hp >> n;
    for (int i = 0; i < n; i++) fin >> x[i] >> y[i];
    fin.close();
}

int Interior(int i, int xs, int ys, int l, int h)
{
    // intoarce 1 daca gaura i este in interiorul dreptunghiului
    // cu coltul stanga-jos (xs,ys), lungimea l si inaltimea h
    if ((x[i] > xs) && (x[i] < xs + 1) && (y[i] > ys) && (y[i] < ys + h))
        return 1;
    return 0;
}

void Taie(int xs, int ys, int l, int h)
{
    int i = 0;
    // caut o gaura in placa
    while ((i < n) && !Interior(i, xs, ys, l, h)) i++;
    if (i == n) // placa nu are gauri
    {
        if (l * h > Amax)
            Amax = l * h, lMax = l, hmax = h, xmax = xs, ymax = ys;
    }
    else // taiem placa prin gaura i
    {
        Taie(xs, ys, l, y[i] - ys); // orizontal
        Taie(xs, y[i], l, ys + h - y[i]);
        Taie(xs, ys, x[i] - xs, h); // vertical
        Taie(x[i], ys, xs + l - x[i], h);
    }
}

int main()
{
    Citire();
    Taie(0, 0, Lp, Hp);
    cout << "Placa de arie maxima are coltul stanga-jos (";
    cout << xmax << ", " << ymax << ")\n";
    cout << "Lungimea=" << lMax << "; inaltimea=" << hmax << endl;
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
