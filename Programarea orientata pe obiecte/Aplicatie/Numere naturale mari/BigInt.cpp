#include "BigInt.h"

BigInt::BigInt(int n)
{
	// Initializez cu 0 vectorul de cifre
	memset(cifre, 0, LGMAX);
	// Extrag cifrele lui n si le memorez incepand cu unitatile
	lg = 0;
	do
	{
		cifre[lg] = n % 10;
		n /= 10;
		lg++;
	} while (n);
}

BigInt::BigInt(const char s[])
{
	// Initializez cu 0 vectorul de cifre
	memset(cifre, 0, LGMAX);
	lg = strlen(s); // Determin lungimea
	if (lg > LGMAX) throw("OVERFLOW");
	if (lg)
		for (int i = lg - 1; i >= 0; i--)
		{
			if (s[i] >= '0' && s[i] <= '9')
				cifre[lg - i - 1] = s[i] - '0';
			else throw("INVALID NUMBER");
		}
	else lg = 1; // Sirulvid il transform in valoarea 0
}

BigInt::BigInt(BigInt& ob)
{
	int i;
	lg = ob.lg;
	memset(cifre, 0, LGMAX);
	for (i = 0; i < lg; i++) cifre[i] = ob.cifre[i];
}

BigInt BigInt::operator=(const BigInt& ob)
{
	int i;
	if (this != &ob) // Nu este autoatribuire
	{
		lg = ob.lg;
		memset(cifre, 0, LGMAX);
		for (i = 0; i < lg; i++) cifre[i] = ob.cifre[i];
	}
	return *this;
}

int BigInt::operator[](const int poz) const
{
	if (poz<0 || poz>LGMAX - 1) throw("RANGE ERROR");
}

BigInt& BigInt::operator++() // Forma prefixata
{
	// TODO: insert return statement here
	int i;
	for (i = 0; i < lg && cifre[i] == 9; i++) cifre[i] = 0;
	if (i == LGMAX) throw("OVERFLOW");
	cifre[i]++;
	if (i == lg) lg++;
}

BigInt& BigInt::operator++(int fictiv) // Forma postfixata
{
	// TODO: insert return statement here
	BigInt temp;
	temp = *this;
	++(*this);
	return temp;
}

BigInt& BigInt::operator--() // Forma prefixata
{
	// TODO: insert return statement here
	int i;
	for (i = 0; cifre[i] == 0; i++) cifre[i] = 9;
	cifre[i]--;
	if (lg > 1 && cifre[lg - 1] == 0) lg--;
}

BigInt& BigInt::operator--(int fictiv) // Forma postfixata
{
	// TODO: insert return statement here
	BigInt temp;
	temp = *this;
	--(*this);
	return temp;
}

bool e0(const BigInt& ob)
{
	return ob.lg == 1 && ob.cifre[0] == 0;
}

bool operator==(const BigInt& ob1, const BigInt& ob2)
{
	int i;
	if (ob1.lg != ob2.lg) return false;
	for (i = 0; i < ob1.lg && ob1.cifre[i] == ob2.cifre[i]; i++);
	return i == ob1.lg;
}

bool operator!=(const BigInt& ob1, const BigInt& ob2)
{
	return !(ob1 == ob2);
}

bool operator<(const BigInt& ob1, const BigInt& ob2)
{
	int i;
	if (ob1.lg < ob2.lg) return true;
	if (ob1.lg > ob2.lg) return false;
	for (i = ob1.lg - 1; i >= 0 && ob1.cifre[i] == ob2.cifre[i]; i--);
	if (i == -1) return false;
	if (ob1.cifre[i] < ob2.cifre[i]) return true;
}

bool operator<=(const BigInt& ob1, const BigInt& ob2)
{
	return ob2 < ob1;
}

bool operator>(const BigInt& ob1, const BigInt& ob2)
{
	return !(ob1 > ob2);
}

bool operator>=(const BigInt& ob1, const BigInt& ob2)
{
	return !(ob1 < ob2);
}

ostream& operator<<(ostream& out, const BigInt& ob)
{
	// TODO: insert return statement here
	for (int i = ob.lg - 1; i >= 0; i--)
		out << (int)ob.cifre[i];
	return out;
}

istream& operator>>(istream& in, BigInt& ob)
{
	// TODO: insert return statement here
	char s[LGMAX + 1];
	in >> s;
	ob.lg = strlen(s);
	if (ob.lg > LGMAX) throw("OVERFLOW");
	for (int i = ob.lg - 1; i >= 0; i--)
	{
		ob.cifre[ob.lg - i - 1] = s[i] - '0';
		return in;
	}
}

BigInt operator+(const BigInt& ob1, const BigInt& ob2)
{
	BigInt temp;
	temp = ob1; temp += ob2;
	return temp;
}

BigInt& operator+=(BigInt& ob1, const BigInt& ob2)
{
	// TODO: insert return statement here
	int t = 0, s, i;
	if (ob2.lg > ob1.lg) ob1.lg = ob2.lg;
	for (i = 0; i < ob1.lg; i++)
	{
		s = ob1.cifre[i] + ob2.cifre[i] + t;
		t = s / 10;
		ob1.cifre[i] = s % 10;
	}
	if (t)
	{
		if (ob1.lg == LGMAX) throw("OVERFLOW");
		ob1.cifre[ob1.lg++] = t;
	}
	return ob1;
}

BigInt operator-(const BigInt& ob1, const BigInt& ob2)
{
	BigInt temp;
	temp = ob1; temp -= ob2;
	return temp;
}

BigInt& operator-=(BigInt& ob1, const BigInt& ob2)
{
	// TODO: insert return statement here
	int i, t = 0, s;
	if (ob1 < ob2) throw("OVERFLOW");
	for (i = 0; i < ob1.lg; i++)
	{
		s = ob1.cifre[i] - ob2.cifre[i] + t;
		if (s < 0)
		{
			s += 10;
			t = -1;
		}
		else t = 0;
		ob1.cifre[i] = s;
	}
	while (ob1.lg > 1 && ob1.cifre[ob1.lg - 1] == 0) ob1.lg--;
	return ob1;
}

BigInt operator*(const BigInt& ob1, const BigInt& ob2)
{
	BigInt temp;
	temp = ob1; temp *= ob2;
	return temp;
}

BigInt& operator*=(BigInt& ob1, const BigInt& ob2)
{
	// TODO: insert return statement here
	int v[LGMAX];
	int i, j, t, s;
	memset(v, 0, sizeof(int) * LGMAX);
	if (e0(ob1) || e0(ob2)) // Rezultatul este 0
	{
		ob1 = BigInt();
		return ob1;
	}
	for (i = 0; i < ob1.lg; i++)
		for (j = 0; j < ob2.lg; j++)
		{
			if (i + j >= LGMAX) throw("OVERFLOW");
			v[i + j] += ob1.cifre[i] * ob2.cifre[j];
		}
	for (t = i = 0; i < LGMAX; i++)
	{
		s = t + v[i];
		v[i] = s % 10;
		t = s / 10;
	}
	if (t) throw("OVERFLOW");
	// Determin lungimea si copiez in ob1 cifrele
	for (ob1.lg = LGMAX; ob1.lg > 1 && !v[ob1.lg - 1]; ob1.lg--);
	for (i = 0; i < ob1.lg; i++) ob1.cifre[i] = v[i];
	return ob1;
}

BigInt operator/(const BigInt& ob1, const BigInt& ob2)
{
	BigInt temp;
	temp = ob1; temp /= ob2;
	return temp;
}

BigInt& operator/=(BigInt& ob1, const BigInt& ob2)
{
	// TODO: insert return statement here
	int cat[LGMAX], i, lgcat = 0, cc;
	if (e0(ob2)) throw("Division by 0");
	if (ob1 < ob2) // Catul este 0
	{
		ob1 = BigInt();
		return ob1;
	}
	if (ob1 == ob2) // Cat este 1
	{
		ob1 = BigInt(1);
		return ob1;
	}
	BigInt t;
	for (i = ob1.lg - 1; t * 10 + ob1.cifre[i] < ob2; i--)
	{
		t *= 10;
		t += ob1.cifre[i];
	}
	// Calculez cifrele catului
	for (; i >= 0; i--)
	{
		t = t * 10 + ob1.cifre[i];
		for (cc = 9; cc * ob2 > t; cc--);
		t -= cc * ob2;
		cat[lgcat++] = cc;
	}
	ob1.lg = lgcat;
	for (i = 0; i < lgcat; i++) ob1.cifre[i] = cat[lgcat - 1 - i];
	return ob1;
}

BigInt operator%(const BigInt& ob1, const BigInt& ob2)
{
	BigInt temp;
	temp = ob1; temp %= ob2;
	return temp;
}

BigInt& operator%=(BigInt& ob1, const BigInt& ob2)
{
	// TODO: insert return statement here
	int cat[LGMAX], i, lgcat = 0, cc;
	if (e0(ob2)) throw("Division by 0");
	if (ob1 < ob2) // Restul este ob1
	{
		return ob1;
	}
	if (ob1 == ob2) // Restul este 0
	{
		ob1 = BigInt();
		return ob1;
	}
	BigInt t;
	for (i = ob1.lg - 1; t * 10 + ob1.cifre[i] < ob2; i--)
	{
		t * 10;
		t += ob1.cifre[i];
	}
	// Calculez cifrele catului
	for (; i >= 0; i--)
	{
		t = t * 10 + ob1.cifre[i];
		for (cc = 9; cc * ob2 > t; cc--);
		t -= cc * ob2;
		cat[lgcat++] = cc;
	}
	while (t.lg > 1 && t.cifre[t.lg - 1] == 0) t.lg--;
	ob1 = t;
	return ob1;
}
