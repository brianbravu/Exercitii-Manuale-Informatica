// Ciurul lui Eratostene.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
#define VMAX 100000
vector<bool>ciur(VMAX, true);

int main()
{
    int i, j;
    for (i = 2; i * i < VMAX; i++)
        if (ciur[i]) // i este prim
            // Elimin din ciur multiplii neeliminati ai lui i
            for (j = i; j * i < VMAX; j++) ciur[j * i] = false;
    // Afisez numerele prime
    for (i = 2; i < VMAX; i++)
        if (ciur[i]) cout << i << ' ';
    cout << '\n';
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
