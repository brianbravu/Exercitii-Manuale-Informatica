// Examinare patratica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NIL NULL
int m;
int hashfunction(char* s)
{
    int i;
    for (i = 0; *s; s++) i = 131 * i + *s;
    return (i % m);
}

int p;
int r = (rand() << 1) | 1;
inline int hash(int x)
{
    return ((unsigned)(x * r) >> (32 - p));
}

int Examinare_patratica(int T[], int x)
{
    int i = hash(x);
    int j = 0;
    do
    {
        if (T[i] == NIL)
        {
            T[i] = x;
            return i;
        }
        j = (j + 1) % m;
        i = (i + j) % m;
    } while (true);
}

int main()
{
    std::cout << "Hello World!\n";
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
