// Numar divizori primi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    unsigned n, x, d, nr, i, oricare = 1;
    scanf_s("%u", &n);
	for (i = 1; i <= n; i++)
	{
		scanf_s("%u", &x); // Citesc o noua valoare
		nr = 0; // Initial, numarul de divizori primi ai lui x este egal cu 0
		d = 2; // Determin divizorii primi ai lui x
		while (x > 1)
		{
			if (x % d == 0) // Am descoperit un divizor
			{
				nr++; // Numar acel divizor prim, apoi il elimin din x, prin impartiri repetate
				while (x % d == 0) x /= d;
			}
			d++; // Caut ceilalti divizori primi mai departe
		}
		if (nr % 2 == 0) oricare = 0; // Deoarece am gasit o valoare cu un numar par de divizori primi
	}
	if (oricare) printf_s("DA\n");
	else printf_s("NU\n");
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
