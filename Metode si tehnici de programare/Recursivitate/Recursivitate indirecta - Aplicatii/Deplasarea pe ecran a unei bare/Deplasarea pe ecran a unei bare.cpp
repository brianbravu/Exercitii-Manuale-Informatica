// Deplasarea pe ecran a unei bare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <conio.h>
#include<dos.h>

int i = 1;

void InSus();
void InJos();

int main()
{
    InJos();
}

void InJos()
{
    if (++i == 25) InSus();
	else // sterg ecranul si redesenez bara
	{
		textbackground(0); clrscr();
		window(1, i, 80, i); textbackground(5); clrscr();
		delay(500);
		InSus();
	}
}

void InSus()
{
	if (--i == 1) InJos();
	else // sterg ecranul si redesenez bara
	{
		textbackground(0); clrscr();
		window(1, i, 80, i); textbackground(5); clrscr();
		delay(500);
		InJos();
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
