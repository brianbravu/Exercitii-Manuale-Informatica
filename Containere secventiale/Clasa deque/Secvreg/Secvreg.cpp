// Secvreg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <deque>
using namespace std;

ifstream fin("secvreg.in");
ofstream fout("secvreg.out");
deque<char>a;
deque<int>b;
string s;

inline bool deschis(char c)
{
    return c == '(' || c == '[';
}

inline char pereche(char c)
{
    if (c == ')') return '(';
    if (c == '(') return ')';
    if (c == ']') return '[';
    if (c == '[') return ']';
}

int la_sfarsit(char c)
{
    int ret;
    if (!a.empty() && !deschis(c) && a.back() == pereche(c))
    {
        ret = b.back() + 2; // Retin lungimea secventei regulate
        b.pop_back(); a.pop_back(); // Elimin secventa regulata formata
        b[b.size() - 1] += ret; // Actualizez in b lungimea secventei regulate
        return ret;
    }
    a.push_back(c); b.push_back(0);
    return 0;
}

int la_inceput(char c)
{
    int ret;
    if (!a.empty() && deschis(c) && a.front() == pereche(c))
    {
        ret = b.front() + 2; // Retin lungimea secventei regulate
        a.pop_front(); b.pop_front();
        b[0] += ret;
        return ret;
    }
    a.push_front(c); b.push_front(0);
    return 0;
}

int main()
{
    char c;
    int i, poz, n;
    fin >> s;
    b.push_back(0);
    for (i = 0; i < s.size(); i++) la_sfarsit(s[i]);
    fin >> n;
    for (i = 0; i < n; i++)
    {
        fin >> poz >> c;
        if (poz) fout << la_sfarsit(c) << '\n';
        else fout << la_inceput(c) << '\n';
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
