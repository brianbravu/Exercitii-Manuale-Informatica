// Marcare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define NMax 1001

int M[NMax];
int main()
{
    int n, s, k, i;
    cout << "n, s, k = "; cin >> n >> s >> k;
    cout << "Numerele marcate in ordinea marcarii lor: ";
    for (i = 0; M[(s + i * k) % n + n * ((s + i * k) % n == 0)] == 0; i++)
    {
        // Scriu elementul care urmeaza sa fie marcat
        cout << (s + i * k) % n + n * ((s + i * k) % n == 0) << ' ';
        // Il retin in multimea de elemente marcate
        M[(s + i * k) % n + n * ((s + i * k) % n == 0)] = 1;
    }
    cout << "\nNumarul de valori nemarcate: " << n - i << '\n';
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
