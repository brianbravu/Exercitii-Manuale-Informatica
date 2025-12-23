// Zid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
ifstream fin("zid.in");
ofstream fout("zid.out");
int n;

void rest(int& x) { x = x % n; }

int main()
{
    int i, j, k, x, cate, gasit;
    fin >> n;
    vector<int>h;
    h.reserve(n);
    for (i = 0; i < n; i++)
    {
        fin >> x;
        h.push_back(x);
    }
    fin.close();
    
    vector<int>s;
    s.reserve(n);
    partial_sum(h.begin(), h.end(), s.begin());
    
    for_each(s.begin(), s.begin() + n, rest);
    
    vector<int>::iterator poz;
    poz = find(s.begin(), s.begin() + n, 0);

    if (poz != s.begin() + n) // Cazul 1
    {
        cate = poz - s.begin() + 1;
        fout << cate << '\n';
        for (i = 0; i < cate; i++) fout << h[i] << ' ';
        fout << '\n';
    }
    else // Cazul 2
    {
        for (gasit = i = 0; i < n && !gasit; i++)
            for (j = i + 1; j < n && !gasit; j++)
                if (s[i] == s[j]) gasit = 1;
        j--; i--;
        fout << j - i << '\n';
        for (k = i + 1; k <= j; k++) fout << h[k] << ' ';
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
