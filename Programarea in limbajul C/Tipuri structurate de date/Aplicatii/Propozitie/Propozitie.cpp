// Propozitie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    char p[500], pmax[500];
    int lg, lgmax = 0, gata = 0;
	char copie[500], sep[] = " ;,:-)(", * c, * next_token = NULL;
	do
	{
		cin.getline(p, 500, '.'); // Citesc o propozitie
		if (!strcmp(p, "#")) gata = 1; // S-a terminat textul
		else
		{
			// Calculez lungimea propozitiei citite
			lg = 0;
			strcpy_s(copie, p); // Copiez propozitia
			c = strtok_s(copie, sep, &next_token);
			while (c) // Am extras un cuvant
			{
				lg++; // Il numar
				c = strtok_s(NULL, sep, &next_token); // Incerc sa extrag urmatorul
			}
			if (lg > lgmax) // Compar lungimea cu lungimea maxima
			{
				lgmax = lg;
				strcpy_s(pmax, p);
			}
		}
	} while (!gata);
	cout << "lgmax=" << lgmax << " pmax=" << pmax << '\n';
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
