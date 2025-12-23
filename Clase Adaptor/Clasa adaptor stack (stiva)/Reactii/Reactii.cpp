// Reactii.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <stack>
using namespace std;
struct SUBST // Substanta retinuta prin minim si maxim
{
    int minim, maxim;
};
stack<SUBST>S;
FILE* f, * g;
int n, m, x, Substanta;
SUBST SVarf, SNoua;

bool OK(SUBST R,SUBST Rx) // Verifica daca se pot combina
{
    return !(R.maxim + 1 != Rx.minim && Rx.maxim + 1 != R.minim);
}

void Reuniune(SUBST R, SUBST& Rx) // Combina cele doua substante
{
    Rx.minim = min(Rx.minim, R.minim);
    Rx.maxim = max(Rx.maxim, R.maxim);
}
int main()
{
    errno_t err;
    err = fopen_s(&f, "reactii.in", "r");
    err = fopen_s(&g, "reactii.out", "w");
    fscanf_s(f, "%d %d", &n, &m);
    for (; m; --m) // Ia pe rand fiecare configuratie
    {
        while (!S.empty()) S.pop(); // GolesteStiva
        for (Substanta = 1; Substanta <= n; Substanta++)
        {
            fscanf_s(f, "%d", &x);
            SNoua.minim = x; SNoua.maxim = x; // Retin
            if (!S.empty()) // Daca am elemente in stiva
            {
                SVarf = S.top();
                while (OK(SVarf, SNoua)) // Daca DA
                {
                    S.pop();
                    Reuniune(SVarf, SNoua);
                    if (!S.empty())
                        SVarf = S.top();
                    else
                        break;
                }
                S.push(SNoua);
            }
            else // Este prima substanta
                S.push(SNoua); // O pun direct in stiva
        }
        fprintf_s(g, "%d\n", S.size() == 1 ? 1 : 0);
    }
    fclose(f); fclose(g);
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
