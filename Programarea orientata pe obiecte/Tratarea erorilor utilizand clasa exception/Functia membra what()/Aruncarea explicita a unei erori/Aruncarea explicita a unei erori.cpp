// Aruncarea explicita a unei erori.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int CitesteNenul()
{
    std::runtime_error eroare("Numar nul");
    int val;
    std::cin >> val;
    if (val == 0) throw(eroare);
    return val;
}

int main()
{
	try
	{
		int x = CitesteNenul();
		std::cout << x;
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "Eroare capturata: " << e.what();
	}
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
