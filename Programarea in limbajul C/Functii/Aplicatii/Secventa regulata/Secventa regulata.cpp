// Secventa regulata.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define LgMax 10000
#define InFile "secvreg.in"
#define OutFile "secvreg.out"

typedef int CoadaI[LgMax];
typedef char CoadaC[LgMax];
char pereche[100];
CoadaC a; // Initial, coada a este vida
CoadaI b; // Initial, coada b este vida
int inca = LgMax / 2; // inca = inceputul cozii a
int sfa = LgMax / 2 - 1; // sfa = sfarsitul cozii a
int incb = LgMax / 2; // incb = inceputul cozii b
int sfb = LgMax / 2 - 1; // sfb = sfarsitul cozii b
char s[LgMax];

int deschis(char c)
{
    return c == '(' || c == '[';
}

int la_sfarsit(char c) 
// Functia insereaza caracterul c la sfarsitul cozii a 
// si returneaza lungimea secventei regulate care sontine caracterul inserat
{
    int ret;
    if (inca <= sfa && !deschis(c) && a[sfa] == pereche[c])
    {
        ret = b[sfb] + 2; // Retin lungimea secventei regulate
        sfa--; sfb--; // Elimin secventa regulata formata
        b[sfb] += ret; // Memorez in b lungimea noii secvente
        return ret;
    }
    a[++sfa] = c; // Adaug la sfarsitul cozii a caracterul c
    b[++sfb] = 0; // Cu c se formeaza o secventa regulata de lungime 0
    return 0;
}

int la_inceput(char c) 
// Functia insereaza caracterul c la inceputul cozii a
// si returneaza lungimea secventei regulate care sontine caracterul inserat
{
    int ret;
    if (inca <= sfa && !deschis(c) && a[inca] == pereche[c])
    {
        ret = b[incb] + 2; // Retin lungimea secventei regulate
        inca++; incb++; // Elimin secventa regulata formata
        b[incb] += ret; // Memorez in b lungimea noii secvente
        return ret;
    }
    a[--inca] = c; // Adaug la inceoutul cozii a caracterul c
    b[--incb] = 0; // Cu c se formeaza o secventa regulata de lungime 0
    return 0;
}

int main()
{
    char* c, ch;
    int n, di, i;
    FILE* fin, * fout;
    errno_t err;
    err = fopen_s(&fin, InFile, "rt");
    fgets(s, LgMax, fin);
    err = fopen_s(&fout, OutFile, "wt");
    pereche['('] = ')'; pereche[')'] = '('; 
    pereche['['] = ']'; pereche[']'] = '['; 
    b[++sfb] = 0; // Deocamdata, elementele din coada a formeaza o secventa regulata de lungime 0
    for (c = s; *c; c++) la_sfarsit(*c); // Inserez succesiv caracterele din sirul citit la sfarsitul cozii a
    fscanf_s(fin, "%d", &n); // Citesc numarul de operatii
    for (i = 0; i < n; i++) // Citesc succesiv operatiile
    {
        fscanf_s(fin, "%d %c", &di, &ch);
        if (di) fprintf_s(fout, "%d\n", la_sfarsit(ch));
        else fprintf_s(fout, "%d\n", la_inceput(ch));
    }
    fclose(fin);
    fclose(fout);
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
