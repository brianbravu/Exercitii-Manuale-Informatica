// Reactivi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;

ifstream fin("react.in");
ofstream fout("react.out");
int N;
int ti[8000]; // ti[i] = temperatura minima pentru reactivul i
int tf[8000]; // tf[i] = temperatura maxima pentru reactivul i
int main()
{
    int nf, poz, miny, maxx, max, i, j, icx, icy;
    // Citire
    fin >> N;
    for (i = 0; i < N; i++) fin >> ti[i] >> tf[i];
    fin.close();
    // Sortare prin selectia maximului
    for (i = N - 1; i > 0; i--)
    {
        for (poz = i, j = 0; j < i; j++)
            if (ti[j] > ti[poz] || ti[j] == ti[poz] && tf[j] < tf[poz]) poz = j;
        max = ti[poz];
        ti[poz] = ti[i];
        ti[i] = max;
        max = tf[poz];
        tf[poz] = tf[i];
        tf[i] = max;
    }
    // Deschidem un frigider si plasam primul reactiv
    nf = 1; // nf = numarul de frigidere deschise
    icx = ti[0]; // icx = temperatura minima de functionare a frigiderului curent
    icy = tf[0]; // icy = temperatura maxima de functionare a frigiderului curent
    // Parcurg ceilalti reactivi in ordine
    for (i = 1; i < N; i++)
    {
        // Verificam daca intervalul curent icx, icy
        // se intersecteaza cu intervalul de temperatura al reactivului i
        miny = icy;
        if (miny > tf[i]) miny = tf[i];
        maxx = icx;
        if (maxx < ti[i]) maxx = ti[i];
        if (maxx <= miny)
            // Actualizez intervalul de temperatura
        {
            icx = maxx;
            icy = miny;
        }
        else // Deschid un nou frigider
        {
            nf++;
            icx = ti[i];
            icy = tf[i];
        }
    }
    fout << nf << '\n';
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
