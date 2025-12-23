#pragma once
#include <iostream>
using namespace std;
class Persoana
{
public:
	static int IdCrt;
protected:
	int Id;
	string Nume;
public:
	// Constrictorii
	Persoana();
	Persoana(const string& s);
	// Destructorul
	~Persoana();
	// Functii de acces
	int GetId();
	string GetNume();
	void SetNume(const string& s);
	virtual void Scrie();
};

