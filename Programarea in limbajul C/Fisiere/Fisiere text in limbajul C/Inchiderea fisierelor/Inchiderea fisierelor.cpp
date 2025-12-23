// Inchiderea fisierelor.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    FILE* fisin, * fisout;
    char x;
    errno_t err;
    // Open for read (will fail if file "crt_fopen_s.c" doesn't exist)
    err = fopen_s(&fisin, "intrare.txt", "r");
    if (err)
    {
        printf_s("EROARE la deschiderea fisierului de intrare\n");
        return 1;
    }
    // Open for write
    err = fopen_s(&fisout, "iesire.txt", "w");
    if (err)
    {
        printf_s("EROARE la deschiderea fisierului de iesire\n");
        return 2;
    }
    while (!feof(fisin))
        if (fscanf_s(fisin, "%c", &x) != EOF)
            fprintf_s(fisout, "%c", x);
    // Close stream if it isn't NULL
    fclose(fisin);
    fclose(fisout);
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
