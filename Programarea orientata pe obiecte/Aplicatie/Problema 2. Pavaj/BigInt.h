#pragma once
#include <ostream>
#include <istream>
using namespace std;
#define LGMAX 1000
class BigInt
{
private:
	char cifre[LGMAX]; // Vectorul de cifre
	int lg; // Lungimea numarului

public:
	// Constructorii
	BigInt(int n = 0); // Constructorul ce creeaza numarul mare dintr-un nr. int
	BigInt(const char s[]); // Constructorul ce creeaza numarul mare dintr-un sir
	BigInt(BigInt& ob); // Constructorul de copiere
	int GetLg()
	{
		return lg;
	}

	friend bool e0(const BigInt& ob);

	BigInt operator=(const BigInt& ob); // Operatorul de atribuire

	int operator[](const int poz) const; // Operatorul de indexare
	BigInt& operator++(); // Forma prefixata
	BigInt& operator++(int fictiv); // Forma postfixata
	BigInt& operator--(); // Forma prefixata
	BigInt& operator--(int fictiv); // Forma postfixata

	friend BigInt operator+(const BigInt& ob1, const BigInt& ob2);
	friend BigInt& operator+=(BigInt& ob1, const BigInt& ob2);

	friend BigInt operator-(const BigInt& ob1, const BigInt& ob2);
	friend BigInt& operator-=(BigInt& ob1, const BigInt& ob2);

	friend BigInt operator*(const BigInt& ob1, const BigInt& ob2);
	friend BigInt& operator*=(BigInt& ob1, const BigInt& ob2);

	friend BigInt operator/(const BigInt& ob1, const BigInt& ob2);
	friend BigInt& operator/=(BigInt& ob1, const BigInt& ob2);

	friend BigInt operator%(const BigInt& ob1, const BigInt& ob2);
	friend BigInt& operator%=(BigInt& ob1, const BigInt& ob2);

	// Operatorii de egalitate
	friend bool operator==(const BigInt& ob1, const BigInt& ob2);
	friend bool operator!=(const BigInt& ob1, const BigInt& ob2);

	// Operatorii relationali
	friend bool operator<(const BigInt& ob1, const BigInt& ob2);
	friend bool operator<=(const BigInt& ob1, const BigInt& ob2);
	friend bool operator>(const BigInt& ob1, const BigInt& ob2);
	friend bool operator>=(const BigInt& ob1, const BigInt& ob2);

	// Operatorii de citire/scriere
	friend ostream& operator<<(ostream& out, const BigInt& ob);
	friend istream& operator>>(istream& in, BigInt& ob);
};
