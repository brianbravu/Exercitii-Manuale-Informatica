// Secventa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int n, a, b, nr, i;
    scanf_s("%d", &n); // 1
    scanf_s("%d", &a); // 2
    i = 1; nr = 0; // 3
    while (i<n) //4
    {
        scanf_s("%d", &b); //5
        i++; //6
        if (b % a == 0) nr++; //7
        a = b; //8
    }
    printf_s("nr=%d\n", nr); // 9
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
