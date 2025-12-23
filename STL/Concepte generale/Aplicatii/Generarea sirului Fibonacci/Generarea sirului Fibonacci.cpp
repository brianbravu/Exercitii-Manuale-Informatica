// Generarea sirului Fibonacci.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
int n;
int f[100];

class TermenF
{
public:
	int f1, f2;
	int operator()() { int f3 = f2 + f1; f1 = f2; f2 = f3; return f3; }
}TF;

int main()
{
	std::cout << "n="; std::cin >> n;
	f[0] = TF.f1 = 0; f[1] = TF.f2 = 1; // Initializare
	std::generate(f + 2, f + n, TF); // Generare
	for (int i = 0; i < n; i++) std::cout << f[i] << ' ';
	std::cout << '\n';
	return 0;
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
