// Palindrom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define LgMax 101
#define InFile "pal.in"
#define OutFile "pal.out"

char s[LgMax];
int Lg;
int rez;
FILE* file;

void citire(void)
{
    errno_t err = fopen_s(&file, InFile, "rt");
    fgets(s, LgMax, file); Lg = strlen(s);
    fclose(file);
}

int palindrom(int inceput, int sfarsit)
{
    while (inceput < sfarsit)
    {
        if (s[inceput] != s[sfarsit]) return 0;
        inceput++; sfarsit--;
    }
    return 1;
}

void dinamic(void)
{
    int i, j, nrp[LgMax], nrmin;
    for (i = 0; i < Lg; i++)
        if (palindrom(0, i)) nrp[i] = 1;
        else
        {
            nrmin = LgMax + 2;
            for (j = 0; j < i; j++)
                if (palindrom(j + 1, i) && nrp[j] < nrmin)
                    nrmin = nrp[j];
            nrp[i] = nrmin + 1;
        }
    rez = nrp[Lg - 1] - 1;
}

void afisare(void)
{
    errno_t err = fopen_s(&file, OutFile, "wt");
    fprintf_s(file, "%d\n", rez);
    fclose(file);
}

int main()
{
    citire();
    dinamic();
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
