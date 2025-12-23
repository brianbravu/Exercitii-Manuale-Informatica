// Alee.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
using namespace std;

const int dx[5] = { 0,-1,0,1,0 };
const int dy[5] = { 0,0,1,0,-1 };
queue<pair<int, int>>C;
int a[178][178];
int ix, iy, ox, oy, x, y;
int n, m;

int main()
{
    int k, i, j;
    pair<int, int>xx, yy;
    errno_t err;
    FILE* f;
    FILE* g;
    err = fopen_s(&f, "alee.in", "r");
    err = fopen_s(&g, "alee.out", "w");
    fscanf_s(f, "%d %d", &n, &m);
    for (k = 1; k <= m; k++)
    {
        fscanf_s(f, "%d %d", &i, &j);
        a[i][j] = -1;
    }
    fscanf_s(f, "%d %d %d %d", &ix, &iy, &ox, &oy);
    fclose(f);
    for (i = 1; i <= n; i++) // Bordare
        a[i][0] = a[i][n + 1] = a[0][i] = a[n + 1][i] = -1;
    a[ix][iy] = 1; // Prima dala
    C.push(make_pair(ix, iy)); // Pun in coada
    while (!C.empty() && a[ox][oy] == 0)
    {
        xx = C.front(); C.pop(); // Extrag primul element din coada
        for (k = 1; k <= 4; k++)
        {
            yy.first = xx.first + dx[k];
            yy.second = xx.second + dy[k];
            if (a[yy.first][yy.second] == 0) // Este liber
            {
                a[yy.first][yy.second] = a[xx.first][xx.second] + 1;
                C.push(make_pair(yy.first, yy.second));
            }
        }
    }
    fprintf_s(g, "%d\n", a[ox][oy]); // Scrie rezultat
    fclose(g);
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
