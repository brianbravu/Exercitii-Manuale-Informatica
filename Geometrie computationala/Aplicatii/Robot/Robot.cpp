// Robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <corecrt_math_defines.h>
#define NMax 10001
#define InFile "robot.in"
#define OutFile "robot.out"
#define sqr(x) ((x)*(x))
#define eps 0.00001

typedef struct { double x, y; } PointD;
PointD p, np;
int n, med, L[NMax];
long ro, ri;
FILE* fout;

void Citire(void);
void Raza(void);
void Rezolva_N(void);
void Rezolva_3(long, long, long);
int Rezolva_2(long, long);
double unghi0(PointD);
double unghi(PointD, PointD);
int Cercuri0(long, PointD, long);

int main()
{
    double u1, u2;
    Citire();
    errno_t err = fopen_s(&fout, OutFile, "wt");
    Raza();
    if (sqr(p.x) + sqr(p.y) > sqr(ro) || sqr(p.x) + sqr(p.y) < sqr(ri))
    {
        fprintf_s(fout, "0\n");
        fclose(fout);
        return 0;
    }
    if (n == 2)
    {
        Rezolva_2(L[1], L[2]);
        u1 = unghi0(np);
        fprintf_s(fout, "%.4lf\n", u1);
        u2 = unghi(np, p);
        fprintf_s(fout, ".4lf\n", u2);
        fclose(fout);
        return 0;
    }
    Rezolva_N();
    return 0;
}

void Citire(void)
{
    int i;
    FILE* fin;
    errno_t err = fopen_s(&fin, InFile, "rt");
    fscanf_s(fin, "%d", &n);
    for (i = 1; i <= n; i++) fscanf_s(fin, "%d", L + i);
    fscanf_s(fin, "%lf %lf", &p.x, &p.y);
    fclose(fin);
}

void Raza(void)
{
    int i, max = -1;
    ro = ri = 0;
    for (i = 1; i <= n; i++)
    {
        ro += L[i];
        if (max < L[i]) max = L[i];
    }
    if (max > ro / 2) ri = 2 * max - ro;
}

void Rezolva_N(void)
{
    long sum = 0;
    for (med = 1; med <= n; med++)
        if (sum + L[med] > ro / 2) break;
        else sum += L[med];
    Rezolva_3(sum, L[med], ro - sum - L[med]);
}

void Rezolva_3(long l1, long l2, long l3)
{
    int i;
    double u1, u2;
    PointD temp;
    if (Rezolva_2(l1 + l2, l3))
    {
        u1 = unghi0(np); fprintf_s(fout, "%.4lf\n", u1);
        for (i = 2; i <= med; i++) fprintf_s(fout, "0\n");
        u2 = unghi(np, p); fprintf_s(fout, "%.4lf\n", u2);
        for (i = med + 2; i <= n; i++) fprintf_s(fout, "0\n");
        fclose(fout);
        return;
    }
    if (Rezolva_2(l1, l2 + l3))
    {
        u1 = unghi0(np);
        fprintf_s(fout, "%.4lf\n", u1);
        for (i = 2; i < med; i++) fprintf_s(fout, "0\n");
        u2 = unghi(np, p); fprintf_s(fout, "%.4lf\n", u2);
        for (i = med + 1; i <= n; i++) fprintf_s(fout, "0\n");
        fclose(fout);
        return;
    }
    for (i = 1; i < med; i++) fprintf_s(fout, "0\n");
    p.x -= l1;
    Rezolva_2(l2, l3);
    u1 = unghi0(np); fprintf_s(fout, "%.4lf\n", u1);
    u2 = unghi(np, p); fprintf_s(fout, "%.4lf\n", u2);
    p.x += l1; np.x += l1;
    for (i = med + 2; i <= n; i++) fprintf_s(fout, "0\n");
    fclose(fout);
    return;
}

int Rezolva_2(long l1, long l2)
{
    int nsol;
    nsol = Cercuri0(l1, p, l2);
    return nsol;
}

int Cercuri0(long r1, PointD c2, long r2)
// Determina punctul de intersectie a doua cercuri
// primul cerc este centrat in origine si are raza r1;
// al doilea cerc este centrat in punctul c2 si are raza r2;
// functia returneaza numarul de puncte de intersectie
{
    long dc1c2 = sqr(c2.x) + sqr(c2.y); // Distanta dintre centre
    long rplus = sqr(r1 + r2), rminus = sqr(r1 - r2);
    double f, a2, sint, cost;
    PointD q;
    if (dc1c2 > rplus || dc1c2 < rminus) // Cercuri nesecante
        return 0;
    if (dc1c2 == rplus) // Cercuri tangente exterior
    {
        f = r1 / (double)(r1 + r2);
        np.x = f * c2.x;
        np.y = f * c2.y;
        return 1;
    }
    if (dc1c2 == rminus) // Cercuri tangente interior
    {
        if (!rminus) // Cercurile coincid
        {
            np.x = r1;
            np.y = 0;
            return 3;
        }
        f = r1 / (double)(r1 - r2);
        np.x = f * c2.x;
        np.y = f * c2.y;
        return 1;
    }
    // Doua puncte de intersectie; rotim c2 a.i. sa fie pe Ox
    a2 = sqrt(dc1c2); cost = c2.x / a2; sint = c2.y / a2;
    q.x = (a2 + (sqr(r1) - sqr(r2)) / a2) / 2;
    q.y = sqrt(sqr(r1) - sqr(q.x));
    np.x = cost * q.x - sint * q.y;
    np.y = sint * q.x + cost * q.y;
    return 2;
}

double unghi0(PointD np)
{
    if (np.y >= 0)
        return 180 * atan2(np.y, np.x) / M_PI;
    return 360 - 180 * atan2(-np.y, np.x) / M_PI;
}

double unghi(PointD np, PointD p)
{
    PointD p1;
    double d;
    p1.x = p.x - np.x;
    p1.y = p.y - np.y;
    d = unghi0(p1) - unghi0(np);
    if (d < 0) d += 360;
    return d;
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
