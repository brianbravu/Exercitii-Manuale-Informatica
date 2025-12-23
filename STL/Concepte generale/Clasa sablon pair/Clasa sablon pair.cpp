// Clasa sablon pair.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
using namespace std;
int main()
{
    pair<string, float>p1("Ionescu Dan", 9.75);
    pair<string, float>p2;
    p2 = make_pair("Popescu Ana", 9.43);
    cout << p1.first << ' ' << p1.second << '\n';
    cout << p2.first << ' ' << p2.second << '\n';
    if (p1 == p2) cout << "perechi egale\n";
    else cout << "Perechi neegale\n";
    if (p1 < p2) cout << "p1<p2";
    else cout << "p1>=p2";
    p1 = make_pair("Popescu Ana", 9.98);
    if (p1 < p2) cout << " Dupa schimbare: p1<p2\n";
    else cout << " Dupa schimbare: p1>=p2\n";
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
