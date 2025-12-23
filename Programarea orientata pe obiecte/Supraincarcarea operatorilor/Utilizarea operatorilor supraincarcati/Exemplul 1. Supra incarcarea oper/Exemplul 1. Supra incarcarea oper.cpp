// Exemplul 1. Supra incarcarea oper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "mesaj.h"
using namespace std;

int main()
{
    mesaj m1, m2("Ama are mere.");
    cout << m1.GetLg() << ' '; m1.Scrie();
    cout << m2.GetLg() << ' '; m2.Scrie();
    mesaj m("12345ABC");
    ~m; // m.operator~();
    m.Scrie();
    mesaj m0, m01("Ana "), m02("are mere");
    m0 = m01 + m02; // m0 = m01.operator+(m02);
    m0.Scrie();
    mesaj m00, m001("Ana ");
    m00 = m001 + "are mere";
    m00.Scrie();
    mesaj m000("ana"), m0001(" are mere"), m0002(" bune");
    m000 += m0001 += m0002;
    m000.Scrie();
    m0001.Scrie();
    mesaj m0000("anapoda");
    cout << m0000[3];
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
