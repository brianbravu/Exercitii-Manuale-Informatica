// Reziston.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define InFile "rez.in"
#define OutFile "rez.out"
#define LMax 1001

int n, p;
char s[LMax];
long r;

void citire();
void afisare();
long rezserie();
long rezparalel();

int main()
{
	citire();
	r = rezserie();
	afisare();
}

void citire(void)
{
	FILE* fin;
	errno_t err = fopen_s(&fin, InFile, "rt");
	fgets(s, LMax, fin);
	for (n = 0; s[n]; n++);
	fclose(fin);
}

void afisare(void)
{
	FILE* fout;
	errno_t err = fopen_s(&fout, OutFile, "wt");
	fprintf_s(fout, "%ld\n", r);
	fclose(fout);
}

long rezserie()
{
	long val, suma = 0;
	if (p >= n || s[p] == ',' || s[p] == ')')
		return 0;
	while (p < n && s[p] != ',' && s[p] != ')')
		if (s[p] == 'R')
		{
			p++;
			val = s[p] - '0';
			p++;
			if (s[p] >= '0' && s[p] <= '9')
			{
				val = val * 10 + s[p] - '0';
				p++;
			}
			suma += val;
		}
		else suma += rezparalel();
	return suma;
}

long rezparalel()
{
	long suma = 0, produs = 1, val;
	while (p < n && s[p] != ',' && s[p] != ')')
	{
		p++;
		val = rezserie();
		suma += val;
		produs *= val;
	}
	p++;
	return produs / suma;
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
