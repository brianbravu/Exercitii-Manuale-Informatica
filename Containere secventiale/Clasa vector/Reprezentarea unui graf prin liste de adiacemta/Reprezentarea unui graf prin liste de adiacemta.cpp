// Reprezentarea unui graf prin liste de adiacemta.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <vector>
using namespace std;
#define NMAX 1001
ifstream fin("graf.in");
ofstream fout("graf.out");
int n;
vector<vector<int>>v(NMAX);
vector<bool>viz(NMAX, false);
void dfs(int x)
{
    viz[x] = true; fout << x << ' ';
    for (int i = 0; i < v[x].size(); i++)
        if (!viz[v[x][i]]) dfs(v[x][i]);
}

int main()
{
    int m, i, x, y, nrc = 0;
    fin >> n >> m;
    for (i = 0; i < m; i++)
    {
        fin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (i = 1; i <= n; i++)
        if (!viz[i])
        {
            fout << "Componenta conexa " << ++nrc << '\n';
            dfs(i);
            fout << '\n';
        }
    fout.close();
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
