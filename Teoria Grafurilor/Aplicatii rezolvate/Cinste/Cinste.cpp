// Cinste.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define NMax 1001
#define MMax 8001
#define InFile "cinste.in"
#define OutFile "cinste.out"
#define sgn(x) ((x)>0?1:0)
typedef struct { int y, c; } Opinion;
int n, m, total;
Opinion* G[NMax], * GT[NMax];
int d[NMax], di[NMax], o[NMax];
int s[NMax];

void read_it(void);
void solve(void);
void write_it(void);
int dfs(int, int);
void top_sort(void);

int main()
{
    read_it();
    top_sort();
    solve();
    write_it();
}

void read_it(void)
{
    int i, x, y; char c;
    FILE* fin;
    errno_t err = fopen_s(&fin, InFile, "rt");
    fscanf_s(fin, "%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        //fscanf_s(fin, "%d %c %d", &x, &c, &y);
        fscanf_s(fin, "%d", &x);
        getc(fin);
        c = getc(fin);
        getc(fin);
        fscanf_s(fin, "%d", &y);
        d[x]++; di[y]++;
        G[x] = (Opinion*)realloc(G[x], d[x] * sizeof(Opinion));
        G[x][d[x] - 1].y = y;
        GT[y] = (Opinion*)realloc(GT[y], di[y] * sizeof(Opinion));
        GT[y][di[y] - 1].y = x;
        if (c == 'c') G[x][d[x] - 1].c = GT[y][di[y] - 1].c = 1;
        else G[x][d[x] - 1].c = GT[y][di[y] - 1].c = -1;
    }
    fclose(fin);
}

void solve(void)
{
    int i, j, how;
    s[o[1]] = 1;
    for (i = 2; i <= n; i++)
    {
        how = 0;
        for (j = 0; j < di[o[i]]; j++)
            if (GT[o[i]][j].c > 0)
            {
                if (!how)
                    how = s[GT[o[i]][j].y];
                else
                    if (s[GT[o[i]][j].y] * how < 0)
                    {
                        printf_s("Contradictie!\n");
                        return;
                    }
            }
            else
            {
                if (!how)
                    how = -s[GT[o[i]][j].y];
                else 
                    if (-s[GT[o[i]][j].y] * how < 0)
                    {
                        printf_s("Contradictie!\n");
                        return;
                    }
            }
        s[o[i]] = how;
    }
}

void write_it(void)
{
    int i, sum = 0, sgn = 1;
    FILE* fout;
    errno_t err = fopen_s(&fout, OutFile, "w");
    for (i = 1; i <= n; i++)
        if (s[i] > 0) sum++;
    if (sum < n / 2) sgn = -1;
    for (i = 1; i <= n; i++)
        if (sgn * s[i] < 0) fprintf_s(fout, "0\n");
        else fprintf_s(fout, "1\n");
    fclose(fout);
}

void top_sort()
{
    int i, nr = 0, j, sdi[NMax];
    for (i = 1; i <= n; i++) sdi[i] = di[i];
    while (nr < n)
    {
        for (i = 1; i <= n && sdi[i]; i++);
        for (j = i + 1; j <= n && sdi[j]; j++);
        o[++nr] = i; sdi[i] = -1;
        for (j = 0; j < d[i]; j++) sdi[G[i][j].y]--;
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
