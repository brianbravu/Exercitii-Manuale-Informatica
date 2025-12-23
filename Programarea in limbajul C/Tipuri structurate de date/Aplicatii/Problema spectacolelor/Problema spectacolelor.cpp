// Problema spectacolelor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int inceput[100], sfarsit[100], nr[100];
int main()
{
    int n, i, h, m, schimb, ultim, aux;
    cout << "n="; cin >> n; // Citire
    cout << "Introduceti inceputul si sfarsitul spectacolelor!\n";
    for (i = 0; i < n; i++)
    {
        nr[i] = i + 1; // Transform timpul in minute
        cin >> h >> m; inceput[i] = h * 60 + m;
        cin >> h >> m; sfarsit[i] = h * 60 + m;
    }
    // Ordonez spectacolele crescator dupa ora de final
    do
    {
        schimb = 0;
        for (i = 0; i < n - 1; i++)
            if (sfarsit[nr[i]] > sfarsit[nr[i + 1]])
            {
                aux = nr[i];
                nr[i] = nr[i + 1];
                nr[i + 1] = aux;
                schimb = 1;
            }
    } while (schimb);
    cout << "Spectacolele selectate sunt:\n" << nr[0] << ' ';
    for (ultim = 0, i = 1; i < n; i++)
        if (inceput[nr[i]] >= sfarsit[nr[ultim]])
        {
            cout << nr[i] << ' ';
            ultim = i;
        }
    cout << '\n';
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
