// Situatie scolara.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iomanip>
using namespace std;

int n, m;
double C[50][50];
int main()
{
    int i, j, nr, corigent;
    double s, max1, max2, max3;
    ifstream fin("Catalog.in");
    ofstream fout("Situatie.out");
    // Citire
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) fin >> C[i][j];
    fin.close();
    // Calculam mediile generale ale elevilor
    for (i = 1; i <= n; i++)
    {
        s = 0; nr = 0; corigent = 0;
        for (j = 1; j <= m && !corigent; j++)
            if (C[i][j])
                if (C[i][j] < 5) corigent = 1;
                else
                {
                    s += C[i][j];
                    nr++;
                }
        if (corigent) C[i][0] = 0;
        else C[i][0] = s / nr;
    }
    // Afisarile se vor face cu doua zecimale
    fout << setprecision(2);
    // Afisam mediile generale ale elevilor
    fout << "Mediile generale ale elevilor:\n";
    for (i = 1; i <= n; i++)
        fout << "Media elevului " << i << " este " << C[i][0] << '\n';
    // Calculam mediile pe obiecte
    for (i = 1; i <= m; i++)
    {
        for (s = 0, nr = 0, j = 1; j <= n; j++)
            if (C[j][i])
            {
                s += C[j][i];
                nr++;
            }
        C[0][i] = s / nr;
    }
    // Afisam mediile pe obiecte
    fout << "Media clasei pe obiecte:\n";
    for (i = 1; i <= m; i++)
        fout << "Media la obiectul " << i << " este " << C[0][i] << '\n';
    // Calculam media generala a clasei
    s = 0; nr = 0;
    for (i = 1; i <= n; i++)
        if (C[i][0])
        {
            s += C[i][0];
            nr++;
        }
    C[0][0] = s / nr;
    fout << "Media generala a clasei este " << C[0][0] << '\n';
    // Calculam max1, max2, max3
    max1 = max2 = max3 = 0;
    for (i = 1; i <= n; i++)
    {
        if (C[i][0] > max1)
        {
            max3 = max2;
            max2 = max1;
            max1 = C[i][0];
        }
        if (C[i][0] < max1 && C[i][0] > max2)
        {
            max3 = max2;
            max2 = C[i][0];
        }
        if (C[i][0] < max2 && C[i][0] > max3) max3 = C[i][0];
    }
    if (max1 >= 9.50) 
        // Se acorda Premiul I
    {
        fout << "Se acorda Premiul I cu media " << max1;
        fout << " elevilor:\n";
        for (i = 1; i <= n; i++)
            if (C[i][0] == max1) fout << i << ' ';
        fout << '\n';
    }
    else
    {
        fout << "Nu se acorda Premiul I\n";
        max3 = max2; 
        max2 = max1;
    }
    if (max2 >= 9)
        // Se acorda Premiul al II-lea
    {
        fout << "Se acorda Premiul al II-lea cu media " << max2;
        fout << " elevilor:\n";
        for (i = 1; i <= n; i++)
            if (C[i][0] == max2) fout << i << ' ';
        fout << '\n';
    }
    else
    {
        fout << "Nu se acorda Premiul al II-lea\n";
        max3 = max2;
    }
    if (max3 >= 8.50)
        // Se acorda Premiul al III-lea
    {
        fout << "Se acorda Premiul al III-lea cu media " << max3;
        fout << " elevilor:\n";
        for (i = 1; i <= n; i++)
            if (C[i][0] == max3) fout << i << ' ';
        fout << '\n';
    }
    else fout << "Nu se acorda Premiul al III-lea\n";
    fout << max1 << ' ' << max2 << ' ' << max3 << '\n';
    fout.close();
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
