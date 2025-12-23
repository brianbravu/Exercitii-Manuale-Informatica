// Fractali.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <amp_graphics.h>
#include <windows.graphics.h>
using namespace std;

int L, grdriver, grmode, Eroare;

void Fractal(int x, int y, int R)
{
	if (R > 0)
	{
		// desenez fractalii din cele patru colturi
		Fractal(x - R, y + R, R / 2);
		Fractal(x - R, y - R, R / 2);
		Fractal(x + R, y - R, R / 2);
		Fractal(x + R, y + R, R / 2);
		// desenez deasupra patratul de latura R
		bar(x - R / 2, y - R / 2, x + R / 2, y + R / 2);
	}
}

int main()
{
	cout << "L= "; cin >> L;
	grdriver = DETECT; // initializez modul grafic
	initgraph(&grdriver, &grmode, "c:\\borlandc\\bgi");
	Eroare = graphresult();
	if (Eroare == grOk) // am initializat corect modul grafic
	{
		// stabilesc culoarea de fundal si culoarea patratelor
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, RED);
		Fractal(getmaxx() / 2, getmaxy() / 2, L);
		getch();
	}
	closegraph(); // inchid modul grafic
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
