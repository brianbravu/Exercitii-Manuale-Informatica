// Imagine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define MAX 250

FILE* Fin, * Fout;
char imagine[MAX][MAX];

int PixeliEgali(int x1, int y1, int x2, int y2, int Pixel)
{
    // functia determina daca zona de coordonate x1, y1, x2, y2
    // are doar pixeli 0 sau doar pixeli 1
    for (int i = x1; i <= x2; i++)
        for (int j = y1; j <= y2; j++)
            if (imagine[i][j] != Pixel) // am gasit un pixel diferit de Pixel
                return 0;
    return 1; // toti pixelii sunt identici cu pixeli
}

unsigned long Lungime_Comp(int x1, int y1, int x2, int y2)
{
    if (PixeliEgali(x1, y1, x2, y2, imagine[x1][y1])) // daca toti pixelii sunt identici
        return 2; // pentru aceasta zona se utilizeaza 2 biti
    else
    {
        // impart imaginea in patru subimagini
        int Mijloc_x = (x1 + x2) / 2; // mijlocul pe orizontala
        int Mijloc_y = (y1 + y2) / 2; // mijlocul pe verticala
        // apoi, evident, numarul de pixeli necesari este
        // 1 + suma pixelilor necesari pentru cele 4 subimagini
        return 1 + Lungime_Comp(x1, Mijloc_y + 1, Mijloc_x, y2)
            + Lungime_Comp(Mijloc_x + 1, Mijloc_y + 1, x2, y2)
            + Lungime_Comp(x1, y1, Mijloc_x, Mijloc_y)
            + Lungime_Comp(Mijloc_x + 1, y1, x2, Mijloc_y);
    }
}

int main()
{
    int n;
    errno_t err = fopen_s(&Fin, "imagine.in", "rt");
    fscanf_s(Fin, "%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) fscanf_s(Fin, "%d", &imagine[i][j]);
    fclose(Fin);
    err = fopen_s(&Fout, "imagine.out", "wt");
    // apelez functia de calculare a numarului de pixeli
    // necesari pentru intreaga fotografie
    fprintf_s(Fout, "%lu", Lungime_Comp(0, 0, n - 1, n - 1));
    fclose(Fout);
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
