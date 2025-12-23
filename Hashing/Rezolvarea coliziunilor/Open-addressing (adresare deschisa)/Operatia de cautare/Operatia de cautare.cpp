// Operatia de cautare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NIL 0
int m;
int hashfunction(char* s)
{
    int i;
    for (i = 0; *s; s++) i = 131 * i + *s;
    return (i % m);
}

int p;
int r = (rand() << 1) | 1;
inline int hash(int x, int i)
{
    return ((unsigned)(x * r) >> (32 - p));
}

int k;
int Insert(int T[], int x)
{
    int i = 0;
    do
    {
        int j = hash(x, i);
        if (T[j] == NIL)
        {
            T[j] = k;
            return j;
        }
        else i++;
    } while (i < m);
    perror("hash table overflow");
    return -1;
}

int Search(int T[], int x)
{
    int i = 0;
    int j;
    do
    {
        j = hash(x, i);
        if (T[j] == x) return j;
        i++;
    } while (T[j] != NIL || i < m);
    return NIL;
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
