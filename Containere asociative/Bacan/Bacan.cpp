// Bacan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

ifstream fin("bacan.in");
ofstream fout("bacan.out");

map<string, int>V;

int main()
{
    int n, i, poz, x;
    string s, s1;
    fin >> n; fin.get();
    for (i = 0; i < n; i++)
    {
        getline(fin, s);
        poz = s.find('*');
        s1 = s.substr(poz + 2); // Extrag cantitatea
        x = stoi(s1); // O convertesc in intreg
        s1 = s.substr(0, poz - 1); // Extrag numele
        V[s1] += x; // Actualizez map
    }
    fin.close();
    fout << V.size() << '\n';
    map<string, int>::iterator it;
    for (it = V.begin(); it != V.end(); ++it)
        fout << it->first << " * " << it->second << '\n';
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
