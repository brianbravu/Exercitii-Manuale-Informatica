// Restaurarea unui apel de functie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define NrMaxF 100

char NF[NrMaxF]; // NF contine numele fiecarii functii
char s[100]; // sirul care trebuie restaurat
int AF[NrMaxF]; // AF contine aritatea functiilor
int NrF; // NrF - numarul de functii

void Citire();
int AR(char);
void Restaurare(int&);

int main()
{
    int i = 0;
    Citire();
    Restaurare(i);
}

void Citire()
{
    ifstream f("f.in");
    char c;
    int a;
    f.getline(s, 100);
    while (!f.eof())
    {
        f >> c >> a;
        NF[NrF] = c; AF[NrF++] = a;
    }
    f.close();
}

int AR(char c)
{
    // functia intoarce 0 daca c nu este un nume de functie,
    // respectiv aritatea functiei, in caz contrar
    for (int j = 0; j < NrF; j++)
        if (NF[j] == c) return AF[j];
    return 0;
}

void Restaurare(int& i)
{
    cout << s[i];
    int k = AR(s[i++]);
    if (k) // s[i] reprezinta un nume de functie
    {
        cout << '(';
        for (int j = 1; j < k; j++)
        {
            Restaurare(i); // restauram argumentele functiei
            cout << ','; // separandu-le prin virgule
        }
        Restaurare(i);
        cout << ')';
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
