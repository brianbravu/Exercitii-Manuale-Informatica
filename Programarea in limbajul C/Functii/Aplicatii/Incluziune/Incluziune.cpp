// Incluziune.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
using namespace std;

typedef int Multime[256];
Multime A, B;
ifstream p("prim.txt");

void Citeste_Multimea(Multime X);
void Compara(Multime X, Multime Y);
int Inclus(Multime X, Multime Y);

int main()
{
    Citeste_Multimea(A); // Construiesc multimea A
    Citeste_Multimea(B); // Construiesc multimea B
    p.close();
    Compara(A, B); // Verific incluziunea
}

void Citeste_Multimea(Multime X)
{
    char c;
    do
    {
        c = p.get(); // Citesc un caracter
        X[c] = 1; // Adaug caracterul c la multime
    } while (c != '\n');
    X[' '] = X['\n'] = 0; // Extrag caractere SPACE si LF
}

void Compara(Multime X, Multime Y)
{
    ofstream d("doi.txt");
    if (Inclus(X, Y)) // Daca X este inclus in Y...
        d << "DA\n";
    else d << "NU\n";
    d.close();
}

int Inclus(Multime X, Multime Y) // Intoarce 1 daca X este inclus in Y si 0 altfel
{
    int i;
    for (i = '0'; i <= '9'; i++)
        if (X[i] > Y[i]) return 0;
    for (i = 'A'; i <= 'Z'; i++)
        if (X[i] > Y[i]) return 0;
    for (i = 'a'; i <= 'z'; i++)
        if (X[i] > Y[i]) return 0;
    return 1;
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
