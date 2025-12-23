// Suma de doua numere prime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, a, rad, d, prim, exista, VMax, oricare = 1;
    cout << "VMax = "; cin >> VMax;
	for (n = 4; n <= VMax && oricare; n++)
	{
		for (exista = 0, a = 2; a <= n / 2 && !exista; a++)
		{
			// Testam daca a este prim
			prim = 1;
			if (a > 2 && a % 2 == 0) prim = 0;
			else for (rad = sqrt(a), d = 3; prim && d <= rad; d += 2)
				if (a % d == 0) prim = 0;
			if (prim)
			{
				// Testam daca n - a este prim
				prim = 1;
				if (n - a > 2 && (n - a) % 2 == 0) prim = 0;
				else for (rad = sqrt(n - a), d = 3; prim && d <= rad; d += 2)
					if ((n - a) % d == 0) prim = 0;
				if (prim) exista = 1; // Am gasit o varianta
			}
		}
		if (!exista) oricare = 0;
	}
	if (oricare) cout << "Proprietatea este verificata\n";
	else
	{
		cout << "Proprietatea nu este verificata\n";
		cout << "Pentru n = " << --n << " nu exista solutie\n";
	}
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
