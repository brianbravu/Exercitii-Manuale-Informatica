// Combinare vectori.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int n, A[20], B[20], i, aux;
    cout << "n="; cin >> n;
    cout << "Elementele vectorului A: ";
    for (i = 0; i < n; i++) cin >> A[i];
    cout << "Elementele vectorului B: ";
    for (i = 0; i < n; i++) cin >> B[i];
    for (i = 0; i < n; i++)
    {
        aux = A[i];
        A[i] = A[i] + B[i];
        B[i] = aux * B[i];
    }
    cout << "Vectorul A: ";
    for (i = 0; i < n; i++) cout << A[i] << ' '; cout << '\n';
    cout << "Vectorul B: ";
    for (i = 0; i < n; i++) cout << B[i] << ' '; cout << '\n';
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
