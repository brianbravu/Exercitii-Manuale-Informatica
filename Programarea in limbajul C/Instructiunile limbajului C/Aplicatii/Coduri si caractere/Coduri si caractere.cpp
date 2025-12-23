// Coduri si caractere.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int cod;
	for (cod = 0; cod < 256; cod++)
	{
		switch (cod)
		{
		case 0:
			cout << "\\0 ";
			break;
		case 7:
			cout << "\\a ";
			break;
		case 8:
			cout << "\\b ";
			break;
		case 9:
			cout << "\\t ";
			break;
		case 10:
			cout << "\\n ";
			break;
		case 11:
			cout << "\\v ";
			break;
		case 12:
			cout << "\\f ";
			break;
		case 13:
			cout << "\\r ";
			break;
		case 26:
			cout << "eof ";
			break;
		case 27:
			cout << "esc ";
			break;
		default:
			cout << unsigned char(cod) << ' ';
			break;
		}
		cout << cod;
		if (cod % 2) cout << '\n';
		else cout << '\t';
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
