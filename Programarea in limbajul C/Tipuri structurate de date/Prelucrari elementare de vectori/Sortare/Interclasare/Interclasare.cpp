// Interclasare.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[100], b[100], c[200], n, m, i, j, k;
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    for (j = 0; j < m; j++) cin >> b[i];
    for (i = j = k = 0; i < n && j < m;)
        if (a[i] < b[i]) // Copiez in c elementul cel mai mic
            c[k++] = a[i++]; // Copiez din a
        else c[k++] = b[j++]; // Copiez din b
    // Copiez eventualele elemente ramase in a
    for (; i < n; i++)
        c[k++] = a[i];
    // Copiez eventualele elemente ramase in b
    for (; j < m; j++)
        c[k++] = b[j];
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
