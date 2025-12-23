// Coment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <list>
#include <vector>
#define NMaxVf 101
using namespace std;

int n;
bool G[NMaxVf][NMaxVf];
vector<bool>uz;
list<int>d;

void Citire();
void Determina();
void Scrie();

int main()
{
    Citire();
    Determina();
    Scrie();
    return 0;
}

void Citire()
{
    ifstream fin("coment.in");
    int x, y, m, i;
    fin >> n;
    uz = vector<bool>(n + 1, false);
    m = n * (n - 1) / 2;
    for (i = 0; i < m; i++)
    {
        fin >> x >> y;
        G[x][y] = true;
    }
    fin.close();
}

void Scrie()
{
    ofstream fout("coment.out");
    list<int>::iterator it;
    for (it = d.begin(); it != d.end(); it++) fout << *it << ' ';
    fout << '\n';
    fout.close();
}

int cautpred(int vf)
{
    for (int i = 1; i <= n; i++)
        if (!uz[i] && G[i][vf]) return i;
    return 0;
}

int cautsucc(int vf)
{
    for (int i = 1; i <= n; i++)
        if (!uz[i] && G[vf][i]) return i;
    return 0;
}

void Determina()
{
    int x;
    list<int>::iterator it;
    uz[1] = true; d.push_back(1); // Initializam drumul cu varful 1
    do // Extindem drumul catre dreapta, cat timp este posibil
    {
        x = cautsucc(d.back());
        if (x)
        {
            d.push_back(x);
            uz[x] = true;
        }
    } while (x);
    do // Extindem drumul catre stanga, cat timp este posibil
    {
        x = cautpred(d.front());
        if (x)
        {
            d.push_front(x);
            uz[x] = true;
        }
    } while (x);
    for (x = 2; x <= n; x++)
        if (!uz[x]) // x nu apartine drumului
        {
            for (it = d.begin(); G[*it][x]; it++); // Caut pozitie de inserare
            d.insert(it, x); // Inserez pe x in pozitia curenta
        }
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
