// Manna-Pnueli.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define DimMax 100

int S[DimMax], x, y, V;
int main()
{
    cout << "x = "; cin >> x;
    S[V] = x; // Initializam stiva cu parametrul primului apel
	while (V >= 0)
	{
		y = S[V];
		if (y >= 12) // Calculam valoarea functiei direct
		{
			// Plasam in stiva valoarea calculata a functiei
			if (--V >= 0) S[V] = y - 1;
		}
		else 
			// Functia nu poate fi calculata direct, 
			// deci inseram in stiva si parametrul noului apel
			S[++V] = y + 2;
	}
		cout << "f (" << x << ") = " << y - 1;
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
