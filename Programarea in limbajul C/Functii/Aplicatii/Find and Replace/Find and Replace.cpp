// Find and Replace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

ifstream f;
ofstream g;
char c, s1[200], s2[200], buffer[200], ns[100], nd[100];
int lbuffer, ls1, ls2;

void Citire()
{
    cout << "Numele fisierului sursa: "; cin.getline(ns, 100);
    cout << "Numele fisierului modificat: "; cin.getline(nd, 100);
    cout << "Sirul cautat: "; cin.getline(s1, 200);
    cout << "Sirul cu care se inlocuieste: "; cin.getline(s2, 200);
}

void UmpleBuffer()
{
    int i = 1;
    char c[2];
    c[1] = buffer[0] = NULL;
    while ((i++ <= lbuffer) && !f.eof())
    {
        f.get(c[0]);
        strcat_s(buffer, c);
    }
}

void Initializare()
{
    f.open(ns); g.open(nd);
    lbuffer = ls1 = strlen(s1); ls2 = strlen(s2); // lbuffer - lungimea bufferului de intrare a caracterelor
    UmpleBuffer();
}

void Stanga(char* b, char& stanga, int lg) // Muta caracterele din buffer cu o pozitie la stanga
{
    stanga = b[0];
    for (int i = 1; i < lg; i++) b[i - 1] = b[i];
}

int main()
{
    Citire();
    Initializare();
    while(!f.eof())
        if (!strcmp(buffer, s1)) // Daca am gasit cuvantul s1, scriem s2 in destinatie
        {
            g << s2;
            UmpleBuffer(); // Reumplem bufferul
        }
        else // Scriem la destinatie primul caracter din buffer
        {
            Stanga(buffer, c, lbuffer);
            g << c;
            if (!f.eof())
                f.get(buffer[lbuffer - 1]); // Citim un caracter in buffer
            else // Nu mai putem umple bufferul
                strncpy_s(buffer, buffer, lbuffer - 1);
        }
    g << buffer; // Scriem bufferul la destinatie
    f.close(); g.close();
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
