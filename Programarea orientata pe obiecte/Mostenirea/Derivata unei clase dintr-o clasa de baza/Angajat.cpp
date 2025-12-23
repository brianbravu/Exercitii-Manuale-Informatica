#include "Angajat.h"

int Angajat::GetSalariu()
{
	return Salariu;
}

void Angajat::SetSalariu(int x)
{
	Salariu = x;
}

string Angajat::GetFunctie()
{
	return Functie;
}

void Angajat::SetFunctie(string s)
{
	Functie = s;
}

void Angajat::Scrie()
{
	cout << Id << ' ' << Nume << ' ' << Functie << ' ' << Salariu << '\n';
}
