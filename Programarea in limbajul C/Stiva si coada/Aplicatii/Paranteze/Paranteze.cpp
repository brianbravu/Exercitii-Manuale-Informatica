// Paranteze.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define DimMaxCoada 100

int C[DimMaxCoada];
int Inceput, Sfarsit = -1, LgMax, Corect = 1; // Corect este 1 daca parantezele se inchid corect
char p;
int main()
{
	do // Citesc caracterele, unul cate unul
	{
		p = cin.get();
		if (p == '(')
		{
			// Inserez o paranteza deschisa in coada
			C[++Sfarsit] = '(';
			if (Sfarsit - Inceput + 1 > LgMax)
				LgMax = Sfarsit - Inceput + 1;
		}
		else if (p == ')')
			// Verific daca pot extrage un element din coada
			if (Inceput <= Sfarsit) 
				Inceput++; // Extrag un element din coada
			else Corect = 0; // Parantezele nu se inchid corect
	} while (p != '.');
	if (Inceput <= Sfarsit) Corect = 0;
	// In coada au mai ramas paranteze deschise
	if (Corect) cout << "Parantezele se inchid corect.\n";
	else cout << "Parantezele nu se inchid corect.\n";
	cout << "Dimensiunea maxima a cozii este " << LgMax << '\n';
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
