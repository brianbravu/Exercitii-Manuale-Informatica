#pragma once
#include "Persoana.h"
class client: public Persoana
{
protected:
	string CodIban;
public:
	string GetCodIban();
	void SetCodIban(const string& sc);
	void Scrie();
	// Constructorii
	client();
	client(const string& sn, const string& sc);
};

