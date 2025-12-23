// Medii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

FILE* f, * g;
float media, nt;
int n[12], GASIT;

void afiseaza(int k)
{
    int i;
    for (i = 1; i <= k; i++)
        fprintf_s(g, "%d ", n[i]);
    fprintf_s(g, "\n");
    GASIT = 1; // Am gasit solutia
}

float media_calculata(int k)
{
    int i;
    float s, mn, mc;
    if (k > 2) // Are rost sa calculez doar daca am minimum 3 note
    {
        s = 0;
        for (i = 1; i <= k; i++) s += n[i]; // Suma notelor
        mn = s / k; // Media notelor
        mc = (nt + 3.0 * mn) / 4.0; // Media calculata
        return mc;
    }
    return 0;
}

void calculeaza(int k)
{
    int i;
    if (k < 11) // Daca nu am pus toate notele (maximum 10 aici)
    {
        for (i = n[k - 1]; i <= 10; i++) // Pun toate notele posibile
        {
            n[k] = i; // Pun nota i
            if (media_calculata(k) == media) // Daca media corespunde
                afiseaza(k); // Afiseaza
            calculeaza(k + 1); // Treci la nota urmatoare
            n[k] = 0; // Anuleaza ultima nota
        }
    }
}

int main()
{
    errno_t err;
    err = fopen_s(&f, "medii.in", "r");
    err = fopen_s(&g, "medii.out", "w+");
    fscanf_s(f, "%f %f", &media, &nt);
    GASIT = 0; // Nu am gasit nici o solutie
    n[0] = 1; // Ca sa plec de la nota 1
    calculeaza(1); // Pune notele incepand cu prima
    if (!GASIT) fprintf_s(g, "NU\n");
    fclose(f); fclose(g);
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
