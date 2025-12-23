// Ecuatia de gradul al II-lea.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    double a, b, c, d;
    scanf_s("%lf %lf %lf", &a, &b, &c);
    d = b * b - 4 * a * c; // Calculam discriminantul
    if (d < 0) printf_s("Ecuatia nu are radacini reale\n");
    else if (!d) printf_s("x1=x2=%.2lf\n", -b / (2 * a));
    else // d>0
        printf_s("x1=%.2lf x2=%.2lf\n", (-b + sqrt(d)) / (2 * a), (-b - sqrt(d)) / (2 * a));
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
