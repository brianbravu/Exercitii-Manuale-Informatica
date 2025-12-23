#pragma once
#include <iostream>
using namespace std;
class fractie
{
private:
	int a; // Numarator
	int b; // Numitor
public:
	int GetNumarator()
	{
		return a;
	}
	int GetNumitor()
	{
		return b;
	}
	void SetNumitor(int y);
	void SetNumarator(int x);
	void Simplifica();
	fractie(int x = 0, int y = 1); // Constructorul clasei

	// Operatori aritmetici
	friend fractie operator-(const fractie& f);
	friend fractie operator+(const fractie& f1, const fractie& f2);
	friend fractie operator-(const fractie& f1, const fractie& f2);
	friend fractie operator*(const fractie& f1, const fractie& f2);
	friend fractie operator/(const fractie& f1, const fractie& f2);
	// Operatorii de atribuire compusi
	friend fractie& operator+=(fractie& f1, const fractie& f2);
	friend fractie& operator-=(fractie& f1, const fractie& f2);
	friend fractie& operator*=(fractie& f1, const fractie& f2);
	friend fractie& operator/=(fractie& f1, const fractie& f2);
	// Operatorii de egalitate
	friend bool operator==(const fractie& f1, const fractie& f2);
	friend bool operator!=(const fractie& f1, const fractie& f2);
	// Operatorii relationari
	friend bool operator<(const fractie& f1, const fractie& f2);
	friend bool operator>(const fractie& f1, const fractie& f2);
	friend bool operator<=(const fractie& f1, const fractie& f2);
	friend bool operator>=(const fractie& f1, const fractie& f2);
	// Operatorii de citire si scriere
	friend istream& operator<<(istream& in, fractie& f);
	friend ostream& operator>>(ostream& out, const fractie& f);

	// Operatori supraincarcati ca functii membre
	fractie& operator++(); // Forma prefixata
	fractie operator++(int fictiv); // Forma postfixata
	fractie& operator--(); // Forma prefixata
	fractie operator--(int fictiv); //Forma postfixata

	operator double() const; // Conversie implicita la double
};

