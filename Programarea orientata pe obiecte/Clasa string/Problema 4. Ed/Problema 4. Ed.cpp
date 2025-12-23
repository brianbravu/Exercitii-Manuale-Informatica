// Problema 4. Ed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;

ifstream fin("ed.in");
ofstream fout("ed.out");

string s, op;
int poz;

int main()
{
    int i, N, lg;
    fin >> s;
    poz = s.length();
    fin >> N;
    for (i = 0; i < N; i++)
    {
        fin >> op;
        switch (op[0])
        {
        case 'L':
        {
            if (poz > 0)
                poz--;
            break;
        }
        case 'R':
        {
            if (poz < s.length())
                poz++;
            break;
        }
        case 'B':
        {
            if (poz > 0)
            {
                s.erase(poz - 1, 1);
                poz--;
            }
            break;
        }
        case 'I':
        {
            s.insert(poz, op, 1, string::npos);
            break;
        }
        case 'D':
        {
            lg = atoi(op.data() + 1);
            // lg = stoi(op.substr(1));
            s.erase(poz, lg);
            poz -= lg;
            break;
        }
        default:
            break;
        }
    }
    fout << s << '\n';
    fin.close();
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
