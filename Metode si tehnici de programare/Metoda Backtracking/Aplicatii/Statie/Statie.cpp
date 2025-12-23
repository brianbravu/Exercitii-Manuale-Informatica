// Statie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define Infinit 99999

typedef struct // Structura unei camere
{
    long nr, // Numarul de persoane
        pers[2]; // Cele (maximum) 2 persoane (greutatile)
} camera;

long pers[10];
camera cam[5], best_cam[5];
int nr_cam, nr_pers;
long best_Cdez = Infinit, medie;

// long abs(long x)
// {
//     if (x < 0) return -x;
//     return x;
// }

long calc_Cdez(void) // Calculeaza coef. de dezechilibru
{
    long Cdez = 0;
    int i, j;
    for (i = 0; i < nr_cam; i++)
        Cdez += abs((nr_cam * (cam[i].pers[0] + cam[i].pers[1])) - medie);
    return (Cdez);
}

void citire(void)
{
    int i;
    FILE* inp;
    errno_t err = fopen_s(&inp, "statie.in", "r");
    fscanf_s(inp, "%d %d", &nr_cam, &nr_pers);
    medie = 0;
    for (i = 0; i < 5; i++) // Initializeaza cu 0 toate camerele
    {
        cam[i].nr = 0; // Numarul de persoane
        cam[i].pers[0] = 0; // Persoana 1
        cam[i].pers[1] = 1; // Persoana 2
    }
    for (i = 0; i < nr_pers; i++) // Greutatile persoanelor
    {
        fscanf_s(inp, "%d ", &(pers[i]));
        medie += pers[i]; // Se calculeaza si suma greutatilor
    }
    fclose(inp);
}

void calcul(int k)
{
    long temp;
    int i, j;
    if (k == nr_pers) // Daca le-am repartizat pe toate
    {
        temp = calc_Cdez(); // Calculez coef de dezechilibru
        if (temp < best_Cdez) // Daca e mai bun
            best_Cdez = temp; // Il retinem
    }
    else // Nu i-am repartizat pe toti
        for (j = 0; j < nr_cam; j++) // Parcurg toate camerele si
            if (cam[j].nr < 2) // Daca in camera j mai e loc
            {
                cam[j].pers[cam[j].nr] = pers[k]; // Pun pers. k aici
                cam[j].nr++; // Numar inca o persoana
                calcul(k + 1); // Trec la persoana urmatoare
                cam[j].nr--; // Revin, scad numarul de persoane
                cam[j].pers[cam[j].nr] = 0; // Greutatea la loc e 0
            }
}

void afisare(void)
{
    FILE* g;
    errno_t err = fopen_s(&g, "statie.out", "w");
    fprintf_s(g, "%5.3f\n", ((float)(best_Cdez)) / ((float)nr_cam));
    fclose(g);
}

int main()
{
    citire();
    calcul(0);
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
