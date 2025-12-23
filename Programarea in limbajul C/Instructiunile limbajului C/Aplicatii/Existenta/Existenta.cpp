// Existenta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int n, p, a, exista = 0, i;
    scanf_s("%d %d", &n, &p);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%d", &a); // Citesc un nou termen
		if (a % p == 0) // Am descoperit un multiplu
			exista = 1;
	}
	if (exista) printf_s("Exista cel putin un multiplu al lui %d", p);
	else printf_s("Nu exista niciun multiplu al lui %d", p);
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
