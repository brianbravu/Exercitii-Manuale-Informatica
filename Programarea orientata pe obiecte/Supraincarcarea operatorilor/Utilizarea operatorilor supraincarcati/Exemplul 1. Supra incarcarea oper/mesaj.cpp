#include "mesaj.h"
#include <iostream>
using namespace std;
mesaj::mesaj()
{
	lg = 0;
	sir = NULL;
}

mesaj::mesaj(const char s[])
{
	int i;
	lg = strlen(s); // Determin lungimea sirului
	sir = new char[lg];
	// Aloc dinamic memorie pentru vectorul care retine
	// Caracterele mesajului
	for (i = 0; i < lg; i++) sir[i] = s[i];
	// Copiez caracterele mesajului
}

mesaj::~mesaj()
{
	delete sir; // Eliberez memoria alocata
}

mesaj::mesaj(mesaj& m)
{
	int i;
	lg = m.lg; // Copiez lungimea
	sir = new char[lg]; // Aloc memorie pentru vector
	for (i = 0; i < lg; i++) sir[i] = m.sir[i];
	// Copiez caracterele din mesajul m in mesajul curent
}

int mesaj::GetLg()
{
	return lg;
}

void mesaj::Scrie()
{
	if (sir)
		for (int i = 0; i < lg; i++) cout << sir[i];
	else
		cout << "Mesajul este vid!";
	cout << '\n';
}

mesaj mesaj::operator~()
{
	int st, dr;
	char aux;
	for (st = 0, dr = lg - 1; st < dr; st++, dr--)
	{
		aux = sir[st];
		sir[st] = sir[dr];
		sir[dr] = aux;
	}
	return *this;
}

mesaj& mesaj::operator=(const mesaj& m)
{
	// TODO: insert return statement here
	// Verificam daca este autoatribuire
	if (this == &m) return *this;
	// Eliberam eventuala zona de memorie alocata deja
	if (sir) delete sir;
	// Alocam o noua zona de memorie pentru oviectul curent
	sir = new char[m.lg];
	// Copiem in obiectul curent obiectul m
	lg = m.lg;
	for (int i = 0; i < lg; i++) sir[i] = m.sir[i];
	return *this;
}

const mesaj mesaj::operator+(const mesaj& m) const
{
	mesaj temp;
	int i;
	temp.lg = lg + m.lg;
	temp.sir = new char[temp.lg];
	for (i = 0; i < lg; i++) temp.sir[i] = sir[i];
	for (i = 0; i < m.lg; i++) temp.sir[i + lg] = m.sir[i];
	return temp;
}

const mesaj& mesaj::operator+=(const mesaj& m)
{
	// TODO: insert return statement here
	mesaj temp;
	int i;
	temp.lg = lg + m.lg;
	temp.sir = new char[temp.lg];
	for (i = 0; i < lg; i++) temp.sir[i] = sir[i];
	for (i = 0; i < m.lg; i++) temp.sir[i + lg] = m.sir[i];
	*this = temp;
	return *this;
}

bool mesaj::operator==(const mesaj& m) const
{
	int i;
	if (lg != m.lg) return false;
	for (i = 0; i < lg && sir[i] == m.sir[i]; i++);
	return (i == lg);
}

inline bool mesaj::operator!=(const mesaj& m) const
{
	return !(*this == m);
}

char mesaj::operator[](const int poz) const
{
	return sir[poz];
}
