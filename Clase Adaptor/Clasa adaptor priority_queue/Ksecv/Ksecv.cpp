// Ksecv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
using namespace std;
#define NMAX 100000
int n, k, lgmax, incmax, sfmax;
int a[NMAX];
priority_queue<int, vector<int>, greater<int>>H;

int main()
{
    int i, x, sf;
    FILE* fin;
    FILE* fout;
    errno_t err;
    err = fopen_s(&fin, "ksecv.in", "r");
    err = fopen_s(&fout, "ksecv.out", "w");
    fscanf_s(fin, "%d %d", &n, &k);
    for (i = 0; i < n; i++) fscanf_s(fin, "%d", &a[i]);
    x = a[0] - 1; sf = 0;
    for(i=0;i<n;i++)
        if (a[i] > x) // Construim o k-secventa incepand cu a[i]
        {
            // Eliminam din heap elementele <= a[i]
            while (!H.empty() && H.top() <= a[i]) H.pop();
            // Adaugam elemente cat timp e posibil
            while (sf < n)
                if (a[sf] <= a[i]) sf++;
                else
                    if (H.size() < k)
                    {
                        H.push(a[sf]);
                        sf++;
                    }
                    else break;
            // Compar lungimea secventei curente cu lgmax
            if (lgmax < (sf - i))
            {
                lgmax = sf - i;
                incmax = i + 1;
                sfmax = sf;
            }
            x = a[i];
        }
    fprintf_s(fout, "%d %d\n", incmax, sfmax);
    fclose(fin);
    fclose(fout);
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
