// Sea.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

set<pair<int, int>>Vase;
int main()
{
    FILE* fin;
    FILE* fout;
    errno_t err;
    err = fopen_s(&fin, "sea.in", "r");
    err = fopen_s(&fout, "sea.out", "w");
    int x, y, n, i;
    set<pair<int, int>>::iterator It, It2, It1;
    fscanf_s(fin, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf_s(fin, "%d %d", &x, &y);
        It = Vase.upper_bound(make_pair(x, y));
        if (It != Vase.end() && It->second > y)
        {
            fprintf_s(fout, "-1\n");
            continue;
        }
        if (!Vase.empty())
        {
            for (It1 = It2 = It, --It1; It2 != Vase.begin() && It1->second < y; It2 = It1, --It1);
            Vase.erase(It2, It);
        }
        Vase.insert(make_pair(x, y));
        fprintf_s(fout, "%d\n", Vase.size());
    }
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
