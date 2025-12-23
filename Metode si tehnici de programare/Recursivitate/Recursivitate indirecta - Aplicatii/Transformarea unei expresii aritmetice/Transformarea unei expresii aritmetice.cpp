// Transformarea unei expresii aritmetice in forma poloneza.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

char e[200], p[200];
int i, lg, lgp;

void TransformExpresie();
void TransformFactor();
void TransformTermen();

int main()
{
    cout << "Introduceti expresia "; cin.getline(e, 200);
    lg = strlen(e);
    TransformExpresie();
    cout << "Expresia in forma poloneza " << p << endl;
}

void TransformFactor()
{
    int r = 1;
    if (e[i] == '(') // factorul e o expresie intre paranteze
    {
        i++; // trec peste '('
        TransformExpresie(); // transform expresia din paranteza
        i++; // trec peste ')'
    }
    else // factorul este o litera sau o cifra
        p[lgp++] = e[i++];
}

void TransformTermen()
{
    TransformFactor(); // transform primul factor al termenului
    while (i < lg && e[i] == '*') // mai urmeaza factori
    {
        i++; // trec peste '*'
        TransformFactor();
        p[lgp++] = '*';
    }
}

void TransformExpresie()
{
    TransformTermen(); // transform primul termen din expresie
    while (i < lg && e[i] == '+') // mai urmeaza termeni
    {
        i++; // trec peste '+'
        TransformTermen();
        p[lgp++] = '+';
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
