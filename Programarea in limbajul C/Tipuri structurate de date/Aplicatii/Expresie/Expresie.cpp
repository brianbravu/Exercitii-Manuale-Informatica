// Expresie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;

unsigned int fp[30000];
int main()
{
    ifstream fin("exp.in");
    ofstream fout("exp.out");
    int n, m, x, i, d;
    // Citire
    fin >> m >> n;
    for (i = 0; i < n; i++)
    {
        fin >> x;
        // Descompun pe x in factori primi
        for (d = 2; x > 1; d++)
            while (!(x % d))
            {
                fp[d]++;
                x /= d;
            }
    }
    // Verific daca toti factorii primi 
    // au multiplicitatile divizibile cu m
    for (i = 2; i < 30000 && !(fp[i] % m); i++);
    if (i < 30000) 
        // Exista cel putin un factor prim 
        // pentru care multiplicitatea nu este divizibila cu m, 
        // deci rezultatul expresiei nu este numar natural
        fout << 0 << '\n';
    else
    {
        fout << 1 << '\n';
        for (i = 2; i < 30000; i++)
            if (fp[i])
                fout << i << ' ' << fp[i] / m << '\n';
    }
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
