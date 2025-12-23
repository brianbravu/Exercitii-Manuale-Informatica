// Sortarea descresc a unui tablou de elevi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <algorithm>
using namespace std;
struct elev { string nume, pren; double mg; };
elev a[1000];
int n;
ifstream fin("elevi.in");
ofstream fout("elevi.out");
void Citeste()
{
    int i;
    fin >> n;
    for (i = 0; i < n; i++) fin >> a[i].nume >> a[i].pren >> a[i].mg;
}
void Scrie()
{
    int i;
    for (i = 0; i < n; i++)
        fout << a[i].nume << ' ' << a[i].pren << ' ' << a[i].mg << '\n';
}

bool ComparElevi(const elev& e1, const elev& e2)
{
    return e1.nume > e2.nume || e1.nume == e2.nume && e1.pren > e2.pren;
}

int main()
{
    Citeste();
    sort(a, a + n, ComparElevi);
    Scrie();
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
