// Problema SL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Stiva.h"
#include <string>
using namespace std;
#define NMAX 1000
ifstream fin("sl.in");
ofstream fout("sl.out");

int n;
string P[NMAX];
Stiva<int>S;
int R = 0;

void citire();
int executie();

int main()
{
    citire();
    fout << executie() << '\n';
    fout.close();
    return 0;
}

void citire()
{
    char c;
    fin >> n; fin.get(c);
    for (int i = 0; i < n; i++) getline(fin, P[i], '\n');
}

int executie()
{
    int i, a, b, poz;
    string op, snr;
    for (i = 0; i < n; i++)
    {
        poz = P[i].find(' ');
        op = P[i].substr(0, poz);
        if (op == "PUSH")
        {
            snr = P[i].substr(poz + 1);
            S.Push(stoi(snr));
            continue;
        }
        if (op == "STORE")
        {
            R = S.Pop();
            continue;
        }
        if (op == "LOAD")
        {
            S.Push(R);
            continue;
        }
        if (op == "PLUS")
        {
            a = S.Pop();
            b = S.Pop();
            S.Push(a + b);
            continue;
        }
        if (op == "TIMES")
        {
            a = S.Pop();
            b = S.Pop();
            S.Push(a * b);
            continue;
        }
        if (op == "IFZERO")
        {
            if (S.Top() == 0)
            {
                snr = P[i].substr(poz + 1);
                i = stoi(snr) - 1;
                continue;
            }
        }
        if (op == "DONE")
        {
            return S.Top();
        }
    }
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
