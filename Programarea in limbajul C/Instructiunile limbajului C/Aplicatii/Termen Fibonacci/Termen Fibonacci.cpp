// Termen Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int n, i, f0 = 1, f1 = 1, f2 = 1;
    scanf_s("%d", &n);
	for (i = 2; i <= n; i++)
	{
		f2 = f1 + f0; // Calculez termenul curent
		f0 = f1; // Ma deplasez in sir
		f1 = f2;
	}
	printf_s("Cel de-al %d-lea termen Fibonacci este %d\n", n, f2);
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
