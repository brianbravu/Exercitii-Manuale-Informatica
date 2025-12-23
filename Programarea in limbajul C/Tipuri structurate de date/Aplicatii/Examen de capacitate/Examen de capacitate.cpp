// Examen de capacitate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    struct Elev {
        char np[40];
        float r, m, ig, mg;
    };
    struct Elev Ex[1000], aux;
    int n, i, schimb;
    cout << "n="; cin >> n;
    cout << "Introduceti informatiile despre elevi!\n";
    for (i = 0; i < n; i++)
    {
        cout << "Numele si prenumele: ";
        cin.get();
        cin.getline(Ex[i].np, 40);
        cout << "Notele (R/M/IG): ";
        cin >> Ex[i].r >> Ex[i].m >> Ex[i].ig;
    }
    // Calculam mediile generale
    for (i = 0; i < n; i++)
        Ex[i].mg = (Ex[i].r + Ex[i].m + Ex[i].ig) / 3;
    // Ordonez elevii alfabetic
    do
    {
        schimb = 0;
        for (i = 0; i < n - 1; i++)
            if (strcmp(Ex[i].np, Ex[i + 1].np) > 0)
            {
                aux = Ex[i];
                Ex[i] = Ex[i + 1];
                Ex[i + 1] = aux;
                schimb = 1;
            }
    } while (schimb);
    // Afisez
    for (i = 0; i < n; i++) cout << Ex[i].np << ' ' << Ex[i].mg << '\n';
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
