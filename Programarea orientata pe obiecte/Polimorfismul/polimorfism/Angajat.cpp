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

Angajat::Angajat() :Persoana()
{
	cout << "Am creat un angajat fara functie si salariu\n";
}

Angajat::Angajat(const string& sf, const int sal) : Persoana()
{
	Functie = sf; Salariu = sal;
	cout << "Am creat un angajat fara nume, ";
	cout << "dar atat cu functie, ";
	cout << "cat si cu salariu\n";
}

Angajat::Angajat(const string& sn, const string& sf, const int sal) :Persoana(sn)
{
	Functie = sf; Salariu = sal;
	cout << "Am creat un angajat cu nume, functie si salariu\n";
}

Angajat::~Angajat()
{
	cout << "Am eliminat un angajat\n";
}
