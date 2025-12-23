// Anagrame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int EAnagrama(char* x, char* y)
{
    char* p;
    if (!*x && !*y) return 1;
    p = strchr(y, *x); // caut in y primul caracter din x
    if (!p) return 0; // nu l-am gasit
    *p = NULL; strcat_s(y, 100, p + 1); // l-am gasit, il sterg din y
    return EAnagrama(x + 1, y);
}

int main()
{
    char x[100], y[100];
    cout << "x= "; cin.getline(x, 100);
    cout << "y= "; cin.getline(y, 100);
    if (strlen(x) != strlen(y)) cout << "NU!" << endl;
    else if (EAnagrama(x, y)) cout << "DA!" << endl;
    else cout << "NU!" << endl;
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
