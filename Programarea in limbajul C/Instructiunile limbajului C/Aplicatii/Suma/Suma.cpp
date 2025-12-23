// Suma.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int S, x, y, r;
    scanf_s("%d", &S);
    r = S % 3;
	switch (r)
	{
	case 0:
		x = S / 3;
		y = 0;
		break;
	case 1:
		x = S / 3 - 3;
		y = 2;
		break;
	case 2:
		x = S / 3 - 1;
		y = 1;
	default:
		break;
	}
	printf_s("3*%d+5*%d\n", x, y);
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
