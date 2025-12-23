// Micro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#define NMAX 100000
#define VMAX 1000000000
#define PII pair<long long, int>
#define mp make_pair
using namespace std;

int main()
{
    FILE* stream;
    errno_t err;
    err = freopen_s(&stream, "micro.in", "rt", stdin);
    err = freopen_s(&stream, "micro.out", "wt", stdout);
    int n, i;
    scanf_s("%d", &n);
    vector<int>p(n), cp(n), nr(n), d(n), cd(n);
    for (i = 0; i < n; i++)
        scanf_s("%d %d %d", &p[i], &cp[i], &nr[i]);
    for (i = 0; i < n - 1; i++)
        scanf_s("%d %d", &d[i], &cd[i]);

    multiset<PII>q;

    long long costdep = 0, total = 0, rez = 0;
    for (i = 0; i < n; i++) // parcurg in ordine cele n zile
    {
        q.insert(mp(cp[i] - costdep, p[i]));
        // Adaug microprocesoarele produse in ziua i
        total += p[i];
        // Livrez cele nr[i] microprocesoare necesare
        while ((!q.empty() && nr[i] > 0))
        {
            // Parcurg multisetul q
            multiset<PII>::iterator it = q.begin();
            PII source = *it;
            int cate = min(nr[i], source.second);
            // Voi livra cate microprocesoare
            source.second -= cate;
            nr[i] -= cate;
            rez += cate * (costdep + source.first);
            // Adun costul microprocesoarelor livrate

            q.erase(it);

            if (source.second > 0) q.insert(source);
            total -= cate;
        }
        if (nr[i] > 0) // Problema nu are solutie
        {
            rez = 1;
            break;
        }

        // Adun costurile de depozitare
        if (i != n - 1)
        {
            costdep += cd[i];
            // Extrag din depozit elemente cat timp depasesc
            // capacitatea de dezvoltare
            while (total > d[i])
            {
                multiset<PII>::iterator it = q.end();
                --it;
                PII last = *it;
                q.erase(it);
                long long cate = total - d[i];
                total -= last.second;
                if (last.second > cate)
                {
                    last.second -= (int)cate;
                    q.insert(last);
                    total += last.second;
                }
            }
        }
    }
    printf_s("%lld\n", rez);
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
