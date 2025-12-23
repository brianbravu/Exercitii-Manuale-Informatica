// Media aritmetica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    double a, s = 0;
    int n, i = 0, nr = 0;
    scanf_s("%d", &n);
    while (i < n) // Cat timp nu am citit toate cele n valori
    {
        scanf_s("%lf", &a); // Citesc o noua valoare
        i++; // Numar valoarea citita
        if (a > 0) // Valoarea este strict pozitiva
        {
            s += a; // O adun la suma
            nr++; // O numar
        }
    }
    if (nr) printf_s("Media aritmetica este %.2lf\n", s / nr);
    else printf_s("Media aritmetica nu se poate calcula\n"); 
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
