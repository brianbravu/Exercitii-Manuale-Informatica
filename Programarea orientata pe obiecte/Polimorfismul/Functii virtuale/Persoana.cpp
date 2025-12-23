#include "Persoana.h"

Persoana::Persoana()
{
	Id = ++IdCrt; Nume = "";
	cout << "Am creat o persoana fara nume\n";
}

Persoana::Persoana(const string& s)
{
	Id = ++IdCrt; Nume = s;
	cout << "Am creat o persoana cu nume\n";
}

Persoana::~Persoana()
{
	cout << "Am eliminat o persoana\n";
}

int Persoana::GetId()
{
	return Id;
}

string Persoana::GetNume()
{
	return Nume;
}

void Persoana::SetNume(const string& s)
{
	Nume = s;
}

void Persoana::Scrie()
{
	cout << Id << ' ' << Nume << '\n';
}
