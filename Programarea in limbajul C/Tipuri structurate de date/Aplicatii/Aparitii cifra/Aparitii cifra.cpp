// Aparitii cifra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define CIFREMAX 10

long int N, K, NT = 0;
long int C[CIFREMAX], P10[CIFREMAX];
int main()
{
    int i, p, pcifra;
    scanf_s("%d %d", &N, &K);
    C[0] = 0;
    P10[0] = 1;
    for (i = 1; i < CIFREMAX; i++)
    {
        C[i] = 9 * C[i - 1] + P10[i - 1];
        P10[i] = P10[i - 1] * 10;
    }
    for (p = CIFREMAX - 1; p + 1; p--)
        if (N >= P10[p])
        {
            pcifra = N / P10[p]; // Determin prima cifra a lui n
            if (pcifra > K)
            {
                NT += P10[p];
                NT += (pcifra - 1) * C[p];
            }
            if (pcifra == K)
            {
                NT += pcifra * C[p];
                NT += N % P10[p] + 1;
                break;
            }
            if (pcifra < K) NT += pcifra * C[p];
            N %= P10[p]; // Eliminam prima cifra a lui N
        }
    printf_s("%d\n", NT);
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
