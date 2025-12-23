// Triunghi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    unsigned int x, x0, x1, x2, x3;
    scanf_s("%u", &x);
    x0 = x % 10; // Retin cifra unitatilor
    x = x / 10; // Elimin cifra unitatilor
    x1 = x % 10; // Retin cifra zecilor
    x = x / 10; // Elimin cifra zecilor
    x2 = x % 10; // Retin cifra sutelor
    x = x / 10; // Elimin cifra sutelor
    x3 = x % 10; // Retin cifra miilor
    x = x / 10; // In x ramane cifra zecilor de mii
    printf_s("  %u\n", x2);
    printf_s(" %u%u%u\n", x3, x2, x1);
    printf_s("%u%u%u%u%u\n", x, x3, x2, x1, x0);
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
