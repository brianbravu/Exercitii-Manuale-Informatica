// Calorii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;
ifstream fin("calorii.in");
ofstream fout("calorii.out");
struct Produs
{
    int cal, pret;
    bool operator>(const Produs& p) const
    {
        return cal * p.pret > pret * p.cal;
    }
};

int main()
{
    int n, S;
    double total = 0;
    Produs x;
    fin >> n;
    vector<Produs>p;
    p.reserve(n);
    for (int i = 0; i < n; i++)
    {
        fin >> x.cal >> x.pret;
        p.push_back(x);
    }
    fin >> S;
    sort(p.begin(), p.end(), greater<Produs>());
    vector<Produs>::iterator it;
    for (it = p.begin(); it != p.end(); it++)
    {
        if (it->pret <= S)
        {
            total += it->cal;
            S -= it->pret;
        }
        else break;
    }
    if (it != p.end()) total += (double)S * it->cal / it->pret;
    fout << setprecision(12) << total << '\n';
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
