#pragma once
#include "Persoana.h"
class Angajat: public Persoana
{
protected:
	string Functie;
	int Salariu;
public:
	int GetSalariu();
	void SetSalariu(int x);
	string GetFunctie();
	void SetFunctie(string s);
	void Scrie();
};

