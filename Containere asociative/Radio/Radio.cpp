// Radio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define NMAX 1000005
#define MOD 13
#define LMAX 2505
#define BASE 37

int N, M, L, K;
char S[NMAX];
multimap<int, int>hashMap;
char C[LMAX];
int dist(char* a, char* b, int n);
void buildHash(int Lg);
bool SePotriveste(int poz);

int main()
{
    FILE* stream;
    errno_t err;
    err = freopen_s(&stream, "radio.in", "r", stdin);
    err = freopen_s(&stream, "radio.out", "w", stdout);
    multimap<int, int>::iterator it, prim, ultim;
    int ic, i, j, hashVal, rez;
    scanf_s("%d %d %d %d", &N, &M, &L, &K);
    scanf_s("%[^\n]%*c", S);
    int Lg = L / (K + 1);
    buildHash(Lg);
    for (ic = 0; ic < M; ++ic)
    {
        scanf_s("%[^\n]%*c", C);
        for (rez = i = 0; i + Lg <= L; i += Lg)
        {
            for (hashVal = j = 0; j < Lg; ++j)
                hashVal = (hashVal * BASE + (C[i + j] - 'a')) % MOD;
            prim = hashMap.lower_bound(hashVal);
            ultim = hashMap.upper_bound(hashVal);
            for (it = prim; it != ultim; ++it)
                   rez |= SePotriveste(it->second - i);
        }
        printf_s("%d\n", rez);
    }
    return 0;
}

int dist(char* a, char* b, int n)
{
    int sol = 0;
    for (int i = 0; i < n; ++i) sol += a[i] != b[i];
    return sol;
}

void buildHash(int Lg)
{
    int hashVal = 0, i, coef = 1;
    for (i = 0; i < Lg - 1 && i < N; ++i)
        hashVal = (hashVal * BASE + (S[i] - 'a')) % MOD;
    for (i = 1; i < Lg; ++i) coef = coef * BASE % MOD;
    for (i = Lg - 1; i < N; ++i)
    {
        hashVal = (hashVal * BASE + (S[i] - 'a')) % MOD;
        hashMap.insert(make_pair(hashVal, i - Lg + 1));
        hashVal = (hashVal - coef * (S[i - Lg + 1] - 'a')) % MOD;
        if (hashVal < 0) hashVal += MOD;
    }
}

bool SePotriveste(int poz)
{
    if (poz<0 || poz + L>N) return 0;
    return dist(S + poz, C, L) <= K;
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
