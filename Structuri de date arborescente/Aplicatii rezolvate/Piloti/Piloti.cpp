// Piloti.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;
#define InFile "piloti.in"
#define OutFile "piloti.out"
#define NMax 10001

int H[NMax], lg = 0;

int maxhead_top()
{
    return H[1];
}

void maxheap_push(int x)
{
    int tata, fiu;
    lg++;
    fiu = lg; tata = lg / 2;
    while (tata > 0)
        if (x > H[tata])
        {
            H[fiu] = H[tata];
            fiu = tata;
            tata = tata / 2;
        }
        else break;
    H[fiu] = x;
}

void maxheap_pop()
{
    int tata, fiu, x;
    x = H[lg--];
    tata = 1; fiu = 2;
    while (fiu <= lg)
    {
        if (fiu < lg && H[fiu] < H[fiu + 1]) fiu++;
        if (x < H[fiu])
        {
            H[tata] = H[fiu];
            tata = fiu;
            fiu = 2 * fiu;
        }
        else break;
    }
    H[tata] = x;
}

int main()
{
    int n, rez = 0, capitan, asistent;
    ofstream fout(OutFile);
    ifstream fin(InFile);
    for (fin >> n; n; --n)
    {
        fin >> capitan >> asistent;
        rez += capitan;
        maxheap_push(capitan - asistent);
        if (n % 2 == 0)
        {
            rez -= maxhead_top();
            maxheap_pop();
        }
    }
    fout << rez << "\n";
    fout.close();
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
