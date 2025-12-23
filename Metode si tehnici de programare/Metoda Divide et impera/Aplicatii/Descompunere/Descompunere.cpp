// Descompunere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMaxFiguri 100

int a, b, Nrmin, dmin[NMaxFiguri];

void Desc(int x, int y, int d[NMaxFiguri], int& n)
{
    int n1, n2, i, d1[NMaxFiguri], d2[NMaxFiguri];
	if ((y - x >= x) || (x == y)) // dreptunghi nedecompozabil
	{
		n = 1; d[0] = x; d[1] = y;
	}
	else
	{
		// descompunerea in prima variaanta
		if (y - x < 2 * x - y) Desc(y - x, 2 * x - y, d1, n1);
		else Desc(2 * x - y, y - x, d1, n1);
		// descompunerea in a doua varianta, daca este posibil
		if (x % 2 == 0)
			if (x < y - x / 2) Desc(x, y - x / 2, d2, n2);
			else Desc(y - x / 2, x, d2, n2);
		else n2 = NMaxFiguri;
		if (n1 <= n2)
		{
			n = n1 + 2; d[0] = x; d[1] = y - x;
			for (i = 2; i < n + 2; i++) d[i] = d1[i - 2];
		}
		else
		{
			n = n2 + 2; d[0] = x/2; d[1] = x/2;
			for (i = 2; i < n + 2; i++) d[i] = d1[i - 2];
		}
	}
}

int main()
{
	cout << "a, b (a<b) = "; cin >> a >> b;
	Desc(a, b, dmin, Nrmin);
	cout << "Numarul minim de figuri: " << Nrmin << endl;
	for (int i = 0; i < Nrmin + 1; i++) cout << dmin[i] << ' ';
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
